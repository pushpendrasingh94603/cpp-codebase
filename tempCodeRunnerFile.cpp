#include<iostream>
using namespace std;
//using long long to avoid overflow in case of long number
long long int sqrt_with_round_of(int n){
   long int lo =0;
   long int hi = n;
   long long int ans = -1;
   while(lo<=hi){
       long long int mid = lo + (hi-lo)/2 ;
       //this meathod is used to protect from overflow as int can only store limited value
       // we can also use mid=(hi+lo)/2;
       if(mid*mid == n)
       {
           ans = mid;
           return ans;
       }
       else if( mid*mid < n){
           ans = mid;
           lo = mid+1;
       }
       else{
           hi = mid-1;
       }
   }
   return ans;
}


//n number jiska square root niaklna hai
// temp_ans answer jo round karke nikala hai
double sqrt_with_precison(int n, long long int temp_ans, int precison){
   double controlvalue =1;
   double ans= temp_ans;


   for (int i =0;i<precison;i++){
       controlvalue = controlvalue/10;


       for (double j = ans; j*j<n; j= j+controlvalue){
           ans = j;
       }
   }
   return ans;
}


int main(){
   int n,precison;
   cout<<"enter the number to find its squar root\n";
   cin>>n;
   cout<<"enter the precison value uptu what extent you want values after decimal point\n";
   cin>>precison;
   long long int temp_ans = sqrt_with_round_of(n);
   cout<<"squar root : "<<sqrt_with_precison(n , temp_ans , precison)<<endl;
   return 0;
}
