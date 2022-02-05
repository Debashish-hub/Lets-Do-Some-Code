/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void copyListToArray(ListNode* list, vector<int>& array){
        while(list != nullptr){
            array.push_back(list->val);
            list=list->next;
        }
        //cout<<"\n Array Size:"<<array.size();
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<int> array;
        auto itr=lists.begin();
        while(itr!=lists.end()){
            copyListToArray(*itr,array);
            itr++;
        }
        sort(array.begin(), array.end());
        ListNode* result=nullptr;
        ListNode* temp=nullptr;
        for(int i=0;i<array.size();i++){
            if(result == nullptr){
                result=new ListNode(array[i]);
                temp=result;
                continue;
            }
            temp->next=new ListNode(array[i]);
            temp=temp->next;
        }
        
        return result;
    }
};