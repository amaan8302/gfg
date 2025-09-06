class Solution {
  public:
    int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            Node* temp = slow;
            slow = slow->next;
            int cnt = 1;
            while(slow != temp) {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}

};