/* Test for binary integer constants.  */

/* Derived from: c99-intconst-1.c, bye Joseph Myers <jsm28@cam.ac.uk>.  */
/* Origin: Joerg Wunsch <j.gnu@uriah.heep.sax.de>.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

#include <limits.h>

/* Assertion that constant C is of type T.  */
#define ASSERT_CONST_TYPE(C, T)			\
	do {					\
	  typedef T type;			\
	  typedef type **typepp;		\
	  typedef __typeof__((C)) ctype;	\
	  typedef ctype **ctypepp;		\
	  typepp x = 0;				\
	  ctypepp y = 0;			\
	  x = y;				\
	  y = x;				\
	} while (0)

/* (T *) if E is zero, (void *) otherwise.  */
#define type_if_not(T, E) __typeof__(0 ? (T *)0 : (void *)(E))

/* (T *) if E is nonzero, (void *) otherwise.  */
#define type_if(T, E) type_if_not(T, !(E))

/* Combine pointer types, all but one (void *).  */
#define type_comb2(T1, T2) __typeof__(0 ? (T1)0 : (T2)0)
#define type_comb3(T1, T2, T3) type_comb2(T1, type_comb2(T2, T3))
#define type_comb4(T1, T2, T3, T4)				\
	type_comb2(T1, type_comb2(T2, type_comb2(T3, T4)))
#define type_comb6(T1, T2, T3, T4, T5, T6)				   \
	type_comb2(T1,							   \
		   type_comb2(T2,					   \
			      type_comb2(T3,				   \
					 type_comb2(T4,			   \
						    type_comb2(T5, T6)))))

/* (T1 *) if E1, otherwise (T2 *) if E2.  */
#define first_of2p(T1, E1, T2, E2) type_comb2(type_if(T1, (E1)),	   \
					     type_if(T2, (!(E1) && (E2))))
/* (T1 *) if E1, otherwise (T2 *) if E2, otherwise (T3 *) if E3.  */
#define first_of3p(T1, E1, T2, E2, T3, E3)			\
	type_comb3(type_if(T1, (E1)),				\
		   type_if(T2, (!(E1) && (E2))),		\
		   type_if(T3, (!(E1) && !(E2) && (E3))))
/* (T1 *) if E1, otherwise (T2 *) if E2, otherwise (T3 *) if E3, otherwise
   (T4 *) if E4.  */
#define first_of4p(T1, E1, T2, E2, T3, E3, T4, E4)			\
	type_comb4(type_if(T1, (E1)),					\
		   type_if(T2, (!(E1) && (E2))),			\
		   type_if(T3, (!(E1) && !(E2) && (E3))),		\
		   type_if(T4, (!(E1) && !(E2) && !(E3) && (E4))))
/* (T1 *) if E1, otherwise (T2 *) if E2, otherwise (T3 *) if E3, otherwise
   (T4 *) if E4, otherwise (T5 *) if E5, otherwise (T6 *) if E6.  */
#define first_of6p(T1, E1, T2, E2, T3, E3, T4, E4, T5, E5, T6, E6)	    \
	type_comb6(type_if(T1, (E1)),					    \
		   type_if(T2, (!(E1) && (E2))),			    \
		   type_if(T3, (!(E1) && !(E2) && (E3))),		    \
		   type_if(T4, (!(E1) && !(E2) && !(E3) && (E4))),	    \
		   type_if(T5, (!(E1) && !(E2) && !(E3) && !(E4) && (E5))), \
		   type_if(T6, (!(E1) && !(E2) && !(E3)			    \
				&& !(E4) && !(E5) && (E6))))

/* Likewise, but return the original type rather than a pointer type.  */
#define first_of2(T1, E1, T2, E2)			\
	__typeof__(*((first_of2p(T1, (E1), T2, (E2)))0))
#define first_of3(T1, E1, T2, E2, T3, E3)				\
	__typeof__(*((first_of3p(T1, (E1), T2, (E2), T3, (E3)))0))
#define first_of4(T1, E1, T2, E2, T3, E3, T4, E4)			    \
	__typeof__(*((first_of4p(T1, (E1), T2, (E2), T3, (E3), T4, (E4)))0))
#define first_of6(T1, E1, T2, E2, T3, E3, T4, E4, T5, E5, T6, E6)	\
	__typeof__(*((first_of6p(T1, (E1), T2, (E2), T3, (E3),		\
				 T4, (E4), T5, (E5), T6, (E6)))0))

/* Types of constants according to the C99 rules.  */
#define C99_UNSUF_TYPE(C)					\
	first_of6(int, (C) <= INT_MAX,				\
		  unsigned int, (C) <= UINT_MAX,		\
		  long int, (C) <= LONG_MAX,			\
		  unsigned long int, (C) <= ULONG_MAX,		\
		  long long int, (C) <= LLONG_MAX,		\
		  unsigned long long int, (C) <= ULLONG_MAX)
#define C99_SUFu_TYPE(C)					\
	first_of3(unsigned int, (C) <= UINT_MAX,		\
		  unsigned long int, (C) <= ULONG_MAX,		\
		  unsigned long long int, (C) <= ULLONG_MAX)
#define C99_SUFl_TYPE(C)					\
	first_of4(long int, (C) <= LONG_MAX,			\
		  unsigned long int, (C) <= ULONG_MAX,		\
		  long long int, (C) <= LLONG_MAX,		\
		  unsigned long long int, (C) <= ULLONG_MAX)
#define C99_SUFul_TYPE(C)					\
	first_of2(unsigned long int, (C) <= ULONG_MAX,		\
		  unsigned long long int, (C) <= ULLONG_MAX)
#define C99_SUFll_TYPE(C)					\
	first_of2(long long int, (C) <= LLONG_MAX,		\
		  unsigned long long int, (C) <= ULLONG_MAX)

/* Checks that constants have correct type.  */
#define CHECK_UNSUF_TYPE(C)				\
	ASSERT_CONST_TYPE((C), C99_UNSUF_TYPE((C)))
#define CHECK_SUFu_TYPE(C) ASSERT_CONST_TYPE((C), C99_SUFu_TYPE((C)))
#define CHECK_SUFl_TYPE(C)				\
	ASSERT_CONST_TYPE((C), C99_SUFl_TYPE((C)))
#define CHECK_SUFul_TYPE(C) ASSERT_CONST_TYPE((C), C99_SUFul_TYPE((C)))
#define CHECK_SUFll_TYPE(C)				\
	ASSERT_CONST_TYPE((C), C99_SUFll_TYPE((C)))
#define CHECK_SUFull_TYPE(C) ASSERT_CONST_TYPE((C), unsigned long long int)

/* Check an octal or hexadecimal value, with all suffixes.  */
#define CHECK_CONST(C)                  	\
	CHECK_UNSUF_TYPE(C);                    \
	CHECK_SUFu_TYPE(C##u);			\
	CHECK_SUFu_TYPE(C##U);			\
	CHECK_SUFl_TYPE(C##l);                  \
	CHECK_SUFl_TYPE(C##L);                  \
	CHECK_SUFul_TYPE(C##ul);		\
	CHECK_SUFul_TYPE(C##uL);		\
	CHECK_SUFul_TYPE(C##Ul);		\
	CHECK_SUFul_TYPE(C##UL);		\
	CHECK_SUFll_TYPE(C##ll);		\
	CHECK_SUFll_TYPE(C##LL);		\
	CHECK_SUFull_TYPE(C##ull);		\
	CHECK_SUFull_TYPE(C##uLL);		\
	CHECK_SUFull_TYPE(C##Ull);		\
	CHECK_SUFull_TYPE(C##ULL);

#define CHECK_BIN_CONST(C)			\
	CHECK_CONST(0b##C);                     \
	CHECK_CONST(0B##C);

/* True iff "long long" is at least B bits.  This presumes that (B-2)/3 is at
   most 63.  */
#define LLONG_AT_LEAST(B)			\
	(LLONG_MAX >> ((B)-2)/3 >> ((B)-2)/3	\
	 >> ((B)-2 - ((B)-2)/3 - ((B)-2)/3))

#define LLONG_HAS_BITS(B) (LLONG_AT_LEAST((B)) && !LLONG_AT_LEAST((B) + 1))

#define FOO 0b1101
#if !FOO
# error "preprocessor does not accept binary constants"
#endif

void
foo (void)
{
  /* Check all 2^n and 2^n - 1 up to 2^72 - 1.  */
  CHECK_BIN_CONST(1);
  CHECK_BIN_CONST(10);
  CHECK_BIN_CONST(11);
  CHECK_BIN_CONST(100);
  CHECK_BIN_CONST(111);
  CHECK_BIN_CONST(1000);
  CHECK_BIN_CONST(1111);
  CHECK_BIN_CONST(10000);
  CHECK_BIN_CONST(11111);
  CHECK_BIN_CONST(100000);
  CHECK_BIN_CONST(111111);
  CHECK_BIN_CONST(1000000);
  CHECK_BIN_CONST(1111111);
  CHECK_BIN_CONST(10000000);
  CHECK_BIN_CONST(11111111);
  CHECK_BIN_CONST(100000000);
  CHECK_BIN_CONST(111111111);
  CHECK_BIN_CONST(1000000000);
  CHECK_BIN_CONST(1111111111);
  CHECK_BIN_CONST(10000000000);
  CHECK_BIN_CONST(11111111111);
  CHECK_BIN_CONST(100000000000);
  CHECK_BIN_CONST(111111111111);
  CHECK_BIN_CONST(1000000000000);
  CHECK_BIN_CONST(1111111111111);
  CHECK_BIN_CONST(10000000000000);
  CHECK_BIN_CONST(11111111111111);
  CHECK_BIN_CONST(100000000000000);
  CHECK_BIN_CONST(111111111111111);
  CHECK_BIN_CONST(1000000000000000);
  CHECK_BIN_CONST(1111111111111111);
  CHECK_BIN_CONST(10000000000000000);
  CHECK_BIN_CONST(11111111111111111);
  CHECK_BIN_CONST(100000000000000000);
  CHECK_BIN_CONST(111111111111111111);
  CHECK_BIN_CONST(1000000000000000000);
  CHECK_BIN_CONST(1111111111111111111);
  CHECK_BIN_CONST(10000000000000000000);
  CHECK_BIN_CONST(11111111111111111111);
  CHECK_BIN_CONST(100000000000000000000);
  CHECK_BIN_CONST(111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111111111111);
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111111111111111);
#if LLONG_AT_LEAST(65)
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(66)
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(67)
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(68)
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(69)
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(70)
  CHECK_BIN_CONST(1000000000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(1111111111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(71)
  CHECK_BIN_CONST(10000000000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(11111111111111111111111111111111111111111111111111111111111111111111111);
#endif
#if LLONG_AT_LEAST(72)
  CHECK_BIN_CONST(100000000000000000000000000000000000000000000000000000000000000000000000);
  CHECK_BIN_CONST(111111111111111111111111111111111111111111111111111111111111111111111111);
#endif
}

