class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target != startValue){
            if(startValue > target){
                return ans + startValue-target;
            }
            if(target % 2 == 0){
                target /= 2;
            }else{
                target++;
            }
            ans++;
        }
        return ans ;
    }
};