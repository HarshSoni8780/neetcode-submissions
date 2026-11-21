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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalLen = 0;
        ListNode* temp = head;
        while(temp != NULL){
            totalLen++;
            temp=temp->next;
        }

        int findna = totalLen - n;

        if(findna == 0){
            if(totalLen == 1){
                return nullptr;
            }
            else{
                return head->next;
            }
        }

        int cnt = 1;
        ListNode* prev = head;
        temp = head->next;
        ListNode* node = head;
        while(temp != NULL){
            ListNode* front = temp->next;
            if(cnt == findna){
                prev->next = front;
                break;
            }
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        return node;
    }
};
