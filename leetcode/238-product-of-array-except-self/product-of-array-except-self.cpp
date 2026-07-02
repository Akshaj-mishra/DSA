class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> presun(n,1);
        vector<int> postsun(n,1);
        vector<int> ans(n,1);


        for (int i = 1 ; i<n; i++){
            presun[i] = presun[i-1] * nums[i-1];
        }

        for (int j = n-2 ; j>=0; j--){
            postsun[j] = postsun[j+1] * nums[j+1];
        }

        for (int k = 0 ; k<n; k++){
            ans[k] = presun[k] * postsun[k];
        }


        return ans;
    }
};