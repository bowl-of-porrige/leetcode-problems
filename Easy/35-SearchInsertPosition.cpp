#include<vector>
#include <algorithm> // std::find
#include<iostream> 

using namespace std;

// Problem Description:
//   Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. 
//   You must write an algorithm with O(log n) runtime complexity.

// Binary Search approach 
// Use binary search to find the pisition of the element 
// if not found then if element which was called last element stored at right index should be comapared with target
// if last element > target return right index else right + 1 or return left 
// Performance
//      Time complexity: O(log(n))
//      Space complexity: O(1)
int searchInsert(const vector<int>& nums, int target) {
    if(target < nums[0]) { return 0; }
    if (target > nums[nums.size() -1]) { return nums.size() - 1;}

    int left = 0;
    int mid = 0;
    int right = nums.size() - 1;

    while(right >= left) {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) { return mid; }
        else if(target > nums[mid]) { 
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // Either : 
    // if(nums[right] > target) { return right; }
    // return right + 1;

    return left;
}

int main() {
    vector<int> t1 {1,3,5,6};

    cout << searchInsert(t1, 5) << endl;
    cout << searchInsert(t1, 2) << endl;
    cout << searchInsert(t1, 0) << endl;
    cout << searchInsert(t1, 7) << endl;
    cout << searchInsert(t1, 4) << endl;

    return 0;
}