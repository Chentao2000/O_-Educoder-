import pandas as pd
from sklearn import datasets
def demo():
    data = datasets.load_linnerud().data
    #********** Begin **********#
    index = pd.MultiIndex.from_product([["A","B","C","D"],["1",'2','3','4','5']])
    column = pd.MultiIndex.from_product([["stage"],["a","b","c"]])
    df = pd.DataFrame(data,index=index,columns=column)
    df1 = df.T.stack()
    idx = pd.IndexSlice
    print(df1.loc[idx["stage",:,"2"],:])
    #*********** End ***********#
