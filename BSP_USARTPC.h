#ifndef __BSP_USARTPC_H
#define __BSP_USARTPC_H
/* Includes ------------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define USARTPC_USARTx					USART1
#define USARTPC_CLK							RCC_APB2Periph_USART1
/* Rx */
#define USARTPC_RX_GPIO_CLK			RCC_AHB1Periph_GPIOA
#define USARTPC_RX_GPIO_PORT		GPIOA
#define USARTPC_RX_PIN					GPIO_Pin_9

#define USARTPC_RX_AFPIN				GPIO_PinSource9
#define USARTPC_RX_AF						GPIO_AF_USART1
/* Tx */
#define USARTPC_TX_GPIO_CLK			RCC_AHB1Periph_GPIOA
#define USARTPC_TX_GPIO_PORT		GPIOA
#define USARTPC_TX_PIN					GPIO_Pin_10

#define USARTPC_TX_AFPIN				GPIO_PinSource10
#define USARTPC_TX_AF						GPIO_AF_USART1
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void BSP_USARTPC_Initialization(void);
#endif
