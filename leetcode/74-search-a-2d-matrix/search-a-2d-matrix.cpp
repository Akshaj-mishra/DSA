class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // if (n == 0 || )

        int l = 0;
        int h = (m*n)-1;

        while (l <= h){
            int mid = l+(h-l)/2;

            int k = mid/n;
            int g = mid%n;
            
            if (matrix[k][g] == target){
                return true;
            }else if (matrix[k][g] > target){
                h = mid-1;
            }else {
                l = mid+1;
            }
        }

        return false;
    }
};