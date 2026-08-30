
///using long long and long double for safety
#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
typedef long long ll;
typedef long double ld;

ll n,a[MAXN],pos[MAXN];
ld rez[MAXN];

signed main (){
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >>n;
    for (int i=1;i<=n;++i){
        cin >>a[i];
    }
    rez[1]=a[1];
    pos[1]=1;
    cout <<1<<' ';
    for (int i=2;i<=n;++i){
        pos[i]=i;
        rez[i]=a[i];
        while (pos[i]>1){
            ld crt=rez[pos[i]-1]*(pos[i]-1-pos[pos[i]-1]+1)+(i-pos[i]+1)*rez[i];
            crt/=ld (i-pos[pos[i]-1]+1);
            if (crt>=rez[i]){
                rez[i]=crt;
                pos[i]=pos[pos[i]-1];
            }
            else
                break;
        }
        cout <<i-pos[i]+1<<' ';
    }
}