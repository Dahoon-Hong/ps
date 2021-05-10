#include <bits/stdc++.h>
 
using namespace std;

int solve()
{
    string s;
    int n;
    cin >> n >> s;
    char previous = s[0];
    bool memo[26] = {0, };
    memo[previous-'A'] = true;
    for(int i = 1 ; i < n; i++)
    {
        if(s[i] != previous && memo[s[i]-'A'])
        {
            cout << "NO" << endl;
            return 0;
        }
        memo[s[i]-'A'] = true;
        previous = s[i];
    }

    cout << "YES" << endl;
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