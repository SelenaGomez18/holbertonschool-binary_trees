#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling of
 *
 * Return: Pointer to the sibling node, or NULL if no sibling or node is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);

	return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle node, or NULL if no uncle or node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !(node->parent) || !(node->parent->parent))
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
