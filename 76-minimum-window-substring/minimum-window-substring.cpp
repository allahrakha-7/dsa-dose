class Solution {
public:
    string minWindow(string s, string t) {

        // base case
        if (t.empty() || s.empty()) {

            return "";

        }

        unordered_map<char, int> countT;

        for (char c : t) {

            countT[c]++;

        }

        int have = 0;
        int need = countT.size();

        unordered_map<char, int> window;
        
        int left = 0;

        int startIndex = -1;
        int minLength = INT_MAX;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {

                have++;

            }
            while (have == need) {

                int currentLength = right - left + 1;

                if (currentLength < minLength) {

                    minLength = currentLength;

                    startIndex = left;

                }
                char removeChar = s[left];

                window[removeChar]--;

                if (countT.count(removeChar) && window[removeChar] < countT[removeChar]) {

                    have--;

                }
                left++;
            }
        }

        if (minLength == INT_MAX) {

            return "";

        } else {

            return s.substr(startIndex, minLength);
        }
    }
};