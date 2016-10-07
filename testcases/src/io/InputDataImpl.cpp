//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#include "InputDataImpl.h"

#include <fstream>                                         // std::ifstream
#include <stdexcept>                                       // std::runtime_error

#include <DictionaryPath/DictionaryFactory.h>              // DictionaryFactory


InputDataImpl::InputDataImpl(const std::string &inputFilePath)
    : inputFilePath_{inputFilePath}
{
}

DictionaryPtr InputDataImpl::getDictonary()
{
    if (!dictionary_.is_initialized()) {
        load();
    }
    return dictionary_.get();
}

Word InputDataImpl::getStartingWord()
{
    if (!start_.is_initialized()) {
        load();
    }
    return start_.get();
}

Word InputDataImpl::getEndingWord()
{
    if (!start_.is_initialized()) {
        load();
    }
    return end_.get();
}

void InputDataImpl::load()
{
    initVariables();

    auto inputStream = std::ifstream{inputFilePath_};
    if (!inputStream.is_open()) {
        throw std::runtime_error("There is a problem with opening input file: " + inputFilePath_);
    }

    readTargetWords(inputStream);
    readDictionary(inputStream);
}

void InputDataImpl::initVariables()
{
    dictionary_ = DictionaryFactory::CreateDictionary();
}

void InputDataImpl::readTargetWords(std::istream &is)
{
    // read starting and ending points
    auto start = Word{};
    auto end = Word{};
    is >> start >> end;
    start_ = start;
    end_ = end;
}

void InputDataImpl::readDictionary(std::istream &is)
{
    // reading dictionary size
    auto dictionarySize = 0;
    is >> dictionarySize;
    if (dictionarySize < 0)
        throw std::runtime_error("Wrong format of data");

    // reading of dictionary
    for (int i = 0; i < dictionarySize; ++i) {
        // read word
        auto word = Word{};
        is >> word;
        // insert word into dictionary
        dictionary_.get()->insert(word);
    }

    verifyWordsLength();
}

void InputDataImpl::verifyWordsLength()
{
    auto length = start_.get().length();
    for (const auto &word : *(dictionary_.get()))
        if (word.length() != length)
            throw std::runtime_error("All words should have the same length.");
}
