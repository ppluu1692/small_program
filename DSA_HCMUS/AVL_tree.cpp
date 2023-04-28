#include <iostream>
#include <queue>
using namespace std;

struct NODE{
    int key;
    NODE* p_left;
    NODE* p_right;
    int height;
};

NODE* createNode(int data) {
    NODE* newNode = new NODE;
    newNode->key = data;
    newNode->p_left = newNode->p_right = NULL;
    newNode->height = 0;
    return newNode;
}

void rightRotate(NODE* pRotate) {
    NODE* pivot = pRotate->p_left;
    NODE* Rpivot = pivot->p_right;

}

void leftRotate(NODE* pRotate) {
    return;
}

void Insert(NODE* &pRoot, int x) {
    if (pRoot == NULL) {
        pRoot = createNode(x);
    }
    else if (x < pRoot->key) {
        Insert(pRoot->p_left, x);
        int leftHeight = pRoot->p_left->height;
        int rightHeight = pRoot->p_right ? pRoot->p_right->height : -1;
        if (leftHeight - rightHeight > 1) {
            int LLHeight =  pRoot->p_left->p_left ? pRoot->p_left->p_left->height : 0;
            int LRHeight =  pRoot->p_left->p_right ? pRoot->p_left->p_right->height : 0;
            cout << pRoot->key << " " << LLHeight << " " << LRHeight << endl;
            if (LLHeight > LRHeight) {
                cout << "LL\n";
                // rightRotate(pRoot);
            }
            else {
                cout << "LR\n";
                // leftRotate(pRoot->p_left);
            //     // rightRotate(pRoot->p_right);
            // }
        }
        pRoot->height = 1 + max(leftHeight, rightHeight);
    }
    else if (x > pRoot->key) {
        Insert(pRoot->p_right, x);
        int leftHeight = pRoot->p_left ? pRoot->p_left->height : 0;
        int rightHeight = 1 + pRoot->p_right->height;
        pRoot->height = max(leftHeight, rightHeight);
    }
}

int height(NODE *NODE)
{
    if (NODE == NULL)
        return 0;
    return NODE->height;
}

void Insert(NODE* &pRoot, int x) {
    NODE* NODE = pRoot;
    NODE* parent = NULL;
    NODE* grandParent = NULL;
    NODE* greatGrandParent = NULL;
    while (NODE != NULL) {
        greatGrandParent = grandParent;
        grandParent = parent;
        parent = NODE;
        if (x == NODE->key) {
            return;
        }
        else if (x < NODE->key) {
            NODE = NODE->p_left;
        }
        else if (x > NODE->key) {
            NODE = NODE->p_right;
        }
    }

    if (pRoot == NODE) {
        pRoot = createNode(x);
        return;
    }

    NODE = createNode(x);
    if (parent == NULL) {
        return;
    }
    parent->height = 1 + max(height(parent->p_left), height(parent->p_right));
    if (grandParent == NULL) {
        return;
    }
    int balance = height(grandParent->p_left) - height(grandParent->p_right);
    if (balance > 1) {

    }

}
 
void LevelOrder(NODE* pRoot) {
    if (pRoot == NULL)
        return;
    queue<NODE*> Q;
    Q.push(pRoot);
    while (!Q.empty()) {
        pRoot = Q.front();
        if (pRoot->p_left != NULL)
            Q.push(pRoot->p_left);
        if (pRoot->p_right != NULL) 
            Q.push(pRoot->p_right);
        cout << Q.front()->key << "-" << Q.front()->height << "  ";
        Q.pop();
    }
}

int main() {
	NODE* pRoot = NULL;
    Insert(pRoot, 12);
    Insert(pRoot, 8);
    Insert(pRoot, 1);
    // Insert(pRoot, 11);
    // Insert(pRoot, 5);
    // Insert(pRoot, 17);
    // Insert(pRoot, 3);
    // Insert(pRoot, 4);

    LevelOrder(pRoot);
	// system("pause");
	return 0;
}