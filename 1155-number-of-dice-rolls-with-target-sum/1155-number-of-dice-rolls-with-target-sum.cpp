long MOD = (long)pow(10,9) + 7;

class Solution {
public:
    vector<vector<int>> records;
    int numRollsToTarget(int n, int k, int target) {
        
        this->records = vector<vector<int>>(n, vector<int>(target + 1, -1));
        long result = helper(n, k, 0, target);
        return result;
    }
    /*  we need to use the n dice, each dice has k 
    */
    long helper(int n, int k, int p, int rest_target){
        
        if (rest_target < 0){
            return 0;
        }
        if (p >= n){
            if (rest_target == 0){
                return 1;
            }
            return 0;
        }
        if (this->records[p][rest_target] != -1){
            return this->records[p][rest_target];
        }
        /*  regular case, at index=p, what value can supply.
        */
        long sub, result = 0;
        for (int value = 1; value <= k; value++){            
            sub = helper(n, k, p + 1, rest_target - value);
            result += sub % MOD;
            result = result % MOD;
        }
        this->records[p][rest_target] = result;
        return result;
    }
};