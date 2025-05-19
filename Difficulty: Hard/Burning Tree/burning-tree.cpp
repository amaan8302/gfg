//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

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
    Node* createMapping(Node* root, int target, map<Node*,Node*>&nodeToParent)
    {
        //ye wala function har node ka parent store kar raha hain
        // target node bhi return karta he
        Node* result=NULL;
        queue<Node*>q;
        q.push(root);
        nodeToParent[root]=NULL;
        // q.push(NULL);
        while(!q.empty())
        {
            Node*temp=q.front();
            q.pop();
            if(temp->data==target)
                result=temp;
            if(temp->left)
            {
                nodeToParent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                nodeToParent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return result;
    }
    int burnTree(Node* root,map<Node*,Node*>&nodeToParent)
    {
        map<Node*,bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        int time=0;
        while(!q.empty())
        {   
            bool flag=0;//to check queue mein kuch addition hua hain ya nhi
            int size=q.size(); //jitne bhi element pade honge unn sbke lia neighbouring node ko burn karke aaoge    
            for(int i=0;i<size;i++)
            {
                Node*front = q.front();
                q.pop();
                if(front->left && !visited[front->left])
                {
                    flag=1;//addition hua he to flag ko true mark kardo
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right])
                {
                    flag=1;//addition hua he to flag ko true mark kardo
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(nodeToParent[front]&& !visited[nodeToParent[front]])
                {
                    flag=1;//addition hua he to flag ko true mark kardo
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                }
            }
            if(flag==1)
                time++;
        }
        return time;
    }
    int minTime(Node* root, int target) 
    {
        int time;
        map<Node*,Node*>nodeToParent;//ishilie kyunki hum kisi bhi node pe kade hein to hum uska parent nhi bata skte
        Node*targetNode=createMapping(root,target,nodeToParent);
        time = burnTree(targetNode,nodeToParent);
        return time;
    }
    
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends