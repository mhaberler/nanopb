#include <stdio.h>
#include <pb.h>

typedef struct { uint32_t msgid; size_t size; pb_field_t *fields; void *user; } msginfo_t;

#define PB_MSG(id) {id, sizeof(PB_MSG_ ## id), PB_MSG_ ## id ## _fields, NULL},

#define PB_MSGID 1

#include "simple.pb.h"
#include "second.pb.h"



msginfo_t msgs[] = {
  SIMPLE_MESSAGES
  SECOND_MESSAGES

};

