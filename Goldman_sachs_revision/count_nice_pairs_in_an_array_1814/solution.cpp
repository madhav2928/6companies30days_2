#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int M= 1e9+7;
    int rev(int n)
    {
        string temp = to_string(n);
        reverse(temp.begin(),temp.end());
        int res = stoi(temp);
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long int ,long long int> m;
        int n = nums.size();
        for(int i = 0;i<n;++i)
        {
            nums[i] = nums[i] - rev(nums[i]);
            m[nums[i]]++;
        }
        long long int ans = 0;
        for(auto val:m)
        {
            // if (val.second&1){
            //     ans+= ((val.second%M)*((val.second-1)/2)%M)%M;
            // }
            // else{
            //     ans+= (((val.second-1)%M)*((val.second/2)%M))%M;
            // } 
            ans += (((val.second%M )*((val.second-1)%M))/2)%M;
            ans= (ans)%M;
        }
        return (int)ans;

    }
};