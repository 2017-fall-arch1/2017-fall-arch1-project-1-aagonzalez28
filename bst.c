
#include <stdio.h>/* for printf */
#include <stdlib.h>/* for free() */
#include <string.h> /* for strlen */
#include "bst.h"/* for list operations */

int main(){
  bstNode *root = root = Null;
  char command = 'c';
  char *name;

  
}

bstNode* newbstNode (char* eName){
  
  bstNode *node = (bstNode*) malloc (sizeof(bstNode));
  node->string = malloc (strlen(eName)+1);
  strcpy (node->string,eName);
  node->left = Null;
  node->right = Null;
  return node;
    
}

bstNode* addNode (bstNode *root, char *eName){

  if (root == Null)
    root = newnewbstNode(eName);
  
  int temp = strcmp(root-> string,eName);
  if(temp > 0)
    root->left = addNode(root->left,eName);
  else if(temp < 0)
    root->right = addNode(root->right, eName);
  return root;
}

bstNode* removeNode(bstNode *root, char *eName){

  if (root == Null)
    return root;

  int temp = strcmp(root->string, eName);
  if (temp > 0)
    root->left = removeNode(root->left, eName);
  else if (temp < 0)
    root->right = removeNode(root->right, eName);

  else{

    bstNode *temp1 = (bstNode*) malloc(sizeof(bstNode));
    bstNode *temp2 = (bstNode*) malloc(sizeof(bstNode));
    bstNode *temp3 = (bstNode*) malloc(sizeof(bstNode));

    if (root->left == NULL){

      temp1 = root->right;
      free(root->string);
      free(root);
      
      return temp1;
    }

    else if (root->right == Null){

      temp1 = root->left;
      free(root->string);
      free(root);
      
      return temp1;
    }

    else{

      temp1 = root->right;
      temp2 = root-> left;

      free(root->string);
      free(root);

      temp3->string = malloc(strlen(tem1->name)+1);
      
      strcpy(temp3->string, min(temp1)->string);
      temp3->left =  temp2;
      temp3->right = removeNode(temp1, temp3->string);

      return temp3;
    }
  }
}



/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */

int gets_n(char *s, int limit)

{

  char *p = s;/* for indexing into s */

  char c;

  if (fgets(s, limit, stdin)) {

    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */

      p++;

    if (c == '\n')/* erase \n */

      *p = 0;

  }

    return (p - s);/* #chars read (not including terminator or \n*/

  } 
