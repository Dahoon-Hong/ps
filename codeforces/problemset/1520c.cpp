#include <bits/stdc++.h>
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if(n == 2)
    {
        cout << -1 << endl;
        return;
    }

    int target = 1;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << target << " "; 
            target += 2;
            if(target > n*n)
            {
                target=2;
            }
        }
        cout << endl;
    }
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