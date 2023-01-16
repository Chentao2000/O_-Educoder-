# 2.3-6循环链表
![在这里插入图片描述](https://img-blog.csdnimg.cn/2d57841f80624e4ca5fa6f34cf493f1c.png)
## 1、循环单链表
**单链表和循环单链表的区别：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/92e4e2b2d1bf431e997fec60c645cbe1.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/2ab91026365441b88135c6f76464fb5d.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/3c7e4aaeee854e0ab757debe48983f30.png)
如果头结点的下一个指向自己，那么循环单链表为空：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b746eabd492e42b597fd5a76cba2fe4b.png)![在这里插入图片描述](https://img-blog.csdnimg.cn/f584baa86c914bb8b6e2c8dafdb8bc39.png)
如果结点p的下一个结点指向头结点即p为表尾结点：
![在这里插入图片描述](https://img-blog.csdnimg.cn/e422603b2e2a446cb7f7e9a9ec76babc.png)

## 2、循环双链表
![在这里插入图片描述](https://img-blog.csdnimg.cn/9ffc5e3f4cbb4cf29eae099ab3b94b35.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/6ddac8c86f1d4053bdd0f8dad2f93723.png)
## 3、总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/c249b52fe5764e3998e9fd2606be3d7f.png)
最后一行：
尝试插入或删除一个结点的时候，要考虑表头、表中、表尾的特殊处理。
