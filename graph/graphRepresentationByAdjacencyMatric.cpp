#include<iostream>
#include<vector>
using namespace std;

// main function
int main(){
    int n,m;
    cin>>n >>m; // taking input for nodes and edges
    int adj[n+1][n+1];  // declearing adjacency matrix
    for(int i = 0; i < m; i++){
        int u , v;
        cin>>u >>v;
        adj[u][v] = 1;
        adj[v][u] = 1; // this will remove in case of directed graph
    }
    return 0;
}