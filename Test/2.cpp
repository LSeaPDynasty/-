/*
实验内容：一元多项式求和。
		把任意给定的两个一元多项式P(x)?,Q(x)?输入计算机，计算它们的和并输出计算结果。
实验说明：
		一元多项式可以用单链表表示，结点结构图示如下：
			coef->exp->next
		一元多项式算法伪代码如下：
        1. 工作指针p、q初始化；
        2. while（p存在且q存在）执行下列三种情形之一
            2.1 如果p->exp<q->exp，则指针p后移; 
            2.2 如果p->exp>q->exp，则
                2.2.1 将结点q插入到结点p之前；
                2.2.2 指针q指向原指结点的下一个结点；
            2.3 如果p->exp=q->exp，则
                2.3.1 p->coef =p->coef+q->coef；
                2.3.2 如果p->coef ==0，则执行下列操作，否则，指针p后移;
                    2.3.2.1 删除结点p；
                    2.3.2.2 使指针p指向它原指结点的下一个结点；
                2.3.3 删除结点q；
                2.3.4 使指针q指向它原指结点的下一个结点；
        3. 如果q不为空，将结点q链接在第一个单链表的后面；
*/

#include <stdio.h>
#include <stdlib.h>

// 定义多项式的节点结构
typedef struct Node {
    int coef; // 系数
    int exp;  // 指数
    struct Node* next; // 指向下一个节点的指针
} Node;

/* 创建新节点
 *@author lihuahua
*/
Node* createNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

/* 插入节点到链表末尾
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

/*打印多项式
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

/*多项式求和
 * @author lihuahua
 */
Node* addPolynomials(Node* p, Node* q) {
    Node* result = NULL;// 结果链表的头结点
    Node* tail = NULL;// 结果链表的尾结点

    while (p != NULL && q != NULL) {
        if (p->exp < q->exp) {// p 的指数小于 q 的指数
            if (result == NULL) {
                result = createNode(p->coef, p->exp);// 创建新节点
                tail = result;// 更新尾结点
            } else {
                tail->next = createNode(p->coef, p->exp);
                tail = tail->next;
            }
            p = p->next;
        } else if (p->exp > q->exp) {// p 的指数大于 q 的指数
            if (result == NULL) {
                result = createNode(q->coef, q->exp);
                tail = result;
            } else {
                tail->next = createNode(q->coef, q->exp);
                tail = tail->next;
            }
            q = q->next;
        } else {// 指数相等
            int sum = p->coef + q->coef;// 计算系数和
            if (sum != 0) {
                if (result == NULL) {// 结果链表为空
                    result = createNode(sum, p->exp);
                    tail = result;
                } else {// 结果链表不为空
                    tail->next = createNode(sum, p->exp);//
                    tail = tail->next;
                }
            }
            p = p->next;
            q = q->next;
        }
    }

    // 将剩余的节点添加到结果链表
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
/*释放链表内存
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

    // 打印多项式 P(x) 和 Q(x)
    printf("多项式 P(x): ");
    printPolynomial(p);
    printf("多项式 Q(x): ");
    printPolynomial(q);

    
    Node* result = addPolynomials(p, q);
    printf("多项式求和结果: ");
    printPolynomial(result);

    freePolynomial(result);
    freePolynomial(p);
    freePolynomial(q);

    return 0;
}






