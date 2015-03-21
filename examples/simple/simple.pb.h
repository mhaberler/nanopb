/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.3-dev at Sat Mar 21 22:10:22 2015. */

#ifndef PB_SIMPLE_PB_H_INCLUDED
#define PB_SIMPLE_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
/* Struct definitions */
typedef struct _DuplicatedMessage {
    int32_t serial;
} DuplicatedMessage;

typedef struct _SimpleMessage {
    int32_t lucky_number;
} SimpleMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define SimpleMessage_init_default               {0}
#define DuplicatedMessage_init_default           {0}
#define SimpleMessage_init_zero                  {0}
#define DuplicatedMessage_init_zero              {0}

/* Field tags (for use in manual encoding/decoding) */
#define DuplicatedMessage_serial_tag             1
#define SimpleMessage_lucky_number_tag           1

/* Struct field encoding specification for nanopb */
extern const pb_field_t SimpleMessage_fields[2];
extern const pb_field_t DuplicatedMessage_fields[2];

/* Maximum encoded size of messages (where known) */
#define SimpleMessage_size                       11
#define DuplicatedMessage_size                   11

#ifdef PB_MSGID
#define PB_MSG_1234 SimpleMessage
#define PB_MSG_5678 DuplicatedMessage

#define SIMPLE_MESSAGES PB_MSG(1234) PB_MSG(5678)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
