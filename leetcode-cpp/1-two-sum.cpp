#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create hash map
        unordered_map <int,int> mp;
        //traverse.
        for (int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            //get answer
            if (mp.count(need))
            {
                return {mp[need], i};
            }
            //put current nums and its index into hash map;
            mp[nums[i]] = i;
        }
        return {};
    }
};