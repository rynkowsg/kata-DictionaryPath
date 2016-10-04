//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#ifndef DICTIONARYPATH_OUTPUTDATA_H
#define DICTIONARYPATH_OUTPUTDATA_H

#include <memory>                                          // std::shared_ptr

class OutputData;
using OutputDataPtr = std::shared_ptr<OutputData>;

class OutputData
{
public:
    virtual unsigned int getExpectingResult() = 0;
};


#endif //DICTIONARYPATH_OUTPUTDATA_H
