//
//  TrainsAndPlatforms.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 08/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "TrainsAndPlatforms.hpp"
#include <algorithm>
#include <iostream>

int TrainsAndPlatforms::findMinPlatforms(vector<int> &arr, vector<int> &dep)
{
    int numPlatforms =0;
    int minNumPlatforms =0;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    
    int arrSz = arr.size();
    int depSz = dep.size();
    int i=0,j=0;
    while(i < arrSz && j < depSz)
    {
        if(arr[i] <= dep[j])
        {
            numPlatforms++;
            i++;
        }
        else
        {
            numPlatforms--;
            j++;
        }
        minNumPlatforms =  std::max(minNumPlatforms,numPlatforms);
    }
   /* while(j < depSz)
    {
        numPlatforms--;
        j++;
    }*/
    
    return minNumPlatforms;
}

void TrainsAndPlatforms::TestfindMinPlatforms()
{
   vector<int> arr1 {900,940,950,1100,1500,1800};
   vector<int> dep1 {910,1200,1120,1130,1900,2000};
   
   vector<int> arr2 {900,940};
   vector<int> dep2 {910,1200};
   
   vector<int> arr3 {900};
   vector<int> dep3 {910};
   
   cout<<"Num of Min Platforms required: "<<TrainsAndPlatforms::findMinPlatforms(arr1, dep1)<<endl;
   cout<<"Num of Min Platforms required: "<<TrainsAndPlatforms::findMinPlatforms(arr2, dep2)<<endl;
   cout<<"Num of Min Platforms required: "<<TrainsAndPlatforms::findMinPlatforms(arr3, dep3)<<endl;
}
