//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#ifndef DICTIONARYPATH_PATH_H
#define DICTIONARYPATH_PATH_H

#include <list>                                            // std::list
#include <memory>                                          // std::shared_ptr

#include "WordsGraph.h"                                    // Node

using Path = std::list<Node>;
using PathPtr = std::shared_ptr<Path>;
using ConstPathPtr = std::shared_ptr<const Path>;

std::ostream &operator<<(std::ostream &os, const Path &dictionary);

#endif //DICTIONARYPATH_PATH_H
