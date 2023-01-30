/*
# File:
#     handler.c
#
# Author:
#     Yang Yi
#
# Description:
#     Handler that communicates with watchdog
#
*/

//#include "header.h"

//#define INPUT_MAX_SIZE 15

// int main() {

//     char *input;
//     int actLen, maxLen;

// 	// Allocating memory to data array;
//     maxLen = INPUT_MAX_SIZE + 2;
//     input = malloc(maxLen * sizeof(char));

// 	// Getting data from standard input;
//     fgets(input, maxLen, stdin);
//     actLen = strlen(input);

// 	// Removing '\n' from the end;
//     if (input[actLen - 1] == '\n') {
//         input[actLen - 1] = '\0';
//         actLen = strlen(input);
//     }

// 	// Forwarding received data;
// 	//manager(input);
//     return 0;
// }
#include "recv.h"
//static uint64_t packet_count = 0;
//tatic time_t t1;


int main(int argc, char **argv)
{
	uint64_t MaxpktNum = 0;
	scanf("%lu", &MaxpktNum);
	data_rx_init(argc, argv);
	ReceivePacket(MaxpktNum);
	return(0);
}