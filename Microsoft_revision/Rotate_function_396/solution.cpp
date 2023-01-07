#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return 0;
        }
        else
        {
            vector<int> help(n-1,0);
            int sum = 0;
            int cnt = 0;
            for(int i = 0;i<n;++i)
            {
                sum += nums[i];
                cnt += i*nums[i];
            }
            sum -= nums[n-1];
            help[0] = sum;
            for(int i = 0;i<n-2;++i)
            {
                sum += nums[n-1-i]- nums[n-2-i];
                help[i+1] = sum;
            }
            
            // vector<int> res;
            // res.push_back(cnt);
            int result = cnt;
            for(int i =1;i<n;++i)
            {
                cnt += help[i-1]-nums[n-i]*(n-1);
                result = max(result,cnt);
            }
            // sort(res.begin(),res.end());
            // for(auto i:res)
            // {
            //     cout<<i<<" ";
            // }
            // return res[res.size()-1];
            return result;
        }
    }
};