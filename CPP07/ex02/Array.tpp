/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:26:38 by aait-mal          #+#    #+#             */
/*   Updated: 2024/02/12 15:32:30 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = 0;
}

template <typename T>
Array<T>::Array(Array const &src) : _arr(new T[src._size]), _size(src._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = src._arr[i];
}

template <typename T>
Array<T>::~Array()
{
    if (_arr)
        delete[] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
    if (this != &src)
    {
        if (_arr)
            delete[] _arr;
        _arr = new T[src._size];
        _size = src._size;
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = src._arr[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size || i < 0)
        throw Array<T>::OutOfLimits();
    return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char *Array<T>::OutOfLimits::what() const throw()
{
    return "Out of limits";
}

#endif
