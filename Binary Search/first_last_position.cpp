#include<iostream>

using namespace std;

int main()
{
    int arr[]={5};
    int target=5;
    int a=0,b=0;
    int start=0,end=1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==target){
            a=mid;
            end=mid-1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    start=0,end=1;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==target){
            a=mid;
            start=mid+1;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<a<<"\n";
    return 0;
}