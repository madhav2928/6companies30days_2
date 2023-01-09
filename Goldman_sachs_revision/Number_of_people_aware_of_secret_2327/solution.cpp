#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // queue<int> del;
        // queue<int> f;
        // int cnt = 0;
        // del.push(1+delay);
        // f.push(1+forget);
        // for(int i = 1;i<=n;++i)
        // {
        //     if(f.front()==i)
        //     {
        //         while(f.front()==i)
        //         {
        //             f.pop();
        //             cnt--;
        //         }
        //     }
            
        //     if(del.front()==i)
        //     {
        //         while(del.front()==i)
        //         {
        //             del.pop();
        //             cnt++;
        //         }
        //     }

        //     if(cnt!=0)
        //     {
        //         for(int j = 0;j<cnt;++j)
        //         {
        //             del.push(i+delay);
        //             f.push(i+forget);
        //         }
        //     }
        // }
        // return f.size();
        vector<long> dp(n+1 , 0);
          long mod = 1e9+7;
          long PeopleSharingSecret = 0;
          long ans = 0;
          
          //day 1 only one person knows the secret
          dp[1] = 1;

          //i -> days
          for(int i=2; i<=n; i++){
               long noofNewPeopleSharingSecret = 0;
              if(i-delay > 0){
                   noofNewPeopleSharingSecret = dp[i-delay];
              }
              long noofPeopleForgettingSecret = 0;
              if(i - forget > 0)    noofPeopleForgettingSecret = dp[i-forget];
              PeopleSharingSecret += (noofNewPeopleSharingSecret - noofPeopleForgettingSecret + mod)%mod;
              
              //dp[i] => no of peoples who found secret on ith day
              dp[i] = PeopleSharingSecret;
          }
        
          for(int i=n-forget+1; i<=n; i++){
              ans = (ans+dp[i])%mod;
          }
          return (int)ans;
    }
};