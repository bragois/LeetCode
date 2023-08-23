class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int idx = 0; idx < t.length(); idx++){
            if(s[idx] != t[idx]){
                return false;
            }
        }
        return true;
    }
};