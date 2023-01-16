object TestSort_02{  
   def main(args:Array[String]){    
       val pairs = Array(  
                      ("a", 5, 1),  
                      ("c", 3, 1),  
                      ("b", 1, 3) )  
//按第三个字段升序，第一个字段降序，注意，排序的字段必须和后面的tuple对应  
  val bx= pairs.sortBy(r => (r._3, r._1))( Ordering.Tuple2(Ordering.Int, Ordering.String.reverse) )
  //打印结果          
  bx.map( println )  
  }  
}  
