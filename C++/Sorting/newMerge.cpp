#include <iostream>

void print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << "array[" << i << "]: " << arr[i] << std::endl;
    }
}

void merge(int *array, int first, int mid, int last) {
    int tmp[last + 1];
    int i = first;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= last) {
        if (array[i] <= array[j]) {
            tmp[k++] = array[i++];
        }
        else {
            tmp[k++] = array[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = array[i++];
    }

    while (j <= last) {
        tmp[k++] = array[j++];
    }

    k--;
    while (k >= 0) {
        array[k + first] = tmp[k];
        k--;
    }
}

void mergeSort(int *arr, int first, int last) {
    int mid = 0;
    if(first < last) {
        mid = (first + last)/2;

        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);

        merge(arr, first, mid, last);
    }
}

int main() {
    int arr[] = {5, 6, 9, 1,  2, 3, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0 , size);
    print(arr, size);
    std::cout << size;
}