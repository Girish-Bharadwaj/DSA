#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node *NODE;
NODE root=0;
void create(NODE*);
int is_lchild(NODE*);
int is_rchild(NODE*);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);

int main(){
	printf("Enter the data for root\n");
	root=(NODE)malloc(sizeof(struct node));
	scanf("%d",&root->data);
	printf("%d %d\n",&root,root );
	create(&root);
	preorder(root);
	printf("\n");
	postorder(root);
}

void create(NODE *root1){
	NODE temp,temp1;
	if(is_lchild(&(*root1))){
		(*root1)->lchild=(NODE)malloc(sizeof(struct node));
		temp=(*root1)->lchild;
		printf("Enter data for lchild:");
		scanf("%d",&temp->data);
		create(&temp);
	}
	else{
		(*root1)->lchild=0;
	}
	if(is_rchild(&(*root1))){
		(*root1)->rchild=(NODE)malloc(sizeof(struct node));
		temp1=(*root1)->rchild;
		printf("Enter data for rchild:");
		scanf("%d",&temp1->data);
		create(&temp1);
	}
	else{
		(*root1)->rchild=0;
	}
	return;
}

int is_lchild(NODE *root2){
	int ch=1;
	printf("Do you want lchild\n");
	scanf("%d",&ch);
	if(ch==1)
		return 1;
	else
		return 0;
}
int is_rchild(NODE *root3){
	int ch;
	printf("Do you want rchild\n");
	scanf("%d",&ch);
	if(ch==1)
		return (1);
	else
		return (0);
}

void inorder(NODE root4){
	if(root4!=0){
		inorder(root4->lchild);
		printf("%d->",root4->data);
		inorder(root4->rchild);
	}
}
void preorder(NODE root7){
	if(root7!=0){
		printf("%d->",root7->data);
		preorder(root7->lchild);
		preorder(root7->rchild);
	}
}
void postorder(NODE root5){
	if(root5!=0){
		postorder(root5->lchild);
		postorder(root5->rchild);
		printf("%d->",root5->data);
	}
}