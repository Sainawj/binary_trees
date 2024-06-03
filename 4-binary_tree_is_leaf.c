#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is a leaf
 * A leaf node does not have any children (neither left nor right).
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node == NULL)
        return 0;

    /* Check if the node has no children */
    if (node->left == NULL && node->right == NULL)
        return 1; /* Node is a leaf */

    return 0; /* Node is not a leaf */
}
