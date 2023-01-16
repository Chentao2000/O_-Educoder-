# 2.3-8 顺序表和链表的比较
![在这里插入图片描述](https://img-blog.csdnimg.cn/b8b16fcc7f91443d9502ed7930f89f84.png)

## 1、逻辑结构、存储结构、优缺点
|  | 逻辑结构| 存储结构| 优点| 缺点|
|--|--|--|--|--|
| 顺序表 | 线性表 |顺序存储|支持随机存取、存储密度高|大片连续空间分配不方便，改变容量不方便
| 链表| 线性表|链式存储|离散的小空间分配方便，改变容量方便|当要查找第i个结点时，一定要从表头结点依次查找，不可随机存取，存储密度低




## 2、**基本操作：创销、增删改查**

 - **初始化表：**
（链表✔）
![在这里插入图片描述](https://img-blog.csdnimg.cn/c489f42c93c14f37a1dfe361fe064e1b.png)
 - **删除表：**
 （链表✔）
顺序表又分为静态分配和动态分配
![在这里插入图片描述](https://img-blog.csdnimg.cn/d06c077df2634382888aa2903867958d.png)

 - **插入/删除：**
 （链表✔）
![在这里插入图片描述](https://img-blog.csdnimg.cn/c47035bb589541cca265955c35cdb4bc.png)
 - **查找：**
 （顺序表✔）
![在这里插入图片描述](https://img-blog.csdnimg.cn/beb3d97df7ed4223ae9bfe2f015fb69d.png)
用顺序表or链表？：
![在这里插入图片描述](https://img-blog.csdnimg.cn/4aa0231d6922450c96d66b3fdb90d710.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/cbd2431bab504d33aab0cd473e821e4d.png)
开放式问题思路要清晰：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6b1ef7eb31844277bc58feabcc286a81.png)
