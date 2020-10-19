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
rti.pulseapp = {
    X_POINT_COUNT: 500,
    chart_config: {},
    cnt: 0,
    lineChart: null,
    /**
     * Sets up a new chart. This method needs to be called before reading or drawing ecg info.
     */
    getCount: function() {
        this.cnt += 1;
        return this.cnt;
    },
    getBaseURL: function() {
      var app = "/dds/rest1/applications/PulseWisApp";
      var pant = "domain_participants/PulseWisParticipant";
      var sub = "subscribers/PulseWisSubscriber";
      return `${app}/${pant}/${sub}`;
    },
    getPulseReaderURL: function() {
      return this.getBaseURL() + "/data_readers/PatientPulseReader";
    },
    getPatientInfoReaderURL: function() {
      return this.getBaseURL() + "/data_readers/PatientInfoReader";
    },
    setupScenario: function() {
        this.chart_config = {
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
                animation: {duration: 0 },
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
                        //ticks: { min: 0, max: 100, stepSize:1, display: false},
                        scaleLabel: {
                            display: false,
                            labelString: 'Time'
                        }
                    }],
                    yAxes: [{
                        display: false,
			            ticks: { min: 0, max: 1000, stepSize:50, display: false },
                        scaleLabel: {
                            display: false,
                            labelString: 'Value'
                        }
                    }]
                }
            }
        };

        context = document.getElementById('canvas').getContext('2d');
        this.lineChart = new Chart(context, this.chart_config);

        let url = this.getPatientInfoReaderURL();
        $.getJSON(
          url,
          { sampleFormat:"json"},
          function(info) {
            rti.pulseapp.updatePatientInfo(info[0]);
        });
    },
    updatePatientInfo(data) {
        const PATIENT_ITEM = document.getElementById('patientNameId');
        let name = `${data.data.FirstName} ${data.data.LastName} &nbsp; &nbsp; Age: ${data.data.Age}`;
        PATIENT_ITEM.innerHTML = name;
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

        var chartUpdateIntervalPeriod = 1000; // in milliseconds

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
                    rti.pulseapp.updateChart(data); /* ecgPulse topic name */
                }
            );
        }, chartUpdateIntervalPeriod);
    },

    /**
     * Updates the chart with the sequence of values
     * @param sampleSeq Sequence of samples to be drawn.
     */

    updateChart: function(sampleSeq) {
        var chart_data = this.chart_config.data.datasets[0].data;
        var chart_labels = this.chart_config.data.labels;
        var x_point = this.X_POINT_COUNT; // not sure why I have to rescope this
        var line_chart = this.lineChart;

        const COUNT_ITEM = document.getElementById("countId");
        COUNT_ITEM.innerHTML = "update count: " + rti.pulseapp.getCount();

        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            
            // console.log("sample", sample);
            // console.log(sample.data.readings.length);
            var valid_data = sample.read_sample_info.valid_data;
            var instance_handle = sample.read_sample_info.instance_handle;
            var instance_state  = sample.read_sample_info.instance_state;
            var reception_time  = sample.read_sample_info.source_timestamp;

            // console.log("sample received:", reception_time);

            // If we received an invalid data sample, and the instance state
            // is != ALIVE, then the instance has been either disposed or
            // unregistered and we remove the shape from the canvas.
            if (valid_data && (instance_state == "ALIVE")) {
                    // console.log(chart_data.length);
                    // console.log(sample.data.readings.length);
                    //console.log(sample.data);

                    sample.data.readings.forEach(function(reading, index){
                        if (chart_data.length === x_point) { 
                            chart_labels.shift();
                            chart_data.shift();
                        }
   
                        //this.chart_config.data.labels.push(x);
                        chart_labels.push(null);
                        chart_data.push(reading);
                    });

                    line_chart.update();

                    var value = (sample.data.bpm.toFixed(2)).slice(-6);
                    var elementHb = document.getElementById("heartbeatValue");
                    elementHb.innerHTML = value;

            }
        });
    },
}
