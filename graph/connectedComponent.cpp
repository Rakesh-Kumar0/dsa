#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:

    // function to count components in undirected graph
    int countComponents(int v, vector<vector<int>>& edges){

        // create adjacency list from edges list
        vector<vector<int>> adjLs(v);
        for(auto &e : edges){
            adjLs[e[0]].push_back(e[1]);
            adjLs[e[1]].push_back(e[0]);
        }

        // visited array keep track  visited node
        vector<int> visited(v, 0);


        // variable to count the number of connected components
        int components = 0;

        //Traversal all the node in the graph
        for(int i =0; i<v; i++){

            // if the node is not visited , it's a new components
            if(!visited[i]){
                components++;
                // start BSF from this node
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                // perform BSF traversal
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    // visit all neighbour node
                    for(auto &it : adjLs[node]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push(it);
                        
                        }
                    }
                }
            }
        }
        return components;
    }
};
int main(){
    // Number of vertices
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    // Create solution object
    Solution sol;

    // Print the number of connected components
    cout << "Number of Connected Components: " 
         << sol.countComponents(V, edges) << endl;

    return 0;
}