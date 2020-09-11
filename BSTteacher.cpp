//David Park
//BSTteacher.cpp
//Semester Project
//Created 5/09/20
#include "BSTteacher.h"
#include "BSTNode.h"
#include <string>
#include <iostream>
#include <vector>

//Function to insert a node into the tree
void BSTteacher::insert(std::string name, std::string sub, char ava)
{
	BSTNode* p = root, * prev = nullptr;

	while (p != nullptr)
	{
		prev = p;

		if (name < p->name)				//if the index is less than the current node index
			p = p->left;
		else p = p->right;					//else greater than
	}
	if (root == nullptr)				//if tree empty insert the new node
	{
		root = new BSTNode(name, sub, ava);	
	}
	else if (name < prev->name)		//or if its less than previous node index
	{
		prev->left = new BSTNode(name, sub, ava);
	}
	else									//or greater than
	{
		prev->right = new BSTNode(name, sub, ava);
	}
}

//Function to find teachers that teach a certain subject using the Morris algo and displays them
void BSTteacher::searchSubject(std::string subject)
{
	BSTNode* p = root, * tmp = nullptr;

	if (p == nullptr)
	{
		std::cout << "There are no substitute teachers in the database!" << std::endl;
	}

	while (p != nullptr)
	{
		if (p->left == nullptr)
		{
			if (p->subject == subject)			//print the node if same subject
				std::cout << p->name << " " << p->subject << " " << p->avail << std::endl;
			
			p = p->right;
		}
		else
		{
			tmp = p->left;

			while (tmp->right != nullptr && tmp->right != p)
				tmp = tmp->right;

			if (tmp->right == nullptr)
			{
				tmp->right = p;
				p = p->left;
			}
			else
			{
				if (p->subject == subject)			//print the node if same subject
					std::cout << p->name << " " << p->subject << " " << p->avail << std::endl;

				tmp->right = nullptr;
				p = p->right;
			}
		}
	}
}

//Function to display teachers available and subject they teach using the morris algo
void BSTteacher::display()
{
	BSTNode* p = root, * tmp = nullptr;

	if (p == nullptr)
	{
		std::cout << "There are no substitute teachers in the database!" << std::endl;
	}

	while (p != nullptr)
	{
		if (p->left == nullptr)
		{
			std::cout << p->name << " " << p->subject << " " << p->avail << std::endl;			//print node
			p = p->right;
		}
		else
		{
			tmp = p->left;

			while (tmp->right != nullptr && tmp->right != p)
				tmp = tmp->right;

			if (tmp->right == nullptr)
			{
				tmp->right = p;
				p = p->left;
			}
			else
			{
				std::cout << p->name << " " << p->subject << " " << p->avail << std::endl;			//print
				tmp->right = nullptr;
				p = p->right;
			}
		}
	}
}

//Function to reserve the teacher using the Morris algo
bool BSTteacher::reserve(std::string name)
{
	bool retVal = false;
	BSTNode* p = root, * tmp = nullptr;

	if (p == nullptr)
	{
		std::cout << "There are no substitute teachers in the database!" << std::endl;
	}

	while (p != nullptr)
	{
		if (p->left == nullptr)
		{
			if (p->name == name)
			{
				p->avail = 'N';			//change the avail to no
				retVal = true;
			}
			p = p->right;
		}
		else
		{
			tmp = p->left;

			while (tmp->right != nullptr && tmp->right != p)
				tmp = tmp->right;

			if (tmp->right == nullptr)
			{
				tmp->right = p;
				p = p->left;
			}
			else
			{
				if (p->name == name)
				{
					p->avail = 'N';			//change the avail to no
					retVal = true;
				}
				tmp->right = nullptr;
				p = p->right;
			}
		}
	}
	return retVal;
}