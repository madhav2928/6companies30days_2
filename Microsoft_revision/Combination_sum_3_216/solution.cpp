#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    void help( set<vector<int> >& res, int k , int n,int i,vector<int> a ,int sum)
    {
        if( i==k && sum == n)
        {
            res.insert(a);
            return ;
        }
        
        for(int j = 1;j<=9;j++)
        {
            a.push_back( j);
            help(res,k,n,i+1,a,sum + j);
            a.pop_back();
        }
        return ;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        set<vector<int> > temp;
        int sum = 0;
        vector<int> a;
        help(temp,k,n,0,a,sum);
        for(auto i:temp)
        {
            res.push_back(i);
        }
        return res;
    }
};