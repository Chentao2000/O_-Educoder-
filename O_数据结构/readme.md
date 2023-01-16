

![图片](https://user-images.githubusercontent.com/68007558/178905167-7e5b1058-5902-413d-8bc6-b74223f0678e.png)


# 编程汇总 :


把指针看成无限量的数组 - 这样可以理解很多代码
-- 到时候我要出一个专辑视频做这一方面


### 数据结构 第二章线性表
-- 前驱结点 - 当前结点的前一个结点称为直接前驱结点
![1661082638051](https://user-images.githubusercontent.com/68007558/185789547-ee91d253-f058-48ee-b47c-89773c087ddc.png)

```
int GetTop(SqStack S,SElemType &e)
{ 
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    /********** Begin **********/ 
    if(S.top > S.base){
        e  = *(S.top-1);
        return OK;
    }
    else
        return ERROR;

    /********** End **********/	
}

```
![1661084358337](https://user-images.githubusercontent.com/68007558/185790575-01af1c48-2b9c-4ca9-9e61-814c92aebd5d.png)
