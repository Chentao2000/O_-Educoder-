#include <iostream>
using namespace std;
int main(){
    int i,j,t;
    // 定义标签表 bq[i] 存放标签i出现的次数 ，开始都是次
    int bq[1001] = {0};

    int N,K;
    // 输入点赞的文章数
    cin >> N;
    // 逐个处理每篇文章
    for(i =0; i< N;i++){
        //输入标签数
        cin >> K;
        for(j=0;j<K;j++){
            // 读入一个标签
            cin >> t;
            bq[t]++;
        }
    }
    // 查找出现最多最大标签
    int max = 0, index = -1;
    for(i=0;i<1001;i++){
        if(bq[i]>=max){
            max = bq[i];
            index = i;
        }
    }

    //输出标签及次数 
    cout << index <<" "<<max <<endl;
    return 0;
}
