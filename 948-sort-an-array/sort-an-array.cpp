class Solution {
public:

    void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end){

        //2 pointer approach
        int i = start;
        int j = mid+1;

        //pehli array i = 0 se mid tak and 2nd array mid+1 se end tak

        //merged array --> is temp and is eq to v and so
        int k=start;

        while(i<=mid && j<=end){
            
            if(v[i]<=v[j]){
                temp[k++]=v[i++]; 

            }else{
                temp[k++]= v[j++];
            }
        }

        //handle remaining elements in case of diff arr size
        while(i<=mid){
            temp[k++]=v[i++]; 
        }
        while(j<=end){
            temp[k++]= v[j++];
        }

        //lets copy merged data of temp to v
        while(start <= end){
            v[start] = temp[start];
            start++;
        }



    }


    void mergeSort(vector<int> &v, vector<int> &temp, int start, int end){
        
        if(start >= end){
            return;
        }

        int mid = (start + end)/2;

        //divide
        mergeSort(v, temp, start, mid);
        mergeSort(v, temp, mid+1, end);

        //conqure - merge
        merge(v, temp, start, mid, end);


    }

    vector<int> sortArray(vector<int>& nums) {

        //for merge operation - use temp vector
        vector<int>temp(nums.size(), 0); //iska size nums size itna and initial val 0

        mergeSort(nums, temp, 0, nums.size()-1);

        return nums;
        
    }
};