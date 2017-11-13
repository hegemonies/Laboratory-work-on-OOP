template <typename... Types> struct TypeList{};
typedef TypeList<int, double, bool, char, const char*> MyTypeList;


#define InstantiateMemFunc(className, funcName, types) \
template<typename T>        \
struct FuncWrapper_##className_##funcName \
{ \
  typedef decltype(&className::funcName<T>) type; \
  static constexpr type value = &className::funcName<T>; \
}; \
volatile auto i_##className_##funcName = detail::Instantiator<FuncWrapper_##className_##funcName, types>::instantiate();

template<template<typename>class FuncWrapperType, typename Type> // первый параметр шаблона - и есть тот новый обобщённый FuncWrapper_MyClass_f
struct Instantiator
{
  static int instantiate(...)
  {
    return 0;
  }
};

template<template<typename>class FuncWrapperType, typename Head, typename... Tail>
struct Instantiator<FuncWrapperType, TypeList<Head, Tail...> >
{
  typedef Instantiator<FuncWrapperType, TypeList<Tail...> > TailInstantiator;
  static typename std::pair<typename FuncWrapperType<Head>::type, decltype(TailInstantiator::instantiate())> 
  instantiate()
  {
    auto headTypeInstantiate = FuncWrapperType<Head>::value;
    return std::make_pair(headTypeInstantiate, TailInstantiator::instantiate());
  }
};
auto a = Instantiator<FuncWrapper_MyClass_f, MyTypeList>::instantiate();


namespace {
 InstantiateMemFunc(MyClass, f, MyTypeList)
}
