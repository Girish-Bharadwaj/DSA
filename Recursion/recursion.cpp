#include<iostream>

using namespace std;

int fun1(int n){
    static int x=1;
    if(n>0){
        x++;
        cout<<x<<" ";
        return fun1(n-1)+x;
    }
    cout<<"\n";
    return 0;
}


int main(){
    int x=3;
    cout<<fun1(x)<<" "<<x<<"\n";
    return 0;
}