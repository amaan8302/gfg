//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    typedef pair<long long,int> p;
    int mostBooked(int n, vector<vector<int>> &meetings) {
        std::sort(meetings.begin(),meetings.end());
        priority_queue<p,vector<p>,greater<p>>usedRoom;
        priority_queue<int,vector<int>,greater<int>>availableRooms;
        vector<int>roomsUsedCount(n,0);
        for (int i = 0; i < n; ++i) 
            availableRooms.push(i);
        for(vector<int>&meet : meetings)
        {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            while(!usedRoom.empty() && usedRoom.top().first <= start)
            {
                int room = usedRoom.top().second;
                usedRoom.pop();
                availableRooms.push(room);
            }
            if(!availableRooms.empty())
            {
                int room = availableRooms.top();
                availableRooms.pop();
                usedRoom.push({(long long)start + duration, room});
                roomsUsedCount[room]++;
            }
            else {
                auto endTime = usedRoom.top().first;
                auto room = usedRoom.top().second;
                usedRoom.pop();
                usedRoom.push({endTime + duration, room});
                roomsUsedCount[room]++;
            }
        }
        int res = 0;
        for(int i = 1 ; i < n ; i++)
        {
            if(roomsUsedCount[i] > roomsUsedCount[res])
                res = i;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends