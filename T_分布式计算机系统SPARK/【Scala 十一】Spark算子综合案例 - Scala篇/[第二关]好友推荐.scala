import org.apache.spark.rdd.RDD  
import org.apache.spark.{SparkConf, SparkContext}
object Friend {  
  def main(args: Array[String]): Unit = {  
    val conf = new SparkConf().setMaster("local").setAppName("friend")  
    val sc = new SparkContext(conf)  
    val path = "file:///root/files/friend.txt"  
    /********* Begin *********/  
    //1.创建RDD  
    val rdd: RDD[String] = sc.textFile(path)  
    //2.切分压平  
    val rdd1: RDD[(String, Int)] = rdd.flatMap(line => {  
      var a = List[(String, Int)]()  
      val split = line.split(" ")  
      val me = split(0)  
      for (i <- 1 until split.length) {  
        val s = if (me.hashCode > split(i).hashCode) me + "_" + split(i) else split(i) + "_" + me  
        a ::= (s, 0)  
        for (j <- i+1 until split.length) {  
          val ss = if (split(j).hashCode > split(i).hashCode) split(j) + "_" + split(i) else split(i) + "_" + split(j)  
          a ::= (ss, 1)
        }  
      }  
      a  
    })  
    //3分组  
    val rdd2: RDD[(String, Iterable[Int])] = rdd1.groupByKey()  
    //4判断每一行里如果为直接好友将其设为0，如果不是+1  
    val rdd3: RDD[(String, Int)] = rdd2.map(x => {
      var bool = false  
      var count = 0  
      val flags = x._2  
      val name = x._1  
      for (flag <- flags) {  
        if (flag == 0) bool = true  
        count += 1  
      }  
      if (bool == false) (name, count)  
      else ("直接好友", 0)  
    })  
    //5过滤掉次数为0的剩下的就是间接好友及其次数  
    val tu: RDD[(String, Int)] = rdd3.filter((x) => if (x._2 !=0) true else false)  
    //6输出  
    tu.foreach(println)  
    /********* End *********/  
    sc.stop()  
  }  
}
