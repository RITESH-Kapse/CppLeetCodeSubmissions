class MinStack {
public:

    vector<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()){
            //matlab first ele push kar rahe hai - wahi min bhi rahega
            //pair<int,int> p = make_pair();
            pair<int,int> p ;
            p.first = val;
            p.second = val ; //yaha first ele hi min rahega

            st.push_back(p);

        }else{// non -empty case

            pair<int,int> p ;
            p.first = val;

            //yaha check karo that cureent val min hai ya purana val min tha
            int puranaMin = st.back().second; //right most pair -st.back and uska second is min val stored  - pair = <val, min>
            p.second =  min(puranaMin, val); //abhi and purana mese konsa min hai wo second me dalenge

            st.push_back(p);
        }
        
    }
    
    void pop() {

        //rightmost ele pop
        st.pop_back();
        
    }
    
    int top() {

        pair<int,int> rightMostPair = st.back();
        return rightMostPair.first ;
       
    }
    
    int getMin() {

        pair<int,int> rightMostPair = st.back();
        return rightMostPair.second ;

        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */