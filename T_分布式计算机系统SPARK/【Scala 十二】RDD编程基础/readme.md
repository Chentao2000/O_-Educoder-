# 任务描述
本关任务：编写Spark独立应用程序实现数据去重。


![1655714723985](https://user-images.githubusercontent.com/68007558/174562541-5c3835ed-7812-4450-8f55-bc639eed1303.png)


# RDD的创建
1. 使用textFile()方法从本地文件系统中加载数据创建RDD，示例如下：  
```java
val lines = sc.textFile("file:///home/hadoop/word.txt")  

```

2. 使用map()函数转换得到相应的键值对RDD，示例如下：
```java
val lines = sc.textFile("file:///home/hadoop/word.txt")  
val pairRDD = lines.flatMap(line => line.split(" ")).map(word => (word,1))  
```

上面示例中，map(word=>(word,1))函数的作用是取出RDD中的每个元素，也就是每个单词，赋值给word，然后把word转换成 (word,1) 的键值对形式

## RDD的转换操作

对于RDD而言，每一次转换操作都会产生新的RDD，供给下一个操作使用。RDD的转换过程是惰性求值的，也就是说，整个转换过程只是记录了转换的轨迹，并不会发生真正的计算，
只有遇到行动操作时，才会触发真正的计算。常见的RDD转换操作如下所示：

1. **filter(func)**：筛选出满足函数func的元素，并返回一个新的RDD，示例如下：
```java
val lines = sc.textFile("file:///home/hadoop/word.txt")  
val linesWithSpark = lines.filter(line => line.contains("Spark"))  
```
2. **map(func)**：将每个元素传递到函数func中，并将结果返回为一个新的RDD，示例如下：
```java
val lines = sc.textFile("file:///home/hadoop/word.txt")  
val words = lines.map(line => line.split(" "))  
````
3. **groupByKey()**：应用于(K,V)键值对RDD时，返回一个新的(K, Iterable)形式的RDD，示例如下：
```java
val lines = sc.textFile("file:///home/hadoop/word.txt")  
val words = lines.flatMap(line => line.split(" ")).map(word => (word,1)).groupByKey()
```
4. **sortByKey()**：应用于(K,V)键值对RDD时，返回一个新的根据key排序的RDD，示例如下：
```java

val pairRDD = sc.parallelize(Array("Hadoop",3),("Spark",5),("Hive",2))  
pairRDD.sortByKey().foreach(println)  
```
5. **partitionBy(partitioner: Partitioner)**：根据partitioner函数生成新的ShuffleRDD，将原RDD重新分区，示例如下：  
```java
val lines = sc.textFile("file:///home/hadoop/word.txt", 3)  
val words = lines.flatMap(line => line.split(" ")).map(word => (word,1)).partitionBy(new HashPartitioner(1)) 
```
6. keys：将键值对RDD中所有元素的key返回，形成一个新的RDD，示例如下：  

```java
val pairRDD = sc.parallelize(Array("Hadoop",3),("Spark",5),("Hive",2))  
pairRDD.keys.foreach(println)  
```


![1655715130590](https://user-images.githubusercontent.com/68007558/174563844-5b8ad158-7fbb-47a5-90fc-f7a9954da927.png)







