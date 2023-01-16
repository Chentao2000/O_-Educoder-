object TestSort_01{  
   def main(args:Array[String]){    
      val xs = Seq(1,5,3,4,6,2)
      println("========= sorted 排序 ========== ")
      println(xs.sorted) // 升序
      println(xs.sorted.reverse) //降序
      println("=========  sortBy排序 ========== ")
      println(xs.sortBy(d=>d)) // 升序
      println(xs.sortBy(d=>d).reverse) //降序
      println("=========  sortWith排序 ========== ")
      println(xs.sortWith(_<_)) //升序
      println(xs.sortWith(_>_)) //降序
   }  
}  
