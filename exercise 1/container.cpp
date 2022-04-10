namespace lasd {
//Foldable Container
template <typename Data>
void AuxFoldExists(const Data& dat, const void *val, void *exists) {
    if (dat == *((Data*)val))
    {
        *((bool *)exists) = true;
    }
}
 
template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& dat) const noexcept {
    bool exists = false;
    FoldPreOrder(&AuxFoldExists<Data>, &dat, &exists);
    return exists;
}
//*************************************************************************/
//Mappable class
 
//PreOrderMappable container
template <typename Data>
inline void PreOrderMappableContainer<Data>::Map(MapFunctor fun, void* par){
    MapPreOrder(fun,par);
}
 
//PostOrderMappable container
template <typename Data>
inline void PostOrderMappableContainer<Data>::Map(MapFunctor fun, void* par){
    MapPostOrder(fun,par);
}
 
//InOrderMappable container
template <typename Data>
inline void InOrderMappableContainer<Data>::Map(MapFunctor fun, void* par){
    MapInOrder(fun,par);
}
 
//BreadthMappableContainer
template <typename Data>
inline void BreadthMappableContainer<Data>::Map(MapFunctor fun, void* par){
    MapBreadth(fun,par);
}
 
/*******************************************************************************/
//Foldable Class
 
//PreOrderFoldable container
template <typename Data>
inline void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc){
  FoldPreOrder(fun,par,acc);
}
 
//PostOrderFoldable container
template <typename Data>
inline void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc){
  FoldPostOrder(fun,par,acc);
}
 
 
//InOrderFoldable container
template <typename Data>
inline void InOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc){
  FoldInOrder(fun,par,acc);
}
 
//BreadthFoldableContainer container
template <typename Data>
inline void BreadthFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc){
  FoldBreadth(fun,par,acc);
}
 
/* ************************************************************************** */
}