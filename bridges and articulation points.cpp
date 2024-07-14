    #include<bits/stdc++.h>
    #define endll '\n'
    #define int long long int
    using namespace std;
    const int mod=1e9+7;
    vector<pair<int,int>> bridges;
    vector<int> tmr,low,sz,art;
    int timer=0;
    void dfs(int u,int p,vector<vector<int>> &adj,vector<bool> &vis)
    {
        tmr[u]=++timer;
        low[u]=timer;
        vis[u]=true;
        bool ok=true;
        for(auto it:adj[u])
        {
            if(it==p)continue;
            if(!vis[it])
            {
                dfs1(it,u,adj,vis);
                low[u]=min(low[u],low[it]);
                if(low[it]>tmr[u])
                {
                    bridges.push_back({it,u});
                }
                ok &=(tmr[u]>low[it]);
            }
            else
            {
                low[u]=min(low[u],low[it]);
            }
        }
        if(!ok){art.push_back(u);}
    }
