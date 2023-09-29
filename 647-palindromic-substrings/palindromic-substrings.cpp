class Solution {
public:

    int expand(string s, int i, int j){

        int count =0;// lets count if there are palindrome subs

        while(i>=0 && j<s.length() && s[i]==s[j]){

            count++; // if both are same , then count ++;

            // here we are moving both directions to right nd left side [from ceneter ]everytime if matched.
            i--; 
            j++; 
        }

        return count;
    }

    int countSubstrings(string s) {
        
        int totalcount=0;

        for(int center=0; center <s.length(); center++){

            //Lets assume we are counting ODD substrings from string
            //in this case use 2 pointers from same position.[i and j at one place]

            int oddsubs = expand(s, center, center); //here i and j both at same plac

            //Lets assume we are counting Even substrings from string
            int evensubs = expand(s, center, center+1); // here for even substrings , i and j and +1 positions

            totalcount = totalcount + oddsubs + evensubs;
        }

        return totalcount;

    }
};