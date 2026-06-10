class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        for (int i =0; i<nums.size(); i++){
            if (nums[i] == 1){
                temp ++;
                ans = max(ans,temp);
            } else {
                temp = 0;
            }
        }
        return ans;
    }
};