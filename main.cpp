#include "Tree_Leftmost_Child_Right_Siblings.h"
#include <iostream>

int main(){
	//initialize cellspace to all available
	avail =1;
	for (int i=1;i<=MAXNODES;i++){
		cellspace[i].right_sibling = i+1;
		cellspace[i].leftmost_child = 0;
	}
//	  A
//	 / \
//  B   C--
// /\   /\ \
//D  E  F G H
	// Get all the leaves
	Tree TH = Create0((labeltype) "H");
	Tree TG = Create0((labeltype) "G");
	Tree TF = Create0((labeltype) "F");
	Tree TE = Create0((labeltype) "E");
	Tree TD = Create0((labeltype) "D");
	Tree TBDE = Create2((labeltype) "B",TD,TE);
	Tree TCFGH = Create3((labeltype) "C",TF,TG,TH);
	Tree T = Create2((labeltype) "A",TBDE,TCFGH);
	cout << "The root is " + cellspace[T].label + ". The root should be A"<<endl;
	node D = cellspace[cellspace[T].leftmost_child].leftmost_child;

	cout << "The leftmost leaf is " + cellspace[D].label + ". It should be D"<<endl;

	node C = cellspace[cellspace[T].leftmost_child].right_sibling;

	cout << "The right sibling of node B is " + cellspace[C].label + ". It should be C"<<endl;
	node F = cellspace[C].leftmost_child;
	cout << "The leftmost child of node C is " + cellspace[F].label + ". It should be F"<<endl;
	node G = cellspace[F].right_sibling;
	cout << "The right sibling of node F is " + cellspace[G].label + ". It should be G"<<endl;
	node H = cellspace[G].right_sibling;
	cout << "The right sibling of node G is " + cellspace[H].label + ". It should be H"<<endl;
	return 0;
}
