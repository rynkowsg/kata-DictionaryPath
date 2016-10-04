//
// Created by Grzegorz Rynkowski on 02/10/2016.
//

#include <iostream>                                        // std::cout, std::endl

#include <DictionaryPath/Dictionary.h>                     // Dictionary, DictionaryPtr
#include <DictionaryPath/DictionaryPath.h>                 // DictionaryPath

int main()
{
    auto dictionary = static_cast<DictionaryPtr>(
        new Dictionary{"hit","dot","dog","cog","hot","log"});
    auto start = &*(dictionary->find("hit"));
    auto end = &*(dictionary->find("cog"));

    auto pathLenth = DictionaryPath{}.calculatePathLength(dictionary, start, end);

    std::cout << "dictionary: " << *dictionary << std::endl;
    std::cout << "start: " << *start << std::endl;
    std::cout << "end:   " << *end << std::endl;
    std::cout << std::endl;
    std::cout << "length: " << pathLenth << std::endl;

    return 0;
}
