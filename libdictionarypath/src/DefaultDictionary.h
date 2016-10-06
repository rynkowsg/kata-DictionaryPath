//
// Created by Grzegorz Rynkowski on 06/10/2016.
//

#ifndef DICTIONARYPATH_DEFAULTDICTIONARY_H
#define DICTIONARYPATH_DEFAULTDICTIONARY_H

#include <set>                                             // std::set
#include <utility>                                         // std::forward

#include <DictionaryPath/Dictionary.h>                     // Dictionary


class DefaultDictionary: public Dictionary
{
public:
    template<typename... Args>
    DefaultDictionary(Args &&... args)
        : set_{std::forward<Args>(args)...}
    {
    }

    InsertingResult insert(const Word &word) override;

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

private:
    std::set<Word> set_;
};


#endif //DICTIONARYPATH_DEFAULTDICTIONARY_H
