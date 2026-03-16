#include <stdlib.h>

/* 哈希表节点结构 */
typedef struct Node {
    int key;            // 存储数组中的数字
    int value;          // 存储该数字对应的下标
    struct Node* next;  // 处理哈希冲突的链表指针
} Node;

/* 哈希函数 */
int hash(int key, int size) {
    int h = key % size;
    return h < 0 ? h + size : h;   // 防止负数
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int tableSize = numsSize * 2;          // 哈希表大小
    Node** table = (Node**)calloc(tableSize, sizeof(Node*));

    for (int i = 0; i < numsSize; i++) {

        int need = target - nums[i];       // 需要找到的另一个数
        int h = hash(need, tableSize);

        /* 在哈希表中查找 need */
        Node* cur = table[h];
        while (cur) {
            if (cur->key == need) {        // 找到答案
                int* result = (int*)malloc(sizeof(int) * 2);
                result[0] = cur->value;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
            cur = cur->next;
        }

        /* 没找到，则把当前数加入哈希表 */
        int h2 = hash(nums[i], tableSize);

        Node* node = (Node*)malloc(sizeof(Node));
        node->key = nums[i];   // 数值
        node->value = i;       // 下标
        node->next = table[h2];
        table[h2] = node;
    }

    *returnSize = 0;
    return NULL;
}