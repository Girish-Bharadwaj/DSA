#include <iostream>


using namespace std;


int rear=0;

void insert(int arr[],int a){
	arr[rear]=a;
	rear++;
}

void del(int arr[]){
	for(int i=1;i<rear;i++){
		arr[i-1]=arr[i];
	}
	rear--;
}

void display(int arr[]){
	for(int i=0;i<rear;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	insert(arr,1);
	insert(arr,2);
	insert(arr,3);
	insert(arr,4);
	display(arr);
}