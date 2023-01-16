import numpy as np


def get_answer(input_data):
    '''
    将input_data转换成ndarray后统计每一行中最大值的位置并打印
    :param input_data: 测试用例，类型为list
    :return: None
    '''

    #********* Begin *********#
    print(np.array(input_data).argmax(axis=1))
    #********* End *********#
