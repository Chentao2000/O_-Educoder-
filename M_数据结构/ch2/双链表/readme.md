# 2.3.5 双链表
![在这里插入图片描述](https://img-blog.csdnimg.cn/011170307d4541a59df6148ad928a28e.png)
## 1、单链表和双链表的比较
![在这里插入图片描述](https://img-blog.csdnimg.cn/2f4c142ee67e42cdb084735d7d9f112f.png)
LNode -> DNode，还加了一个*prior（前驱指针）
## 2、双链表的初始化（带头节点）
![在这里插入图片描述](https://img-blog.csdnimg.cn/008c7d18e7414a20a0cd2e505081f47e.png)
**把前向指针和后向指针都设为NULL：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/71e626d2963e45aabb11cc2bc9593304.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/81d7f4ec4975468794e1be88afb9d3dd.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/28b81e2dc0314ceabbc65914d6722016.png)![在这里插入图片描述](https://img-blog.csdnimg.cn/0f4fb5ff3a524839ba4938e05765a5c8.png)
**只是DLinklist强调是列表，DNode*强调是指针，但都是等价的**

![在这里插入图片描述](https://img-blog.csdnimg.cn/37c1fe65b2ea471d9bc7e5a8d19a4a22.png)
## 3、双链表的插入
![在这里插入图片描述](https://img-blog.csdnimg.cn/4af9251aada14a50bc2524d4ca180a77.png)![在这里插入图片描述](https://img-blog.csdnimg.cn/da191f58f7654adb85c6b99972cd535b.png)
 **步骤：**
1. s指向的下一个节点 = p指向的下一节点 （绿线）
 2. 判断p结点有没有后继节点，有则使p的后继结点（Y）的前向指针指向（=）新插入的s （黄线）
 3. s的前向指针指向p（蓝线）
 4. p的后向指针指向s（橙线）

## 4、双链表的删除
![在这里插入图片描述](https://img-blog.csdnimg.cn/e3459990daa54d85944a6fa60ee1326f.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/9c95670ad0cf44c38ee9864fb2aaccd0.png)
**步骤：**
 
  1. p的下一结点等于q的下一结点（绿线）
  2. q的下一结点的前向指针指向（=）p（黄线）
  3. 再释放q结点

**如何销毁一个双链表：**

用while循环每次删除头结点的后继节点
![在这里插入图片描述](https://img-blog.csdnimg.cn/ad4a40863b744c6cbc2b7a6710076426.png)
## 5、双链表的遍历
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/19d41c0b9d754b058959074812e967a6.png )
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/2433d2b247f94e359e792d9531ac2cff.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/3463862f87804629879bd642d5b9571a.png)
 和单链表的区别就是多了一个前向指针。
