## 1.1
## 1、数据结构基本概念
## 1） 数据项、数据元素、组合项
![在这里插入图片描述](https://img-blog.csdnimg.cn/cbf0a81854604bf6835e4d89f5aa6241.png)
## 2）数据对象
具有相同性质的数据元素的集合，是数据的一个子集。
如第一个数据对象是关于财富榜的所有数据元素的集合
第二个则是关于微博账号的数据元素集合
第三个是关于海底捞排队的数据元素集合
![在这里插入图片描述](https://img-blog.csdnimg.cn/8ae7f62d064049f59a0c1ed94e70ddfd.png)
## 3）数据结构
数据结构是指相互之间存在一种或多种特定关系的数据元素的集合。
关注的是数据元素之间的关系和对这些数据元素的操作，而不关心具体的数据项内容

## 4）数据类型和抽象数据类型（ADT）
## 数据类型
（1）原子类型：其值不可再分的数据类型（如bool和int类型）
![在这里插入图片描述](https://img-blog.csdnimg.cn/4bf2451085f54c2891bc8f124e85d8b9.png)
（2）结构类型：其值可以再分解成若干份的数据类型（如struct结构体可以分解成x和y两个分量）
![在这里插入图片描述](https://img-blog.csdnimg.cn/5961aec867cf4b6a9d6fae014b3a0868.png)
## 抽象数据类型（ADT）
是抽象数据组织及与之相关的操作。
![在这里插入图片描述](https://img-blog.csdnimg.cn/cf9603a0f4ea4c29b3cdefa23b2c1319.png)

 
## 2、数据结构三要素

![在这里插入图片描述](https://img-blog.csdnimg.cn/f9872f6714e743a1bb47b284a16368c5.png)
## 3、总结
![在这里插入图片描述](https://img-blog.csdnimg.cn/ebb0e0da162347bf973881562dd70ded.png)
## 1.2
##  1）算法的基本概念
![在这里插入图片描述](https://img-blog.csdnimg.cn/0d3a8a2bab5440b586425a6b45d5202f.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/671b922e387a4cb4a5bd93a13aec9a12.png)
## 2）算法效率的度量
![ ](https://img-blog.csdnimg.cn/073b1e98a99b463e9339573e4b3e79aa.png)
## 空间复杂度S(n)
![在这里插入图片描述](https://img-blog.csdnimg.cn/4ae00490fa1c4e6681155e375f0b3326.png)

（1）S(n) = O(1)
当问题规模无论怎么变，算法运行所需的内存空间都是固定的常量，算法的空间复杂度就为S(n) = O(1)
![在这里插入图片描述](https://img-blog.csdnimg.cn/455123d150004f0e831005a161159c7f.png)
(2)具体怎么算

1、
![在这里插入图片描述](https://img-blog.csdnimg.cn/354bc6028479486dbbe31480df0e369b.png)
4：定义一个 int n 要4个字节
4n：数组中有n个int，一个int要4字节，即4n
4：定义一个 int i 要4个字节
故S(n) = O(4n+8) = O(n) 
**因为用O表示法，只关注n的阶数**


2、
![在这里插入图片描述](https://img-blog.csdnimg.cn/e4057ff6a16b4670a6f86aa86706b043.png)

3、
**当多个O相加时，只需取最大的O**
![在这里插入图片描述](https://img-blog.csdnimg.cn/02e8a41729304d33a87b74f77056fb7f.png)
4、函数递归调用带来的内存开销
 
![在这里插入图片描述](https://img-blog.csdnimg.cn/2a4de5ad13d64a8cab392de475bbd777.png)
S(n) = O(5n) = O(n)
**空间复杂度 = 递归调用的深度**

5、
在4、的基础上改一下，把变量改成数组
![在这里插入图片描述](https://img-blog.csdnimg.cn/6612f6dd48a64d84ab2d2fe2b547f824.png)
## 时间复杂度T(n)
**（1）关于O**
O表示“同阶”，同等数量级
而且相加时取最大
**简单来说O就是取最高阶的值并把系数化为1**
故T1(n) = O(3n + 3) = O(3n) = O(n)
T2(n) = O(n^2 + 3n + 1000) = O(n ^2)
T3(n) = O(n^3 + n ^2 + 9999999) = O(n ^3)
 
 **（2）**加法规则和乘法规则****
![在这里插入图片描述](https://img-blog.csdnimg.cn/3d02f81213094bf88eb55704bb1d692c.png)（**3）常见的数量级**![在这里插入图片描述](https://img-blog.csdnimg.cn/b5134f79854e4da2a60e39786a453a03.png)
**简单记忆：常对幂指阶**
![在这里插入图片描述](https://img-blog.csdnimg.cn/0ede63fd1dab42e3b64a65cf9ddee20e.png)
**常数 < 对数 < 幂数 < 指数 < 阶数**
      1   <  log2n < (n < n^2) < 2 ^ n < n! 
      
**(4) 快速计算的结论
1、顺序执行的代码只会影响常数项，可以忽略
2、只需挑循环中的一个基本操作分析它的执行次数与n的关系即可**
![在这里插入图片描述](https://img-blog.csdnimg.cn/53edcd92122d4703a962e041a09cb669.png)
故这里可只看第4行，执行n次，故T(n) = O(n)
3、如果有多层嵌套循环，只需关注最深层循环循环了多少次
![在这里插入图片描述](https://img-blog.csdnimg.cn/f100a8d8a38346dca1ebf193d99a93ac.png)
（5）小练习
![在这里插入图片描述](https://img-blog.csdnimg.cn/98d37fede3244824b2de32fe663f3f78.png)
最后的+1,是因为循环到最后一个数的时候，还要循环一次判断，再跳出循环


