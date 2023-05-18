#ifndef BENCHMAKER_DOUBLELIST_H
#define BENCHMAKER_DOUBLELIST_H
#include <iostream>
#include "Node.h"

using namespace std;

class DoubleList{
private:
    Node* head;
    Node* tail;
    Node* min;
    Node* max;

public:
    DoubleList():
            head(nullptr),
            tail(nullptr),
            min(nullptr),
            max(nullptr){}



    void insert(int data);
    void remove(int data);
    bool empty() const;
    bool contains(int value) const;
    Node* search(int value) const;
    void printByValue() const;
    void print() const;
};

bool DoubleList::empty() const{
    return head == nullptr;
}

void DoubleList::insert(int value){
    if(empty()){
        head = tail = min = max = new Node(value);
    }else{
        Node* temp = new Node(value);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;

        if(tail->data < min->data){
            min->prevByValue = tail;
            tail->nextByValue = min;
            min = tail;
        }else if(tail->data > max->data){
            max->nextByValue = tail;
            tail->prevByValue = max;
            max = tail;
        }else{
            Node* ptr = min;
            while(value > ptr->data){
                ptr = ptr->nextByValue;
            }
            ptr->prevByValue->nextByValue = tail;
            tail->prevByValue = ptr->prevByValue;
            ptr->prevByValue = tail;
            tail->nextByValue = ptr;
        }
    }

}


void DoubleList::printByValue() const {
    Node* temp = min;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->nextByValue;
    }
}

void DoubleList::print() const{
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool DoubleList::contains(int value) const{
    Node* temp = min;
    while(value > temp->data){
        temp = temp->nextByValue;
    }

    return temp->data == value;
}

Node* DoubleList::search(int value) const{
    Node* temp = head;
    while(temp->data != value){
        temp = temp->next;
    }

    return temp;
}

void DoubleList::remove(int value){
    if(!contains(value)){
        cout << "The value is not contained in the list" << endl;
        return;
    }

    Node* temp = head;
    while(temp->data != value){
        temp = temp->next;
    }

    if(temp->prev == nullptr){
        head = temp->next;
        head->prev = nullptr;
        if(temp->prevByValue == nullptr){
            min = temp->nextByValue;
            min->prevByValue = nullptr;
        }else if(temp->nextByValue == nullptr){
            max = temp->prevByValue;
            max->nextByValue = nullptr;
        }

        delete temp;
        return;
    }else if(temp->next == nullptr){
        tail = temp->prev;
        tail->next = nullptr;
        if(temp->prevByValue == nullptr){
            min = temp->nextByValue;
            min->prevByValue = nullptr;
        }else if(temp->nextByValue == nullptr){
            max = temp->prevByValue;
            max->nextByValue = nullptr;
        }

        delete temp;
        return;
    }



    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prevByValue->nextByValue = temp->nextByValue;
    temp->nextByValue->prevByValue = temp->prevByValue;

    delete temp;
}



#endif //BENCHMAKER_DOUBLELIST_H