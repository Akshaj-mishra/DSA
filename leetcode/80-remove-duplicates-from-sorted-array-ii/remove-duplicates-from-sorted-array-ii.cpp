class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 2){
            return 2;
        }

        if (nums.size() == 1){
            return 1;
        }

        int s = 2;

        for (int i = 2; i<nums.size(); i++){
            if (nums[i] != nums[s-2]){
                nums[s] = nums[i];
                s++;
            }
        }

        return s;
    }
};