class Solution {
public:
    int romanToInt(string s) {
        int lastValue = INT_MAX;
        int convertedNum = 0;
        std::map<char, int> map = {{'M', 1000}, 
                                     {'D', 500}, 
                                     {'C', 100},
                                     {'L', 50},
                                     {'X', 10},
                                     {'V', 5},
                                     {'I', 1}};
        for(int i = 0 ;i < s.size(); ++i){
            char map_key = s[i];
            convertedNum += map[map_key];
            /* Check if the last character is smaller than the current one */
            if(lastValue < map[map_key]){
                /* 
                * If it is smaller, we need to adjust the current number 
                * by substracting the lastValue( that was mistakenly added 
                * to the number) 
                */
                convertedNum = convertedNum - lastValue - lastValue;
            }
            
            lastValue = map[map_key];
        }
        return convertedNum;
    }
};