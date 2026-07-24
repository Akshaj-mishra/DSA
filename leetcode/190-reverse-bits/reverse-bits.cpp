class Solution {
public:
    int reverseBits(int n) {
        string s = "";

        for (int i = 0; i < 32; i++) {
            s += (n % 2) + '0';
            n /= 2;
        }

        uint32_t ans = 0;
        for (char c : s) {
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }
};