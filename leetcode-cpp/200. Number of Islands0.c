#include <stdlib.h>

/* 队列中存储的坐标结构 */
typedef struct {
    int x;  // 行
    int y;  // 列
} Node;

int numIslands(char** grid, int gridSize, int* gridColSize) {
    // 边界判断
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return 0;
    }

    int rows = gridSize;        // 行数 m
    int cols = gridColSize[0];  // 列数 n（默认每行一样）

    int count = 0;  // 岛屿数量

    // BFS 队列（最多所有格子都入队）
    Node* queue = (Node*)malloc(sizeof(Node) * rows * cols);

    // 四个方向：上、下、左、右
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 遍历整个网格
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // 如果当前是陆地 '1'
            if (grid[i][j] == '1') {

                count++;  // 发现一个新的岛屿

                // 初始化队列
                int front = 0;  // 队头
                int rear = 0;   // 队尾

                // 把当前点入队
                queue[rear].x = i;
                queue[rear].y = j;
                rear++;

                // 立刻“淹没”（标记为已访问）
                // 防止重复入队
                grid[i][j] = '0';

                // BFS 开始
                while (front < rear) {

                    // 取出队头元素
                    int x = queue[front].x;
                    int y = queue[front].y;
                    front++;

                    // 向四个方向扩展
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];  // 新行
                        int ny = y + dy[k];  // 新列

                        // 判断是否越界 + 是否是陆地
                        if (nx >= 0 && nx < rows &&
                            ny >= 0 && ny < cols &&
                            grid[nx][ny] == '1') {

                            // 是同一个岛的陆地 → 入队
                            queue[rear].x = nx;
                            queue[rear].y = ny;
                            rear++;

                            // 入队后立刻标记为水（避免重复访问）
                            grid[nx][ny] = '0';
                        }
                    }
                }
            }
        }
    }

    // 释放队列内存
    free(queue);

    return count;
}