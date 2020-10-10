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
​
var rti = rti || {};
​
/**
 * @namespace rti.ecg
 */
rti.ecg = {
    /**
     *  The method will call the methods that update the display at 33 ms intervals.
     */
    readEcg: function() {
        var ecgPulseReaderUrl =
            "/dds/rest1/applications/ShapesDemoApp" +
            "/domain_participants/MyParticipant" +
            "/subscribers/MySubscriber" +
            "/data_readers/MySquareReader";
        var bpmReaderUrl =
            "/dds/rest1/applications/ShapesDemoApp" +
            "/domain_participants/MyParticipant" +
            "/subscribers/MySubscriber" +
            "/data_readers/MyTriangleReader";

        var ecgReadIntervalPeriod = 33; // in milliseconds
​
        // Call chartjs() for ecgPulse and bpm every ecgReadIntervalPeriod, passing the data resulting
        // for reading new samples of the appropriate topic in json format without deleting the samples
        // from the Reader's cache.
        setInterval(function(){
            // Read ecgPulse
            $.getJSON(
                ecgPulseReaderUrl,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "false"
                },
                function(data) {
                    rti.ecg.updateChart(data, "ecgPulse"); /* ecgPulse topic name */
                }
            );
​
            // Read bmp data
            $.getJSON(
                bpmReaderUrl,
                {
                    sampleFormat: "json",
                    removeFromReaderCache: "false"
                },
                function(data) {
                    rti.ecg.updateBpm(data, "ecgBpm"); /* Bpm topic name */
                }
            );

    },
​
    /**
     * Updates the chart with the sequence of values
     * @param sampleSeq Sequence of samples to be drawn.
     */
    updateChart: function(sampleSeq) {
        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            var validData = sample.read_sample_info.valid_data;
            var instanceHandle = sample.read_sample_info.instance_handle;
            var instanceState  = sample.read_sample_info.instance_state;
​
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
    },
    updateBpm: function(sampleSeq) {
        sampleSeq.forEach(function(sample, i, samples) {
            // Process metadata
            var validData = sample.read_sample_info.valid_data;
            var instanceHandle = sample.read_sample_info.instance_handle;
            var instanceState  = sample.read_sample_info.instance_state;
    ​
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
​









