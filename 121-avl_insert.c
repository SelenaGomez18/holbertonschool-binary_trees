#include "binary_trees.h"

/**
 * avl_insert_recursive - Helper to insert value in AVL recursively
 * @tree: Pointer to the current root
 * @value: Value to insert
 *
 * Return: Pointer to inserted node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, int value)
{
	int balance;
	avl_t *node;

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		node = avl_insert_recursive(&(*tree)->left, value);
		if (!node)
			return (NULL);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		node = avl_insert_recursive(&(*tree)->right, value);
		if (!node)
			return (NULL);
		(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (node);
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);
	return (avl_insert_recursive(tree, value));
}
