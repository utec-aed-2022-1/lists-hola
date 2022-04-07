#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	// TODO            
        }

        T front(){
            throw ("sin definir");
        }

        T back(){
            throw ("sin definir");
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
            //std::cout << this->head->data  << std::endl;
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
            throw ("sin definir");
        }
        
        void sort(){
            Node<T>* tempNode1 = this->head; 
            Node<T>* nextComp = this->head; 
            Node<T>* prevComp = this->head; 
            Node<T>* prevOrg = this->head; 
            Node<T>* nextOrg = this->head; 
            Node<T>* actComp = this->head; 
            int ma = 0; 
            int key = 0; 

            
            for(int i = 0; i < this->size(); i++){
                Node<T>* tempNode2 = this->head; 
                ma = 0; 
                for(int k = 0; k < i; k++){
                    tempNode2 = tempNode2->next; 
                    ma++; 
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
                    //std::cout<< "X: " << i << "       " << j << "        " << ma << "       " << actComp->data << "      " << tempNode1->data << std::endl;
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
                                actComp->next = nextOrg;
                                nextOrg->next = nullptr;
                            } else {
                                if(tempNode2->next==nullptr){
                                    prevOrg->next = actComp;
                                    actComp->next = nextOrg;
                                    nextOrg->next = tempNode1;
                                } else {
                                    prevOrg->next = actComp; //10 apunta a 12  ---------- 8 apunta a 10
                                    actComp->next = nextOrg; //12 apunta a 30  ---------- 10 apunta a 30
                                    prevComp->next = tempNode1; //30 apunta a 20 -------- 20 apunta a 12
                                    tempNode1->next = nullptr; // 20 no apunta a nadie -- 12 apunta a nadie
                                }
                                //std::cout<<std::endl<< "DATOS2: " << prevOrg->data <<  "  " <<actComp->data << "    " << tempNode1->data << "  " << prevComp->data <<  "  " << nextOrg->data << std::endl;
                            }
                        } else {
                            if(tempNode1->next == actComp){
                                prevOrg->next = actComp; // 10 apunta a 20 
                                actComp->next  = tempNode1; // 20 apunta a 30  
                                tempNode1->next = nextComp; // 30 apunta a 12
                            } else {
                                prevComp->next = tempNode1; 
                                tempNode1->next  = nextComp; 
                                prevOrg->next = actComp; 
                                actComp->next = nextOrg;  
                            }
                        }
                        key++; 
                        tempNode1 = actComp; 
                    }
                    prevComp = tempNode2;
                    if(j != this->size()-1)tempNode2 = tempNode2->next; 
                }
                prevOrg = tempNode1; 
                if(i + 1 != this->size()) {tempNode1 = tempNode1->next;} 
                //std::cout<<std::endl;
            }
            /*std::cout<< "FINAL" << "    " <<std::endl;
            std::cout<< this->head->data << "  " << this->head->next->data << "  " << this->head->next->next->data << "  " 
            << this->head->next->next->next->data << "  " << this->head->next->next->next->next->data << "  "  
            << this->head->next->next->next->next->next->data << "  " <<  this->head->next->next->next->next->next->next->data << "  " <<  
            std::endl;*/
        }

        bool is_sorted(){
            Node<T>* tempNode1 = this->head; 
            if(this->head->data > this->head->next->data){
                for(int i = 0; i < this->size(); i++){
                    Node<T>* tempNode2 = this->head; 
                    for(int j = 0; j < this->size(); j++){
                        if(tempNode1->data < tempNode2->data){
                            return false;
                        }
                        tempNode2 = tempNode2->next; 
                    }
                    tempNode1 = tempNode1->next; 
                }
                return true; 
            } else {
                //std::cout<<std::endl<<this->head->data << "     " << this->head->next->data << std::endl;
                for(int i = 0; i < this->size(); i++){
                    Node<T>* tempNode2 = this->head; 
                    for(int j = 0; j < this->size(); j++){
                        //if(tempNode1->data > tempNode2->data){
                            std::cout<<std::endl<< tempNode1->data << "  " << tempNode2->data << std::endl;
                        //    return false;
                        //}
                        tempNode2 = tempNode2->next; 
                    }
                    tempNode1 = tempNode1->next; 
                }
                return true; 
            }
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif