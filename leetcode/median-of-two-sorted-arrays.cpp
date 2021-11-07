#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=0;
        int n=0;
        vector<int> merged;
        int mmax = nums1.size();
        int nmax = nums2.size();
        
        int num1=1000001;
        int num2=1000001;
        while(m+n < (mmax+nmax)/2+1)
        {
            if(m < mmax)
            {
                num1 = nums1[m];
            }
            else
            {
                num1 = 1000001;
            }
            if(n < nmax)
            {
                num2 = nums2[n];
            }
            else
            {
                num2 = 1000001;
            }
            if(num1 <= num2)
            {
                merged.push_back(num1); 
                m++;
            }
            else if(num2 <= num1)
            {
                merged.push_back(num2);
                n++;
            }

        }
        
        int middle = (mmax+nmax)/2;
        int res = (mmax+nmax)%2;
        
        printf("%d %d\n", middle, (mmax+nmax)/2+1);
        if(res != 0)
        {
            return merged[middle];
        }
        else
        {
            printf("%d %d\n", merged[middle-1], merged[middle]);
            return double(merged[middle] + merged[middle-1])/2.0;
        }
    }
};

int main()
{
    Solution s;
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    printf("%lf\n", s.findMedianSortedArrays(a, b));
    return 0;
}