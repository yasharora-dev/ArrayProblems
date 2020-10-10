//
//  NutsAndBoltsProblem.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 04/10/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

/*
 https://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem/
 
 https://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem-set-2-hashmap/
 
 
 Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.
 Constraint: Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
 Other way of asking this problem is, given a box with locks and keys where one lock can be opened by one key in the box. We need to match the pair.
 
 Nuts represented as array of character
 char nuts[] = {‘@’, ‘#’, ‘$’, ‘%’, ‘^’, ‘&’}
 Bolts represented as array of character
 char bolts[] = {‘$’, ‘%’, ‘&’, ‘^’, ‘@’, ‘#’}
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>




using namespace std;

class NutsAndBoltsProblem{
public:
    static void printArray(char arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    static int partition(char arr[],int start,int end, char pivot )
    {
        /*int pivotIndexofpair2;
        for(int i=start;i<=end;i++)
        {
            if(pivot==arr[i])
                pivotIndexofpair2 = i;
                
        }
        
        swap(arr[pivotIndexofpair2],arr[end]);*/
        
        int pivotIndex = start;
        
        for(int i=start;i<end;i++)
        {
            if(arr[i] < pivot)
            {
                swap(arr[i],arr[pivotIndex]);
                pivotIndex++;
            }
            else if(arr[i]== pivot)
            {
                swap(arr[i],arr[end]);
                i--;
            }
            
         
        }
        
        swap(arr[pivotIndex],arr[end]);
        
        return pivotIndex;
        
    }
    
    //match pairs of nuts and bolts or pairs of locks and keys
    static void matchPairs(char nuts[], char bolts[],int st, int end)
    {
        if(st < end)
        {
            int pivotIndex = partition(nuts, st, end, bolts[end]);
            
            partition(bolts, st, end, nuts[pivotIndex]);
            
            matchPairs(nuts, bolts, st, pivotIndex-1);
            matchPairs(nuts, bolts, pivotIndex+1, end);
        }
    }
    
    
    
    
    static void Test_NutsAndBoltsMatching()
    {
        char nuts[] = {'@', '#', '$', '%', '^', '&'};
        char bolts[] = {'$', '%', '&', '^', '@', '#'};
        
        int n = sizeof(nuts)/sizeof(nuts[0]);
        
        matchPairs(nuts, bolts, 0, n);
        
        printArray(nuts, n);
        printArray(bolts, n);
        
    
    }
    
    static void matchPair_map(char nuts[], char bolts[],  int n)
    {
        unordered_map<char,int> hash;
        
        for(int i=0;i<n;i++)
            hash[nuts[i]]=i;
        
        for(int i=0;i<n;i++)
        {
            if(hash.find(bolts[i])!=hash.end())
            {
                nuts[i]=bolts[i];
            }
        }
        
        // print the result
           cout << "matched nuts and bolts are-" << endl;
           for (int i = 0; i < n; i++)
               cout << nuts[i] << " ";
           cout << endl;
           for (int i = 0; i < n; i++)
               cout << bolts[i] << " ";
        
    }
    
   /* static void Test_NutsAndBoltsMatching_Map()
    {
        char nuts[] = {'@', '#', '$', '%', '^', '&'};
        char bolts[] = {'$', '%', '&', '^', '@', '#'};
        
        int n = sizeof(nuts)/sizeof(nuts[0]);
        
        matchPair_map(nuts, bolts, n);
    
    }*/
    
};
