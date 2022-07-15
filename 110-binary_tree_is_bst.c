#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - checks if a binary tree is a valid binary search tree
 * @tree: root node of the tree to check
 * @low: value of the smallest node
 * @high: value of the largest node
 * Return: 1 if tree is a valid BST or 0
 */
int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
