#include <stdlib.h>
#include <stdio.h>

typedef char *data;
typedef int keyType;

struct tree{
		keyType key;
		data info;
		struct tree *left;
		struct tree *right;	
	};
	
void insertKey(keyType key, data x, struct tree **T);
void deleteKey(keyType key, struct tree **T);
struct tree *search(keyType key, struct tree *T);
struct tree *findMin(struct tree *T);
void printTree(struct tree *T);

int main(){
	
	struct tree *T = NULL;
	
	int i;
/* Insert 10 random key */
	for (i = 0; i < 10; i++) {
		int ikey = (rand() % 20) + 1;
		printf("Insert key  %d \n", ikey);
		insertKey(ikey, "someinfo", &T);
	}
	
	printf("Tree: ");
	
	printTree(T);
	
	printf("\n");
	
	return 0;
	}

struct tree *search(keyType key, struct tree *T){
		if (NULL == T) return NULL;
		else if (key < T->key) return search(key, T->left);
		else if (key > T->key) return search(key, T->right);
		else return T;
	}

void insertKey(keyType key, data x, struct tree **T){
		if(*T==NULL){
			*T=(struct tree *)malloc(sizeof(**T));
			(*T)->key=key;
			(*T)->left=NULL;
			(*T)->right=NULL;
		}
		else if((*T)->key<key){
			insertKey(key,x,&(*T)->left);
		}
		else if((*T)->key>key){
			insertKey(key,x,&(*T)->right);
			}
		else fprintf(stderr,"This key alredy exist");
	}
	
	
struct tree *findMin(struct tree *T)
{ 
	while (NULL != T->left) T = T->left;
		return T;
}

void deleteKey(keyType key, struct tree **T){
	if(*T==NULL){
		fprintf(stderr,"Is not exist");
	}
	else {
		if(key < (*T)->key){
				deleteKey(key,&(*T)->left);
			}
		else if(key > (*T)->key){
				deleteKey(key,&(*T)->right);
			}
		else // Element from delete is okey 
			if((*T)->left && (*T)->right){
					
				struct tree *replace= findMin((*T)->right);
					(*T)->key = replace->key;
					(*T)->info = replace->info;
					deleteKey((*T)->key,&(*T)->right);
			}
			else {
				struct tree *temp = *T;
				if ((*T)->left)
					*T = (*T)->left;
				else
					*T = (*T)->right;
				free(temp);				
				
			}
		}
	
	}
void printTree(struct tree *T)
{
	if (NULL == T) return;
	
	printf("%d ", T->key);
	printTree(T->left);
	printf(" ");
	printTree(T->right);
}
