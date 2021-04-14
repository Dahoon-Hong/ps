#include <bits/stdc++.h>
 
using namespace std;

#define MAX_LEN  101

string sarr[MAX_LEN];

bool my_compare(string a, string b)
{
    int al = a.length();
    int bl = b.length();
    if(al > bl)
    {
        return true;
    }
    else if(al < bl)
    {
        return false;
    }
    else
    {
        for(int i = 0 ; i < al; i++)
        {
            if(a[i] < b[i])
            {
                return false;
            }
        }
    }
    return true;
}

int solve()
{
    int n;
    cin >> n;
    int count = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        sarr[i] = "";
        cin >> sarr[i];
    }

    for(int i = 1 ; i < n ; i++)
    {
        
        if(my_compare(sarr[i-1], sarr[i]))
        {
            
            int ac=0;
            int bc=0;
            int c = -1;

            do
            {
                int act = sarr[i-1][ac] - '0';
                int bct = 0;
                //printf("%s %s %d %d\n", sarr[i-1].c_str(), sarr[i].c_str(), act, sarr[i].length());
                if(ac < sarr[i].length())
                {
                    bct = sarr[i][bc] - '0';
                    // cout << bct << endl;
                    
                    if(act == bct)
                    {
                        if(c<=0)
                        {

                            c = 0;
                        }
                    }
                    else if(act > bct)
                    {
                        if(c<=0)
                        {
                            c = 1;
                        }
                    }
                    else
                    {
                        if(c<=0)
                        {
                            c = 2;
                        }
                    }
                    bc++;
                }
                ac++;
            }while(ac < sarr[i-1].length());

            
            // printf("%d %d %d\n", ac, bc, c);
            if(c == 0)
            {
                
                if(ac > bc && sarr[i-1][ac-1] < '9')
                {
                    sarr[i] = sarr[i-1];
                    sarr[i][ac-1] = sarr[i][ac-1] + 1;
                    count += (ac-bc);
                    bc = ac;

                }
                else
                {
                    // all same
                    //cout << "HI " << endl;
                    sarr[i] = sarr[i-1];
                    sarr[i].push_back('0');
                    count += (ac-bc);
                    count += 1;
                    bc = ac+1;
                }
                
            }
            else if (c==1)
            {
                for(int k = 0 ; k < (ac-bc+1) ; k++ )
                {
                    sarr[i].push_back('0');
                    count += 1;
                }
                bc = ac + 1;
            }
            else
            {
                for(int k = 0 ; k < (ac-bc) ; k++ )
                {
                    sarr[i].push_back('0');
                    count += 1;
                }
                bc = ac;
            }

        }
        cout << sarr[i-1] << " " << sarr[i] << endl;
    }

    
    return count;
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