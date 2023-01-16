import scala.collection.mutable.ArrayBuffer
import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {  

      // 定义 一个 Set 集合
      val site = Set("educoder","百度","腾旭")
      println("第一个网站是",site.head)
      println("最后一个是网站是",site.tail)
      println("查看列表site是否为空:"+site.isEmpty)

  }  
} 
