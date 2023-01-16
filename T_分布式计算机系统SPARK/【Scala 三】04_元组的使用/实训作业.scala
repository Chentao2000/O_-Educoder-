object ForDemo {
  def main(args: Array[String]): Unit = {
    // 请在 Begin-End 间编写代码
    /********** Begin **********/
    // 统计元组中所有整数的积
    val t = new Tuple7(23,"hello",3,33,"hi","map",51)
    val sum = t._1 * t._3* t._4* t._7
    println("整数积为: "+sum)
   
      
    /********** End **********/
  }
}
