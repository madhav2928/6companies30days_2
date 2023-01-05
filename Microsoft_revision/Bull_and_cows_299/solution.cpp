#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m;
        int b = 0;
        int c = 0;
        for(auto i:secret)
        {
            m[i]++;
        }

        int n = secret.length();
        for(int i = 0;i<n;++i)
        {
            if(guess[i]==secret[i])
            {
                c++;
                m[guess[i]]--;
            }
        }
        for(int i = 0;i<n;++i)
        {
            if(guess[i]==secret[i])
            {
                
            }
            else
            {
                if(m.count(guess[i]) && m[guess[i]])
                {
                    m[guess[i]]--;
                    b++;
                }
            }
        }
        string res = "";
        res+= to_string(c)+"A"+to_string(b)+"B";
        return res;
    }
};