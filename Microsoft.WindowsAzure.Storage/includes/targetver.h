#include <iostream>
using namespace std;
struct Node
{
	int x;
	Node *l, *r;
};
void Show(Node *&Tree)
{
	if (Tree != NULL)
	{
		Show(Tree->l);
		cout << endl << Tree->x;
		Show(Tree->r);
	}
}
void add(int x, Node *&Tree)
{
	if (NULL == Tree)
	{
		Tree = new Node;
		Tree->x = x;
		cout << endl << x;
		Tree->l = Tree->r = NULL;

	}
	if (x < Tree->x)
	{
		if (Tree->l != NULL) add(x, Tree->l);
		else                                          
		{
			Tree->l = new Node;                      
			Tree->l->l = Tree->l->r = NULL;        
			Tree->l->x = x; 
			cout << endl << x << "          ";
		}
	}
	if (x > Tree->x)
	{
		if (Tree->r != NULL) add(x, Tree->r); 
		else                                          
		{
			Tree->r = new Node;                      
			Tree->r->l= Tree->r->r = NULL;        
			Tree->r->x = x;  
			cout << endl << "         "  << x;
		}
	}
}
void del(Node *&Tree)
{
	if (Tree != NULL)
	{
		del(Tree->l);
		del(Tree->r);
		delete Tree;
	}
}
int main()
{
	Node *Tree = NULL;
	int A[18] = { 15,17,24,31,83,23,57,99,77,66,0,37,94,23,74,1,85,2};

	for (int i = 0; i <= 18; i++)
	{
		add(A[i], Tree);

	}
	
	del(Tree);

	system("pause");
	return 0;
}
