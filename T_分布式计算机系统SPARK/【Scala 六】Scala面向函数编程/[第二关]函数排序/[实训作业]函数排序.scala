object TestSort{  
  def main(args:Array[String]){  
    val pairs = Array(  
      ("Cathy",  100,  110,  108,  78,  95,  89),  
      ("Daniel",  110,  98,  110,  80, 94,     88),  
      ("Andy",   105,  120,  115, 85,     90,     95) )  
    //**************Begin*************************
    //构造新数组（姓名，三科总分，六科总分）
    val  count = Array(  
      (pairs{0}._1,pairs{0}._2+pairs{0}._3+pairs{0}._4,  
        pairs{0}._2+pairs{0}._3+pairs{0}._4+pairs{0}._5+pairs{0}._6+pairs{0}._7),  
      (pairs{1}._1,pairs{1}._2+pairs{1}._3+pairs{1}._4,  
        pairs{1}._2+pairs{1}._3+pairs{1}._4+pairs{1}._5+pairs{1}._6+pairs{1}._7),  
      (pairs{2}._1,pairs{2}._2+pairs{2}._3+pairs{2}._4,  
        pairs{2}._2+pairs{2}._3+pairs{2}._4+pairs{2}._5+pairs{2}._6+pairs{2}._7) )
    //排序  
    val b= count.sortWith{  
      case (a,b)=>{  
        if(a._3==b._3) {//如果总分相等，就按三科降序  
          if(a._2==b._2)  
            a._1<b._1  
          else  
            a._2>b._2  
        }else {  
          a._3>b._3 //否则总分降序  
        }  
      }  
    }  
    //**************End**************************
    //打印结果  
    b.map(println)  
  }  
}
