#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create unordered_map
        unordered_map<int,int> mp;

        //traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            
        int need = target - nums[i];

        //if need exist in unordered_map
        if (mp.count(need))
        {
            return {mp[need], i};
        }
        
        //put the current number and its index into hash map
        mp[nums[i]] = i;

        }
        return {};
    }
};