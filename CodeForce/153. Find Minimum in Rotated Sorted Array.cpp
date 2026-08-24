#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() -1;

        int minimum = nums[0];
        while (left<right){
            int mid = (left + right)/2;

            if (nums[mid] > nums[left]){
                left = mid+1;
            }else if(nums[mid]<= nums[left]){
                right = mid-1;
            }

            minimum = min(minimum,nums[mid]);


        }
        

        return minimum;
        
    }
};

int main(){
    Solution sh;
    int n;
    vector<int> nums = {3,4,5,1,2};
    int ans = 1;
    int result = sh.findMin(nums);
    cout<<result<<endl;

    if (result == ans){
        cout<<"True"<<endl;
    }else if (result != ans){
        cout<<"False"<<endl;
    }


    vector<int> NUM = {4,5,6,7,0,1,2};
    ans = 0;
    result = sh.findMin(NUM);
    cout<<result<<endl;


    if (result == ans){
        cout<<"True"<<endl;
    }else if (result != ans){
        cout<<"False"<<endl;
    }
    
    vector<int> Nom = {3,1,2};
    ans = 1;
    result = sh.findMin(Nom);
    cout<<result<<endl;


    if (result == ans){
        cout<<"True"<<endl;
    }else if (result != ans){
        cout<<"False"<<endl;
    }
    return 0;
}