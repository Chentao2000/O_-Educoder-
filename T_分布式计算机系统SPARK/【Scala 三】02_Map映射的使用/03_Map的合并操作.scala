import scala.io.StdIn

object ForDemo {
  def main(args: Array[String]): Unit = {
    
    val colors1 = Map(
      "red"-> "#FF0000",
      "azure" -> "#F0FFFF",
      "peru"-> "#CD853F"
    )
    val colors2 = Map(
      "blue" -> "#0033FF",
      "yellow" -> "#FFFF00",
      "red" -> "FF0001"
    )
    // 使用 ++ 运算符合并
    var colors = colors1 ++ colors2
    println("colors1 ++ colors2 :" + colors)

    //使用.++运算方法合并
    colors = colors1.++ (colors2)
    println("colors1.++(colors2)"+colors)



}
}
