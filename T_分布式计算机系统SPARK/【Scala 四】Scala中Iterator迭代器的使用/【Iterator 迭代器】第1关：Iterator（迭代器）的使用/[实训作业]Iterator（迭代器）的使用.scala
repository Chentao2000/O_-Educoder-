import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 请在 Begin-End 间编写代码  
    /********** Begin **********/  
    // 统计各单词长度        
    val line=StdIn.readLine() // 读取给定字符串  
    val arr=line.split(",") // 切割字符串，获取单词数组  
    var it: Iterator[String] =arr.toIterator // 将数组转为迭代器  
    while(it.hasNext){ // 遍历输出单词长度  
      println(it.next().size)  
    }  
    /********** End **********/
  }  
}  
