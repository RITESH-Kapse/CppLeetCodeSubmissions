class Solution {
public:
    int firstUniqChar(string s) {
        
    queue <char> q;

    int ans;

    int freq[26] = {0};

    for(int i=0; i<s.length(); i++){

        char ch=s[i];
        freq[ch -'a']++;
        q.push(ch);

        //answer find karlo
        while(!q.empty()){
            char frontchar = q.front();

            if(freq[frontchar - 'a'] > 1){
                //yani ye ans nai hai -- logic nusar frq array me count add ho raha hai jo b char aaega str me uska
                //freq[ch - 'a'] --> matlab ch mese a minus karo to unka ascii val minas hota and 0 , 1 etc values add hoti

                q.pop();

            }else{ // freq[frontchar - 'a'] =  1 wala case

                //that means yahi ans hai
                //ans = s[frontchar] ;
                ans = s.find(frontchar) ;
                break;

            }
        }

        if(q.empty()){
            //koi ans nai nikla
            ans = -1;

        }
    }

    return ans;

    }
};