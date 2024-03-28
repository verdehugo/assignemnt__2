#include <stdio.h>
#include <string.h>
#include "../header/cmdproc.h"
#include "cmdproc.c"
#include <assert.h>






int main() {



// Simulate receiving a command and processing it
 /* ************************************************************ */
/* Processes the chars in the RX buffer looking for commands 	*/
/* Returns:                                                     */
/*  	 0: if a valid command was found and executed           */
/* 		-1: if empty string or incomplete command found         */
/* 		-2: if an invalid command was found                     */
/* 		-3: if a CS error is detected (command not executed)    */
/* 		-4: if string format is wrong                           */
/* ************************************************************ */
//int cmdProcessor(void);

//0: if a valid command was found and executed  

UARTRxBuffer[0] = '#';
UARTRxBuffer[1] = 'A';

unsigned char list_valid_commands[4]={'A','P','L','R'};


UARTRxBuffer[2] = '3';
UARTRxBuffer[3] = '4';
UARTRxBuffer[4] = '5';
UARTRxBuffer[5] = '6';
UARTRxBuffer[6] = '!';

assert(cmdProcessor()==0);


//-1: if empty string or incomplete command found 

UARTRxBuffer[0] = '#';
UARTRxBuffer[1] = 'A';  
UARTRxBuffer[2] = '3';
UARTRxBuffer[3] = '4';
UARTRxBuffer[4] = '5';
UARTRxBuffer[5] = '6';
UARTRxBuffer[6] = '!';

assert(cmdProcessor()==-1);

//-2: if an invalid command was found 

UARTRxBuffer[0] = '#';
UARTRxBuffer[1] = 'A';  //invalid command
UARTRxBuffer[2] = '3';
UARTRxBuffer[3] = '4';
UARTRxBuffer[4] = '5';
UARTRxBuffer[5] = '6';
UARTRxBuffer[6] = '!';

assert(cmdProcessor()==-2);

//-3: if a CS error is detected (command not executed)

UARTRxBuffer[0] = '#';
UARTRxBuffer[1] = 'A';  
UARTRxBuffer[2] = '3';
UARTRxBuffer[3] = '4';
UARTRxBuffer[4] = '5';
UARTRxBuffer[5] = '6';
UARTRxBuffer[6] = '!';

assert(cmdProcessor()==-3);

//-4: if string format is wrong 

UARTRxBuffer[0] = '#';
UARTRxBuffer[1] = 'A';  
UARTRxBuffer[2] = '3';
UARTRxBuffer[3] = '4';
UARTRxBuffer[4] = '5';
UARTRxBuffer[5] = '6';
UARTRxBuffer[6] = '!';

assert(cmdProcessor()==-4);


//////////////////////////////////////////////////////////////////////////////////////////////


/* ******************************** */
/* Adds a char to the RX buffer 	*/
/* I.e., the reception of commands 	*/
/* Returns: 				        */
/*  	 0: if success 		        */
/* 		-1: if buffer full	 	    */
/* ******************************** */


assert(rxChar('A')==0);

for (int j = 7; j < UART_RX_SIZE-1; ++j) {
    UARTRxBuffer[j] = 'X'; 
}
assert(rxChar('A')==-1);


/////////////////////////////////////////////////////////////////////////////////7

/* ************************************ */
/* Adds a char to the TX buffer 		*/
/* I.e., the tranmsisison of answers 	*/
/* Returns: 				        	*/
/*  	 0: if success 		        	*/
/* 		-1: if buffer full	 	    	*/
/* ************************************ */
int txChar(unsigned char car);

assert(txChar('A')==0);

for (int j = 0; j < UART_RX_SIZE-1; ++j) {
    UARTTxBuffer[j] = 'X'; 
}

assert(txChar('A')==-1);
   



    

    

    return 0;
}
