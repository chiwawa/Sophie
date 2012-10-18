/*!
 * \class zia::api::Callback
 * \brief Impossible fast delegates
 *
 *      Imposible fast delegates GLH
 *                             ( Goes Like Hell )
 *                          galby_j pichot_f wacren_p
 *
 * Generic method pointeur
 *    ( Equivalent to a function ptr )
 *
 *   - No allocation
 *   - Light ( size of 2 pointers )
 *   - No virtual
 *   - Strict signature ( like a function pointer type )
 *   - One Callback signature can store any method ptr of any object
 *   - indifferentiates function pointers and method pointers + instance
 *   - >> Fastest C++ method callback
 *
 * \a Callback<int (double)> : Callback returning an int and taking a double as parameter
 *
 * \a Callback<void ()> : Callback returning nothing and taking nothing as parameter
 *
 * e.g.:
 *
 * How to create a \a Callback:
 * \code
 * zia::api::Callback< return_type (arg1_type, arg2_type, arg3_type) >
 *     ::create< object_type, mehtod_ptr >( object_instance_ptr )
 *
 * zia::api::Callback< return_type (arg1_type, arg2_type, arg3_type) >
 *     ::create( function_ptr )
 * \endcode
 *
 * Full usage:
 * \code
 * //
 * // Typedef it to simplify usage
 * //
 *
 *      typedef zia::api::Callback< int (double, size_t) >      MyCallback;
 *      typedef zia::api::Callback< void (int) >                MyCallback2;
 *
 * //
 * // Create a callback
 * //
 *
 *      class A // example class
 *      {
 *      public:
 *          int     method(double, size_t);
 *          void    method2(int);
 *      };
 *
 *      void        function(void*, int);
 *
 *      A           a;
 *      MyCallback  callback = MyCallback::create< A, &A::method >( &a );
 *      MyCallback2  callback2 = MyCallback2::create< A, &A::method2 >( &a );
 *      MyCallback2  callbackF = MyCallback2::create( &function );
 *
 * //
 * // Call it
 * //
 *
 *      callback(2.45, 1256);
 *      callback(42.635, 65553);
 *      callback(5454.0, 454);
 *
 *      callbackF(42);
 *      callbackF(1337);
 *
 *      callback2(42);
 *      callback2(-42);
 *      callback2(23);
 *
 * // enjoy
 * \endcode
 */


#ifndef _ZIA_API_CALLBACK_H_
#define _ZIA_API_CALLBACK_H_

#include "defines.hpp"

_BOF_ZIA_API_

template <typename T>
class Callback;

# define ZIA_CALLBACK_GEN(_TN_TARGS, _TARGS, _CTARGS, _TN_ARGS, _CTN_ARGS, _ARGS, _CARGS) \
template <typename R _TN_TARGS>                                         \
class Callback<R (_TARGS)>                                              \
{                                                                       \
public:                                                                 \
  template <typename T>                                                 \
  struct Traits                                                         \
    {                                                                   \
      typedef R			(T::*Method)(_TARGS);                   \
    };                                                                  \
                                                                        \
  typedef R			(*Funcptr)(_TARGS);                     \
                                                                        \
  typedef Callback<R (_TARGS)>	This;                                   \
  typedef R			(*CallerPtr)(void * _CTARGS);           \
                                                                        \
  inline Callback()                                                     \
    : mInstance(0), mCaller(0)                                          \
    {}                                                                  \
                                                                        \
  template <typename T, typename Traits<T>::Method method>              \
  inline static This		create(T* instance)                     \
    {                                                                   \
      return (This(instance, &caller<T, method>));                      \
    }                                                                   \
                                                                        \
  inline static This		create(CallerPtr func, void* param = 0) \
    {                                                                   \
      return (This(param, func));                                       \
    }                                                                   \
                                                                        \
  inline R			operator()(_TN_ARGS)                    \
    {                                                                   \
      return ((*mCaller)(mInstance _CARGS));                            \
    }                                                                   \
                                                                        \
  inline bool			isSet() const                           \
    {                                                                   \
      return (mCaller != 0);                                            \
    }                                                                   \
                                                                        \
  inline void			clear()                                 \
    {                                                                   \
      mCaller = 0;                                                      \
    }                                                                   \
                                                                        \
private:                                                                \
  void*				mInstance;                              \
  CallerPtr			mCaller;                                \
                                                                        \
  inline Callback(void *instance, CallerPtr ptr)                        \
    : mInstance(instance), mCaller(ptr)                                 \
    {}                                                                  \
                                                                        \
  template <typename T, typename Traits<T>::Method method>              \
  inline static R	caller(void* instance _CTN_ARGS)                \
    {                                                                   \
      return ((static_cast<T*>(instance)->*method)(_ARGS));             \
    }                                                                   \
                                                                        \
};

// 0 parameters
ZIA_CALLBACK_GEN(,,,,,,)

// 1 parameter
#define _TN_TARGS_1     , typename TARG1
#define _TARGS_1        TARG1
#define _CTARGS_1       , TARG1
#define _TN_ARGS_1      TARG1 _arg1
#define _CTN_ARGS_1     , _TN_ARGS_1
#define _ARGS_1         _arg1
#define _CARGS_1        , _arg1
ZIA_CALLBACK_GEN( _TN_TARGS_1, _TARGS_1, _CTARGS_1, _TN_ARGS_1, _CTN_ARGS_1, _ARGS_1, _CARGS_1 )

// 2 parameters
#define _TN_TARGS_2     _TN_TARGS_1, 	typename TARG2
#define _TARGS_2        _TARGS_1,	TARG2
#define _CTARGS_2       _CTARGS_1, 	TARG2
#define _TN_ARGS_2      _TN_ARGS_1,	TARG2 _arg2
#define _CTN_ARGS_2     _CTN_ARGS_1, 	TARG2 _arg2
#define _ARGS_2         _ARGS_1,	_arg2
#define _CARGS_2        _CARGS_1, 	_arg2
ZIA_CALLBACK_GEN( _TN_TARGS_2, _TARGS_2, _CTARGS_2, _TN_ARGS_2, _CTN_ARGS_2, _ARGS_2, _CARGS_2 )

// 3 parameters
#define _TN_TARGS_3     _TN_TARGS_2, 	typename TARG3
#define _TARGS_3        _TARGS_2,	TARG3
#define _CTARGS_3       _CTARGS_2, 	TARG3
#define _TN_ARGS_3      _TN_ARGS_2,	TARG3 _arg3
#define _CTN_ARGS_3     _CTN_ARGS_2, 	TARG3 _arg3
#define _ARGS_3         _ARGS_2,	_arg3
#define _CARGS_3        _CARGS_2, 	_arg3
ZIA_CALLBACK_GEN( _TN_TARGS_3, _TARGS_3, _CTARGS_3, _TN_ARGS_3, _CTN_ARGS_3, _ARGS_3, _CARGS_3 )

// 4 parameters
#define _TN_TARGS_4     _TN_TARGS_3, 	typename TARG4
#define _TARGS_4        _TARGS_3,	TARG4
#define _CTARGS_4       _CTARGS_3, 	TARG4
#define _TN_ARGS_4      _TN_ARGS_3,	TARG4 _arg4
#define _CTN_ARGS_4     _CTN_ARGS_3, 	TARG4 _arg4
#define _ARGS_4         _ARGS_3,	_arg4
#define _CARGS_4        _CARGS_3, 	_arg4
ZIA_CALLBACK_GEN( _TN_TARGS_4, _TARGS_4, _CTARGS_4, _TN_ARGS_4, _CTN_ARGS_4, _ARGS_4, _CARGS_4 )

// 5 parameters
#define _TN_TARGS_5     _TN_TARGS_4, 	typename TARG5
#define _TARGS_5        _TARGS_4,	TARG5
#define _CTARGS_5       _CTARGS_4, 	TARG5
#define _TN_ARGS_5      _TN_ARGS_4,	TARG5 _arg5
#define _CTN_ARGS_5     _CTN_ARGS_4, 	TARG5 _arg5
#define _ARGS_5         _ARGS_4,	_arg5
#define _CARGS_5        _CARGS_4, 	_arg5
ZIA_CALLBACK_GEN( _TN_TARGS_5, _TARGS_5, _CTARGS_5, _TN_ARGS_5, _CTN_ARGS_5, _ARGS_5, _CARGS_5 )

// 6 parameters
#define _TN_TARGS_6     _TN_TARGS_5, 	typename TARG6
#define _TARGS_6        _TARGS_5,	TARG6
#define _CTARGS_6       _CTARGS_5, 	TARG6
#define _TN_ARGS_6      _TN_ARGS_5,	TARG6 _arg6
#define _CTN_ARGS_6     _CTN_ARGS_5, 	TARG6 _arg6
#define _ARGS_6         _ARGS_5,	_arg6
#define _CARGS_6        _CARGS_5, 	_arg6
ZIA_CALLBACK_GEN( _TN_TARGS_6, _TARGS_6, _CTARGS_6, _TN_ARGS_6, _CTN_ARGS_6, _ARGS_6, _CARGS_6 )

// 7 parameters
#define _TN_TARGS_7     _TN_TARGS_6, 	typename TARG7
#define _TARGS_7        _TARGS_6,	TARG7
#define _CTARGS_7       _CTARGS_6, 	TARG7
#define _TN_ARGS_7      _TN_ARGS_6,	TARG7 _arg7
#define _CTN_ARGS_7     _CTN_ARGS_6, 	TARG7 _arg7
#define _ARGS_7         _ARGS_6,	_arg7
#define _CARGS_7        _CARGS_6, 	_arg7
ZIA_CALLBACK_GEN( _TN_TARGS_7, _TARGS_7, _CTARGS_7, _TN_ARGS_7, _CTN_ARGS_7, _ARGS_7, _CARGS_7 )

// 8 parameters
#define _TN_TARGS_8     _TN_TARGS_7, 	typename TARG8
#define _TARGS_8        _TARGS_7,	TARG8
#define _CTARGS_8       _CTARGS_7, 	TARG8
#define _TN_ARGS_8      _TN_ARGS_7,	TARG8 _arg8
#define _CTN_ARGS_8     _CTN_ARGS_7, 	TARG8 _arg8
#define _ARGS_8         _ARGS_7,	_arg8
#define _CARGS_8        _CARGS_7, 	_arg8
ZIA_CALLBACK_GEN( _TN_TARGS_8, _TARGS_8, _CTARGS_8, _TN_ARGS_8, _CTN_ARGS_8, _ARGS_8, _CARGS_8 )

_EOF_ZIA_API_

#endif /* _ZIA_API_CALLBACK_H_ */
