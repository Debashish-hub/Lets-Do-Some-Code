class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;        
        string digits ="123456789";
        int lSize = to_string(low).size(), usize = to_string(high).size();

        for(int i = lSize; i <= usize; i++) { 
            for(int j=0; j<10-i; j++){
                int num = stoi(digits.substr(j,i));
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};