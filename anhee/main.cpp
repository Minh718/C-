#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x)
{
while(left<=right){
int mid = left + ((right-left)/2);
cout << "We traverse on index: " << mid << endl;
if(arr[mid]==x) return mid;
else if(arr[mid]<x) left = mid +1;
else right = mid - 1;
}
return -1;
}
int main(){
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int x = 10;
int n = sizeof(arr) / sizeof(arr[0]);
int result = binarySearch(arr, 0, n - 1, x);
(result == -1) ? cout << "Element is not present in array"
                : cout << "Element is present at index " << result;
}
