#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;

ull safe_div_ceil(ull x, ull y)
{
    ull res = x/y;
    if(x%y > 0)
    {
        res++;
    }
    
    return res;

};

void solve()
{
    ull n, k, x;
    ull res=1;
    ull a[200000];
    priority_queue<ull, vector<ull>, greater<ull> > pq;

    cin >> n >> k >> x;
    
    for(int i = 0 ; i < n ; i++)
    {  
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i = 1 ; i < n ; i++)
    {
        ull diff = a[i] - a[i-1];
        if(diff > x)
        {
            pq.push(diff);
        }
    }
    res = pq.size() + 1;

    while(!pq.empty() && k > 0)
    {
        ull t = pq.top();
        pq.pop();

    
        // ull m = (ull)ceil(double(t)/x) - 1;
        ull m = safe_div_ceil(t, x) - 1;
        //printf("%llu\n", (ull)ceil(double(t-x)/x));

        //printf("%llu\n", (ull)ceil((t-x)/x));
        //printf("%llu\n", (ull)ceil(t/x) - 1);
        // printf("%llu\n", (ull)ceil(double(t)/x) - 1);
        //printf("%llu\n", (ull)ceil(double((t-x)/x)));

        //printf("remain = %llu, d = %llu, x = %llu, m = %llu, k = %llu\n", res, t, x, m, k );
        if(k >= m)
        {
            //cout << "HI" << endl;
            k -= m;
            res--;
        }
        else
        {
            break;
        }
        
    }

    cout << res <<endl;
}

int main() 
{
    int TC=1;
    // cin >> TC;
    while(TC-->0)
    {
        solve();
    }
}   