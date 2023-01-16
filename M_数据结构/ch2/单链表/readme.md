# 2.3 单链表
## 2.3.1 单链表的定义
![在这里插入图片描述](https://img-blog.csdnimg.cn/8a737f5a3f05466d96f47c0209a0ad9e.png)
## **什么是单链表？**
![在这里插入图片描述](https://img-blog.csdnimg.cn/e6d9d6607ceb41e9a4a395cced12a2ab.png)


****typedef关键字**：数据类型重命名**
**typedef <数据类型> <别名>**
如：
 - typedef int zhengshu; 
 - typedef int *zhengshuzhizhen; 
 - 平时我们写的int x=1相当于zhengshu x=1； 
 - 平时我们写的int *p相当于zhengshuzhizhen p;
 
## **定义单链表**
 - **节点和结点的区别**，视频中应该写错了，在数据结构算法中应都为结点。节点呢，被认为是一个实体，有处理能力，比如，网络上的一台计算机；而结点则只是一个交叉点，像“结绳记事”，打个结，做个标记，仅此而已，还有就是，要记住：**一般算法中点的都是结点**。
 - **法一**：先struct定义结构体再用typedef重命名![在这里插入图片描述](https://img-blog.csdnimg.cn/2a58ba5c9c5f4807bc31f878ae0dd968.png)

 - **法二（最简单）**：
 - ![在这里插入图片描述](https://img-blog.csdnimg.cn/58eb98b182674baea6fd991c4ba04434.png)这里直接同时用typedef和struct，把**单链表结点命名为LNode**，把**指向struct LNode的指针命名为*LinkList**；
 - struct LNode *是指向下一结点的指针，这里名字设为next；
 - 表示一个单链表时，只需声明一个**头指针L**
![在这里插入图片描述](https://img-blog.csdnimg.cn/29d292da4bc84afaa2bb394c8e950d33.png)

## **GetElem**：把链表L中第i个结点取出来并返回
![在这里插入图片描述](https://img-blog.csdnimg.cn/bf40df006bdb4811bac0202149931be4.png)

 - 因为要返回第i个结点，故要用LNode*来强调返回的是结点；
 - 又因为要从单链表中寻找第i个结点，故要后面的LinkList要强调这是一个单链表
 - **强调这是一个结点用LNode***
 - **强调这是一个单链表用LinkList**

## **初始化单链表**
  - **不带头结点时(不带头结点就是，指针L只能指向第一个数据元素，当在第一个数据元素的位置进行插入或删除操作时，要注意让L指向新的结点，L保持指向第一个数据元素的位置；而且只是声明了一个指针L，并没有和带头结点时一样申请空间给头结点)**![在这里插入图片描述](https://img-blog.csdnimg.cn/71967e6350f24d13948054c764fa9ca3.png)
 - **带头结点时**，在**初始化时会用malloc申请一片空间存头结点，并把地址赋给头指针L**，再把next指针设为NULL，头结点不存储数据
![在这里插入图片描述](https://img-blog.csdnimg.cn/ab2911eaf21143bf9d67fe7491da567b.png)**如果头结点之后暂时没有节点，即L->next = NULL，指向下一个指针为空，那么这个单链表就是空链表。**
 - 传入指针变量时传入的是&L，**带有引用&时**是修改头指针L；如果**不带引用&时**则是修改头指针L的复制品。
 - **不带头结点和带头节点的区别**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/c4acfcbe1da640c1923965a69cb181e8.png)
**不带头节点**：头指针L指向的下一结点就是实际用于存放数据的结点。
**带头节点**：**头指针L所指向的下一结点（头结点）是不存放实际的数据的，只有头结点的下一结点才存放数据**。
## 总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/27a2f882b51d45888ba5a088aba7f2b3.png)
#  2.3.2 单链表的插入和删除
![在这里插入图片描述](https://img-blog.csdnimg.cn/576dcea420da46c782772c55095e078f.png)
# 1、按位序插入（带头结点）
**ListInsert(&L, i, e)**
插入操作，在表L的第i个位置上插入指定元素e。
因为是在第i个位置上插入结点，故要找到i-1个结点，再将新结点插入其后。
即**先找到第i-1个结点，再用malloc申请一个新的结点存入数据元素e。**
 - **如果i=1则意为插在表头**
 - **头结点看作是第0个结点，即j=0**
 - **j用来记录p当前指向哪个结点**
![在这里插入图片描述](https://img-blog.csdnimg.cn/5ea277d108f54c9dba89677bdae6bb18.png)
最坏时间复杂度为O（n）：插到最后面时
故平均复杂度为O（n），取最长时间

```cpp
LNode *s = (LNode *)malloc(sizeof(LNode));
//申请新的结点空间,并用指针s指向它
s->data=e;
//把参数e存入新结点中
s->next=p->next;
//s指向结点的下一个指针next，等于p指向结点的下一个指针next
p->next=s; 
//将结点s连到p之后
return true；
//插入成功
```
**s->next=p->next;和p->next=s; 这两句顺序不能颠倒，否则指针只会指向自己**
要先连接后面再连接前面![在这里插入图片描述](https://img-blog.csdnimg.cn/50673496401b44a8b955ed14569edd04.png)
## 2、按位序插入（不带头结点）
**ListInsert(&L, i, e)** (同上)
由于不存在头结点故不存在”第0个“结点，因此i=1时需要特殊处理。
**如果不带头结点，则插入，删除第1个元素时，需要更改头指针L，让L指向新的结点。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/55a2f4fa0ef442789f11747489531a17.png)
**除了考虑当i=1时的情况，也就是插入第1个结点的操作与其他结点操作不同。后续逻辑和带头节点的一样。**
## 3、指定结点的后插操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/55da3e6b948c44829dff96aa44007d11.png)

## 4、指定结点的前插操作
**在p结点之前插入元素e**
单链表的特性：**已知一个指定节点的地址，因为这个节点中只保存一个 next 指针**，所以只知道后面的区域，而不知道前面的区域。
**故申请一个新的结点在p指向结点的后面，新的结点再复制p结点的数据，再把e的数据放到p结点中**

![在这里插入图片描述](https://img-blog.csdnimg.cn/ee34d0b84d08487882474d41d56a5f82.png)王道书版本中直接传入了新的要插入的结点s：
![在这里插入图片描述](https://img-blog.csdnimg.cn/3bdd25016ba94df1a11f4400fe44eeb8.png)
**先把s连到p的后面，然后申明一个temp变量把p结点的内容保存下来，再把s的内容复制到p里面，再把temp中的内容复制s里面。**
## 5、按位序删除（带头节点）

**ListDelete（&L，i，&e）**：删除操作
 - 删除表L中第i个位置的元素，并用e返回删除元素的值。
 - **因为删除第i个位置的元素，故要找到i-1个结点，将其指针指向第i+1个结点，并释放第i个结点。**
 - 因为要带回e，故传入时要用&e
![在这里插入图片描述](https://img-blog.csdnimg.cn/a8119f156dac49d68f9e6986fe50c837.png)![在这里插入图片描述](https://img-blog.csdnimg.cn/79b3a6dcb79f4f979aef6e2b328c5324.png)
## 6、指定结点的删除
*bool DeleteNode(LNode *p)**
删除p的下一个结点q
![](https://img-blog.csdnimg.cn/842af7395ff84d30a583b1434d32b053.png)
p->data = p->next->data;
//p的数据，等于p指向的下一个结点的数据
![在这里插入图片描述](https://img-blog.csdnimg.cn/df6aa3a70ea04658b2f50c19e58826cc.png)
但如果删除的是最后一个结点，这个结点指向的时NULL，那么就不存在q->next，故上面的代码就会报错（但王道书上也是这个代码）
![在这里插入图片描述](https://img-blog.csdnimg.cn/42f5a9154831414e8e437f340736c094.png)
**故这里也体现了单链表的局限性，无法逆向检索。
故这里就有了双链表，即可以双向检索的链表。
**
## 7、总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/b392922c773b4afd9e250299655846e5.png)
封装的好处：

![在这里插入图片描述](https://img-blog.csdnimg.cn/e655c6442b554f6783cfe9cdaede2358.png)可以直接return使用

## 2.3.3 单链表的查找
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/e515f494eb954d13b1801fa1f34c850e.png)
 ## 1、按位查找
 p刚开始指向第0个结点
 
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/ca9f0673002d4c7d8249d6dcab0b54f0.png)
 王道书版本：
 p刚开始指向第1个结点
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/a82188613b424f71b53675b0b3eaa5c1.png)
封装的好处：
避免重复代码，调用即可查找
![在这里插入图片描述](https://img-blog.csdnimg.cn/8593333bac1b4191a21c3f80a7ae94ff.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/e2c0532c48fd47c680bc6fc4212f0409.png)
## 2、按值查找
![ ](https://img-blog.csdnimg.cn/79f5dda328e946cb8b9a713d76cfe718.png)
平均时间复杂度：O（n）
LNode *p = L->next; // 让p指向头结点的下一个结点
## 3、求单链表的长度
![在这里插入图片描述](https://img-blog.csdnimg.cn/4d42fd763e2247b2ae103acf2e5a5e59.png)
## 4、总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/d03006dc24e74300b16187e3f920ab07.png)
## 2.3.4 单链表的建立

![在这里插入图片描述](https://img-blog.csdnimg.cn/76e56d5e709c4be7bf578b700547db47.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/6a56c88b9c6543f5bede77c7f187aa82.png)
## 1、尾插法建立单链表
![在这里插入图片描述](https://img-blog.csdnimg.cn/b3ee0c720d11415da14ef67c24824882.png)

  - 用malloc申请一个头结点，并把地址赋给头指针L
 - 9999是自己设置的特殊值，输入9999后结束循环
 - 设置一个表尾指针r，表尾指针从头指针开始
 - 每输入一个值时，都申请一个新的结点s，把输入的值x给s，并让r的next指针指向s
![在这里插入图片描述](https://img-blog.csdnimg.cn/c39fc60980a44a329c0e0b3b79423a56.png)
 - 再让r指针指向新的表尾结点x
![在这里插入图片描述](https://img-blog.csdnimg.cn/9cdf455c28914a42b82ea651b68734e2.png)
 - 输入完后再让尾结点指针指空（NULL）
 - 最后return L；

 ## 2、头插法建立单链表
 即**对头结点进行后插操作**
![在这里插入图片描述](https://img-blog.csdnimg.cn/0f37fd0b388c4f3fbd8df1748e8f1d42.png)
 头插法最后得到的数为输入的数的逆置，
 **即*链表的逆置！！！***。
 

 **注意尾插法可以不用L->next = NULL;但头插法一定要。**
因为尾插法头结点指向的下一个位置的值始终会随着我们输入而变化，但头插法的头结点可能先指向某个不确定区域（脏数据），再通过s->next = L->next使得s也指向这个脏数据。
**故要养成好习惯，只要是初始化单链表，都先把头指针指向NULL**












  
