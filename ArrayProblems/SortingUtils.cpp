//
//  QuickSort.cpp
//  ArrayProblems
//
//  Created by Yash Arora on 04/10/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//
/*
 https://www.geeksforgeeks.org/quick-sort/
 

 
 Quick sort, a pivot element is selected in each iteration
 and elements are rearranged such that elements less than pivot are re-arranged on left of pivot
 and elements greater than pivot are on right side of povit
 
 
 //and after each partiton recursively the array is again divided into left of pvit and right of pivot
 until left>=right
 
 this sorts each element
 
 //now in worst case its time complexity is O(n^2)
 but if randomized pivot is selcted than its O(nlogn)
 
 here use rand() function from algorithm
 it return a positive integer in range from o to 2^16
 and this can be mod with size of range i.e. end - start
 
 also srand(time(NULL)) to use systems internal clock as seed
 as seed is different sequence of random number generation will always be different
 seed is initial input to rand function which is used for reandom number generation
 
 
 ====================== ====================== ====================== ======================
 
 
  https://www.geeksforgeeks.org/merge-sort/
 
 
 
 */
#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class SortingUtils{
public:
    
    static int partition(int arr[],int start, int end)
    {
        int pivot = arr[end];
        int pIndex = start;
        
        
        for(int i=pIndex;i<end;i++)
        {
            if(arr[i] < pivot)
            {
                
                swap(arr[i],arr[pIndex]);
                pIndex++;
            }
        }
        
        swap(arr[pIndex],arr[end]);
        return pIndex;
    }
    static void quickSortUtil(int arr[],int start, int end)
    {
        if(start>=end)
            return;
        
        int pivotIndex = partition(arr,start,end);
        quickSortUtil(arr, start, pivotIndex-1);
        quickSortUtil(arr, pivotIndex+1, end);
    }
    static void quickSort(int arr[],int n)
    {
        quickSortUtil(arr, 0, n-1);
    }
    
   
    static int partition_randomized(int arr[],int start, int end)
    {
        srand(time(NULL));
        int random = start + (rand() % (end - start));
        swap(arr[random], arr[end]);
        return partition(arr, start,end);
    }
    static void quickSortUtil_randomized(int arr[],int start, int end)
    {
        if(start>=end)
            return;
        
        int pivotIndex = partition_randomized(arr,start,end);
        quickSortUtil_randomized(arr, start, pivotIndex-1);
        quickSortUtil_randomized(arr, pivotIndex+1, end);
    }
    static void quickSort_randomized(int arr[],int n)
    {
        quickSortUtil_randomized(arr, 0, n-1);
    }
    
    static void printArray(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    static void Test_QuickSort()
    {
        int arr[] = {7,2,1,6,8,5,3,4};
        int n = sizeof(arr)/sizeof(arr[0]);
        
        cout<<"Elements before quick sort:"<<endl;
        printArray(arr, n);
        
        quickSort(arr, n);
        
        cout<<"Elements after quick sort:"<<endl;
        printArray(arr, n);
        
    }
    
    static void Test_QuickSort_randomized()
    {
        int arr[] = {7,2,1,6,8,5,3,4};
        int n = sizeof(arr)/sizeof(arr[0]);
        
        cout<<"Elements before randomized quick sort:"<<endl;
        printArray(arr, n);
        
        quickSort_randomized(arr, n);
        
        cout<<"Elements after randomized quick sort:"<<endl;
        printArray(arr, n);
        
    }
    
    //simple function to merge two sorted arrays of range [left to mid] and [mid+1 to right]
    static void merge(int arr[],int left,int mid,int right)
    {
        // 7,2,1,6,8,5,3,4
        // so in case mid=3
        //divide the left half including mid and right excluding mid
        // l = 3 - 0 + 1 = 4
        // r = 7 - 3 = 4
        
        
        int l = mid - left +1;
        int r = right -mid;
        

        int L[l];
        int R[r];
        

        for(int i=0;i<l;i++)
            L[i]=arr[i+left];

        for(int i=0;i<r;i++)
            R[i]=arr[i+mid+1];
        
        int i=0,j=0,k=left;
        while(i<l && j<r)
        {
            if(L[i]<R[j])
            {
                arr[k]=L[i];
                i++;
            }
            else
            {
                arr[k]=R[j];
                j++;
            }
            
            k++;
        }
        
        while(i<l)
        {
            arr[k]=L[i];
            i++;
            k++;
        }
        
        while(j<r)
        {
            arr[k]=R[j];
            j++;
            k++;
        }
        
    }
    
    
    static void mergeSortUtil(int arr[],int left, int right)
    {
        
        //dvidie the array into two halves until only two elements exists
        //then merge both and thn merge those recursively
        if(left < right)
        {
            int mid = left + (right-left)/2; //avoid overflow
            mergeSortUtil(arr, left,mid);
            mergeSortUtil(arr, mid+1, right);
            
            //merge when two elements considering whichever is smaller in O(n)
            //this will be called logn times
            merge(arr,left,mid,right);
        }
        
    }
    
    
    static void mergeSort(int arr[],int n)
    {
        mergeSortUtil(arr,0,n-1);
    }
    static void Test_MergeSort()
    {
        int arr[] = {7,2,1,6,8,5,3,4};
        int n = sizeof(arr)/sizeof(arr[0]);
        
        cout<<"Elements before merge sort:"<<endl;
        printArray(arr, n);
        
        mergeSort(arr, n);
        
        cout<<"Elements after merge sort:"<<endl;
        printArray(arr, n);
        
    }
    
    
};
