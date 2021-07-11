#include <bits/stdc++.h>
typedef unsigned long long llu;

using namespace std;


llu solve()
{
    llu N, C;
    cin >> N >> C;
    llu res = 0;
    llu l, r;

    map<llu, int> cm;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> l >> r;
        if(l-r > 1)
        {
            for(llu j = l+1; j < r ; j++)
            {
                auto it = cm.find(j);
                if(it == cm.end())
                {
                    cm.insert(pair<llu, int>(j, 1));
                }
                else
                {
                    it->second = it->second+1;
                }
            }
        }
        res++;
    }
    priority_queue<int> q;
    for(auto it = cm.begin(); it != cm.end(); it++)
    {
        q.push(it->second);
    }
    while(!q.empty() && C-->0)
    {
        int val = q.top();
        q.pop();
        res += (llu)val;
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