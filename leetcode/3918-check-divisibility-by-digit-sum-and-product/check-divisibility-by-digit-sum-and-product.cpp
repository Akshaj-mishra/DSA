class Solution {
public:
    bool checkDivisibility(int n) {
        int v = n;
        int sum = 0;
        int product = 1;
        while(v > 0){
            int temp = v%10;
            sum += temp;
            product = product * temp;

            v = v/10;
        }
        if (n%(product + sum) == 0){
            return true;
        }
        return false;
    }
};