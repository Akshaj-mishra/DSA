class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;
        if (freq.count(1)) {
            int f = freq[1];
            if (f % 2 == 0) f--; 
            ans = max(ans, f);
        }

        for (auto &[x, f] : freq) {
            if (x == 1) continue;

            long long curr = x;
            int length = 0;
            while (true) {
                auto it = freq.find(curr);
                if (it == freq.end()) {
                    length -= 1; 
                    break;
                }
                
                if (it->second >= 2) {
                    length += 2;
                    curr = curr * curr;
                    if (curr > 1e9) {
                        if (freq.count(curr)) length += 1;
                        else length -= 1;
                        break;
                    }
                } else {
                    length += 1;
                    break;
                }
            }

            ans = max(ans, length);
        }

        return ans;
    }
};