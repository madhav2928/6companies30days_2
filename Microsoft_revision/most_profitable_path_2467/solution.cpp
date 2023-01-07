#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(int node, int parentEdge, int dept, vector<int> &disToBob, vector<int>adj[], vector<int>& amount){
        int ans=INT_MIN; 
        for(auto &edge:adj[node]){
            if(edge!=parentEdge){
                ans=max(ans, dfs(edge, node, dept+1, disToBob, adj, amount));
                disToBob[node]=min(disToBob[node], disToBob[edge]+1);
            }
        }
        int cosTOpen=0;
        if(disToBob[node]>dept)cosTOpen=amount[node]; //If Bob reaches a Node Prior to Alice
        else if(disToBob[node]==dept)cosTOpen=amount[node]/2; //If Both Bob & Alice reaches a Node Simultaneously
        return (ans==INT_MIN)?cosTOpen:ans+cosTOpen;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //No. Of nodes in Graph
        int n=amount.size();
        //Build Graph Adjacency list
        vector<int>adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>disToBob(n, n); //To measure of Bob from Alice to a node
        disToBob[bob]=0;
        return dfs(0, 0, 0, disToBob,adj, amount);
    }
};