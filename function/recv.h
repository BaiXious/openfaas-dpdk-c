#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <signal.h>
#include <rte_eal.h>
#include <rte_ethdev.h>
#include <rte_cycles.h>
#include <rte_lcore.h>
#include <rte_mbuf.h>

void DumpHex(const void*, size_t);
void rx_packets(void);
void exit_stats(int);
void data_rx_init(int argc, char *argv[]);
void ReceivePacket(uint64_t MaxpktNum);