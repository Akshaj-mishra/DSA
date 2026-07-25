class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;

        while (n>0){
            int res = n%10;

            ans.push_back(res);

            n = n/10;
        }

        sort(ans.begin(),ans.end());

        int prod = ans[ans.size()-2] * ans[ans.size()-1];
        return prod;
    }
};