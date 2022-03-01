#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* rlink;
};

typedef struct node* NODE;
NODE insert_front(NODE,int);
NODE insert_rear(NODE,int);
void display(NODE);

int main(){
	NODE head=0;
	head=(NODE)malloc(sizeof(struct node));
	head->rlink=head;
	head=insert_front(head,2);
	head=insert_front(head,1);
	head=insert_rear(head,3);
	display(head);
}

NODE insert_front(NODE head,int data){
	NODE first,temp;
	NODE newnode=(NODE)malloc(sizeof(struct node));
	newnode->data=data;
	if(head->rlink==head){
		head->rlink=newnode;
		newnode->rlink=head;
		return head;
	}	
	first=head->rlink;
	head->rlink=newnode;
	newnode->rlink=first;
	return(head);
}


void display(NODE head){
	NODE temp=head->rlink;
	while(temp!=head){
		printf("%d ", temp->data);
		temp=temp->rlink;
	}
	printf("\n");
}


NODE insert_rear(NODE head,int data){
	NODE temp,newnode;
	newnode=(NODE)malloc(sizeof(struct node));
	newnode->data=data;
	if(head->rlink==head){
		head->rlink=newnode;
		newnode->rlink=head;
		return(head);
	}
	temp=head->rlink;
	while(temp->rlink!=head){
		temp=temp->rlink;
	}
	temp->rlink=newnode;
	newnode->rlink=head;
	return(head);
}