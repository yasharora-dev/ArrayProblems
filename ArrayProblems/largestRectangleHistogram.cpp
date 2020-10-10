//
//  largestRectangleHistogram.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 01/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "largestRectangleHistogram.hpp"
#include <stack>

int Histogram::getLargestRectangleInHistogram(vector<int> Histogram)
{
    int maxArea=0;
    int area=0;
    
    int currenBar=0;
    int currentIndex=0;
    
    stack<int> st;
    
    while(currentIndex < Histogram.size())
    {
        //if stack is empty means this is first number or smallest number
        // or if next bar is greater than previous bar so keep on going
        // store index as we need to find the length of bar contributing in rectangle
        if(st.empty() || Histogram[currentIndex] > Histogram[st.top()])
            st.push(currentIndex++);
        else
        {
            currenBar = st.top();
            st.pop();
            
            if(st.empty())
            {
                //as this is the smallest element
                area = Histogram[currenBar] * (currentIndex);
            }
            else
            {
                // find out the contribution of currentBar in the rectangle area
                // consider cuurent bar as smallest and find out smaller or equal element index in left and smaller index than current in right
                // right index - left index - 1 gives the no of bars in between left and right
                // - 1 is used to give num of bars in between left ruight
                // 12 - 8 has 9,10,11 i.e. 3 numbers, which is 12-8-1
                area = Histogram[currenBar] * (currentIndex - st.top() - 1 );
            }
            
            maxArea = max(area,maxArea);
        }
    }
    
    while(!st.empty())
    {
        currenBar = st.top();
        st.pop();
        
        if(st.empty())
        {
            area = Histogram[currenBar]* currentIndex;
        }
        else
        {
            area = Histogram[currenBar] * (currentIndex - st.top() -1);
        }
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
