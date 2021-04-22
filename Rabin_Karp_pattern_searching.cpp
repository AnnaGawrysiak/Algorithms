#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void Rabin_Karp_Algorithm(string pattern, string text);

int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    Rabin_Karp_Algorithm(pattern, text);

    return 0;
}

void Rabin_Karp_Algorithm(string pattern, string text)
{
    const int nr_of_chars_in_alphabet = 256;
    const int w = 101;
    // We take modulo w (%w) where w is a large prime number because hash calculated in the equation can become 
    //very large due to powers of t. Hence to fit hash in int variable we do modulo w.

    int text_length = text.length();
    int pattern_length = pattern.length();

    //Calculate hash_p(hash value of pattern) and first window of text
    int hash_p = 0;
    int hash_t = 0;
    int i = 0;
    
    int index = -1;

    hash_p = 0;

    for (int i = 0; i < pattern_length; i++)
    {
        hash_p += pattern[pattern_length - i- 1] * pow(nr_of_chars_in_alphabet, i);
        hash_p = hash_p % w;
        hash_t += text[pattern_length - i - 1] * pow(nr_of_chars_in_alphabet, i);
        hash_t = hash_t % w;
    }
    
    // The value of c would be "pow(nr_of_chars_in_alphabet, pattern_length-1)%w"
    int c = pow(nr_of_chars_in_alphabet, pattern_length - 1);
    c = c % w;

    for (int i = 0; i < (text_length - pattern_length); i++)
    {
        int j = 0;
        if (hash_p == hash_t)
        {
      
            for (j = 0; j < pattern_length; j++)
            {
                if (pattern[j] != text[i + j])
                    break;
            }

            if (j == pattern_length)
            {
                cout << "Pattern found at index " << i << endl;;
            }
        }

        //Calculate hash value of next window
        // t = nr of chars
        //general equation: hash_i+1 = t * {hash_i - text[i] * t^(plen-1)} + text[i+plen]
        // remove previous digit, add subsequent digit
        hash_t = (nr_of_chars_in_alphabet * (hash_t - text[i] * c) + text[i + pattern_length])%w;
       
        // We might get negative value of t, converting it 
           // to positive 
        if (hash_t < 0)
            hash_t = (hash_t + w);
            
    }

}