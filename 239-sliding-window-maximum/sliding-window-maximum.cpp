class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;

        //1. first window ko process karo -- usme max ele k index to deque me dalo
        for(int i=0; i<k; i++){

            int element = nums[i];

            //now check that , dequeue me agar koi ele se chota ele ka index hai to uska index remove karo

            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            //agar ele dq wale last ele se chota hai to bhi uska index store karo [ useful for next window]
            dq.push_back(i);

        }

        //2. process remaining windows 
            //removal elements which are not in k range [index - k >= 0]
            //add new element[index] which is bigger than prev
        
        for(int i=k; i<nums.size(); i++){
            //store karo ans me dq ka front ele [ index se ele ]
            ans.push_back(nums[dq.front()]);

            //remove out of range elements
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();

            }

            //remove chote elements jo current elements se chote hai and jinka index dq me stored hai
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            //addition of ele ka index wo chahe bada ho ya chota
            dq.push_back(i);        

        }

        //last window ka ans store karo
        ans.push_back(nums[dq.front()]);

        return ans;        
    }
};