class Solution {
public:

    unordered_map<int,int> tmks;

    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;

        if (tmks.count(n)) return tmks[n]; 

        return tmks[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};