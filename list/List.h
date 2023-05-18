//
// Created by alen on 5/16/23.
//

#ifndef BENCHMAKER_LIST_H
#define BENCHMAKER_LIST_H

#include <iostream>
#include "Node.h"

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool empty(){
        return head == nullptr;
    }

    void remove(int value){
        if(this->empty()){
            return;
        }
        else if(head->data == value){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* current = head;
            while(current->next != nullptr){
                if(current->next->data == value){
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    break;
                }

                current = current->next;
            }
        };
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};


#endif //BENCHMAKER_LIST_H
