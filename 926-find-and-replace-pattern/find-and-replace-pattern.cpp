class Solution {
public:


    //this fun normalized alll how words and patterns into similiar format
    //so that we can compare them and find solution

    void createMapping(string& str){

        //find if already mapped
        char start ='a';
        char mapping[300]={0}; //char array to map inputs wrt 'a' - anything greater than 256[2^8] will work

        for(auto ch:str){

            if(mapping[ch]==0){ //agar ch from string ka mapping nahi hua hai
                mapping[ch]= start; // to map kardo
                start ++;
            }
        }

        //update the string wrt mapping
        for(int i=0; i<str.length();i++){

            char ch = str[i]; // dekho ip ka char kya hai
            str[i] = mapping[ch] ; // wahi ip char ko mapping wale se replace kardo
            
        }
    }

    //this func defination[not complete fun] was already avaiable in code
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        //create a "STRING" vector to store ans
        vector<string> ans;
        
        //normalize the pattern
        createMapping(pattern);  // hum inp pattern and words dono ka mapping kar rahe hai

        //for ex:
        // pattern is qqr  and words are ["abc","deq","mee","aqq","dkd","ccc"] 
        // here pattern qqr is mapped to aab
        // then words are mapped to aab and hence both have same grounds to compare

        //for words
        for(string s: words){

            string tempString = s;

            //normalize karo ip string- islia purana store kia
            createMapping(tempString);

            if(tempString == pattern){//ip string and pattern is matched
                ans.push_back(s); // because s is original string and hence it should be pushed .
            }

        }
        
        return ans;
    }
};