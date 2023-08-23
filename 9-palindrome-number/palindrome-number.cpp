class Solution {
public:
    bool isPalindrome(int x) {
        int reverted_x = 0;
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        while(x > reverted_x ){
            reverted_x = reverted_x * 10 + x % 10;
            x /= 10;
        }
        return (x == reverted_x || (x == reverted_x / 10));
    }
};