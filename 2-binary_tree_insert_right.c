#include "binary_trees.h"

/**
 * create_node - Allocates memory for a new binary tree node
 * @value: Value of the node
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *create_node(int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
	return (NULL);

	node->n = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * binary_tree_insert_right - Add a node to the right of the parent
 * @parent: Parent node
 * @value: Value of the node
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	return (NULL);

	new_node = create_node(value);

	if (!new_node)
	return (NULL);

	new_node->parent = parent;

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
		}

	parent->right = new_node;

	return (new_node);
}
