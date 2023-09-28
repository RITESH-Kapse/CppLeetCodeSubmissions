class Solution {
public:

    bool checkPalin(string s, int i, int j){

        while(i<=j){

            if(s[i]!= s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }

        return true;
    }


    bool validPalindrome(string s){

        int i=0;
        int j= s.length()-1;

        while(i<j){

            if(s[i]==s[j]){

                i++;
                j--;
            }else{

                //equal nai hai
                //1 removal allowed

                //konsa decide karenge ?
                // remove both 1 by 1 and see remaining string is palindrome
                // jo side wala remove karke baki ka palindrome aaya to true
                // warna false == Use OR Operation -
                //koi b ek 1 aaya to overall answer 1

                //remove ith char
                bool ans1 = checkPalin(s, i+1, j);

                //remove jth char
                bool ans2 = checkPalin(s, i, j-1);

                return ans1 || ans2;   // koi b 1 raha to op 1 jaega             
            }
        }

        //yaha aagae matlab string palindrome hai 
        //hence 0 removal

        return true;

        
    }
};