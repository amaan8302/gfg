//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

class Solution {
  public:
    Node* merge(Node* left, Node* right)
    {
        Node dummy(0);
        Node* tail = &dummy;
    
        while (left && right) {
            if (left->data < right->data) {
                tail->bottom = left;
                left = left->bottom;
            } else {
                tail->bottom = right;
                right = right->bottom;
            }
            tail = tail->bottom;
        }
        tail->bottom = left ? left : right;
        return dummy.bottom;
    }
    
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->bottom;
        while (fast && fast->bottom) {
            slow = slow->bottom;
            fast = fast->bottom->bottom;
        }
        return slow;
    }
    
    Node* mergeSort(Node* head) {
        if (!head || !head->bottom) return head;
    
        Node* mid = getMid(head);
        Node* right = mid->bottom;
        mid->bottom = nullptr;
    
        Node* left = mergeSort(head);
        right = mergeSort(right);
    
        return merge(left, right);
    }
    Node *flatten(Node *root) {
        Node* temp1 = root;
        Node* temp2 = root->next;
        while(temp2)
        {
            Node *down = temp1;
            while(down->bottom)
                down = down->bottom;
            down->bottom = temp2;
            temp1->next = NULL;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return mergeSort(root);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends