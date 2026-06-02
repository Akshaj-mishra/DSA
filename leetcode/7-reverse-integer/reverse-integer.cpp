#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while (x != 0){
            int rev = x % 10;
            if (y > INT_MAX / 10 || (y == INT_MAX / 10 && rev > 7)) return 0;
            if (y < INT_MIN / 10 || (y == INT_MIN / 10 && rev < -8)) return 0;
            y = y*10 + rev;
            x = x/10;
        }
        return y;
    }
};