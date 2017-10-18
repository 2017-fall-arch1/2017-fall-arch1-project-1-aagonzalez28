
#include <stdio.h>/* for printf */
#include <stdlib.h>/* for free() */
#include <string.h> /* for strlen */
#include "bst.h"/* for list operations */

int main(){
  bstNode *root = root = NULL;
  char command = 'c';
  char *string;


  while(command != 'c'){

    printf("Enter 'n' to enter a name\n" "Enter 'd' to delete a name\n"
	   "Enter 'l' for list of names\n" "Enter 'r' to read file\n"
	   "Enter 'w' to write name to file\n" "Enter 'e' to exit\n");

    scanf("%c",&command);

    if (command == 'n'){

      printf("Enter the name you want to add" );
      scanf("%s",string);
      root = addNode(root, string);
      
    }

    else if(command == 'd'){

	printf("Enter the name you want to delete: \n");
	scanf("%s",string);
	root = removeNode(root, string);

      }

    else if(command == 'l'){

	inOrder(root);

      }

    else if(command == 'r'){

	printf("Enter file to read\n");
	scanf("%s", string);
	root = readTxt(root, string);

      }

    else if(command == 'w'){

	printf("Enter the file to write\n");
	scanf("%s", string);

	FILE *file;
	file = fopen(string,"w");
	writeTxt(root,file);
	fclose(file);

      }

      getchar();

      }

    printf("Thank You! Please come back again.");

    root = freeMemory(root);
    
  }

bstNode* newbstNode (char* eName){
  
  bstNode *node = (bstNode*) malloc (sizeof(bstNode));
  node->string = malloc (strlen(eName)+1);
  strcpy (node->string,eName);
  node->left = NULL;
  node->right = NULL;
  return node;
    
}

bstNode* addNode (bstNode *root, char *eName){

  if (root == NULL)
    root = newbstNode(eName);
  
  int temp = strcmp(root->string, eName);
  if(temp > 0)
    root->right = addNode(root->right, eName);
  else if(temp < 0)
    root->left = addNode(root->left, eName);
  return root;
}

bstNode* removeNode(bstNode *root, char *eName){

  if (root == NULL)
    return root;

  int temp = strcmp(root->string, eName);
  if (temp > 0)
    root->right = removeNode(root->right, eName);
  else if (temp < 0)
    root->left = removeNode(root->left, eName);

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

    else if (root->right == NULL){

      temp1 = root->left;
      free(root->string);
      free(root);
      
      return temp1;
    }

    else{

      temp1 = root->right;
      temp2 = root->left;

      free(root->string);
      free(root);

      temp3->string = malloc(strlen(temp1->string)+1);
      
      strcpy(temp3->string, min(temp1)->string);
      temp3->left =  temp2;
      temp3->right = removeNode(temp1, temp3->string);

      return temp3;
    }
  }
}

bstNode* min(bstNode *root){

  if(root->left == NULL)
    return root;

  return min(root->left);
}

void inOrder(bstNode *root){

  if(root != NULL){
    inOrder(root->left);
    printf("%s\n", root->string);
    inOrder(root->right);
  }
}

bstNode* readTxt (bstNode *root, char *filename){

  FILE *file;
  file = fopen (filename, "r");

  if (file == NULL){

    printf ("File does not exist\n");

    return root;
  }
  char *string = (char*) malloc (sizeof(char*));

  while(!feof (file)){

    fscanf(file, "%s", string);
    root = addNode(root, string);
    
  }

  fclose(file);
  
  free(string);
  return root;
}

void writeTxt (bstNode *root, FILE *file){

  if(root != NULL){

    writeTxt(root->left, file);
    fprintf(file, "%s\n", root->string);
    writeTxt(root->right, file);
  }
}

bstNode* freeMemory(bstNode *root){

  while( root != NULL){

    root = removeNode(root, root->string);
  }
  return NULL;
}
/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
