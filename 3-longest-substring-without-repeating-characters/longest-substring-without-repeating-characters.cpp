class Solution {
public:

    /*
    Method to determine the logest substring without repeating characters,
    using the sliding window approach. The initial position of the right 
    index (startIdx) will be at the begining of the string. The left frame 
    (endIdx) will be positioned by checking 
    */
    int lengthOfLongestSubstring(string s) {
        map<char, int> chMap;
        int max_length = 0;
        int current_length = 0;
        unsigned int startIdx = 0;
        unsigned int endIdx = 0;
        unsigned int oldStartIdx = 0;

        if(s.empty() == true){
            return 0;
        }

        while(endIdx < s.length()){
            if(chMap.find(s[endIdx]) != chMap.end()){
                if((endIdx - startIdx) > max_length){
                    max_length = (endIdx - startIdx);
                }
                oldStartIdx = startIdx;
                //move to the next position 
                startIdx = chMap[s[endIdx]] + 1;
                /* 
                remove everything that was processed 
                before meeting a repeating character
                */
                while(oldStartIdx < startIdx){
                    chMap.erase(s[oldStartIdx++]);
                }
                chMap.insert(make_pair(s[endIdx],endIdx));
            }
            else{
                chMap.insert(make_pair(s[endIdx],endIdx));
            }
            endIdx++;
        }
        
        if((endIdx - startIdx) > max_length){
            max_length = (endIdx - startIdx);
        }
        return max_length;
    }
};