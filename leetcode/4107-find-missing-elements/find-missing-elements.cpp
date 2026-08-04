class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> abc;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1] + 1) {
                for (int j = nums[i-1] + 1; j < nums[i]; j++) {
                    abc.push_back(j);
                }
            }
        }

        return abc;
    }
};