#include <iostream>
#include <vector>

template <typename T>
class Vector {
    private:
        unsigned int mSize;
        unsigned int mCapacity;
        T* vector;
    public:
        // Constructs an empty container, with no elements

        /**
         * @brief Constructs an empty container, with no elements
         */
        Vector(){
            mSize = 0;
            mCapacity = 0;
            vector = new T [mSize];
        }

        // Constructs a container with n elements. Each element is a copy of val.

        /**
         * @brief Constructs a container with size elements. Each element is a copy of value.
         * @param size - number of elements
         * @param value - value for each element
         */
        Vector(const unsigned int size = 5, const T value = 0) {
            try
            {
                this->mSize = size;
                this->mCapacity = size;
                this->vector = new T[size];
                for (int i = 0; i < size; ++i) {
                    this->vector[i] = value;
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() <<" uncorected index" << '\n';
            }


        }

        // Constructs a container with a copy of each of the elements in x, in the same order.
        Vector(const Vector &copy){
            this->mSize = copy.mSize;
            this->mCapacity = copy.mCapacity;
            this->vector = new T[copy.mSize];
            for (int i = 0; i < mSize; ++i) {
                this->vector[i] = copy.vector[i];
            }
        }

        // Destroys the container object
        ~Vector(){
            delete[] vector;
        }

        // Assigns new contents to the container, replacing its current contents,
        // and modifying its size accordingly
        Vector<T>& operator= (const Vector<T>& value) {
            this->mSize = value.mSize;
            this->mCapacity = value.mSize;
            this->vector = value.vector;
            return *this;
        }

        // Returns a reference to the element at position n in the vector container.
        T& operator[] (const int n) const {
            return *(vector + n);
        }

        T& operator* () const {
            return *vector;
        }

        // Returns the number of elements in the vector.
        unsigned int size() const {
            return mSize;
        }

        // Returns the size of the storage space currently allocated for the vector.
        unsigned int capacity() const {
            return mCapacity;
        }

        // Returns whether the vector is empty (i.e. whether its size is 0)
        /**
         * @brief check vector is empty?
         * @return return true when vector size = 0, else false
         */
        bool empty() {
            return mSize == 0 ? true : false;
        }

        // Adds a new element at the end of the vector, after its current last elementr
        void push_back(const T value){
            if(mSize == mCapacity) {
                mCapacity *= 2;
                T* tmp = new T [mCapacity];
                for (int i = 0; i < mSize; ++i) {
                    tmp[i] = vector[i];
                }
                tmp[mSize] = value;
                delete[] vector;
                vector = tmp;
            } else {
                vector[mSize ] = value;
            }

            ++mSize;
        }

        //change vector size
        /**
         * @brief delete last element and decrement vector size
         */
        void pop_back() {
            mSize = mSize - 1;
        }

        // Resizes the container so that it contains n elements
        void resize (const unsigned int size, const T value = 0) {
            T* tmp;
            if(mSize > size) {
                mSize = size;
                tmp = new T [mCapacity];
                for(unsigned int i = 0; i < mSize; ++i) {
                    tmp[i] = vector[i];
                }

                delete[] vector;
                vector = tmp;
            } else if(mSize < size && size > mCapacity){
                tmp = new T [size];
                for(unsigned int i = 0; i < mSize; ++i) {
                    tmp[i] = vector[i];
                }
                for(unsigned int i = mSize; i < size; ++i) {
                    tmp[i] = value;
                }
                mSize = mCapacity = size;
                delete[] vector;
                vector = tmp;
            } else if(mSize < size && size < mCapacity) {
                for(unsigned int i = mSize; i < size; ++i) {
                    vector[i] = value;
                }
                mSize = size;
            }
        }

        // quests that the vector capacity be at least enough to contain n elements.
        // If val is specified, the new elements are initialized as copies of val,
        // otherwise, they are value-initialized.
        void reserve (const unsigned int size) {
            if(mCapacity < size) {
                mCapacity = size;
            }
        }

        //  Requests the container to reduce its capacity to fit its size.
        void shrink_to_fit () {
            mCapacity = mSize;
        }

        class Iterator {
            public:
                T* array;
                Iterator (T* newArray): array(newArray) {}

                Iterator(): array(nullptr) {}

                ~Iterator() {}

                bool operator!= (const Iterator& itr) const {
                    return array != itr.array;
                }

                bool operator== (const Iterator& itr) const {
                    return array == itr.array;
                }

                Iterator operator++(int) {
                    T* tmp = array;
                    array = array + 1;
                    return tmp;
                }

                Iterator operator++() {
                    array = array + 1;
                    return array;
                }

                Iterator operator--(int) {
                    T* tmp = array;
                    array = array - 1;
                    return tmp;
                }

                Iterator operator--() {
                    array = array - 1;
                    return array;
                }

                Iterator operator+(int n) {
                    return array + n;
                }

                Iterator operator-(int n) {
                    return array - n;
                }

                T& operator* () const {
                    return *array;
                }

        };

        // Returns an iterator pointing to the first element in the vector.
        Iterator begin() const {
            return Iterator(vector);
        }

        // Returns an iterator referring to the past-the-end element in the vector container
        Iterator end() const {
            return Iterator(vector + mSize);
        }

        // Returns an iterator referring to the past-the-begin element in the vector container
        Iterator rbegin() const {
            return Iterator(vector + mSize -1);
        }

        // Returns an iterator pointing to the end element in the vector.
        Iterator rend() const {
            return Iterator(vector - 1);
        }
};

int main() {
    Vector<int> obj(2, 7);
    obj.push_back(5);
    obj.push_back(4);
    obj.push_back(5);
    obj.push_back(65);

    int count = 0;
    //print vector items from begin to end
    std::cout << "vector from begin to end"<< obj.capacity() << std::endl;
    for(Vector<int>::Iterator i = obj.begin(); i != obj.end(); ++i) {
        std::cout << "vector[" << count++ << "] = " << *(i) << std::endl;
    }

    obj.pop_back();
    obj.pop_back();

    count -= 2;
    //print vector items from end to begin
    std::cout << std::endl << "vector from end to begin" << std::endl;
    for(Vector<int>::Iterator i = obj.rbegin(); i != obj.rend(); --i) {
        std::cout << "vector[" << --count << "] = " << *(i) << std::endl;
    }

    if(obj.empty()) {
        std::cout << "vector  is empty" << std::endl;
    } else {
        std::cout << "vector is'n empty" << std::endl;
    }

    std::cout << "size1:  " << obj.size() << std::endl;
    std::cout << "capacity1:  " << obj.capacity() << std::endl;

    obj.resize(3, 88);
    std::cout << "resize size:  " << obj.size() << std::endl;
    std::cout << "resize capacity:  " << obj.capacity() << std::endl;
    for(int i = 0 ; i < obj.size(); ++i){
        std::cout << " vec: " << obj[i] <<std::endl;
    }
    obj.reserve(15);

    std::cout << "reserve size:  " << obj.size() << std::endl;
    std::cout << "reserve capacity:  " << obj.capacity() << std::endl;

    obj.shrink_to_fit();
    std::cout << "size:  " << obj.size() << std::endl;
    std::cout << "capacity:  " << obj.capacity() << std::endl;

    return 0;
}