#include <stdio.h>
#include <tchar.h>
struct AVLNODE
{
	int Key;
	int bal; // thuộc tính cho biết giá trị cân bằng
	// 0: cân bằng, 1: lệch trái, 2: lệch phải
	AVLNODE* pLeft;
	AVLNODE* pRight;
};
AVLNODE* CreateNode(int Data)
{
	AVLNODE* pNode;
	pNode = new AVLNODE; //Xin cấp phát bộ nhớ động để tạo một phần tử (node)
	if (pNode == NULL) {
		return NULL;
	}
	pNode->Key = Data;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->bal = 0; // node mới được tạo là node lá nên node cân bằng
	return pNode;
}
void LeftRotate(AVLNODE*& P)
{
	AVLNODE* Q;
	Q = P->pRight;
	P->pRight = Q->pLeft;
	Q->pLeft = P;
	P = Q;
}
void RightRotate(AVLNODE*& P)
{
	// AVLNODE* Q;
	// Q = P->pLeft;
	// P->pLeft = Q->pRight;
	// Q->pRight = P;
	// P = Q;
}
void LeftBalance(AVLNODE*& P)
{
	switch (P->pLeft->bal) {
	case 1: //mất cân bằng trái trái
		RightRotate(P);
		P->bal = 0;
		P->pRight->bal = 0;
		break;
	case 2: // mất cân bằng trái-phải
		LeftRotate(P->pLeft);
		RightRotate(P);
		switch (P->bal) {
		case 0:
			P->pLeft->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1:
			P->pLeft->bal = 0;
			P->pRight->bal = 2;
			break;
		case 2:
			P->pLeft->bal = 1;
			P->pRight->bal = 0;
			break;
		} P
			->bal = 0;
		break;
	}
}
void RightBalance(AVLNODE*& P)
{
	switch (P->pRight->bal) {
	case 1: //mất cân bằng phải-trái
		RightRotate(P->pRight);
		LeftRotate(P);
		switch (P->bal) {
		case 0:
			P->pLeft->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1:
			P->pLeft->bal = 1;
			P->pRight->bal = 0;
			break;
		case 2:
			P->pLeft->bal = 0;
			P->pRight->bal = 2;
			break;
		} P
			->bal = 0;
		break;
	case 2: // mất cân bằng phải phải
		LeftRotate(P);
		P->bal = 0;
		P->pLeft->bal = 0;
		break;
	}
}
int InsertNode(AVLNODE*& tree, int x)
{
	int res;
	if (tree == NULL) { // đã tìm thấy vị trí thêm node
		tree = CreateNode(x);
		if (tree == NULL) {
			return -1; //thêm ko thành công vì thiếu bộ nhớ
		}
		return 2;//thêm thành công và làm tăng chiều cao cây
	}
	else {
		if (tree->Key == x) {
			return 0; //khóa này đã tồn tại trong cây
		}
		else if (tree->Key > x) {
			res = InsertNode(tree->pLeft, x);
			if (res < 2) {
				return res;
			}
			switch (tree->bal) { // vì node được insert vào cây bên phải nên cần thay đổi bal và cân bằng cây nếu mất cân bằng
			case 0:
				tree->bal = 1;
				return 2;
			case 1:
				LeftBalance(tree);
				return 1;
			case 2:
				tree->bal = 0;
				return 1;
			}
		}
		else {
			res = InsertNode(tree->pRight, x);
			if (res < 2) {
				return res;
			}
			switch (tree->bal) {
			case 0:
				tree->bal = 2;
				return 2;
			case 1:
				tree->bal = 0;
				return 1;
			case 2:
				RightBalance(tree);
				return 1;
			}
		}
	}
}
void Traverse(AVLNODE* t)
{
	if (t != NULL)
	{
		Traverse(t->pLeft);
		printf("Khoa: %d, can bang: %d\n", t->Key, t->bal);
		Traverse(t->pRight);
	}
}
void RemoveAll(AVLNODE*& t)
{
	if (t != NULL) {
		RemoveAll(t->pLeft);
		RemoveAll(t->pRight);
		delete t;
	}
}

AVLNODE* Search(AVLNODE* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	if (key > root->Key) {
		return Search(root->pRight, key);
	}
	if (key < root->Key) {
		return Search(root->pLeft, key);
	}
	return root;
}

int Height(AVLNODE* root) {
	if (root == NULL) {
		return 0;
	}
	int height_left = 1 + Height(root->pLeft);
	int height_right = 1 + Height(root->pRight);
	return height_left > height_right ? height_left : height_right;
}
int _tmain(int argc, _TCHAR* argv[])
{
	AVLNODE* tree;
	// khởi tạo một cây rỗng
	tree = NULL;
	int Data;
	do
	{
		printf("Nhap vao du lieu, -1 de ket thuc: ");
		scanf("%d", &Data);
		if (Data == -1)
			break;
		InsertNode(tree, Data);
	} while (Data != -1);
	printf("\nCay AVL vua tao: \n");
	Traverse(tree);
	RemoveAll(tree);
	return 0;
}