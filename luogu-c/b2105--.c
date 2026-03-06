#include <stdio.h>

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    //开两个二维数组
    int A[n][m];
    int B[m][k];
    int C[n][k];

    //填入A，B
    for(int i = 0; i < n; i++){
        for(int p = 0; p < m; p++){
            scanf("%d",&A[i][p]);
        }
    }
    for(int p = 0; p < m; p++){
        for(int j = 0; j < k; j++){
            scanf("%d",&B[p][j]);
        }
    }

    //算并输出
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            C[i][j] = 0;
            for(int p = 0; p < m; p++){
                C[i][j] += A[i][p] * B[p][j];
            }
            printf("%d",C[i][j]);
            if(j != (k - 1))printf(" ");
        }
        printf("\n");
    }
    return 0;
}
    

