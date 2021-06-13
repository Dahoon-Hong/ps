#include <bits/stdc++.h>
 
using namespace std;

int arr[100];

void solve()
{
    int n;
    cin >> n;

    int min_idx=0, max_idx=0;
    int min_val=101, max_val=0;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
        // cout << arr[i] << endl;
        if(min_val > arr[i])
        {
            min_idx = i;
            min_val = arr[i];
        }
        if(max_val < arr[i])
        {
            max_idx = i;
            max_val = arr[i];
        }
    }
    //printf("%d %d\n", min_idx, max_idx);

    int ll;
    int lr;
    int rr;
    ll = max(min_idx, max_idx) + 1;
    rr = n - min(min_idx, max_idx);
    lr = min(min_idx, max_idx) + 1 + n - max(min_idx, max_idx);
    //printf("%d %d %d\n",ll,rr,lr);
    cout << min({ll,lr,rr}) << endl;


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