# Include the nanopb provided Makefile rules
include ../../extra/nanopb.mk

all: 	simple expanded.c

# Compiler flags to enable all warnings & debug info
CFLAGS = -Wall -Werror -g -O0
CFLAGS += -I$(NANOPB_DIR)

# C source code files that are required
CSRC  = simple.c                   # The main program
CSRC += simple.pb.c                # The compiled protocol definition
CSRC += second.pb.c                # The compiled protocol definition
CSRC += mapping.c
CSRC += $(NANOPB_DIR)/pb_encode.c  # The nanopb encoder
CSRC += $(NANOPB_DIR)/pb_decode.c  # The nanopb decoder
CSRC += $(NANOPB_DIR)/pb_common.c  # The nanopb common parts

PROTOC_OPTS += -I$(NANOPB_DIR)/generator/proto/ -I.
# Build rule for the main program
simple: $(CSRC) simple.pb.h second.pb.h
	$(CC) $(CFLAGS) -osimple $(CSRC)

# Build rule for the protocol
simple.pb.c: simple.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. simple.proto

second.pb.c: second.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. second.proto

expanded.c: mapping.c simple.pb.h second.pb.h
	gcc -E -I../.. mapping.c >expanded.c


