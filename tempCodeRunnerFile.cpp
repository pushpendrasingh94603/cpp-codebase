//binary search basic syntax using function

#include<iostream>
using namespace std;

int findlostoccurence(int arr[],int size, int x){
    int lo =0;
    int hi = size-1; //yours n
    int lastoccure = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2 ; //this meathod is used to protect from overflow as int can only store limited value
        // we can also use mid=(hi+lo)/2;
        if(arr[mid] == x)
        { 
            lastoccure =  mid;
            lo = mid+1;
        }
        else if(arr[mid]<x){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return lastoccure; //case : number not found
}

int main(){
    int arr[10] ={0,1,2,3,4,4,4,4,8,9};
    int x;
    int size =10;
    cout<<"enter the number to print its index\n";
    cin>>x;
    cout<<"NOTE: if -1 is printed it means number note found\n";
    cout<<"last occurence at "<<findlostoccurence(arr,size,x)<<endl;
}
