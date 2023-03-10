#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> delim(string a){
        vector<string> cur;
        string str = "";
        for (auto& c : a){
            if (c == ','){
                cur.push_back(str);
                str = "";
            }
            else str += c;
        }
        cur.push_back(str);
        return cur;
    }
    vector<string> invalidTransactions(vector<string>& t) {
        vector<string> ans;
        vector<bool> v(t.size());
        unordered_map<string, vector<vector<string>>> m;
        // m[string][0] = name
        // m[string][1] = time
        // m[string][2] = money
        // m[string][3] = city
        // m[string][4] = index
        // m[string][5] = original string
        for (int i = 0; i < t.size(); ++i){
            vector<string> ts = delim(t[i]);
            for (auto& vc : m[ts[0]]){
                if (vc[3] != ts[3] && abs(stoi(vc[1]) - stoi(ts[1])) <= 60){
                    if(!v[stoi(vc[4])]) {
                        ans.push_back(vc[5]);
                        v[stoi(vc[4])] = true;
                    }
                    if(!v[i]){
                        ans.push_back(t[i]);
                        v[i] = true;
                    }
                }
            }
            ts.push_back(to_string(i));
            ts.push_back(t[i]);
            m[ts[0]].push_back(ts);
            if (!v[i] && stoi(ts[2]) > 1000) {
                v[i] = true;
                ans.push_back(t[i]);
            }
        }
        return ans;
    }
};