#include<iostream>

using namespace std;


class node{
    public:int data;
           node *next;
}; 


class Stack{
    public:
        node *top;
        Stack(){
            top=NULL;
        }
        void push(int);
        void pop();
        int peek(int);
        bool isEmpty();
        void display();
};


void Stack::push(int x){
    node *t=new node;
    if(t==NULL){

    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

void Stack::pop(){
    node *temp=top;
    top=top->next;
    free(temp);
}

bool Stack::isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}


int Stack::peek(int pos){
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

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    return 0;
}