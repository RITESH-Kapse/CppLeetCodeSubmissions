class Solution {
public:

    int myAtoi(string s) {

        int num = 0; int i=0, sign=1; //+ve

        while(s[i] == ' '){
            i++;
        }

        if(i< s.size() && (s[i] == '-' || s[i] == '+')){

            //agar s[i] == + then sign = 1 else sign = 0 

            sign = s[i] == '+' ? 1 : -1 ;
            i++;
        }

        while(i<s.size() && isdigit(s[i])){

            //to handle the  32-bit signed integer range [-231, 231 - 1]
            if(num > INT_MAX/10 || (num ==INT_MAX/10 && s[i] > '7' )){
                return sign == -1 ? INT_MIN:INT_MAX;
            }
            
            num = num * 10 + (s[i] - '0'); 
            i++;

        }

        //agar Positive or negative number hai to sign se multiply
        return num * sign;

        /*
        //with atoi function
        int integer = atoi(s.c_str());
        return integer;
        */
        
    }
};