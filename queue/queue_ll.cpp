#include <iostream>


using namespace std;


class Node{
public:
	int data;
	Node *next;
};


class queue{
private:Node *front=NULL;
		Node*rear=NULL;
public:
	void enqueue(int ele);
	int dequeue();
	void display();
};


void queue::enqueue(int ele){
	Node *t=new(Node);
	if(t==NULL){
		cout<<"Queue is full\n";
		return;
	}
	t->data=ele;
	t->next=NULL;
	if(front==NULL){
		front=rear=t;
		return;
	}
	rear->next=t;
	rear=t;
	return;
}

int queue::dequeue(){
	if(front==NULL){
		cout<<"Queue is empty\n";
		return -1;
	}
	Node* temp=front;
	int num=temp->data;
	front=front->next;
	delete(temp);
	return num;
}

void queue::display(){
	Node *t=new(Node);
	t=front;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<"\n";
}



int main(){
	queue que;
	que.enqueue(1);
	que.display();
	que.enqueue(2);
	que.display();
	que.enqueue(3);
	que.display();
	que.enqueue(4);
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
	return 0;
}