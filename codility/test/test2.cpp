#include <bits/stdc++.h>
 
using namespace std;

#define N 1001

#define DEBUG true

class node {
public:
    int id;
    int adj_node_id[N] = {0, };
    int max_dependency_arr[N] = {0, };
    int min_dependency_arr[N] = {N+1, };
    int visited[N] = {0, };
};
node graph[N];
void bfs(int start_node, int current_node, int n)
{
    graph[start_node].visited[current_node] = 1;
    for(int i = start_node ; i < n; i++)
    {
        if(!graph[current_node].adj_node_id[i] || graph[start_node].visited[i])
        {
            continue;
        }
            
        graph[start_node].max_dependency_arr[i] = max({
            graph[start_node].max_dependency_arr[i], 
            graph[start_node].max_dependency_arr[current_node], 
            i});
        graph[start_node].min_dependency_arr[i] = min({
            graph[start_node].min_dependency_arr[i], 
            graph[start_node].min_dependency_arr[current_node], 
            i});
        if(DEBUG) printf("%d %d %d %d\n", 
            start_node, 
            i, 
            graph[start_node].max_dependency_arr[i], 
            graph[start_node].min_dependency_arr[i]);
        
        bfs(start_node, i, n);
        
        
    }
}

int solution(vector<int> &T) 
{
    // write your code in C++14 (g++ 6.2.0)
    memset(graph, 0, N*sizeof(node));

    int n = T.size();

    for(int i = 0 ; i < n; i++)
    {
        graph[i].id = i;
        graph[i].adj_node_id[i] = 1;  // self
        graph[i].adj_node_id[T[i]] = 1;  
        graph[T[i]].adj_node_id[i] = 1;
        for(int j = 0 ; j < n ; j++)
        {
            graph[i].min_dependency_arr[j] = N;
        }
    }

    int count = 0;
    for(int i = 0 ; i < n; i++)
    {
        bfs(i, i, n);
        for(int j = i ; j < n ; j++)
        {
            if(i!=j && graph[i].min_dependency_arr[j] == N){
                break;
            }
            if(graph[i].max_dependency_arr[j] <= j)
            {
                if(DEBUG) printf("(%d, %d)\n",i,j);
                count++;
            }
            
        }
        
    }
    if(DEBUG)
    {
        
        for(int i = 0 ; i < n ; i++)
        {
            cout << i << " : ";
            for(int j = 0; j < n ; j++)
            {
                printf("%d ", graph[i].adj_node_id[j]);
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
        
        for(int i = 0 ; i < n ; i++)
        {
            cout << i << " : ";
            for(int j = 0; j < n ; j++)
            {
                printf("%d ", graph[i].max_dependency_arr[j]);
            }
            cout << endl;
        }

        cout << "-----------------" << endl;
        
        for(int i = 0 ; i < n ; i++)
        {
            cout << i << " : ";
            for(int j = 0; j < n ; j++)
            {
                printf("%d ", graph[i].min_dependency_arr[j]);
            }
            cout << endl;
        }
    } 

    return count;
}


int main()
{
    vector<int> input = {2, 0, 2, 2, 1, 0};
    cout << solution(input) << endl;
    return 0;
}