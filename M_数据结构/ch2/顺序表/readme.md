## 2.1线性表的定义和基本操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/b0965076e6db40eca8f74468451bf2af.png)
## 1、线性表的定义
线性表是具有**相同数据类型**的n(n>=0)个数据元素的**有限序列**，其中n为表长，当n=0时线性表是一个空表。若用L命名线性表，则一般表示为  L = （a1, a2, ... , ai, ai+1, ... , an）
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/87f9b1561bd94535a32741af1aede1bb.png)
 ## 2、线性表的基本操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/8c1361a2a92c440786af1ee524234152.png)
补充tips5：
**什么时候要传入引用“&”：当需要 把参数的修改结果带回来的时候，就需要传入参数的引用“&”**。 
也就是说，如果不用&，那么参数只会在我们定义的函数里面发生变化，调用时不会发生变化，所以要用&，把修改结果带回来。
补充tips6:
在元素“e”中已经定义了数据类型，可以是int也可以是struct等，故在这些操作中不用另外考虑类型。

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/a52cb099e9b143ca8ea9ff44fe432745.png)
 ## 3、总结
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/76485afa20db459f9158702440c83efb.png)
 ## 2.2 顺序表的定义

![在这里插入图片描述](https://img-blog.csdnimg.cn/a10a02054e4d4b39b2ac6e31b11c28da.png)
用**顺序存储**的方式实现线性表的顺序存储。把**逻辑上相邻的元素**存储在**物理位置上也相邻**的存储单元中，元素之间的关系由存储单元的邻接关系来体现。
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/0df3873a4d614780a11d7869b0680b1a.png)
## 1、顺序表的实现--静态分配
所谓的静态分配就是用静态的“数组”存放数据元素（也就是这个数组的长度大小一旦确定之后就不能改变），如果数组存满了就可放弃治疗，因为表长无法更改。
![在这里插入图片描述](https://img-blog.csdnimg.cn/61affdd4a8384866bfc3f450de872ac2.png)

|  **MaxSize**| **最多能存放多少数据元素** |
|--|--|
|**typedef** | **type define，定义类型，可以给已有类型定义新别名，比如这里最后定义的新别名为SqList** |
| **ElemType** | **Element Type ，数据元素类型，可以为int也可以为struct，这里是为了数据结构类型的通用性**  |
| **data[MaxSize]** | **定义了一个静态数组，长度为MaxSize** |
|  **length**| **用来表示顺序表已经存放了多少元素** |
| **SqList** | **Sq：sequence，顺序表的类型定义（静态分配方式）**|

  ![在这里插入图片描述](https://img-blog.csdnimg.cn/40ae50d92b524beab398acdbc61f2b56.png)
 当使用SqList L，声明一个顺序表的时候，内存就开始分配顺序表L的空间（也就是typedef struct所产生的空间）。
由于刚开始一个数据都没有，故length要初始化为0。

## 2、顺序表的实现--动态分配
![在这里插入图片描述](https://img-blog.csdnimg.cn/987b8d9bde104305b522f5d496a8c1a5.png)
|ElemType *data | ElemType *，指示动态分配数组的指针data，指向顺序表中的第一个元素 |
|--|--|
|**malloc函数（C）**  | **L.data = (ElemType*)malloc(sizeof(ElemTpye)*InitSize) 申请一整片的连续存储空间并且返回一个指针，这里需要强制转型为你定义的数据元素类型指针，如这里的ElemType *，如果数据表是用来存放整数int的，那么这里的ElemType可换成int;sizeof(ElemTpye)就是一个数据元素所占空间的大小，*InitSize即乘上顺序表的初始长度**|
 | **SeqList**|**顺序表的类型定义（动态分配方式）** | 

![在这里插入图片描述](https://img-blog.csdnimg.cn/0d5b5296421d427fa25d10cccbe77ee7.png)
malloc中要强制转型的原因：
![在这里插入图片描述](https://img-blog.csdnimg.cn/8774b3c9c79e4007a036bb4ae44aa902.png)int*表示两个p指针之间要隔着四个字节


 1. SeqList L 声明一个顺序表，内存开始分配顺序表的空间，包括MaxSize、length还有*data；
 2. InitList（L）初始划顺序表，即调用InitList函数，用malloc申请一整片连续的存储空间InitSize*sizeof（int）并返回这一连续存储空间的起始地址，再把返回指针的类型转型为int *，并赋给data，故现在指针指向这一存储空间的起始地址data[0]![在这里插入图片描述](https://img-blog.csdnimg.cn/9fb50176cd15424683443f2c2f6faac2.png)橙色区域即为malloc申请的一片连续的存储空间；
 3. IncreaseSize（L，5）即动态增加动态数组的长度，定义IncreaseSize中的len即为要增加的长度；
 4. int *p=L.data，定义一个指针p（紫色区域），把顺序表的data指针赋给p，也就是*p和data[0]指向同一个位置；![在这里插入图片描述](https://img-blog.csdnimg.cn/fc1d41f2a13540d0a909348d6809d696.png)

 5. 再用malloc函数，开辟新的空间（黄色区域），长度为L.MaxSize+len,并让data指针指向新的内存空间，再用for循环把以前内存空间的数据挪过来并更新MaxSize的值。
 6.   free（p）把p指针所指向的一整片存储空间（橙色区域）给释放掉，存储p的区域也一并回收（紫色区域）。
 
 ## 总结
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/8dda30dbba1c4ffe811f0525b01a4afe.png)
 ## 2.2 顺序表的插入和删除
 
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/3e75c75da4cb47be996527b4389800fa.png)
 ## 1、顺序表的基本操作--插入
ListInsert(&L, i, e)：插入操作。在表L中的第i个位置上插入指定元素e。
插入也就是，插入位置后面的所有数都往后挪一位，在把元素插入指定位置。
![在这里插入图片描述](https://img-blog.csdnimg.cn/ec951f5bea3c422aad3083d8aebedbd4.png)
L.data[i-1]=e;由于线性表的内序i是从1开始的，但数组是从0开始的，所以需要i-1
## 2、用bool提升插入算法的健壮性
可以让函数返回bool型的变量既可用来判断i的范围是否有效也可判断存储空间是否已满，最后也可和上面的函数一样带回新的列表
![在这里插入图片描述](https://img-blog.csdnimg.cn/53b1aae58f9a49e0a410878c793c93eb.png)
如从最后一个如第五个开始退，那么第五个位置就要存第四个位置的值，接下来到第四个，第四个位置要存第三个位置的值....，再到第i个
## 3、插入操作的时间复杂度
求其时间复杂度即要关注最深层循环语句的执行次数与问题规模n的关系。
现在的问题规模n = L.length（表长）
|  情况 | T（n） | 备注|
| --| --| --| 
| 最好情况 |T(n) = O(1) |插入最后一位，i = n+1，其他元素不需要移位，故需要循环0次 | 
| 最坏情况 | T(n) = O(n)| 插入到表头，需要将原有的n个元素全都向后移动，i=1，循环n次|
| 平均情况| T(n)= O(n) |假设新元素插到任何一个位置的概率相同，即i = 1，2，3，...，length+1的概率都是p=1/n+1 ，而且i=1，循环n次；i=2，循环n-1次....那么平均循环次数=np+(n-1)p+(n-2)p+...+1*p=n/2  => T（n ）= O（n/2）= O(n) 
## 4、顺序表的基本操作--删除
ListDelete（&L，i，&e）：删除操作，删除表L中的第i个位置的元素，并用e返回删除元素的值。即把删除位置后面的所有元素往前移一位
![在这里插入图片描述](https://img-blog.csdnimg.cn/6b3d22fc628d4f00b14c1d74b3a419f3.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/9e901b41dcd24d8da72c644627f29480.png)
int e = -1 是为了先定义变量e，方便下面调用函数把e的值带回来
## 5、删除操作的时间复杂度
|  情况 |T(n) | 备注|
| --| --| --| 
| 最好情况 |T(n) = O(1) |删除表尾元素，i=n，循环0次 | 
| 最坏情况 | T(n) = O(n)| 删除表头元素，需要将后续的n-1个元素全都向前移动，循环n-1次|
| 平均情况| T(n)= O(n） |假设删除任何一个元素的概率相同，即i=1，2，3，...,length的概率都是p=1/n；i=1,循环n-1次；i=2，循环n-2次；...;i=n，循环0次。那么平均循环次数=(n-1)p + (n-2)p + ... + 1*p = (n-1)/2 = O(n)

## 6、顺序表插入和删除操作的总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/52b8f8702cf14d298a8f9c552bdabf98.png)
## 7、顺序表的查找
![在这里插入图片描述](https://img-blog.csdnimg.cn/de5e2f77e47f478093212856a64ed5ee.png)
## 按位查找
GetElem(L, i):按位查找操作。获取表L中第i个位置的元素的**值**。

 1. 静态分配的情况下![在这里插入图片描述](https://img-blog.csdnimg.cn/a3858fd340f3415cbd3bbbe515b8a9f2.png)这里要注意的是i-1才是下标
 2. 动态分配的情况下
![在这里插入图片描述](https://img-blog.csdnimg.cn/6147a9196fe14a4294704c74df66146a.png)
## 按值查找
LocateElem(L, e)：按值查找操作。在表L中查找具有给定关键字值的元素的**位置**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/ff3c10827a4544f093238784f3af2766.png)
## 8、按值查找的时间复杂度
|  情况 |T(n) | 备注|
| --| --| --| 
| 最好情况 |T(n) = O(1) |目标元素在表头，循环一次 | 
| 最坏情况 | T(n) = O(n)| 目标元素在表尾，循环n次|
| 平均情况| T(n)= O(n） |假设删除任何一个元素的概率相同，即i=1，2，3，...,length的概率都是p=1/n；循环元素在第1位，循环1次，第二位，循环2次，...，在第n位，循环n次；平均循环次数=1*1\n + 2*2\n +...+n*1/n = (n+1)\2
## 9、顺序表中按位查找和按值查找的总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/1d98b28efd36488b9cf042ca3520d783.png)







