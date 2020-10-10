//
//  TwoRepeatingNumbers.hpp
//  ArrayProblems
//
//  Created by Yash Arora on 23/08/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef TwoRepeatingNumbers_hpp
#define TwoRepeatingNumbers_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class TwoRepeatingNumbers{
    
public:
    static pair<int,int> findTwoReapeatingNumbers(vector<int> &numbers,int range);
    static void TestTwoReapetingNumbers();
};

#endif /* TwoRepeatingNumbers_hpp */
