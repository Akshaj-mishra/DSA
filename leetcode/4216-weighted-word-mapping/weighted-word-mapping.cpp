class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int mod = sum % 26;
            char mapped = 'z' - mod;

            ans += mapped;
        }

        return ans;
    }
};