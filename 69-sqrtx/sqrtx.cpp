class Solution {
public:
    int mySqrt(int x) {

        int s=0;
        int e=x;

        long long int mid=s+(e-s)/2; // if we will take only int, 
        // it gives error due to oversize of mid*mid , hence use long long int
        int ans=-1;

        while(s<=e){

            //kya mid hi answer hai
            if(mid*mid==x){

                return mid;

            }else if(mid*mid < x){

                //ans store karo kyu ki 8.something times me value 8 and 9 k bich wala ho
                // sakta hai -- like for 48 value will be 6.9 - hence 6*6 <48 k lie store 6
                //then go to right

                ans=mid;
                s=mid+1;

            }else{

                //left me jao
                e=mid-1;

            }
            mid=s+(e-s)/2;
            // agar yaha mid = s/2 + e/2 lia to overflow error aaega - use above formula only
            
        }

        return ans;
        
    }
};