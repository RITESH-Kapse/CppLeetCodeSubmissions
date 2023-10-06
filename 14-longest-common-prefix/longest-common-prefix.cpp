class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans; // to store ans
        int i=0; // for going to each letter from words in sentence

        while(true){

            char curr_char = 0; // to compare current char with others char

            for(auto str:strs){ // for loop with another approach

                //first check outof bound
                if(i >= str.size()){ // agar i > size that means koi ek word khatam hua
                    curr_char=0;
                    break;
                }

                //just started
                if(curr_char == 0){ // agar empty hai to first letter as curr str
                    curr_char = str[i];
                }else if(str[i] != curr_char){ //agar next wala same nai aarha hai to break
                    curr_char = 0;
                    break;
                }
            }

            if(curr_char==0){ // ek bhi same nai aaya to break
                break;
            }

            ans.push_back(curr_char); //jitne same hai add to ans
            i++; // next char in word pe jao 
        }

        return ans;


        
        
    }
};