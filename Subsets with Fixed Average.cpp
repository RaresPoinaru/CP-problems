#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")

const int MAXN=503;
const int MOD=1e9+7;
const int MAXS=2*MAXN*MAXN;
const int C=MAXN*MAXN;

int n,x,a[MAXN],dp[MAXS],ndp[MAXS];

signed main (){
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

    cin >>n>>x;
    for (int i=1;i<=n;++i){
        cin >>a[i];
    }
    dp[0+C]=1;

    for (int i=1;i<=n;++i){
        for (int j=C-MAXN*i;j<C+MAXN*i;++j){
            ndp[j]=0;
        }

         for (int j=C-MAXN*i;j<C+MAXN*i;++j){

            if (dp[j]==0) continue;
            ndp[j+a[i]-x]=(ndp[j+a[i]-x]+dp[j])%MOD;
        }

         for (int j=C-MAXN*i;j<C+MAXN*i;++j){
            dp[j]=(ndp[j]+dp[j])%MOD;
        }
    }

    cout <<(dp[0+C]-1+MOD)%MOD;
}