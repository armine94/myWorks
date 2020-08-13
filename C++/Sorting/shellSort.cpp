#include <iostream>

void print(int *arr, int n) {
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << "\t";
    }

    std::cout << std::endl;
}

void shellsort(int *arr, int n)
{
    int k, i, j, temp;

    for (k = n / 2; k > 0; k /= 2) {
        for (i = k; i < n; i++) {
            for (j = i - k; j >= 0 && arr[j] > arr[j + k]; j -= k) {
                temp = arr[j];
                arr[j] = arr[j + k];
                arr[j + k] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {14, 84, 11, 32, 25};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Array before sort: ";
    print(arr, n); // 14 84 11 32 25
    shellsort(arr, n);
    std::cout << "Array after sort:  ";
    print(arr, n); // 11 14 25 32 84
    return 0;
}