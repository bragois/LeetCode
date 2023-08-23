// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    
public:
    int firstBadVersion(unsigned int n) {
        long int left, right, mid;
        left = 1;
        right = n;
        while(left < right){
            mid = ( left + right ) / 2;
            if(isBadVersion(mid) == true){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};