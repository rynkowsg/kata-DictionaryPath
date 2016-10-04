//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include "Path.h"

std::ostream &operator<<(std::ostream &os, const Path &path)
{
    if (path.empty()) {
        os << 0 << "\n";
    }
    else {
        for (const auto &elem : path)
            os << *elem << " ";
        os << "\n";
    }
    return os;
}
