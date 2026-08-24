class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ma = -1;
        int cou = count(s.begin(), s.end(), '1');
        int next = 0;
        int prev = 0;
        bool possible = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                next++;
            } else {
                
                if (i + 1 == s.size() || s[i + 1] == '0') {
                    ma = max(ma, prev + next);

                    int start = i;
                    while (start >= 0 && s[start] == '1'){
                        start--;
                    }
                        
                    if (start >= 0 && i + 1 < s.size() &&
                        s[start] == '0' && s[i + 1] == '0') {
                        possible = true;
                    }

                    prev = next;
                    next = 0;
                }
            }
        }

        ma = max(ma, prev + next);

        if (!possible){
            return cou;
        }
            

        return cou + ma;
    }
};