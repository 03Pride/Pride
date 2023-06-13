/*
 * @Author: Pride03 1955858379@qq.com
 * @Date: 2022-12-05 16:07:35
 * @LastEditors: Pride03 1955858379@qq.com
 * @LastEditTime: 2023-05-18 11:17:25
 * @FilePath: \移位\移位.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdint.h>
#include <stdio.h>

uint8_t buff[3];
int main(){
    uint16_t number,number1;
    float number2;
    buff[0] = 0x01;//0000 0001
    buff[1] = 0xFF;//1111 1111
    buff[2] = 0x28;//0010 1000

    //buff[0]的8位作为number的低八位，buff[1]的高8位为number的高八位
    //对0x7FF(0111 1111 1111)取与运算只拿走16位数据的后11位
    number = (buff[0]|buff[1]<<8)&0x07FF;
    //取出buff[1]的前5位和buff[2]的后6位
    number1 = (buff[1]>>3|buff[2]<<5)&0x07FF;

    uint16_t mask = 1u<<15;

    for(;mask;mask>>=1){
        printf("%d",number&mask?1:0);//00000 11100000001
        if(mask==0x0100)
         printf(" ");
    }
    printf("\n");
    
    mask = 1u<<15;

    for(;mask;mask>>=1){
        printf("%d",number1&mask?1:0);//00000 00100011111
        if(mask==0x0100)
         printf(" ");
    }
    printf("\n");
    
    return 0;
}
