#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;

#define MAX_LEN 100000
//#define precision 1000000000
#define ull unsigned long long

ull precision = 1000000000;
int dia[MAX_LEN];
int miner[MAX_LEN];

int solve()
{
    int n;
    int xc = 0;
    int yc = 0;
    cin >> n;
    for(int i=0; i<2*n; i++)
    {
        int x,y;
        cin >> x >> y;
        // cout << x << y << endl;
        if(x==0)
        {
            miner[yc++] = abs(y);
        }
        else
        {
            dia[xc++] = abs(x);
        }
    }

    sort(dia, dia+n);
    sort(miner, miner+n);

    ull ans_for = 0;
    ull ans_for_upper = 0;
    int yf = 0, yr = n-1;
    for(int i=0; i<n; i++)
    {
        ull ans_t = 0;
        ull ans_t_upper = 0;
        // forward
        double ta = sqrt(pow((dia[i]),2) + pow((miner[i]), 2));
        ans_t_upper = int(ta);
        ans_t = (ull)((ta - int(ta))*precision);

        ans_for += ans_t;
        ans_for_upper += ans_t_upper;
        // cout << ta << " " << ans_t_upper << " " <<ans_t << endl;
        

        if(ans_for >= precision)
        {
            ans_for_upper += (ull)(ans_for/precision);
            ans_for = ans_for%(precision);
        }

        // cout << ans_for_upper << " " << ans_for << endl;
    }

    printf("%llu.%09llu\n", ans_for_upper, ans_for);
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