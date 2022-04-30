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
            Node<T>* tempNode = this->head;
            while(this->head != nullptr){
                if(this->head->next != nullptr){
                    tempNode = this->head->next; 
                }
                if(this->head->next != nullptr){
                    this->head->killSelf(); 
                    this->head = tempNode; 
                    if(this->head->next == nullptr){
                        this->head->killSelf(); 
                        this->head = nullptr; 
                    }
                }
                this->nodes--;
            }
            this->tail = nullptr; 
            this->nodes--;
        }

        void sort(){
            Node<T>* tempNode1 = this->head; 
            Node<T>* nextComp = this->head; 
            Node<T>* prevComp = this->head; 
            Node<T>* prevOrg = this->head; 
            Node<T>* nextOrg = this->head; 
            Node<T>* actComp = this->head; 
            
            for(int i = 0; i < this->size(); i++){
                Node<T>* tempNode2 = this->head; 
                for(int k = 0; k < i; k++){
                    tempNode2 = tempNode2->next; 
                }
                for(int j = i; j < this->size(); j++){
                    int key = 0; 
                    actComp = tempNode2; 
                    if(tempNode1->data > actComp->data){
                        if(actComp->next == nullptr){
                            nextOrg = tempNode1->next; // 30 
                            prevComp = tempNode2->prev; // 20 
                            if (i == 0) {
                                //Caso que desde el ultimo punto de la lista quiere ir al primer punto de la lista 

                            } else if(tempNode1->next == actComp){
                                //Caso desde cualquier punto de la lista quiere ir al siguiente y es el final
                                prevOrg = tempNode1->prev;
                                prevOrg->next = tempNode2; //12 apunta 20
                                tempNode2->prev = prevOrg; //20 apunta a 12
                                tempNode2->next = tempNode1; //20 apunta a 30
                                tempNode1->next = nullptr; 
                                key++; 
                                this->tail = tempNode1; 
                            } else {
                                //Caso que desde el ultimo punto de la lista quiere ir a cualquier punto de la lista
                                prevOrg = tempNode1->prev; // 8
                                prevOrg->next = tempNode2;  
                                nextOrg->prev = tempNode2;     
                                prevComp->next = tempNode1; 
                                tempNode2->next = nextOrg;    
                                tempNode2->prev = prevOrg;    
                                tempNode1->prev = prevComp;
                                tempNode1->next = nullptr;
                                key++;
                            }
                            
                        } else {
                            nextOrg = tempNode1->next; 
                            prevComp = actComp->prev; 
                            nextComp = actComp->next; 
                            if (i == 0) {
                                //Caso desde cualquier punto de la lista quiere ir al primer punto de la lista
                            } else if(tempNode1->next == actComp){
                                prevOrg = tempNode1->prev; 
                                //Caso desde cualquier punto de la lista quiere ir al siguiente 
                                prevOrg->next = tempNode2;  //10 apunta 20
                                nextComp->prev = tempNode1; //12 apunta a 30  
                                tempNode2->prev = prevOrg; //20 apunta a 10
                                tempNode1->next = nextComp; //30 apunta a 12
                                tempNode2->next = tempNode1; //20 apunta a 30
                                tempNode1->prev = tempNode2; //30 apunta a 20
                                key++; 
                            } else {
                                //Caso desde cualquier punto de la lista quiere ir a cualquier punto de la lista
                                prevOrg = tempNode1->prev; 
                                prevOrg->next = actComp; //     | 5 apunta a 8 (next)
                                nextOrg->prev = actComp; //     | 20 apunta a 8 (prev)
                                prevComp->next = tempNode1; // | 30 apunta a 12 (next)
                                nextComp->prev = tempNode1; // | 10 apunta a 12 (prev)
                                tempNode1->next = nextComp; // | 12 apunta a 10 (next)
                                tempNode1->prev = prevComp; // | 12 apunta a 30 (prev)
                                actComp->next = nextOrg; //    | 8 apunta a 20 (next)
                                actComp->prev = prevOrg; //     | 8 apunta a 5 (prev) 
                                key++;
                            }
                        }
                    }
                    if(key != 0){
                        tempNode2 = tempNode1->next; 
                        tempNode1 = actComp;
                    }
                    else tempNode2 = tempNode2->next; 
                }
                tempNode1 = tempNode1->next; 
            }
        }

        bool is_sorted(){
            Node<T>* tempNode1 = this->head; 
            Node<T>* nextComp = this->head; 
            Node<T>* prevComp = this->head; 
            Node<T>* prevOrg = this->head; 
            Node<T>* nextOrg = this->head; 
            Node<T>* actComp = this->head; 
            
            for(int i = 0; i < this->size(); i++){
                Node<T>* tempNode2 = this->head; 
                for(int k = 0; k < i; k++){
                    tempNode2 = tempNode2->next; 
                }
                for(int j = i; j < this->size(); j++){
                    int key = 0; 
                    actComp = tempNode2; 
                    if(tempNode1->data > actComp->data){
                        return false; 
                    }
                    tempNode2 = tempNode2->next; 
                }
                tempNode1 = tempNode1->next; 
            }
            return true; 
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "DoubleList";
        }
        
};
#endif