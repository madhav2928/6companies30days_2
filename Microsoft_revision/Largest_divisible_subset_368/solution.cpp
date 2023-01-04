#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> sum(n,1);
        vector<int> a(n,-1);
        int prev = -1;
        int res = -1;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<i;++j)
            {
                if((nums[i]%nums[j]==0) && (sum[j]>=sum[i]))
                {
                    sum[i] = sum[j]+1;
                    a[i] = j; 
                }
            }

            if(sum[i]>res)
            {
                res = sum[i];
                prev = i;
            }
        }
        vector<int> ans ;
        // for(auto i:sum)
        // {
        //     cout<<i<<" ";
        // }

        while(prev!=-1)
        {
            ans.push_back(nums[prev]);
            prev = a[prev];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};