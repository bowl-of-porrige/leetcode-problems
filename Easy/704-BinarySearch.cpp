#include<vector>
#include<iostream>

using namespace std;

// Problem Description:
//     Given an array of integers nums which is sorted in ascending order, 
//     and an integer target, write a function to search target in nums. 
//     If target exists, then return its index. Otherwise, return -1.
//     must write an algorithm with O(log n) runtime complexity.

// Solution: 
    // Given a sorted array. Retrieve the middle element of the array and compare 
    // againt the target value. If same return the middle index. In case if middle element
    // is bigger then the target, then search in the right half of the array.
    // Else search in the left half of the array (from )

// Performance:
//      Time complexity: O(log(n))
//      Space complexity: O(1)
// Approach 1 - recursion:

int BinarySearchRecursion(const vector<int> v, int leftInt, int rightInt, int num)
{
    if(rightInt >= leftInt) {
        int mid = leftInt + (rightInt - leftInt) / 2;
        if(v[mid] == num) { return mid; }
        else if(v[mid] < num) { return BinarySearchRecursion(v, mid + 1, rightInt, num); }
        else { return BinarySearchRecursion(v, leftInt, mid - 1 , num);}
    }

    return -1;
}

int searchRecursion(const vector<int>& nums, int target) {
    if(nums[0] > target || target > nums[nums.size() -1 ]) { return -1; }
    if(nums[0] == target) { return 0; }
    if(target == nums[nums.size() -1 ]) { return nums.size() -1; }
    return BinarySearchRecursion(nums, 0, nums.size() -1,target);
}

// Performance:
//      Time complexity: O(log(n))
//      Space complexity: O(1)
// Approach 2 - iteration:

int searchIteration(const vector<int>& nums, int target) {
    if(nums[0] > target || target > nums[nums.size() -1 ]) { return -1; }

    int rightInt = nums.size() - 1;
    int leftInt = 0;

    while(rightInt >= leftInt)
    {
        int mid = leftInt + (rightInt - leftInt) / 2;
        if(nums[mid] == target) { 
            return mid;
        }
        else if(target > nums[mid]) { 
            leftInt = mid + 1;
        }
        else { 
            rightInt = mid - 1;
        }
    }

    return -1;
}


int main()
{
    vector<int> v { -1,0,3,5,9,12};
    cout << searchIteration(v, 9) << endl;
}



