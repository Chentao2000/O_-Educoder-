
# 任务描述
    本关任务：本关主题是以手机品牌为例，理解Scala面向对象编程中方法重写和多态请仔细阅读下面“相关知识”中的内容，理解每个手机类所需完成的操作，补全huawei类中的函数，使得程序运行结果如预期输出。
    
![在这里插入图片描述](https://img-blog.csdnimg.cn/a09ab5f0f20f410d8c91480dbb295061.png)

# 相关知识
    为了完成本关任务，你需要掌握：1.如何方法重写，2.如何实现多态。
##### 方法重写
    方法重写指的是当子类继承父类时，从父类继承过来的方法不能满足自身的需要，子类希望有自己的实现，这时需要对父类的方法进行重写（override）,方法重写是实现多态和动态绑定的关键。Scala 语言中的方法重写与 Java 语言中的方法重写一样，也是通过override关键字对父类中的方法进行重写，从而实现子类自身处理逻辑。  


```java
class Phone(var phoneBrand:String,var price:Int){  
   //对父类Any中的toString方法进行重写  
   override def toString=s"Phone($phoneBrand,$price)"  
}
class Apple(phoneBrand:String,price:Int,var place:String)extends Phone(phoneBrand,price){  
  //对父类Phone中的toString方法进行重写  
   override def toString=s"Apple($phoneBrand,$price,$place)"  
}
object TestPhone{  
   def main(args:Array[String]){  
    //调用Apple类自身的toString方法返回结果  
      println(new Apple("iphone",5400,"Shenzhen"))  
   }  
}  
```
运行结果：
Apple(iphone,5400,shenzhen)

    如果不重写父类的toString方法，则返回的结果是类名加hashcode值，例如：  

```java
scala> class Phone(var phoneBrand:String,var price:Int)  
defined class Phone
scala> new Phone("HuaWei",4500)  
res1: Phone = Phone@55881f40  
```


#  多态与继承
    实现继承后，子类可以拥有父类的属性和方法，也可以在子类中添加新的类成员或重写父类中的方法。多态是在继承的基础上实现的一种语言特性，它指的是允许不同类的对象对同一消息做出响应，即同一消息可以根据发送对象的不同而采用多种不同的行为方式。
    多态也称动态绑定或延迟绑定，指在执行期间而非编译期间确定所引用对象的实际类型，根据其实际类型调用其相应的方法，也就是说子类的引用可以赋给父类，程序在运行时根据实际类型调用相应的方法。多态主要作用就是消除类型之间的耦合关系。多态存在的三个必要条件是：要有继承；要有重写；父类引用指向子类对象。  


```java
  //定义父类Phone  
class Phone(var phoneBrand:String,var price:Int){  
    def buy():Unit=println("buy() method in Phone") //buy方法，无参数  
  //compare方法，参数为Phone类型  
    def compare(p:Phone):Unit=println("compare() method in Phone")  
}
   //定义子类Apple  
class Apple( phoneBrand:String,price:Int) extends Phone(phoneBrand,price){  
   private var AphoneNo:Int=0  
  //重写父类compare方法  
   override def compare(p:Phone):Unit={  
       println("compare() method in Apple")  
       println(this.phoneBrand+" is compared with "+p.phoneBrand)  
  }  
} 
```
    使用父类引用p1调用compare方法，则真正调用的是子类 Apple 中重写的compar方法；若父类引用p1调用buy方法，由于子类 Apple 中未重写父类中的buy方法，将毫无疑问地调用父类中的buy方法。
####编程要求
    本关的编程任务是根据预期结果补全 HuaWei 类中从 Phone 类继承的函数，考虑是否需要重写各方法。
