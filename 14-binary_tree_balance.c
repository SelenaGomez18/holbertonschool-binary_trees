#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return ((left > right) ? left + 1 : right + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
		return (0);
	if (tree->left)
		height_left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		height_right = binary_tree_height(tree->right) + 1;

	return (height_left - height_right);
}
