//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

class Solution {
  public:
    bool prime(int n)
    {
        if (n <= 1) return false;
        if (n == 2 || n == 3) 
            return true;
        if (n % 2 == 0 || n % 3 == 0) 
            return false;
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int solve(int n)
    {
        if(prime(n))
            return n;
        int prev = n-1;
        int next = n+1;
        while(true)
        {
            if(prev>=2&&prime(prev))
                return prev;
            if(prime(next))
                return next;
            prev--;
            next++;
        }
    }
    Node *primeList(Node *head) {
        Node*temp = head;
        while(temp)
        {
            int x = solve(temp->val);
            temp->val = x;
            temp = temp->next;
        }
        return head;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends