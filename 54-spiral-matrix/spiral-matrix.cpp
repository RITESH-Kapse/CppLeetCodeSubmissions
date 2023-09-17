class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int>ans;

        int m=matrix.size();
        int n=matrix[0].size();

        int total_elements = m*n;

        int starting_row =0;
        int ending_col = n-1;
        int starting_col=0;
        int ending_row= m-1;
        int count = 0;

        while(count < total_elements){

            //print starting row
            for(int i=starting_col;i<=ending_col && count < total_elements;i++){
                
                ans.push_back(matrix[starting_row][i]);
                count++;

                if(count >= total_elements){
                    break;
                }

            }

            starting_row++;

            //print ending col
            for(int i=starting_row;i<=ending_row && count < total_elements;i++){

                ans.push_back(matrix[i][ending_col]);
                count++;

            }

            ending_col--;
            //print ending row
            for(int i=ending_col;i>=starting_col && count < total_elements;i--){

                ans.push_back(matrix[ending_row][i]);
                count++;

            }

            ending_row--;
            //print starting col
            for(int i=ending_row;i>=starting_row && count < total_elements;i--){

                ans.push_back(matrix[i][starting_col]);
                count++;

            }
            starting_col++;

        }

    return ans;


        
    }
};