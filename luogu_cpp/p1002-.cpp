#include <bits/stdc++.h>
using namespace std;

int main(){
    //输入b的坐标和马的坐标
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;


    //blocked[i][j] 表示这个点能不能走
    bool blocked[25][25] = {false};

    //马的8个控制方向
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    //先把马所在的位置设为不能走
    blocked[hx][hy] = true;

    //把马控制到的点设为不能走
    for (int k = 0; k < 8; k++)
    {
        int x = hx + dx[k];
        int y = hy + dy[k];
        if (x >= 0 && x <= n && y >= 0 && y <= m) {
            blocked[x][y] = true;
        }
    }

    // dp[i][j]表示从(0,0)走到(i,j)的路径数
    long long dp[25][25] = {0};

    // 起点如果没有被马控制，路径数为 1
    if (!blocked[0][0]) {
        dp[0][0] = 1;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            //跳过起点
            if (i == 0 && j == 0) continue;
            
            // 如果这个点不能走，方法数就是 0
            if (blocked[i][j]) {
                dp[i][j] = 0;
                continue;
            }
        }
    }


    

}