object ForDemo {  
  def main(args: Array[String]): Unit = {
    // 字符串列表  
    val list: Seq[String] ="腾讯":: ("百度" :: ("阿里" :: Nil))  
    // 整数列表  
    val list1 = List(1,2)
    val list2 = List(3,4)
    // 连接列表并且打包
    println(list1.:::(list2))
    print(list1:::list2)
  }  
}  
