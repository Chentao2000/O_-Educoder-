#include<bits/stdc++.h>
using namespace std;

char st[1000]; //保存符号的堆栈数组(模拟栈)
int top = -1; //堆栈指针
string ss = ""; //保存结果逆波兰式

int main(){
	printf("%s", "Input:");
	string s;
	
	cin>>s;
	int L = s.length();
	for(int i =  0;i < L; ++i){
		if(s[i]=='+'||s[i]=='-'){
			if(top==-1){ //栈为空, 遇到运算符,入栈
				st[++top] = s[i]; //将+,-入栈
			}else
			{
				while (st[top]!='(' && top > -1) //遇到其他运算符’+”-”*”/’时，弹出所有优先级大于或等于该运算符的栈顶元素(即除了 ' ( '
				{
					ss.push_back(st[top]);
					top--;
				}
				st[++top] = s[i]; //然后将该运算符入栈
			}
		}else if(s[i]=='*'||s[i]=='/'){
			if(top==-1){ //栈为空, 遇到运算符,入栈
				st[++top] = s[i]; //入符号栈
			}else{
				while (st[top]!='('&&(st[top]=='*'||st[top]=='/')) //同L20处, 不过st[top]不能为=或-,否则无法输出
				{
					ss.push_back(st[top]);
					top--;
				}
				st[++top] = s[i]; 
			}
		}else if(s[i]==')'){ //遇到右括号将左括号之前全部入栈,加入逆波兰式
			while(st[top]!='('){ //遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出
				ss.push_back(st[top]);
				top--;
			}
			top--; //左括号出栈但不加入逆波兰式
		}else{ 
			ss.push_back(s[i]); //操作数直接加入逆波兰式
		}
	} 

	//最后将堆栈中全部元素加入波兰式
	while(top>-1){
		ss.push_back(st[top]);
		top--;
	}
	printf("%s","逆波兰式为: ");
	cout<<ss<<endl;
	return 0;
} 
