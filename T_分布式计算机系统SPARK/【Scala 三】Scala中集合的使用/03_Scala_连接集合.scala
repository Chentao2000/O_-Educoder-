import scala.collection.mutable.ArrayBuffer
import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {  

    val site1 = Set("educoder","腾旭","百度")
    val site2 = Set("华为","educoder","淘宝")

    // 使用运算符 ++
    var site = site1 ++ site2
    println("site1 ++ site2 :" + site)

    // 使用 .++ 方法
    site = site.++(site2)

    println("site1.++(site2):"+ site)

  }  
} 
