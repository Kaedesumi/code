#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	int val;
	struct Node* next;
} Node;

typedef struct {
	int size;
	Node** buckets;
} HashMap;

static int hash_func(HashMap* map, int key) {
	long k = key;
	if (k < 0) k = -k;
	return (int)(k % map->size);
}

static HashMap* create_map(int size) {
	HashMap* m = (HashMap*)malloc(sizeof(HashMap));
	m->size = size;
	m->buckets = (Node**)calloc(size, sizeof(Node*));
	return m;
}

static void map_put(HashMap* m, int key, int val) {
	int idx = hash_func(m, key);
	Node* cur = m->buckets[idx];
	while (cur) {
		if (cur->key == key) { cur->val = val; return; }
		cur = cur->next;
	}
	Node* n = (Node*)malloc(sizeof(Node));
	n->key = key; n->val = val; n->next = m->buckets[idx];
	m->buckets[idx] = n;
}

static int map_get(HashMap* m, int key, int* found) {
	int idx = hash_func(m, key);
	Node* cur = m->buckets[idx];
	while (cur) {
		if (cur->key == key) { *found = 1; return cur->val; }
		cur = cur->next;
	}
	*found = 0;
	return 0;
}

static void free_map(HashMap* m) {
	for (int i = 0; i < m->size; ++i) {
		Node* cur = m->buckets[i];
		while (cur) {
			Node* t = cur;
			cur = cur->next;
			free(t);
		}
	}
	free(m->buckets);
	free(m);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int cap = numsSize * 2 + 1;
	HashMap* m = create_map(cap);
	int* res = (int*)malloc(2 * sizeof(int));
	*returnSize = 0;
	for (int i = 0; i < numsSize; ++i) {
		int complement = target - nums[i];
		int found = 0;
		int idx = map_get(m, complement, &found);
		if (found) {
			res[0] = idx;
			res[1] = i;
			*returnSize = 2;
			free_map(m);
			return res;
		}
		map_put(m, nums[i], i);
	}
	free_map(m);
	// According to problem statement there is always exactly one solution.
	free(res);
	*returnSize = 0;
	return NULL;
}

int main(void) {
	int nums[] = {2, 7, 11, 15};
	int target = 9;
	int returnSize = 0;
	int* ans = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);
	if (ans && returnSize == 2) {
		printf("[%d,%d]\n", ans[0], ans[1]);
		free(ans);
	} else {
		printf("No solution\n");
	}
	return 0;
}