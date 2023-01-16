
任务描述
    本关主题是利用 Scala 面向对象编程中类的继承，对手机品牌进行面向对象建模与编程。请仔细阅读下面“相关知识”中的内容，理解每个手机类所需完成的操作，补全huawei类中的函数，使得程序运行结果如预期输出。
 

![在这里插入图片描述](https://img-blog.csdnimg.cn/6f570cdfb8664ff581b05e869fe96b93.png)


相关知识
    Scala语言通过extends关键字来实现类间的继承。Scala 不允许类从多个父类继承。
Scala 中的继承需满足：
（1）重写一个非抽象方法必须使用override修饰符；
（2）只有主构造函数可以调用父类的主构造函数；
（3）在子类中重写父类的抽象方法时，不需要使用override关键字；
（4）可以重写父类中的成员变量。  

    首先创建一个手机抽象类，让这个抽象类被其他类继承。  

```java
abst\fract class Phone{   //是抽象类，不能直接被示例化  
      val phoneBrand: String  //成员变量没有初始化值，就是一个抽象成员变量  
      def info()  //抽象方法，不需要使用abst\fract关键字  
      def greeting() {  //具体方法  
          println("Welcome to use phone!")   
      }  
}  
```

  当子类继承抽象类时，需要在子类中对父类中的抽象成员变量进行初始化，否则子类也必须声明为抽象类。  

```java
/*父类中包含抽象成员变量时，子类如果为普通类则必须将该成员变量初始化，否则子类也应声明为抽象类*/  
scala> class XiaoMi extends Phone  
<console>:12: error: class XiaoMi needs to be abst\fract, since:  
it has 2 unimplemented members.  
/** As seen from class XiaoMi, the missing signatures are as follows.  
 *  For convenience, these are usable as stub implementations.  
 */  
  def info(): Unit = ???  
  val phoneBrand: String = ???
       class XiaoMi extends Phone  
             ^
//在子类中对父类中的抽象成员变量及抽象方法进行初始化，使用override关键字  
scala> class Apple extends Phone{  
          override val phoneBrand:String="Apple"  
          override def info:Unit=println("Welcome to use iphone!")  
      }  
defined class Apple
//也可以省略override关键字  
scala> class Apple extends Phone{  
       val phoneBrand:String="Apple"  
       def info:Unit=println("Welcome to use iphone!");  
     }  
defined class Apple  
```
如果Phone类中存在抽象成员变量phoneBrand，子类Apple如果没有对该成员变量进行初始化的话，系统会报错并提示应该将该类也定义为抽象类，如果不需要子类为抽象类，则需要对该成员变量进行初始化，值得注意的是子类对父类抽象成员变量进行重写可以加override关键字，也可以省略。
    抽象类不能直接被实例化，可以定义扩展类，其将扩展 Phone 类，或者说继承自 Phone 类

```java
class Apple extends Phone{
     //重写父类成员变量，可以使用override关键字。  
      override val phoneBrand = "Apple"     
    //重写父类的抽象方法时，不需要使用override关键字，不过，如果加上override编译也不报错  
    def info() {  
       printf("This is a/an %s phone. It is expensive", phoneBrand)  
    }   
   //重写父类的非抽象方法，必须使用override关键字  
   override def greeting() {  
       println("Welcome to use Apple Phone!")  
   }  
}  
```
