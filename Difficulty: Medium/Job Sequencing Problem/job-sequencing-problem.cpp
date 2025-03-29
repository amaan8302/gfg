//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    class DSU {
        vector<int> parent;
    public:
        DSU(int n) {
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
    
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]); // Path compression
        }
    
        void merge(int u, int v) {
            parent[find(u)] = find(v);
        }
    };

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<vector<int>> jobs(n);
        
        for(int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
        }
    
        sort(jobs.rbegin(), jobs.rend()); // Sort by profit in descending order
    
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        DSU dsu(maxDeadline);
    
        int jobCount = 0, totalProfit = 0;
        
        for(auto &job : jobs) {
            int d = job[1], p = job[0];
            int availableSlot = dsu.find(d);
            
            if (availableSlot > 0) {
                dsu.merge(availableSlot, availableSlot - 1);
                jobCount++;
                totalProfit += p;
            }
        }
        
        return {jobCount, totalProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends