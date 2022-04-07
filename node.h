#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){ 
        Node<T>* next;
        Node<T>* prev;
        // TODO
    }

    Node(T value){
        this->data = value; 
        this->next = nullptr;
        this->prev= nullptr;
        // TODO
    }

    void killSelf(){
        delete this->next; 
        delete this->prev; 
    }    
};

#endif