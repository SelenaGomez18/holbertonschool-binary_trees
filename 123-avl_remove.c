#include "binary_trees.h"

/**
 * min_value_node - Encuentra el nodo con el valor mínimo en un subárbol.
 * @node: Puntero a la raíz del subárbol.
 * Return: Puntero al nodo con el menor valor.
 */
avl_t *min_value_node(avl_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * avl_delete_node - Elimina un nodo dado de un árbol AVL.
 * @root: Puntero al nodo raíz del subárbol.
 * Return: Puntero al nuevo nodo raíz del subárbol.
 */
avl_t *avl_delete_node(avl_t *root)
{
	avl_t *temp;

	if (!root->left || !root->right)
	{
		temp = root->left ? root->left : root->right;
		if (!temp)
		{
			temp = root;
			root = NULL;
		}
		else
		{
			temp->parent = root->parent;
			*root = *temp;
		}
		free(temp);
	}
	else
	{
		temp = min_value_node(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * avl_remove - Elimina un nodo de un árbol AVL y re-balancea.
 * @root: Puntero a la raíz del árbol.
 * @value: Valor a eliminar.
 * Return: Puntero a la nueva raíz tras re-balancear.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int balance;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
		root = avl_delete_node(root);

	if (!root)
		return (NULL);

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
