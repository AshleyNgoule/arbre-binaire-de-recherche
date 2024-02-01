#include<stdio.h>
#include<stdlib.h>

#include"tree.h"

int main(void)
{

  tree *arbre = Join_Tree(Join_Tree(New_Tree(2), New_Tree(7), 9), New_Tree(4), 5);
  Print_Tree_Prefixe(arbre);
  Print_Tree_Postfixe(arbre);
  Print_Tree_infixe(arbre);
  printf("nombre de nodes : %d\n", Count_Tree_Nodes(arbre));
  printf("hauteur de l'arbre : %d\n", Hauteur_Tree(arbre));
  Clean_Tree(arbre);
  
  

  return 0;
}