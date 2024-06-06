#include "binary_trees.h"

/**
 * r_insert_node - Inserts a value in an AVL tree recursively.
 * @tree: Double pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node.
 * @new_node: Double pointer to store the newly inserted node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: Pointer to the new root node after insertion.
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
		return (NULL);
	}
	else
	{
		return (*tree);
	}

	balance_factor = binary_tree_balance(*tree);

	if (balance_factor > 1 && value < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right(*tree);
    }
	else if (balance_factor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
    }
	else if (balance_factor < -1 && value > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_left(*tree);
    }
	else if (balance_factor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The value to insert into the AVL tree.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	r_insert_node(tree, *tree, &new_node, value);

	return (new_node);
}
