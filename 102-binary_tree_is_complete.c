#include "binary_trees.h"

/**
 * create_node - Function that creates a new node in a linked list
 * @node: Pointer to the binary tree node
 * Return: Pointer to the newly created node
 */
link_t *create_node(binary_tree_t *node)
{
    link_t *new_node = malloc(sizeof(link_t));
    if (new_node == NULL)
        return NULL;
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/**
 * free_queue - Function that frees the nodes in a linked list
 * @head: Pointer to the head of the linked list
 */
void free_queue(link_t *head)
{
    while (head != NULL)
    {
        link_t *temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * push - Function that pushes a node onto the queue
 * @node: Pointer to the binary tree node
 * @head: Pointer to the head of the queue
 * @tail: Pointer to the tail of the queue
 */
void push(binary_tree_t *node, link_t **head, link_t **tail)
{
    link_t *new_node = create_node(node);
    if (new_node == NULL)
    {
        free_queue(*head);
        exit(1);
    }
    if (*head == NULL)
        *head = new_node;
    else
        (*tail)->next = new_node;
    *tail = new_node;
}

/**
 * pop - Function that pops a node from the queue
 * @head: Pointer to the head of the queue
 */
void pop(link_t **head)
{
    if (*head == NULL)
        return;
    link_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Pointer to the root of the binary tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    link_t *head = NULL, *tail = NULL;
    int flag = 0;

    push((binary_tree_t *)tree, &head, &tail);

    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return 0;
            }
            push(head->node->left, &head, &tail);
        }
        else
            flag = 1;

        if (head->node->right != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return 0;
            }
            push(head->node->right, &head, &tail);
        }
        else
            flag = 1;

        pop(&head);
    }

    return 1;
}
