![image](https://user-images.githubusercontent.com/68007558/174548423-d974a151-8dd9-4d3f-8fb3-1c891d3866b3.png)




基本概念：

- Application：用户编写的Spark应用程序，包含一个Driver和多个Executor。

- Driver：Spark中的Driver即运行上述Application的main函数并创建SparkContext，创建SparkContext的目的是为了准备Spark应用程序的运行环境，在Spark中有SparkContext负责与 ClusterManager通信，进行资源申请、任务的分配和监控等，当Executor部分运行完毕后，Driver同时负责将SparkContext关闭。  

- Executor：是运行在工作节点WorkerNode的一个进程，负责运行 Task。

- RDD：弹性分布式数据集，是分布式内存的一个抽象概念，提供了一种高度受限的共享内存模型。

- DAG：有向无环图，反映RDD之间的依赖关系。

- Task：运行在Executor上的工作单元。

- Job：一个Job包含多个RDD及作用于相应RDD上的各种操作。

- Stage：是Job的基本调度单位，一个Job会分为多组Task，每组Task被称为Stage，或者也被称为TaskSet，代表一组关联的，相互之间没有Shuffle依赖关系的任务组成的任务集。

- Cluster Manager：指的是在集群上获取资源的外部服务。目前有三种类型： 
- -- 

1. Standalon：Spark原生的资源管理，由Master负责资源的分配；
2. Apache Mesos：与Hadoop MR兼容性良好的一种资源调度框架；
3. Hadoop Yarn：主要是指Yarn中的ResourceManager。
# Spark运行流程：  

![image](https://user-images.githubusercontent.com/68007558/174548588-84b50c6d-8f37-427f-bf8a-6a0f3acf89b5.png)


1. 构建Spark Application的运行环境，启动SparkContext；
2. SparkContext向资源管理器（可以是Standalone，Mesos，Yarn）申请运行Executor资源；
3. Executor向SparkContext申请Task；
4. SparkContext构建DAG图，将DAG图分解成Stage 、并将 Stage封装成Taskset发送给Task Scheduler，最后由Task Scheduler将Task发送给Executor运行；
5. Task在Executor上运行，运行完释放所有资源。

