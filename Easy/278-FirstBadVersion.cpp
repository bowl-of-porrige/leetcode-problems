#include<vector>
#include <algorithm> // std::find
#include<iostream> 

using namespace std;

// Problem Description:
    // You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
    // Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
    // You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

int lastBad = 0;

bool isBadVersion(int number) {
    return number >= lastBad;
}

// Greedy approach - Iterate over all element from 1 to n to find 
// Performance:
//      Time complexity: O(n)
//      Space complexity: O(1)
// Approach 1 - recursion:

int firstBadVersionGreedy(int n) {
    // return immedietly if n is outlier 
    if(isBadVersion(1)) return 1;
    if(!isBadVersion(n - 1)) return n;
    int firstBad = n / 2 + 1;

    while(firstBad >= 1 && firstBad <= n - 1) {
        if(!isBadVersion(firstBad) && isBadVersion(firstBad + 1) ) {  return firstBad + 1; }
        else if(isBadVersion(firstBad) && !isBadVersion(firstBad - 1)) {  return firstBad; }
        
        firstBad = firstBad / 2 + 1;
    }

    return firstBad;
}

// Binary search approach 
// Think about it as a problem where given array of size n find an element x where 
// x is bad and x - 1 is not bad or x + 1 is bad a x is not bad 
// Greedy approach - Iterate over all element from 1 to n to find 
// The problem with this problem is that it frequently calls isBadVersion

// Performance:
//      Time complexity: O(log(n))
//      Space complexity: O(1)
int firstBadVersionBinarySearch(int n) {
        if (n == 1 || isBadVersion(1)) return 1;
        if(!isBadVersion(n - 1)) return n;
    
        int firstBad = 0;
        int leftB = 1;
        int rightB = n;
        int mid = leftB + (rightB - leftB / 2);
    
        while(firstBad == 0 && (mid != 0 || mid != n))
        {
            if(isBadVersion(mid)) {
                if(!isBadVersion(mid - 1)) {
                    firstBad = mid;
                    break;
                }
                
                rightB = mid - 1;
            }
            else {
                if(isBadVersion(mid + 1)) {
                    firstBad = mid + 1;
                    break;
                }
                
                leftB = mid + 1;
            }
            mid = leftB + (rightB - leftB / 2);
        }
    
    return firstBad;
}

// Optimized Binary search approach 
// To minimize call to isBadVersion we will call isBadVersion only one time in each iteration
// It will not return immediately instead it will execute until lowerBound >= rightBound is encountered
// As oppose to traditional version of binarySearh right = mid if mid is Bad beacuse the elements right to 
// bad element is always bad 

// Performance:
//      Time complexity: O(log(n))
//      Space complexity: O(1)
int firstBadVersionOptimizedBinaySearch(int n) {
    if (n == 1 || isBadVersion(1)) return 1;
    if(!isBadVersion(n - 1)) return n;

    int leftB = 1, rightB = n, mid;

    while(rightB > leftB)
    {
        mid = leftB + (rightB - leftB) /2;
        if(isBadVersion(mid)) {            
            rightB = mid;
        }
        else {
            leftB = mid + 1;
        }
    }
    
    return leftB;
}


int main() {
    lastBad = 12333;
    cout << firstBadVersionOptimizedBinaySearch(22222) << endl;
    
    return 0;
}