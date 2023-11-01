/*
Given a weighted, directed and connected graph of V vertices and E edges,
Find the shortest distance of all the vertex's from the source vertex S.
If a vertices can't be reach from the S then mark the distance as 10^8. 
Note: If the Graph contains a negative 
cycle then return an array consisting of only -1.
*/


/*
E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
S = 2
Output:
1 6 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-0. This has a distance of 1.
For nodes 2 to 1, we cam follow the path-
2-0-1, which has a distance of 1+5 = 6,
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V,1e8);
        dist[S]=0;
        
        // in N-1 relaxation it is 100% sure that we will get our minimun weights
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int mt=it[2];
                
                if(mt+dist[u]<dist[v]){
                    dist[v]=dist[u]+mt;
                }
            }
        }
        
        // this loops tells us that even after n-1 relaxation if we get change in weight this means that negative cycle is presenmt in our graph
        for(auto it : edges){
            int u=it[0];
            int v = it[1];
            int mt = it[2];
            if(dist[u]+mt<dist[v]){
                return{-1};
            }
        }
        
        // if we do not get negative cycle then we will return our answer of vector dist with minimun distances
        return dist;
    }
};
