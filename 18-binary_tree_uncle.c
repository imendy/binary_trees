#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *                     in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no uncle, NULL.
 *         Otherwise, a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (current_node == NULL ||
	    current_node->parent == NULL ||
	    current_node->parent->parent == NULL)
		return (NULL);
	if (current_node->parent->parent->left == current_node->parent)
		return (current_node->parent->parent->right);
	return (current_node->parent->parent->left);
}
