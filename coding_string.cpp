/*
Given a string str, find the length of the longest substring without repeating characters.

Example:

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.

For “BBBB” the longest substring is “B”, with length 1.
*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

void reverse_string(std::string& text);
std::string longestSubstringWithoutRepeatingCharacters(std::string& text);

int main()
{
	std::string text_to_reverse = "Reverse me";
	//reverse_string(text_to_reverse);
	//std::cout << "swapped: " << text_to_reverse;
	std::string longest_substr_candidate = "ABCABADEC";
	
	std::string substr = longestSubstringWithoutRepeatingCharacters(longest_substr_candidate);
	std::cout << "the substring length: " << substr;

	return 0;
}

void reverse_string(std::string& text)
{
	int length = text.length();

	for(int i = 0; i < length/2; i++)
	{
		std::swap(text[i], text[length - 1 - i]);
	}

}

std::string longestSubstringWithoutRepeatingCharacters(std::string& text)
{
	if (text.length() == 0)
		return "";
	if (text.length() == 1)
		return "";

	std::set<char> letters_already_seen;
	int left = 0;

	size_t max_length = 0;
	std::string current_text = "";
	std::string the_longest_substr = "";

	for (int right = 0; right < text.length(); ++right)
	{

		if (letters_already_seen.count(text[right]))
		{
			size_t new_left = current_text.find(text[right]);
			for (auto c: current_text.substr(left, new_left))
			{
				letters_already_seen.erase(c);
			}
			left = new_left;
			if (current_text.length() > 1)
			{
				current_text = current_text.substr(left, current_text.length());
			}
			else
			{
				current_text = current_text.substr(left, current_text.length() - 1);
			}

		}
		else
		{
			current_text.push_back(text[right]);
		}

		letters_already_seen.insert(text[right]);
		std::cout << "current text(window slicing): " << current_text << std::endl;
		max_length = std::max(max_length, current_text.length());
		if (current_text.length() > the_longest_substr.length())
		{
			the_longest_substr = current_text;
		}

	}

	return the_longest_substr;
}