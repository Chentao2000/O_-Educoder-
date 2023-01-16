import scala.io.StdIn

object ForDemo {
  def main(args: Array[String]): Unit = {
    // 请在 Begin-End 间编写代码
    /********** Begin **********/
    var it = Iterator("百度","腾讯","阿里","淘宝")
    while(it.hasNext){
      println(it.next())
    }
      
 
    /********** End **********/

  }
}
