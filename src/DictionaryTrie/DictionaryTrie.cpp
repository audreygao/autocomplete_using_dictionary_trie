/**
 * TODO: File Header
 *
 * Author:
 */
#include "DictionaryTrie.hpp"
#include <iostream>
#include <queue>
#include <stack>

/* TODO */
DictionaryTrie::DictionaryTrie() { root = new TrieNode(0, '\0', -1); }

/* TODO */
bool DictionaryTrie::insert(string word, unsigned int freq) {
    if (word.length() == 0) {
        return false;
    }

    TrieNode* curr = root;

    for (int i = 0; i < word.length(); i++) {
        // char not in the hashmap
        if (curr->indexMap.find(word[i]) == curr->indexMap.end()) {
            // add char to hashmap; hashvalue = size
            curr->indexMap[word[i]] = curr->indexMap.size();

            // add TrieNode* into ptrArray
            curr->ptrArray.push_back(new TrieNode(0, word[i], i));

            // update curr to point to next TrieNode
            curr = curr->ptrArray.at(curr->indexMap.size() - 1);

            // char already in the hashmap
        } else {
            // get char index stored in hashmap
            int index = curr->indexMap[word[i]];

            // update curr to next TrieNode
            curr = curr->ptrArray.at(index);
        }
    }

    // check if end of word has nonzero frequency
    // meaning word already exists
    if (curr->frequency != 0) {
        return false;
    } else {
        curr->frequency = freq;  // update frequency
    }
    return true;
}

/* TODO */
bool DictionaryTrie::find(string word) const {
    TrieNode* curr = root;

    for (int i = 0; i < word.length(); i++) {
        // char not in the hashmap
        if (curr->indexMap.find(word[i]) == curr->indexMap.end()) {
            return false;

            // char already in the hashmap
        } else {
            // get char index stored in hashmap
            int index = curr->indexMap[word[i]];

            // update curr to next TrieNode
            curr = curr->ptrArray.at(index);
        }
    }

    if (curr->frequency == 0) {
        return false;
    }

    return true;
}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

/* TODO */
vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
    // for DFS
    stack<TrieNode*> stack;

    // for ordering each word
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&cmp)>
        a(cmp);

    // vector to store the autocompleted words
    std::vector<string> vec;

    // prefis is empty
    if (prefix == "") {
        return {};
    }

    // find prefix, continue to using dfs to loop through pointer array of it
    TrieNode* curr = root;

    for (int i = 0; i < prefix.length(); i++) {
        // prefix doesn't exist in the trie
        if (curr->indexMap.find(prefix[i]) == curr->indexMap.end()) {
            return {};
        }

        // get char index stored in hashmap
        int index = curr->indexMap[prefix[i]];

        // update curr to next TrieNode
        curr = curr->ptrArray.at(index);
    }

    // in the loop keep track of the previous character for curr
    // word.append, pq<pair<word, frequency>>, add word to pq after pop

    stack.push(curr);

    string word;
    word = prefix.substr(0, prefix.length() - 1);
    // word.append(prefix, 0, prefix.length() - 1);

    while (!stack.empty()) {
        TrieNode* top = stack.top();

        stack.pop();

        // update the word
        word = word.substr(0, top->length);
        word.push_back(top->character);

        // if is an end of a word
        if (top->frequency != 0) {
            a.push(make_pair(word, top->frequency));
        }

        // for each children of the current node
        for (int i = 0; i < top->ptrArray.size(); i++) {
            stack.push(top->ptrArray[i]);
        }
    }

    // whole word nums fewer than numOf Completion
    if (a.size() < numCompletions) {
        int size = a.size();
        for (int i = 0; i < size; i++) {
            vec.push_back(a.top().first);
            a.pop();
        }
    } else {
        // normal case,directly pop
        for (int i = 0; i < numCompletions; i++) {
            vec.push_back(a.top().first);
            a.pop();
        }
    }

    return vec;
}

/* TODO */
std::vector<string> DictionaryTrie::predictUnderscores(
    string pattern, unsigned int numCompletions) {
    return {};
}

/* TODO */
DictionaryTrie::~DictionaryTrie() {
    stack<TrieNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        TrieNode* top = stack.top();

        stack.pop();
        // for each children of the current node
        for (int i = 0; i < top->ptrArray.size(); i++) {
            stack.push(top->ptrArray[i]);
        }
        top->ptrArray.clear();
        free(top);
    }
}
