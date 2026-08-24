class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> pref;
        pref.reserve(nums.size());

        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            pref.push_back(gcd(x, mx));
        }

        sort(pref.begin(), pref.end());

        long long ans = 0;
        int l = 0, r = pref.size() - 1;

        while (l < r) {
            ans += gcd(pref[l], pref[r]);
            l++;
            r--;
        }

        return ans;
    }
};