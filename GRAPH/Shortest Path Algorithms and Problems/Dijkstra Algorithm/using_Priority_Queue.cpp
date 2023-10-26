/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list
 adj where adj[i] is a list of lists containing two integers where the first integer 
 of each list j denotes there is edge between i and j , second integers corresponds 
 to the weight of that  edge . You are given the source vertex S and You to Find the
  shortest distance of all the vertex's from the source vertex S. You have to return
 a list of integers denoting shortest distance between each node and Source vertex S.

Note: The Graph doesn't contain any negative weight cycle.
*/

/*
Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2

Output:
4 3 0

Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int,int>> s;
       s.insert({0,S});
       vector<int> dis(V,1e9);
       dis[S]=0;
       while(!s.empty()){
           auto it = *(s.begin());
           int node = it.second;
           int dist = it.first;
           s.erase(it);
           
           for(auto it:adj[node]){
               int adjnode = it[0];
               int weight = it[1];
               
               if(dist+weight < dis[adjnode] ){
                   
                   if(dis[adjnode] != 1e9){
                       s.erase({dis[adjnode],adjnode});
                   }
                   
                   dis[adjnode] = weight+dist;
                   s.insert({dist+weight , adjnode});
               }
           }
       }
       return dis;
    }
};