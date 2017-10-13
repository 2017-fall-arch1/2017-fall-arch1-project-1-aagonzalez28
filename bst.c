
#include <stdio.h>/* for printf */
#include <stdlib.h>/* for free() */
#include <string.h> /* for strlen */
#include "bst.h"/* for list operations */

int main(){
  bstNode *root = root = Null;
  char command = 'c';
  char *name;

  
}

bstNode* newbstNode( char* eName){
  bstNode *node = ( bstNode*) malloc ( sizeof(bstNode));
  node->string = malloc (strlen(eName)+1);
  strcpy( node->string,eName);
  node->left = Null;
  node->right = Null;
  return node;
    
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
