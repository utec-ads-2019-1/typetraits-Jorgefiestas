#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        int s = 0;
              
    public:
        List() : head(nullptr) {};

        bool find(T search, Node<T> **&pointer) {
            pointer = &head;
            while(*pointer != nullptr && !cmp(search, (*pointer)->data))
                    pointer = &((*pointer)->next);
            return *pointer !=nullptr && (*pointer)->data == search;
        }
             
        bool insert(T data) {
            Node<T>* nNode= new Node<T>(data);

			Node<T>** temp;
			if(find(data, temp))
                return false;

            s++;
            nNode->next = *temp;
            *temp = nNode;
			return true;
        }
             
        bool remove(T item) {
			Node<T>** temp;

			if(!find(item, temp))
                return false;

            s--;
            Node<T>* dNode = *temp;
            *temp = (*temp)->next;
            delete dNode;
			return true;
        }  
             
        int size() {
            return s;
        }

        T operator[](int index) {
			Node<T>* temp = head;

			for(int i = 0; i<index; i++){
				temp = temp->next;
				if(temp == nullptr)
					throw out_of_range("Segmentation Fault");
			}

			return temp->data;
        }

        ~List() {
			head->killSelf();
        }         
};

#endif
