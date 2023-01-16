import scala.io.StdIn

object ForDemo {
  def main(args: Array[String]): Unit = {
    
    val colors = Map(
      "red"-> "#FF0000",
      "azure" -> "#F0FFFF",
      "peru"-> "#CD853F"
    )
    val nums:Map[Int,Int] = Map()

    println("colors中的所有键 : "+ colors.keys)
    println("colors中的所有值 ："+ colors.values)
    println("检测colors是否为空："+ colors.isEmpty)
    println("检测nums是否为空 :" + nums.isEmpty)



}
}
