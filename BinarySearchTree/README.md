# Binary Search Tree (BST)

# Company Binary Search Tree (BST) Management System

This C++ program implements a binary search tree (BST) to store and manage companies based on their scores. The tree allows adding new companies, displaying the list of companies in order, and deleting a company by name.

## How It Works

1. The BST is created dynamically, with nodes arranged according to their scores. Left children are smaller, and right children are larger.
2. The `add` function inserts nodes recursively based on the scores provided.
3. The `show` function displays the tree using in-order traversal, providing a sorted list of companies.
4. The `delete_name` function deletes a company by name, restructuring the tree as needed.
