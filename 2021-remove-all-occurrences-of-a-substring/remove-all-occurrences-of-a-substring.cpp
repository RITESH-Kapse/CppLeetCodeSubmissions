class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.find(part) != string::npos){

            //IF string is find then only we are inside the loop
            //so erase the part from string

            s.erase(s.find(part), part.length());

        }

        return s;
        
    }
};