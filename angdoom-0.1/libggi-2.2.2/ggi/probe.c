/* $Id: probe.c,v 1.6 2005/09/19 18:46:44 cegger Exp $
******************************************************************************

   LibGGI core - probe for targets.

   Copyright (C) 2004 Christoph Egger

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************************
*/

#include "config.h"
#include <ggi/internal/internal.h>
#include <ggi/internal/ggi_debug.h>


ggi_visual_t _ggiProbeTarget(void)
{
	int err;
	uint32_t dlret = 0;
	ggi_dlhandle *dlh = NULL;
	ggi_visual_t vis = NULL;

	DPRINT_CORE("Launch display-auto\n");
	err = _ggiProbeDL(NULL, _ggiGetConfigHandle(), "display-auto", NULL, &vis, 0,
			  &dlh, &dlret);
	if (err) {
		DPRINT_CORE("display-auto failed\n");
		return NULL;
	}

	DPRINT_CORE("Unload display-auto\n");
	ggFreeModule(dlh->handle);
	free(dlh);

	return vis;
}
