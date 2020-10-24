/*
 * (c) 2016-2020 Copyright, Real-Time Innovations, Inc.  All rights reserved.
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
    patientId: null,
    chartConfig: {},
    updateCount: 0,
    emptyCount: 0,
    lineChart: null,
    bumpEmptyCount: function() { this.emptyCount++; return this.emptyCount; },
    getUpdateCount: function() { this.updateCount++; return this.updateCount; },
    getPatientId: function() { return this.patientId;},
    setPatientId: function(id) { this.patientId = id; },
    getBaseURL: function(is_pub) {
      var app = "/dds/rest1/applications/PulseWisApp";
      var pant = "domain_participants/PulseWisParticipant";
      var pOrS;
      if (is_pub) {
        pOrS = "publishers/PulseWisPublisher";
      } else {
        pOrS = "subscribers/PulseWisSubscriber";
      }
      return `${app}/${pant}/${pOrS}`;
    },
    getPulseReaderURL: function() {
      return this.getBaseURL(false) + "/data_readers/PatientPulseReader";
    },
    getPatientInfoReaderURL: function() {
      return this.getBaseURL(false) + "/data_readers/PatientInfoReader";
    },
    getConfigWriterURL: function() {
      return this.getBaseURL(true) + "/data_writers/PatientConfigWriter";
    },
    /**
     * Sets up a new chart. This method needs to be called before reading or drawing ecg info.
     */
    setupScenario: function() {
        this.chartConfig = {
            type: 'line',
		    scale: { xScalePaddingLeft: 0, xScalePaddingRight: 0},
            data: {
                labels: [],
		//defaultFontSize: 20,
                datasets: [{
                    label: "Pulse",
                    backgroundColor: 'rgb(255, 99, 132)',
                    borderColor: 'rgb(255, 99, 132)',
                    data: [],
                    fill: false,
                    pointRadius:1, // removes the dots, default: 3
                }],
            },
            options: {
                animation: {duration: 0 }, // speeds up display
		events: [], // disable hover and tooltip behavior
                title: {
                    display: false,
                    text: 'Pulse Graph',
                },
                legend: {
                    display: false
                },
		    layout: {
		    padding: {
			left: -2, right: 10, top: 20, bottom: 30
			},
		},
                scales: {
                    xAxes: [{
                        display: true,
			gridLines: { display: false},
			
 		        ticks: { display: false},
                        //ticks: { min:0, max:100, stepSize:1, display: false},
                        scaleLabel: {
                            display: false,
                            labelString: 'Some Patient',
 			    //padding: { top: 0, bottom: 0},
                        }
                    }],
                    yAxes: [{
                        display: true,
			//ticks: { min:0, max:1050, stepSize:50, display:false},
                        scaleLabel: {
                            display: false,
                            labelString: 'Value'
                        }
                    }]
                }
            }
        };

        context = document.getElementById('canvas').getContext('2d');
        this.lineChart = new Chart(context, this.chartConfig);

        for (i=0; i< this.X_POINT_COUNT; i++){
            // prefill the chart with gray nominal data (autoscales)
            this.chartConfig.data.labels.push('0:00');
            this.chartConfig.data.datasets[0].data.push(500);
        };

        let url = this.getPatientInfoReaderURL();
        $.getJSON(
          url,
          { sampleFormat:"json"},
          function(info) {
            if (info && info.length) {
	        rti.pulseapp.updatePatientInfo(info[0]);
	    }
        });

	/* Button handlers 
        document.getElementById("btn50").addEventListener("click", function() { rti.pulseapp.write(50, 1);}, false);
        document.getElementById("btn100").addEventListener("click", function() { rti.pulseapp.write(100, 2);}, false);
        document.getElementById("btn200").addEventListener("click", function() { rti.pulseapp.write(200, 3);}, false); 
	*/
    },
    updatePatientInfo(data) {
        // console.log(data);
        const PATIENT_ITEM = document.getElementById('patientNameId');
        let html_name = `${data.data.FirstName} ${data.data.LastName} &nbsp; &nbsp; Age: ${data.data.Age}`;
        PATIENT_ITEM.innerHTML = html_name;
        // remove name/age from chart canvas, showing in HTML
	//let name = `${data.data.FirstName} ${data.data.LastName}     Age: ${data.data.Age}`;
	//this.chartConfig.options.scales.xAxes[0].scaleLabel.labelString = name;
    },
    /**
     *  The method will call the methods that update the display at 33 ms intervals.
     */
    read: function() {
        var url = this.getPulseReaderURL();

        var chartUpdateIntervalPeriod = 1000; // in milliseconds

        // Call chartjs() for ecgPulse and bpm every ecgReadIntervalPeriod, passing the data resulting
        // for reading new samples of the appropriate topic in json format without deleting the samples
        // from the Reader's cache.
        setInterval(function(){
            // Read pulse
            $.getJSON(
                url,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "true"
                },
                function(data) {
		    if (data) {
                        rti.pulseapp.updateChart(data); 
		    } else {
 		        console.log('got empty data' + this.bumpEmptyCnt());
		    }
                }
            );
        }, chartUpdateIntervalPeriod);
    },

    /**
     * Updates the chart with the sequence of values
     * @param sampleSeq Sequence of samples to be drawn.
     */

    updateChart: function(sampleSeq) {
        var chartData = this.chartConfig.data.datasets[0].data;
        var chartLabels = this.chartConfig.data.labels;
        var lineChart = this.lineChart;

        const COUNT_ITEM = document.getElementById("countId");
        COUNT_ITEM.innerHTML = "update count: " + rti.pulseapp.getUpdateCount();
        
        // how to change the line color in time (can also be changed by value condition)
        // lineChart.config.data.datasets[0].borderColor="rgb(255, 99, 132)";
        // lineChart.config.data.datasets[0].backgroundColor="rgb(255, 99, 132)";
    

        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            
            // console.log("sample", sample);
            // console.log(sample.data.readings.length);
	    var info = sample.read_sample_info;
            var valid_data = info.valid_data;
            var instance_handle = info.instance_handle;
            var instance_state  = info.instance_state;
            var reception_time  = info.source_timestamp;
            //var averageReading;

            //console.log("sample received:", reception_time);

            // If we received an invalid data sample, and the instance state
            // is != ALIVE, then the instance has been either disposed or
            // unregistered and we ignore the sample.
            if (valid_data && (instance_state == "ALIVE")) {
                    // console.log(chartData.length);
                    // console.log(sample.data.readings.length);
                    // console.log(sample.data.readings);

                    sample.data.readings.forEach(function(reading, index){
                        //index += index;
                        if (reading < 100) { return; } //- return from this sample - simple filter to get rid of spikes in the data
                        // Better to fix this at the source (not the browser) or integrate the sample more.

                        chartLabels.shift();
                        chartData.shift();

			//console.log(reception_time.sec);
		        let dt = new Date (reception_time.sec * 1000);
                        chartLabels.push(('00'+dt.getMinutes()).slice(-2) + ':' + 
				         ('00'+dt.getSeconds()).slice(-2));
                        chartData.push(reading);
                    });

                    lineChart.update();

                    var value = sample.data.bpm;
                    var elementHb = document.getElementById("heartbeatValue");
                    elementHb.innerHTML = value;

            }
        });
    },

	/* Write some value back on the PatientConfig topic
	 * INACTIVE
    write: function(highValue, lowValue) {
      var configURL = this.getConfigWriterURL();
        var configData = { 
	  "Id": { "Id": "iamGroot", },
	  "PulseHighThreshold": highValue,
	  "PulseLowThreshold": lowValue,
	};

	var configDataJSON = JSON.stringify(configData);
	console.log(configDataJSON);

        $.ajax({
          url:configURL,
          type:"POST",
          data:configDataJSON,
          contentType:"application/dds-web+json",
          dataType:"json",
          success: function(param){
            console.log("sent " + configDataJSON);
		 
          }
        });
    }, */ 
}
