object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 整数列表  
    val list: Seq[Int] = 1 :: (2 :: (3 :: (4 :: Nil)))  
    // 字符串列表  
    val list1: Seq[String] ="edu" :: ("coder" :: Nil)  
    // 空列表  
    val list2=Nil  
    // 打印列表  
    println(list)  
    println(list1)  
    println(list2)  
  }  
} 
