#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

priority_queue<int> pq;

void solve()
{ 
    int n;
    int res=0;
    ll s=0;
    int t;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t;
        s += (ll)t;
        res++;
        if(t<0)
        {
            pq.push(abs(t));
        }

        while(s<0)
        {
            s += pq.top();
            pq.pop();
            res--;
        }
    }
    
    cout << res << endl;
}

int main() 
{
    solve();
}