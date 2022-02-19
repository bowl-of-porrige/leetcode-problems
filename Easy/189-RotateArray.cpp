#include<vector>
#include <algorithm> // std::copy 
#include<iostream> 

using namespace std;

// Problem description: 
// Given an array, rotate the array to the right by k steps, where k is non-negative.

void print(const vector<int>&v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

// Iterative approach: 
// return immediately if size of the vector is 1 (no need to rotate) or 
// the number of rotation is equals to the size of the vector as this will give a same vector after rotation
// otherwise select k elements starting from size - k pos and then select the rest of the elements
// starting from 0 to size -k -> [0, size - k )

// Performance
//      Time complexity: O(n)
//      Space complexity: O(n)

void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    if(size != 1 && size != k && k != 0 ) {
        if( k > size) { k = k % size; }
        vector<int> temp(size);
        int fromIndex = size - k;

        for(int i = 0; i < size; ++i) {
            temp[i] = nums[fromIndex];
            ++fromIndex;
            if(fromIndex == size) {
                fromIndex = 0; 
            }
        }

        nums = temp; 
    }
}

// implementation with STL copy method

void rotate2(vector<int>& nums, int k) { 
    int size = nums.size();

    if(size != 1 && size != k && k != 0 ) {
         if( k > size) { k = k % size; }
        vector<int> temp(size); 
        copy(nums.begin() + (size - k), nums.end(), temp.begin());
        copy(nums.begin() , nums.begin() + (size - k), temp.begin() + k);

        nums = temp; 
    }
}

int main() {
    vector<int> t1 {1,2,3,4,5,6,7};
    vector<int> t2 {-1,-100,3,99};
    vector<int> t3 {-1,-100,3,99};
    vector<int> t4 {-1};

    rotate2(t1, 3);
    rotate2(t2, 2);
    rotate2(t3, 4);
    rotate2(t4, 1);

    // rotate(t1, 3);
    // rotate(t2, 2);
    // rotate(t3, 4);
    // rotate(t4, 1);

    print(t1);
    print(t2);
    print(t3);
    print(t4);

    return 0; 
}