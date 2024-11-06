/*
ʵ�����ݣ�һԪ����ʽ��͡�
		���������������һԪ����ʽP(x)?,Q(x)?�����������������ǵĺͲ������������
ʵ��˵����
		һԪ����ʽ�����õ������ʾ�����ṹͼʾ���£�
			coef->exp->next
		һԪ����ʽ�㷨α�������£�
        1. ����ָ��p��q��ʼ����
        2. while��p������q���ڣ�ִ��������������֮һ
            2.1 ���p->exp<q->exp����ָ��p����; 
            2.2 ���p->exp>q->exp����
                2.2.1 �����q���뵽���p֮ǰ��
                2.2.2 ָ��qָ��ԭָ������һ����㣻
            2.3 ���p->exp=q->exp����
                2.3.1 p->coef =p->coef+q->coef��
                2.3.2 ���p->coef ==0����ִ�����в���������ָ��p����;
                    2.3.2.1 ɾ�����p��
                    2.3.2.2 ʹָ��pָ����ԭָ������һ����㣻
                2.3.3 ɾ�����q��
                2.3.4 ʹָ��qָ����ԭָ������һ����㣻
        3. ���q��Ϊ�գ������q�����ڵ�һ��������ĺ��棻
*/

#include <stdio.h>
#include <stdlib.h>

// �������ʽ�Ľڵ�ṹ
typedef struct Node {
    int coef; // ϵ��
    int exp;  // ָ��
    struct Node* next; // ָ����һ���ڵ��ָ��
} Node;

/* �����½ڵ�
 *@author lihuahua
*/
Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

/* ����ڵ㵽����ĩβ
 *@author lihuahua
*/
void insertNode(Node** head, int coef, int exp) {
    Node* newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/*��ӡ����ʽ
 *@author lihuahua
*/
void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

/*����ʽ���
 * @author lihuahua
 */
Node* addPolynomials(Node* p, Node* q) {
    Node* result = NULL;// ��������ͷ���
    Node* tail = NULL;// ��������β���

    while (p != NULL && q != NULL) {
        if (p->exp < q->exp) {// p ��ָ��С�� q ��ָ��
            if (result == NULL) {
                result = createNode(p->coef, p->exp);// �����½ڵ�
                tail = result;// ����β���
            } else {
                tail->next = createNode(p->coef, p->exp);
                tail = tail->next;
            }
            p = p->next;
        } else if (p->exp > q->exp) {// p ��ָ������ q ��ָ��
            if (result == NULL) {
                result = createNode(q->coef, q->exp);
                tail = result;
            } else {
                tail->next = createNode(q->coef, q->exp);
                tail = tail->next;
            }
            q = q->next;
        } else {// ָ�����
            int sum = p->coef + q->coef;// ����ϵ����
            if (sum != 0) {
                if (result == NULL) {// �������Ϊ��
                    result = createNode(sum, p->exp);
                    tail = result;
                } else {// �������Ϊ��
                    tail->next = createNode(sum, p->exp);//
                    tail = tail->next;
                }
            }
            p = p->next;
            q = q->next;
        }
    }

    // ��ʣ��Ľڵ���ӵ��������
    while (p != NULL) {
        tail->next = createNode(p->coef, p->exp);
        tail = tail->next;
        p = p->next;
    }
    while (q != NULL) {
        tail->next = createNode(q->coef, q->exp);
        tail = tail->next;
        q = q->next;
    }

    return result;
}
/*�ͷ������ڴ�
 * @author lihuahua
 */
    void freePolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    Node* p = NULL;
    Node* q = NULL;

    //P(x)
    insertNode(&p, 3, 2);
    insertNode(&p, 5, 1);
    insertNode(&p, 6, 0);

    //Q(x)
    insertNode(&q, 4, 3);
    insertNode(&q, 2, 2);
    insertNode(&q, 7, 0);

    // ��ӡ����ʽ P(x) �� Q(x)
    printf("����ʽ P(x): ");
    printPolynomial(p);
    printf("����ʽ Q(x): ");
    printPolynomial(q);

    
    Node* result = addPolynomials(p, q);
    printf("����ʽ��ͽ��: ");
    printPolynomial(result);

    freePolynomial(result);
    freePolynomial(p);
    freePolynomial(q);

    return 0;
}






