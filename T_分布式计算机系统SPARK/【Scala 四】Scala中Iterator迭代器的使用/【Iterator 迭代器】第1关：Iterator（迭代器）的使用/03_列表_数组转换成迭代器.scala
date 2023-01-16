import scala.io.StdIn

object ForDemo {
  def main(args: Array[String]): Unit = {
    // 请在 Begin-End 间编写代码
    /********** Begin **********/
   var list = List(1,2,3)

    var arr = Array(1,2,3)
 
    var it=list.toIterator
    var it1=arr.toIterator

  // 遍历迭代器it的元素
    while(it.hasNext){
      println(it.next())
    }
    // 迭代器 it1 的元素
    while (it1.hasNext)
    {
      println(it1.next())
    }
      
 
    /********** End **********/

  }
}
