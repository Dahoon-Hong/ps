#include <bits/stdc++.h>
 
using namespace std;

int solution(vector< vector<int> > &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    
    int n = A.size();
    int m = A[0].size();

    vector<int> current;
    vector<int> diff;
    for(int j = 0 ; j < n ; j++)
    {
        current.push_back(A[j][0]);
        diff.push_back(0);
    }

    for(int i = 1 ; i < m ; i++)
    {
        int nonflip = 0;
        int flip = 0;
        for(int j = 0 ; j < n; j++)
        {
            if(current[j] == -1)
            {
                continue;
            }
            if(A[j][i] == current[j])
            {
                nonflip += 1;
                diff[j] = 0;
            }
            else
            {
                flip += 1;
                diff[j] = 1;
            }
        }
        if(nonflip == 0 && flip == 0)
        {  
            return -1;
        }

        for(int j = 0 ; j < n ; j++)
        {
            if(!diff[j] && flip > nonflip)
            {
                current[j] = -1;
                continue;
            }
            if(diff[j] && flip <= nonflip)
            {
                current[j] = -1;
                continue;
            }
        }
    }
    int res = 0;
    for(int j = 0 ; j < n ; j++)
    {
        if(current[j] != -1)
        {
            res++;
        }
    }
    return res;
}


int main()
{
    vector<vector<int>> input = {
        {1,0,0,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,1}
    };
    cout << solution(input) << endl;
    return 0;
}