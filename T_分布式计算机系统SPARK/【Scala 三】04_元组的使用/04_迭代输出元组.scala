object ForDemo {
  def main(args: Array[String]): Unit = {
    // 请在 Begin-End 间编写代码
    /********** Begin **********/
    val t = (4,3,2,1)
    t.productIterator.foreach{
      i => println(i)
    }

    /********** End **********/
  }
}
