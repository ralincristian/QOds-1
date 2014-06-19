/*
 * Copyright © 2014 f35f22fan@gmail.com
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef MTL_DSO_HXX_
#define MTL_DSO_HXX_

#include "global.hxx"

// Now we use the generic helper definitions above to define
// MTL_DSO_SHARE and MTL_DSO_HIDE.
// MTL_DSO_SHARE is used for the public API symbols or does nothing for
// static builds
// MTL_DSO_HIDE is used for non shared symbols.

#ifdef MTL_DSO // defined if it is compiled as a DSO
	// defined if we are building the DSO (instead of using it)
	#ifdef MTL_DSO_BUILD
		#define MTL_DSO_SHARE MTL_DSO_EXPORT_T
	#else
		#define MTL_DSO_SHARE MTL_DSO_IMPORT_T
	#endif // MTL_DSO_BUILD
	#define MTL_DSO_HIDE MTL_DSO_HIDDEN_T
#else // MTL_DSO is not defined: this means it is a static lib.
	#define MTL_DSO_SHARE
	#define MTL_DSO_HIDE
#endif // MTL_DSO

#endif //MTL_DSO_HXX_
