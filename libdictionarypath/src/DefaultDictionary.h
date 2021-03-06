//
// Created by Grzegorz Rynkowski on 06/10/2016.
//

#ifndef DICTIONARYPATH_DEFAULTDICTIONARY_H
#define DICTIONARYPATH_DEFAULTDICTIONARY_H

#include <utility>                                         // std::forward

#include <DictionaryPath/Dictionary.h>                     // Dictionary, Word


class DefaultDictionary final: public Dictionary
{
public:
    template<typename... Args>
    DefaultDictionary(Args &&... args)
        : set_{std::forward<Args>(args)...}
    {
    }

    inline Iterator find(const Word &word) const override final
    { return set_.find(word); }

    inline Iterator begin() const override final
    { return set_.begin(); }

    inline Iterator end() const override final
    { return set_.end(); }

    inline bool empty() const override final
    { return set_.empty(); }

    inline std::size_t size() const override final
    { return set_.size(); }

    inline InsertingResult insert(const Word &word) override final
    { return set_.insert(word); }

    inline bool contains(const Word &word) override final
    { return set_.find(word) != set_.end(); }

private:
    WordsSet set_;
};


#endif //DICTIONARYPATH_DEFAULTDICTIONARY_H
