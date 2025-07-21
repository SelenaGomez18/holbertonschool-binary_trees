#include "binary_trees.h"

/**
 * bst_remove - Remove a node from a BST
 * @root: Pointer to root node
 * @value: Value to remove
 *
 * Return: New root after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = root->right;
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
