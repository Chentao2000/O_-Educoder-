# 解题01：

![1655631960474](https://user-images.githubusercontent.com/68007558/174475206-2f598b98-6684-44e6-a166-496c258fdda4.png)


```java
import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 请在 Begin-End 间编写代码  
    /********** Begin **********/  
    // 读取字符串  
    val line: String =StdIn.readLine()  
    // 依据逗号切割字符串，得到一个数组  
    var arr =line.split(",")  
    // 将数组中每个元素转化为（单词元素，1）  
    var map1: Seq[(String, Int)] =arr.flatMap(x=>x.split("-")).map(x=>(x,1))  
    // 按照单词对键值对分组  
    var r1: Map[String, Seq[(String, Int)]] = map1.groupBy(_._1)  
    // 统计各单词的个数  
    var count= r1.map(t => (t._1,t._2.size))  
    // 遍历输出结果  
    count.keys.foreach{ i =>  
      print( "单词： " + i +",")  
      println(" 个数 " + count(i) )}  
    /********** End **********/  
  }  
}  
```

-----

# 以下代码演示了如何定义 Map 映射。 

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 定义一个空 Map 映射  
    var map: Map[Nothing, Nothing] =Map()  
    // 定义一个键为字符串，值为整型的 Map 映射  
    var people: Map[String, Int] =Map("张三"->34,"李四"->30)  
    println(map)  
    println(people)  
  }  
}  
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/23df448b6e414efd82737c3d33fef1f2.png)

```java
object Test {  
   def main(args: Array[String]) {  
      val colors = Map("red" -> "#FF0000",  
                       "azure" -> "#F0FFFF",  
                       "peru" -> "#CD853F")
      val nums: Map[Int, Int] = Map()
      println( "colors 中的所有键 : " + colors.keys )  
      println( "colors 中的所有值 : " + colors.values )  
      println( "检测 colors 是否为空 : " + colors.isEmpty )  
      println( "检测 nums 是否为空 : " + nums.isEmpty )  
   }  
}  
```

# 合并操作
合并两个或者多个 Map 有两种方式：一是使用 ++ 运算符，二是使用.++() 方法。Map  合并时会移除重复的 key。  

```java
val colors1 = Map("red" -> "#FF0000",  
      "azure" -> "#F0FFFF",  
      "peru" -> "#CD853F")  
    val colors2 = Map("blue" -> "#0033FF",  
      "yellow" -> "#FFFF00",  
      "red" -> "#FF00001")
    //  使用 ++ 运算符合并  
    var colors = colors1 ++ colors2  
    println( "colors1 ++ colors2 : " + colors )
    //  使用 .++ 方法合并  
    colors = colors1.++(colors2)  
    println( "colors1.++(colors2)) : " + colors ) 
```

# 遍历 Map 的 keys 和 values
使用 foreach 循环，可以遍历 Map 中的 keys 和 values。  

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    val sites = Map("educoder" -> "www.educoder.net",  
      "baidu" -> "http://www.baidu.com",  
      "taobao" -> "http://www.taobao.com")  
      // 使用 foreach 遍历 Map 中的 keys 和 values  
      sites.keys.foreach{ i =>  
      print( "Key = " + i )  
      println(" Value = " + sites(i) )}  
  }  
}  
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/6e1ccbc933164ee4a8bf06c717739669.png)



![在这里插入图片描述](https://img-blog.csdnimg.cn/96d1167e87394fee899150dc52c6ecf4.png)
