// WA in tc1
#include <bits/stdc++.h>
#define llu long long

using namespace std;

int solve()
{
    llu arr[3][3] = {0, };
    
    cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
    cin >> arr[1][0] >> arr[1][2];
    cin >> arr[2][0] >> arr[2][1] >> arr[2][2];

    llu mid[4];
    
    int res=0;

    if((arr[0][0]-arr[0][1]) == (arr[0][1]-arr[0][2]))
    {
        res++;
    }
    if((arr[2][0]-arr[2][1]) == (arr[2][1]-arr[2][2]))
    {
        res++;
    }
    if((arr[0][0]-arr[1][0]) == (arr[1][0]-arr[2][0]))
    {
        res++;
    }
    if((arr[0][2]-arr[1][2]) == (arr[1][2]-arr[2][2]))
    {
        res++;
    }

    mid[0] = arr[0][0] + arr[2][2];
    mid[1] = arr[0][1] + arr[2][1];
    mid[2] = arr[1][0] + arr[1][2];
    mid[3] = arr[0][2] + arr[2][0];

    llu t[4];
    llu flag[4] = {0, };
    int maxt=0;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(mid[i] % 2 != 0)
        {
            flag[i] = 0;
            continue;
        }
        flag[i] = 1;
        t[i] = (llu)(mid[i]/(llu)(2));
        int tmax=1;
        for(int j = 0; j < i ; j++)
        {
            if(t[i] == t[j] && flag[i] == 1)
            {
                tmax++;
            }
        }
        maxt = max(tmax, maxt);
    }
    res += maxt;
    return res;
}

int main() 
{
    int TC;
    cin >> TC;
    for(int i =1 ; i <= TC ; i++)
    {
        cout << "Case #" <<i<<": " << solve() << endl;
    }
}