class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        int n = nums.size();
        int i=0, j=1;
        //int count=0;
        set<pair<int,int>> ans;
        sort(nums.begin(), nums.end());

        while(j<n){
            if(nums[j]-nums[i]==k){
                ans.insert({nums[i],nums[j]});
                //count ++;
                i++;
                j++;
            }else if(nums[j]-nums[i]>k){
                i++;
            }else{
                j++;
            }
            if(i==j){//to avoid comparing with same index
                j++;
            }
        }

    //cout <<ans ;
    //return count; -- Here it wont accept the submission 
    //reason for same if ip is 1,1,1 and k=0 it fails, as we only want distict pairs
    return ans.size();       
    }
};