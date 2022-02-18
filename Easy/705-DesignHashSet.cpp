#include<vector>
#include <algorithm> // std::find
#include<iostream> 

using namespace std;

// Problem Description:
// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

// Vector implementation: 
class MyHashSet {
private: 
    vector<int> v;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if (!contains(key)) { 
            v.push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)) {
            v.erase(find(v.begin(), v.end(), key));
        }
    }
    
    bool contains(int key) {
        if (find(v.begin(), v.end(), key) != v.end()) { // up to O(n)
            return true;
        }
        return false;
    }
};

int main() {
    MyHashSet myHashSet;
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(1) << "\n"; // return True
    cout << myHashSet.contains(3) << "\n"; // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(2) << "\n"; // return True
    myHashSet.remove(2);   // set = [1]
    cout << myHashSet.contains(2) << "\n"; // return False, (already removed)
}



