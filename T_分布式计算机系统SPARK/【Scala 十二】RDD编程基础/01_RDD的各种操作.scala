//  1. 使用 textFile()方法从本地文件系统中加载数据创建RDD:
val lines = sc.textFile("file:///home/hadoop/word.txt")
// 执行sc.textFile()方法后，Spark从本地文件word.txt中加载数据到内存
// 在内存中生成一个RDD对象lines， 这个RDD里面包含了若干个元素
// 每个元素类型都是String类型，也就是说 ，从word.txt文件读取出来每一行的文本内容
// 都回成为RDD中的每一个元素

// 2. 使用map()函数转换成 相应的键值 对 RDD:
val lines = sc.textFile("file:///home/hadoop/word.txt")
val pairRDD  = lines.flatMap(line => line.split(" ").map(word => (word,1)))

// map(word => (word,1))函数的作用去除素，也就是每个单词，赋值给word，然后把word转换成 (word,1) 的键值对形式

// filter(func) 筛选出满足func 的元素 ，并返回一个新的RDD
val lines = sc.textFile("file:///home/hadoop/word.txt")  
val linesWithSpark = lines.filter(line => line.contains("Spark"))  

//**map(func)**：将每个元素传递到函数func中，并将结果返回为一个新的RDD，示例如下：  
val lines = sc.textFile("file:///home/hadoop/word.txt")  
val words = lines.map(line => line.split(" "))  

//**groupByKey()**：应用于(K,V)键值对RDD时，返回一个新的(K, Iterable)形式的RDD，示例如下：

val lines = sc.textFile("file:///home/hadoop/word.txt")  
val words = lines.flatMap(line => line.split(" ")).map(word => (word,1)).groupByKey()

// **sortByKey()**：应用于(K,V)键值对RDD时，返回一个新的根据key排序的RDD，示例如下：

val pairRDD = sc.parallelize(Array("Hadoop",3),("Spark",5),("Hive",2))  
pairRDD.sortByKey().foreach(println)  
// **partitionBy(partitioner: Partitioner)**：根据partitioner函数生成新的ShuffleRDD，将原RDD重新分区，示例如下：  
val pairRDD = sc.parallelize(Array("Hadoop",3),("Spark",5),("Hive",2))  
pairRDD.keys.foreach(println)  
