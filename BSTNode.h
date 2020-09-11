//David Park
//BSTNode.h
//Semester Project
//Created 5/09/20
#pragma once
#include <string>
#include <iostream>

class BSTNode
{
public:
	BSTNode()
	{
		left = right = nullptr;
	}
	BSTNode(std::string& nam, std::string& sub, char av, BSTNode* l = nullptr, BSTNode* r = nullptr)
	{
		name = nam; subject = sub; avail = av; left = l; right = r;
	}
	std::string name, subject;
	char avail;
	BSTNode* left, * right;
};