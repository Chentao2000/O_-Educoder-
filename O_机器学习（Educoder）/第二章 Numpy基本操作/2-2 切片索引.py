import numpy as np

def get_roi(data, x, y, w, h):
    '''
    提取data中左上角顶点坐标为(x, y)宽为w高为h的ROI
    :param data: 二维数组，类型为ndarray
    :param x: ROI左上角顶点的行索引，类型为int
    :param y: ROI左上角顶点的列索引，类型为int
    :param w: ROI的宽，类型为int
    :param h: ROI的高，类型为int
    :return: ROI，类型为ndarray
    '''
    return data[x:x+h+1, y:y+w+1]  

    #********* Begin *********#

    #********* End *********#
