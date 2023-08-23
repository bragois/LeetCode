class Solution {
public:
    bool inRange(int lowValue, int highValue, int num){
        return ((num >= lowValue) && (num <= highValue)); 
    }
    int removeElement(vector<int>& nums, int val) {
        bool found = false;
        int pos = 0;
        if((nums.empty() == 0)
            && inRange(0,100,nums.size())
            && inRange(0, 50, val)){
            for(int i = 0; i < nums.size(); ++i){
                if(inRange(0, 50, nums[i])){
                    if(nums[i] != val){
                        nums[pos] = nums[i];
                        pos++;
                    }
                }
            }
            return pos;
        }
        else {
            return nums.size();
        }
    }
};