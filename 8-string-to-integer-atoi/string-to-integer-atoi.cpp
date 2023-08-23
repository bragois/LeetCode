#include <iostream>

using namespace std;

class Solution {
private:
    bool inRange(char low, char high, char value){
        return ((value >= low) && (value <= high));
    }

    bool checkInput(string s){
        for(int idx = 0; idx < s.length() - 1; idx++){
            if((inRange('0', '9', s[idx]) == false)
               && (inRange('a', 'z', s[idx]) == false)
               && (inRange('A', 'Z', s[idx]) == false)
               && (s[idx] != '-') 
               && (s[idx] != '+')
               && (s[idx] != '.')
               && (s[idx] != ' ')){
                    return false;
                }
        }
        return true;
    }
    
    bool checkOverflow(int a, int b){
        bool ovflag = false;
        
        if((a > (INT32_MAX / 10)) || (a * 10) > INT32_MAX - abs(b)){
            cout << a << " " << b << endl;
            ovflag = true;
        }
        return ovflag;
    }
    
    void correctSigness(int& result, int pos, bool ovflag){
        if(ovflag == true){
            result = (pos == true) ? INT32_MAX: INT32_MIN;
        }
        else{
            result = (pos == true) ?((int)result) : ((int) -1 * result);
        }
    }
    
public:    
    int myAtoi(string s) {
        int idx = 0;
        int result = 0;
        bool pos = true;
        bool ovflag = false;
    
        if(checkInput(s) == false){
            return 0;
        }
        //read leading whitespaces;
        while(s[idx] == ' '){
            idx++;
        }
        //read '-' or '+'
        if((idx < s.length())
              && ((s[idx] == '-') || (s[idx] == '+'))) {
            //save result signess
            pos = (s[idx] == '-') ? false : true;
            idx++;
        }
        //read digits
        while(idx < s.length() && (inRange('0', '9', s[idx]) == true)){
            ovflag = checkOverflow(result, s[idx] - '0');
            if(ovflag != true){
                result = result * 10 + (s[idx] - '0');
                idx++;
            }
            else{
                //overflow encountered
                break;
            }
        }
        correctSigness(result, pos, ovflag);
        return result;
    }
};