//David Park
//BSTteacher.h
//Semester Project
//Created 5/09/20
#pragma once
#include <string>
#include "BSTNode.h"

class BSTteacher
{
public:
	BSTteacher()
	{
		root = nullptr;
	}
	void insert(std::string, std::string, char);
	void searchSubject(std::string);
	void display();
	bool reserve(std::string nam);
protected:
	BSTNode* root;
};