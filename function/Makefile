# SPDX-License-Identifier: BSD-3-Clause
# Copyright(c) 2010-2014 Intel Corporation

# ifeq ($(FF_PATH),)
# 	FF_PATH=/opt/f-stack
# endif

# Build using pkg-config variables if possible
ifeq ($(shell pkg-config --exists libdpdk && echo 0),0)

PKGCONF=pkg-config --define-prefix

# PC_FILE := $(shell $(PKGCONF) --path libdpdk)
# CFLAGS += -O3 $(shell $(PKGCONF) --cflags libdpdk)
# CFLAGS += -DALLOW_EXPERIMENTAL_API
CFLAGS += -O -gdwarf-2 $(shell $(PKGCONF) --cflags libdpdk)

# LDLIBS_FSTACK += -L${FF_PATH}/lib -Wl,--whole-archive,-lfstack,--no-whole-archive \
#                  -L${FF_DPDK}/lib -Wl,--whole-archive,-ldpdk,--no-whole-archive \
#                  -Wl,--no-whole-archive -lrt -lm -ldl -lcrypto -pthread -lnuma
LIBS+= $(shell $(PKGCONF) --static --libs libdpdk)
#LIBS+= -L${FF_PATH}/lib -Wl,--whole-archive,-lfstack,--no-whole-archive
LIBS+= -Wl,--no-whole-archive -lrt -lm -ldl -lcrypto -pthread -lnuma

TARGET="helloworld"

all:
#	cc ${CFLAGS} -o ${TARGET} main.c ${LIBS}
#	cc ${CFLAGS} -o ${TARGET}_epoll main_epoll.c ${LIBS}
#	cc ${CFLAGS} -o ${TARGET}_client client-main.c ${LIBS}
#	g++ fstack_server.cpp  $(CPPFLAGS_FSTACK) -o fstack_server $(LIBS)
#	g++ fstack_client.cpp  $(CPPFLAGS_FSTACK) -o fstack_client $(LIBS)
#	cc ${CFLAGS} send.c -o dpdk_send ${LIBS}
#	cc ${CFLAGS} recv.c -o dpdk_recv ${LIBS}
	gcc ${CFLAGS} handler.c recv.h recv.c -o handler ${LIBS}
# gcc send.c -fPIC -shared -mssse3 -o libsendtest.so ${LIBS}
# gcc recv.c -fPIC -shared -mssse3 -o librecvtest.so ${LIBS}
.PHONY: clean

# clean:
# 	rm -f *.o ${TARGET} ${TARGET}_epoll
# 	rm -f *.o 
endif
