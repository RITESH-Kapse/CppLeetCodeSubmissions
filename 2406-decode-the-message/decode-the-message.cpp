class Solution {
public:
    string decodeMessage(string key, string message) {

        //2 step process
        //1. create mapping -- using key inputs
        //2. use mapping - for solution in string message

        //1. create mapping 
        char start='a';
        char mapping[280] ={0} ; // as char is 1 byte - 8 bits - that is 2^8 combinations.

        for(auto i:key){ // this is same as normal for loop [ its for each loop] - shortcut of for loop

            if(i!=' ' && mapping[i]==0){ //inp madhe blank nai and mapping madhe i number la 0 nai tewa - do this

                mapping[i] = start; //
                start++; //ethe start is 'a' hence start++ is 'a'+1 = 'b'

            }
        } 

        //Use mapping - on ip message
        string ans; // to store the converted ans

        for(auto i:message){

            if(i==' '){// jar inp madhe empty asel tar convereted madhe empty send kara
                ans.push_back(' ');

            }else{

                char decodedChar = mapping[i]; // maping madhe check kara what is 'i'th value of inp key
                ans.push_back(decodedChar);

            }
        }

        return ans;

    }
};