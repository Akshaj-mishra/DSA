class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> presum(n, 1);
        vector<int> postsum(n, 1);
        vector<int> ans(n);

        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; j--) {
            postsum[j] = postsum[j + 1] * nums[j + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = presum[i] * postsum[i];
        }

        return ans;
    }
};