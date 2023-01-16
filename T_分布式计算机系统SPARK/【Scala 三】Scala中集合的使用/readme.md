# 解题思路：
![1655627940786](https://user-images.githubusercontent.com/68007558/174472855-f1e829fb-fd62-4421-b017-2ca9d0965041.png) 
 
这个地方结题求两个交集直接 .&就好了 ，点 应该是 调用的意思 。之后所有题都有这个调用的意思
```java
    println("两个集合的交集是："+set.&(set1))
```

这一段是把字符串转换成了整数型：

```java
    for(x<-1 to  n){  
      var line =StdIn.readLine()  
      var line1=line.toInt  
      arr.insert(x-1,line1)  
    }  


```
----
# 完整代码
```java
import scala.collection.mutable.ArrayBuffer  
import scala.io.StdIn
object ForDemo {  
  def main(args: Array[String]): Unit = {
    val set = Set(2,3,7,8)  
    // 请在 Begin-End 间编写代码  
    /********** Begin **********/  
    // 接收给定的第一个数据  
    val n=StdIn.readInt()  
    // 创建数组  
    var arr = new ArrayBuffer[Int]()  
    // 将数据添加到数组  
    for(x<-1 to  n){  
      var line =StdIn.readLine()  
      var line1=line.toInt  
      arr.insert(x-1,line1)  
    }  
    var set1= arr.toSet  
    println("两个集合的交集是："+set.&(set1))
    /********** End **********/
  }  
}
```


----

常见的集合类有 List 列表、Set 集合、Map 映射和元组等。接下来我们将为大家介绍第二种集合---Set 集合。

Set 集合简介
Set 是最简单的一种集合。集合中的对象不按特定的方式排序，并且没有重复对象。

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 定义一个空集合  
    var set: Set[Nothing] =Set()  
    // 定义一个存储字符串的集合  
    var set1: Set[String] =Set("edu","coder")  
    // 定义一个存储整数的集合  
    var set2: Set[Int] =Set(1,2,3)  
    println(set)  
    println(set1)  
    println(set2)  
  }  
}  

```

执行结果：  
```java
Set()  
Set(edu, coder)  
Set(1, 2, 3)
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/6b1f2f2e81b045bd86a5a2ae63477b64.png)
```java

object ForDemo {  
  def main(args: Array[String]): Unit = {  
        // 定义 Set 集合  
        val site = Set("educoder", "百度", "腾讯")  
        println( "第一网站是 : " + site.head )  
        println( "最后一个网站是 : " + site.tail )  
        println( "查看列表 site 是否为空 : " + site.isEmpty )  
  }  
}  
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/55cf6a5a40544393b0e6018be4919fd1.png)


```java
object ForDemo {  
  def main(args: Array[String]): Unit = {
    val site1 = Set("educoder", "腾讯", "百度")  
    val site2 = Set("华为","educoder","淘宝")
    // 使用运算符 ++  
    var site = site1 ++ site2  
    println( "site1 ++ site2 : " + site )
    //  使用 .++ 方法  
    site = site1.++(site2)
    println( "site1.++(site2) : " + site )  
  }  
}  
```


```java
site1 ++ site2 : Set(腾讯, 淘宝, 百度, 华为, educoder)  
site1.++(site2) : Set(腾讯, 淘宝, 百度, 华为, educoder)  
```

- 需要注意的是：1.两个集合合并之后，会把重复的元素去除；2.只有当两个集合的元素类型相同时，才可以做连接。

交集
使用 & 方
法或 intersect 方法可以查看两个集合的交集元素

![在这里插入图片描述](https://img-blog.csdnimg.cn/a0d69d503ff6464087bd91b99a04085b.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/bda2cd082e004a3e9a3d8c01c53a9eda.png)
