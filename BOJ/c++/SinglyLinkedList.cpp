#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node() {
            value = 0;
            next = NULL;
        }
        Node(int value) {
            this->value = value;
            next = NULL;
        }
};

class linkedList {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        linkedList() {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        linkedList(int value) {
            Node* n = new Node(value);
            head =  n;
            tail = n;
            size = 1;
        }
        void insertNode(int value) {
            Node* n = new Node(value);
            tail->next = n;
            tail = n;
            size++;
        }
        void printList() {
            Node* nowNode = head;
            for(int i=0;i<size;i++) {
                cout << nowNode->value << endl;
                if(nowNode->next != NULL) {
                    nowNode = nowNode->next;
                }
                else {
                    break;
                }
            }
        }
        void removeNode(int index) {
            if(index < 0 || index >= size) {
                cout << "Invalid index range" << endl;
            }
            else {
                if(index == 0) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                else {
                    Node* nowNode = head;
                    for(int i=0;i<size;i++) {
                        if(i == index-1) {
                            Node* temp = nowNode->next;
                            nowNode->next = nowNode->next->next;
                            size--;
                            delete temp;
                            break;
                        }
                        else {
                            nowNode = nowNode->next;
                        }
                    }
                }
            }
            
        }
};

int main()
{
    linkedList a = linkedList(1);

    a.insertNode(2);
    a.insertNode(3);
    a.insertNode(4);
    a.insertNode(5);
    a.insertNode(6);
    a.printList();
    a.removeNode(3);
    a.printList();
}