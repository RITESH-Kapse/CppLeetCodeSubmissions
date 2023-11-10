class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.find(part) != string::npos){

            //string::npos --> matlab pure string me ye "part" found ho gaya
            // nai find hota to 'npos' matlab no position return karta.

            //IF string is find then only we are inside the loop
            //so erase the part from string

            s.erase(s.find(part), part.length());

        }

        return s;
        
    }
};