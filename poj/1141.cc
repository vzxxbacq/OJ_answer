#include <bits/stdc++.h>
using namespace std;
int const INF = 0x3f3f3f3f;  
int const MAX = 105;  
int dp[MAX][MAX], path[MAX][MAX];  
char s[MAX];  
  
void Print(int i, int j)  {  
    if(i > j)  
        return;  
    if(i == j){  
        if(s[i] == '(' || s[i] == ')')  
            printf("()");  
        else  
            printf("[]");  
    }  
    else if(path[i][j] == -1){  
        printf("%c", s[i]);  
        Print(i + 1, j - 1);  
        printf("%c", s[j]);  
    }  
    else{  
        Print(i, path[i][j]);  
        Print(path[i][j] + 1, j);  
    }  
}  
  
void solve(){
    while(cin >> s) {  
        int n = strlen(s);  
        if(n == 0)  {  
            printf("\n");  
            continue;  
        }  
        memset(dp, 0, sizeof(dp));  
        for(int i = 0; i < n; i++)  
            dp[i][i] = 1;  
        for(int l = 1; l < n; l++)  {  
            for(int i = 0; i < n - l; i++)  {  
                int j = i + l;  
                dp[i][j] = INF;  
                if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))  {  
                    dp[i][j] = dp[i + 1][j - 1];  
                    path[i][j] = -1;  
                }  
                for(int k = i; k < j; k++)  {  
                    if(dp[i][j] > dp[i][k] + dp[k + 1][j])  {  
                        dp[i][j] = dp[i][k] + dp[k + 1][j];  
                        path[i][j] = k;  
                    }  
                }  
            }  
        }  
        Print(0, n - 1);  
        printf("\n");  
    }  
}

int main()  {
#ifndef ONLINE_JUDGE
    freopen("datain.txt", "r", stdin);
    freopen("dataout.txt", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
}  