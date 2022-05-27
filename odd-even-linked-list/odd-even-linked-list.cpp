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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *ptr1 = odd, *ptr2 = even;
        while(ptr2 != NULL && ptr1 != NULL && ptr2->next != NULL) {
            ptr1->next = ptr2->next;
            ptr1 = ptr2->next;
            ptr2->next = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = even;
        return odd;
    }
};