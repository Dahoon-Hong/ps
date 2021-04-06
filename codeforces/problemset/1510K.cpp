#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1001
#define DEBUG false
int n;

int arr[2*MAX_N+1];
int sol[2*MAX_N+1];
int memo[2][2*MAX_N+1];

int get_next_position(int i, int clock_dir)
{
    if(memo[clock_dir][i] != 0)
    {
        return memo[clock_dir][i];
    }
    int next = 0;
    if(n%2==1)
    {
        if(clock_dir == 1)
        {
            if(i%2 == 1)
            {
                next = i+1;
            }
            else
            {
                next = i-n;
            }
        }
        else
        {
            if(i%2 == 1)
            {
                next = i+n;
            }
            else
            {
                next = i-1;
            }
        }
    }
    else
    {
        if(clock_dir == 1)
        {
            if(i%2 == 1)
            {
                next = i < n ? i+1 : i-n;
            }
            else
            {
                next = i <= n ? i+n : i-1;
            }
        }
        else
        {
            if(i%2 == 1)
            {
                next = i < n ? i+n : i+1;
            }
            else
            {
                next = i > n ? i-n : i-1;
            }
        }
    }
    if(next <= 0)
    {
        next += 2*n;
    }
    if(next > 2*n)
    {
        next -= 2*n;
    }

    memo[clock_dir][i] = next;
    return next;
}

void solve()
{
    for(int i = 1; i <= 2*n ; i++)
    {
        int org_check = -1;
        int rev_check = -1;

        int org_next = i;
        int rev_next = i;
        int target = arr[i];
        
        for(int j = 1 ; j <= n ; j++)
        {
            // forward
            org_next = get_next_position(org_next, 1);
            if(org_next == target)
            {
                org_check = j;
            }

            // backward
            rev_next = get_next_position(rev_next, 0);
            if(rev_next == target)
            {
                rev_check = j;
            }


            if(org_check != -1 || rev_check != -1)
            {
                if(org_check == -1 || rev_check == -1)
                {
                    sol[i] = max(org_check, rev_check);
                }
                else
                {
                    sol[i] = min(org_check, rev_check);
                }
                break;
            }
        }
        if(org_check == -1 && rev_check == -1)
        {
            sol[i] = n;
        }
    }
    
    int sum=0;
    for(int i = 1; i <= 2*n ; i++)
    {
        sum += sol[i];
        // cout << i << " " << sol[i] << endl;
    }

    if(sum != sol[1]*2*n)
    {
        cout << "-1";
    }
    else
    {
        cout << (sol[1]);
    }

    // cout << endl<< memo[0][1] << " " << memo[1][1] << endl;
    
}

int main() 
{
    
    cin >> n;
    int check = 0;
    for(int i = 1 ; i<=2*n ; i++)
    {
        cin >> arr[i];
        if(arr[i] == i)
        {
            check++;
        }
        // cout << arr[i];
    }
    // cout << endl;
    if(check == 2*n)
    {
        cout << "0";
    }
    else
    {
        solve();
    }
    
}