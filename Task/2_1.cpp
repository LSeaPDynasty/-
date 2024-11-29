#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* intersect(Node *headA, Node *headB) {
    Node *result = NULL;
    Node *p = headA;
    Node *q = headB;

    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            insert(&result, p->data);
            p = p->next;
            q = q->next;
        } else if (p->data < q->data) {
            p = p->next;
        } else {
            q = q->next;
        }
    }

    return result;
}

int main() {
    Node *headA = NULL;
    Node *headB = NULL;

    printf("��������A��Ԫ�أ��Կո�ָ����س���������");
    int data;
    while (scanf("%d", &data) == 1) {
        insert(&headA, data);
        char c;
        //�����������
        scanf("%c", &c);
        if (c == '\n') break;
    }

    printf("��������B��Ԫ�أ��Կո�ָ����س���������");
    while (scanf("%d", &data) == 1) {
        insert(&headB, data);
        char c;
        scanf("%c", &c);
        if (c == '\n') break;
    }

    Node *intersection = intersect(headA, headB);

    printf("����Ϊ��");
    Node *p = intersection;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    freeList(headA);
    freeList(headB);
    freeList(intersection);

    return 0;
}