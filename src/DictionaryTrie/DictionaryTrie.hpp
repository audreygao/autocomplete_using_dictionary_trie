/**
 * TODO: File Header
 *
 * Author:
 */
#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class TrieNode {
  public:
    int frequency;
    int length;
    std::unordered_map<char, int> indexMap;
    std::vector<TrieNode*> ptrArray;
    char character;

    TrieNode(int freq, char ch, int len) {
        frequency = freq;
        character = ch;
        length = len;
        indexMap = {};
    }
};

/**
 * The class for a dictionary ADT, implemented as either
 * a mulit-way trie or a ternary search tree.
 */
class DictionaryTrie {
  private:
    TrieNode* root;
    // TODO: add private members and helper methods here
  public:
    /**
     * Initializes a new DictionaryTrie
     */
    DictionaryTrie();

    /**
     * Insert a word with its frequency into the trie;
     * Return true if word is inserted successfully
     * Return false if string is empty or already existed
     * Parameter:
     *  - word: word to be inserted
     *  - freq: frequency of the word
     */
    bool insert(string word, unsigned int freq);

    /**
     * Return true if the word is in the DictionaryTrie
     * Return false otherwise.
     * Parameter:
     *  - word: word to search for
     */
    bool find(string word) const;

    /* TODO: add function header */
    vector<string> predictCompletions(string prefix,
                                      unsigned int numCompletions);

    /* TODO: add function header */
    vector<string> predictUnderscores(string pattern,
                                      unsigned int numCompletions);

    /* TODO: add function header */
    ~DictionaryTrie();
};

#endif  // DICTIONARY_TRIE_HPP
