#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *f_p, *s_p;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	f_p = first->parent, s_p = second->parent;
	if (first == s_p || !f_p || (!f_p->parent && s_p))
		return (binary_trees_ancestor(first, s_p));
	else if (f_p == second || !s_p || (!s_p->parent && f_p))
		return (binary_trees_ancestor(f_p, second));
	return (binary_trees_ancestor(f_p, s_p));
}
