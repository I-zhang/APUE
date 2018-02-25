/* Includes ----------------------------------------------------------*/
#include "BSP_USARTPC.h"
#include "stm32f4xx.h"
#include <stdio.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#ifdef __GNUC__
	/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
		 set to 'Yes') calls __io_putchar() */
	#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
	#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

void BSP_USARTPC_Initialization(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	RCC_AHB1PeriphClockCmd(USARTPC_RX_GPIO_CLK | USARTPC_TX_GPIO_CLK, ENABLE);

	RCC_APB2PeriphClockCmd(USARTPC_CLK, ENABLE);


	GPIO_PinAFConfig(USARTPC_TX_GPIO_PORT,USARTPC_TX_AFPIN, USARTPC_TX_AF);

	GPIO_PinAFConfig(USARTPC_RX_GPIO_PORT,USARTPC_RX_AFPIN, USARTPC_RX_AF);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_InitStructure.GPIO_Pin = USARTPC_RX_PIN;
	GPIO_Init(USARTPC_RX_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = USARTPC_TX_PIN;
	GPIO_Init(USARTPC_TX_GPIO_PORT, &GPIO_InitStructure);

	USART_OverSampling8Cmd(USARTPC_USARTx, ENABLE); 

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USARTPC_USARTx, &USART_InitStructure);
	
	/* Enable USART */
	USART_Cmd(USARTPC_USARTx, ENABLE);
	
	USART_ClearFlag(USARTPC_USARTx,USART_FLAG_TC);
}

PUTCHAR_PROTOTYPE
{
  USART_SendData(USARTPC_USARTx, (uint8_t) ch);

  while (USART_GetFlagStatus(USARTPC_USARTx, USART_FLAG_TC) == RESET)
  {}
  return ch;
		
}
