//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void merge(vector<int> &arr, int s, int e)
    {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        int *first = new int[len1];
        int *second = new int[len2];
        int mainArrayIndex = s;
        for (int i = 0; i < len1; i++)
            first[i] = arr[mainArrayIndex++];
        for (int i = 0; i < len2; i++)
            second[i] = arr[mainArrayIndex++];
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;
        while (index1 < len1 && index2 < len2)
        {
            if (first[index1] < second[index2])
                arr[mainArrayIndex++] = first[index1++];
            else
                arr[mainArrayIndex++] = second[index2++];
        }
        while (index1 < len1)
            arr[mainArrayIndex++] = first[index1++];
        while (index2 < len2)
            arr[mainArrayIndex++] = second[index2++];
        delete[] first;
        delete[] second;
    }
    void mergeSort(vector<int> &arr, int s, int e) {
        if (s >= e)
            return;
        int mid = s + (e - s) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, e);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends