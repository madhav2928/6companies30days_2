#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> ans;
    int Max=-1;
    int help(int n,vector<int>&a,vector<int>&b,int i,int sum){
        if(i>=a.size()){
            if(sum>Max){
                Max = sum;
                ans = b;
                ans[11] += n;
            }
            return sum;
        }
        int t1 = 0;
        if(n>=a[i]+1){
            b[i] = a[i]+1;
            t1 += i +help(n-a[i]-1,a,b,i+1,sum+i);
            b[i] = 0;
        }
        t1 = max(t1,help(n,a,b,i+1,sum));
        return t1;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> a(12,0);
        int x = help(numArrows,aliceArrows,a,0,0);
        return ans;
    }
    
};