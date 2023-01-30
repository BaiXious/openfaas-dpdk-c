FROM openfaas/classic-watchdog:0.18.0 as watchdog

FROM lucasfsduarte/alpine-build-base

FROM ic3b34r/dpdk-ovs:20.11.5

# Allows you to add additional packages via build-arg
ARG ADDITIONAL_PACKAGE
# ARG PKGCONF=pkg-config --define-prefix
# CFLAGS += -O -gdwarf-2 $(shell $(PKGCONF) --cflags libdpdk)
# LIBS+= $(shell $(PKGCONF) --static --libs libdpdk) -Wl,--no-whole-archive -lrt -lm -ldl -lcrypto -pthread -lnuma

COPY --from=watchdog /fwatchdog /usr/bin/fwatchdog
RUN chmod +x /usr/bin/fwatchdog

WORKDIR /app/

COPY function/recv.h     .
COPY function/recv.c     .
COPY handler.c           .

RUN gcc ${CFLAGS} recv.h handler.c recv.c -static -o /handler ${LIBS} \
    && chmod +x /handler

ENV fprocess="/handler"

HEALTHCHECK --interval=3s CMD [ -e /tmp/.lock ] || exit 1

CMD ["fwatchdog"]
