class Solution {
public:
    bool isValid(string s) {
        stack <char> tcs;
        
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if (c == '(' || c == '{' || c == '['){
                tcs.push(c);
            }
            else if (c == ')' || c == '}' || c == ']'){

                if (tcs.empty()){
                    return false;
                }
                
                char top = tcs.top();

                if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                    tcs.pop();  
                }else {
                    return false;
                }
            }
        }

        return tcs.empty();
    }
};