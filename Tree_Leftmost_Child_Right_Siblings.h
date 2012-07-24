#include <string>
#include <iostream>

using namespace std;
const int MAXNODES = 100;

typedef int node;
typedef int Tree;
typedef string labeltype;

struct cell{
	labeltype label;
	node leftmost_child;
	node right_sibling;
	node parent;
};

cell cellspace[MAXNODES+1];

int avail;

node Parent(node n,Tree T);
node Leftmost_Child(node n, Tree T);
node Right_Sibling(node n, Tree T);
labeltype Label(node n,Tree T);
Tree Create0(labeltype v);
Tree Create1(labeltype v,Tree T1);
Tree Create2(labeltype v,Tree T1,Tree T2);
Tree Create3(labeltype v,Tree T1,Tree T2,Tree T3);
node Root(Tree T);
void MAKENULL(Tree T);

node Parent(node n,Tree T){
	return cellspace[n].parent;
}

node Leftmost_Child(node n, Tree T){
	return cellspace[n].leftmost_child;
}
node Right_Sibling(node n, Tree T){
	return cellspace[n].right_sibling;
}

labeltype Label(node n,Tree T){
	return cellspace[n].label;
}

Tree Create0(labeltype v){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	return temp;
}

Tree Create1(labeltype v,Tree T1){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].leftmost_child = T1;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	return temp;
}

Tree Create2(labeltype v,Tree T1,Tree T2){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].leftmost_child = T1;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	cellspace[T1].right_sibling = T2;
	return temp;
}

Tree Create3(labeltype v,Tree T1,Tree T2,Tree T3){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].leftmost_child = T1;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	cellspace[T1].right_sibling = T2;
	cellspace[T2].right_sibling = T3;
	return temp;
}

node Root(Tree T){
	return T;
}

