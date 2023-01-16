object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 字符串列表  
     val list:Seq[String] = "腾旭"::("百度"::("阿里"::Nil))
    // 打印列表
    println(list)
    println("列表的第一家公司是" +list.head)
    println("列表中除了第一家公司之外的公司是 "+ list.tail)
    println("查看列表是否为空:" + list.isEmpty)
  }  
}  
