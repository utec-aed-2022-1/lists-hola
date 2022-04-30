#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"
// FALTA REVERSE REMOVE
// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes = 0;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	// TODO            
        }

        T front(){
            return this->head->data;
        }

        T back(){
            Node<T>* tempNode = this->head;
            while(tempNode->next != nullptr){
                tempNode = tempNode->next; 
            }
            return tempNode->data; 
        }

        void push_front(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
            } else {
                newNode->next = this->head; 
                this->head = newNode; 
            }
            this->nodes = this->nodes + 1; 
        }

        void push_back(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
            } else {
                Node<T>* tempNode = this->head; 
                int i = 0; 
                while (true){
                    if(i + 1  == this->nodes){
                        tempNode->next = newNode; 
                        break; 
                    } else {
                        tempNode = tempNode->next; 
                    }
                    i++; 
                }
            }
            this->nodes = this->nodes + 1; 
        }

        T pop_front(){
            Node<T>* deleteNode = this->head; 
            T result = deleteNode->data; 
            this->head = this->head->next; 
            delete deleteNode; 
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T pop_back(){
            Node<T>* tempNode = this->head; 
            T result; 
            int i = 0; 
            while (true){
                if(i + 2  == this->nodes){
                    result = tempNode->next->data;
                    tempNode->next = nullptr;
                    break; 
                } else {
                    tempNode = tempNode->next; 
                }
                i++; 
            }    
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T insert(T data, int pos){
            Node<T>* newNode = new Node<T>(data);
            Node<T>* tempNode1 = this->head; 
            int i = 0; 
            while (true){
                if(i + 2  == pos){
                    Node<T>* tempNode2 = tempNode1->next;
                    tempNode1->next = newNode; 
                    newNode->next = tempNode2; 
                    break; 
                } else {
                    tempNode1 = tempNode1->next; 
                }
                i++; 
            } 
            this->nodes = this->nodes + 1; 
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
                for(int j = i; j < this->size() - 1; j++){
                    if(j == this->size()-1){ 
                        actComp = tempNode2;
                    } 
                    else{ 
                        if(tempNode2->next==nullptr){
                            actComp = tempNode2; 
                        } else {
                            actComp = tempNode2->next;
                        }
                    }
                    if(actComp->data < tempNode1->data){
                        if(j == this->size()-1){nextComp = nullptr;}
                        else { 
                            if(tempNode2->next==nullptr){
                                nextComp = nullptr;
                            } else {
                                nextComp = tempNode2->next->next;
                            }
                        } 
                        if(j != this->size()-1) prevComp = tempNode2; 
                        nextOrg  = tempNode1->next; 
                        if(nextComp == nullptr){
                            if(tempNode1->next == actComp){
                                prevOrg->next = actComp;
                                actComp->next = tempNode1;
                                tempNode1->next = nullptr;
                            } else {
                                if(tempNode2->next==nullptr){
                                    prevOrg->next = actComp;
                                    actComp->next = nextOrg;
                                    nextOrg->next = tempNode1;
                                    tempNode1->next = nullptr; 
                                } else {
                                    prevOrg->next = actComp; //10 apunta a 12  ---------- 8 apunta a 10
                                    actComp->next = nextOrg; //12 apunta a 30  ---------- 10 apunta a 30
                                    prevComp->next = tempNode1; //30 apunta a 20 -------- 20 apunta a 12
                                    tempNode1->next = nullptr; // 20 no apunta a nadie -- 12 apunta a nadie
                                }
                            }
                        } else {
                            if(tempNode1->next == actComp){
                                if(actComp->next == nullptr){
                                }
                                prevOrg->next = actComp; // 12 apunta a 20 
                                actComp->next  = tempNode1; // 20 apunta a 30  
                                tempNode1->next = nextComp; // 30 apunta a 12
                            } else {
                                prevComp->next = tempNode1; 
                                tempNode1->next  = nextComp; 
                                prevOrg->next = actComp; 
                                actComp->next = nextOrg;  
                            }
                        }
                        tempNode1 = actComp; 
                    }
                    prevComp = tempNode2;
                    if(j != this->size()-1)tempNode2 = tempNode2->next; 
                }
                prevOrg = tempNode1; 
                if(i + 1 != this->size()) {tempNode1 = tempNode1->next;} 
                //std::cout<<std::endl;
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
                    if(j == this->size()-1){ 
                        actComp = tempNode2;
                    } 
                    else{ 
                        if(tempNode2->next==nullptr){
                            actComp = tempNode2; 
                        } else {
                            actComp = tempNode2->next;
                        }
                    }
                    if(actComp->data < tempNode1->data){
                        return false; 
                    }
                    prevComp = tempNode2;
                    if(j != this->size()-1)tempNode2 = tempNode2->next; 
                }
                prevOrg = tempNode1; 
                if(i + 1 != this->size()) {tempNode1 = tempNode1->next;} 
            }  
            return true;
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif