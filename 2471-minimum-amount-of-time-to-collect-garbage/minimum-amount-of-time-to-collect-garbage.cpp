class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int pickP=0;
        int pickM=0;
        int pickG=0;

        int travelP=0;
        int travelG=0;
        int travelM=0;

        //jahatak last P/G/M milega tabtak uska truck jaega
        int lastP=0;
        int lastG=0;
        int lastM=0;


        //calculate pick and travel time
        for(int i=0; i<garbage.size(); i++){

            string curr = garbage[i]; // we are on current string in input vector

            //now lets find char in string and check if itsP?G?M and find picktime 
            for(int j=0; j< curr.length();j++){
                char ch=curr[j];

                if(ch=='P'){
                    pickP++; //if P found , increse P count
                    lastP=i; // P mila that means yaha tak to truck chalega atleaset - hence lastP=i

                }else if(ch=='G'){
                    pickG++;
                    lastG=i;

                }else if(ch=='M'){
                    pickM++;
                    lastM=i;
                }
            }
        }

        //calculate travel time - apne pas lastP/M/G hai i equals wala 
        //travel array me 3 values hai - 1 for P then M and G

        for(int i=0; i<lastP;i++){
            travelP= travelP + travel[i]; 
            // matlab P tak jane me kitna time lagega 
            //sum[wo konse index pe hai * uska respective traval[value] from input travel array]

        }
        
        for(int i=0; i<lastG;i++){
            travelG=travelG + travel[i];
        }

        for(int i=0; i<lastM;i++){
            travelM=travelM + travel[i];
        }

        //now lets calculate total pick time + travel time
        int ans = (pickP+travelP)+(pickG+travelG)+(pickM+travelM);

        return ans;    

    }
};