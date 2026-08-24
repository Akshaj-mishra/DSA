class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> damm;

        for (int i = 0; i<word.size(); i++){
            damm[word[i]]++;
        }

        vector<int> val;

        for (auto pair : damm){
            val.push_back(pair.second);
        }
        
        sort(val.rbegin(), val.rend());
        
        int ans = 0;

        for(int i = 0 ; i < val.size(); i++){
            ans += ((i/8) + 1) * val[i];
        }

        return ans;
    }
};