//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#include "InputDataImpl.h"

#include <fstream>                                         // std::ifstream

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

const Word *InputDataImpl::getStartingWord()
{
    if (!start_.is_initialized()) {
        load();
    }
    return start_.get();
}

const Word *InputDataImpl::getEndingWord()
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

    readData(inputStream);
}

void InputDataImpl::initVariables()
{
    dictionary_ = std::make_shared<Dictionary>();
}

void InputDataImpl::readData(std::istream &is)
{
    // read starting and ending points
    auto start = Word{};
    auto end = Word{};
    is >> start >> end;

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
        auto is_successfully_inserted = dictionary_.get()->insert(word).second;

        /// The description doesn't mention that words can't repeat.
        /// For now I'm going to ignore that.
//        if (!is_successfully_inserted)
//            throw std::runtime_error("Repetition of words in the dictionary.");
    }

    setTwoIndicatedWords(start, end);
    verifyWordsLength();
}

void InputDataImpl::setTwoIndicatedWords(const Word &start, const Word &end)
{
    const auto iteratorOfStartingWord = dictionary_.get()->find(start);
    const auto iteratorOfEndingWord = dictionary_.get()->find(end);
    if (iteratorOfStartingWord == dictionary_.get()->end() ||
        iteratorOfEndingWord == dictionary_.get()->end()) {
        throw std::runtime_error("Starting and ending word needs to be also in the dictionary.");
    }
    start_ = &*iteratorOfStartingWord;
    end_ = &*iteratorOfEndingWord;
}

void InputDataImpl::verifyWordsLength()
{
    auto length = start_.get()->length();
    for (const auto &word : *(dictionary_.get()))
        if (word.length() != length)
            throw std::runtime_error("All words should have the same length.");
}

