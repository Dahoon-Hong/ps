#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int get_a(int k, int i)
{

    double x1 = double(k)/double(i);
    double x2 = -0.5*double(i);
    double x3 = -0.5;
    double x= x1+x2+x3;
    if(x < 0)
    {
        return -1;
    }
    if(x - int(x) == 0.0)
    {
        return int(x);
    }
    else
    {
        return -1;
    }
}

llu check(int a, int b)
{
    return b*(b+1)/2 - a*(a+1)/2;
}

llu solve()
{
    int k;
    cin >> k;
    int res =0 ;
    for(int i = 1 ; i <= k ; i++)
    {
        int x=get_a(k, i);
        if(x != -1)
        {
            //cout << x << " " << x+i << endl;
            if(check(x, x+i)==k)
            {
                res++;
            }
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