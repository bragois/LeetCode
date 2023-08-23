class Solution {
public:
    bool inRange(int low, int high, int val){
        return (val >= low && val <= high);
    }
    int strStr(string haystack, string needle) {
        int j = 0;
        int i = 0;
        if(needle.length() == 0){
            return 0;
        }
        if(inRange(0, (5 * pow(10, 4)), haystack.length()) == false
           && inRange(0, (5 * pow(10, 4)), needle.length()) == false){
               return 0;
        }
        while( i < haystack.length()){
            if(haystack[i] == needle[j]){
                j++;
                if(j == needle.length()){
                    return (i - j + 1);
                }
            }
            else{
                i = (i - j);
                j = 0;
            }
            i++;
        }
        // needle not a part of haystack
        return -1;    
    }
};