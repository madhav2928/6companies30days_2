#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int help(vector<int> &res,string &a)
    {
        int n = a.length();
        int i = 0;
        int j = 1;
        while(j<n)
        {
            if(a[i]==a[j])
            {
                res[j] = i+1;
                i++;
                j++;
            }
            else
            {
                if(i!=0)
                {
                    i = res[i-1];
                }
                else
                {
                    res[j] = 0;
                    j++;
                }
            }
        }
        return res[n-1];
    }
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> res(n,0);
        int cnt = help(res,s);
        string result = s.substr(0,cnt);
        return result;
    }
};