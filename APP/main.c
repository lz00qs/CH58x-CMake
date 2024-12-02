#include "CH58x_common.h"
#define LED_Pin GPIO_Pin_15

int main()
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);
    GPIOB_ModeCfg(LED_Pin, GPIO_ModeOut_PP_5mA);

    // for UART1 init
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD-配置上拉输入
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD-配置推挽输出，注意先让IO口输出高电平
    UART1_DefInit();

    while (1)
    {
        printf("Hello World!\n");
        GPIOB_SetBits(LED_Pin);
        DelayMs(1000);
        GPIOB_ResetBits(LED_Pin);
        DelayMs(1000);
    }
}