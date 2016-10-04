//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#ifndef DICTIONARYPATH_INPUTDATAIMPL_H
#define DICTIONARYPATH_INPUTDATAIMPL_H

#include <istream>                                         // std::istream
#include <string>                                          // std::string

#include <boost/optional.hpp>                              // boost::optional

#include "InputData.h"                                     // InputData

class InputDataImpl: public InputData
{
public:
    InputDataImpl(const std::string &inputFilePath);

    DictionaryPtr getDictonary() override;

    const Word *getStartingWord() override;

    const Word *getEndingWord() override;

private:
    void load();
    void initVariables();
    void readData(std::istream &is);
    void setTwoIndicatedWords(const Word &start, const Word &end);
    void verifyWordsLength();

    std::string inputFilePath_;

    boost::optional<DictionaryPtr> dictionary_;
    boost::optional<const Word *> start_;
    boost::optional<const Word *> end_;
};


#endif //DICTIONARYPATH_INPUTDATAIMPL_H
