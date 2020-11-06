#include <iostream>
#include<vector>
#include<cstdlib>
#include <ctime>
#include<fstream>
#include<iomanip>

using std::cout; using std::cin; using std::endl; using std::vector;using std::fixed;

//https://www.geeksforgeeks.org/merge-sort/

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r) {

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
//https://www.geeksforgeeks.org/insertion-sort/
/* Function to sort an array using insertion sort*/
void insertionSort(vector<int> &arr, int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  

int main()
{

    std::ofstream oss("data.txt");
    
    vector<int> data_merge;
    vector<int> data_insertion;
    int n;
    int delay=10000;
    for(n=5;n<=200;n++)
    {
        
        oss<<n<<" ";
        srand(7);
        std::clock_t start_time = std::clock();
        for(int j=0;j<delay;j++)
        {
            for(int i=0;i<n;i++)
            {
                int item=std::rand()%100;
                data_insertion.push_back(item);  
                
            }
        
            insertionSort(data_insertion, data_insertion.size());
        
            
            data_insertion.clear();
       
        }
        std::clock_t tot_time = std::clock() - start_time;
        double seconds=((double) tot_time) / (double) CLOCKS_PER_SEC;
      
        double result=seconds/(double) delay;
        oss<<fixed<<result<<" ";
        
       // srand(7);
        start_time = std::clock();
        for(int j=0;j<delay;j++)
        {
            for(int i=0;i<n;i++)
            {
                int item=std::rand()%100;
                data_merge.push_back(item);
                  
            }
            mergeSort(data_merge,0,data_merge.size()-1);
            data_merge.clear();
        }
        tot_time = std::clock() - start_time;
        seconds=((double) tot_time) / (double) CLOCKS_PER_SEC;
       
        result=seconds/(double) delay;
        oss<<fixed<<result<<endl;
        
    }
    oss.close();
    
}
