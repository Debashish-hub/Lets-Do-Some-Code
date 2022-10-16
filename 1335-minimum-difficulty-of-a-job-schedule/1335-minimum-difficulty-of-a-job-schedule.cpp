class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        // Corner Case: Less than d jobs available, no valid schedule, return -1
        if (n < d)
            return -1;
        
        // Corner Case: Exactly d jobs available, schedule 1 job per day, return sum of array as result
        if (n == d)
            return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        
        // DP State: (lastCutIdx, d)
        // lastCutIdx = Last Cut Index, initially when there are no cuts, this is set to -1
        // d = Number of cuts remaining, for d days, we need d-1 cuts, so that's why we initially start with d-1
        vector<vector<int>> t(n, vector<int>(d, -1));
        return solve(jobDifficulty, -1, d-1, t);
    }
	
	int solve(vector<int> &jd, int lastCutIdx, int d, vector<vector<int>> &t) {
        int k, n = jd.size(), curRes, curMax, nextRes;
        
        // If not enough jobs remaining as the number of cuts left, then this is not a valid solution
        // return INT_MAX for it to not be selected as a solution
        if (n - lastCutIdx - 1 <= d)
            return INT_MAX;
        
        // For indicating current subproblem we use lastCutIdx+1 because we start with lastCutIdx = -1
        // for which the table indexing will fail, so this is an adjustment for that
        if (t[lastCutIdx+1][d] != -1)
            return t[lastCutIdx+1][d];
        
        // If we have no cuts remaining, then the remaining array, (lastCutIdx+1, n-1) becomes the set
        // of jobs scheduled on the last day and difficulty for this job will be max job difficulty
        // in the subarray (lastCutIdx+1, n-1)
        if (d == 0) {
            curMax = jd[lastCutIdx+1];
            for (k=lastCutIdx+2; k<n; k++)
                curMax = max(curMax, jd[k]);
            return t[lastCutIdx+1][d] = curMax;
        }
        
        // We have cuts available, so try to place the next cut anywhere from lastCutIdx+1 to n-2
        // We cannot place a cut at n-1 because that's putting a cut at the end of the array, partitioning
        // into a non-empty and an EMPTY subarray which is not allowed (atleast 1 job must be scheduled)
        // If we place the cut at index k, (lastCutIdx+1, k) becomes the set of jobs scheduled on that day
        // and the job difficulty will be the max in this subarray and the total difficulty will be
        // job difficulty of that day + the job difficulties of the future cuts, i.e.
        // solve(k, d-1) => Last Cut at index k and one more cut used up
        curMax = INT_MIN, curRes = INT_MAX;
        for (k=lastCutIdx+1; k<n-1; k++) {
            curMax = max(curMax, jd[k]);
            nextRes = solve(jd, k, d-1, t);
            
            if (nextRes != INT_MAX)
                curRes = min(curRes, curMax + nextRes);
        }
        
        return t[lastCutIdx+1][d] = curRes;
    }
};