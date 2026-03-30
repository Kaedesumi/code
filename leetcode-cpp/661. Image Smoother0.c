#include <stdlib.h>

/**
 * img: 原始二维数组
 * imgSize: 行数 m
 * imgColSize: 每一行的列数（这里所有行都一样）
 * returnSize: 返回的行数
 * returnColumnSizes: 每一行的列数数组
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    
    int m = imgSize;          // 行数
    int n = imgColSize[0];    // 列数

    // 设置返回的行数
    *returnSize = m;

    // 分配每一行的列数数组
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);

    // 分配结果二维数组
    int** ans = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;           // 每一行列数都是 n
        ans[i] = (int*)malloc(sizeof(int) * n); // 为每一行分配空间
    }

    // 遍历每一个位置 (i, j)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            int sum = 0;   // 当前九宫格的总和
            int cnt = 0;   // 有效元素个数

            // 枚举以 (i,j) 为中心的 3×3 区域
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {

                    // 判断是否越界（只处理合法位置）
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        sum += img[x][y]; // 累加值
                        cnt++;            // 计数 +1
                    }
                }
            }

            // 求平均值（C语言整数除法自动向下取整）
            ans[i][j] = sum / cnt;
        }
    }

    // 返回结果矩阵
    return ans;
}