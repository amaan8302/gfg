//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
class Solution {
  public:
    Node* mergeSortedLL(Node* head1, Node* head2) 
    {
        if (!head1) return head2;
        if (!head2) return head1;
    
        Node* result = nullptr;
        if (head1->data < head2->data) {
            result = head1;
            result->next = mergeSortedLL(head1->next, head2);
        } else {
            result = head2;
            result->next = mergeSortedLL(head1, head2->next);
        }
        return result;
    }
    
    Node* midPoint(Node* head) {
        if (!head || !head->next)
            return head;
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        if (!head || !head->next)
            return head;
    
        Node* mid = midPoint(head);
        Node* right = mid->next;
        mid->next = nullptr;
    
        Node* left = mergeSort(head);
        right = mergeSort(right);
    
        return mergeSortedLL(left, right);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends