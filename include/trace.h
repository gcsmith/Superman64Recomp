#ifndef __SUPERMAN64_TRACE_H__
#define __SUPERMAN64_TRACE_H__

#include <stdio.h>

#define TRACE_ENTRY()   fprintf(stderr, "TRACE_ENTRY(%s)\n", __func__);
#define TRACE_RETURN()  fprintf(stderr, "TRACE_RETURN(%s)\n", __func__);

#endif // __SUPERMAN64_TRACE_H__

