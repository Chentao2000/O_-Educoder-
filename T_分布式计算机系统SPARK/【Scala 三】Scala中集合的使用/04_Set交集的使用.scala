import scala.collection.mutable.ArrayBuffer
import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {  

    val num1 = Set(5,6,90,28,30,45)
    val num2 = Set(5,60,90,20,35,55)
    // 打印交集
    println("num1.&(num2):" + num1.&(num2))
    println("num1.intersect(num2):"+ num1.intersect(num2))

  }  
} 
