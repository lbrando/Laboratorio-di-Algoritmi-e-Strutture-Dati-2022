#ifndef VECTOR_HPP
#define VECTOR_HPP


/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector:
             virtual public LinearContainer <Data>,
             virtual public PreOrderMappableContainer<Data>,
             virtual public PostOrderMappableContainer<Data>,
             virtual public PreOrderFoldableContainer<Data>,
             virtual public PostOrderFoldableContainer<Data>{

private:

  // ...

protected:

using LinearContainer<Data>::size;
Data* Elements= nullptr;

public:

  // Default constructor
  Vector()=default;
  // Vector() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong); // A vector with a given initial dimension
  Vector(const LinearContainer<Data>&); // A vector obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector&);

  // Move constructor
  Vector(const Vector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector&);

  // Move assignment
  Vector&operator=(const Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector&) const noexcept;
  bool operator!=(const Vector&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void Resize (const ulong); // Resize the vector to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() noexcept override;// Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  Data& operator[](const ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
  using typename MappableContainer<Data>::MapFunctor;
  
  void Map(const MapFunctor, void*) override; // Override MappableContainer member
  //const se va all'interno o all'esterno della parentesi

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)
  void MapPreOrder(const MapFunctor, void*) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  void MapPostOrder(const MapFunctor, void*) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;
  
  void Fold(FoldFunctor, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  void FoldPostOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
