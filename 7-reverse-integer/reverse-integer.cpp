class Solution {
public:
    int reverse(int x) {
        int reversed_x = 0;
        while(x){
            // Check if reversed x will overflow INT_MAX or INT_MIN
            if ((reversed_x > INT_MAX / 10 ||  (reversed_x == INT_MAX / 10 && (x % 10 > 7)))
            ||  (reversed_x < INT_MIN / 10 ||
                (reversed_x == INT_MIN / 10 && (x % 10 < -8)))){
                return 0;
            }
            reversed_x = reversed_x * 10 + x % 10;
            x /= 10;
        }
        return reversed_x;
    }
};