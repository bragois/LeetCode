class Solution {
public:
    bool inRange(int low, int high, int value){
        return (value >= low) && ( value <= high);
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int pos = 0;
        if(inRange(1,100,digits.size())){
            pos = digits.size() - 1;
            if(inRange(0, 9, digits[pos])){
                while((digits[pos] + 1) > 9){
                    if(pos == 0){
                        vector<int> digits_copy(digits.size() + 1, 0);
                        digits_copy[0] = 1;
                        return digits_copy;
                    }
                    else{
                        digits[pos] = 0;
                        pos--;
                    }
                }
                digits[pos]++;
            }
        }

        return digits;           
    }
};