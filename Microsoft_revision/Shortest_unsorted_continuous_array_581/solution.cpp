#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // vector<int> temp(nums.begin(),nums.end());
        // sort(temp.begin(),temp.end());
        // for(auto i:temp)
        // {
        //     cout<<i<<endl;
        // }
        // int n = nums.size();
        // if(n==1)
        // {
        //     return 0;
        // }
        // else
        // {
        //     int i = 0;
        //     int j = n-1;
        //     while(i<n)
        //     {
        //         if(nums[i]==temp[i])
        //         {
        //             i++;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     while( j>=0)
        //     {
        //         if(temp[j]==nums[j])
        //         {
        //             j--;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     cout<<i<<" "<<j<<endl;
        //     if(j<=i)
        //     {
        //         return 0;
        //     }
        //     return j-i+1;
        // }
        int n = nums.size(), start = -1, end = -1, prevHigh = n-1, prevLow = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[prevLow]) end = i;
            else prevLow = i;
        }
        for(int i=n-2; i >= 0; i--){
            if(nums[i] > nums[prevHigh]) start = i;
            else prevHigh = i;
        }
        return (start>=0 && end>=0) ? (end-start)+1 : 0;

    }
};