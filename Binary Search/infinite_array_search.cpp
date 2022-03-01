#include<iostream>

using namespace std;

int main()
{
    int arr[]={2,3,5,6,7,8,10,11,12,15};

    int start=0,end=1,mid;
    int target=15;
    while(start<=end){
        if(target>=arr[start] && target<=arr[end]){
            break;
        }
        else{
            if(target>end){
                start=end+1;
                end=end*2;
            }
        }
    }
    int found=-1;
    cout<<start<<" "<<end<<"\n";
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==target){
            found = mid;
            break;
        }
        if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<found<<"\n";
    return 0;
}