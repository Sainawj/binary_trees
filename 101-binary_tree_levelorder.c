#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);

	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((l > r) ? l : r);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node
 * Return: Depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list from depth level and node
 * @head: Pointer to head of linked list
 * @tree: Node to store
 * @level: Depth of the node
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
		return;

	new->n = level;
	new->node = tree;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
			aux = aux->next;

		new->next = NULL;
		aux->next = new;
	}
}

/**
 * recursion - Goes through the complete tree and stores each node
 * in the linked_node function
 * @head: Pointer to head of linked list
 * @tree: Node to check
 * Return: Nothing
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	head = NULL;
	recursion(&head, tree);

	while (count <= height)
	{
		aux = head;
		while (aux != NULL)
		{
			if (count == aux->n)
				func(aux->node->n);
			aux = aux->next;
		}
		count++;
	}

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
