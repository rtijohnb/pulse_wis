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

rti.pulseapp = {
  /**
   * Set up a new canvas, called before graphing.
   */
  getPulseReaderURL: function() {
    var app = "/dds/rest1/applications/PulseWisApp";
    var pant = "domain_participants/PulseWisParticipant";
    var sub = "subscribers/PulseWisSubscriber";
    var reader = "/data_readers/PatientPulseReader";
    return `${app}/${pant}/${sub}/${reader}`;
  },
  X_POINT_COUNT: 300,
  chart_config: {
    type: 'line',
    data: {
      labels: [],
      datasets: [{
        label: "Pulse",
        borderColor: 'rgb(255, 99, 132)',
        data: [],
        fill: false,
        //<!--lineTension: 0, -->
        //<!--showLine: false, -->
      }],
    },
    options: {
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
    lineChart = new Chart(context, this.chart_config);
    BPM_ITEM = document.getElementById("bpmId");
  },

  /**
   * Sets up the enviroment for reading Pulse and Beat topics. 
   * The method will call the updatePulse method every 33 ms intervals.
   */
  readPatientData: function () {

    let drawIntervalPeriod = 33; // in milliseconds

    /**
     * Request the data in JSON format; 
     * update BPM value and chart 
     */
    let url = this.getPulseReaderURL();
    setInterval(function(){
      $.getJSON(
        url, 
        {
          sampleFormat: "json",
          removeFromReaderCache: "false"
        },
        function (samples)
        {
          rti.pulseapp.updatePulse(samples[0]); // TODO: iterate
        });
      }, drawIntervalPeriod);
  },
  /**
   * Update the BPM field and
   * store/shift new data into chartData array
   * update the lineChart
   */
  updatePulse: function (sample) {
    // TODO: avoid getElement... for each update
    const BPM_ITEM = document.getElementById("bpmId");
    BPM_ITEM.innerHTML = sample.data.bpm;
    var chartData = this.chart_config.data.datasets[0].data;
    var items = [];
    sample.data.readings.forEach(function (item, index) {
      if (chartData.length === this.X_POINT_COUNT) {
        //this.chart_config.data.labels.shift(); // restore if using x labels
        chartData.shift();
      }
      chartData.push(item);
    });
    lineChart.update();
    return true;
  },
}

