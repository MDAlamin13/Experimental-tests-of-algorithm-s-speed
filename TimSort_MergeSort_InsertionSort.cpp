#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::vector;

// https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(vector<int> &arr, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

// https://www.geeksforgeeks.org/merge-sort/
void merge(vector<int> &arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (int i = 0; i < n1; i++) L[i] = arr[l + i];
  for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

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
void mergeSort(vector<int> &arr, int l, int r) {
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

void tim_Sort(vector<int> &arr, int l, int r, int k) {
  if ((l < r) && ((r - l + 1) <= k)) {
    insertionSort(arr, l, r);
  } else if (l < r) {
    int m = l + (r - l) / 2;

    tim_Sort(arr, l, m, k);
    tim_Sort(arr, m + 1, r, k);

    merge(arr, l, m, r);
  }
}

int main() {
  std::ofstream oss("data_tim_1500.txt");
  vector<int> data_tim;
  vector<int> data_merge;
  vector<int> data_insertion;
  int n = 1500;
  int delay = 10000;
  // srand(5);

  for (int k = 5; k <= 200; k += 5) {
    oss << k << " ";

    std::clock_t start_time = std::clock();
    for (int d = 0; d < delay; d++) {
      for (int i = 0; i < n; i++) {
        int item = std::rand() % 100;
        data_tim.push_back(item);
      }
      tim_Sort(data_tim, 0, data_tim.size() - 1, k);
      data_tim.clear();
    }
    std::clock_t tot_time = std::clock() - start_time;
    double seconds = ((double)tot_time) / (double)CLOCKS_PER_SEC;
    double result1 = seconds / (double)delay;

    std::clock_t start_time2 = std::clock();
    for (int d = 0; d < delay; d++) {
      for (int i = 0; i < n; i++) {
        int item = std::rand() % 100;
        data_merge.push_back(item);
      }
      mergeSort(data_merge, 0, data_merge.size() - 1);
      data_merge.clear();
    }
    std::clock_t tot_time2 = std::clock() - start_time2;
    double seconds2 = ((double)tot_time2) / (double)CLOCKS_PER_SEC;
    double result2 = seconds2 / (double)delay;

    std::clock_t start_time3 = std::clock();
    for (int d = 0; d < delay; d++) {
      for (int i = 0; i < n; i++) {
        int item = std::rand() % 100;
        data_insertion.push_back(item);
      }
      insertionSort(data_insertion, 0, data_insertion.size() - 1);
      data_insertion.clear();
    }
    std::clock_t tot_time3 = std::clock() - start_time3;
    double seconds3 = ((double)tot_time3) / (double)CLOCKS_PER_SEC;
    double result3 = seconds3 / (double)delay;

    oss << fixed << result1 << " " << result2 << " " << result3 << endl;
  }
  oss.close();
}
