/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    struct Compare 
    {
        bool operator()(Node* a, Node* b) 
        {
            return a->data > b->data;
        }
    };
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
    for (Node* list : arr) {
        if (list) pq.push(list);
    }

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (!pq.empty()) {
        Node* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = node;
        if (node->next) pq.push(node->next);
    }

    return dummy->next;
    }
};