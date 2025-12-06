class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        
        vector<int> decrypted_code(n, 0);
        
        if (k == 0) return decrypted_code;

        for (int i = 0; i < n; i++) {

            int currentSum = 0;

            if (k > 0) {

                for (int j = 1; j <= k; j++) {

                    int index = (i + j) % n;

                    currentSum += code[index];

                }
            
            } else {

                for (int j = 1; j <= abs(k); j++) {

                    int index = (i - j + n) % n;

                    currentSum += code[index];

                }
            }
            decrypted_code[i] = currentSum;
        }
        return decrypted_code;
    }
};