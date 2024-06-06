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

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowable value.
 * @max: Maximum allowable value.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree->n - 1) &&
		binary_tree_is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowable value.
 * @max: Maximum allowable value.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (!binary_tree_is_bst(tree, min, max))
		return (0);

	int left_height = tree->left ? binary_tree_height(tree->left) : 0;
	int right_height = tree->right ? binary_tree_height(tree->right) : 0;

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left, min, tree->n - 1) &&
		binary_tree_is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_helper(tree, INT_MIN, INT_MAX));
}
