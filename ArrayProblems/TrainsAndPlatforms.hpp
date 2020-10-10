//
//  TrainsAndPlatforms.hpp
//  ArrayProblems
//
//  Created by Yash Arora on 08/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.


//--------------------------------------------------------------------------
//	Minimum Number of Platforms Required for a Railway/Bus Station
//--------------------------------------------------------------------------


/*  Given arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
    We are given two arrays which represent arrival and departure times of trains that stop. */

/*  Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
    dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
    Output: 3
    Explantion: There are at-most three trains at a time (time between 11:00 to 11:20)

    Input: arr[] = {9:00, 9:40}
    dep[] = {9:10, 12:00}
    Output: 1
    Explantion: Only one platform is needed. */

#ifndef TrainsAndPlatforms_hpp
#define TrainsAndPlatforms_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class TrainsAndPlatforms{
    
public:
    static int findMinPlatforms(vector<int> &arr,vector<int> &dep);
    static void TestfindMinPlatforms();
};
#endif /* TrainsAndPlatforms_hpp */
