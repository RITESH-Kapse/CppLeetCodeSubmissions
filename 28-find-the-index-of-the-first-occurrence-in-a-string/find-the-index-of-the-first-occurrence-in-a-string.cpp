class Solution {
public:
    int strStr(string haystack, string needle) {

        //we will perform sliding window method
        int n = haystack.size(); //9 
        int m = needle.size(); //3

        for(int i=0; i<=n-m; i++){

            for(int j=0 ; j<m; j++){

                //check string and substring
                if(needle[j] != haystack[i+j]){

                    break ;
                }


                //agar sub string mile matlab we have travelled complete needle length and its match
                if(j == m-1){
                    return i;

                }
            }
        }

        return -1;
        
    }
};