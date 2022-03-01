#include<iostream>

using namespace std;

int main()
{
    int arr[]={1,2,5,9,11,14,15};
    int target=3
    ;
    int low=0,high=7,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            low=mid;
            break;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<arr[high]<<"\n";
    return 0;
}