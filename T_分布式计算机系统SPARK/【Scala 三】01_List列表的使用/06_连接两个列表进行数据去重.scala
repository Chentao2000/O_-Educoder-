import scala.collection.mutable.ArrayBuffer
import scala.io.StdIn

object ForDemo {
  def main(args: Array[String]): Unit = {
    // 创建集合list
    val list =List(2,4,5)
    // 接收给定的第一个数据
    val n=StdIn.readInt()
    // 创建数组
    var arr = new ArrayBuffer[Int]()
    // 将数据添加到数组
    for(x<-1 to  n){
      var line =StdIn.readLine()
      var line1=line.toInt

      arr.insert(x-1,line1)

    }
    // 将数组转为列表
    val list1= arr.toList
    
    // 请在 Begin-End 间编写代码
    /********** Begin **********/
    // 按要求连接列表并去重，最后输出去重后的列表
    println((list:::list1).distinct)
      
      
    /********** End **********/
  }
}
