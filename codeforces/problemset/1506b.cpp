#include <bits/stdc++.h>
 
using namespace std;


int solve(string &s, int n, int k) 
{  
    int last_star = -1;
    int last_change = -1;
    int count = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(s[i] == '*')
        {
            if(last_change == -1 || i - last_change == k)
            {
                // initial
                last_change = i;
                // cout << i << endl;
                count++;
            }
            else if(i - last_change > k)
            {
                last_change = last_star;
                // cout << last_star << endl;
                count++;
            }
            last_star = i;
        }
    }
    // cout << last_change << " " << last_star << endl;
    if(last_change != last_star)
    {
        count++;
    }
    return count;
}

int main() 
{
    int TC;
    cin >> TC;
    while(TC-->0)
    {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        
        cout << solve(s,n,k) << endl;
    }
}