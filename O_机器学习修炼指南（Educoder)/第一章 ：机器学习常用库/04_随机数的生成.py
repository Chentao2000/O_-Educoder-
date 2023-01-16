import numpy as np


def shuffle(input_data):
    '''
    打乱input_data并返回打乱结果
    :param input_data: 测试用例输入，类型为list
    :return: result，类型为list
    '''

    # 保存打乱的结果
    result = []
    #********* Begin *********#
    #********* Begin *********#
    result=list(np.random.choice(input_data,size=len(input_data),replace=False))
    #********* End *********#
    #********* End *********#
    return result
