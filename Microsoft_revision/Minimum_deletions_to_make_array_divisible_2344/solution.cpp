#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& a) {
        int res = a[0];
        for(int i = 1;i<a.size();++i)
        {
            res = __gcd(res,a[i]);
        }
        int cnt = 0;
        sort(nums.begin(),nums.end());
        for(auto i:nums)
        {
            if(i==res || res%i==0)
            {
                return cnt;
            }
            cnt++;
        }
        return -1;
        
        
    }
};