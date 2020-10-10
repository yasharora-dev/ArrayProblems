//
//  MedianSortedArray.hpp
//  ArrayProblems
//
//  Created by Yash Arora on 25/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef MedianSortedArray_hpp
#define MedianSortedArray_hpp

#include <stdio.h>
#include <vector>

class MedianSortedArray{
public:
    static double findMedianInSortedArrayDiffSize(std::vector<int> &arr1,std::vector<int> &arr2);
    static double calculateMedian(int leftX, int leftY, int rightX, int rightY, bool isOdd);
    static double findMedianInSortedArrayUtil(std::vector<int> &arr1, std::vector<int> &arr2);
    static void Test_findMedianInSortedArrayDiffSize();
};
#endif /* MedianSortedArray_hpp */
