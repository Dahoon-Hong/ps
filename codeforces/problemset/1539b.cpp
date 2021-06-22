#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;

ull arr[100001] = {0, };

void solve()
{
    int n, q;
    cin >> n >> q;
    
    string s;    
    cin >> s;
    arr[0] = 0;
    for(int i = 1 ; i <= s.length() ; i++)
    {
        arr[i] = arr[i-1] + ull(s[i-1] - 'a' + 1);
    }

    for(int i = 0 ; i < q ; i++)
    {
        int l, r;
        
        cin >> l >> r;
        cout << arr[r] - arr[l-1] << endl;
    }

}

int main() 
{
    int tc;
    //cin >> TC;
    tc = 1;
    while(tc-->0)
    {
        solve();
    }
}   