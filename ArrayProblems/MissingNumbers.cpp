//
//  MissingNumbers.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 11/10/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

/*
Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class MissingNumber{
public:
    static vector<int> getMissingNumbers(vector<int> &nums, int N)
    {
        vector<int> missingNums;
        
        //subtract 1 from all to make it in range
        for(int i=0;i<nums.size();i++)
        {
            nums[i]-=1;
        }
        
        //add N to every number's index
        for(int i=0;i<nums.size();i++)
        {
            nums[(nums[i]) % N] +=N;
        }
        //check which index has number still less than N, indicating they have been not encountered in the traversal
        //return the index + 1 as that index (which num = index + 1) denotes the missing num
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]) < N)
                missingNums.push_back(i+1);
        }
        
        return missingNums;
    }
    
    static void Test_getMissingNumbers()
    {
        vector<int> nums {4,3,2,7,8,2,3,1};
        int N = 8;
        vector<int> missingNums = getMissingNumbers(nums, N);
        cout<<"Missing numbers in range 1 to "<<N<<endl;
        for(int num: missingNums)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
};
