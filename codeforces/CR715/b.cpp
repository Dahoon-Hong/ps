#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;

#define MAX_LEN 2001
//#define precision 1000000000
#define ull unsigned long long
#define ui unsigned int

ui arr[MAX_LEN];


int solve()
{
    int n;
    cin >> n;
    int tc=0;
    int mc=0;
    char c;
    int res = 1;
    for(int i=0; i<n; i++)
    {
        cin >> c;
        if(c == 'T')
        {
            tc++;
        }
        else
        {
            mc++;
        }
        //cout << c << " "<< tc << " / " << mc << endl;
        if(res)
        {
            if(tc<mc || (tc-mc)>(n/3))
            {
                res = 0;
                //cout << "NO" << endl;
            }
        }
    }
    
    if(tc!=mc*2)
    {
        res=0;
    }
    
    string s = res?"YES":"NO";
    cout << s << endl;

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