class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>arr;
        for(int i =0;i<nums.size();i++){
            if (arr.count(nums[i])){
                return true;
            }

            arr[nums[i]] ++;
        }

        return false;
    }
};