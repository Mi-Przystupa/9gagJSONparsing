#include "stdafx.h"
#include "PermutationGenerator.h"
#include <stdio.h>

PermutationGenerator::PermutationGenerator(std::string s)
{
	ParseWords(s);
}


PermutationGenerator::~PermutationGenerator()
{
}

void PermutationGenerator::ParseWords(std::string s){
	char *str = new char[s.size() + 1];
	str[s.size()] = 0;
	memcpy(str, s.c_str(), s.size());

	char * token;
	char* next_token;
	token = strtok_s(str, " ", &next_token);
	while (token != NULL)
	{
		//Will split up words
		printf("%s\n", token);
		token = strtok_s(NULL, " ", &next_token);
		words.push_back(std::string(token));
	}
}

std::vector<std::string>* PermutationGenerator::GetPermutations(){
	std::vector<std::string>* permutations = new std::vector<std::string>();
	for (unsigned int i = 0; i < words.size(); i++){
		for (unsigned int j = i; j < words.size(); j++){
			//concatenated permutation.
			int x = 0;
		}
	}

}