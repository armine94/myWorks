#include <iostream>

void print(int *arr, int n) {
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << "\t";
    }

    std::cout << std::endl;
}
void quicksort(int* arr, int low, int high) {
    int i, j, tmp, pivot;

    if (low < high) {
        pivot = low; //pivot
        i = low;
        j = high;

        while (i < j) {

            while (arr[i] <= arr[pivot] && i <= high) {
                i++;
            }

            while (arr[j] > arr[pivot] && j >= low) {
                j--;
            }

            // if i < j, swap the elements in locations i & j
            if (i < j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        // when i >= j, it means the j-th position is the correct position of the pivot element,
        // so swap the pivot element with the element in the j-th position
        tmp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = tmp;

        //repeat quicksort for the two sub-arrays, one to the left of j
        // and the one to the right of j
        quicksort(arr, 0, j-1);
        quicksort(arr, j+1, high);
    }
}

int main() {
    int arr[] = {25, 7, 85, 16, 41, 15, 9, 32, 2, 88};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Array before sort: ";
    print(arr, n); // 25 7 85 16 41 15 9 32 2 88
    quicksort(arr, 0, n-1);
    std::cout << "Array after sort:  ";
    print(arr, n); // 2 7 9 15 16 25 32 41 85 88

    return 0;
}