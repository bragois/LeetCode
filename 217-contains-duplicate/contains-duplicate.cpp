class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(auto n : nums){
            if(mp.find(n) == mp.end()){
                mp.insert(make_pair(n, 1));
            }
            else{
                return true;
            }
        }
        return false;
    }
};