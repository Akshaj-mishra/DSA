class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort (nums.begin(), nums.end());

        int n = nums.size();

        int sum = nums[n - 1] * nums[n - 2] * nums[n - 3];

        int minimum = nums[0]*nums[1]*nums[2];

        int non_neg = nums[0]*nums[1]*nums[n-1];

        int maximum = max(sum,minimum);



        return max(non_neg , maximum);
    }
};