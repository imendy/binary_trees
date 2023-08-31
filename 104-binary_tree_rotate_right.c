#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp_right_child;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;
	temp_right_child = new_root->right;
	new_root->right = tree;
	tree->left = temp_right_child;
	if (temp_right_child != NULL)
		temp_right_child->parent = tree;
	temp_right_child = tree->parent;
	tree->parent = new_root;
	new_root->parent = temp_right_child;
	if (temp_right_child != NULL)
	{
		if (temp_right_child->left == tree)
			temp_right_child->left = new_root;
		else
			temp_right_child->right = new_root;
	}

	return (new_root);
}
