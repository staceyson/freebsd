/*-
 * Copyright (c) 1998 Manuel Bouyer.
 * Copyright (c) 2013 Stacey Son <sson at FreeBSD dot org>.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef _UFS_UFS_BSWAP_H_
#define	_UFS_UFS_BSWAP_H_

#include <sys/endian.h>

/* Macros to access UFS flags */
#ifdef UFS_EI
#define	UFS_FSNEEDSWAP(fs)	((fs)->fs_flags & FS_SWAPPED)
#define UFS_MPNEEDSWAP(ump)	((ump)->um_flags & UFS_NEEDSWAP)
#define	UFS_IPNEEDSWAP(ip)	UFS_MPNEEDSWAP((ip)->i_ump)
#else
#define	UFS_FSNEEDSWAP(fs)	(0)
#define	UFS_MPNEEDSWAP(ump)	(0)
#define	UFS_IPNEEDSWAP(ip)	(0)
#endif /* UFS_EI */

#ifdef UFS_EI
#define	UFS_RW16(a, ns)	((ns) ? bswap16(a) : (a))
#define	UFS_RW32(a, ns)	((ns) ? bswap32(a) : (a))
#define	UFS_RW64(a, ns)	((ns) ? bswap64(a) : (a))
#else
#define UFS_RW16(a, ns) ((uint16_t)(a))
#define UFS_RW32(a, ns) ((uint32_t)(a))
#define UFS_RW64(a, ns) ((uint64_t)(a))
#endif /* UFS_EI */

#define	UFS_ADD16(a, b, ns)	(a) = UFS_RW16(UFS_RW16((a), (ns)) + (b), (ns))
#define	UFS_ADD32(a, b, ns)	(a) = UFS_RW32(UFS_RW32((a), (ns)) + (b), (ns))
#define	UFS_ADD64(a, b, ns)	(a) = UFS_RW64(UFS_RW64((a), (ns)) + (b), (ns))

#endif /* !_UFS_UFS_BSWAP_H_ */
