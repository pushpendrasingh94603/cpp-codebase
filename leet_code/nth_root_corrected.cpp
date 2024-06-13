#include<iostream>
using namespace std;
long long int calculate_pos_ans(int number, int times_to_multiply) {
  long long int result = number;
  for (int i = 1; i < times_to_multiply; i++) {
    result = result * number;
  }
  return result;
}

int NthRoot(int n,int m) {
  int s = 1;
  int e = m;
  long long int mid = s + (e -s ) / 2;
  long long int curr_sol;
  
  while (s <= e) {

    mid = s + (e - s) / 2;
    curr_sol = calculate_pos_ans(mid, n);
    cout<<curr_sol<<endl;
    if (curr_sol == m) {
      return mid;
    } else if (curr_sol < m) {
      s = mid + 1;
      // closest_sol = mid;
    } else {
      e = mid - 1;
    }

  }
  return -1;
}
int main(){
    cout<<"ans : "<<NthRoot(9, 1953125);
    return 1;
}