class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        if(s.length() != t.length()){
            return false;
        }
        for(int idx = 0; idx < s.length(); idx++){
            if(mp.find(s[idx]) == mp.end()){
                mp.insert(make_pair(s[idx], 1));
            }
            else{
                mp[s[idx]]++;
            }
        }

        for(int idx = 0; idx < t.length(); idx++){
            if(mp.find(t[idx]) == mp.end()){
                return false;
            }
            else{
                mp[t[idx]]--;
                if(mp[t[idx]] == 0){
                    mp.erase(t[idx]);
                }
            }
        }
        return (mp.empty());
    }
};