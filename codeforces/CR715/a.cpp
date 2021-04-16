#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;

#define MAX_LEN 2001
//#define precision 1000000000
#define ull unsigned long long
#define ui unsigned int

ui arr[MAX_LEN];


int solve()
{
    int n;
    cin >> n;
    deque<ui> res;
    int t;
    for(int i=0; i<n; i++)
    {
        cin >> t;
        if(t%2==0)
        {
            res.push_back(t);
        }
        else
        {
            res.push_front(t);
        }
    }

    for(int i =0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

}

int main() 
{
    int TC;
    cin >> TC;
    while(TC-->0)
    {
        solve();
    }
} 