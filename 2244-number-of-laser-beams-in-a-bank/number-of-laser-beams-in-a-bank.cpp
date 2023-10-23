class Solution {
public:

    int countDevices(string& binary){
        int c=0;

        for(auto b:binary){
            c = c + b - '0';
        }

        return c;
    }

    int numberOfBeams(vector<string>& bank) {

        //number of devices string me hai unko int me karte hai first
        vector<int> devices;

        for(auto row:bank){
            devices.push_back(countDevices(row));
        }

        int beams = 0;        

        for(int i=0; i<devices.size(); i++){

            int j= i+1;

            while(j < devices.size()){
                beams = beams + devices[i] * devices[j];

                if(devices[j]==0){
                    j++;
                }else{
                    break;
                }
            }

        }
        return beams;
    }
    
};