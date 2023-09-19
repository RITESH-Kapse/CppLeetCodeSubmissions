class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();

        int n= row*col; // very very imp for 2D matrix [ n is not arr.size() here]

        //int totalSize = row*col; //total dabbe iin matrix

        int s=0;
        int e=n-1;

        int mid = s+(e-s)/2;

        while(s<=e){

            // to covert given 2D array into 1D as it will be stored as 1D array [Binary Srch]
            int rowIndex = mid/col;
            int colIndex = mid%col;

            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber==target){
                return true;
            }else if(target > currNumber){
                s=mid+1;
            }else{
                e=mid-1;
            }

            mid=s+(e-s)/2;
        }

        return false;



        
    }
};