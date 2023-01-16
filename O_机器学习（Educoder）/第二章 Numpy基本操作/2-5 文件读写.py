import numpy as np
ndarray = np.ndarray
def task():  
    '''  
    任务要求：从指定路径的二进制文件中（"step5/FileHandling/files/A.npy"）读取NumPy矢量数组A，从从指定路径的txt文件中读取矢量数组B（"step5/FileHandling/files/B.txt"），然后使用通用函数numpy.add()对数组A和B进行求和，将结果保存到指定的二进制文件中（"step5/FileHandling/files/out.npy"）  
    提示1：使用np.load('path')加载二进制文件'step5/FileHandling/files/A.npy'  
    提示2：使用np.loadtxt('path', delimiter=',')加载文本文件'step5/FileHandling/files/B.txt'  
    提示3：使用使用np.save('path', C)将结果储存到二进制文件'step5/FileHandling/files/out.npy'中  
    提示3：A.npy和B.txt中矩阵维度一致  
    '''  
    # ********** Begin *********  
    A = np.load('step5/FileHandling/files/A.npy')  
    B = np.loadtxt('step5/FileHandling/files/B.txt', delimiter=',')  
    C = A + B  
    np.save("step5/FileHandling/files/out.npy", C)  
    # ********** Begin *********
