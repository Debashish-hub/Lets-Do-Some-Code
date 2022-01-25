class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        int i = 0, j = 1;
        if(arr[i] > arr[j]){
            return false;
        }
        while(arr[j] > arr[i]){
            i++;
            j++;
        }
        if(i == arr.size()-1){
            return false;
        }
        while(i < arr.size()-1){
            if(arr[i] > arr[i+1]){
                i++;
            }else{
                return false;
            }
        }
        return true;
    }
};