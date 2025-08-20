#include<iostream>
#include<vector>
#include <climits>
using namespace std;


// Not Optimal Solution 
// Time Complexity: O(n1 + n2)
double findMedianSortedArraysNotOptimal(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int tsize = n1 + n2;
    int i1 = tsize/2 - 1, i2 = tsize/2;
    int j1 = INT_MAX, j2 = INT_MAX;
    int i = 0, j = 0, index = 0;

    while(i < n1 && j < n2){
        if(nums1[i] < nums2[j]){
            if(index == i1) j1 = nums1[i];
            if(index == i2) j2 = nums1[i];
            i++;
        }else{
            if(index == i1) j1 = nums2[j];
            if(index == i2) j2 = nums2[j];
            j++;
        }
        index++;
    }        
    while(i < n1){
        if(index == i1) j1 = nums1[i];
        if(index == i2) j2 = nums1[i];
        i++;
        index++;
    }
    while(j < n2){
        if(index == i1) j1 = nums2[j];
        if(index == i2) j2 = nums2[j];
        j++;
        index++;
    }
    return tsize%2 == 0 ? (j1 + j2)/2.0 : j2;
    }


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int tsize = n1 + n2;
        int left = 0, right = n1;
        int division = (n1 + n2 + 1)/2;

        while(left <= right){
            int mid1 = (right + left)/2;
            int mid2 = division - mid1;
            int r1 = INT_MAX, r2 = INT_MAX, l1 = INT_MIN, l2 = INT_MIN;
            if(mid1 > 0) l1 = nums1[mid1 - 1];
            if(mid2 > 0) l2 = nums2[mid2 - 1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(l1 <= r2 && l2 <=r1){
                if(tsize % 2 == 0) return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                else return (double)max(l1, l2);
            }
            else if(l1 > r2){
                right = mid1 - 1;
            }
            else{
                left = mid1 + 1;
            }
        }
        return 0.0;
    }


int main(){
    vector<int> nums1 = {1, 22, 33, 44, 55, 66, 77, 88, 99};
    vector<int> nums2 = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    double resultNotOptimal = findMedianSortedArraysNotOptimal(nums1, nums2);
    double result = findMedianSortedArrays(nums1, nums2);
    cout << "Median of the two sorted arrays not optimal: " << resultNotOptimal << endl;
    cout << "Median of the two sorted arrays: " << result << endl;
    return 0;
}