#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> merged;

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        } else {
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m) {
        merged.push_back(nums1[i]);
        i++;
    }

    while (j < n) {
        merged.push_back(nums2[j]);
        j++;
    }

    int total = m + n;
    if (total % 2 == 0) {
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    } else {
        return merged[total / 2];
    }
}

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;
    return 0;
}
