#include "binary_trees.h"


/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	const binary_tree_t *a = NULL, *b = NULL;

	if (!first || !second)
		return (NULL);

	for (a = first; a != NULL; a = a->parent)
	{
		for (b = second; b != NULL; b = b->parent)
		{
			if (a == b)
			{
				return ((binary_tree_t *)a);
			}
		}
	}
	return (NULL);
}
