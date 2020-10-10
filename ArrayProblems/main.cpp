//
//  main.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 08/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <iostream>
#include <vector>
#include "TrainsAndPlatforms.hpp"
#include "TwoRepeatingNumbers.hpp"
#include "MedianSortedArray.hpp"
#include "largestRectangleHistogram.hpp"
#include "SortingUtils.cpp"
#include "NutsAndBoltsProblem.cpp"
#include "MissingNumbers.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //Minimum Number of Platforms Required for a Railway/Bus Station
    TrainsAndPlatforms::TestfindMinPlatforms();
    TwoRepeatingNumbers::TestTwoReapetingNumbers();
    
    MedianSortedArray::Test_findMedianInSortedArrayDiffSize();
    vector<int> Histogram{2,1,2};
    
    cout<<"Max rectangular are in histogram is: "<< Histogram::getLargestRectangleInHistogram(Histogram)<<endl;
    
    SortingUtils::Test_QuickSort();
    
    SortingUtils::Test_QuickSort_randomized();
    
    SortingUtils::Test_MergeSort();
    
    //NutsAndBoltsProblem::Test_NutsAndBoltsMatching();
    
    //NutsAndBoltsProblem::Test_NutsAndBoltsMatching_Map();
    
    MissingNumber::Test_getMissingNumbers();
    return 0;
}
