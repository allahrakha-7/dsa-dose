class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // base case
        if (strs.empty()) return "";

        int n = strs.size();

        // sorting string array
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[n - 1];

        string commonPrefix = "";

        for (int i = 0; i < min(first.size(), last.size()); i++) {

            if (first[i] != last[i]) {

                return commonPrefix;

            } else {

                commonPrefix += first[i];

            }
        }
        return commonPrefix;
    }
};