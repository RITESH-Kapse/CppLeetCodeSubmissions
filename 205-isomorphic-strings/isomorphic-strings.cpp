class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int hash[256]= {0}; // mapping of each char of 's' to 't'
//         bool isTCharMapped[256] = {0} ;//stores if t[i] char already mapped with s[i]

//         for(int i=0;i<s.size();i++){

//             if(hash[s[i]]==0 && isTCharMapped[t[i]]==0){
//                 hash[s[i]] =t[i];
//                 isTCharMapped[t[i]]=true;
//             }
//         }


//         for(int i=0; i<s.size(); i++){

//             if(char(hash[s[i]]) != t[i]){

//                 return false;

//             }

//         }

//         return true;
        
//     }
// };
public:
//     bool isIsomorphic(string s, string t) {
//         int s2t[256] = {0}; // Mapping from s to t
//         int t2s[256] = {0}; // Mapping from t to s

//         for (int i = 0; i < s.size(); i++) {
//             // Check the mapping from s to t
//             if (s2t[s[i]] == 0) {
//                 s2t[s[i]] = t[i];
//             } else if (s2t[s[i]] != t[i]) {
//                 return false;
//             }

//             // Check the mapping from t to s
//             if (t2s[t[i]] == 0) {
//                 t2s[t[i]] = s[i];
//             } else if (t2s[t[i]] != s[i]) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.size(); i++) {
            char sChar = s[i];
            char tChar = t[i];

            if (s2t.find(sChar) != s2t.end()) {
                if (s2t[sChar] != tChar) {
                    return false;
                }
            } else {
                s2t[sChar] = tChar;
            }

            if (t2s.find(tChar) != t2s.end()) {
                if (t2s[tChar] != sChar) {
                    return false;
                }
            } else {
                t2s[tChar] = sChar;
            }
        }

        return true;
    }
};