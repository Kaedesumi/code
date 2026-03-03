#include <stdio.h>

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    int A[100][100];
    int B[100][100];
    int C[100][100];

    // 输入矩阵 A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // 输入矩阵 B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // 计算矩阵 C = A × B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = 0;  // 初始化
            for (int t = 0; t < m; t++) {
                C[i][j] += A[i][t] * B[t][j];
            }
        }
    }

    // 输出矩阵 C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d", C[i][j]);
            if (j != k - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}