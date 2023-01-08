#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int> , greater<int> > a;
        for(auto i:nums)
        {
            a.push(i);
        }
//         unordered_map<int,vector<int> > m;
//         int k = 0;
//         while(!a.empty())
//         {
//             int temp = a.top();
//             a.pop();
//             if(m.empty())
//             {
//                 m[k].push_back(temp);
//             }
//             else
//             {
//                 int p = m[k].size();
//                 int top = m[k][p-1];
//                 if(top+1 == temp)
//                 {
//                     m[k].push_back(temp);
//                 }
//                 else
//                 {
//                     m[++k].push_back(temp);
//                 }
//             }
//         }
//         for(auto i:m)
//         {
//             int temp = i.second.size();
//             if(temp>=3)
//             {
                
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
        unordered_map<int,int> m;
        for(auto i: nums)
        {
            m[i]++;
        }
        for(auto i:nums)
        {
            if(m[i]==0)
            {
                continue;
            }
            int present_num = m[i];
            int cnt = 0;
            int curr_element = i;
            //below second condition is to cut the subsequence when there is a chance
            while(m.count(curr_element) && m[curr_element]>=present_num)
            {
                present_num = max(present_num , m[curr_element]);
                m[curr_element]--;
                curr_element++;
                cnt++;
            }
            if(cnt<3)
            {
                return false;
            }
        }
        return true;
    }
};