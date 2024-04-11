#include "stm32f10x.h"                  // Device header
#include "bsp_led.h"
#include "bsp_usart.h"
#include "stdio.h"
#include "string.h"
#include "global_variables.h"

static void Show_Message(void);



int main(void){
	



	USART_Config();
	LED_GPIO_Config();
	Show_Message();
	
	while(1){
		
		ucTemp = getchar();
		printf("LED编号 = %c\n",ucTemp);

		switch(ucTemp){
      case '1':
        LED_RED;
      break;
      case '2':
        LED_GREEN;
      break;
      case '3':
        LED_BLUE;
      break;
      case '4':
        LED_YELLOW;
      break;
      case '5':
        LED_PURPLE;
      break;
      case '6':
        LED_CYAN;
      break;
      case '7':
        LED_WHITE;
      break;
      case '8':
        LED_BLACK;
      break;
      default:
		  Show_Message();

        break;      
		}

	}
	


}

static void Show_Message(void)
{
	// 输出欢迎信息和串口通信参数
	printf("\r\n这是一个通过串口通信指令控制RGB彩灯的实验\n");
	printf("使用USART参数为：%d 8-N-1 \n", 115200);

	// 输出指令对照表
	printf("开发板接到指令后控制RGB彩灯颜色，指令对应如下：\n");
	printf("指令\t------\t彩灯颜色\n");

	// 列出具体指令与对应颜色
	printf("     1\t------\tRed \n");
	printf("     2\t------\tGreen \n");
	printf("     3\t------\tBlue \n");
	printf("     4\t------\tYellow \n");
	printf("     5\t------\tPurple \n");
	printf("     6\t------\tCyan \n");
	printf("     7\t------\tWhite \n");
	printf("     8\t------\tRGB OFF \n"); 
}
