#include <iostream>
#include <vector>
#include <unistd.h> // For sleep (not recommended for production)

using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
      // Print the swapped elements and a delay for animation effect
      cout << "Swapping: " << arr[i] << " and " << arr[j] << endl;
      sleep(1);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  // Print the final swap after partition
  cout << "Swapping: " << arr[i + 1] << " and " << arr[high] << endl;
  sleep(1);
  return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  vector<int> arr = {8, 7, 2, 1, 0, 9, 6};
  int n = arr.size();

  cout << "Unsorted array: ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

