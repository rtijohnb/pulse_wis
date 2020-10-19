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
var cnt = 0;
const X_POINT_COUNT = 350;

rti.pulseapp = {
  /**
   * Set up a new canvas, called before graphing.
   */
  getCount: function() {
	  cnt += 1;
	  return cnt;
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
  chart_config: {
    type: 'line',
    data: {
      labels: [],
      datasets: [{
        label: "Pulse",
        borderColor: 'rgb(255, 99, 132)',
        data: [],
        fill: false,
        pointRadius:1, // removes the dots, default: 3
        //lineTension: 0,
        //showLine: false,
      }],
    },
    options: {
      animation: {duration: 0},
      backgroundColor: "transparent",
      title: { display: false, /* text: 'Pulse Graph',*/ },
      legend: { display: false },
      scales: {
        xAxes: [ {
          display: false,
          scaleLabel: { display: false, /* labelString: 'Time' */ },
        }],
        yAxes: [ {
          ticks: {
            min: 0,
            max: 1000,
            stepSize: 50
          },
          display: true,
          scaleLabel: { display: false, /* labelString: 'Value' */ },
        }]
      }
    }
  },
  lineChart: null,
  setupScenario: function () {
    const context = document.getElementById('canvas').getContext('2d');
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
   * Sets up the enviroment for reading Pulse and Beat topics. 
   * The method will call the updatePulse method every 33 ms intervals.
   */
  readPatientData: function () {

    let drawIntervalPeriod = 5; // in milliseconds

    /**
     * Request the data in JSON format; 
     * update BPM value and chart 
     */
    var url = this.getPulseReaderURL();
    setInterval(function(){
      $.getJSON(
        url, 
        {
          sampleFormat: "json",
          removeFromReaderCache: "false"
        },
        function (samples)
        { 
          samples.forEach(function(sample, index) {
 	    rti.pulseapp.updatePulse(sample);
	  });
        });
      }, drawIntervalPeriod);
  },
  /**
   * Update the BPM field and
   * store/shift new data into chartData array
   * update the lineChart
   * Note: must add label value even if not shown for chart to update
   */
  updatePulse: function (sample) {
    // TODO: avoid getElement... for each update
    const BPM_ITEM = document.getElementById("bpmId");
    BPM_ITEM.innerHTML = sample.data.bpm;
    var data = this.chart_config.data;
    var chartLabels = data.labels;
    var chartData = data.datasets[0].data;
    const COUNT_ITEM = document.getElementById("countId");
    COUNT_ITEM.innerHTML = "update count: " + rti.pulseapp.getCount();
    sample.data.readings.forEach(function (item, index) {
      if (chartData.length >= X_POINT_COUNT) {
        chartLabels.shift();
        chartData.shift();
      }
      chartData.push(item);
      chartLabels.push(null);
    });
    this.lineChart.update();
  },
}

