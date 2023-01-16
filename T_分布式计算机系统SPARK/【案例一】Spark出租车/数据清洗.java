import org.apache.spark.sql.SparkSession

object Step1 {

    def main(args: Array[String]): Unit = {

        val spark = SparkSession.builder().appName("Step1").master("local").getOrCreate()

        /**********begin**********/

val frame = spark.read.option("header", true).option("delimiter", "\t").csv("/root/data.csv")

 frame.createTempView("data")

 spark.udf.register("cleanData", (x: String) => {

 x.replaceAll("\\@+", "").replaceAll("\\$+", "")

 })

 spark.sql(

 """

 |select cleanData(TRIP_ID) as TRIP_ID,cleanData(CALL_TYPE) as CALL_TYPE,cleanData(ORIGIN_CALL) as ORIGIN_CALL,

 |cleanData(TAXI_ID) as TAXI_ID,cleanData(ORIGIN_STAND) as ORIGIN_STAND ,cleanData(TIMESTAMP) as TIMESTAMP,

 |cleanData(POLYLINE) as POLYLINE

 |from data

 """.stripMargin).show()

        /**********end**********/

        spark.stop()

    }

}
