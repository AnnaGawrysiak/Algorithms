#include <iostream>
#include <string>
#define NO_OF_CHARS 256

void badCharHeuristic(std::string str, int badchar[NO_OF_CHARS]);

int search(std::string pattern, std::string text);

int main()
{
    std::string txt = "ABAAABCD";
    std::string pat = "ABC";
    std::cout << search(pat, txt) << std::endl;

    return 0;
}

int search(std::string pattern, std::string text)
{
    int pattern_size = pattern.size();
    int text_size = text.size();

    int last_occurence[NO_OF_CHARS];

    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(pattern, last_occurence);

    int shift = 0; // s is shift of the pattern with
                // respect to text

    while (shift <= (text_size - pattern_size)) //  not end of string S
    {
        int pattern_index = pattern_size - 1;

        while (pattern_index >= 0 && pattern[pattern_index] == text[shift + pattern_index])
        {
            pattern_index--;
        }

        if (pattern_index < 0)
        {
            std::cout << "Pattern occurs at index : " << shift << " of the text. " << std::endl;
            return shift;

        }

        if (last_occurence[pattern[pattern_index]] == -1) // not found
        {
            shift = shift + pattern_size; // jump over
        }
        else
        {
            shift = shift + std::max(0, last_occurence[pattern[pattern_index]]);
        }

    }

    return -1; // not matched
}

void badCharHeuristic(std::string str, int badchar[NO_OF_CHARS])
{
    // Initialize all occurrences as -1

    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badchar[i] = -1;
    }
    

    // Fill the actual value of last occurrence of a character    

    for (int j = 0; j < str.size(); j++)
    {
        badchar[str[j]] = j;
    }


}