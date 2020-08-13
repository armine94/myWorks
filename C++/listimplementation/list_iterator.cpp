#include <iostream>

template <typename T>
class List {

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;

public : 
    List(){
        head = NULL;
        tail = NULL;
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

    void insert(int pos,const T& elem){  
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
    }

		void remove(int pos){
			Node* tmp = new Node;
			Node* cur = head; 
			int count = size();
            std::cout << "coutn: " << count << std::endl;
			if(pos > -1 && pos < count ){
                //find prevuse element 
				for(int i = 0; i < count - 1; ++i){
                    if(pos == 0) {
                        tmp = head;
                        head = tmp->next;
                        delete tmp;break;
                    }
					else if(i == pos - 1 && i != count - 2) {
						tmp = cur->next;
						cur->next = tmp->next;
                        tmp->next->prev = cur;
                        delete tmp; break;
					} else if (i == count - 2) {
						tmp = cur->next;
                        cur->next = NULL;
                        tail = cur;
                        tail->next = NULL;
                        tail->prev = cur->prev->prev;
                        delete tmp;break;
                    } 
                    cur = cur->next;
				}
			}
			else {
				std::cout<<"that position don't have\n";
			
			}
		}

    //if finds element of the value return index of that value else return -1
    int indexOf(const T& elem) {
        Node* tmp = head;
        for(int i = 0; i < size() - 1; ++i) {
            if(tmp->data == elem) {
                return i;
            }
            tmp = tmp->next;
        }
        return -1;
	}

    //print elements of list
    void print(){
        int a = 0;
        Node* cur = head;
        while(cur != NULL) {
            std::cout << cur->data <<std::endl;
            cur = cur->next;
        }
    }

    //returns number of elements in list
    int size(){
        int size = 0;
        Node* tmp = head;
        while(tmp != NULL) {
            ++size;
            tmp = tmp->next;
        }
        return size;
    }

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(tail->next);
    }

    Iterator rbegin() const {
        return Iterator(tail);
    }

    Iterator rend() const {
        return Iterator(head->prev);
    }

};

int main() {
    List<int> l;
    l.insert(0,555);
    l.insert(1,111);
    l.insert(0,654);
    l.insert(0,8888);
    l.insert(0,7006);
    l.insert(3,7777);
	std::cout << "index of 555: " << l.indexOf(555) << std::endl;
    std::cout << "Print list afther remove 4th item" << std::endl;
    l.print();
	l.remove(4);
    std::cout << "Print list before remove 4th item" << std::endl;
    l.print();

    std::cout << std::endl;
    for(List<int>::Iterator i = l.begin(); i != l.end(); ++i) {
        std::cout << "++ Iterator: " << *(i) << std::endl;
    }

    for(List<int>::Iterator i = l.rbegin(); i != l.rend(); --i) {
        std::cout << "-- Iterator: " << *(i) << std::endl;
    }

    List<int>::Iterator i = l.rbegin();
    --i;
    std::cout << "--i: " << *(i) << std::endl;
    std::cout << "i--: " << *(i--) << std::endl;
    std::cout << "i:   " << *(i) << std::endl;
    std::cout << "i++: " << *(i++) << std::endl;
    std::cout << "++i: " << *(++i) << std::endl;
        return 0 ;
}