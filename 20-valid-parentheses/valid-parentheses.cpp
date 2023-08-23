class Solution {
public:
    bool isValid(string s) {
        map <char, int> validCharsMap = {{'(', 1},{')', -1},
                                         {'[', 2},{']', -2},
                                         {'{', 3},{'}', -3}};
        stack<int> stack;
            
        for(int i = 0; i < s.length(); i++){
            // Only put on the stack {, ( or [ ;
            if(validCharsMap[s[i]] > 0){
                stack.push(validCharsMap[s[i]]);
            }
            else if(stack.empty() == false){
                // Check if the current char is not }, ) or ]
                if (validCharsMap[s[i]] + stack.top() == 0) {
                    stack.pop();  
                }
                else{
                    return false;
                }
            }
            else {
                return false;
            }
            
        }
            
        return stack.empty();
    }
};