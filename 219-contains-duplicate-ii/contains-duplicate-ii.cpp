class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // base case
        if (nums.size() <= 1) {
            return false;
        }

        unordered_map <int, int> seen_indices;

        for (int i = 0; i < nums.size(); i++) {

            int currentNumber = nums[i];

            if (seen_indices.count(currentNumber)) {

               int oldIndex = seen_indices[currentNumber];

               if (i - oldIndex <= k) {
                
                    return true;

               }
            }
            seen_indices[currentNumber] = i;
        }
        return false;
    }
};