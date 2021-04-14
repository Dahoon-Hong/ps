#include <bits/stdc++.h>
 
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string ts;
    string s;
    int c;
    int z, w;
    
    int cm = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ts >> c;
        if(c > cm)
        {
            s = ts;
            z = c;
            w = 1;
        }
    }

    
    cout << s << " "<<z <<"/" <<w << endl;
}

int main() 
{
    int TC;
    cin >> TC;
    for(int i =1 ; i <= TC ; i++)
    {
        cout << "Case #" <<i<<": ";
        solve();
    }
}