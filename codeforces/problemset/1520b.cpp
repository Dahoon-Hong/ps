#include <bits/stdc++.h>
 
using namespace std;

int solve()
{
    int n;
    cin >> n;
    int d = -1;
    int temp = n;
    
    while(temp > 0)
    {
        temp /= 10;
        d++;
    };

    int first = n/pow(10, d);
    int compare = 0;
    for(int i = 0 ; i <= d ; i++)
    {
        compare *= 10;
        compare += first;
    }
    // cout << d << " " << compare << endl;
    int result = d * 9;
    result += first;
    if(n < compare)
    {
        result--;
    }
    cout << result << endl;
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