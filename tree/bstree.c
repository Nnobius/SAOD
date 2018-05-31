#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

bstree *bstree_create(char *key,int value)
{
	bstree *node;

	node = malloc( sizeof (*node) );
	
	if (node == NULL) { 
		printf("\nError of creating\n");
		return -1;
	} else {
		node -> key = strdup(key);;
		node -> left = NULL;
		node -> right = NULL;
		node -> value = value;
	}
	
	return node;

}

bstree_add(bstree *tree, char *key, int value)
{
	bstree *parent;
	bstree *node;

	if(tree == NULL) {
		return;
	}

	for (parent = tree; tree != NULL;) {
		parent = tree;
		if (strcmp(key,tree-> key) < 0) {
			tree = tree -> left;
		} else if(strcmp(key, tree -> key) > 0){
			tree = tree -> right;
		} else {
			return;
		}
	}

	node = bstree_create(key, value);

	if (strcmp(key, parent-> key) < 0) {
		parent -> left = node;
	} else {
		parent -> right = node;
	}	
}

bstree *bstree_lookup(bstree *tree, char *key) 
{
	while (tree != NULL) {
		if (strcmp(key, tree-> key) == 0 ) {
			return tree;
		} else if (strcmp(key, tree-> key) < 0) {
			tree = tree -> left;
		} else {
			tree = tree -> right;
		}
	}
	
	return tree;
}

bstree *bstree_min (bstree *tree) 
{
	if(tree== NULL) {
		return NULL;
	}

	while (tree -> left != NULL) {
		tree = tree -> left;
	}
	
	return tree;
}

bstree *bstree_max (bstree *tree) 
{
	if(tree == NULL) {
		return NULL;
	}

	while (tree -> right != NULL) {
		tree = tree -> right;
	}
	
	return tree;
}
		
void treeprint(bstree *tree) 
{
	if (tree!=NULL) {
		treeprint(tree->left);
		treeprint(tree->right); 
		printf("%s\n", tree -> key); 
	}
}