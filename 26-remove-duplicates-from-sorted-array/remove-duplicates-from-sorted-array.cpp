class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //two pointer approach -
        int i=1,j=0;

        //here j=0 bcoz j aur j k pehle sare unique elements honge
        // i=1 means i elemts se j ke elements compare karenge and same mila to age badhenge
        // same nai mila to j ko age badhaenge and a[j]=a[i] karenge and then i ko age badhate

        while(i< nums.size()){

            if(nums[i]==nums[j]){
                i++;
            }else{
                j++;
                nums[j]=nums[i];
                i++;
            }
            //else nums[++j]=nums[i+] -- this is shortcut logic for else block
        }
        return j+1; //kyu ki j 0 se start hua to j tak sare unique elements hai
        // that means k unique elements are j+1 


        //agar sare unique elemts rahe to pura loop chalega - that means
        // time complexity is O(n)       
    }
};