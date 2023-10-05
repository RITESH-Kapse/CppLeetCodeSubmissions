class Solution {
public:
    bool isAnagram(string s, string t) {


        //method 1 - sorting
        //'a' = 97 , b=98 
        // Time complexity - O(nlog(n)) - bcz of sorting

        // sort(s.begin(),s.end());

        // sort(t.begin(),t.end());

        // if(s==t){
        //     return true;
        // }else{
        //     return false;
        // }  


        //method 2 - counting
        // freq table of s shouuld be equal to freq table of t --


        //freq table for strings
        // strings ASCII - 256

        int freqTable[256]={0};

        for(int i=0;i<s.size();i++){
            freqTable[s[i]]++;
        }

        for(int i=0;i<t.size();i++){
            freqTable[t[i]]--;
        }

        for(int i=0;i<256;i++){

            if(freqTable[i] !=0){
                return false;
            }
        }

        return true;
    }
};