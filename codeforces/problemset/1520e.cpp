#include <bits/stdc++.h>
 
using namespace std;

#define SM 200000
#define ull unsigned long long
int arr[SM];
int rev_arr[SM];

void solve()
{
    int n = 0;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cost[2];
    vector<int> sheepPosition;
    int middle = 0;
    int sheepCount = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(s[i]=='.')
        {
            continue;
        }
        sheepCount++;
        sheepPosition.push_back(i);
    }
    if(sheepCount == n || sheepCount == 0)
    {
        cout << 0 << endl;
        return;
    }
    middle = sheepPosition[sheepCount/2];

    int pos[2] = {middle, middle};
    int space[2] = {0, 0};
    ull result = 0;
    for(int i = 0 ; i < n; i++)
    {
        pos[0] -= 1;
        pos[1] += 1;
        int flag = 0;
        if(pos[0] >= 0)
        {
            flag++;
            if(s[pos[0]] == '.')
            {
                space[0]++;
            }
            else
            {
                result += (ull)(space[0]);
            }
        }
        if(pos[1] < n)
        {
            flag++;
            if(s[pos[1]] == '.')
            {
                space[1]++;
            }
            else
            {
                result += (ull)(space[1]);
            }
        }
        if(flag==0)
        {
            break;
        }
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