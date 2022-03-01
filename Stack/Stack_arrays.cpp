#include<iostream>

using namespace std;

class stack{
    public:
    int *arr,size,front;
        stack(){
            arr=new int[1];
            size=1;
            front=0;
        }
        void push(int data){
            if(front==size-1){
                int *arr2=new int[2*size];
                for(int i=0;i<size;i++){
                    arr2[i]=arr[i];
                }
                delete(arr);
                arr=arr2;
                size=size*2;
            }
            arr[front++]=data;
        }
        int get(int i){
            return arr[i];
        }
        int getsize(){
            return size;
        }
        void print(){
            for(int i=front-1;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        void pop(){
            front--;
        }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    s.pop();
    s.print();
}