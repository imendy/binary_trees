#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp_left_child;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	temp_left_child = new_root->left;
	new_root->left = tree;
	tree->right = temp_left_child;
	if (temp_left_child != NULL)
		temp_left_child->parent = tree;
	temp_left_child = tree->parent;
	tree->parent = new_root;
	new_root->parent = temp_left_child;
	if (temp_left_child != NULL)
	{
		if (temp_left_child->left == tree)
			temp_left_child->left = new_root;
		else
			temp_left_child->right = new_root;
	}

	return (new_root);
}
