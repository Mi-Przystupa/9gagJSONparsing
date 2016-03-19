#pragma once
#include <string>
#include <vector>

class PermutationGenerator
{
public:
	PermutationGenerator(std::string s);
	virtual ~PermutationGenerator();

	std::vector<std::string>* GetPermutations();

private:

	std::vector<std::string> words;
	void ParseWords(std::string s);
};

