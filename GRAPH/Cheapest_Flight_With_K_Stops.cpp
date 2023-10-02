// QUESTONS

/*
There are n cities and m edges connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei]
 indicates that there is a flight from the city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest
 price from src to dst with at most k stops. If there is no such route, return -1

Note: The price from city A to B may be different From price from city B to A. 

*/


#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


class Solution {
public:
    // Function to find the cheapest flight from source to destination with at most 'k' stops.
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Create an adjacency list to represent the flights between cities.
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        // Create a queue for BFS traversal with elements {number of stops, {current node, cost so far}}.
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        // Create a vector to store the minimum cost to reach each city, initialized to a large value.
        vector<int> dis(n,1e9);
        
        while(!q.empty()){
            int stop = q.front().first; // Number of stops made so far.
            int node = q.front().second.first; // Current node (city).
            int cost = q.front().second.second; // Cost to reach the current node.
            q.pop();
            
            if(stop > k) continue; // If the number of stops exceeds 'k', skip this path.
            
            for(auto it:adj[node]){ // Iterate through neighboring cities.
                int adjCity = it.first; // Next city.
                int price = it.second; // Price to reach the next city.
                
                if(cost + price < dis[adjCity] && stop <= k){
                    // If the cost to reach the next city through the current path is less than the recorded minimum cost,
                    // and the number of stops is within 'k', update the minimum cost and push the next city into the queue.
                    dis[adjCity] = cost + price;
                    q.push({stop + 1, {adjCity, cost + price}});
                }
            }
        }
        
        if(dis[dst] != 1e9) return dis[dst]; // If a valid path to the destination is found, return the minimum cost.
        else return -1; // If no valid path is found, return -1.
    }
};

