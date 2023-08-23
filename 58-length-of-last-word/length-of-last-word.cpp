class Solution {
public:
    bool inRange(int low, int high, int value){
        return (value >= low && value <= high);
    }
    int lengthOfLastWord(string s) {
        int count = 0;
        int end = 0;
        if(s.length() == 1){
            return 1;
        }
        if( inRange(1, pow(10,4), s.length())){
            end = s.length() - 1;
            //Ignore trailing spaces
            while((end >= 0) && (s[end] == ' ')){
                end--;
            }
            while((end >= 0) && (s[end] != ' ')){
                count++;
                end--;
            }
        }

        return count;
    }
};