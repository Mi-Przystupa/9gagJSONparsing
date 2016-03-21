#include "stdafx.h"
#include "PermutationGenerator.h"
#include <stdio.h>
#include <algorithm>

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
		token = strtok_s(NULL, " ", &next_token);
		if (token != NULL) {
			std::string cleaned(token);
			cleaned.resize(std::remove_if(cleaned.begin(), cleaned.end(), [](char x) {return !isalnum(x) && !isspace(x); }) - cleaned.begin());
			printf("%s\n", cleaned);

			words.push_back(cleaned);
		}
		else {
			break;
		}
	}
}


std::vector<std::string>* PermutationGenerator::GetPermutations(){
	std::vector<std::string>* permutations = new std::vector<std::string>();
	for (unsigned int i = 0; i < words.size(); i++){
		std::string current(words[i]);
		for (unsigned int j = 0; j < words.size(); j++){
			//concatenated permutation.
			permutations->push_back(current);
			current += words[j];
			//permutations = 
		}
	}
	return permutations;

}