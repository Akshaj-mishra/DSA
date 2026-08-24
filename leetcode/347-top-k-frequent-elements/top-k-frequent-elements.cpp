class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> abc;
        vector<int> ans;

        for (int num : nums) {
            abc[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (abc[a] != abc[b]) {
                return abc[a] > abc[b];
            }
            return a < b;
        });

        for (int i = 0; i < nums.size() && ans.size() < k; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};