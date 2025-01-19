//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int total(Node* head)
    {
        if(head==NULL)
            return 0;
        if(head->next==NULL)
            return 1;
        Node* temp = head;
        int k = 0;
        while(temp!=NULL)
        {
            k++;
            temp = temp->next;
        }
        return k;
    }
    Node* rotate(Node* head, int k) {
        if(head == NULL)
            return NULL;
        if(!head->next)
            return head;
        int shift = k % total(head);
        Node* temp = head;
        Node* first = head;
        Node* second = NULL;
        Node* last = head;
        if(shift==0)
            return head;
        while (last && last->next)
            last = last->next;
        while(shift!=1)
        {
            temp = temp->next;
            shift--;
        }
        last->next = first;
        second = temp->next;
        temp -> next = NULL;
        return second;
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

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends