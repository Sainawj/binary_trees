#include "binary_trees.h"

/**
 * balance_avl_tree - Measures and adjusts the balance factor of an AVL tree.
 * @tree: Double pointer to the root of the tree.
 */
void balance_avl_tree(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_avl_tree(&(*tree)->left);
	balance_avl_tree(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the smallest node in the right subtree.
 * @node: Pointer to the node to check.
 * Return: The minimum value in the right subtree.
 */
int find_successor(bst_t *node)
{
	int left_value;

	if (node == NULL)
		return (0);

	left_value = find_successor(node->left);

	return (left_value == 0 ? node->n : left_value);
}

/**
 * remove_node - Removes a node from a BST based on its children.
 * @node: Pointer to the node to be removed.
 * Return: 0 if the node has no children, or the successor value if it does.
 */
int remove_node(bst_t *node)
{
	int new_value;

	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent->right == node)
		node->parent->right = NULL;
		else
		node->parent->left = NULL;
		free(node);
		return (0);
	}

	if (node->left == NULL || node->right == NULL)
	{
		bst_t *child = node->left ? node->left : node->right;

		if (node->parent->right == node)
		node->parent->right = child;
		else
			node->parent->left = child;

		child->parent = node->parent;
		free(node);
		return (0);
	}

	new_value = find_successor(node->right);
	node->n = new_value;
	return (new_value);
}

/**
 * bst_remove - Removes a node with a specific value from a BST.
 * @root: Pointer to the root of the tree.
 * @value: The value of the node to remove.
 * Return: Pointer to the new root of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int successor_value;

	if (root == NULL)
		return (NULL);

		if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else
	{
		successor_value = remove_node(root);
		if (successor_value != 0)
		bst_remove(root->right, successor_value);
	}

	return (root);
}

/**
 * avl_remove - Removes a node with a specific value from an AVL tree.
 * @root: Pointer to the root of the AVL tree.
 * @value: The value of the node to remove.
 * Return: Pointer to the new root of the AVL tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = (avl_t *)bst_remove((bst_t *)root, value);

	if (new_root == NULL)
		return (NULL);

	balance_avl_tree(&new_root);
	return (new_root);
}
