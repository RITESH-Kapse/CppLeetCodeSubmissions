class Solution {
public:
    vector<double> convertTemperature(double celcius){

        double k = celcius + 273.15;
        double f = celcius * 1.80 + 32.00;

        vector<double>v;
        v.push_back(k);
        v.push_back(f);

        return v;
    }
};