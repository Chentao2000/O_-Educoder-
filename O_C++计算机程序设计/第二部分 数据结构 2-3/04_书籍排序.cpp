#include <string.h>
#include <iostream>

using namespace std;

//请在此添加代码，实现书籍数据的输入、排序和输出
/********** Begin *********/

struct book{
	char name[55];
	float price;
}b[105];

int main()
{

	int n ;
    cin>>n;
	
	for(int i=0;i<n;i++)
	{
		getchar(); 
		cin.getline(b[i].name,55);//得到一整行字符串 ，带空格 ，但是不带回车 赋值给 name
		cin>>b[i].price;		
	
	}
	// 排序
    for(int i=0;i<n-1;i++){
    	int k=i; //标记最小价格位置
		for(int j=i+1;j<n;j++){ //循环找到最小的价格

			if(b[k].price > b[j].price)
			 k = j;
			else if(b[k].price == b[j].price && strcmp(b[k].name, b[j].name) > 0 ) //价格一样，但是名字没比尔长 也放进去
			 k = j; //位置交换
		}   
		if(k!=i){ //需要交换 
			book t = b[k];//t 相当于 temp 临时变量来的
			b[k] = b[i];
			b[i] = t;
			
		}
	} 

	for(int i=0; i<n; i++){
		cout << b[i].price << ", " << b[i].name << "\n";
	}
	return 0;
}


/********** End **********/

