#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree_recursive - Recursively stores each level of the tree in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @buffer: Buffer to store the tree representation
 *
 * Return: Length of printed tree after processing
 */
static int print_tree_recursive(const binary_tree_t *tree, int offset, int depth, char **buffer)
{
	char node_repr[6];
	int width, left_width, right_width, is_left_child, i;

	if (!tree)
	return (0);

	is_left_child = (tree->parent && tree->parent->left == tree);
	width = sprintf(node_repr, "(%03d)", tree->n);

	left_width = print_tree_recursive(tree->left, offset, depth + 1, buffer);
	right_width = print_tree_recursive(tree->right, offset + left_width + width, depth + 1, buffer);

	for (i = 0; i < width; i++)
	buffer[depth][offset + left_width + i] = node_repr[i];

	if (depth)
	{
	if (is_left_child)
	{
		for (i = 0; i < width + right_width; i++)
		buffer[depth - 1][offset + left_width + width / 2 + i] = '-';
		buffer[depth - 1][offset + left_width + width / 2] = '.';
	}
	else
	{
		for (i = 0; i < left_width + width; i++)
		buffer[depth - 1][offset - width / 2 + i] = '-';
		buffer[depth - 1][offset + left_width + width / 2] = '.';
	}
	}

	return (left_width + width + right_width);
}

/**
 * calculate_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree
 */
static size_t calculate_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
	return (0);

	left_height = tree->left ? 1 + calculate_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + calculate_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **buffer;
	size_t height, i, j;

	if (!tree)
	return;

	height = calculate_tree_height(tree);
	buffer = malloc(sizeof(*buffer) * (height + 1));
	if (!buffer)
	return;

	for (i = 0; i <= height; i++)
	{
	buffer[i] = malloc(sizeof(**buffer) * 255);
	if (!buffer[i])
	{
		for (j = 0; j < i; j++)
		free(buffer[j]);
		free(buffer);
		return;
	}
	memset(buffer[i], ' ', 255);
	}

	print_tree_recursive(tree, 0, 0, buffer);

	for (i = 0; i <= height; i++)
	{
	for (j = 254; j > 1; --j)
	{
		if (buffer[i][j] != ' ')
		break;
		buffer[i][j] = '\0';
	}
	printf("%s\n", buffer[i]);
	free(buffer[i]);
	}

	free(buffer);
}
