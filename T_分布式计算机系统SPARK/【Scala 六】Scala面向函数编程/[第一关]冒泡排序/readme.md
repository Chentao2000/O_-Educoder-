# 任务描述
    本关任务：本关主题是利用Scala基础实现对冒泡排序算法的改进。使用冒泡算法存在这样一种情况：在第j(j<n-1)趟时就已排好序，但算法仍然执行后面几趟的比较。实际上，一旦算法中某一趟比较时没有任何元素交换，说明已经排好序了，就可以结束算法。现有9个随机数：[49,38,65,97,76,13,27,49,78]
    请改进冒泡排序算法，避免序列在已经排好的情况下继续进行冒泡的操作。

相关知识

![在这里插入图片描述](https://img-blog.csdnimg.cn/ab27e1eac4e142f2bdb97848ac3c0e8e.png)

# 冒泡排序
    冒泡排序也称为气泡排序，是一种典型的交换排序方法。冒泡排序算法的原理如下：
1、比较相邻的元素。如果第一个比第二个大，就相互交换。
2、对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。最后的元素应该会是最大的数。
3、针对所有的元素重复以上的步骤，除了最后一个。
4、持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

```java
object BubbleSort {  
      def main(args: Array[String]): Unit = {  
          val sortArray=Array(49,38,65,97,76,13,27,49,78）  
          // 循环完成一次外循环后 就会得到 一次最大值 ，最大值将不再参与排序  
          for( j <- 0 until( sortArray.length -1)){    
              for(i<- 0 until sortArray.length - 1 -j ){// 对每个外循环和进行多次内循环  
                  if(sortArray(i) > sortArray(i+1)){  
                       val temp = sortArray(i)  
                       sortArray(i) = sortArray(i+1)  
                       sortArray(i+1) = temp  
                  }       
              }  
          }  
          sortArray.foreach(x=> print(x + " "))  
          println()  
     }  
}  

```
