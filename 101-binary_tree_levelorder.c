#include "binary_trees.h"

#define MAX_QUEUE_SIZE 1024

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: The function uses a static array as a queue
 * to visit each node from left to right.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *queue[MAX_QUEUE_SIZE];
	const binary_tree_t *current;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}
}
