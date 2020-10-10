//
//  MedianSortedArray.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 25/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "MedianSortedArray.hpp"
#include <iostream>

using namespace std;

double MedianSortedArray::calculateMedian(int leftX, int leftY, int rightX, int rightY, bool isOdd)
{
    return (isOdd ? (max(leftX,leftY)): ((max(leftX,leftY) + min(rightX,rightY))/2.0) );
    
}

double MedianSortedArray::findMedianInSortedArrayUtil(vector<int> &arr1, vector<int> &arr2)
{
    double median=INT_MIN;
    int len1 = arr1.size();
    int len2 = arr2.size();
    
    //for binary search
    int st=0;
    int end = len1-1;
    int partX;
    int partY;
    
    int partitionSize = (len1+len2+1)/2;
    
    while(st<=end)
    {
        //if arr1 left half is <= arr2 right half and arr2 left half is <= arr1 right half then we have a our median
        partX = st + (end -st)/2;
        partY = partitionSize - partX;
        int arr1MinLeft = partX > 0 ? arr1[partX-1] : INT_MIN;
        int arr1MaxRight = partX >= len1 ? INT_MAX : arr1[partX];
        int arr2MinLeft = partY > 0 ? arr2[partY-1]: INT_MIN;
        int arr2MaxRight = partY >= len2 ? INT_MAX : arr2[partY];
        bool isOdd = !((len1+len2)%2==0);
        if(arr1MinLeft <= arr2MaxRight && arr2MinLeft <= arr1MaxRight)
            return calculateMedian(arr1MinLeft,arr2MinLeft,arr1MaxRight,arr2MaxRight,isOdd);
        else if(arr1MinLeft > arr2MaxRight)
            end = partX-1;
        else
            st = partX+1;
    }
    
    return median;
}

double MedianSortedArray::findMedianInSortedArrayDiffSize(vector<int> &arr1, vector<int> &arr2)
{
    int len1 = arr1.size();
    int len2 = arr2.size();
    
    //perform binary search on shorter array
    double median;
    if(len1<len2)
        median = findMedianInSortedArrayUtil(arr1,arr2);
    else
        median = findMedianInSortedArrayUtil(arr2,arr1);
    
    return median;
}

void MedianSortedArray::Test_findMedianInSortedArrayDiffSize()
{
    vector<int> arr1 {23,26,31,25};
    vector<int> arr2 {3,5,7,9,11,16};
    
    cout<<"Median of two sorted arrays of diff sizes is: "<<findMedianInSortedArrayDiffSize(arr1,arr2)<<endl;
}
