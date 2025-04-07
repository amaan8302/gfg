//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int,int>mp;
        Node* temp1 =head1;
        int cnt = 0;
        while(temp1)
        {
            mp[temp1->data] = cnt++;
            temp1 = temp1->next;
        }
        vector<pair<int,int>>vec;
        Node*temp2 = head2;
        while(temp2)
        {
            if(mp.find(temp2->data)!=mp.end())
                vec.push_back({mp[temp2->data],temp2->data});
            temp2 = temp2->next;
        }
        if (vec.empty()) return nullptr;
        std::sort(vec.begin(),vec.end());
        Node* head3 = new Node(vec[0].second);
        Node* temp = head3;
        for(int i = 1 ; i < vec.size() ; i++)
        {
            temp->next = new Node(vec[i].second);
            temp = temp->next;
        }
        return head3;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        int tmp;
        string input1, input2;

        getline(cin, input1);
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.findIntersection(head1, head2);
        printList(result);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends