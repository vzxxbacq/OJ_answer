// author: vzxxbacq
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200, INF = 0x3f3f3f3f;
int dp[MAX][3], a[MAX], n;





int main(){
#ifndef ONLINE_JUDGE
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    void solve();
    solve();
    return 0;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);    
#endif
}






void init(){
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) dp[i][j] = INF;
    dp[0][0] = 0;
    return;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) a[i] = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    init();
    for(int i=1;i<=n;i++){
        dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
        if(a[i]==2||a[i]==3) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        if(a[i]==1||a[i]==3) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
    }
    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << ans << endl;
    return;
}

