using namespace std;
class Solution {
public:
    // Returns true if x is in range [low..high], else false
    bool inRange(int low, int high, int x)
    {
        return ((x-high)*(x-low) <= 0);
    }
    
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        int pivot = 0;
        if((nums.empty() == 0) && 
           inRange( 0, (3*pow(10,4)), nums.size())){
            pivot = nums[pos];
            for(int i = 1; i < nums.size(); ++i){
                if(pivot != nums[i]){
                    pos++;
                    nums[pos] = nums[i];
                    pivot = nums[i];
                }
            }
            return (pos + 1);
        }
        return 0;
    }
};