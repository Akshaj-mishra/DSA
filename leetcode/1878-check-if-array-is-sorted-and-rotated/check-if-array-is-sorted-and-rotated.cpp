#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drop_count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                drop_count++;
            }
        }
        
        return drop_count <= 1;
    }
};