#include <bits/stdc++.h>
 
using namespace std;
typedef long long ull;

void solve()
{
    int n;
    ull dist[100000] = {0, };
    ull diff[100000] = {0, };
    ull res = 0;

    cin >> n;
    for( int i = 0 ; i < n ; i++)
    {
        cin >> dist[i];
    }

    sort(dist, dist + n);

    ull addv = 0;
    for(int i = 2 ; i < n ; i++)
    {
        diff[i] = abs(dist[i] - dist[i-1]);
        res -= (dist[i]);
        if( i == 2)
        {
            continue;
        }
        ull idx = i-2;
        addv += (idx*diff[i] + diff[i-1]);
        //cout << addv << " "<< diff[i] << " " << diff[i-1] << endl;
        res -= addv;
        //cout << res << endl;
    }
    cout << res <<endl;
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