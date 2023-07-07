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
    ListNode* merge(ListNode *h1, ListNode *h2){
        ListNode head, *temp = &head;
        while(h1 && h2){
            if(h1 -> val < h2 -> val)
                temp -> next = h1, h1 = h1 -> next;
            else
                temp -> next = h2, h2 = h2 -> next;
            temp = temp -> next;
        }
        if(h1)
            temp -> next = h1;
        if(h2)
            temp -> next = h2;
        return head.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        if(lists.size() == 1)
            return lists[0];
        vector<ListNode*> temp;
        for(int i = 0; i < lists.size(); i += 2){
            if(i + 1 == lists.size())
                temp.push_back(merge(lists[i], nullptr));
            else
                temp.push_back(merge(lists[i], lists[i + 1]));
        }
        return mergeKLists(temp);
    }
};