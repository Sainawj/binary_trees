#include "binary_trees.h"

/**
 * successor - Find the in-order successor (minimum value-right subtree)
 * @node: The node to check
 * Return: The value of the in-order successor
 */
int successor(bst_t *node)
{
	while (node && node->left)
	node = node->left;
	return (node ? node->n : 0);
}

/**
 * remove_node - Remove a node from the BST
 * @node: The node to remove
 * Return: Pointer to the node to replace the removed node (if any)
 */
bst_t *remove_node(bst_t *node)
{
	bst_t *temp = NULL;

	if (!node->left && !node->right)
	{
		free(node);
		return (NULL);
	}
		if (!node->left)
	{
		temp = node->right;
		temp->parent = node->parent;
		free(node);
		return (temp);
	}
		if (!node->right)
		{
		temp = node->left;
		temp->parent = node->parent;
		free(node);
		return (temp);
		}

/* Node with two children */
	node->n = successor(node->right);
	node->right = bst_remove(node->right, node->n);
	return (node);
}

/**
 * bst_remove - Remove a node from a BST
 * @root: The root of the tree
 * @value: The value to remove
 * Return: Pointer to the new root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
		root = remove_node(root);

	return (root);
}
