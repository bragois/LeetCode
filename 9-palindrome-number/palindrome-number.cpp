class Solution {
public:
    bool isPalindrome(int x) {
        int reversed_x = 0;
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        while(x > reversed_x ){
            reversed_x = reversed_x * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed_x || (x == reversed_x / 10));
    }
};