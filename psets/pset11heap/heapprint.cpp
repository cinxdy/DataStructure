/**
* File: heapprint.cpp
*	converts a heap data structure in an array into a complete
*	binary tree and invokes treeprint() in treeprint.cpp
*
* @Author	Youngsup Kim, idebtor@gmail.com
* 05/05/2016	Creation
* 05/05/2019	Simplified using std::queue
*
* Algorithm to build a binary tree(BT) from a complete binary tree(CBT).
* 0. If the CBT size is zero, return a nullptr.
* 1. initialize the tree (BT) with the first key from CBT
* 2. queue the tree root node.
* 3. Loop until the queue is empty
*    Get a next key from the CBT
*    Get the front node in the queue.
*    If the left child of this front node doesn��t exist,
*        set the left child as the new node.
*	 else if the right child of this front node doesn��t exist,
*        set the right child as the new node.
* 4. If the front node has both the left child and right child,
*        dequeue() it.
* 5. enqueue() the new node.
* On my honour, I pledge that I have neither received nor provided improper assistance
* in the completion of this assignment.
* signed : 신지영 Section:03 Student Number:21800409
*/

#include <iostream>
#include <cassert>
#include <queue>
#include "heap.h"
#include "treenode.h"
#include <cmath>

void treeprint(tree t);

void heapprint(heap p) {
	DPRINT(std::cout << ">heapprint\n";);
	if (empty(p)) return;

	//std::cout << "your code here\n";
	tree root = new TreeNode(p->nodes[1]);
	std::queue<tree> q;
	q.push(root);

	int i=2;
	while(i<=p->N){
		int key = p->nodes[i];
		tree node = new TreeNode(key);
		tree temp = q.front();
		if(temp->left==nullptr) temp->left = node;
		else if(temp->right==nullptr) temp->right = node;
		if(temp->left!=nullptr && temp->right!=nullptr) q.pop();
		q.push(node);
		i++;
	}
	
	treeprint(root);

	// treeprint_levelorder(root);  // may use this instead of heapprint_levelorder()
	DPRINT(std::cout << "<heapprint\n";);
}

void heapprint_levelorder(heap p) {
	DPRINT(std::cout << ">heapprint_levelorder\n";);
	if (empty(p)) return;
	int N = size(p);                   // number of nodes, N is the last index
	int max_level = height(N);         // total number of levels, starting at 1
	int i = 1;
	while (i <= N) {
		for (int level = 0; level < max_level; level++) {
			int n = (int)pow(2, level);            // n is max nodes per level
			for (int k = 0; k < n && i <= N; k++)   // disply one level
				std::cout << p->nodes[i++] << " ";
			std::cout << std::endl;
		}
	}
	DPRINT(std::cout << "<heapprint_levelorder\n";);
}