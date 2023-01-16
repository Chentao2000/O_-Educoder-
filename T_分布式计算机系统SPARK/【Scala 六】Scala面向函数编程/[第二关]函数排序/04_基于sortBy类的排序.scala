object TestSort{
    def main(args:Array[String]){  

       case class Person(
          val.name:String,val age:Int
       )
       val p1 = Person("canthy",23)
       val p2 = Person("daniel",23)
       val p3 = Person("andy",25)
       val pairs = Array(p1,p2,p3)
	  //**************End**************************//
     // 先按照年龄排序 ，如果一样，那就按照名称来排序
     val bx = pairs.sortBy(person => (person.age , person.name))
     ( Ordering.Tuple2(Ordering.Int, Ordering.String.reverse) ) 
     bx.map(println)
      

    }
}
