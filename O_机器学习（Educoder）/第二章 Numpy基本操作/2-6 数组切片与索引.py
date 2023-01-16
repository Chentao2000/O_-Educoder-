# 引入numpy库
import numpy as np
# 定义cnmda函数
def ce(a,m,n):
    '''
    参数：
    a:是一个Numpy数组
    m:是第m维数组的索引
    n:第m维数组的前n个元素的索引
    返回值:
    ret: 一个numpy数组
    '''
    ret = 0
	# 请在此添加切片的代码,实现找出多维数组a中第m个数组的前n个元素 并赋值给ret
    #********** Begin *********#
    ret = a[m,:n]

    #********** End **********#
    return ret
