#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (bst_insert(&(*tree)->left, value));
		(*tree)->left = binary_tree_node(*tree, value);
		return ((*tree)->left);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (bst_insert(&(*tree)->right, value));
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
	return (NULL);
}
