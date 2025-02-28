class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head; // If the list is empty or has one element, return it.
        
        ListNode* dummy = new ListNode(0); // Dummy node to simplify insertion.
        ListNode* curr = head; // Pointer to iterate over the original list.
        
        while (curr) {
            ListNode* prev = dummy;
            ListNode* next = curr->next; // Store next node to process.
            
            // Find the correct position to insert current node.
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            // Insert current node into the sorted list.
            curr->next = prev->next;
            prev->next = curr;
            
            // Move to the next node.
            curr = next;
        }
        
        return dummy->next; // Return sorted list.
    }
};