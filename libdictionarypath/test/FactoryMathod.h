//
// Created by Grzegorz Rynkowski on 09/10/2016.
//

#ifndef DICTIONARYPATH_FACTORYMATHOD_H
#define DICTIONARYPATH_FACTORYMATHOD_H


///
/// Template implementation of Factory Method pattern.
///
template<class T>
class FactoryMethod
{
public:
    using Ref = std::shared_ptr<T>;

    /// Returns an object of T.
    template<typename... Args>
    static Ref Create(Args &&... args)
    {
//        return Ref{new T(std::forward<Args>(args)...)};
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
};


#endif //DICTIONARYPATH_FACTORYMATHOD_H
