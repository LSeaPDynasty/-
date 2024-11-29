/*
实验内容：二叉排序树。
	任意给定一组数据，设计一个算法，建立一棵二叉排序树，对它进行查找、插入、删除等操作。
实验说明：
二叉排序树存储结构如下：
typedef struct BiTNode { // 结点结构
    
    struct BiTNode  *lchild, *rchild; 
                                     // 左右孩子指针
} BiTNode, *BiTree;

二叉排序树插入算法伪代码如下：

1. 若root是空树，则将结点s作为根结点插入；否则
2. 若s->data＜root->data，则把结点s插入到root的左子树中；否则
3. 把结点s插入到root的右子树中。

二叉排序树中删除一个结点f的左孩子结点p算法伪代码如下：
1. 若结点p是叶子，则直接删除结点p；
  2. 若结点p只有左子树，则只需重接p的左子树；
     若结点p只有右子树，则只需重接p的右子树；   
  3. 若结点p的左右子树均不空，则
       3.1 查找结点p的右子树上的最左下结点s以及结点s的双亲结点par；
3.2 将结点s数据域替换到被删结点p的数据域；
3.3 若结点p的右孩子无左子树，则将s的右子树接到par的右子树上；
否则，将s的右子树接到结点par的左子树上；
3.4 删除结点s；
*/

#include <iostream>
using namespace std;

typedef struct BiTNode {
    int data;
    BiTNode *lchild, *rchild; 
} BiTNode, *BiTree;


void insert(BiTree &root, int value) {
    BiTNode *newNode = new BiTNode;
    newNode->data = value;
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;

    if (root == nullptr) {
        root = newNode;
    } else {
        BiTNode *current = root;
        while (true) {
            if (value < current->data) {
                if (current->lchild == nullptr) {
                    current->lchild = newNode;
                    break;
                }
                current = current->lchild;
            } else {
                if (current->rchild == nullptr) {
                    current->rchild = newNode;
                    break;
                }
                current = current->rchild;
            }
        }
    }
}


void deleteNode(BiTree &root, int value) {
    if (root == nullptr) {
        return; 
    }

    BiTNode *parent = nullptr;
    BiTNode *current = root;

    while (current != nullptr && current->data != value) {
        parent = current;
        if (value < current->data) {
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }

    if (current == nullptr) {
        return; 
    }

    if (current->lchild == nullptr && current->rchild == nullptr) {
        if (current == root) {
            root = nullptr;
        } else if (parent->lchild == current) {
            parent->lchild = nullptr;
        } else {
            parent->rchild = nullptr;
        }
        delete current;
    }

    else if (current->lchild == nullptr || current->rchild == nullptr) {
        BiTNode *child = (current->lchild != nullptr) ? current->lchild : current->rchild;
        if (current == root) {
            root = child;
        } else if (parent->lchild == current) {
            parent->lchild = child;
        } else {
            parent->rchild = child;
        }
        delete current;
    }

    else {
        BiTNode *successor = current->rchild;
        BiTNode *successorParent = current;

        while (successor->lchild != nullptr) {
            successorParent = successor;
            successor = successor->lchild;
        }

        current->data = successor->data;


        if (successorParent->lchild == successor) {
            successorParent->lchild = successor->rchild;
        } else {
            successorParent->rchild = successor->rchild;
        }
        delete successor;
    }
}

void inorderTraversal(BiTree root) {
    if (root != nullptr) {
        inorderTraversal(root->lchild);
        cout << root->data << " ";
        inorderTraversal(root->rchild);
    }
}

int main() {
    BiTree root = nullptr;

    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "插入后的中序遍历: ";
    inorderTraversal(root);
    cout << endl;

    deleteNode(root, 20);
    deleteNode(root, 30);
    deleteNode(root, 50);

    cout << "删除后的中序遍历: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}