#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if a node is a root
 * A root node is a node with no parent.
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
/* Check if the node is NULL or has a parent */
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
