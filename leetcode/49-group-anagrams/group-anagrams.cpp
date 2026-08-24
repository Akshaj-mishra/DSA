class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs){
            string res = s;
            sort(res.begin(),res.end());
            mp[res].push_back(s);
        }

        vector<vector<string>> ans;

        for (const auto& [key,map]: mp ){
            ans.push_back(map);
        }

        return ans;
    }
};