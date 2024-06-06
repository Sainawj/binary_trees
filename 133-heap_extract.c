#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 * Return: Size of the tree, 0 if @tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap_values - Swaps the values of two binary tree nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_values(binary_tree_t *node1, binary_tree_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * sift_down - Moves the node down the heap if necessary.
 * @heap: Pointer to the root node of the heap.
 */
void sift_down(heap_t *heap)
{
	heap_t *largest, *child;

	while (1)
	{
		largest = heap;
		child = heap->left;

		if (child != NULL && child->n > largest->n)
			largest = child;

		child = heap->right;
		if (child != NULL && child->n > largest->n)
			largest = child;

		if (largest == heap)
			break;

		swap_values(heap, largest);
		heap = largest;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node, or 0 if the function fails.
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *current_node;
	int extracted_value;

	if (root == NULL || *root == NULL)
		return (0);

	extracted_value = (*root)->n;
	last_node = *root;
	while (last_node->right != NULL)
	{
		if (last_node->right->parent != last_node)
			last_node = last_node->right;
		else if (last_node->left->parent != last_node)
			last_node = last_node->left;
	}

	if (last_node->parent != NULL)
	{
		if (last_node->parent->right != NULL)
			last_node->parent->right = NULL;
		else
			last_node->parent->left = NULL;
	}

	if (*root == last_node)
	{
		free(last_node);
		*root = NULL;
		return (extracted_value);
	}

	(*root)->n = last_node->n;
	current_node = last_node->parent;
	if (current_node->right == NULL)
		current_node->left = NULL;
	else
		current_node->right = NULL;

	free(last_node);

	sift_down(*root);

	return (extracted_value);
}
