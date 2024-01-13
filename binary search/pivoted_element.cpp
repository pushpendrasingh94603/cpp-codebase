#include<iostream>
using namespace std;

class Solution{
    public:
    int serch_pivoted_element(int arr[],int size){
        int mid = 0 ,s = 0;
        int e = size-1;
        while(s<e){
            mid = s + (e-s)/2;
            if(arr[0]<arr[mid]){
                s= mid+1;
            }
            else{
                e = mid;
            }
        }
        return e;
    }
};

int main(){
    int arr[] = {'6','7','8','1','2','3','4','5'};
    int size = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    cout<<obj.serch_pivoted_element(arr,size);
}