#include "binary_trees.h"

/**
 * tree_is_perfect - Checks if a tree is perfect
 * A perfect tree has the same quantity of levels in the left subtree as the right,
 * and each node has either 2 children or no children.
 * @tree: Tree to check
 * Return: 0 if it is not perfect, else the level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree->left && tree->right)
	{
		left_height = 1 + tree_is_perfect(tree->left);
		right_height = 1 + tree_is_perfect(tree->right);

		if (right_height == left_height && right_height != 0 && left_height != 0)
		return (right_height);

		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * A perfect binary tree has the same quantity of levels in the left subtree as the right,
 * and each node has either 2 children or no children.
 * @tree: Tree to check
 * Return: 1 if it is perfect, 0 if it is not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);

	result = tree_is_perfect(tree);

	if (result != 0)
	return (1);

	return (0);
}
