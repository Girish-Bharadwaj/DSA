#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *llink;
	struct node *rlink;
};

typedef struct node *NODE;
int i;
NODE first=0;
NODE insert_front(NODE,int);
void display(NODE);
NODE insert_rear(NODE,int);
NODE insert_pos(NODE,int,int);
NODE delete_front(NODE);
NODE delete_rear(NODE);
NODE delete_pos(NODE,int);
int main(){
	first=insert_rear(first,3);
	first=insert_rear(first,5);
	first=insert_rear(first,7);
	first=insert_rear(first,9);
	first=insert_rear(first,11);
	first=insert_front(first,1);
	first=insert_pos(first,2,2);
	first=insert_pos(first,2,2);
	display(first);
	first=delete_pos(first,9);
	display(first);
}

NODE delete_pos(NODE first,int pos){
	NODE temp=first;
	NODE temp1,temp2;
	if(first==0){
		printf("No nodes in the list\n");
		return(first);
	}
	if(pos==1 && first->rlink==0){
		first=0;
		free(temp);
		return(first);
	}
	if(pos==1){
		first=temp->rlink;
		first->llink=0;
		free(temp);
		return(first);
	}
	for(i=1;i<pos;i++){
		temp=temp->rlink;
	}
	if(temp==0){
		printf("Invalid pos\n");
		return(first);
	}
	temp1=temp->llink;
	temp2=temp->rlink;
	temp2->llink=temp1;
	temp1->rlink=temp2;
	free(temp);
	return(first);
}

NODE delete_front(NODE first){
	NODE temp=first;
	if(first==0){
		printf("No nodes in the list\n");
		return(first);
	}
	if(first->rlink==0){
		first=0;
		free(temp);
		return(first);
	}
	first=first->rlink;
	first->llink=0;
	free(temp);
	return(first);
}

NODE delete_rear(NODE first){
	if(first==0){
		printf("No nodes in the list\n");
		return(first);
	}
	NODE temp=first;
	while(temp->rlink!=0){
		temp=temp->rlink;
	}
	temp->llink->rlink=0;
	free(temp);
	return(first);
}

NODE insert_pos(NODE first,int pos,int data){
	if(pos==1){
		first=insert_front(first,data);
		return(first);
	}
	NODE temp=first;
	NODE temp1=first;
	for(i=1;i<pos;i++){
		temp1=temp;
		temp=temp->rlink;
	}
	if(temp==0){
		printf("Invalid position\n");
		return(first);
	}
	NODE newnode=(NODE)malloc(sizeof(struct node));
	newnode->data=data;
	temp1->rlink=newnode;
	newnode->llink=temp1;
	newnode->rlink=temp;
	temp->llink=newnode;
	return(first);
}

NODE insert_front(NODE first,int data){
	NODE newnode=(NODE)malloc(sizeof(struct node));
	newnode->llink=newnode->rlink=0;
	newnode->data=data;
	if(first==0){
		first=newnode;
		return(first);
	}
	newnode->rlink=first;
	first->llink=newnode;
	return(newnode);
}

void display(NODE first){
	NODE temp=first;
	while(temp->rlink!=0){
		printf("%d ",temp->data);
		temp=temp->rlink;
	}
	printf("%d ",temp->data);
	printf("\n");
}



NODE insert_rear(NODE first,int data){
	NODE newnode=(NODE) malloc(sizeof(struct node));
	newnode->data=data;
	if(first==0){
		newnode->llink=newnode->rlink=0;
		first=newnode;
		return(first);	
	}
	NODE temp=first;
	while(temp->rlink!=0){
		temp=temp->rlink;
	}
	temp->rlink=newnode;
	newnode->llink=temp;
	newnode->rlink=0;
	return(first);
}