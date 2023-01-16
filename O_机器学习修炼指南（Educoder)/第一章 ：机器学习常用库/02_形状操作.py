import numpy as np


def reshape_ndarray(input_data):
    '''
    将ipnut_data转换成ndarray后将其变形成一位数组并打印
    :param input_data: 测试用例，类型为list
    :return: None
    '''
    # 首先你 要将 他实例化 ，再进行numpepy等操作

    #********* Begin *********#
    print(np.array(input_data).reshape(-1))
    #********* End *********#
