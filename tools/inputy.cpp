#include "inputy.h"

Inputy::Inputy() {};

// Method to autocomplete a word
string Inputy::autocomplete(Vectory<string> &words)
{
    cout << "Is this what you meant? \n";

    for (int i = 0; i < words.size(); i++)
    {
        cout << i + 1 << ". " << words[i] << endl;
    }

    int wordNum;
    cin >> wordNum;
    while (wordNum < 1 || wordNum >= words.size() + 1)
    {
        cout << "Invalid word number\n";
        cin.clear();
        cin >> wordNum;
        cin.ignore(INT_MAX, '\n');
    }
    cout << "You have selected: " << words[wordNum - 1] << endl;
    return words[wordNum - 1];
}

// Method to break input into words
Vectory<string> Inputy::break_input(string input)
{
    Vectory<string> words;
    string word = "";
    cout << input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += input[i];
        }
    }
    words.push_back(word);
    return words;
}

// Method to choose a book from a list of results
string Inputy::chooseBook(Vectory<Result> books)
{
    if (books.empty())
    {
        cout << "No books found\n";
        return "";
    }
    cout << "Choose a book: \n";
    cout << "Results: " << books.size() << endl;
    if (books.size() > 10)
    {
        cout << "Type 0 to see more results\n";
    }

    int displays = min(10, books.size());
    for (int i = 0; i < displays; i++)
    {
        cout << i + 1 << ". " << books[i].title << " (relavance: " << books[i].relevance << ")\n";
    }

    int bookNum;
    cin >> bookNum;

    if (bookNum == 0 && books.size() > 10)
    {
        for (int i = 10; i < books.size(); i++)
        {
            cout << i + 1 << ". " << books[i].title << " (relavance: " << books[i].relevance << ")\n";
        }
        cout << "Please select a book number: ";
        cin >> bookNum;
    }

    

    while (bookNum < 1 || bookNum >= books.size() + 1)
    {
        cout << "Invalid book number\n";
        cin.clear();
        cin >> bookNum;
        cin.ignore(INT_MAX, '\n');
    }

    cout << "You have selected: \nTitle: " << books[bookNum - 1].title <<"\nPath: " << books[bookNum - 1].filePath<< endl;
    return books[bookNum - 1].filePath;
}
