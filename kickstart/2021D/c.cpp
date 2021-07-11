// WA in tc 1
#include <bits/stdc++.h>
#define llu unsigned long long
#define MAX_LEN 1000
using namespace std;

vector<llu>::iterator get_lower_bound(std::vector<llu> &vec, llu& value)
{
    auto it = vec.begin();

    while (it != vec.end() && *it <= value)
        ++it;

    if( it != vec.begin())
        --it;
    return it;
}

void solve()
{
    int N, M;
    vector<llu> a;
    vector<llu> b;
    vector<llu> s;
    vector<llu> ans;

    llu A, B;
    llu S;
    cin >> N  >> M ;
    for(int i = 0 ; i < N; i++)
    {
        cin >> A >> B;
        a.push_back(A);
        b.push_back(B);
    }
    for(int i = 0 ; i < M; i++)
    {
        cin >> S;
        s.push_back(S);
        ans.push_back(0);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // sort(s.begin(), s.end());

    int idx2=0;
    for(int i = 0; i < M ; i++)
    {
        auto it = get_lower_bound(a, s[i]);
        if(it == a.end())
        {
            it++;
        }
        
        int idx = it - a.begin();
        //cout << endl << " ["<< idx << "] " << s[i] << " " << a[idx] << " " << b[idx] << endl;
        if(s[i] > a[idx] && s[i] < b[idx])
        {
            
            a.insert(a.begin() + idx + 1, s[i]-1);
            b.insert(b.begin() + idx, s[i+1]);
            
        }
        else if(s[i] == a[idx])
        {
            a[idx] += 1;
            if(a[idx] > b[idx])
            {
                a.erase(a.begin()+idx);
                b.erase(b.begin()+idx);
            }
            
        }
        else if(s[i] == b[idx])
        {
            b[idx] -= 1;
            if(a[idx] > b[idx])
            {
                a.erase(a.begin()+idx);
                b.erase(b.begin()+idx);
            }
        }
        else
        {
            continue;
        }
        ans[i] = s[i];
    }

    for(int i = 0; i < M ; i++)
    {
        if(ans[i] != 0)
        {
            continue;
        }
        auto it = get_lower_bound(a, s[i]);
        if(it == a.end())
        {
            it++;
        }
        
        int idx = it - a.begin();
        // cout << endl << " ["<< idx << "] " << s[i] << endl;
        if(s[i] > a[idx] && s[i] < b[idx])
        {
            ans[i] = s[i];
            a.insert(a.begin() + idx + 1, s[i]-1);
            b.insert(b.begin() + idx, s[i+1]);
            
        }
        else if(s[i] <= a[idx])
        {
            ans[i] = a[idx];
            a[idx] += 1;
            if(a[idx] > b[idx])
            {
                a.erase(a.begin()+idx);
                b.erase(b.begin()+idx);
            }
            
        }
        else // (s[i] => b[idx])
        {
            ans[i] = b[idx];
            b[idx] -= 1;
            if(a[idx] > b[idx])
            {
                a.erase(a.begin()+idx);
                b.erase(b.begin()+idx);
            }
        }
        
    }
    for(int i = 0; i < M ; i++)
    {
        cout << " " << ans[i];
    }
}

int main() 
{
    int TC;
    cin >> TC;
    for(int i =1 ; i <= TC ; i++)
    {
        cout << "Case #" <<i<<":" ;
        solve();
        cout << endl;
    }
}