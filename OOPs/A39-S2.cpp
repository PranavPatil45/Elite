#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Trienode
{
    char data;
    Trienode *children[26];
    bool isEndOfWord;

public:
    Trienode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isEndOfWord = false;
    }

    void insert(string word)
    {
        Trienode *current = this;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';

            if (current->children[index] == NULL)
            {
                current->children[index] =
                    new Trienode(word[i]);
            }

            current = current->children[index];
        }

        current->isEndOfWord = true;
    }
};

int main()
{
    ifstream file("data.txt");

    if (!file.is_open())
    {
        cout << "Error can't open file" << endl;
        return 1;
    }

    string word;
    char ch[100];
    int n = 0;

    Trienode *root = new Trienode('\0');

    while (getline(file, word))
    {
        if (!word.empty())
        {
            root->insert(word);
            cout << word << endl;
            n++;
        }
    }

    file.close();

    return 0;
}