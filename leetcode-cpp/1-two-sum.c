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
                int*
            }
            
        }
        
    }
    
}
