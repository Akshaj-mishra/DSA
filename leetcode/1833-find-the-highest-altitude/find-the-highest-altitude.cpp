class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int hight =0;
        for (int i =0; i< gain.size(); i++){
            sum = sum + gain[i];
            hight = max(hight,sum);
        }
        return hight;
    }
};