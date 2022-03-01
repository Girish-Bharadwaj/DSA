#include<iostream>

using namespace std;

class NODE{
public:
	int data;
	NODE* link;
};


NODE *head=NULL;


NODE* reverse(NODE* head){
	NODE* p=head;
	NODE *q;
	NODE* r;
	q=r=NULL;
	while(p!=0){
		r=q;
		q=p;
		p=p->link;
		q->link=r;
	}
	return q;
}

NODE* insert_first(int data){
	NODE* temp=NULL;
	temp=new NODE();
	if(head==NULL){
		temp->data=data;
		temp->link=NULL;
		return temp;
	}
	temp->data=data;
	temp->link=head;
	return temp;
}

NODE* insert_end(int data){
	if(head==NULL){
		return insert_first(data);
	}
	NODE* temp=head;
	while(temp->link!=NULL){
		temp=temp->link;
	}
	NODE *temp1=new NODE();
	temp1->data=data;
	temp1->link=NULL;
	temp->link=temp1;
	return head;
}

void print(NODE* head){
	NODE *temp=head;
	if(head==NULL){
		return;
	}
	if(temp==0){
		return;
	}
	printf("%d ",temp->data);
	print(temp->link);
}

void insert_pos(int data,int n){
	NODE *temp=new NODE();
	temp->data=data;
	temp->link=NULL;
	if(n==1){
		temp->link=head;
		head=temp;
		return;
	}
	NODE *temp1=head;
	for(int i=2;i<n;i++){
		temp1=temp1->link;
		if(temp1==NULL){
			if(i!=n){
				cout<<"Invalid\n";
				return;
			}
		}
	}
	if(temp1==NULL){
		temp1=temp;
		return;
	}
	temp->link=temp1->link;
	temp1->link=temp;
	return;

}

void delete_end(){
	if(head==NULL){
		cout<<"No nodes in the list\n";
		return;
	}
	NODE* temp=head;
	while(temp->link->link!=NULL){
		temp=temp->link;
	}
	delete(temp->link);
	temp->link=NULL;
}

void delete_front(){
	if(head==NULL){
		cout<<"No nodes in the list\n";
		return;
	}
	NODE *temp=head;
	head=head->link;
	delete(temp);
}

int main(){
	head=NULL;
	head=insert_first(3);
	head=insert_first(2);
	head=insert_first(1);
	head=insert_end(4);
	head=insert_end(6);
	head=insert_end(9);
	insert_pos(5,5);
	insert_pos(7,7);
	insert_pos(8,8);
	insert_pos(10,10);
	delete_front();
	delete_end();
	print(head);
	head=reverse(head);
	print(head);
}