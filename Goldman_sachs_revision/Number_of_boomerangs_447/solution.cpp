#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();
        for(int i = 0;i<n;++i)
        {
            unordered_map<double,int> m;
            int x = points[i][0];
            int y = points[i][1];
            for(int j = 0;j<n;++j)
            {
                if(i==j)
                {
                    continue;
                }
                int x1 = points[j][0];
                int y1 = points[j][1];
                double dist = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
                m[dist]++;
            }
            for(auto i:m)
            {
                if(i.second>1)
                {
                    cnt += ((i.second)*(i.second-1));
                }
            }
        }
        return cnt;
    }
};