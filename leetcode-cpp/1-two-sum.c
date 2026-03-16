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
    //
    Node** table = (Node**) 

}


