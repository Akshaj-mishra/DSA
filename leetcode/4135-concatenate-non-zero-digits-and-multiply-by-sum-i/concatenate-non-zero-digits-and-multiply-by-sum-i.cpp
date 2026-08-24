class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> abc;
        while(n>0){
            int num = n%10;

            if (num > 0){
                n = n/10;
                abc.push_back(num);
            }else {
                n = n/10;
            }
        }

        long long x = 0;
        long long sum = 0;
        for (int i = abc.size() - 1; i >= 0; i--) {
            x = (x * 10) + abc[i];
            sum += abc[i];
        }

        return x * sum;
    }
};