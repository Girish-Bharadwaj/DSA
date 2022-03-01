#include<iostream>
#include<stack>
#include <math.h>
using namespace std;

bool isOperand(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='(' || a==')' || a=='^'){
		return 0;
	}
	else{
		return 1;
	}
}

int inpre(char a){
	if(a=='^'){
		return 5;
	}
	if(a=='*' || a=='/'){
		return 4;
	}
	if(a=='+' || a=='-'){
		return 2;
	}
	if(a=='('){
		return 0;
	}
	if(a==')'){
		return -1;
	}
	return 0;
}
int outpre(char a){
	if(a=='^'){
		return 6;
	}
	if(a=='*' || a=='/'){
		return 3;
	}
	if(a=='+' || a=='-'){
		return 1;
	}
	if(a=='('){
		return 7;
	}
	if(a==')'){
		return 0;
	}
	return 0;
}


int eval(char a,int b,int c){
	int num1=b;
	int num2=c;
	if(a=='+'){
		return (num1+num2);
	}
	if(a=='-'){
		return (num1-num2);
	}
	if(a=='/'){
		return (num1/num2);
	}
	if(a=='*'){
		return (num1*num2);
	}
	if(a=='^'){
		return (pow(num1,num2));
	}
}

int main(){
	stack<char> stk;
	string s,postfix="";
	cin>>s;
	int i=0;
	while(s[i]!='\0'){
		if(isOperand(s[i])){
			postfix+=s[i];
			i++;
		}
		else if(stk.empty()==false && outpre(s[i])==inpre(stk.top())){
			stk.pop();
			i++;
		}
		else if(stk.empty()==false && outpre(s[i])<inpre(stk.top())){
			postfix+=stk.top();
			stk.pop();
		}
		else{
			stk.push(s[i]);
			i++;
		}
	}
	while(!stk.empty()){
		postfix+=stk.top();
		stk.pop();
	}
	i=0;
	stack<int> stk2;
	while(postfix[i]!='\0'){
		if(isOperand(postfix[i])){
			cout<<"Enter value of "<<postfix[i]<<"\n";
			int temp;
			cin>>temp;
			stk2.push(temp);
			i++;
		}
		else{
			int num1=stk2.top();
			stk2.pop();
			int num2=stk2.top();
			stk2.pop();
			int ans=eval(postfix[i],num2,num1);
			stk2.push(ans);
			i++;
		}
	}
	cout<<stk2.top()<<"\n";
	return 0;
}