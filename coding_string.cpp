///*
//Given a string str, find the length of the longest substring without repeating characters.
//
//Example:
//
//For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
//
//For “BBBB” the longest substring is “B”, with length 1.
//*/
//
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include<array>
//
//void reverse_string(std::string& text);
//std::string longestSubstringWithoutRepeatingCharacters(std::string& text);
//std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string>);
void rotate(std::vector<std::vector<int>>& matrix);

int main()
{
//	//std::string text_to_reverse = "Reverse me";
//	//reverse_string(text_to_reverse);
//	//std::cout << "swapped: " << text_to_reverse;
//	//std::string longest_substr_candidate = "ABCABADEC";
//	
//	//std::string substr = longestSubstringWithoutRepeatingCharacters(longest_substr_candidate);
//	//std::cout << "the substring length: " << substr;
//
//	std::vector<std::string > strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	std::vector<std::vector<std::string>> groups_of_anagrams = group_anagrams(strs);
//
//	for (const auto& group : groups_of_anagrams)
//	{
//		for (const auto& word : group)
//		{
//			std::cout << word << " ";
//		}
//		std::cout << std::endl;
//	}

	std::vector<std::vector<int>> matrix_to_rotate = { std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6}, std::vector<int>{7, 8, 9} };
	rotate(matrix_to_rotate);
	for (const auto& row : matrix_to_rotate)
	{
		for (const auto& nr : row)
		{
			std::cout << nr << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}

//void reverse_string(std::string& text)
//{
//	int length = text.length();
//
//	for(int i = 0; i < length/2; i++)
//	{
//		std::swap(text[i], text[length - 1 - i]);
//	}
//
//}
//
//std::string longestSubstringWithoutRepeatingCharacters(std::string& text)
//{
//	if (text.length() == 0)
//		return "";
//	if (text.length() == 1)
//		return "";
//
//	std::set<char> letters_already_seen;
//	int left = 0;
//
//	size_t max_length = 0;
//	std::string current_text = "";
//	std::string the_longest_substr = "";
//
//	for (size_t right = 0; right < text.length(); ++right)
//	{
//
//		if (letters_already_seen.count(text[right]))
//		{
//			size_t new_left = current_text.find(text[right]);
//			for (auto c: current_text.substr(left, new_left))
//			{
//				letters_already_seen.erase(c);
//			}
//			left = new_left;
//			if (current_text.length() > 1)
//			{
//				current_text = current_text.substr(left, current_text.length());
//			}
//			else
//			{
//				current_text = current_text.substr(left, current_text.length() - 1);
//			}
//
//		}
//		else
//		{
//			current_text.push_back(text[right]);
//		}
//
//		letters_already_seen.insert(text[right]);
//		std::cout << "current text(window slicing): " << current_text << std::endl;
//		max_length = std::max(max_length, current_text.length());
//		if (current_text.length() > the_longest_substr.length())
//		{
//			the_longest_substr = current_text;
//		}
//
//	}
//
//	return the_longest_substr;
//}
//
//std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> words)
//{
//	std::vector<std::vector<std::string>> result;
//	std::map<std::array<int, 26>, std::vector<std::string>> groups;
//
//	for (auto& word : words)
//	{
//		std::array<int, 26> letters = {};
//		letters.fill(0);
//
//		for (auto& c : word)
//		{
//			//std::cout << 'c ' << c << " ";
//			c = std::tolower(c);
//			int index = (int)c - (int)'a';
//			//std::cout << index << "(index)";
//			letters[index] += 1;
//		} 
//
//		//std::cout << std::endl;
//
//		auto it = groups.find(letters);
//
//		if (it != groups.end())
//		{
//			groups[letters].push_back(word);
//		}
//		else
//		{
//			groups[letters] = std::vector<std::string>{word};
//		}
//
//	}
//
//	for (auto it = groups.begin(); it != groups.end(); ++it)
//	{
//		result.push_back(it->second);
//	}
//
//	return result;
//};


void rotate(std::vector<std::vector<int>>& matrix)
{
	int left = 0;
	int right = matrix.at(0).size()-1;

	while (left < right)
	{
		int top = left;
		int bottom = right;

		for (int i = 0; i < (right - left); i++)
		{
			int temp = matrix.at(top).at(left+i);
			matrix.at(top).at(left+i) = matrix.at(bottom-i).at(left);
			matrix.at(bottom-i).at(left) = matrix.at(bottom).at(right-i);
			matrix.at(bottom).at(right-i) = matrix.at(top+i).at(right);
			matrix.at(top+i).at(right) = temp;

		}

		left += 1;
		right -= 1;
	}
};