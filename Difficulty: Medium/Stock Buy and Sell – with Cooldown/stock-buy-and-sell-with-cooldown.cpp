//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) 
    {
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int i = n-1 ; i >=0 ; i--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                long long profit;
                if(buy)
                {
                    long long buyKaro = -prices[i] + curr[buy-1];
                    long long excl = curr[buy];
                    profit = max(buyKaro , excl);
                }    
                else
                {
                    long long sellKaro = prices[i] + next[buy+1];
                    long long excl = curr[buy];
                    profit = max(sellKaro , excl);
                }
                prev[buy] = profit;
                next = curr;
                curr=prev;
            }
        }
        return curr[1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
