#include <bits/stdc++.h>
 
using namespace std;
#define N 200001
int memo[N];
int initK;

void solve(int n, int k)
{
    deque<vector<int>> q;

    q.push_back({k,0});
    int max_limit = max(n, k)*2;

    while(!q.empty())
    {
        vector<int> temp = q.front();
        q.pop_front();

        int tpos = temp[0];
        int count = temp[1];
        // cout << tpos << "/" << count << endl;

        if(memo[tpos] && memo[tpos] < count)
        {
            continue;
        }
        memo[tpos] = count;

        if(tpos == n)
        {
            break;
        }

        if(tpos%2 == 0)
        {
            q.push_back({tpos/2, count+1});
        }

        if(tpos <= max_limit)
        {
            q.push_back({tpos+1, count+1});
        }

        if(tpos > 0)
        {
            q.push_back({tpos-1, count+1});
        }
    }
}

int main() 
{
    int n, k;
    cin >> n >> k ;
    initK=k;
    solve(n, k);
    cout << memo[n] << endl;
    return 0;
}