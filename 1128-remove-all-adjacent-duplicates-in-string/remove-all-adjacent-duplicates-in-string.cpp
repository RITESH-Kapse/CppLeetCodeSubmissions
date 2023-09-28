class Solution {
public:
    string removeDuplicates(string s) {

        string ans ="";
        int index = 0;

        while(index < s.length()){

            //if ans[rightmost] is same as s[index] then pop
            if(ans.length() >0 && s[index]==ans[ans.length()-1]){

                //pop from ans
                ans.pop_back();

            }else{
                ans.push_back(s[index]);
            }
            index ++;
        }

        return ans;        
    }
};