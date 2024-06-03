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
        return NULL;

    node->n = value;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/**
 * binary_tree_node - Create a binary tree node and set its parent
 * @parent: Parent node
 * @value: Value of the node
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = create_node(value);
    if (!node)
        return NULL;

    node->parent = parent;

    return node;
}
