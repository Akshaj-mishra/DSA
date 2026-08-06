class Solution {
public:
    int sumo(int n){
        int sum = 1;
        while(n>0){
            sum *= n%10;
            n = n/10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        while (true){
            int res = sumo(n);

            if (res%t == 0){
                return n;
            }

            n++;
        }

        return -1;
    }
};