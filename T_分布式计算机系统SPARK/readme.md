
#  这次用的是头歌平台，头歌平台要比 力扣等要难一点（主要是获取答案）
其次是你要记住一些代码编写的技巧
以这次Set集合的使用为例子


## 读取给定字符串  
```java
 val line=StdIn.readLine() 
```
    val line=StdIn.readLine() 
    
## 切割字符串，获取单词数组  
 ```java
  val arr=line.split(",")
```

## 接收数据（一个一个数据接受到变量）
```java
 val n=StdIn.readInt()  
```


## 接收数据（一行数据接受到数组）

```java
 var line =StdIn.readLine()  
```
## 创建一个数组
```java
  var arr = new ArrayBuffer[Int]()  
```

## 数组转换成整数型数组
```java
      var line1=line.toInt  
```

## 插入交集

```java
  arr.insert(x-1,line1)  
```



···
完整代码
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
