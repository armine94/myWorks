template <typename T>
std::vector<T> shellSort(std::vector<T> arr, int n)
{
    int k, i, j;
    T temp;

    for (k = n / 2; k > 0; k /= 2) {
        for (i = k; i < n; i++) {
            for (j = i - k; j >= 0 && arr[j] > arr[j + k]; j -= k) {
                temp = arr[j];
                arr[j] = arr[j + k];
                arr[j + k] = temp;
            }
        }
    }

    return arr;
}


template <typename T>
void print(std::vector<T> arr, int n) {
    std::cout << std::endl << "Array afther sorting" << std::endl;
    for(int i = 0; i < n; ++i) {
        std::cout << "array[" << i << "]: " << arr[i] << std::endl;
    }

    std::cout << std::endl;
}