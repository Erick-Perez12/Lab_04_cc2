#ifndef NODE_H
#define NODE_H
 
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node
{      
       
    public:
        Node();
        ~Node();
        Node(T);

        Node *next;
        T element;
        
        void delete_all();
        void print();
        friend ostream& operator <<(ostream &out, const Node &p){
            out<<p.element<<"->";
            return out;
		}
};
template<typename T>
Node<T>::Node(){
    element = NULL;
    next = NULL;
}

template<typename T>
Node<T>::Node(T element_){
    element = element_;
    next = NULL;
}
template<typename T>
void Node<T>::delete_all(){
    if(next)
        next->delete_all();
    delete this;
}

template<typename T>
void Node<T>::print(){
    cout<<element<<"->";
}

template<typename T>
Node<T>::~Node(){}
#endif // NODE_H