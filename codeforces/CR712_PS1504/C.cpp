#include <bits/stdc++.h>
 
using namespace std;
 

int main() 
{
    int TC;
    cin >> TC;
    while(TC-->0)
    {
        int n;
        string s;
        cin >> n >> s;
        int one_count = 0;
        for(int i = 0; i < n; i++)
        {
            one_count += (s[i] == '1');
        }
        if(one_count % 2 == 1 ||
            !(s[0] == '1' && s[n-1] == '1'))
        {
            cout << "NO" << endl;
            continue;
        }

        string a, b;
        int half_of_1 = one_count/2;
        int count_of_1 = 1;
        int flag = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                if(count_of_1++ <= half_of_1)
                {
                    a.push_back('(');
                    b.push_back('(');
                }
                else
                {
                    a.push_back(')');
                    b.push_back(')');
                }
            }
            else 
            {
                if(flag)
                {
                    a.push_back('(');
                    b.push_back(')');
                }
                else
                {   
                    a.push_back(')');
                    b.push_back('(');
                }
                flag = !flag;
            }
        }
        cout << "YES" << endl;
        cout << a << '\n' << b << endl;
    }
}