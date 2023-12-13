class Solution {

//next and prev are [index val ]

//width = next - prev - 1

//Note - next nikalne se pehle horizontal dekho kaha tak ja sakta hai -
// jiske aage nai ja sakte uske bad wala next 
//prev k lie bhi left leke jao jaha tak ja sakta 
//ek bar pohoch gae left most possible pe to uske pehle wala prev 


// Ex - 1 me
// Start from 0th index [val = 2]  - uske pehle ka index = -1
// right most val = 3 uska index is 5 - uske bad wala 6 [val = 0]


public:

    vector<int> nextSmallElement(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);

        for(int i=arr.size()-1; i>=0; i--){

            //find ans for curr
            int curr = arr[i];

            while(st.top()!= -1 && arr[st.top()] >=curr ){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);

        }

        return ans;

    }

    vector<int> prevSmallElement(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);

        for(int i=0; i< arr.size(); i++){

            //find ans for curr
            int curr = arr[i];

            while(st.top()!= -1 && arr[st.top()] >=curr){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);

        }

        return ans;

    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> next = nextSmallElement(heights);

        for(int i=0; i<heights.size();i++){
            
            //yaha agar next index[rightmost] me kuch nai hai to -1 le rahe the
            //uski jaga heights ka size lo -
            if(next[i]==-1){
                next[i] = heights.size();
            }

        }

        vector<int> prev = prevSmallElement(heights);

        vector<int> area(next.size());

        for(int i=0; i<next.size(); i++){
            int width = next[i] - prev[i]-1;
            int lenght = heights[i];

            int currArea = width * lenght;
            area [i] = currArea;
        }

        int maxi = INT_MIN; 

        for(int i=0; i<area.size(); i++){
            maxi = max(maxi, area[i]);
        }

        return maxi;
        
    }
};