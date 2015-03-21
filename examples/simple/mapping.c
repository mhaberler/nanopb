#include <stdio.h>
#include <pb.h>

typedef struct {
    uint32_t msgid;
    const char *name;
    size_t size;
    const pb_field_t *fields;
    void *user;
} msginfo_t;

#define PB_MSG(id, name) {					\
	id,							\
	    # name,						\
	    sizeof(PB_MSG_ ## id),				\
	    name ## _fields,					\
	    NULL						\
	    },
#define PB_MSGINFO_DELIMITER {0, NULL, 0, NULL, NULL}

#define PB_MSGID 1

#include "simple.pb.h"
#include "second.pb.h"


msginfo_t msgs[] = {
  SIMPLE_MESSAGES
  SECOND_MESSAGES
  PB_MSGINFO_DELIMITER
};

#if 0
// cpp expands this into:

msginfo_t msgs[] = {
    { 1234, "SimpleMessage", sizeof(SimpleMessage), SimpleMessage_fields, ((void *)0) },
    { 5678, "DuplicatedMessage", sizeof(DuplicatedMessage), DuplicatedMessage_fields, ((void *)0) },
    { 8192, "SecondMessage", sizeof(SecondMessage), SecondMessage_fields, ((void *)0) },
    { 4711, "ThirdMessage", sizeof(ThirdMessage), ThirdMessage_fields, ((void *)0) },
    { 0, ((void *)0), 0, ((void *)0), ((void *)0)}
};

#endif
