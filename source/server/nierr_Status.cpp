/*!
   \file nierr_Status.c
   \brief Status C functions, the low level manipulator for Status
*/
/*
   Copyright (c) 2012-2012 National Instruments Corporation.
   All rights reserved.
*/

/* includes... */
#include "nierr_Status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STATUS_MIN_DESC_SIZE 512

#define STATUS_JSON_MAX_CAPACITY ((uint32_t)(INT32_MAX))  /* quite arbitrary, but big enough. */

char *initJsonBuffer(char* buf, size_t size, const char* initial_json)
{
   const char JSONZ_TERM_CHAR = 'J';
   size_t len;

   if (!initial_json)
   {
      len = strlen(buf);
      if (size <= len+1) 
      {
         return NULL; /* not enough space in buffer */
      }
   }
   else
   {
      len = strlen(initial_json);
      if (size <= len+1)
      {
         return NULL; /* not enough space in buffer */
      }

      strncpy(buf, initial_json, len+1);
   }

   memset(buf+len+1 /*+1 from the null char*/, 0, size-len-1-1 /* the last -1 from termination char*/);
   buf[size-1] = JSONZ_TERM_CHAR;
   return buf+len-1;
}

uint32_t calcDescSizeToAllocate_(uint32_t size)
{
   if (size <= STATUS_MIN_DESC_SIZE) return STATUS_MIN_DESC_SIZE;
   /* else, round up to the next highest power of 2 - http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
    * This is done for performance and minimize memory fragmentation
    */
   --size;
   size |= (size >> 1);
   size |= (size >> 2);
   size |= (size >> 4);
   size |= (size >> 8);
   size |= (size >> 16);
   ++size;
   return size;
}

bool kNICCall nierr_defaultReallocJson(nierr_Status *s, uint32_t size)
{
   char *json;

   if (size == 0)
   {
      if (s->json)
      {
         free(s->json);
         s->capacity = 0;
         s->json = NULL;
      }
      return true;
   }

   if (size <= s->capacity) return true; // we're never shrinking json
   if (size > STATUS_JSON_MAX_CAPACITY) return false; // avoid overflow

   /* alright, we're growing the json here */
   size = calcDescSizeToAllocate_(size);
   json = (char*)malloc(size);
   if (!json) return false;

   initJsonBuffer(json, size, (s->json)? s->json : NIERR_JSON_EMPTY);
   free(s->json);

   s->capacity = size;
   s->json = json;
   return true;
}

void nierr_Status_initialize(struct nierr_Status * status)
{
   status->code = 0;
   status->capacity = 0;
   status->reallocJson = &nierr_defaultReallocJson;
   status->json = nullptr;
}
