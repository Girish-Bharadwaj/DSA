#include<iostream>

using namespace std;

class node{
    public: int data;
            node* lchild;
            node* rchild;
};

node* head=nullptr;

void insert(int data){
    node *p=head;
    if(p==nullptr){
        p=new node;
        p->lchild=p->rchild=nullptr;
        p->data=data;
        head=p;
        return;
    }
    node *t,*r;
    t=head;
    r=nullptr;
    while(t!=nullptr){
        r=t;
        if(t->data<data){
            t=t->rchild;
        }
        else if(t->data>data){
            t=t->lchild;
        }
        else{
            return;
        }
    }
    p=new node;
    p->lchild=p->rchild=nullptr;
    p->data=data;
    if(data<r->data)r->lchild=p;
    else r->rchild=p;
    return;
}

void Inorder(node *root){
    if(root!=nullptr){
        Inorder(root->lchild);
        cout<<root->data<<" ";
        Inorder(root->rchild);
    }
}

node* search(int key){
    node *p=head;
    while(p!=nullptr){
        if(key==p->data){
            return p;
        }
        else if(key<p->data){
            p=p->lchild;
        }
        else{
            p=p->rchild;
        }
    }
    return nullptr;
}

int main()
{
    insert(30);
    insert(50);
    insert(70);
    insert(45);
    insert(20);
    insert(5);
    insert(25);
    Inorder(head);
    cout<<"\n";
    cout<<search(10)<<"\n";
    return 0;
}