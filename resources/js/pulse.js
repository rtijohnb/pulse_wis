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

var context; 
var config;
var linechart;
/**
 * @namespace rti.pulse
 */
rti.pulse = {
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
                        ticks: {display: false},
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
            "/dds/rest1/applications/ShapesDemoApp" +
            "/domain_participants/MyParticipant" +
            "/subscribers/MySubscriber" +
            "/data_readers/MySquareReader";
        var bpmReaderUrl =
            "/dds/rest1/applications/ShapesDemoApp" +
            "/domain_participants/MyParticipant" +
            "/subscribers/MySubscriber" +
            "/data_readers/MyTriangleReader";

        var pulseDemoIntervalPeriod = 500; // in milliseconds

        // Call chartjs() for ecgPulse and bpm every ecgReadIntervalPeriod, passing the data resulting
        // for reading new samples of the appropriate topic in json format without deleting the samples
        // from the Reader's cache.
        setInterval(function(){
            // Read pulse
            $.getJSON(
                pulseReaderUrl,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "false"
                },
                function(data) {
                    rti.pulse.updateChart(data, "Square"); /* ecgPulse topic name */
                }
            );

            // Read bmp data
            $.getJSON(
                bpmReaderUrl,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "false"
                },
                function(data) {
                    rti.pulse.updateBpm(data, "Triangle"); /* Bpm topic name */
                }
            );
        }, pulseDemoIntervalPeriod);
    },

    /**
     * Updates the chart with the sequence of values
     * @param sampleSeq Sequence of samples to be drawn.
     */

    updateChart: function(sampleSeq, topic) {
        console.log(sampleSeq.length, topic);
        const x_point_count = 50;
        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            var validData = sample.read_sample_info.valid_data;
            var instanceHandle = sample.read_sample_info.instance_handle;
            var instanceState  = sample.read_sample_info.instance_state;

            // If we received an invalid data sample, and the instance state
            // is != ALIVE, then the instance has been either disposed or
            // unregistered and we remove the shape from the canvas.
            if (validData && instanceState == "ALIVE") {

                    if (config.data.labels.length === x_point_count) {
                        config.data.labels.shift();
                        config.data.datasets[0].data.shift();
                    }
            
                    config.data.labels.push(1);
                    config.data.datasets[0].data.push(sample.data.y);
                    lineChart.update();

                    var value = (sample.data.y.toFixed(2)).slice(-6);
                    var elementHb = document.getElementById("heartbeatValue");
                    elementHb.innerHTML = value;
            }
        });
    },
    updateBpm: function(sampleSeq) {
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
