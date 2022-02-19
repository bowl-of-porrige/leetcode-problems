#include<vector>
#include <algorithm> // std::find //std::reverse
#include<iostream> 

using namespace std;

// Problem description: 
    // Given an integer array nums sorted in non-decreasing order, 
    // return an array of the squares of each number sorted in non-decreasing order.

// Brute force approach: 
// Iterate overall elements sequere them and sort them 

// Performance
//      Time complexity: 0(N*log2(N)) + O(N)
//      Space complexity: O(n)

void print(const vector<int>&v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

vector<int> sortedSquaresBruteForce(vector<int>& nums) {
    bool hasNoNegative = nums[0] >= 0;
    
    for (int i = 0; i < nums.size(); ++i)
    {
        nums[i] = nums[i] * nums[i];
    }

    if (!hasNoNegative) {
        sort(nums.begin(), nums.end());
    }

    return nums; 
}

// Iterative approach: 
// Given a vector of size n then the upper bound of the vector will be n - 1 and lower bound 0
// Compare the square of the element at lower bound and upper bound (as the array might have negative elements
// at beginning of the array) 
// Given the element A is the sqaure of the element at upper bound and B at lower bound insert 
// A at beginning of the vector and shift the upperBound pointer to right otherwise insert B at beginning and
// shift the left bound pointer to right.
// Repeat until left pointer >  right pointer 
// This will ensure that the resulting vector is at asceding order as the biggest element is always inserted first
// The  problem with this solution is that it always performs a right shift of a vector if 
// an element is inserted at front

// Performance
//      Time complexity: O(N) + O(1 + M) where m is the number of element shifted to the right when insert front is performed
//      Space complexity: O(n)
vector<int> iterativeSortedSquares(const vector<int>& nums) {
    int upperBound = nums.size() - 1;
    int lowerBound = 0; 
    vector<int> squaredNums;

    while(upperBound >= lowerBound) {
        int A = nums[upperBound] * nums[upperBound];
        int B = nums[lowerBound] * nums[lowerBound];

        if(A > B) {
            squaredNums.insert(squaredNums.begin(), A);
            --upperBound;
        }
        else {
            squaredNums.insert(squaredNums.begin(),B);
            ++lowerBound;
        }

    }

    return squaredNums; 
}

// Optimazation of Iterative approach 
// Insted of insert at front. Use push back which takes O(1) runtime. 
// This will give a sorted vector in non-ascending order(decreasing order). 
// Reverse the vector using stl method reverese(O(n))

// Performance
//      Time complexity: O(n) + O(n) 
//      Space complexity: O(n)

vector<int> iterativeSortedSquares2(const vector<int>& nums) {
    int upperBound = nums.size() - 1;
    int lowerBound = 0; 
    vector<int> squaredNums;

    while(upperBound >= lowerBound) {
        int A = nums[upperBound] * nums[upperBound];
        int B = nums[lowerBound] * nums[lowerBound];

        if(A > B) {
            squaredNums.push_back(A);
            --upperBound;
        }
        else {
            squaredNums.push_back(B);
            ++lowerBound;
        }

    }

    reverse(squaredNums.begin(), squaredNums.end());

    return squaredNums; 
}

// Final optimazation of iterative approach
// Use a counter to record the order of the squared numbers in the vector
// Because the vector is already sorted then if it contains non negative integers then 
// return immediately with square of each number in the vector (As never the case when squared of 
// of element at index i - 1 is bigger then squared of a num at i)
// If it contains negative integers then it might be the case when (i - 1)^2 > i ^2 as 
// square of the negative num is always postitve. 
// In this case comapre the square of an element at lower bound and uppperBound and set it 
// to a position indicated by the couter and decrease the counter. 
// As the counter set as size - 1 of the vector it will always make sure that the bigger element is
// set to a pos higher then smaller element
vector<int> sortedSquares(vector<int>& nums) {

    if(nums[0] >= 0) {
        for(int i = 0; i < nums.size(); ++ i) {
            nums[i] *= nums[i];
        }

        return nums;
    }

    int counter = nums.size() - 1;
    vector<int> squaredNums(counter + 1);
    int upperBound = counter;
    int lowerBound = 0; 

    while(upperBound >= lowerBound) {
        int A = nums[upperBound] * nums[upperBound];
        int B = nums[lowerBound] * nums[lowerBound];

        if(A > B) {
            squaredNums[counter] = A;
            --upperBound;
        }
        else {
            squaredNums[counter] = B;
            ++lowerBound;
        }

        --counter;
    }

    return squaredNums; 
}

int main() {
    vector<int> nums1 { -7,-3,2,3,11 };
    vector<int> nums2 { -4,-1,0,3,10 };
    vector<int> nums3 { 0,3,10 };
    vector<int> nums4 { 1 };
    vector<int> nums5 { -5,-4,-2, -1 };

    print(sortedSquares(nums1));
    print(sortedSquares(nums2));
    print(sortedSquares(nums3));
    print(sortedSquares(nums4));
    print(sortedSquares(nums5));

    return 0;
}