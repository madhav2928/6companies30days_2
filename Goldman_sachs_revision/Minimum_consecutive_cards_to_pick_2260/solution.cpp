#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> m;
        int n = cards.size();
        int i = 0;
        int j = 0;
        int cnt = INT_MAX;
        while(j<n)
        {
            m[cards[j]]++;
            if(m[cards[j]]>1)
            {
                cnt = min(cnt,j-i+1);
                while(i<j && m[cards[j]]>1)
                {
                    cnt = min(cnt,j-i+1);
                    m[cards[i]]--;
                    i++;
                }
            }
            j++;
        }
        return cnt==INT_MAX?-1:cnt;
    }
};