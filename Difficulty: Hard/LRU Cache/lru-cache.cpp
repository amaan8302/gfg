//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        
        auto it = map[key];
        int value = it->second;
        
        cache.erase(it);
        cache.push_front({key, value});
        
        map[key] = cache.begin();
        
        return value;
    }
    
    void set(int key, int value) {
        if (map.find(key) != map.end()) {
            auto it = map[key];
            cache.erase(it);
        }
        else if (cache.size() >= capacity) {
            int lru_key = cache.back().first;
            map.erase(lru_key);
            cache.pop_back();
        }
        
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends