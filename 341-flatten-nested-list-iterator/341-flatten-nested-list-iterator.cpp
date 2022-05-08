/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> a;
    int ptr = 0;
    void getIntegers(vector<NestedInteger>& nestedList, int pos) {
        int n = nestedList.size();
        if(pos == n) {
            return;
        }
        if(nestedList[pos].isInteger()) {
            int val = nestedList[pos].getInteger();
            a.push_back(val);
            getIntegers(nestedList, pos + 1);
            return;
        }
        getIntegers(nestedList[pos].getList(), 0);
        getIntegers(nestedList, pos + 1);
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        getIntegers(nestedList, 0);
    }
    
    int next() {
        return a[ptr++];
    }
    
    bool hasNext() {
        if(ptr == (int) a.size()) {
            return false;
        }
        return true;
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */