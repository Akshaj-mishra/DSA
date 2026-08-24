class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() -1;

        int minimum = nums[0];
        while (left<right){
            int mid = (left + right)/2;

            if (nums[mid] >= nums[left]){
                left = mid+1;
            }else{
                right = mid;
            }

            minimum = min(minimum,nums[left]);
        }
        

        return minimum;
        
    }
};