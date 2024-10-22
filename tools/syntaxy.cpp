#include "syntaxy.h"

Syntaxy::Syntaxy(){};

Vectory<Result> Syntaxy::and_search(Vectory<Result> &word1, Vectory<Result> &word2)
{
    
    sorter.quickSortByName(word1, 0, word1.size() - 1);
    sorter.quickSortByName(word2, 0, word2.size() - 1);

    Vectory<Result> d_first;

    int word1_size = word1.size();
    int word2_size = word2.size();
    int i = 0;
    int j = 0;

    while (i < word1_size && j < word2_size)
    {
        if (word1[i].title < word2[j].title)
            i++;
        else
        {
            if (!(word2[j].title < word1[i].title)){
                Result temp = {word1[i].title, word1[i].filePath, word1[i].relevance + word2[j].relevance};
                d_first.push_back(temp); 
            }
            j++;
        }
    }
    sorter.quickSortByCount(d_first, 0, d_first.size() - 1);

    return d_first;
}

Vectory<Result> Syntaxy::or_search(Vectory<Result> word1, Vectory<Result> word2)
{
    sorter.quickSortByName(word1, 0, word1.size() - 1);
    sorter.quickSortByName(word2, 0, word2.size() - 1);
    Vectory<Result> d_first;
    int word1_size = word1.size();
    int word2_size = word2.size();
    cout << "Word 1 - " << word1_size << endl;
    cout << "Word 2 - " << word2_size << endl;
    int i = 0;
    int j = 0;

    while (i < word1_size && j < word2_size) {
        if (word1[i].title < word2[j].title) {
            d_first.push_back(word1[i]);
            i++;
        } else if (word2[j].title < word1[i].title) {
            d_first.push_back(word2[j]);
            j++;
        } else {
            Result temp = {word1[i].title, word1[i].filePath, word1[i].relevance + word2[j].relevance};
            d_first.push_back(temp);
            i++;
            j++;
        }
    }

    while (i < word1_size) {
        d_first.push_back(word1[i]);
        i++;
    }

    while (j < word2_size) {
        d_first.push_back(word2[j]);
        j++;
    }

    return d_first;
    sorter.quickSortByCount(d_first, 0, d_first.size() - 1);

    return d_first;
}

Vectory<Result> Syntaxy::not_search(Vectory<Result> word1)
{
    sorter.quickSortByName(word1, 0, word1.size() - 1);
    Vectory<Result> all_words = idx.getBooksName();
    Vectory<Result> d_first;
    int word1_size = word1.size();
    int word2_size = all_words.size();
    int i = 0;
    int j = 0;

    while (j < word2_size)
    {
        if (!(word1[i].title == all_words[j].title)){
            d_first.push_back(all_words[j]);
            j++;
        }
        else
        {
            if (i < word1_size-1){
                i++;
            }
            j++;
        }
    }

    sorter.quickSortByCount(d_first, 0, d_first.size() - 1);
    return d_first;
    
}
