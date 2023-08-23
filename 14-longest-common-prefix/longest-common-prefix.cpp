class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        if(strs.size() == 0 || strs.size() > 200){
            return "";
        }
        for(int i = 0; i < strs[0].length(); ++i){
            for(int j = 1; j < strs.size(); ++j){
                if ( i == strs[j].length() ||
                    strs[j][i] != strs[0][i]){
                    return string(strs[0], 0, i);
                }
            }
        }
        return strs[0];
    };
};