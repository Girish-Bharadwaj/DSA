#include<iostream>

using namespace std;


class node{
    public:char data;
           node *next;
}; 


class Stack{
    public:
        node *top;
        Stack(){
            top=NULL;
        }
        void push(char);
        char pop();
        char peek(int);
        bool isEmpty();
        void display();
};


void Stack::push(char x){
    node *t=new node;
    if(t==NULL){

    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char Stack::pop(){
    node *temp=top;
    char data=top->data;
    top=top->next;
    free(temp);
    return data;
}

bool Stack::isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}


char Stack::peek(int pos){
    if(top==NULL){
        return -1;
    }
    if(pos==0){
        return top->data;
    }
    node *temp=top;
    for(int i=0;i<pos;i++){
        temp=temp->next;
        if(temp==NULL){
            return -1;
        }
    }
    return temp->data;
}

void Stack::display(){
    if(top==NULL){
        return;
    }
    node *t=top;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<"\n";
}

bool isOperand(char a){
	if(a=='+' || a=='-' || a=='*' || a=='/'){
		return 0;
	}
	else{
		return 1;
	}
}

int pre(char a){
	if(a=='*' || a=='/'){
		return 2;
	}
	if(a=='+' || a=='-'){
		return 1;
	}
	return 0;
}

int main()
{
    Stack stack;
    string s;
    cin>>s;
   	string postfix="";
   	int i=0,j=0;
   	while(s[i]!='\0'){
   		if(isOperand(s[i])){
   			postfix+=s[i];
   			i++;
   		}
   		else{
   			if(pre(s[i])<pre(stack.peek(j)) && stack.isEmpty()==false){
   				postfix+=stack.pop();
  			}
   			else{
   				stack.push(s[i]);
   				i++;
   			}
   		}
   	}
   	while(stack.isEmpty()==false){
   		postfix+=stack.pop();
   	}
   	cout<<postfix<<"\n";
    return 0;
}


