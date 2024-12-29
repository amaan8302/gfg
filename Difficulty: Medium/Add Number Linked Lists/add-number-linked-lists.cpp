//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends

class Solution {
  public:
    void insertAtTail(Node* &head, Node* &tail, int val)
    {
        Node* temp = new Node(val);
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    Node* reverseList(Node* head) 
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* temp=NULL;
        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* add(Node* l1, Node* l2)
    {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while(l1!=NULL && l2!=NULL)
        {
            int sum = carry + l1->data + l2->data;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            l1 = l1 -> next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            int sum = carry + l1->data;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail,digit);
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            int sum = carry + l2->data;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail,digit);
            carry = sum/10;
            l2 = l2->next;
        }
        while(carry!=0)
        {
            int sum = carry;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail,digit);
            carry = sum/10;
        }
        return ansHead;
    }
    Node* addTwoLists(Node* l1, Node* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        Node* ans = add(l1,l2);
        ans = reverseList(ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends