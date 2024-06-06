#include "binary_trees.h"

/**
 * bst_min_value_node - Finds the node with the smallest value in a BST
 * @node: Pointer to the root of the tree
 * Return: Pointer to the node with the smallest value
 */
bst_t *bst_min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
	current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node with a specific value from a BST
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
	return (NULL);

	if (value < root->n)
	root->left = bst_remove(root->left, value);
	else if (value > root->n)
	root->right = bst_remove(root->right, value);

	else
	{
		if (root->left == NULL)
		{
		bst_t *temp = root->right;

		free(root);
		return (temp);
		}
		else if (root->right == NULL)
		{
		bst_t *temp = root->left;

		free(root);
		return (temp);
		}

		bst_t *temp = bst_min_value_node(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
