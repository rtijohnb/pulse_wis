/*
 * (c) 2016-2017 Copyright, Real-Time Innovations, Inc.  All rights reserved.
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software.  Licensee has the right to distribute object form
 * only for use with RTI products.  The Software is provided "as is", with no
 * warranty of any type, including any warranty for fitness for any purpose.
 * RTI is under no obligation to maintain or support the Software.  RTI shall
 * not be liable for any incidental or consequential damages arising out of the
 * use or inability to use the software.
 */

var rti = rti || {};

/**
 * @namespace rti.pulse
 */
rti.patient = {
    /**
     * Sets up a new chart. This method needs to be called before reading or drawing ecg info.
     */
    setupScenario: function() {
        config = {
            type: 'line',
            data: {
                labels: [],
                datasets: [{
                    label: "Pulse",
                    backgroundColor: 'rgb(255, 99, 132)',
                    borderColor: 'rgb(255, 99, 132)',
                    data: [],
                    fill: false,
                }],
            },
            options: {
                title: {
                    display: false,
                    text: 'Pulse Graph',
                },
                legend: {
                    display: false
                },
                scales: {
                    xAxes: [{
                        display: false,
                        ticks: { min: 0, max: 260, stepSize:10, display: false},
                        scaleLabel: {
                            display: false,
                            labelString: 'Time'
                        }
                    }],
                    yAxes: [{
                        display: false,
			            ticks: { min: 0, max: 260, stepSize:10, display: false },
                        scaleLabel: {
                            display: false,
                            labelString: 'Value'
                        }
                    }]
                }
            }
        };

        context = document.getElementById('canvas').getContext('2d');
        lineChart = new Chart(context, config);
    },
    /**
     *  The method will call the methods that update the display at 33 ms intervals.
     */
    read: function() {
        var pulseReaderUrl =
            "/dds/rest1/applications/PulseWisApp" +
            "/domain_participants/PulseWisParticipant" +
            "/subscribers/PulseWisSubscriber" +
            "/data_readers/PatientPulseReader";
        var infoReaderUrl =
            "/dds/rest1/applications/PulseWisApp" +
            "/domain_participants/PulseWisParticipant" +
            "/subscribers/PulseWisSubscriber" +
            "/data_readers/PatientInfoReader";

        var patientUpdateIntervalPeriod = 500; // in milliseconds

        // Call chartjs() for ecgPulse and bpm every ecgReadIntervalPeriod, passing the data resulting
        // for reading new samples of the appropriate topic in json format without deleting the samples
        // from the Reader's cache.
        setInterval(function(){
            // Read pulse
            var x=1;
            $.getJSON(
                pulseReaderUrl,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "false"
                },
                function(data) {
                    rti.patient.updateChart(data); /* ecgPulse topic name */
                }
            );

            // Read bmp data
            $.getJSON(
                infoReaderUrl,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "false"
                },
                function(data) {
                    rti.patient.updateInfo(data, "Triangle"); /* Bpm topic name */
                }
            );
        }, patientUpdateIntervalPeriod);
    },

    /**
     * Updates the chart with the sequence of values
     * @param sampleSeq Sequence of samples to be drawn.
     */

    updateChart: function(sampleSeq) {
        console.log("Sample Length: ", sampleSeq.length);
        const x_point_count = 50;
        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            var validData = sample.read_sample_info.valid_data;
            var instanceHandle = sample.read_sample_info.instance_handle;
            var instanceState  = sample.read_sample_info.instance_state;
            var receptionTime  = sample.read_sample_info.reception_timestamp;

            //console.log("valid data: ", validData);
            //console.log("instance state:", instanceState);
            console.log("sample received:", receptionTime);
            // If we received an invalid data sample, and the instance state
            // is != ALIVE, then the instance has been either disposed or
            // unregistered and we remove the shape from the canvas.
            if (validData && (instanceState == "ALIVE")) {

                    if (config.data.labels.length === x_point_count) {
                        config.data.labels.shift();
                        config.data.datasets[0].data.shift();
                    }
                    x=+.1;

                    console.log(sample.data);
                    console.log("Patient Id:", sample.data.Id.Id)
                    console.log("bpm: ", sample.data.bpm);

                    console.log(sample.read_sample_info.reception_timestamp);
                    //console.log(sample.log.readings);
                    //console.log(sample.log.bpm);
                    /*
                    config.data.labels.push(x);
                    config.data.datasets[0].data.push(sample.data.y);
                    lineChart.update();
                    */
                    var value = (sample.data.bpm.toFixed(2)).slice(-6);
                    var elementHb = document.getElementById("heartbeatValue");
                    elementHb.innerHTML = value;

            }
        });
    },
    updateInfo: function(sampleSeq) {
        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            var validData = sample.read_sample_info.valid_data;
            var instanceHandle = sample.read_sample_info.instance_handle;
            var instanceState  = sample.read_sample_info.instance_state;

            // If we received an invalid data sample, and the instance state
            // is != ALIVE, then the instance has been either disposed or
            // unregistered and we remove the shape from the canvas.
            if (!validData) {
                if (instanceState != "ALIVE") {
                    rti.shapesdemo.canvas.getObjects().every(
                        function (element, j, array) {
                            if (element.uid.instanceHandle == instanceHandle
                                && element.uid.topic == shapeKind) {
                                element.remove();
                                rti.shapesdemo.canvas.renderAll();
                                return false;
                            }
                            return true;
                        }
                    );
                    return true;
                }
                return true;
            }
            return true;
        });
     }
}