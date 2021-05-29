#include <bits/stdc++.h>
 
using namespace std;

int get_11(int n)
{
    int result = 0;
    for(int i = 0 ; i < n; i++)
    {
        result *= 10;
        result += 1;
    }
    return result;
}
int get_10(int n)
{
    int result = pow(10, n-1);
    return result;
}

int base[10] = {
    0, 0, 11, 111, 1111,1111,111111,1111111,11111111,
    111111111};

void solve()
{
    int n;
    cin >> n;

    int c111=0;
    int c11=0;

    int flag = 0;
    
    while(true)
    {
        if(n < 0)
        {
            flag = 1;
            break;
        }

        if(n%11 == 0)
        {
            break;
        }

        if(n%111 == 0)
        {
            break;
        }
        n -= 11;
        //cout << n << endl;
    }


    if(flag==0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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