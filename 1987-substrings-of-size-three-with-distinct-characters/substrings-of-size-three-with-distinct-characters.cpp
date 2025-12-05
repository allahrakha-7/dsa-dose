class Solution {
public:
    int countGoodSubstrings(string s) {
        // base case
        if (s.size() < 3) return 0;

        int length = 0;
        
        // hashmap to store characters
        unordered_map<char, int> freq_count;

        for (int i = 0; i < 3; i++) {

            freq_count[s[i]]++;

        }

        if (freq_count.size() == 3) {

            length++;

        }

        for (int i = 3; i < s.size(); i++) {

            freq_count[s[i - 3]]--;

            if (freq_count[s[i - 3]] == 0) {

                freq_count.erase(s[i - 3]);
            }

            freq_count[s[i]]++;

            if (freq_count.size() == 3) {

                length++;
                
            }
        }
        return length;
    }
};