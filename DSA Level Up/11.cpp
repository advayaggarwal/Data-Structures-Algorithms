#include<bits/stdc++.h>
using namespace std;

int skip_whitespace(int i, string &copy)
{
    while (i < copy.size() && copy[i] == ' ')    i++;

    return i;
}

int normalize_word(int i, string &copy)
{
    if (i < copy.size()) copy[i++] = toupper(copy[i]);

    while (i < copy.size() && copy[i] != ' ')
    {
        copy[i++] = tolower(copy[i]);
    }

    return i;
}


string normalize(const string &sentence)
{
    string copy = sentence;
    int i = 0;

    while (i < copy.size())
    {
        i = skip_whitespace(i, copy);
        i = normalize_word(i, copy);
    }

    return copy;
}