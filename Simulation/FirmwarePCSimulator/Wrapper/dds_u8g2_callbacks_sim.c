#include "dds_u8g2_callbacks.h"

#include <stdio.h>

uint8_t u8x8_gpio_and_delay_template(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    return 0;
}

uint8_t u8x8_byte_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    switch(msg)
    {
        case U8X8_MSG_BYTE_SEND:
        {
            //printf("U8X8_MSG_BYTE_SEND\n");
#if 0
            uint8_t * data = (uint8_t *)arg_ptr;
            while( arg_int > 0 )
            {
                printf("%X ", *data);
                data++;
                arg_int--;
            }
#endif
        } break;

        case U8X8_MSG_BYTE_INIT:
        {
            //printf("U8X8_MSG_BYTE_INIT\n");
        } break;

        case U8X8_MSG_BYTE_START_TRANSFER:
        {
            //printf("U8X8_MSG_BYTE_START_TRANSFER\n");
        } break;

        case U8X8_MSG_BYTE_END_TRANSFER:
        {
            //printf("U8X8_MSG_BYTE_END_TRANSFER\n");
        } break;

        default:
        {
            return 0;
        }
    }

    return 1;
}
