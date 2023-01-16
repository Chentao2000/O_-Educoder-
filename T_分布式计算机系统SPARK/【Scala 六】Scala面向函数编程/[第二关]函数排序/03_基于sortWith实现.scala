object TestSort{
    def main(args:Array[String]){  

       val pairs = Array(
                      ("a", 5, 1),  
                      ("c", 3, 1),  
                      ("b", 1, 3)
       )

       val b = pairs.sortWith{
          case(a,b)=>if(a._3 == b._3)
            if (a._3 == b._3)
               a._1 > b._1
      //如果第三字段相同 则按第一个字段降序
       }else
       {
            a._3 < b._3
       }
       b.map(println)
	  //**************End**************************
    }
}
