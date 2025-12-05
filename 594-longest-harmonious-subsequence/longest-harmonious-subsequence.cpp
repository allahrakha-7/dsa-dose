class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        // base case
        if (nums.empty()) return {};

        // map to count frequency of numbers
        unordered_map<int, int> freq_count;

        for (int num : nums) {

            freq_count[num]++;

        }
        
        // max length of longest harmonius sequence
        int maxLength = 0;

        for (auto& pair : freq_count) {

            int key = pair.first;
            int count = pair.second;

            if (freq_count.find(key + 1) != freq_count.end()) {

                int currentLength = count + freq_count[key + 1];

                maxLength = max(maxLength, currentLength);

            }
        }
        return maxLength;
    }
};