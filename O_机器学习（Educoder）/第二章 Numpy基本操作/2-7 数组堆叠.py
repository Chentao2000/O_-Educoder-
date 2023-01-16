# 引入numpy库  
import numpy as np  
# 定义varray函数  
def  varray(m,n):  
    '''  
    参数：  
    m：是第一个数组  
    n：是第二个数组  
    返回值:  
    ret: 一个numpy数组  
    '''  

    ret = np.vstack((m,n))
    # 请在此添加代码实现数组的垂直叠加 并赋值给ret  
    #********** Begin *********#
    #********** End **********#  
    return ret  
# 定义darray函数  
def  darray(m,n):  
    '''  
    参数：  
    m：是第一个数组  
    n：是第二个数组  
    返回值:  
    ret: 一个numpy数组  
    '''  
    ret = np.dstack((m,n))
    # 请在此添加代码实现数组的深度叠加并赋值给ret  
    #********** Begin *********#
    #********** End **********#  
    return ret  
 # 定义harray函数  
def  harray(m,n):  
    '''  
    参数：  
    m：是第一个数组  
    n：是第二个数组  
    返回值:  
    ret: 一个numpy数组  
    '''  
    ret = np.hstack((a,b))
    # 请在此添加代码实现数组的水平叠加并赋值给ret  
    #********** Begin *********#
    #********** End **********#  
    return ret  
