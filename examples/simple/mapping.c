#include <stdio.h>
#include <pb.h>

typedef struct {
    uint32_t msgid;
    int32_t encoded_size;
    const char *name;
    size_t size;
    const pb_field_t *fields;
    void *user;
} msginfo_t;

#define PB_MSG(id, size, name) {				\
	id,							\
	    size,						\
	    # name,						\
	    sizeof(PB_MSG_ ## id),				\
	    name ## _fields,					\
	    NULL,						\
	    },

#define PB_MSGINFO_DELIMITER {0, -1, NULL, 0, NULL, NULL}

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
    { 1234, 11, "SimpleMessage", sizeof(SimpleMessage), SimpleMessage_fields, ((void *)0), },
    { 5678, 11, "DuplicatedMessage", sizeof(DuplicatedMessage), DuplicatedMessage_fields, ((void *)0), },
    { 3456, 2, "SecondMessage", sizeof(SecondMessage), SecondMessage_fields, ((void *)0), },
    { 4711, 2, "ThirdMessage", sizeof(ThirdMessage), ThirdMessage_fields, ((void *)0), },
    {0, -1, ((void *)0), 0, ((void *)0), ((void *)0)}
};


#endif

