class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        // base case
        if (s.size() < 10 || s.empty()) return {};

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i <= s.size() - 10; i++) {

            string DNASequence = s.substr(i, 10);
            
            if (seen.find(DNASequence) != seen.end()) {

                repeated.insert(DNASequence);

            } else {

                seen.insert(DNASequence);

            }
        }
        vector<string> answer;

        for (auto& str : repeated) {

            answer.push_back(str);

        }
        return answer;
    }
};