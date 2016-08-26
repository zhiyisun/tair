/*
 * (C) 2007-2010 Alibaba Group Holding Limited
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * commonly used data structures and value define
 *
 * Version: $Id: define.hpp 973 2012-07-06 10:56:22Z nayan@taobao.com $
 *
 * Authors:
 *   yubai.lk <yubai.lk@taobao.com>
 *     - initial release
 *
 */

#ifndef  TAIR_COMMON_ATOMIC_H_
#define  TAIR_COMMON_ATOMIC_H_
#include <stdint.h>

namespace tair
{
  namespace common
  {
    //return: the incremented value;
    /// 原子地做 8位，16位，32位，64位的++i的操作
    /// 该操作虽然参数和返回值都是无符号型整数，但是一样可以
    /// 对有符号型整数做操作，只需要做适当的参数转换即可
    /// @param pv 指向操作数的指针
    /// @return 操作数加1以后的数值
    static __inline__ uint64_t atomic_inc(volatile uint64_t * pv)
    {
	return __atomic_add_fetch((uint64_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint32_t atomic_inc(volatile uint32_t * pv)
    {
	return __atomic_add_fetch((uint32_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint16_t atomic_inc(volatile uint16_t * pv)
    {
	return __atomic_add_fetch((uint16_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint8_t  atomic_inc(volatile uint8_t * pv)
    {
	return __atomic_add_fetch((uint8_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    //return: the decremented value;
    /// 原子地做 8位，16位，32位，64位的--i的操作
    /// 该操作虽然参数和返回值都是无符号型整数，但是一样可以
    /// 对有符号型整数做操作，只需要做适当的参数转换即可
    /// @param pv 指向操作数的指针
    /// @return 操作数减1后的数值
    static __inline__ uint64_t atomic_dec(volatile uint64_t * pv)
    {
	return __atomic_sub_fetch((uint64_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint32_t atomic_dec(volatile uint32_t * pv)
    {
	return __atomic_sub_fetch((uint32_t *)pv, 1, __ATOMIC_SEQ_CST);
    }
    static __inline__ uint16_t atomic_dec(volatile uint16_t * pv)
    {
	return __atomic_sub_fetch((uint16_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint8_t  atomic_dec(volatile uint8_t * pv)
    {
	return __atomic_sub_fetch((uint8_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    //return: the initial value of *pv
    /// 原子地做 8位，16位，32位，64位的加法的操作
    /// 该操作虽然参数和返回值都是无符号型整数，但是一样可以
    /// 对有符号型整数做操作，只需要做适当的参数转换即可
    /// @param pv 指向操作数的指针
    /// @return 操作数加法之前的数值
    static __inline__ uint64_t atomic_add(volatile uint64_t * pv, const uint64_t av)
    {
	return __atomic_fetch_add((uint64_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint32_t atomic_add(volatile uint32_t * pv, const uint32_t av)
    {
	return __atomic_fetch_add((uint32_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint16_t atomic_add(volatile uint16_t * pv, const uint16_t av)
    {
	return __atomic_fetch_add((uint16_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint8_t  atomic_add(volatile uint8_t * pv, const uint8_t av)
    {
	return __atomic_fetch_add((uint8_t *)pv, 1, __ATOMIC_SEQ_CST);
    }

    //function: set *pv to nv
    //return: the initial value of *pv
    /// 原子地把nv赋值给pv指向的整数，支持8位，16位，32位，84位操作
    /// @param pv 待赋值的整数（目的操作数）
    /// @param nv 向pv赋的整数
    /// @return pv指向的赋值前的数值
    static __inline__ uint64_t atomic_exchange(volatile uint64_t * pv, const uint64_t nv)
    {
	    return __atomic_exchange_n((uint64_t *)pv, (uint64_t)nv, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint32_t atomic_exchange(volatile uint32_t * pv, const uint32_t nv)
    {
	    return __atomic_exchange_n((uint32_t *)pv, (uint32_t)nv, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint16_t atomic_exchange(volatile uint16_t * pv, const uint16_t nv)
    {
	    return __atomic_exchange_n((uint16_t *)pv, (uint16_t)nv, __ATOMIC_SEQ_CST);
    }

    static __inline__ uint8_t  atomic_exchange(volatile uint8_t * pv, const uint8_t nv)
    {
	    return __atomic_exchange_n((uint8_t *)pv, (uint8_t)nv, __ATOMIC_SEQ_CST);
    }

    //function: compare *pv to cv, if equal, set *pv to nv, otherwise do nothing.
    //return: the initial value of *pv
    /// 比较pv和cv，如果两者相等，则返回pv原有数值并且把nv赋值给pv
    /// 否则什么也不作，返回pv原有数值
    /// @param pv 待赋值的整数（目的操作数）
    /// @param nv 向pv赋的整数
    /// @param cv 和pv比较的整数
    /// @return pv指向的操作前的数值
    static __inline__ uint64_t atomic_compare_exchange(volatile uint64_t * pv,
        const uint64_t nv, const uint64_t cv)
    {
	    uint64_t cv_temp = cv;
	    return __atomic_compare_exchange_n((uint64_t *)pv,
				    (uint64_t *)&cv_temp, (uint64_t)nv, false,
				    __ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST);
    }

    static __inline__ uint32_t atomic_compare_exchange(volatile uint32_t * pv,
        const uint32_t nv, const uint32_t cv)
    {
	    uint32_t cv_temp = cv;
	    return __atomic_compare_exchange_n((uint32_t *)pv,
				    (uint32_t *)&cv_temp,(uint32_t)nv, false,
				    __ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST);
    }

    static __inline__ uint16_t atomic_compare_exchange(volatile uint16_t * pv,
        const uint16_t nv, const uint16_t cv)
    {
	    uint16_t cv_temp = cv;
	    return __atomic_compare_exchange_n((uint16_t *)pv,
				    (uint16_t *)&cv_temp, (uint16_t)nv, false,
				    __ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST);
    }
    static __inline__ uint8_t atomic_compare_exchange(volatile uint8_t * pv,
        const uint8_t nv, const uint8_t cv)
    {
	    uint8_t cv_temp = cv;
	    return __atomic_compare_exchange_n((uint8_t *)pv,
				    (uint8_t *)&cv_temp, (uint8_t)nv, false,
				    __ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST);
    }

    typedef void * pvoid;

    //function: set *pv to nv
    //return: the initial value of *pv
    /// 把nv原子地赋值给*pv
    static __inline__ pvoid atomic_exchange_pointer(volatile pvoid * pv, const pvoid nv)
    {
      return (pvoid) atomic_exchange((uint64_t *) pv, (uint64_t) nv);
    }
    //function: compare *pv to cv, if equal, set *pv to nv, otherwise do nothing.
    //return: the initial value of *pv
    /// 比较cv和*pv，如果两者相等则把nv赋值给*pv，并且返回*pv原有数值
    /// 否则返回*pv原有数值，不做赋值操作
    static __inline__ pvoid atomic_compare_exchange_pointer(volatile pvoid * pv,
        const pvoid nv, const pvoid cv)
    {
      return (pvoid) atomic_compare_exchange((uint64_t *) pv, (uint64_t) nv, (uint64_t)cv);
    }
  }
}
#endif // TAIR_COMMON_ATOMIC_H_
