本关任务：连接两个列表并对数据去重。![在这里插入图片描述](https://img-blog.csdnimg.cn/e9daf3eb93e84a118eb163db6656ceba.png)




------


相关知识
Scala 提供了一套很好的集合实现，Scala 集合分为可变的和不可变的集合。可变集合可以在适当的地方被更新或扩展。也就是说你可以修改，添加，移除一个集合的元素。相比之下，不可变集合类永远不会改变。不过，你仍然可以模拟添加，移除或更新操作。但是这些操作将在每一种情况下都返回一个新的集合，同时使原来的集合不发生改变。在默认的情况下，Scala 使用的是不可变的集合类。本实训介绍的也是基于不可变集合类。

常见的集合类有 List 列表、Set 集合、Map 映射和元组等。接下来我们将为大家介绍第一种集合---List 列表。


## List列表简介
Scala List 列表可以存放重复元素，它有点像数组, 因为它们都是有序存储结构，而且列表中所有元素的类型都一样，但它又不同于数组：
1. 列表(List)一旦被创建就不能改变其中的元素；
2. 列表(List)底层的数据结构是链接表，而数组是一块连续的内存。

因为列表不可变，所以所有操作它的方法或者构造器都会创建一个新的列表。

# 定义列表(List)
定义列表有两种方式，分别是实例化 List 对象和构造符构造。

1. 实例化 List 对象
我们使用 List[T] 来定义一个 T 类型的列表。T 可以是 String，Int 等基本数据类型，也可以是用户自己定义的类型。

下列代码定义了多种类型的列表：  

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 整数列表  
    val list: Seq[Int] = List(4, 5, 6)  
    // 字符串列表  
    val list1: Seq[String] =List("edu","coder")  
    // 空列表  
    val list2=List()  
      // 打印列表  
    println(list)  
    println(list1)  
    println(list2)  
  }  
}  
```
2. 构造符构造
构造列表的两个基本元素是 Nil 和 ::。Nil 代表一个空列表。:: 的发音为“cons”，它可以把新元素组合到现有列表的最前端，然后返回作为执行结果的新列表。

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 整数列表  
    val list: Seq[Int] = 1 :: (2 :: (3 :: (4 :: Nil)))  
    // 字符串列表  
    val list1: Seq[String] ="edu" :: ("coder" :: Nil)  
    // 空列表  
    val list2=Nil  
    // 打印列表  
    println(list)  
    println(list1)  
    println(list2)  
  }  
}  
```

# 列表的常用操作
三个最基本的操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/0d45ecc0f6b545d890a4b0a1e1cdc7f5.png)

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 字符串列表  
    val list: Seq[String] ="腾讯":: ("百度" :: ("阿里" :: Nil))  
    // 打印列表  
    println("列表中第一家公司是："+list.head)  
    println("列表中除了第一家公司之外的公司是："+list.tail)  
    println("查看列表是否为空 :"+list.isEmpty) 
  }  
}  
```
# 连接列表
使用 ::: 运算符或 List.:::() 方法来连接两个或多个列表。实例如下:  


```java
object ForDemo {  
  def main(args: Array[String]): Unit = {
    // 字符串列表  
    val list: Seq[String] ="腾讯":: ("百度" :: ("阿里" :: Nil))  
    // 整数列表  
    val list1=List(1,2)  
    val list2=List(3,4)
    // 连接列表并打印  
    println(list1.:::(list2))
    println(list1:::list2)  
  }  
}
```
需要注意的是，上述两种连接方式的连接顺序是不一样的，另外，不同类型的列表是无法拼接的，比如代码中的字符串列表 list 和整数列表 list1 、list2 是无法连接的。

![在这里插入图片描述](https://img-blog.csdnimg.cn/b3f9ca7217f84aa4a1b654a12e80ee6b.png)

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {
    // 整数列表  
    val list1=List(1,2)  
    // 为列表添加元素2  
    val list2=2+:list1  
    println(list2)  
    // 判断列表是否包含元素1  
    println(list2.contains(1))  
    // 去除列表重复元素  
    println(list2.distinct)  
  }  
}  
```
