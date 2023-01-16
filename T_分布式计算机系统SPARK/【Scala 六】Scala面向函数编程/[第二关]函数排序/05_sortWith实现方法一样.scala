object TestSort_05{  
     def main(args:Array[String]){    
           case class Person(val name:String,val age:Int)  
           val p1=Person("cathy",23)  
           val p2=Person("daniel",23)  
           val p3=Person("andy",25)
           val pairs = Array(p1,p2,p3)  
           val b=pairs.sortWith{  
               case (person1,person2)=>{  
                     person1.age==person2.age match {  
                          //年龄一样，按名字降序排  
case true=> person1.name > person2.name                             
case false=>person1.age < person2.age //否则按年龄升序排  
                     }  
               }  
            }  
         b.map(println)  
    }  
}  
