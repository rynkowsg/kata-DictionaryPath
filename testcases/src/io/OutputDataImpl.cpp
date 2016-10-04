//
// Created by Grzegorz Rynkowski on 04/10/2016.
//

#include "OutputDataImpl.h"

#include <fstream>                                         // std::ifstream

OutputDataImpl::OutputDataImpl(const std::string &outputFilePath)
    : outputFilePath_{outputFilePath}
{
}

unsigned int OutputDataImpl::getExpectingResult()
{
    if (!expectingResult_.is_initialized()) {
        load();
    }
    return expectingResult_.get();
}

void OutputDataImpl::load()
{
    auto inputStream = std::ifstream{outputFilePath_};
    if (!inputStream.is_open()) {
        throw std::runtime_error("There is a problem with opening input file: " + outputFilePath_);
    }
    readData(inputStream);
}

void OutputDataImpl::readData(std::istream &is)
{
    auto value = 0;

    is >> value;
    if (value < 0) {
        throw std::runtime_error("The length can't be negative.");
    }

    expectingResult_ = value;
}
