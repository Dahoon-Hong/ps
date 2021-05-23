#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int RR=1;
int SS=2;
int PP=3;

int w, e;

int expect(int next, int r, int s, int p)
{
    double wn;
    double en;
    double ln;
    if(next == RR)
    {
        wn = s;
        en = r;
        ln = p;
    }
    else if(next == SS)
    {
        wn = p;
        en = s;
        ln = r;
    }
    else
    {
        wn = r;
        en = p;
        ln = s;
    }
    //printf("%d %lf %lf %lf\n",next, wn, en, ln);
    double t = double(r+s+p);
    int we = double(wn)/t*double(w);
    int ee = double(en)/t*double(e);

    return we+ee;
}

string solve(int)
{
    cin >> w >> e;
    int exp = 0;
    string res;
    int r=1, p=0, s=1;
    res.append("R");
    res.append("S");
    for(int i = 2 ; i < 40; i++)
    {
        if(i%2==0)
        {
            res.append("R");
        }
        else
        {
            res.append("S");
        }
    }
    for(int i = 40 ; i < 60; i++)
    {
        res.append("P");
    }
    return res;
}

int main() 
{
    int TC;
    cin >> TC;
    int exp;
    cin >> exp;
    for(int i =1 ; i <= TC ; i++)
    {
        cout << "Case #" <<i<<": " << solve(exp) << endl;
    }
}