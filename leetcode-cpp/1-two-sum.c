#include <stdlib.h>

//hash node
typedef struct Node
{
    int key;
    int value;
    struct Node* next;
} Node;

//hash function
int hash(int key, int size){
    int h = key%size;
    return h < 0 ? h + size : h;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int tableSize = numsSize * 2;
    //create hash map
    Node** table = (Node**)calloc(tableSize, sizeof(Node*));

    for (int i = 0; i < numsSize; i++)
    {
        int need = target - nums[i];
        int h = hash(need, tableSize);

        /*search need in hash table*/
        Node* cur = table[h];
        while (cur)
        {
            if (cur->key == need)
            {
                int* result = (int*)malloc(sizeof(int) + 2);
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
