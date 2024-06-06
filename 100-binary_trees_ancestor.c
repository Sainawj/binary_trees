#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	while (first != second)
	{
		first = (first && first->parent) ? first->parent : second;
		second = (second && second->parent) ? second->parent : first;
	}

	return ((binary_tree_t *)first);
}
