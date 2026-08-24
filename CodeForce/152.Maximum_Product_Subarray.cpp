#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = nums[0];// why not 0
        int maximum = nums[0];// why not INT_MINIMUM
        int minimum = nums[0];// why not INY_MAXIMUN

        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) {
                swap(maximum, minimum);
            }


            maximum = max(nums[i], maximum * nums[i]);
            minimum = min(nums[i], minimum * nums[i]);
            
            ans = max(ans, maximum);
        }

        return ans;
    }
};

int main(){
    Solution sh;
    int n;
    vector<int> nums = {2,3,-2,4};
    int ans = 6;
    int result = sh.maxProduct(nums);


    if (result == ans){
        cout<<"True"<<endl;
    }else if (result != ans){
        cout<<"False"<<endl;
    }


    vector<int> NUM = {-2,0,-1};
    ans = 0;
    result = sh.maxProduct(NUM);



    if (result == ans){
        cout<<"True"<<endl;
    }else if (result != ans){
        cout<<"False"<<endl;
    }
    

    return 0;
}