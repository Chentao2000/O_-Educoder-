# 2.3-7 静态链表
![在这里插入图片描述](https://img-blog.csdnimg.cn/8ec5beb526c845bca9290b82a4c53583.png)
## 1、什么是静态链表
 - 单链表各个结点在内存中星罗棋布并且每个结点由数据元素和指向下一个结点的指针（地址）构成
 - **静态链表：分配一整片连续的内存空间，各个结点集中安置**
![在这里插入图片描述](https://img-blog.csdnimg.cn/a7e763c1e8cc48848ed508df7979e96a.png)
 - 静态链表中每个结点存放数据元素和下一个结点的数组下标
 - 头号指针（下标为0）不存放实际的数据元素
 - 如图所示，头结点的下一个结点的下标为2，下标为2的结点的下一个节点的下标为1，再下一个结点的下标为1...
 - 故灰色部分的游标充当“指针”，只不过指针指明了具体地址，但游标只是指明了下标
 - **游标为-1表示已经到达表尾，-1也就相当于NULL**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/e486775abae8449d8819faf92f59b9e2.png)
 ## 2、如何代表定义一个静态链表
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/c808af59c0b344c4a47d47d4347f7331.png)
课本上的定义：
![在这里插入图片描述](https://img-blog.csdnimg.cn/cb02cee9cdf64e02ae387fd608e06922.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/e8cb437fc5e0416b887b57c5582bf91e.png)
- 等价于，先定义一个结构体，这个结构体叫做struct Node，最后一行再用typedef把struct Node改名为SLinkList[MaxSize]
- 即如果用SLinkList定义一个变量a的话，就相当于声明了一个数组，并且这个元素数组有MaxSize个
![在这里插入图片描述](https://img-blog.csdnimg.cn/0b715d8ddb7f41d69bef552dc16511fe.png)
## 3、简述基本操作的实现
![在这里插入图片描述](https://img-blog.csdnimg.cn/3ee52f3d86ae41adb66a2065138fdd9e.png)

**故在初始化的时候，也要把空闲的结点标记出来以便使用**
## 4、知识回顾与重要考点
![在这里插入图片描述](https://img-blog.csdnimg.cn/b4f580c0fd3346a6b10e595d1ca00b3e.png)（模糊字段：数据元素数量固定不变的场景）
