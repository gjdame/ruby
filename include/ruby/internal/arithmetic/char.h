#ifndef RBIMPL_ARITHMETIC_CHAR_H                     /*-*-C++-*-vi:se ft=cpp:*/
#define RBIMPL_ARITHMETIC_CHAR_H
/**
 * @file
 * @author     Ruby developers <ruby-core@ruby-lang.org>
 * @copyright  This  file  is   a  part  of  the   programming  language  Ruby.
 *             Permission  is hereby  granted,  to  either redistribute  and/or
 *             modify this file, provided that  the conditions mentioned in the
 *             file COPYING are met.  Consult the file for details.
 * @warning    Symbols   prefixed  with   either  `RBIMPL`   or  `rbimpl`   are
 *             implementation details.   Don't take  them as canon.  They could
 *             rapidly appear then vanish.  The name (path) of this header file
 *             is also an  implementation detail.  Do not expect  it to persist
 *             at the place it is now.  Developers are free to move it anywhere
 *             anytime at will.
 * @note       To  ruby-core:  remember  that   this  header  can  be  possibly
 *             recursively included  from extension  libraries written  in C++.
 *             Do not  expect for  instance `__VA_ARGS__` is  always available.
 *             We assume C99  for ruby itself but we don't  assume languages of
 *             extension libraries. They could be written in C++98.
 * @brief      Arithmetic conversion between C's `char` and Ruby's.
 */
#include "ruby/internal/arithmetic/int.h"  /* NUM2INT is here, but */
#include "ruby/internal/arithmetic/long.h" /* INT2FIX is here.*/
#include "ruby/internal/attr/artificial.h"
#include "ruby/internal/attr/const.h"
#include "ruby/internal/attr/constexpr.h"
#include "ruby/internal/cast.h"
#include "ruby/internal/core/rstring.h"
#include "ruby/internal/value_type.h"

#define RB_NUM2CHR rb_num2char_inline
#define NUM2CHR    RB_NUM2CHR
#define CHR2FIX    RB_CHR2FIX

/** @cond INTERNAL_MACRO */
#define RB_CHR2FIX RB_CHR2FIX
/** @endcond */

RBIMPL_ATTR_CONST_ON_NDEBUG()
RBIMPL_ATTR_CONSTEXPR_ON_NDEBUG(CXX14)
RBIMPL_ATTR_ARTIFICIAL()
static inline VALUE
RB_CHR2FIX(unsigned char c)
{
    return RB_INT2FIX(c);
}

static inline char
rb_num2char_inline(VALUE x)
{
    if (RB_TYPE_P(x, RUBY_T_STRING) && (RSTRING_LEN(x)>=1))
        return RSTRING_PTR(x)[0];
    else
        return RBIMPL_CAST((char)RB_NUM2INT(x));
}

#endif /* RBIMPL_ARITHMETIC_CHAR_H */
