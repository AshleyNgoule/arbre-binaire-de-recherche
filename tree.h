#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED


typedef struct tree
{
  int values;
  struct tree *tleft;
  struct tree *tright;
  struct tree *parent;
}tree;

tree *New_Tree(int x);
void Clean_Tree(tree *tr);
tree *Join_Tree(tree *left, tree *right, int node);
void Print_Tree_Prefixe(tree *tr);
void Print_Tree_Postfixe(tree *tr);
void Print_Tree_infixe(tree *tr);
int Count_Tree_Nodes(tree *tr);
int Hauteur_Tree(tree *tr);

#endif
