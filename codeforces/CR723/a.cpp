#include <bits/stdc++.h>
 
using namespace std;

void solve()
{
    int n;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < 2*n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " " << a[i+n] << " ";
    }
    cout << endl;
    
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