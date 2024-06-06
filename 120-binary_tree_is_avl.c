#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	size_t right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * bal_avl - Helper function to check if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @lower: Lower bound of valid node values.
 * @high: Upper bound of valid node values.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	if (tree == NULL)
	return (1);

	if (tree->n < lower || tree->n > high)
		return (0);

	size_t height_l = binary_tree_height(tree->left);
	size_t height_r = binary_tree_height(tree->right);
	size_t balancer = (height_l > height_r)
		? height_l - height_r : height_r - height_l;

	if (balancer > 1)
	return (0);

	return (bal_avl(tree->left, lower, tree->n - 1)
			&& bal_avl(tree->right, tree->n + 1, high));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (bal_avl(tree, INT_MIN, INT_MAX));
}
