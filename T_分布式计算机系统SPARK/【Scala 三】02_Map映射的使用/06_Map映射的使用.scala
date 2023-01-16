import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 请在 Begin-End 间编写代码  
    /********** Begin **********/  
    // 读取字符串  
    val line: String =StdIn.readLine()  
    // 依据逗号切割字符串，得到一个数组  
    var arr =line.split(",")  
    // 将数组中每个元素转化为（单词元素，1）  
    var map1: Seq[(String, Int)] =arr.flatMap(x=>x.split("-")).map(x=>(x,1))  
    // 按照单词对键值对分组  
    var r1: Map[String, Seq[(String, Int)]] = map1.groupBy(_._1)  
    // 统计各单词的个数  
    var count= r1.map(t => (t._1,t._2.size))  
    // 遍历输出结果  
    count.keys.foreach{ i =>  
      print( "单词： " + i +",")  
      println(" 个数 " + count(i) )}  
    /********** End **********/  
  }  
}  
