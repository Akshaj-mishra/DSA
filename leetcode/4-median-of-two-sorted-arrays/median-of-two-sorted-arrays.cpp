#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;

        while (low <= high) {

            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxLeftX =
                (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];

            int minRightX =
                (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY =
                (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

            int minRightY =
                (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Correct partition found
            if (maxLeftX <= minRightY &&
                maxLeftY <= minRightX) {

                // Even total length
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) +
                            min(minRightX, minRightY)) / 2.0;
                }

                // Odd total length
                return max(maxLeftX, maxLeftY);
            }

            // Move left
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }

            // Move right
            else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};