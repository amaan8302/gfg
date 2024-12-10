//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/* Following is the Linked list node structure */
class Solution {
  public:
    void reorderList(Node* head) {
   if (!head || !head->next) return;
   
   Node* slow = head;
   Node* fast = head;
   while (fast->next && fast->next->next) {
       slow = slow->next;
       fast = fast->next->next;
   }
   
   Node* prev = nullptr;
   Node* curr = slow->next;
   while (curr) {
       Node* nextNode = curr->next;
       curr->next = prev;
       prev = curr;
       curr = nextNode;
   }
   slow->next = nullptr;
   
   Node* first = head;
   Node* second = prev;
   while (second) {
       Node* firstNext = first->next;
       Node* secondNext = second->next;
       
       first->next = second;
       second->next = firstNext;
       
       first = firstNext;
       second = secondNext;
   }
}
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends