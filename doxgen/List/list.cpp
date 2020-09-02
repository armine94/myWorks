#include <iostream>
#include <vector>

template <typename T>
/**
 * @brief Lists are sequence containers that allow non-contiguous memory allocation.
 * As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick.
*/
class List {

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    unsigned int mSize;

    public :
        //Constructs an empty container, with no elements.
        List(){
            head = NULL;
            tail = NULL;
            mSize = 0;
            std::cout << "defolt" << std::endl;
        }

        //Constructs a container with n elements. Each element is a copy of value.
        List(unsigned int size = 0, int value = 0) {
            mSize = size;
            head = NULL;
            tail = NULL;

            for(int i = 0; i < size; ++i) {
                Node* tmp = new Node();
                tmp->data = value;
                tmp->prev = NULL;
                tmp->next = head;
                if(head != NULL) {
                    head->prev = tmp;
                }
                head = tmp;

                if(i == 0) {
                    tail = tmp;
                }
            }

        }

        /**
         * @todo
         * @brief This function generate new data for Valodik
         * @param norParametr - new parametr
         */
        void Valodik(int norParametr) {

        }

        //Constructs a container with a copy of each of the elements in x, in the same order.
        List(const List &copy){
            this->head = NULL;
            this->tail = NULL;
            Node* cur = copy.tail;
            for (int i = 0; i < copy.mSize; ++i) {
                Node* tmp = new Node();
                tmp->data = cur->data;
                tmp->prev = head;
                tmp->next = head;
                head = tmp;
                cur = cur->prev;
                if(i == 0) {
                    tail = tmp;
                }
            }
        }

        // Assigns new contents to the container, replacing its current contents,
        // and modifying its size accordingly.
        List& operator= (const List& obj) {
            Node* tmp = head;
            head = NULL;
            tail = NULL;
            delete tmp;

            tmp = obj.tail;
            for(int i = 0; i < mSize; ++i) {
                Node* newNode = new Node();
                newNode->data = tmp->data;
                newNode->prev = head;
                newNode->next = head;
                head = newNode;
                tmp = tmp->prev;
                if(i == 0) {
                    tail = newNode;
                }
            }
            return *this;
        }

        //Destroys the container object
        ~List() {
            delete tail;
            delete head;
        }


        /**
         * @brief It takes the element to be added as a parameter and adds it to the list container.
         * @param value - value for new added node of list
        */
        void push_back (const T& value) {
            Node* tmp = new Node();
            tmp->data = value;

            if(head == NULL) {
                head == tmp;
                tail == tmp;
                tail->next = NULL;
                tail->prev = NULL;
                head->next = NULL;
                head->prev = NULL;
            } else {
            Node* cur = tail;
            cur->next = tmp;
            tmp->next = NULL;
            tmp->prev = cur;
            tail = tmp;
            tail->prev = cur;
            tail->next = NULL;
            mSize++;
            }

        }

        //inserts a new element at the beginning of the list, right before its current
        //first element. The content of val is copied (or moved) to the inserted element.
        /**
         *@brief It takes the element to be added as a parameter and adds it to the first container.
         *@param value - value for new added node of list
         */
        void push_front (const T& value) {
            Node* tmp = new Node();
            tmp->data = value;
            tmp->prev = NULL;
            tmp->next = head;
            if(head != NULL) {
                head->prev = tmp;
            }
            head = tmp;
            mSize++;
        }

        //Removes the first element in the list container, effectively reducing its size by one.
        void pop_front() {
            Node* tmp = head;
            if(tmp->next != NULL) {
            head = tmp->next;
            tmp->next->prev = NULL;
            }
            mSize--;
            delete tmp;
        }

        //Removes the last element in the list, effectively reducing the container size by one.
        void pop_back() {
            Node* tmp = tail;
            if(tail->prev != NULL) {
                tmp->prev->next = NULL;
                tail = tmp->prev;
            } else {
                head = NULL; //tail = NULL;
            }
            delete tmp;
            mSize--;
        }

        // Returns the number of elements in the list.
        // Member type size_type is an unsigned integral type.
        unsigned int size() const {
            return mSize;
        }

        // Returns whether the list is empty (i.e. whether its size is 0).
        bool empty() const {
            return mSize == 0 ? true : false;
        }

        // Removes from the container all the elements that compare equal to val.
        // This calls the destructor of these objects and reduces the container size
        // by the number of elements removed.
        void remove (const T& value) {
            Node* cur = head;
            unsigned int size = mSize;
            for (int i = 0; i < size; ++i) {
                if(cur->data == value) {
                    if(i == 0) {
                        pop_front();
                    }
                    else if(i == size - 1) {
                        pop_back();
                    }
                    else {
                        Node* tmp = cur;
                        if(cur->prev == NULL) {
                            head = cur->next;
                            cur->next->prev = NULL;
                        } else {
                            cur->next->prev = cur->prev;
                            cur->prev->next = cur->next;
                        }
                        delete tmp;
                        mSize--;
                    }
                }
                cur = cur->next;
            }
        }

        void insert_at(int pos,const T& elem){
            Node* tmp = new Node(); //new node
            int cout = size(); //size of list items

            //checks which on the index need add new item
            if(pos == 0) {
                //push front
                tmp->data = elem;
                tmp->prev = NULL;
                tmp->next = head;
                if(head != NULL) {
                    head->prev = tmp;
                } else {
                    tail =  tmp;
                    tail->prev = NULL;
                    tail->next = NULL;
                }
                head = tmp;
            } else  if (pos < cout && pos > 0){
                //in the middle
                Node* prev = head;
                tmp->data = elem;

                int i ;
                //find prevuse element
                for( i = 0; i < pos - 1;++i){
                    prev = prev->next;
                }

                tmp->next = prev->next;
                prev->next->prev = tmp;
                tmp->prev = prev;
                prev->next = tmp;
            }
            else if (pos > 0 && pos == cout) {
                //push_back
                Node* tmp = new Node();
                Node* cur = head;
                tmp->data = elem;
                for(int i = 0; i<pos-1; ++i){
                    cur = cur->next;
                }
                cur->next = tmp;
                tmp->next = NULL;
                tmp->prev = cur;
                tail = tmp;
                tail->prev = cur;
                tail->next = NULL;
            }
            mSize++;
        }

        void print(){
            Node* cur = head;
            while(cur != NULL) {
                std::cout << cur->data <<std::endl;
                cur = cur->next;
            }
        }

        class Iterator {
        private:
            Node* node;

        public:
            Iterator (Node* newArray): node(newArray) {}

            Iterator(): node(nullptr) {}

            ~Iterator() {}

            Iterator operator++() {
                node = node->next;
                return node;
            }

            Iterator operator++(int) {
                Node* tmp = node;
                node = node->next;
                return tmp;
            }

            Iterator operator--() {
            node = node->prev;
                return node;
            }

            Iterator operator--(int) {
                Node* tmp = node;
                node = node->prev;
                return tmp;
            }

            T operator* () const {
                return node->data;
            }

            bool operator!= (const Iterator& itr) const {
                return node != itr.node;
            }

            bool operator== (const Iterator& itr) const {
                return node == itr.node;
            }
        };

        // Returns an iterator pointing to the first element in the list.
        Iterator begin() const {
            return Iterator(head);
        }

        // Returns an iterator referring to the past-the-end element in the list container.
        Iterator end() const {
            return Iterator(tail->next);
        }

        // Returns an iterator pointing to the end element in the list.
        Iterator rbegin() const {
            return Iterator(tail);
        }

        // Returns an iterator referring to the past-the-first element in the list container
        Iterator rend() const {
            return Iterator(head->prev);
        }
};

int main() {
    List<int> l(1, 2);
    l.pop_back();
    l.push_back(66);
    // l.push_front(111);
    // l.insert_at(1, 555);

    // std::cout << "Print list before remove all items each value equal 15" << std::endl;
    // l.print();
	// l.remove(15);
    // std::cout << "Print list afther remove all items each value equal 15" << std::endl;
    // l.print();

    // std::cout << std::endl;
    // for(List<int>::Iterator i = l.begin(); i != l.end(); ++i) {
    //     std::cout << "++ Iterator: " << *(i) << std::endl;
    // }

    // for(List<int>::Iterator i = l.rbegin(); i != l.rend(); --i) {
    //     std::cout << "-- Iterator: " << *(i) << std::endl;
    // }

    return 0;
}