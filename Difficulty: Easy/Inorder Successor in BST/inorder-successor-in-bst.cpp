//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* search(Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}


// } Driver Code Ends

class Solution {
  public:
    vector<int> in;
    void inorder(Node *root) {
        if (root == NULL)
            return;
        inorder(root->left);
        in.push_back(root->data);
        inorder(root->right);
    }
    int inOrderSuccessor(Node *root, Node *x) {
        in.clear();  
        inorder(root);
        
        int tar = x->data;
        int idx = -1;  
        int low = 0, high = in.size() - 1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (in[mid] == tar) {
                idx = mid;
                break;
            } else if (in[mid] > tar) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (idx == -1 || idx + 1 >= in.size())  
            return -1;
    
        return in[idx + 1];
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Node* kNode = search(head, k);
        Solution obj;
        cout << obj.inOrderSuccessor(head, kNode) << endl;

        cout << "~"
             << "\n";
    }

    return 1;
}
// } Driver Code Ends