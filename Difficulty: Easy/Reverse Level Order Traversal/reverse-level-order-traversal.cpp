//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int>ans;
        vector<vector<int>>res;
        queue<Node*>que;
        que.push(root);
        que.push(NULL);
        while(!que.empty())
        {
            Node* top = que.front();
            que.pop();
            if(top==NULL)
            {
                res.push_back(ans);
                ans.clear();
                if(!que.empty())
                    que.push(NULL);
            }
            else
            {
                ans.push_back(top->data);
                if(top->left)
                    que.push(top->left);
                if(top->right)
                    que.push(top->right);
            }
        }
        ans.clear();
        for(int i = res.size()-1 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < res[i].size() ; j++)
                ans.push_back(res[i][j]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
//   Driver program to test size function
int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);
        Solution obj;
        vector<int> result = obj.reverseLevelOrder(head);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends