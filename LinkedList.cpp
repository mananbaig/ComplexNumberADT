# include "LinkedList.h"
# include"Node.h"
# include <iostream>
using namespace std;
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList()
{
    while (head != nullptr) 
    {
        deleteAtHead();
    }
}
void LinkedList::addAtHead(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) 
    {
      
        
       tail = newNode;
    }
}
v/*oid LinkedList::addAtTail(int value)
{
    if (tail == nullptr) 
    {
        tail = new Node(value);
    }
    else
    {
        Node* newNode = head;
        while (newNode->next != nullptr)
        {
            newNode = newNode->next;
            newNode->next = new Node(value);
        }
    }
}*/
void LinkedList::addBefore(int targetValue, int newValue) {
    if (head == nullptr)
    {
        return;
    }
    if (head->data == targetValue)
    {
        addAtHead(newValue);
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr->data != targetValue) 
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr != nullptr) 
    {
        Node* newNode = new Node(newValue);
        prev->next = newNode;
        newNode->next = curr;
    }
}
void LinkedList::addAfter(int targetValue, int newValue)
{
    if (!head)
    {
        return;
    }
    Node* curr = head;
    while (curr->data != targetValue)
    {
        curr = curr->next;
    }
    if (curr != nullptr)
    {
        Node* newNode = new Node(newValue);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}
void LinkedList::deleteAtHead()
{
    if (head == nullptr)
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    if (head == nullptr) 
    {
        tail = nullptr;
    }
}
void LinkedList::addAtTail(int value)
{
    Node* newNode = new Node(value);
    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void LinkedList::display()
{
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}
int LinkedList::getSize()
{
    if (!head)
    {
        return;
    }
    Node* curr = head;
    int i = 0;
    while (curr != nullptr)
    {
        i++;
        curr = curr->next;
    }
    return i;
}
void LinkedList::deleteAfter(int targetValue)
{
    Node* curr = head;
    while (curr != nullptr && curr->data != targetValue)
    {
        curr = curr->next;
    }
    if (curr != nullptr && curr->next != nullptr) 
    { 
        Node* temp = curr->next;
        curr->next = temp->next;
        if (temp == tail)
        {
            tail = curr;
        }
        delete temp;
    }
}