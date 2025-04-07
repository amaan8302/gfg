#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        unordered_map<int, int> freq;

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            freq[A[i]]++;
        }

        vector<pair<int, int>> sortedElements;
        for (auto& it : freq) {
            sortedElements.push_back({it.first, it.second});
        }

        sort(sortedElements.begin(), sortedElements.end(), compare);

        vector<int> result;
        for (auto& it : sortedElements) {
            for (int i = 0; i < it.second; ++i) {
                result.push_back(it.first);
            }
        }

        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
