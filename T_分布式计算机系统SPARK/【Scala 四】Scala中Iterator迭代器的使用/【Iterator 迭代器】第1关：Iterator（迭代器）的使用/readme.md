
# 任务描述
本关任务：统计各单词长度。

![在这里插入图片描述](https://img-blog.csdnimg.cn/818ce02494fd4cebb2af21a1a3e31995.png)

定义迭代器
以下代码演示了如何定义迭代器。


```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 定义迭代器   
    var it=Iterator("edu","coder",1)  
  }  
}  
```

从上述代码中可以看出，使用 Iterator（元素 1，元素 2,...）即可定义一个迭代器，另外，它还可以存放不同数据类型的元素。

# 迭代器的基本操作
while 循环遍历迭代器
让迭代器逐个返回所有元素最简单的方法是使用 while 循环。  

```java
object Test {  
   def main(args: Array[String]) {  
      // 定义迭代器   
      val it = Iterator("百度", "腾讯", "阿里", "淘宝")  
      // 遍历元素  
      while (it.hasNext){  
         println(it.next())  
      }  
   }  
}  
```

上述代码中，it.hasNext 用于判断迭代器中是否还有下一个元素，如果有，返回 true，如果没有，返回 false。it.next 则用于获取下一个具体的值。

列表、数组转为迭代器
可以使用 toIterator 方法将数组或者列表转为迭代器。  


```java
object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 创建集合  
    val list=List(1,2,3)  
    // 创建数组  
    val arr=Array(1,2,3)  
    // 转为迭代器  
    var it=list.toIterator  
    var it1=arr.toIterator  
    // 遍历迭代器it的元素  
    while (it.hasNext){  
      println(it.next())  
    }  
    // 遍历迭代器it1的元素  
    while (it1.hasNext){  
      println(it1.next())  
    }  
  }  
}  
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/6dc339d6d22a4f9e9a89c572be8db88d.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/875e3b4dd3a948ae9f5668623bd110ad.png)




