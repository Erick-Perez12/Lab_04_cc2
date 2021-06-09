#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
 
using namespace std;
 
template <class T>
 
class LinkedList{
	int size;
	Node<T> *head;
	public:
		LinkedList();
		~LinkedList();
		void insert(T);
		void remove(int);
		void print();
        //friend std:: ostream& operator<<(ostream& o, const LinkedList& p);
};
/*template<typename T>
std:: ostream& operator << <>(ostream& o, const LinkedList<T>& p){
        Node<T> *aux=p.head;
        while(aux != NULL){
            o<<aux->element<<"->";
            aux=aux->next;
        }
        return o;
}*/
template<typename T>
LinkedList<T>::LinkedList(){
    size=0;
    head=NULL;
}

template<typename T>
void LinkedList<T>::insert(T element_){
    Node<T> *new_node = new Node<T> (element_);
    Node<T> *temp = head;
    if (!head){
        head=new_node;
    }else{
        if(head->element > element_){
            new_node->next = head;
            head = new_node;
        }else{
            while((temp->next !=NULL)&&(temp->next->element < element_)){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    size++;
}

template<typename T>
void LinkedList<T>::remove(int pos){
    Node<T> *temp= head;
    Node<T> *temp1= temp->next;
    if(pos<1 || pos> size){
        cout<<"FUERA DE RANGO"<<endl;
    }else{
        for(int i=2; i<=pos;i++){
            if(i==pos){
                Node<T> *aux= temp1;
                temp->next =temp1->next;
                delete aux;
                size--;
            }
            temp= temp->next;
            temp1=temp1->next;
        }
    }
}

template<typename T>
void LinkedList<T>::print(){
    Node<T> *temp = head;
    if(!head){
        cout<<"la lista esta vacia"<<endl;
    }else{
        while(temp){
            temp->print();
            if(!temp->next)cout<<"NULL";
                temp=temp->next;
        }
    }
    cout<<endl << endl;
}
template<typename T>
LinkedList<T>::~LinkedList(){}
#endif // LIST_H