#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes = 0;
    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){ 
         	// TODO            
        }
        T front(){
            return this->head->data;
        }

        T back(){
            return tail->data; 
        }

        void push_front(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
            } else {
                newNode->next = this->head; 
                this->head->prev = newNode; 
                this->head = newNode; 
            }
            this->nodes = this->nodes + 1; 
        }

        void push_back(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
            } else {
                newNode->prev = this->tail; 
                this->tail->next = newNode; 
                this->tail = newNode;
            }
            this->nodes = this->nodes + 1; 
        }
        T pop_front(){
            Node<T>* deleteNode = this->head; 
            T result = deleteNode->data; 
            this->head = this->head->next; 
            delete this->head->prev; 
            this->head->prev = nullptr;
            return result; 
        }

        T pop_back(){
            Node<T>* deleteNode = this->tail; 
            T result = deleteNode->data; 
            this->tail = this->tail->prev; 
            delete this->tail->next; 
            this->tail->next = nullptr;
            return result; 
        }

        T insert(T data, int pos){
            throw ("sin definir");
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            Node<T>* tempNode = this->head; 
            int i = 0; 
            while (true){
                if(i + 1  == pos){
                    return tempNode->data; 
                    break; 
                } else {
                    tempNode = tempNode->next; 
                }
                i++; 
            }    
        }
        

        bool is_empty(){
            if(this->nodes == 0)return true;
            return false; 
        }

        int size(){
            return this->nodes;
        }
        void clear(){
            for(Node<T>* temp = head; temp != nullptr; temp = temp->next)std::cout<<temp->data<<" ";
            std::cout<<std::endl;   
        }

        void sort(){
            throw ("sin definir");
        }

        bool is_sorted(){
            throw ("sin definir");
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};
#endif