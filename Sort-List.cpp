// Source : https://leetcode.com/problems/sort-list/
// Date   : 12-05-2022

/********************************************************************************** 

Given the head of a linked list, return the list after sorting it in ascending order.

Input: head = [4,2,1,3]
Output: [1,2,3,4]

**********************************************************************************/

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
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1 != NULL) {
            curr->next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL) {
            curr->next = l2;
            l2 = l2->next;
        }
        
        return ptr->next;
    }
    
    ListNode *mergeSort(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *mid=head, *fast=head->next;
        
        while(fast != NULL && fast->next != NULL) {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        ListNode *secondHalf = mid->next;

        /*
            Breaking linked list into two parts.
            If we don't make mid->next = NULL then in the recursive call,
            it will always go the initial linkedlist end.
        */
        mid->next = NULL;
        
        ListNode *l1 = mergeSort(head);
        ListNode *l2 = mergeSort(secondHalf);
        
        return merge(l1, l2);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};