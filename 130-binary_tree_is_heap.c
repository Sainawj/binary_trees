#include "binary_trees.h"

/**
 * is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root of the binary tree.
 * @index: Index of the current node.
 * @node_count: Total number of nodes in the binary tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_max_heap - Checks if a binary tree is a valid max heap.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is a valid max heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left != NULL && tree->n < tree->left->n) ||
		(tree->right != NULL && tree->n < tree->right->n))
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int node_count;

	if (tree == NULL)
		return (0);

/* Count total number of nodes */
	node_count = binary_tree_size(tree);

/* Check if the tree is complete and a valid max heap */
	return (is_complete(tree, 0, node_count) && is_max_heap(tree));
}
