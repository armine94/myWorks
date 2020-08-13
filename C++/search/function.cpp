//======================================================================
//=                         Liner Search                               =
//======================================================================

template <typename T>
int linerSearch(const std::vector<T> arr, const int n, const T value, int start = 0) {
    for(int i = start; i < n; ++i) {
        //compare searching element with elements of array if element found return index of element
        if(arr[i] == value) {
            return i;
        }
    }

    //if element not fount return -1
    return -1;
}


//======================================================================
//=                         Binary Search                              =
//======================================================================

template <typename T>
int binarySearch(const std::vector<T> arr, const int n, const T value, int start = 0) {
    int first = start, last = n -1;
    int middle = (last + first) / 2;

    if(value > arr[n - 1] || value < arr[0]) {
        return -1;
    }


    if(arr[0] == value) {
        return 0;
    }

    if(arr[n - 1] == value) {
        return n - 1;
    }

    while (first <= last) {
        if(arr[middle] == value) {
            return middle;
        }

        if(arr[middle] < value) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }

        middle = (last + first) / 2;
    }

    return -1;
}


//======================================================================
//=                         Jump Search                                =
//======================================================================

template <typename T>
int jumpSearch(const std::vector<T> arr, const int n, const T value) {
    int jump = sqrt(n);
    int step = sqrt(n);

    if(value > arr[n - 1] || value < arr[0]) {
        return -1;
    }

    if(arr[0] == value) {
        return 0;
    }

    if(arr[n - 1] == value) {
        return n - 1;
    }

    while (arr[jump] <= value && jump < n) {
        jump += step;
    }

    int size = jump > n ? n : jump;

    // linerSearch(arr, size, value, jump - step);
    for(int i = size - step ; i <= size; ++i) {
        //linear search in current block
        if(arr[i] == value) {
            return i; //position of element being searched
        }
    }

    //if element not fount return -1
    return -1;
}


//======================================================================
//=                       exponential Search                           =
//======================================================================

template <typename T>
int exponentialSearch(const std::vector<T> arr, const int n, const T x) {
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;

    //  Call binary search for the found range.
    int size = i > n ? n : i;
    return binarySearch(arr, size, x, i/2);
}


//======================================================================
//=                         ternary Search                             =
//======================================================================

// Function to perform Ternary Search
template <typename T>
int ternarySearch(std::vector<T> arr, int left, int right, const T value) {
    if (right >= left) {

        // Find the mid1 and mid2
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Check if Value is present at any mid
        if (arr[mid1] == value) {
            return mid1;
        }
        if (arr[mid2] == value) {
            return mid2;
        }

        if (value < arr[mid1]) {

            // The Value lies in between l and mid1
            return ternarySearch(arr, left, mid1 - 1, value);
        }
        else if (value > arr[mid2]) {

            // The Value lies in between mid2 and r
            return ternarySearch(arr, mid2 + 1, right, value);
        }
        else {

            // The Value lies in between mid1 and mid2
            return ternarySearch(arr, mid1 + 1, mid2 - 1, value);
        }
    }

    // Value not found
    return -1;
}


//======================================================================
//=                         interpolation Search                             =
//======================================================================

int interpolationSearch(const std::vector<int> arr, const int n, const int value) {

    // Find indexes of two corners
    int first = 0, last = (n - 1);

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (first <= last && value >= arr[first] && value <= arr[last]) {
        if (first == last) {
            if (arr[first] == value) return first;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = first + (((double)(last - first) / (arr[last] - arr[first])) * (value - arr[first]));

        // Condition of target found
        if (arr[pos] == value) {
            return pos;
        }

        // If value is larger, value is in upper part
        if (arr[pos] < value) {
            first = pos + 1;
        } else {
            // If value is smaller, value is in the lower part
            last = pos - 1;
        }
    }

    return -1;
}