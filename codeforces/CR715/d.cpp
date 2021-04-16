#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;

#define N 100000
#define BIT_N   25001
#define ANS_N   37501
bitset<8> buffer[3][BIT_N];
bitset<8> ans[ANS_N];


int solve()
{
    int n;
    cin >> n;
    memset(ans, 0, ANS_N * sizeof(bitset<8>));
    
    for(int j = 0 ; j < 3 ; j++)
    {
        int num = 0;
        char temp;
        int idx = 0;
        bitset<8> bst;
        for(int i=0; i<2*n; i++)
        {
            cin >> temp;
            buffer[j][i/8][i%8] = int(temp-'0');
        }
    }
    
    int t1 = 0;
    int t2 = 1;
    for(int k = 0; k < 3; k++)
    {
        int ac=0;
        int bc=0;
        int count = 0;
        if(t2==3)
        {
            t2 = 0;
        }
        
        for(int i = 0 ; i < 3*n; i++)
        {
            //printf("%d %d %d %d\n", ac, bc, buffer[0][ac/8].test(ac%8), buffer[1][bc/8].test(bc%8));
            if(ac==2*n && bc==2*n)
            {
                break;
            }
            if(ac==2*n && bc<2*n)
            {
                ans[i/8][i%8] = buffer[t2][bc/8][bc%8];
                bc++;
            }
            else if(ac<2*n && bc==2*n)
            {
                ans[i/8][i%8] = buffer[t1][ac/8][ac%8];
                ac++;
            }
            else
            {
                if(buffer[t1][ac/8][ac%8] == buffer[t2][bc/8][bc%8])
                {
                    ans[i/8][i%8] = buffer[t1][ac/8][ac%8];
                    ac++;
                    bc++;
                }
                else
                {
                    int at=0;
                    int bt=0;
                    for(int j = ac ; j < 2*n;j++)
                    {
                        if(buffer[t1][j/8][j%8] == buffer[t2][bc/8][bc%8])
                        {
                            break;
                        }
                        at++;
                    }
                    for(int j = bc ; j < 2*n;j++)
                    {
                        if(buffer[t1][ac/8][ac%8] == buffer[t2][j/8][j%8])
                        {
                            break;
                        }
                        bt++;
                    }
                    if(at<=bt)
                    {
                        ans[i/8][i%8] = buffer[t1][ac/8][ac%8];
                        ac++;
                    }
                    else
                    {
                        ans[i/8][i%8] = buffer[t2][bc/8][bc%8];
                        bc++;
                    }
                }
            }
            //printf("%d\n", ans[i/8].test(i%8));
        }
        
        if(bc == 2*n && ac == 2*n)
        {
            for(int i = 0 ; i < 3*n; i++)
            {
                cout << ans[i/8].test(i%8);
            }
            cout << endl;
            break;
        }
        else
        {
            t1++;
            t2++;
        }
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