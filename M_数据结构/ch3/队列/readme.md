# 3.2_2 队列的基本概念 
 - **队列（Queue）是只允许在一端进行插入，在另一端删除的线性表**
 - **重要术语：队头、队尾、空队列**
 - **队尾：允许插入元素的一端**
 - **队头：允许删除元素的一端**
 - **特点：先进先出（FIFO）**
![在这里插入图片描述](https://img-blog.csdnimg.cn/3ebafed60185449c9b117be56654e17c.png)
## 1、队列的基本操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/77f7d166a9a847f1b4e6fa6ea15fdc05.png)
## 2、总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/320de3b799144f36a0a4328b5d45d5c1.png)
# 3.2_2队列的顺序实现

![在这里插入图片描述](https://img-blog.csdnimg.cn/09965efa2daf40a882bb5681a7137f67.png)
## 1、定义队列
![在这里插入图片描述](https://img-blog.csdnimg.cn/202e7dbf0a32492fbe5e5719d97721db.png)
## 2、声明队列
![在这里插入图片描述](https://img-blog.csdnimg.cn/6a9b9aa44945478a92719c20224dc65d.png)
## 3、初始化队列
 - **初始化时让队尾指针（rear）和队头指针（front）同时指向0**
 - **队尾指针rear指向队尾元素的下一个元素**
 - **队头指针front指向队头元素**
![在这里插入图片描述](https://img-blog.csdnimg.cn/2f40b9ac2ddb4de0944f64888a5bc432.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/4358fd1fb87a40c996715071bbfacd97.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/e2a8dde17a0b422f92caf9339839a100.png)
## 4、入队（插入）操作
**只能从队尾插入**

![在这里插入图片描述](https://img-blog.csdnimg.cn/07127a7cac0a459ba63533721ba1a907.png)
 -  **队列已满的条件并不是rear = MaxSize**
 - **因为当rear指向MaxSize时，front还可以移动出列，此时队列并不是满的**![在这里插入图片描述](https://img-blog.csdnimg.cn/562377072791476b8c718ea0dc5425ff.png)
 - **故当rear在队尾，并且队列未满，要继续进行插入操作时，rear需要重新指向data[0]。**
 - **这时需要在队尾指针加1再对队长取余使rear重新指向0**
 - **这种方法可以得出rear将要去的下一个指针，可以应对插入时包含上种情况（rear在队尾，并且队列未满）的所有情况，比如，先把下标为4的元素插入到队尾，再（4+1）%10=5，即队尾指针rear指向下一个下标5**
## 5、循环队列
**通过以上的方法使得每当rear到了队尾但队列还未满时，rear就会变为0，就像下图一样逻辑上形成“环状”**
![在这里插入图片描述](https://img-blog.csdnimg.cn/ba2a0f4d923440299432593e4d2ebb79.png)
## 6、队列已满条件
**如果队尾指针的后一个指针为队头，即队列已满**

![在这里插入图片描述](https://img-blog.csdnimg.cn/31302dfa802d413abfbb1b4991076ba6.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/2dfaa6a0b5b74a40a04c4ae7f1d31a24.png)
 - **而且由于在初始化时，rear=front是用来判断队空的，所以判断队满时要换一个条件，此时判断队满时rear指向的位置不再放新的数据元素，使得队尾指针的下一个位置就是队头指针的位置**
 - **故判断队满的代价就是牺牲一个存储单元**
 - 如果遇到出题老师说不能牺牲这一个存储单元，则可以另外定义一个变量size来记录队列当前长度，size==Maxsize则队满，size ==0则队空。
 - 第二种方法则是，定义一个变量tag，删除时tag=0，插入时tag=1，那么front== rear && tag== 1 则队满，front== rear && tag==0
 ## 5、循环队列---出队操作
 **只能让队头元素出队**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/a09f9f13493947b2b0cb91b41a98461b.png)
 **获得队头元素的值也就是把队头指针后移的代码删掉，不用后移，返回就行：**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/e39f9f67aa3e42528a7e4422323cd80b.png)
 ## 7、队空和队满的总结
  - **队空条件：Q.rear == Q.front**
  - **队满条件：(Q.rear+1)%MaxSize == Q.front**
## 8、队列元素个数
**队列元素个数 = (rear+Maxsize-front)%Maxsize** 

![在这里插入图片描述](https://img-blog.csdnimg.cn/6fe5860800e24d2480283c0aa7b7a761.png)
## 9、其他出题方法
**上面说的方法都是基于队尾指针指向队尾元素的下一位得来的（左），但考试中可能会遇到rear指针直接指向队尾元素的情况（右）**

![在这里插入图片描述](https://img-blog.csdnimg.cn/6feac01913de4c5ebc614fb3a5d4ffad.png)
 - **在入队操作时，先让rear指针往后移一位，即Q.rear = (Q.rear+1)%MaxSize再往这个位置写入新的元素x**
 - **判空：（Q.rear+1）%MaxSize==Q.front**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/73633059cbf84733a561f24b2c17ed54.png)
  - **但判满时则不能用同一条式子了**
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/8f15a4ec8dd940ecab3c47f2e0f011c4.png)
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/59d051ef235d4ced975e8e9ce29eaad9.png)
  ## 10、知识回顾与重要考点
  
![在这里插入图片描述](https://img-blog.csdnimg.cn/e3ec0333184349cb8a4b8fe718476052.png)
# 3.2.3_队列的链式实现
![在这里插入图片描述](https://img-blog.csdnimg.cn/9ecd085d150c49689c6702dd3c7acc21.png)
## 1、定义链式队列结点和指针
 - **之前标记单链表是只需要保存单链表的头指针L就够了，但如果想要在单链表的尾部进行插入操作的时候，需要从头开始遍历到尾部，时间复杂度为O(n)**
 - **而在队列中，每次插入元素都只能在表尾插入**
![在这里插入图片描述](https://img-blog.csdnimg.cn/b63e727a294e486ab938652613936f33.png)
**链队列也可以和链表一样分为带头结点和不带头结点：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/f8e7d31e6e0a4132af8efd7649139bf3.png)
## 2、初始化
**带头结点时：**
 - front和rear都指向头结点
 - 并且front的next指针指向NULL
 - 判空：Q.front == Q.rear
![在这里插入图片描述](https://img-blog.csdnimg.cn/cbb43ee840084c7a84bf729228e84230.png)
**不带头结点时：**
 - front和rear都指向NULL
 - 判空：Q.front==NULL(也可以rear==NULL)

![在这里插入图片描述](https://img-blog.csdnimg.cn/a3879b9ce9054a88a627cf3bf0467890.png)
## 3、入队
**带头结点时：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/3f4aae214e3c45b6a7daa935c609ca9e.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/93874baad118425491bf005e5b20d255.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/b7e7e88c4df7490b94e3be0a7528e3f2.png)
**不带头结点时：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/01c3e4022db64d33abd02de37887f3ff.png)
## 4、出队操作
**带头结点时的队头元素出队：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/510a6900019742a6bbe3ceb8607f3e40.png)
如果在队头元素出队的情况下最后一个结点出队（即没有结点了），那么就要修改rear指针，Q.rear = Q.front,即表示这是空队列。
**不带头结点时的队头元素出队:**
 - 由于没有头结点，故每次出队都要修改front指针的指向
 - 如果是最后一个结点出队，也是要把front和rear同时指向NULL表明是空队列
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/0ea6e86d39cd44f1bc395d355d12f761.png)
## 5、队列满的条件
 - 顺序存储---预分配的空间耗尽时队满![在这里插入图片描述](https://img-blog.csdnimg.cn/d73c179d99754fa2a038dbd376e8b991.png)

 - 链式存储---一般不会队满，除非内存不足![在这里插入图片描述](https://img-blog.csdnimg.cn/f74aef732d4b4828baa2e512115f1da9.png)
 ## 6、知识回顾与重要考点
 
![在这里插入图片描述](https://img-blog.csdnimg.cn/19dd6df494ae4bc79f4f9b143696a539.png)
# 3.2.4_双端队列
**双端队列：只允许从两端插入、两端删除的线性表**
![在这里插入图片描述](https://img-blog.csdnimg.cn/518122d02b604b4b914112bb9ce41851.png)
**双端队列还可以引出输入受限的双端队列（只能一边输入）和输出受限的双端队列（只能一边输出）：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/a8a5a64f82f44981afc1298d8237e258.png)
## 考点：判断输出序列的合法性
## 1、对栈来判断序列的合法性
**如果对栈来说是合法的，那么双端队列一定合法（栈相当于双端队列的一种情况）**

![在这里插入图片描述](https://img-blog.csdnimg.cn/e51d4d7a777f4bddbdba3c6c2bfc37c2.png)
 - **如输出队列是1，2，3，4：**
那么可以输入1，输出1；输入2，输出2；输入3，输出3；输入4，输出4。
 - **如输出队列是2，4，1，3：**
 先输入1、输入2，再输出2；输入3、输入4，再输出4；但是现在栈中剩下1和3了，只能3先出栈，故无法做到1先出栈再到3。
 - **答案**![在这里插入图片描述](https://img-blog.csdnimg.cn/fd07c0d308f24a08a884d59faea0582c.png)
 - **卡特兰数**（要会使用）
![在这里插入图片描述](https://img-blog.csdnimg.cn/0cce50ddedab4bfd9e2b9286810e83c7.png)
## 2、对输入受限的双端队列判断输出序列的合法性
**答案：**
只有两种不合法
![在这里插入图片描述](https://img-blog.csdnimg.cn/4a1e9c246d7e416aafb268c8a7a2c203.png)
## 3、对输出受限的双端队列判断输出序列的合法性
**答案：**![在这里插入图片描述](https://img-blog.csdnimg.cn/70c7efca047e4f9e8c136574483a9ddd.png)
## 4、知识回顾与重要考点
![在这里插入图片描述](https://img-blog.csdnimg.cn/b3abfac19ce3495b9da94bc26f81d07d.png)
