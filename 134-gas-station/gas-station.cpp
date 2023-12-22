class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int deficit = 0; // kiti kami padla petrol/gas
        int balance = 0; //kiti shillak aahe gas

        //kontya index pasun suru karaicha check karaila
        int start = 0;

        //check every index and update the start 
        for(int i=0; i<gas.size(); i++){

            balance = balance + gas[i] - cost[i]; // note - ek litre petrol madhe 1 km jato - hence remaining is balance

            if(balance < 0){ //mhnje petrol kami padla - kiti padla te note kara

                deficit = deficit + abs(balance); //abs karan balance -ve asel
                start = i+1; //start la pudhe nya karan prev warun circle complete hot nawta
                balance = 0 ; //next index[start] sathi parat balance is 0

            }
        }

        if(balance - deficit >= 0 ){//mhnje travel possible
            return start;
        }else{
            return -1;
        }
       
    }
};