class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        long long org = x;
        long long rev = 0; 
        while (org != 0) { 
            rev = rev * 10 + org % 10; 
            org = org / 10; 
        }
        return x == rev ;
    }
};