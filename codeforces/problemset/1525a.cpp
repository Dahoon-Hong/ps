#include <bits/stdc++.h>
 
using namespace std;

int gcd(int a, int b)
{
    int t;
    while(b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve()
{
   int k;
   cin >> k;
   
   int c = k;
   int m = 100;
   for(int i = 0 ; i <= 100; i++)
   {
       int t = gcd(c, m);
       // printf("%d %d %d\n", c, m ,t );
       if(t == 1)
       {
           break;
       }
       c /= t;
       m /= t;
   }
   cout << m << endl;

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