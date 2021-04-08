#include <bits/stdc++.h>
 
using namespace std;

#define MAX_LEN 200001

int arr[MAX_LEN+1];
int arr_rev[MAX_LEN+1];

void solve(int n)
{
    int pc = 0;
    for(int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_remain = 0;
    for(int i = n-1; i>=0; i--)
    {
        max_remain = max(arr[i], max_remain);
        
        if(max_remain > 0)
        {
            arr_rev[i] = 1;
            max_remain--;
        }
        else
        {
            arr_rev[i] = 0;
        }
    }

    for(int i = 0 ; i < n; i++)
    {
        cout << arr_rev[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int TC;
    cin >> TC;
    while(TC-->0)
    {
        int n;
        cin >> n;
        solve(n);
    }
}