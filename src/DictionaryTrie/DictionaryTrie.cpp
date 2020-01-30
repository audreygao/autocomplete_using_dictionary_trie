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
DictionaryTrie::DictionaryTrie() { root = new TrieNode(0); }

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
            curr->ptrArray.push_back(new TrieNode(0));

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

    return true;
}

/* TODO */
vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
    stack<TrieNode*> stack;
    std::priority_queue<int> queue;
    // prefix doesnt exits
    if (find(prefix) == 0) {
        return {};
    }

    // find prefix, continue to using dfs to loop through pointer array of it
    TrieNode* curr = root;

    for (int i = 0; i < prefix.length(); i++) {
        // get char index stored in hashmap
        int index = curr->indexMap[prefix[i]];

        // update curr to next TrieNode
        curr = curr->ptrArray.at(index);
    }

    // in the loop keep track of the previous character for curr
    // word.append, pq<pair<word, frequency>>, add word to pq after pop

    stack.push(curr);

    while (!stack.empty()) {
        TrieNode* top = stack.top();
        stack.pop();

        for (int i = 0; i < top->ptrArray.size(); i++) {
            stack.push(top->ptrArray[i]);
        }
    }

    // whole word nums fewer than numOf Completion

    // normal case,directly pop

    return {};
}

/* TODO */
std::vector<string> DictionaryTrie::predictUnderscores(
    string pattern, unsigned int numCompletions) {
    return {};
}

/* TODO */
DictionaryTrie::~DictionaryTrie() {}