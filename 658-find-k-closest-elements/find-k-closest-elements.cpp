class Solution {
public:

    //approach 2 - 2 pointer approach - time complexity - O(k-n) - space O(1)
    vector<int> twoPointerMethod(vector<int>& arr, int k, int x){

        int low=0; int high=arr.size()-1;

        while(high-low >=k){

            if(x-arr[low]>arr[high]-x){
                low++;
            }else{
                high--;
            }
        }

        vector<int> ans;

        for(int i=low;i<=high;i++){
            ans.push_back(arr[i]);
        }

        return ans;

    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //approach 1 - nlogn - sorting
        // sare elements ka diff nikal0 x se , means arr[i]-x and un sabko vector me add karo
        // ans.push_back(value);
        //then ans ko increasing order me sort karo -- sort(ans);
        // then first 4 elements ko print kardo -- for i till i<=k print arr[i]

        //approach 2 - 2 pointer approach
        // low from left , high from right
        // get diff of number from x at both ends
        // jiska diff chota hai usko ignore karo
        // jiska bada hai diff wo side pointer decrease karo
        // x-a[l] > a[h]-x then low ++ else high --
        // while loop chalega until high - low >= k that means k elements left
        //then return all eles from low to high

        return twoPointerMethod(arr,k,x);

        }
};