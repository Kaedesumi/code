#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    // 利用对称性，C(n, m) = C(n, n-m)
    // 这样可以让数组更小一些
    m = min(m, n - m);

    // dp[j] 表示当前处理到某一行时的 C(i, j)
    vector<int> dp(m + 1, 0);

    // C(i, 0) = 1
    dp[0] = 1;

    // 逐行计算组合数
    for (int i = 1; i <= n; i++) {
        // 必须从后往前更新
        // 否则 dp[j-1] 会被当前行提前覆盖，导致结果错误
        for (int j = min(i, m); j >= 1; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    cout << dp[m] << endl;

    return 0;
}