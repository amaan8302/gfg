class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        if(head->data > data)
        {
            Node* temp = head;
            while(temp->next!=head)
                temp = temp->next;
            Node* x = new Node(data);
            temp->next = x;
            x->next = head;
            return x;
        }
        Node*tail = head;
        while(tail->next!=head)
                tail = tail->next;
        if(data > tail->data)
        {
            Node* x = new Node(data);
            tail -> next = x;
            x->next = head;
            return head;
        }
        Node* temp = head;
        Node* x = new Node(data);
        while(temp->next->data < data)
            temp = temp->next;
        Node* nxtTemp = temp->next;
        temp->next = x;
        x->next = nxtTemp;
        return head;
    }
};