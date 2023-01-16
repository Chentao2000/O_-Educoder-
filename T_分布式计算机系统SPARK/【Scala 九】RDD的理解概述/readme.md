## RDD介绍

![112a5a56ddee8f7350e4ffa657c22fa](https://user-images.githubusercontent.com/68007558/174552579-e709a113-b352-4d92-b5f9-6bccf2da647e.png)



RDD 是Spark的核心抽象，即 弹性分布式数据集  
代表一个 不可变 可分区 里面元素可以并行计算的集合  
其具有数据流模型的特点 ： 自动容错 ，位置感知性调度和可伸缩性  

在Spark中 ，对数据的所有操作不外乎创建 RDD，转换成已有的RDD以及调用RDD操作进行求职

![1655710966207](https://user-images.githubusercontent.com/68007558/174550401-f37b4e01-893b-4680-816c-eabc2db3b449.png)


## RDD具有五大特性 :
1. 一组分片： 一组分片（Partition），即数据集的基本组成单位（RDD是由一系列的partition组成的）。将数据加载为RDD时，一般会遵循数据的本地性（一般一个HDFS里的block会加载为一个partition

2. RDD之间的依赖关系。依赖还具体分为宽依赖和窄依赖，但并不是所有的RDD都有依赖。为了容错（重算，cache，checkpoint），也就是说在内存中的RDD操作时出错或丢失会进行重算。

3. 由一个函数计算每一个分片。Spark中的RDD的计算是以分片为单位的，每个RDD都会实现compute函数以达到这个目的。compute函数会对迭代器进行复合，不需要保存每次计算的结果。

4. （可选）如果RDD里面存的数据是key-value形式，则可以传递一个自定义的Partitioner进行重新分区

5. （可选）RDD提供一系列最佳的计算位置，即数据的本地性

## RDD之间的依赖关系:

RDD之间有一系列的依赖关系，依赖关系又分为窄依赖和宽依赖。

## 窄依赖：
```
父RDD和子RDD partition之间的关系是一对一的。
或者父RDD一个partition只对应一个子RDD的partition情况下的父RDD和子RDD partition关系是多对一的，
也可以理解为没有触发shuffle。

```

## 宽依赖
```
父RDD与子RDD partition之间的关系是一对多。
父RDD的一个分区的数据去到子RDD的不同分区里面。也可以理解为触发了shuffle。
```

![1655711268534](https://user-images.githubusercontent.com/68007558/174551360-7fd1a6ec-e6a4-418a-a382-9c206c0dfed1.png)

# RDD创建
1. 从Hadoop文件系统（或与Hadoop兼容的其他持久化存储系统，如Hive、Cassandra、HBase）输入（例如HDFS）创建。1

2. 通过集合进行创建。
![1655711284740](https://user-images.githubusercontent.com/68007558/174551458-fc989be9-f021-4dcd-8227-8706b509ff62.png)

# 算子

算子可以分为Transformation 转换算子和Action 行动算子。
RDD是懒执行的，如果没有行动操作出现，所有的转换操作都不会执行。


--


