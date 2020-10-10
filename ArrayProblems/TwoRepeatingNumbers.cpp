//
//  TwoRepeatingNumbers.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 23/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "TwoRepeatingNumbers.hpp"
#include <iostream>

using namespace std;

//Steps
// XOR all numbers with 1 to N and u will get X^Y
// find the set bits lets say rightmost set bit and XOR all numbers in array and range 1 to N
// This will result in either X and Y and from that you can get other number
pair<int,int> TwoRepeatingNumbers::findTwoReapeatingNumbers(vector<int> &numbers,int range)
{
    int X,Y;
    int len = numbers.size();
    int XOR = numbers[0];
    for(int index=1;index<len;index++)
        XOR ^= numbers[index];

    for(int rangeIndex =1; rangeIndex <= range;rangeIndex++)
        XOR ^= rangeIndex;
    
    //get rightmost set bit
    // XOR -1 toggles right most set bit to 0
    // ~ (XOR - 1) this is negation of set bit and X & ~ X-1 will give the bit which was unset in X-1
    int rightmost_set_bit = XOR & ~(XOR-1);
    int XOR_setbits=0;
    
    //check if rightmost_set_bit is set or not in number by  X & (1 << rightmost_set_bit-1)) is 1
    for(int index=0;index<len;index++)
    {
        if(numbers[index] & rightmost_set_bit)
            XOR_setbits ^= numbers[index];
    }
    
    for(int num=1;num<=range;num++)
    {
        if(num & rightmost_set_bit)
            XOR_setbits ^= num;
    }
    
    X = XOR_setbits;
    Y = XOR ^ X;
    
    return make_pair(X, Y);
}


void TwoRepeatingNumbers::TestTwoReapetingNumbers()
{
    vector<int> numbers {4,1,5,5,2,3,1};
    int range = 5;
    
    std::pair<int,int> twoNumbers = findTwoReapeatingNumbers(numbers,range);
    std::cout<<"repeating numbers are: "<<twoNumbers.first<<" and "<<twoNumbers.second<<std::endl;
}
