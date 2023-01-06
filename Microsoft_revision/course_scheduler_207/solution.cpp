#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool help(int ind,vector<bool> &vis,vector<bool>&curr, vector<int> adj[])
    {
        vis[ind] = true;
        curr[ind] = true;

        for(auto i:adj[ind])
        {
            if(!vis[i])
            {
                if(help(i,vis,curr,adj))
                {
                    return true;
                }
            }
            else if(vis[i] && curr[i])
            {
                return true;
            }
        }
        curr[ind] = false;
        return false;


    }


    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool > vis(n,false);
        vector<bool > curr(n,false);
        vector<int> adj[n];
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }

        for(int i = 0;i<n;++i)
        {
            if(!vis[i])
            {
                if(help(i,vis,curr,adj))
                {
                    return false;
                }
            }
        }

        return true;
    }
};