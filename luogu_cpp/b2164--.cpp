#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    //读取
    int n,m;
    cin >> n
        >> m;
    
    //利用对称性使m尽量小
    m = min(m,n - m);

    //创建数组储存动态结果
    vector<int> dp(m + 1, 0);

    dp[0] = 1;

    // 逐行计算组合数
    for (int i = 1; i <= n; i++)//其中i表示这是c(i,j)
    {
        for (int j = min(m,i); j >= 1; j--)//c(i,j)
        {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    cout << dp[m] << endl;
    return 0;
}