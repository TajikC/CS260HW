#include <stdio.h>
#include <stddef.h>

const int MAXNODES= 100;

typedef int node;
typedef struct{
	node node;
	int next;
}cellspace[MAXNODES+1];

typedef int list;
typedef int labeltype;

typedef struct{
	list headers[MAXNODES+1];
	labeltype labels[MAXNODES+1];
}Tree;

node Parent(node n,Tree T);
node Leftmost_Child(node n, Tree T);
node Right_Sibling(node n, Tree T);
labeltype Label(node n,Tree T);
Tree Create0(labeltype l);
Tree Create1(labeltype l,Tree T1);
Tree Create2(labeltype l,Tree T1,Tree T2);
Tree Create3(labeltype l,Tree T1,Tree T2,Tree T3);
node Root(Tree T);
void MAKENULL(Tree T);

const cellspace cellspace;
node Parent(node n,Tree T){ //Return the Parent of node n of Tree T
	for (int p=1;p<MAXNODES;p++){
		list l = T.headers[p];
		while (l != 0){ // if i is not a leaf node
			if (cellspace[l].node == n)
				return l;
			else
				l =cellspace[l].next;
		}
	}
	return 0; // No parent is found, root
};

node Leftmost_Child(node n, Tree T){
	list l = T.headers[n];
	if (l==0)//n is a leaf
		return 0;
	else
		return cellspace[l].node;
};

node Right_Sibling(node n, Tree T){
	node parent_node = Parent(n,T);
	if (parent_node == 0){
		return 0; // n is the root node, no right_sibling.
	}
	list l = T.headers[parent_node];
	while ( cellspace[l].node != n){ // Move pass all the left siblings of the node
		l = cellspace[l].next;
	}
	l = cellspace[l].next; // move pass the node n itself;
	if (cellspace[1].node != n)
		return cellspace[1].node;
	else
		return 0; //node n is the right most children of the parent, no more right siblings.
};

labeltype Label(node n,Tree T){
	return T.labels[n];
};

Tree Create0(labeltype l){
	Tree new_T;
	new_T.headers[1] = 0;
	new_T.labels[1] = l;
};

Tree Create1(labeltype l,Tree T1);
Tree Create2(labeltype l,Tree T1,Tree T2);
Tree Create3(labeltype l,Tree T1,Tree T2,Tree T3);
node Root(Tree T){
	node root = 0;
	for (node i=1; i<=MAXNODES;i++){
		if (T.headers[i] == 0)
			root = i;
	}
	return root;
}
void MAKENULL(Tree& T){
	for(node i=1;i<=MAXNODES;i++){
		T.headers[i] = 0;
		T.labels[i] = 0;
	}
};

