#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete_recursive(tree, 0, binary_tree_count(tree)));
}

/**
 * binary_tree_count - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The number of nodes in the tree
 */
size_t binary_tree_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_count(tree->left) + binary_tree_count(tree->right));
}

/**
 * is_complete_recursive - Recursively checks if a binary tree is complete
 * @tree: Pointer to the current node in the recursion
 * @index: Index of the current node in level-order traversal
 * @count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree,
		size_t index, size_t count)
{
	if (!tree)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, count) &&
			is_complete_recursive(tree->right, 2 * index + 2, count));
}
