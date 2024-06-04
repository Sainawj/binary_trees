#include "binary_trees.h"

/**
 * binary_tree_depth - Compute the depth of a node in a binary tree
 * @tree: Pointer to the node to compute the depth for
 *
 * Return: Depth of the node from the root (0 if root or NULL)
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
	{
		return (0);
	}
	else
	{
		return (1 + binary_tree_depth(tree->parent));
	}
}
