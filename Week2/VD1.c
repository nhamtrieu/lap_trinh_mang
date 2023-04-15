#include<stdio.h>


int main(){
    char packet_bytes[] = {
        0x45, 0x00, 0x01, 0x8e, 0x9c, 0x2e, 0x40, 0x00,
        0x40, 0x06, 0x64, 0x98, 0x0a, 0x0d, 0x38, 0x6a,
        0x6b, 0x16, 0x8b, 0x16
    };
    //Version of headre
    char value = packet_bytes[0];
    int version = value>>4;
    printf("Version: %d\n",version);
    //IHL
    value = packet_bytes[0];
    int IHL = (value&15)*4;
    printf("Internet header lenght: %d\n",IHL);
    //Total length
    int total_length = packet_bytes[2]<<8;
    total_length = total_length|((int)packet_bytes[3]);
    printf("Total length: %d\n",total_length);
    //IP Source
    printf("IP Source: %u.%u.%u.%u\n",(unsigned char)packet_bytes[12],(unsigned char)packet_bytes[13],(unsigned char)packet_bytes[14],(unsigned char)packet_bytes[15]);
    printf("IP Destination: %u.%u.%u.%u\n",(unsigned char)packet_bytes[16],(unsigned char)packet_bytes[17],(unsigned char)packet_bytes[18],(unsigned char)packet_bytes[19]);

}