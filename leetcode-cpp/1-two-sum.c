#include <stdlib.h>

//hash node
typedef struct Node{
    int key;//the number
    int value;//index
    struct Node* next;//prevent conflict
} Node;

//hash function
int hash(int key, int size){
    int h = key % size;
    return h < 0 ? h + size : h;//no negative
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //tablesize
    int tablesize = numsSize * 2;
    //create an array
    Node** table = (Node**)calloc(tablesize, sizeof(Node*));

    //traverse whole nums
    for (int i = 0; i < numsSize; i++)
    {
        //need
        int need = target - nums[i];
        int h = hash(need, tablesize);//compute the bucket index for 

        //在哈希表中查找need
        Node* cur = table[h];
    }
    

}


