#include "CH58x_common.h"
#include "stdio.h"
#define LED_Pin GPIO_Pin_8

int main()
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);
    GPIOA_ModeCfg(LED_Pin, GPIO_ModeOut_PP_5mA);

    // for UART0 initialization
    GPIOB_SetBits(GPIO_Pin_7);
    GPIOB_ModeCfg(GPIO_Pin_4, GPIO_ModeIN_PU);      // RXD-配置上拉输入
    GPIOB_ModeCfg(GPIO_Pin_7, GPIO_ModeOut_PP_5mA); // TXD-配置推挽输出，注意先让IO口输出高电平
    UART0_DefInit();

    while (1)
    {
        printf("Hello World!\n");
        GPIOA_SetBits(LED_Pin);
        DelayMs(1000);
        GPIOA_ResetBits(LED_Pin);
        DelayMs(1000);
    }
}