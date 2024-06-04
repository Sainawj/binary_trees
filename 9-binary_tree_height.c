#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
	return (0);
	}

/* Calculate the height of the left subtree */
	size_t left_height = (tree->left != NULL) ? 1 + binary_tree_height(tree->left) : 0;

/* Calculate the height of the right subtree */
	size_t right_height = (tree->right != NULL) ? 1 + binary_tree_height(tree->right) : 0;

/* Return the maximum height between the left and right subtrees */
	return ((left_height > right_height) ? left_height : right_height);
}
