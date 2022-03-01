#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class tree{
    public:int data;
            tree* left;
            tree* right;
};
typedef tree* node;
const auto null=nullptr;

node root=null;


node createleft(node root){
    node temp=new tree;
    cout<<"Enter data for left child\n";
    cin>>temp->data;
    temp->left=null;
    temp->right=null;
    root->left=temp;
    return temp;
}
node createright(node root){
    node temp=new tree;
    cout<<"Enter data for left child\n";
    cin>>temp->data;
    temp->left=null;
    temp->right=null;
    root->right=temp;
    return temp;
}


void inorder(node root){
    if(root!=null){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(node root){
    stack<node> st;
    node temp=root;
    while(temp!=null || !st.empty()){
        if(temp!=null){
            st.push(temp);
            temp=temp->left;
        }
        else{
            temp=st.top();
            cout<<temp->data<<" ";
            st.pop();
            temp=temp->right;
        }
    }
}

void levelorder(){
    queue<node> q;
    node temp=root;
    cout<<temp->data<<" ";
    q.push(temp);
    node temp2;
    while(!q.empty()){
        temp2=q.front();
        q.pop();
        if(temp2->left){
            cout<<temp->left->data<<" ";
            q.push(temp2->left);
        }
        if(temp2->right){
            cout<<temp2->right->data<<" ";
            q.push(temp2->right);
        }
    }
}


int count(node p){
    int x,y;
    if(p!=NULL){
        x=count(p->left);
        y=count(p->right);
        return x+y+1;
    }
    return 0;
}

int height(node p){
    if(p==NULL){
        return 0;
    }
    int h1=height(p->left);
    int h2=height(p->right);
    return max(h1,h2)+1;
}

int countLeafNodes(node p){
    
}

int main()
{
    root=new tree;
    cout<<"Enter the value of root node\n";
    cin>>root->data;
    root->left=root->right=null;
    queue<node> que;
    que.push(root);
    node temp;
    while(!que.empty()){
        temp=que.front();
        que.pop();
        bool is=0;
        cout<<"Do you to create lchild of"<<temp->data<<"\n";
        cin>>is;
        if(is){
            que.push(createleft(temp));
        }
        is=0;
        cout<<"Do you to create rchildof"<<temp->data<<"\n";
        cin>>is;
        if(is){
            que.push(createright(temp));
        }
    }
    inorder(root);
    preorder(root);
    cout<<"\n";
    levelorder();
    cout<<"\n"<<count(root)<<"\n";
    cout<<height(root)<<"\n";
}