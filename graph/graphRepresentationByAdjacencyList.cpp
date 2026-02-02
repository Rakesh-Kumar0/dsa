#include<iostream>
#include<vector>
using namespace std;
 
// main function
int main(){
    int n, m;
    cin>>n >>m;
    vector<int> adj[n+1]; // adjacency list
    for(int i = 0; i < m; i++){
        int u, v;
        cin >>u >>v;
        adj[u].push_back(v);
        adj[u].push_back(u); // in case of directed graph this line will remove
    }
    return 0;

}

