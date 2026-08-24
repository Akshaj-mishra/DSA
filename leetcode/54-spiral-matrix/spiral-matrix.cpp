class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();

        while (top < bottom && left < right){
            for (int i = left; i<right; i++){
                ans.push_back(matrix[top][i]);
            }
            top ++;

            for (int j = top; j < bottom; j++) {
                ans.push_back(matrix[j][right-1]);
            }
            right--;

            if (top >= bottom || left >= right) {
                break;
            }

            for(int k = right-1; k>=left; k--){
                ans.push_back(matrix[bottom-1][k]);
            }
            bottom--;

            for (int l = bottom-1; l>=top; l--){
                ans.push_back(matrix[l][left]);
            }
            left ++;
        }
        return ans;
    }
};