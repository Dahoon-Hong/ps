// WA in tc1
#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int arr[100000] = {0, };
int arr2[100000] = {0, };
llu div1 = 1000000007;
llu div2 = 10000000000;

llu safe_power(int k, int p)
{
    llu res=1;
    for(int i = 0 ; i < p ; i++)
    {
        res *= (llu)k;
        res %= div2;
    }
    return res;
}

llu solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    
    int len = n/2;
    if(n%2 == 1)
    {
        len++;
    }
    for(int i = 0 ; i < len; i++)
    {
        int x = min(str[i]-'a', str[(n-i-1)]-'a');
        x = min(x+1, k);

        arr[i] = x;
    }
    
    int res = 0;

    for(int i = 0 ; i < len; i++)
    {
        if(arr[i] > 1)
        {
            res += ((llu)safe_power(k, len-i-1) * (llu)(arr[i]-1));
            res %= div2;
            
        }

        if(i == len-1)
        {
            res++;
        }
        //cout << res <<endl;
    }
    
    int flag = 0;
    for(int i = 0 ; i < len ; i++)
    {
        if(((str[i]-'a') - (arr[i]-1) != 0) || 
            ((str[n-1-i]-'a') - (arr[i]-1) != 0) )
        {
            flag=1;
            break;
        }

    }
    //cout << flag << endl;
    if(!flag)
    {
        res--;
    }

    return (res) % div1;


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