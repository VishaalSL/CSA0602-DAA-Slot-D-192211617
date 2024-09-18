#include <stdio.h>
#include <limits.h>
// Function to find maximum and minimum using divide and conquer
void findMaxMin(int arr[], int left, int right, int *max, int *min) {
 if (left == right) {
 // Base case: only one element
 *max = arr[left];
 *min = arr[left];
 } else if (right == left + 1) {
 // Base case: two elements
 if (arr[left] > arr[right]) {
 *max = arr[left];
 *min = arr[right];
 } else {
 *max = arr[right];
 *min = arr[left];
 }
 } else {
 // Divide
 int mid = left + (right - left) / 2;
 int leftMax, leftMin, rightMax, rightMin;
 // Conquer
 findMaxMin(arr, left, mid, &leftMax, &leftMin);
 findMaxMin(arr, mid + 1, right, &rightMax, &rightMin);
 // Combine
 *max = (leftMax > rightMax) ? leftMax : rightMax;
 *min = (leftMin < rightMin) ? leftMin : rightMin;
 }
}
int main() {
 int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
 int size = sizeof(arr) / sizeof(arr[0]);
 int max, min;
 // Find maximum and minimum
 findMaxMin(arr, 0, size - 1, &max, &min);
 // Output: Maximum and Minimum values
 printf("Maximum value: %d\n", max);
 printf("Minimum value: %d\n", min);
 return 0;
}
