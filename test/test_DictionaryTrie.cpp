/**
 * TODO: File HEADER
 *
 * Author:
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "DictionaryTrie.hpp"
#include "util.hpp"

using namespace std;
using namespace testing;

/* Empty test */
TEST(DictTrieTests, EMPTY_TEST) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.find("abrakadabra"), false);
}

TEST(DictTrieTests, TEST_INSERT) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.insert("abrakadabra", 100), true);
    ASSERT_EQ(dict.find("abrakadabra"), true);
    ASSERT_EQ(dict.insert("abrakadabra", 100), false);
    ASSERT_EQ(dict.insert("abrakadabra", 20), false);
    ASSERT_EQ(dict.insert("ab", 30), true);
    ASSERT_EQ(dict.find("ab"), true);
    ASSERT_EQ(dict.find("brakadabra"), false);
    ASSERT_EQ(dict.insert("bad", 10), true);
    ASSERT_EQ(dict.insert("bat", 20), true);
    ASSERT_EQ(dict.find("bad"), true);
    ASSERT_EQ(dict.find("bat"), true);
    ASSERT_EQ(dict.find("ba"), false);
}

/**
TEST(DictTrieTests, TEST_INSERT) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.insert("abrakadabra", 100), true);
    ASSERT_EQ(dict.find("abrakadabra"), true);
    ASSERT_EQ(dict.insert("abrakadabra", 100), false);
    ASSERT_EQ(dict.insert("abrakadabra", 20), false);
    ASSERT_EQ(dict.insert("ab", 30), true);
    ASSERT_EQ(dict.find("ab"), true);
    ASSERT_EQ(dict.find("brakadabra"), false);
    ASSERT_EQ(dict.insert("bad", 10), true);
    ASSERT_EQ(dict.insert("bat", 20), true);
    ASSERT_EQ(dict.find("bad"), true);
    ASSERT_EQ(dict.find("bat"), true);
    ASSERT_EQ(dict.find("ba"), false);
}
*/
/**
TEST(DictTrieTests, EMPTY_TEST) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.find("abrakadabra"), false);
}

TEST(DictTrieTests, EMPTY_TEST) {
    DictionaryTrie dict;
    ASSERT_EQ(dict.find("abrakadabra"), false);
}
*/

/* TODO */
