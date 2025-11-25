class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // sort the given array nums
        sort(nums.begin(), nums.end());

        // initialization for closest sum
        int closestSum = nums[0] + nums[1] + nums[2];

        // loop through the given array
        for (int i = 0; i < nums.size() - 2; i++) {

            // initialize two pointers
            int left = i + 1;
            int right = nums.size() - 1;

            // loop through by pointers
            while (left < right) {

                // for current sum
                int currentSum = nums[i] + nums[left] + nums[right];

                // if current sum is less than the old sum
                if (abs(target - currentSum) < abs(target - closestSum)) {

                    closestSum = currentSum;

                }

                if (currentSum < target) {

                    left++;

                } else if (currentSum > target) {

                    right--;

                } else {

                    return currentSum;
                }
            }
        }
        return closestSum;
    }
};