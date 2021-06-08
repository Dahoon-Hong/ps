#include <bits/stdc++.h>
 
using namespace std;

const int SIZE = 26;

int get_idx(int x=-1, int y=-1, int z=-1)
{
    if(z != -1)
    {
        return (x+1)*26*26+(y+1)*26+(z+1);
    }

    if(y != -1)
    {
        return (x+1)*26+(y+1);
    }

    return x+1;

};

string get_str(int idx)
{
    string res = "";
    int len = 0;
    if(idx > 702)
    {
        len = 3;
    }
    else if (idx > 26)
    {
        len = 2;
    }
    else
    {
        len = 1;
    }

    for(int i = 0 ; i < len ; i++)
    {
        int c = idx % 26;
        idx /= 26;
        if(c==0)
        {
            c = 26;
        }
        res.insert(0, 1, char(c+'a'-1));
    }
    return res;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int wmap[1010] = {0, };

    int tvar[3];
    tvar[0] = get_idx(s[0]-'a');
    tvar[1] = get_idx(s[1]-'a');
    tvar[2] = get_idx(s[0]-'a', s[1]-'a');

    for(int j = 0 ; j < 3 ; j++)
    {
        if(tvar[j] <= 1000)
        {
            wmap[tvar[j]]=1;
        }            
    }

    for(int i = 2 ; i < s.length(); i++)
    {
        int var[3];
        int idx[3] = {
            s[i-2]-'a',
            s[i-1]-'a',
            s[i]-'a'
        };
        var[0] = get_idx(idx[0], idx[1], idx[2]);
        var[1] = get_idx(-1, idx[1], idx[2]);
        var[2] = get_idx(-1, -1, idx[2]);
        
        for(int j = 0 ; j < 3 ; j++)
        {
            if(var[j] <= 1000)
            {
                wmap[var[j]]=1;
            }            
        }
    }
    
    for(int i = 1 ; i <= 1000; i++)
    {
        
        if(wmap[i] == 0 )
        {
            //cout << i << endl;
            cout << get_str(i) << endl;
            return;
        }
    }
    cout << get_str(1001) << endl;
    return;
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