#include <stdlib.h>
#include <stdio.h>

struct tree_el{
	int val;
	struct tree_el *right, *left;
	};

typedef struct tree_el node;

void insert(node ** tree,node * item){
	if(!(*tree)){
		*tree=item;
		return;
	}
	if(item->val < (*tree)->val){
		insert(&(*tree)->left, item);
	}
	else if(item->val > (*tree)->val){
		insert(&(*tree)->right, item);
	}
}

void printOut(node *tree){
	
	if(tree->left) printOut(tree->left);
	printf("%d \n", tree->val);
	if(tree->right) printOut(tree->right);
	}
	
int main(){
	 node *curr, *root;
	 int i;
	 
	 root=NULL;
	 for(i=0;i<10;i++){
		curr= (node *)malloc(sizeof(node));
		curr->left=curr->right=NULL;
		curr->val=(rand() % 20) + 1;
		printf("%d ",curr->val);
		insert(&root,curr);
	  }
	
	printOut(root);
	
	return 0;
	}
