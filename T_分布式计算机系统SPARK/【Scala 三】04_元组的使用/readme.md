Scala 提供了一套很好的集合实现，Scala 集合分为可变的和不可变的集合。可变集合可以在适当的地方被更新或扩展。也就是说你可以修改，添加，移除一个集合的元素。相比之下，不可变集合类永远不会改变。不过，你仍然可以模拟添加，移除或更新操作。但是这些操作将在每一种情况下都返回一个新的集合，同时使原来的集合不发生改变。在默认的情况下，Scala 使用的是不可变的集合类。本实训介绍的也是基于不可变集合类。

常见的集合类有 List 列表、Set 集合、Map 映射和元组等。接下来我们将为大家介绍第四种集合---元组。

# 元组简介
元组看起来犹如列表，都可以存储重复元素，但是它们之间最大的不同是元组可以包含不同类型的元素。  

定义元组
定义元组可以有两种方式：一是直接将元素写在（）中，另一种就是通过 new Tuplen()的方式。
## 1.直接将元素写在（）中  

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 定义元组  
    val t = (1, 3.14, "Fred"，1)      
  }  
}  
```

上述代码定义了一个由三种元素组成的元组，对应的类型分别为[Int, Double, java.lang.String]，另外需要注意的是，它是允许重复元素存在的（比如元素 1）。

## 2.通过 new Tuplen()的方式  

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 定义有三个元素的元组   
    val t1 = new Tuple3(1, 3.14, "Fred")  
    // 定义有四个元素的元组   
    val t2 = new Tuple4(1, 3.14, "Fred",3)  
    println(t1)  
    println(t2)  
  }  
}  
```

上述代码中，Tuple 后面的数字表示元组有多少个元素，比如 Tuple3 代表该元组存储 3 个元素，最多元素个数为 22。


### 元组的基本操作
#### 访问元组
访问元组的元素可以通过数字索引实现。 

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 创建元组  
    val t = (4,3,2,1)  
    // 计算元组中各元素的和  
    val sum = t._1 + t._2 + t._3 + t._4  `在这里插入代码片`
    println( "元素之和为: "  + sum )
  }  
}  
```


## 迭代元组
productIterator() 方法可以迭代输出元组的所有元素，元素的输出顺序和定义时相同。  

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 创建元组  
    val t = (4,3,2,1)  
    t.productIterator.foreach{ i =>println( i )}
  }  
}  
```
##  元组转为字符串

toString() 方法能将元组的所有元素组合成一个由逗号拼接的字符串。 

```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 创建元组  
    val t = new Tuple3(1, "hello", "edu")  
    println("连接后的字符串为: " + t.toString() )  
  }  
}  
```

