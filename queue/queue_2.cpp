#include<iostream>

using namespace std;

class queue{
	private:int front=0;
			int rear=0;
			int *arr;
			int size;
	public:
		queue(int n){
			size=n;
			arr=new int[n];
		}
		void insert(int ele);
		void del();
		void display();
		int peek(int pos);
		~queue(){
			delete [] arr;
		}
};
void queue::insert(int ele){
	if((rear+1)%size==front){
		cout<<"Queue is full\n";
		return;
	}
	rear=(rear+1)%size;
	arr[rear]=ele;
	return;
}

void queue::del(){
	if((front+1)%size==rear){
		cout<<"Queue is empty\n";
		return;
	}
	front=(front+1)%size;
	return;
}
void queue::display(){
	int i=(front+1)%size;
	while(i!=(rear+1)%size){
		cout<<arr[i]<<" ";
		i=(i+1)%size;
	}
	cout<<"\n";
}
int main(){
	queue que(5);
	que.insert(1);
	que.insert(2);
	que.insert(3);
	que.insert(4);
	que.display();
	que.del();
	que.insert(5);
	que.display();
}