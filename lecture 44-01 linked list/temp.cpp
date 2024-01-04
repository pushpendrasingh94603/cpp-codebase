#include<iostream>
using namespace std;

int binarysearch(int n){
    int lo =0;
    int hi = n; //yours n
    while(lo<=hi){
        int mid = lo + (hi-lo)/2 ; //this meathod is used to protect from overflow as int can only store limited value
        // we can also use mid=(hi+lo)/2;
        if(mid*mid == n)
        { return mid;}
        else if(mid*mid < n){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return -1; //case : number not found
}

int main(){
    int n;
    cout<<"enter the number to print its index\n";
    cin>>n;
    cout<<"NOTE: if -1 is printed it means number note found\n";
    cout<<binarysearch(n)<<endl;
    return 0;
}