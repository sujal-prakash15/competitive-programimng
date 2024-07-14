#include<bits/stdc++.h>
#define endll '\n'
#define int long long int
using namespace std;
const int mod=1e9+7;
vector<int> dijkstra(int s,vector<vector<vector<int>>> &adj)
    {
        int n=(int)adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n, 1e18);
        dis[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int curr = pq.top().first;
            pq.pop();
            if(curr>dis[node])continue;
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (curr + w < dis[v])
                {
                    dis[v] = curr + w;
                    pq.push({curr + w, v});
                }
            }
        }
        return dis;
    }
/*
    
*/
