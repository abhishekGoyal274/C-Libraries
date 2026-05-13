#include <bits/stdc++.h>
#include "./_utility.h"

int main()
{

    /**
     * @file trie_demo.cpp
     * @brief Demonstration and interactive testing of Trie data structure.
     *
     * @details
     * This file demonstrates how to use the Trie class for:
     *  - inserting words
     *  - searching complete words
     *  - checking prefixes
     *  - retrieving all stored words
     *  - retrieving all words matching a given prefix
     *
     * This code is intended **only for testing and demonstration**.
     * It should NOT be part of a production STL-like library.
     */

    /**
     * @brief Example usage of the Trie data structure.
     *
     * @details
     * Initializes a Trie with a predefined list of words and provides
     * an interactive menu-driven interface for performing operations
     * such as insert, search, prefix check, and traversal.
     *
     * @note
     * The Trie instance is dynamically allocated and explicitly deleted
     * to demonstrate ownership and cleanup.
     */

    /**
     * @variable words
     * @brief Initial list of words inserted into the Trie.
     *
     * @details
     * These words are used to populate the Trie at initialization time.
     */
    std::vector<std::string> words = {
        "hello", "my", "name", "is", "harsh",
        "and", "i", "love", "coding", "i"};

    /**
     * @variable Dictionary
     * @brief Pointer to the Trie instance used as a dictionary.
     *
     * @details
     * The Trie stores all words and supports prefix-based queries.
     */
    Trie *Dictionary = new Trie(words);

    /**
     * @brief Interactive loop for Trie operations.
     *
     * @details
     * The loop continuously prompts the user to choose one of the following operations:
     *  - 0 : Insert a word
     *  - 1 : Find a complete word
     *  - 2 : Check if a prefix exists
     *  - 3 : Retrieve all words with a given prefix
     *  - 4 : Retrieve all stored words
     *  - 5 : Exit the program
     */
    while (true)
    {

        /**
         * @variable operation
         * @brief Stores the user-selected operation code.
         */
        int operation;

        std::cout
            << "Enter operation - "
            << "insert(0)/find(1)/check prefix(2)/"
            << "get all with prefix(3)/get all words(4)/exit(5): ";
        std::cin >> operation;

        if (operation == 0)
        {

            /**
             * @variable: word
             * @brief Word to be inserted into the Trie.
             */
            std::string word;
            std::cout << "Enter word to insert: ";
            std::cin >> word;

            Dictionary->insert(word);
        }
        else if (operation == 1)
        {

            /**
             * @variable word
             * @brief Word to be searched in the Trie.
             */
            std::string word;
            std::cout << "Enter word to find: ";
            std::cin >> word;

            std::cout << Dictionary->find(word) << std::endl;
        }
        else if (operation == 2)
        {

            /**
             * @variable prefix
             * @brief Prefix to be checked in the Trie.
             */
            std::string prefix;
            std::cout << "Enter prefix to check: ";
            std::cin >> prefix;

            std::cout << Dictionary->check_prefix(prefix) << std::endl;
        }
        else if (operation == 3)
        {

            /**
             * @variable prefix
             * @brief Prefix used to retrieve matching words.
             */
            std::string prefix;
            std::cout << "Enter prefix to find all words with: ";
            std::cin >> prefix;

            /**
             * @variable matched_words
             * @brief List of all words starting with the given prefix.
             */
            auto matched_words = Dictionary->find_all_with_prefix(prefix);

            for (auto &word : matched_words)
            {
                std::cout << word << ", ";
            }
            std::cout << std::endl;
        }
        else if (operation == 4)
        {

            /**
             * @variable all_words
             * @brief List of all words stored in the Trie.
             */
            auto all_words = Dictionary->find_all_words();

            for (auto &word : all_words)
            {
                std::cout << word << ", ";
            }
            std::cout << std::endl;
        }
        else
        {
            break;
        }
    }

    /**
     * @brief Cleanup allocated Trie instance.
     * @details
     * Frees all dynamically allocated memory associated with the Trie.
     */
    delete Dictionary;

    return 0;
}