#include <bits/stdc++.h>
typedef unsigned long long llu;

using namespace std;


llu solve()
{
    llu k;
    cin >> k;
    llu res = 0;
    for(llu i = 1 ; ; i++)
    {
        llu s = i*(i+1)/(llu)2;
        if(k<s)
        {
            break;
        }
        if((k - s) % i == 0)
        {
            res++;
        }
    }
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