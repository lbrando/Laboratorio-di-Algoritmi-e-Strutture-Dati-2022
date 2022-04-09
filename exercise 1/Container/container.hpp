#ifndef CONTAINER_HPP
#define CONTAINER_HPP
 
/* ************************************************************************** */
 
#include <stdexcept>
#include <functional>
 
/* ************************************************************************** */
 
namespace lasd {
 
/* ************************************************************************** */
 
class Container {
 
protected:
size_t size=0; //ogni volta che si usa il costruttore size=0
 
public:
 
  // Destructor 
  virtual ~Container() = default; 
 
  /* ************************************************************************ */
 
  // Copy assignment
  Container& operator=(const Container&)=delete;
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
 
  // Move assignment
  Container& operator=(Container&&)=delete;
  // type operator=(argument); // Move assignment of abstract types should not be possible.
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const Container&) const noexcept=delete;  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const Container&) const noexcept=delete; // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
 
 
 
  /* ************************************************************************ */
 
  // Specific member functions
  virtual bool Empty() const noexcept{
    return size==0;
  } // type Empty() specifiers; // (concrete function should not throw exceptions)
 
  virtual size_t Size() const noexcept{
    return size;
  } // type Size() specifiers; // (concrete function should not throw exceptions)
 
  virtual void Clear()=0; // type Clear() specifiers;
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class LinearContainer: virtual public Container { // Must extend Container
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~LinearContainer()= default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) const noexcept = delete; // type operator=(argument); // Copy assignment of abstract types should not be possible.
 
  // Move assignment
  LinearContainer& operator=(LinearContainer&&) const noexcept = delete; // type operator=(argument); // Move assignment of abstract types should not be possible.
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const LinearContainer&) const noexcept=delete; // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer&) const noexcept=delete; // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
 
  /* ************************************************************************ */
 
  // Specific member functions
  virtual Data& Front() const = 0; // (concrete function must throw std::length_error when empty)
  virtual Data& Back() const = 0; // (concrete function must throw std::length_error when empty)
 
  virtual Data& operator[](const ulong) const = 0; // (concrete function must throw std::out_of_range when out of range)
 
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class TestableContainer: virtual public Container { // Must extend Container
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
 virtual ~TestableContainer() = default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  TestableContainer& operator=(const TestableContainer&) = delete; // type operator=(argument); // Copy assignment of abstract types should not be possible.
 
  // Move assignment
  TestableContainer& operator=(TestableContainer&&) noexcept = delete; // type operator=(argument); // Move assignment of abstract types should not be possible.
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
 
  /* ************************************************************************ */
 
  // Specific member functions
  virtual bool Exists(const Data&) const noexcept = 0; // type Exists(argument) specifiers; // (concrete function should not throw exceptions)
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class MappableContainer: virtual public Container { // Must extend Container
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~MappableContainer() = default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete; // type operator=(argument); // Copy assignment of abstract types should not be possible.
 
  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete; // type operator=(argument); // Move assignment of abstract types should not be possible.
 
  /* ************************************************************************ */
 
  // Comparison operators
 bool operator==(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
 bool operator!=(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
 
  /* ************************************************************************ */
 
  // Specific member functions
  typedef std::function<void(Data&, void*)> MapFunctor; // typedef std::function<void(Data&, void*)> MapFunctor;
 
  virtual void Map(const MapFunctor, void*) = 0;
  // type Map(arguments) specifiers;
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class FoldableContainer: virtual public TestableContainer<Data> { // Must extend TestableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
 virtual ~FoldableContainer() = default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
 
  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) = delete; // Move assignment of abstract types should not be possible.
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
 
  /* ************************************************************************ */
 
  // Specific member functions
  typedef std::function<void(const Data&, const void*, void*) noexcept> FoldFunctor;
  virtual void Fold(const FoldFunctor, const void*, void*) const = 0;
 
  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~PreOrderMappableContainer()= default; 
 
  /* ************************************************************************ */
 
  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer&)=delete;
 
  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) noexcept=delete;
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const PreOrderMappableContainer&) const noexcept=delete;
  bool operator!=(const PreOrderMappableContainer&) const noexcept=delete;
 
  /* ************************************************************************ */
 
  // Specific member functions
 
  using typename MappableContainer<Data>::MapFunctor;
 
 
  // type MapPreOrder(arguments) specifiers;
  virtual void MapPreOrder(const MapFunctor, void*) = 0;
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from MappableContainer)
 
  void Map(const MapFunctor, void*) override;
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class PreOrderFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~PreOrderFoldableContainer()=default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer&) = delete; 
 
  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&&) = delete; 
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const PreOrderFoldableContainer&) const noexcept = delete; 
  bool operator!=(const PreOrderFoldableContainer&) const noexcept = delete; 
 
  /* ************************************************************************ */
 
  // Specific member functions
 
  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;
 
  // type FoldPreOrder(arguments) specifiers;
  virtual void FoldPreOrder(const FoldFunctor, const void*, void*) const = 0;
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from FoldableContainer)
 
  // type Fold(argument) specifiers; // Override FoldableContainer member
  void Fold(const FoldFunctor, const void*, void*) const override;
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class PostOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~PostOrderMappableContainer()=default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer&)=delete;
 
  // Move assignment
  PostOrderMappableContainer& operator=(PostOrderMappableContainer&&)=delete;
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const PostOrderMappableContainer&) const noexcept=delete;
  bool operator!=(const PostOrderMappableContainer&) const noexcept=delete;
 
  /* ************************************************************************ */
 
  // Specific member functions
  using typename MappableContainer<Data>::MapFunctor;
 
 
  // type MapPostOrder(arguments) specifiers;
  virtual void MapPostOrder(const MapFunctor, void*) = 0;
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from MappableContainer)
 
  // type Map(argument) specifiers; // Override MappableContainer member
  void Map(const MapFunctor, void*) override;
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class PostOrderFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~PostOrderFoldableContainer()= default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer&) = delete;  
 
  // Move assignment
  PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&&) = delete;  
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const PostOrderFoldableContainer&) const noexcept = delete;  
  bool operator!=(const PostOrderFoldableContainer&) const noexcept = delete;  
 
  /* ************************************************************************ */
 
  // Specific member functions
 
  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor; 
 
  // type FoldPostOrder(arguments) specifiers;
  virtual void FoldPostOrder(const FoldFunctor, const void*, void*) const = 0; 
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from FoldableContainer)
 
  // type Fold(argument) specifiers; // Override FoldableContainer member
  void Fold(const FoldFunctor, const void*, void*) const override; 
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class InOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~InOrderMappableContainer()=default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  InOrderMappableContainer& operator=(const InOrderMappableContainer&)=delete; 
 
  // Move assignment
  InOrderMappableContainer& operator=(InOrderMappableContainer&&)=delete; 
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const InOrderMappableContainer&) const noexcept = delete; 
  bool operator!=(const InOrderMappableContainer&) const noexcept=delete; 
 
  /* ************************************************************************ */
 
  // Specific member functions
  using typename MappableContainer<Data>::MapFunctor; 
  virtual void MapInOrder(const MapFunctor, void*) = 0; // type MapInOrder(arguments) specifiers;
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from MappableContainer)
 
  // type Map(argument) specifiers; // Override MappableContainer member
  void Map(const MapFunctor, void*) override;
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class InOrderFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~InOrderFoldableContainer()=default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  InOrderFoldableContainer& operator=(const InOrderFoldableContainer&) = delete;  
 
  // Move assignment
  InOrderFoldableContainer& operator=(InOrderFoldableContainer&&) = delete;  
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const InOrderFoldableContainer&) const noexcept = delete;  
  bool operator!=(const InOrderFoldableContainer&) const noexcept = delete;
 
  /* ************************************************************************ */
 
  // Specific member functions
  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor; 
 
  // type FoldInOrder(arguments) specifiers;
  virtual void FoldInOrder(const FoldFunctor, void*) const = 0;
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from FoldableContainer)
 
  void Fold(const FoldFunctor, const void*, void*) const override; 
  // type Fold(argument) specifiers; // Override FoldableContainer member
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class BreadthMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~BreadthMappableContainer()=default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  BreadthMappableContainer& operator=(const BreadthMappableContainer&)=delete; 
 
  // Move assignment
  BreadthMappableContainer& operator=(BreadthMappableContainer&&)=delete; 
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const BreadthMappableContainer&) const noexcept=delete; 
  bool operator!=(const BreadthMappableContainer&) const noexcept=delete; 
 
  /* ************************************************************************ */
 
  // Specific member functions
 
 
  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor; 
 
  // type MapBreadth(arguments) specifiers;
  virtual void MapBreadth(const MapFunctor, void*) = 0; 
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from MappableContainer)
 
  // type Map(argument) specifiers; // Override MappableContainer member
  void Map(const MapFunctor, void*) override; 
 
};
 
/* ************************************************************************** */
 
template <typename Data>
class BreadthFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer<Data>
 
private:
 
  // ...
 
protected:
 
  // ...
 
public:
 
  // Destructor
  virtual ~BreadthFoldableContainer()=default;
 
  /* ************************************************************************ */
 
  // Copy assignment
  BreadthFoldableContainer& operator=(const BreadthFoldableContainer&) = delete;  
 
  // Move assignment
  BreadthFoldableContainer& operator=(BreadthFoldableContainer&&) = delete;  
 
  /* ************************************************************************ */
 
  // Comparison operators
  bool operator==(const BreadthFoldableContainer&) const noexcept = delete;  
  bool operator!=(const BreadthFoldableContainer&) const noexcept = delete;
 
  /* ************************************************************************ */
 
  // Specific member functions
 
  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor; 
 
  // type FoldBreadth(arguments) specifiers;
  virtual void FoldBreadth(const FoldFunctor, const void*, void*) const = 0; 
 
  /* ************************************************************************ */
 
  // Specific member functions (inherited from FoldableContainer)
  void Fold(const FoldFunctor, const void*, void*) const override; 
  // type Fold(argument) specifiers; // Override FoldableContainer member
 
 
};
 
/* ************************************************************************** */
 
}
 
#include "container.cpp"
 
#endif
