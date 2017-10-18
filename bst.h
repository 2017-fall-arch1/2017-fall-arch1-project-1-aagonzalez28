#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bstNode{

  char *string;              /* Definig the char */
  
  struct bstNode *left;      /* Definig the left node */
  struct bstNode *right;     /* Definig the right node */
  
}
  bstNode;

bstNode* newbstNode(char*);

bstNode* addNode(bstNode*, char*);

bstNode* removeNode(bstNode*, char*);

bstNode* min(bstNode*);

void inOrder(bstNode*);

bstNode* readTxt(bstNode*, char*);

void* writeTxt(bstNode*, File*);

bstNode* freeMemory(bstNode*);


#endif
