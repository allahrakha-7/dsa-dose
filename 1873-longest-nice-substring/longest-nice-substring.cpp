class Solution {
public:
    string longestNiceSubstring(string s) {
        
        // base case
        if (s.size() < 2) return "";

        unordered_set<char> charSet;

        for (int c : s) {

            charSet.insert(c);

        }
        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (charSet.find(toupper(c)) == charSet.end() || charSet.find(tolower(c)) == charSet.end()) {

                string leftPart = longestNiceSubstring(s.substr(0, i));

                string rightPart = longestNiceSubstring(s.substr(i + 1));

                if (leftPart.size() >= rightPart.size()) {

                    return leftPart;

                } else {

                    return rightPart;

                }
            }
        }
        return s;
    }
};