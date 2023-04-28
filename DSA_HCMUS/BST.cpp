#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

struct NODE {
    int key;
    NODE* p_left;
    NODE* p_right;
};

NODE* createNode(int data) {
    NODE* newNode = new NODE;
    newNode->key = data;
    newNode->p_left = NULL;
    newNode->p_right = NULL;
    return newNode;
}

void NLR(NODE* pRoot) {
    if (pRoot == NULL) 
        return;
    cout << pRoot->key << " ";
    NLR(pRoot->p_left);
    NLR(pRoot->p_right);
}

void LNR(NODE* pRoot) {
    if (pRoot == NULL) 
        return;
    LNR(pRoot->p_left);
    cout << pRoot->key << " ";
    LNR(pRoot->p_right);
}

void LRN(NODE* pRoot) {
    if (pRoot == NULL) 
        return;
    LRN(pRoot->p_left);
    LRN(pRoot->p_right);
    cout << pRoot->key << " ";
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
        cout << Q.front()->key << " ";
        Q.pop();
    }
}

NODE* Search(NODE* pRoot, int x) {
    if (pRoot == NULL || pRoot->key == x) {
        return pRoot;
    }
    if (x < pRoot->key) {
        return Search(pRoot->p_left, x);
    }
    if (x > pRoot->key) {
        return Search(pRoot->p_right, x);
    }
}

void Insert(NODE* &pRoot, int x) {
    if (pRoot == NULL)
        pRoot = createNode(x);
    if (x < pRoot->key)
        Insert(pRoot->p_left, x);
    if (x > pRoot->key)
        Insert(pRoot->p_right, x);
}

void Remove(NODE* &pRoot, int x) {
    NODE* pPre = pRoot;
    NODE* pDel = pRoot;
    while (pDel != NULL && x != pDel->key) {
        pPre = pDel;
        pDel = x < pDel->key ? pDel->p_left : pDel->p_right;
    }
    
    if (pDel == NULL) 
        return;
    
    if (pDel->p_left == NULL && pDel->p_right == NULL) {
        if (pDel == pRoot) {
            pRoot = NULL;
        }
        pPre->p_left == pDel ? pPre->p_left = NULL : pPre->p_right = NULL;
        delete pDel;
        pDel = NULL;
    }
    else if (pDel->p_left == NULL || pDel->p_right == NULL) {
        NODE* pChild = pDel->p_left ? pDel->p_left : pDel->p_right;
        if (pDel == pRoot) {
            pRoot = pChild;
        }
        else {
            pPre->p_left == pDel ? pPre->p_left = pChild : pPre->p_right = pChild;
        }
        delete pDel;
        pDel = NULL;
    }
    else {
        NODE* preSuccessor = pDel;
        NODE* successor = pDel->p_left;
        while (successor->p_right != NULL) {
            preSuccessor = successor;
            successor = successor->p_right;
        }
        preSuccessor->p_left == successor ? preSuccessor->p_left = successor->p_left : preSuccessor->p_right = successor->p_left;
        pDel->key = successor->key;
        delete successor;
        successor = NULL;
    }
}

NODE* createTree(int a[], int n) {
    NODE* pRoot = NULL;
    for (int i = 0; i < n; i++) {
        Insert(pRoot, a[i]);
    }
    return pRoot;
}

void removeTree(NODE* &pRoot) {
    if (pRoot == NULL)
        return;
    removeTree(pRoot->p_left);
    removeTree(pRoot->p_right);
    delete pRoot;
    pRoot = NULL;
}

int Height(NODE* pRoot) {
    if (pRoot == NULL)
        return -1;
    return 1 + max(Height(pRoot->p_left), Height(pRoot->p_right));
}

int countNode(NODE* pRoot) {
    if (pRoot == NULL) 
        return 0; 
    return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}

int sumNode(NODE* pRoot) {
    if (pRoot == NULL)
        return 0;
    return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}

int heightNode(NODE* pRoot, int value) {
    NODE* pCur = pRoot;
    int height = 0;
    while (pCur != NULL) {
        if (pCur->key == value)
            return height;
        height++;
        pCur = value < pCur->key ? pCur->p_left : pCur->p_right;
    }
    return -1;
}

int countLeaf(NODE* pRoot) {
    if (pRoot == NULL)
        return 0;
    if (pRoot->p_left == NULL && pRoot->p_right == NULL)
        return 1;
    else if (pRoot->p_left == NULL || pRoot->p_right == NULL)
        return pRoot->p_left ? countLeaf(pRoot->p_left) : countLeaf(pRoot->p_right);    
    else
        return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}

int countLess(NODE* pRoot, int x) {
    if (pRoot == NULL)
        return 0;
    if (pRoot->key < x)
        return 1 + countNode(pRoot->p_left) + countLess(pRoot->p_right, x);
    return countLess(pRoot->p_left, x);
}

int countGreater(NODE* pRoot, int x) {
    if (pRoot == NULL)
        return 0;
    if (pRoot->key > x) 
        return 1 + countNode(pRoot->p_right) + countGreater(pRoot->p_left, x);
    return countGreater(pRoot->p_right, x);
}

int findMax(NODE* pRoot) {
    if (pRoot == NULL)
        return -INT_MAX;
    return max(pRoot->key, max(findMax(pRoot->p_left), findMax(pRoot->p_right)));   
}

int findMin(NODE* pRoot) {
    if (pRoot == NULL)
        return INT_MAX;
    return min(pRoot->key, min(findMin(pRoot->p_left), findMin(pRoot->p_right)));   
}

bool isBST(NODE* pRoot) {
    if (pRoot == NULL)
        return 1;
    bool checkNode = pRoot->key > findMax(pRoot->p_left) && pRoot->key < findMin(pRoot->p_right);
    return checkNode && isBST(pRoot->p_left) && isBST(pRoot->p_right);
}

bool isFullBST(NODE* pRoot) {
    if (pRoot == NULL)
        return 1;
    bool checkNode = pRoot->key > findMax(pRoot->p_left) && pRoot->key < findMin(pRoot->p_right);
    bool checkChild = (pRoot->p_left == NULL) == (pRoot->p_right == NULL);
    bool checkLR = isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
    return checkNode && checkChild && checkLR;
}
int main() {
    // srand(time(NULL));
    // NODE* pRoot = NULL;
    // Insert(pRoot, 49);
    // Insert(pRoot, 23);
    // Insert(pRoot, 93);
    // Insert(pRoot, 80);
    // Insert(pRoot, 97);
    // Insert(pRoot, 86);
    // Insert(pRoot, 50);
    // Insert(pRoot, 80);
    // Insert(pRoot, 87);
    // for (size_t i = 0; i < 12; i++)
    // {
    //     int rd = rand()%100;
    //     Insert(pRoot, rd);
    //     cout << rd << ", ";
    // }
    // cout << endl;
    // LevelOrder(pRoot);
    // cout << endl;
    // cout << endl << isFullBST(pRoot);
    // cout << endl;
    // LevelOrder(pRoot);
    // cout << "\n" << countLeaf(pRoot) <<endl;
    // int x(1);
    // while (x) {
    //     cout << "\nnhap x: ";
    //     cin >> x;
    //     cout << countLess(pRoot, x) << endl;
    //     cout << countGreater(pRoot, x) << endl;
    // }
    NODE* pRoot = NULL;
    Insert(pRoot, 12);
    Insert(pRoot, 8);
    Insert(pRoot, 18);
    Insert(pRoot, 11);
    Insert(pRoot, 5);
    Insert(pRoot, 17);
    Insert(pRoot, 4);
    LevelOrder(pRoot);
	// system("pause");
    return 0;
}