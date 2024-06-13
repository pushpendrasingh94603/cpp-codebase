#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    // if (n == 1 && m == 0) {
    //     nums1[0] = nums2[0];
    //     return;
    // } else
    if (n == 1)
    {
        int j = m + n - 1;
        for (; j >= 0; j--)
        {
            if (nums1[j] == 0)
            {
                continue;
            }
            else if (nums1[j] >= nums2[0])
            {
                nums1[j + 1] = nums1[j];
            }
            else
            {
                nums1[j + 1] = nums2[0];
                break;
            }
        }
        nums1[j + 1] = nums2[0];
        return;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {

            int temp = nums2[i];
            int j = m + n - 1;
            for (j = m + n - 1; j >= 0; j--)
            {

                if (nums1[j] == 0)
                {
                    if (j <= m - 1 && temp > -1)
                    {
                        nums1[j + 1] = temp;
                        break;
                    }
                    else if (j <= m - 1 && temp < 0)
                    {
                        nums1[j + 1] = 0;
                        nums1[0] = temp;
                        break;
                    }
                    else
                        continue;
                }
                else if (nums1[j] >= temp)
                {
                    nums1[j + 1] = nums1[j];
                }
                else
                {
                    nums1[j + 1] = temp;
                    break;
                }
            }
            if (j == -1)
            {
                nums1[j + 1] = temp;
            }
            cout<<"round : "<<i<<endl;
            for(int k = 0 ; k<m+n; k++)
    {
        cout<<" "<<nums1[k];
    }
    cout<<endl<<endl;
        }
    }
}


int main()
{
    vector <int> nums1 = {-1,-1,0,0,0,0};
    int m =4;
    vector <int> nums2 ={-1,0};
    int n= 2;
    cout<<"before"<<endl;
      for(int k = 0 ; k<m+n; k++)
    {
        cout<<" "<<nums1[k];
    }
    cout<<endl<<" "<<endl;

    
    merge(nums1,  m, nums2,  n);
    
    cout<<"final one"<<endl;
    for(int k = 0 ; k<m+n; k++)
    {
        cout<<" "<<nums1[k];
    }
    cout<<endl;

    return 0;
} 