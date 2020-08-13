#include <iostream>

template <typename T>
class Vector {
    public:
        int mSize; //count of vector items
        T* mArray;
    	Vector(){
            mSize = 0;
            mArray = new T [mSize];
		}

        ~Vector(){
            delete[] mArray;
        }

        Vector(const Vector &copy){
            this->mSize = copy.mSize;
            this->mArray = new T[copy.mSize];
            for (int i = 0; i < mSize; ++i) {
                this->mArray[i] = copy.mArray[i];
            }
        }


        void operator = (const Vector& op){
            this->mSize = op.mSize;
            if(this->mArray != nullptr){
                delete[] mArray;
            }
            this->mArray = new T[op.mSize];
            for(int i = 0 ; i < op.mSize; ++i){
                this->mArray[i] = op.mArray[i];
            }
        }

        //add new element in end of vector
        void push_back(const T value){
    
            T* tmp = new T [1 + mSize];
            for (int i = 0; i < mSize; ++i) {
                tmp[i] = mArray[i];
            }
            
            delete[] mArray;
            mArray = tmp;
            mArray[mSize ] = value;
            mSize =  1 + mSize;
        }

        //add new element in index
        void insert_at(int index, T elem){
            T* tmp = new T [1 + mSize];
            for (int i = 0; i <= mSize; ++i) {
                    if(i < index){
                    tmp[i] = mArray[i];
                }
                else if(i == index) {
                    tmp[i] = elem;
                }
                else{
                    tmp[i] = mArray[i-1];
                }    
            }
            delete[] mArray;
            mArray = tmp;
            mSize =  1 + mSize;
        }

        //get element by index
        T get_at(int index){
            return mArray[index];
        }

        int get_size(){
            return mSize;
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


        Iterator begin() const {
            return Iterator(mArray);
        }

        Iterator end() const {
            return Iterator(mArray + mSize);
        }

        Iterator rbegin() const {
            return Iterator(mArray + mSize -1);
        }

        Iterator rend() const {
            return Iterator(mArray - 1);
        }
};

int main() {
    Vector<int>* obj = new Vector<int>;
    
    obj->push_back(4);
    obj->push_back(5);
    obj->push_back(6);
    obj->push_back(7);
    obj->insert_at(0, 111);
    obj->insert_at(1, 222);
    obj->insert_at(3, 444);
     
     int count = 0;
    //print vector items from begin to end
    std::cout << "vector from begin to end" << std::endl;
    for(Vector<int>::Iterator i = obj->begin(); i != obj->end(); ++i) {
        std::cout << "vector[" << count++ << "] = " << *(i) << std::endl;
    }

    //print vector items from end to begin
    std::cout << std::endl << "vector from end to begin" << std::endl;
    for(Vector<int>::Iterator i = obj->rbegin(); i != obj->rend(); --i) {
        std::cout << "vector[" << --count << "] = " << *(i) << std::endl;
    }

    return 0;
}