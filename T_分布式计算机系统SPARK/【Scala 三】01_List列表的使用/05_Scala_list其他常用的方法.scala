object ForDemo {  
  def main(args: Array[String]): Unit = {
      val list1 = List(1,2)
      val list2 = 2+:list1
    println(list2)
    // 判断列表是否包含元素1
    println(list2.contains(1))
    //去除列表的重复元素
    println(list2.distinct)
  }  
}  
