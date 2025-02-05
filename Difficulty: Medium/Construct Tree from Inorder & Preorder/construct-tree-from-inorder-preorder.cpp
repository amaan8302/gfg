//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

class Solution {
  public:
    int findPosition(vector<int> &inorder, int element) 
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == element)
                return i;
        }
        return -1;
    }
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &i, int start, int end, int n) {
        if (i >= n || start > end)
            return NULL;
    
        int ele = preorder[i++];
        Node* root = new Node(ele);
        int pos = findPosition(inorder, ele);
    
        root->left = solve(inorder, preorder, i, start, pos - 1, n);
        root->right = solve(inorder, preorder, i, pos + 1, end, n);
    
        return root;
    }
    
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int index = 0;
        return solve(inorder, preorder, index, 0, inorder.size() - 1, inorder.size());
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends