//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#ifndef DICTIONARYPATH_OUTPUTDATAIMPL_H
#define DICTIONARYPATH_OUTPUTDATAIMPL_H

#include <istream>                                         // std::istream
#include <string>                                          // std::string

#include <boost/optional.hpp>                              // boost::optional

#include "OutputData.h"                                    // OutputData

class OutputDataImpl: public OutputData
{
public:
    OutputDataImpl(const std::string &outputFilePath);

    unsigned int getExpectingResult() override;

private:
    void load();
    void readData(std::istream &is);


    std::string outputFilePath_;

    boost::optional<unsigned int> expectingResult_;
};


#endif //DICTIONARYPATH_OUTPUTDATAIMPL_H
