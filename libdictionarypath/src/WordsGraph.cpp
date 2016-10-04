//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "WordsGraph.h"

namespace
{

bool AreDifferent(const Word &first, const Word &second)
{
    return &first != &second;
}

bool IsOneCharacterDifference(const Word &first, const Word &second)
{
    auto amountOfDifferentCharacters = 0;
    for (auto i = 0u; i < first.length(); ++i) {
        amountOfDifferentCharacters += (first[i] != second[i]);
        if (amountOfDifferentCharacters > 1)
            return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Neighbours &neighbours)
{
    if (neighbours.empty()) {
        return os;
    }
    auto it = neighbours.begin();
    os << "[" << **it;
    for (++it; it != neighbours.end(); ++it) os << ", " << **it;
    os << "]";
    return os;
}

}  // namespace


WordsGraph::WordsGraph()
{
    initVariables();
}

void WordsGraph::initVariables(DictionaryPtr dictionary)
{
    dictionary_ = dictionary;
    nodes_ = std::make_shared<Nodes>();
    connections_ = std::make_shared<Connections>();

    for (const auto &word : *dictionary) {
        nodes_->insert(&word);
        (*connections_)[&word] = Nodes();
    }
}

void WordsGraph::setData(DictionaryPtr dictionary)
{
    initVariables(dictionary);
    findConnections();
}

void WordsGraph::findConnections()
{
    for (const Word &first_word : *dictionary_) {
        for (const Word &second_word : *dictionary_) {
            if (AreDifferent(first_word, second_word)
                && IsOneCharacterDifference(first_word, second_word)) {
                (*connections_)[&first_word].insert(&second_word);
            }
        }
    }
}

void WordsGraph::printConnections(std::ostream &os)
{
    os << "Connections [" << connections_->size() << "]: \n";
    for (const auto &pair : *connections_) {
        const auto &node = *pair.first;
        const auto &neighbours = pair.second;
        os << node << " [" << neighbours.size() << "]: " << neighbours << "\n";
    }
    os << "\n";
}
