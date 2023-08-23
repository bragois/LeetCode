class Solution {
public:
    bool inRange(double low, double high, int val){
        return (val < low || val > high);
    }

    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = 0;
        int med = 0;
        if((inRange(1,pow(10,4),nums.size()) != 0)
           || (inRange((-1)*pow(10,4),pow(10,4),target) != 0)){
            return 0;
        }
        right = nums.size() - 1;
        if(target > nums[right]){
            return right + 1;
        }
        if(target < nums[left]){ 
            return left;
        }
        while(left <= right){
            med = left + ((right - left) >> 1);
            
            if(target <= nums[med]){
                right = med - 1;
            }
            else{
                left = med + 1;
            }    
        }
        return left;
    }
};