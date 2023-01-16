
import org.apache.spark.rdd.RDD  
import org.apache.spark.{SparkConf, SparkContext}
object WordCount {  
    def main(args: Array[String]): Unit = {  
      val conf = new SparkConf().setMaster("local").setAppName("WordCount")
      val path = "file:///root/files/wordcount.txt"
      // 读取文件创建 RDD
      val file = sc.textFile(path)
      // 切分并压平
      val words: RDD[String] = file.flatMap(_.split(" "))
      // 组装
      val wordsAndone: RDD[(String,Int)] = word.map((_,1))
      // 分组聚合
      val result: RDD[(String,Int)] = wordsAndone.reduceByKey(_+_)
      //排序
      val result1:RDD[(String,Int)] = result.sortBy(_._2,false)
      //输出
      result1.foreach(println)
      sc.stop()
    }
  }
