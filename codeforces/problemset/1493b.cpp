#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;

vector<int> valid_set;

int mmap[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void solve()
{
    int n;
        int H, M;
        string s;
        cin >> H >> M;
        cin >> s;
        // printf("%s\n",s.c_str());
        int h1, h2, m1, m2;
        h1 = s[0]-'0';
        h2 = s[1]-'0';
        m1 = s[3]-'0';
        m2 = s[4]-'0';

        while(true)
        {
            
            if(m2 >= 10)
            {
                m2 = 0;
                m1++; 
            }
            if(h2 >= 10)
            {
                h2 = 0;
                h1++;
            }
            if(m1*10+m2 >= M)
            {
                h2++;
                if(h2>=10)
                {
                    h1++;
                    h2=0;
                }
                m1=0;
                m2=0;
            }

            if(h1*10+h2 >= H)
            {
                h1=0;
                h2=0;
                m1=0;
                m2=0;
            }

            // printf("%d%d:%d%d\n", h1,h2,m1,m2);

            if (find(valid_set.begin(), valid_set.end(), m2) == valid_set.end())
            {
                m2++;
                continue;
            }
            if (find(valid_set.begin(), valid_set.end(), m1) == valid_set.end())
            {
                m2 = 0;
                m1++;
                continue;
            }
            if (find(valid_set.begin(), valid_set.end(), h2) == valid_set.end())
            {
                m1 = 0;
                m2 = 0;
                h2++;
                continue;
            }
            if (find(valid_set.begin(), valid_set.end(), h1) == valid_set.end())
            {
                m1=0;
                m2=0;
                h2=0;
                h1++;
                continue;
            }

            int rh1, rh2, rm1, rm2;
            rh1 = mmap[m2];
            rh2 = mmap[m1];
            rm1 = mmap[h2];
            rm2 = mmap[h1];

            if(rh1*10+rh2< H && rm1*10+rm2 < M)
            {
                printf("%d%d:%d%d\n", h1,h2,m1,m2);
                break;
            }
            else
            {
                m2++;
            }
        }

}

int main() 
{
    int TC;
    cin >> TC;

    valid_set.push_back(0);
    valid_set.push_back(1);
    valid_set.push_back(2);
    valid_set.push_back(5);
    valid_set.push_back(8);

    while(TC-->0)
    {
        solve();
    }
}