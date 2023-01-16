# 3.1_1 栈的基本概念
## 1、栈的基本概念
 - **栈是只允许在一端进行插入或删除操作的线性表**
 - **重要术语：栈顶、栈底、空栈**
 - **逻辑结构：与普通线性表相同（线性结构）**
 - **数据的运算：与普通线性表插入、删除操作有区别**
 - **栈顶可插入和删除**
 - **栈底不允许插入和删除**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/ae8982b4f8c34b1ba283b3240e808a0d.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/9a62f98337744edbb0823b8b1346a40a.png)



![在这里插入图片描述](https://img-blog.csdnimg.cn/b4db010fda684ee5ac918c2fe9888587.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/bed6cba71b3b40a9a372c1b5f130d764.png)
## 2、栈的基本操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/4385e40d9f214b60bfee9f828c28a173.png)
## 3、卡特兰数
![在这里插入图片描述](https://img-blog.csdnimg.cn/3730773ac42a4d21b51a7e4891748be6.png)
## 4、知识回顾与重要考点
![在这里插入图片描述](https://img-blog.csdnimg.cn/2b4d32ffa1824d7ea063ed2f3775a323.png)
# 3.1_2栈的顺序存储实现
**用顺序存储方式实现的栈**
![在这里插入图片描述](https://img-blog.csdnimg.cn/ea515ed0fd9e44b59b711b6880bd497e.png)
**顺序栈的缺点：栈的大小不可变**
## 1、顺序栈的定义
![在这里插入图片描述](https://img-blog.csdnimg.cn/aac1b9f00a9846ecbb16e6ec51b64cbf.png)
 - **顺序存储：给各个数据元素分配连续的存储空间，大小为MaxSize*sizeof(ElemType)**
 - **sq：sequence---顺序** 
 - **top：栈顶指针，也是数组的下标，从0开始**
![在这里插入图片描述](https://img-blog.csdnimg.cn/8d4d8fe2524a4624977ce0076cd5d864.png)
## 2、初始化操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/761e5770ea434cff8c1b57a490a6cd47.png)
 - **刚开始栈顶指针指向0这个位置是不合理的，因为这时栈中并没有数据元素，故top此时指向-1**
 - **故判断是否栈空只要判断top是否指向-1即可**
![在这里插入图片描述](https://img-blog.csdnimg.cn/dc5948b2ce884c66928a4b18140f9f61.png)
## 3、进栈操作
![在这里插入图片描述](https://img-blog.csdnimg.cn/bdfd36f69d1d4f6a84bb2fb3c2fdf2c5.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/d93aed9b72be428c9031b86fb77108dc.png)
**如果上下两句代码颠倒，则等价于：`S.data[S.top++]=x;`**

 - **因为MaxSize相当于元素个数，故top（相当于下标）不能超过MaxSize-1**
 - **S.data[S.top] = x;把数据元素传到data数组中tpp指针所指向的地方**
 ## 4、出栈操作
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/043c17dadb9e45cf8cf45668a50185c5.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/b40ac3b984dd4c0b8d1dce9457160fc4.png)
 ## 5、读栈顶元素操作
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/9fb9c4691a3449a5b0ecaaa1fbbde327.png)
 **读栈顶元素操作与出栈操作的唯一区别：**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/390fe783010246f89b77e2fddd230a04.png)
 ## 6、另一种方式：top初始指向0（审题时要注意）
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/c3750d76a74f4d74986770dfb0a10835.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/9bcad7012d8447aba0fa34b3f45ce6b0.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/65c3f1ba21a0447c83c916842160ddd3.png)
 ## 7、共享栈
  - 两个栈共享同一片空间
  - 可以提高空间的利用率
  - 设置两个栈顶指针（如0号栈top0和1号栈top1）
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/15ce3eabf3f84edfabae2639b6dc79f0.png)
0号栈从下往上依次递增，1号栈从上往下依次递增
 - ![在这里插入图片描述](https://img-blog.csdnimg.cn/3a1c2ed727a34890b8cb1b94f8e1f46f.png)
 - **栈满条件：top0 + 1 == top1**
## 8、知识回顾与重要考点
![在这里插入图片描述](https://img-blog.csdnimg.cn/579c64fc6a3741a888609c3c3587bcda.png)
（最后一行：栈满条件）
# 3.1_3 栈的链式存储实现
![在这里插入图片描述](https://img-blog.csdnimg.cn/21f71fac28904fd2a2854dc553b1561d.png)
## 1、链栈的定义
 - **头插法建立单链表 -> 进栈操作**
 - **对头结点的“后删”操作 -> 出栈操作**
![在这里插入图片描述](https://img-blog.csdnimg.cn/252dcd4a82a742a0961352f686b6992f.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/241130044ad141b3a09b8b00f10c70d7.png)


