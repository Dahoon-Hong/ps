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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int next=0;        
        int current=0;
        ListNode *l1node = l1;
        ListNode *l2node = l2;
        ListNode *result = nullptr;
        ListNode *currentNode = nullptr;
        int flag=0;
        while(true)
        {
            flag=0;
            current = next;
            if(l1node != nullptr)
            {
                current += l1node->val;
                l1node = l1node->next;
                flag=1;
            }
            if(l2node != nullptr)
            {
                current += l2node->val;
                l2node = l2node->next;
                flag=1;
            }
            if(flag == 0 && next ==0)
            {
                break;
            }
            next = current / 10;
            current = current - next*10;
            ListNode *tempNode = new ListNode();
            tempNode->val = current;
            if(currentNode == nullptr)
            {
                currentNode = tempNode;
            }
            else
            {
                currentNode->next = tempNode;
                currentNode = tempNode;
            }
            if(result == nullptr)
            {
                result = currentNode;
            }
            
        }
        if(result == nullptr)
        {
            result = new ListNode();
            result->val = 0;
        }
        return result;
        
    }
};