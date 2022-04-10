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
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T pop_back(){
            Node<T>* deleteNode = this->tail; 
            T result = deleteNode->data; 
            this->tail = this->tail->prev; 
            delete this->tail->next; 
            this->tail->next = nullptr;
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T insert(T data, int pos){
            Node<T>* newNode = new Node<T>(data);
            int i = 0;
            Node<T>* tempNode1 = this->head;
            while (true){
                if(i + 2  == pos){
                    Node<T>* tempNode2 = tempNode1->next;
                    tempNode1->next = newNode; 
                    newNode->prev = tempNode1; 
                    newNode->next = tempNode2;
                    tempNode2->prev = newNode; 
                    break; 
                } else {
                    tempNode1 = tempNode1->next; 
                }
                i++; 
            } 
            this->nodes = this->nodes + 1; 
            return data; 
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            int closeHead = pos - 0; 
            int closeTail = this->size() - pos; 
            if(closeHead <= closeTail){
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
            } else {
                Node<T>* tempNode = this->head; 
                int i = this->size(); 
                while (true){
                    if(i - 1  == pos){
                        return tempNode->data; 
                        break; 
                    } else {
                        tempNode = tempNode->prev; 
                    }
                i--; 
                }   
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
            Node<T>* tempNode1 = this->head; 
            Node<T>* nextComp = this->head; 
            Node<T>* prevComp = this->head; 
            Node<T>* prevOrg = this->head; 
            Node<T>* nextOrg = this->head; 
            Node<T>* actComp = this->head; 
            std::cout << std::endl << "SORT" << std::endl; 
            
            for(int i = 0; i < this->size(); i++){
                Node<T>* tempNode2 = this->head; 
                for(int k = 0; k < i; k++){
                    tempNode2 = tempNode2->next; 
                }
                for(int j = i; j < this->size(); j++){
                    std::cout << "ACTUAL " << tempNode1->data << " I: " << i << std::endl; 
                    std::cout << "COMPARADO: " << tempNode2->data << " J : " << j << std::endl; 
                    std::cout << "------------------------------" << std::endl; 
                    if(tempNode1->data > tempNode2->data){
                        std::cout << std::endl << "ES MENOOOOOR" << std::endl; 
                    }
                    tempNode2 = tempNode2->next; 
                }
                std::cout << std::endl << "CAMBIO DEL ACTUAL" << std::endl;
                tempNode1 = tempNode1->next; 
            }
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