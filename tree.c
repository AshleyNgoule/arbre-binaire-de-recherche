#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

tree *New_Tree(int x)
{

  tree *tr = malloc(sizeof(*tr));

  if(tr == NULL)
  {
    fprintf(stderr, "ERREUR ALLOCATION MEMOIRE.\n");
    exit(EXIT_FAILURE);
  }

  tr->values = x;
  tr->tleft = NULL;
  tr->tright = NULL;
  tr->parent = NULL;

  printf("creaion de %d\n", tr->values);

  return tr;

}

void Clean_Tree(tree *tr)
{

  if(tr == NULL)
    return;
    

    Clean_Tree(tr->tleft);
    Clean_Tree(tr->tright);
    free(tr);
}

tree *Join_Tree(tree *left, tree *right, int node)
{
  tree *tr = New_Tree(node);

  tr->tleft = left;
  tr->tright = right;

  if(left != NULL)
    left->parent = tr;

  if(right != NULL)
    right->parent = tr;

    return tr;

}

void Print_Tree_Prefixe(tree *tr)
{

  if(tr == NULL)
    return;

  if(tr->parent != NULL)
    printf("(%d) -> (%d)\n", tr->parent->values, tr->values);
  else
    printf("(%d)\n", tr->values);

  if(tr->tleft != NULL)
    Print_Tree_Prefixe(tr->tleft);

  if(tr->tright != NULL)
    Print_Tree_Prefixe(tr->tright);


}

void Print_Tree_Postfixe(tree *tr)
{
  if(tr == NULL)
    return;

  if(tr->parent != NULL)
    printf("(%d) -> (%d)\n", tr->parent->values, tr->values);
  else
    printf("(%d)\n", tr->values);

  if(tr->tright != NULL)
    Print_Tree_Postfixe(tr->tright);

  if(tr->tleft != NULL)
    Print_Tree_Postfixe(tr->tleft);

}

void Print_Tree_infixe(tree *tr)
{
  if(tr != NULL)
  {
    Print_Tree_infixe(tr->tleft);
    printf("(%d)\n", tr->values);
    Print_Tree_infixe(tr->tright);
  }

}

int Count_Tree_Nodes(tree *tr)
{
   if(tr == NULL)
   return 0;

   return(Count_Tree_Nodes(tr->tleft) + Count_Tree_Nodes(tr->tright) + 1);
}

int Hauteur_Tree(tree *tr)
{
   int hg,hd;
   if(tr == NULL)
     return 0;
   else
     hg = Hauteur_Tree(tr->tleft);
     hd = Hauteur_Tree(tr->tright);

   if(hg > hd)
     return (hg+1);
   else
     return (hd+1);
}



