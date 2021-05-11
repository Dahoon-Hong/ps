#include <bits/stdc++.h>
 
using namespace std;

#define SM 200000
#define ull unsigned long long
int arr[SM];
int rev_arr[SM];

void solve()
{
    int n;
    ull result = 0;
    int t = 0;
    int diff = 0;
    int diff_max = 0;
    memset(arr, 0 , sizeof(int)*SM);
    memset(rev_arr, 0 , sizeof(int)*SM);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t;
        diff = t - i;
        if(diff < 0)
        {
            rev_arr[-1*diff]++;
            diff_max = max(diff_max, -1*diff);
            continue;
        }
        arr[diff]++;
        diff_max = max(diff_max, diff);
    }
    for(int i = 0 ; i <= diff_max; i++)
    {
        //cout << i << " " << arr[i] << endl;
        if(arr[i] > 1)
        {
            ull a=0, b= 0;
            if(arr[i]%2 ==0)
            {
                a = arr[i]/2;
                b = arr[i]-1;
            }
            else
            {
                a = arr[i];
                b = (arr[i]-1)/2;
            }
            //printf("%llu %llu %llu\n",a, b, a*b);
            result += a*b;
        }
        if(rev_arr[i] > 1)
        {
            ull a=0, b= 0;
            if(rev_arr[i]%2 ==0)
            {
                a = rev_arr[i]/2;
                b = rev_arr[i]-1;
            }
            else
            {
                a = rev_arr[i];
                b = (rev_arr[i]-1)/2;
            }
            //printf("%llu %llu %llu\n",a, b, a*b);
            result += a*b;
        }
    }
    cout << result << endl;
}

int main() 
{
    int TC;
    cin >> TC;
    while(TC-->0)
    {
        solve();
    }
    //ull a=100000, b=199999;
    //cout << a << " "<< b << " "<< a*b << endl;
}