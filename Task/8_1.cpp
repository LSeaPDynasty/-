#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


void insertNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        head->prev = head;
        head->next = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void bidirectionalBubbleSort(Node* head) {
    if (head == nullptr || head->next == head) {
        return; 
    }

    bool swapped;
    Node* start = head;
    Node* end = head->prev;

    do {
        swapped = false;
        Node* current = start;
        while (current != end) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        end = current->prev;

        if (!swapped) break;

        swapped = false;
        current = end;
        while (current != start) {
            if (current->data < current->prev->data) {
                swap(current->data, current->prev->data);
                swapped = true;
            }
            current = current->prev;
        }
        start = current->next;
    } while (swapped);
}
void printList(Node* head) {
    if (head == nullptr) return;
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertNode(head, 10);
    insertNode(head, 5);
    insertNode(head, 15);
    insertNode(head, 20);
    insertNode(head, 2);

    cout << "原始链表: ";
    printList(head);

    bidirectionalBubbleSort(head);

    cout << "排序后的链表: ";
    printList(head);

    return 0;
}