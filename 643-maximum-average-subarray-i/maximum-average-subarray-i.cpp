class Solution {
public:

    double slidingWindow(vector<int>& nums, int k){

        // Second approach - Sliding window

            //formula - 
            // first time pura sum nikalo - i=0 to j=k-1 tak
            // then next k elemnts k lie niche wala formula use karo -
            //Step 1 -> sum = sum - num[i++]; 
            //Step 2  -> sum = sum + num[++j];

        int i=0,j=k-1;
        int sum=0;

        for(int y=i;y<=j;y++){
            sum=sum+nums[y];
        }

        int maxsum = sum;
        j++;

        while(j< nums.size()){

            sum=sum-nums[i++];
            sum=sum+nums[j++];
            maxsum = max(maxsum,sum);
        }  

        double maxAvg=maxsum/(double)k;
        return maxAvg;
    }


    double bruteforce(vector<int>& nums, int &k){

        // there are 2 aapproaches - 1 is brute force method - time complexity O(n^2)
        int maxsum = INT_MIN;
        int i=0,j=k-1;

        while(j<nums.size()){

            int sum=0;
            for(int y=i;y<=j;y++){

                sum = sum+nums[y];

            }

            maxsum = max(maxsum,sum);

            j++,i++;

        }
        double maxAvg = maxsum/(double)k;
        return maxAvg;

    }

    double findMaxAverage(vector<int>& nums, int k) {

        return slidingWindow(nums,k);
        //return bruteforce(nums,k);
        
        
    }
};