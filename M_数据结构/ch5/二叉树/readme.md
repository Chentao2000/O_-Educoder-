# 5.2_1 二叉树的定义和基本术语
![在这里插入图片描述](https://img-blog.csdnimg.cn/18f2b741e959494c98f74e30b796f26b.png)
## 1、二叉树的基本概念
![在这里插入图片描述](https://img-blog.csdnimg.cn/1a480283590949518aadc2486b9191dc.png)

 - **每个结点至多只有两颗子树**
 - **左右子树不能颠倒（二叉树是有序树）**
 - **二叉树是递归定义的数据结构**
 - **任意结点的度<=2，允许所有结点的度都<2，可以是空树**
## 2、二叉树的五种状态
![在这里插入图片描述](https://img-blog.csdnimg.cn/65bea35a4ca44d549f868eb9f4e04d05.png)
## 3、几个特殊的二叉树
### 满二叉树：
![在这里插入图片描述](https://img-blog.csdnimg.cn/d089df4590344bce999d81b4a4d918cd.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/42d87c111b274663aefb3bbce06ead6d.png)

 - **除了最下面的叶子结点外，其他所有的分支结点都长满了两个分支**
 - **等比数列求和公式：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/e1289fb971964f1596f6a7fb660e9c6a.png)
**1 x （1-2^h）/（1-2）= 2 ^ h - 1**
 - **结点i的左孩子为2i，右孩子为2i+1，父节点为[i/2]**
### 完全二叉树：
![在这里插入图片描述](https://img-blog.csdnimg.cn/18322c85d5a94f2ca551947e88d3ccef.png)

 - **③是同满二叉树的③**
 - **完全二叉树也就是在满二叉树的基础上删除结点，剩余的结点和二叉树对应的结点的编号要相同**
 - **i<=[n/2]为分支结点，i>[n/2]为叶子结点**
  - **如果完全二叉树中某个结点只有一个孩子，那么一定是左孩子**
  
**满二叉树和完全二叉树是形态上特殊的二叉树，接下来是功能上比较特殊的二叉树：**
### 二叉排序树
![在这里插入图片描述](https://img-blog.csdnimg.cn/8c02efd15a884e14b4abbd1db8cf327c.png)
 - **二叉排序树的左子树的关键字<根结点的关键字**
 - **二叉排序树的右子树的关键字>根结点的关键字**
 - **左子树和右子树又各是一棵二叉排序树**
 - **故二叉排序树可用于元素的排序、搜索**
### 平衡二叉树
**树上任一结点的左子树和右子树的深度之差不超过1**
![在这里插入图片描述](https://img-blog.csdnimg.cn/1c6af80fc21b4530a345f8ebbde2e0b7.png)
 - **使树比较宽和矮，节省查找时间**
![在这里插入图片描述](https://img-blog.csdnimg.cn/32ec0141d33f434b9348711717a924b1.png)
# 5.2_2 二叉树的常考性质

## 1、二叉树的常考考点
### （1）
![在这里插入图片描述](https://img-blog.csdnimg.cn/33c471b738ce434e8311acce19cdfc97.png)
### （2）
![在这里插入图片描述](https://img-blog.csdnimg.cn/e5d24582dbd74414b59ab44c8f31d6aa.png)
### （3）
![在这里插入图片描述](https://img-blog.csdnimg.cn/c151157f331e4c0b9e94c762a84a202a.png)
## 2、完全二叉树的常考考点
### (1)
（第一条式子的解法）
![在这里插入图片描述](https://img-blog.csdnimg.cn/c32f95cdd1aa4193beca5934ead91c97.png)
（第二条式子的解法）
 
![在这里插入图片描述](https://img-blog.csdnimg.cn/d74e79ef830040f08afc88ee1c802624.png)
### （2）
![在这里插入图片描述](https://img-blog.csdnimg.cn/4adaf91651d647d794223c96387ae5b6.png)
**故只要知道完全二叉树的结点数n，就可以知道它有几个叶子，几个单分支结点，几个双分支结点**

## 3、知识回顾与重要考点

![在这里插入图片描述](https://img-blog.csdnimg.cn/88784b8dd2b44940a231bddcd5218a77.png)
# 5.2_3 二叉树的存储结构
![在这里插入图片描述](https://img-blog.csdnimg.cn/0c8d8b6d9c33488ca0369cb5094663e5.png)
## 1、二叉树的顺序存储
![在这里插入图片描述](https://img-blog.csdnimg.cn/c07f1b34bca743a6b8f110c150a20350.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/625dd60d977141089dc20513ef534fb0.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/da18eba234ab4d2d97063263182963df.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/04300d89aaf148c7a125013a92f91cb5.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/2fa9362ec3484780bdddb9c6ee42e902.png)
## 2、二叉树的链式存储
![在这里插入图片描述](https://img-blog.csdnimg.cn/dbfd90a7f00a47d5b31b549b594030be.png)

**有n个结点时，共有2n个指针，除了根结点之外，其他每个结点头上都会连一个指针，故总共有n-1个这样的指针，因此，n个结点的二叉链表共有2n-(n-1)=n+1个空链域，可以用于构造线索二叉树**
![在这里插入图片描述](https://img-blog.csdnimg.cn/b66194efd9214c9b9ac969ed1a3e1e6b.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/ccd6867dd4304ec9b7684f173a4c428e.png)
## 3、知识回顾与重要考点
![在这里插入图片描述](https://img-blog.csdnimg.cn/21c301f189914e2683e0db9be92fd27b.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/905b1c9fc4e94471aea322703abc593e.png)






