#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NIBBLE_STR_SIZE             5
#define FORMAT3_NIBBLE_STR_SIZE     8
#define NUM_NIBBLE_IN_DW           16

#define CGI

#ifdef CGI
#define PRINT_CGI printf
#else /* CGI */
#define PRINT_CGI 
#endif /* CGI */

#define PRINT printf
//#define PRINT(format, args...) \
//        printf("<BR>"format, ##args)

void char2nibble(char c, char *nibble)
{
    switch(c) {
    case '0': snprintf(nibble, NIBBLE_STR_SIZE, "0000"); break;
    case '1': snprintf(nibble, NIBBLE_STR_SIZE, "0001"); break;
    case '2': snprintf(nibble, NIBBLE_STR_SIZE, "0010"); break;
    case '3': snprintf(nibble, NIBBLE_STR_SIZE, "0011"); break;
    case '4': snprintf(nibble, NIBBLE_STR_SIZE, "0100"); break;
    case '5': snprintf(nibble, NIBBLE_STR_SIZE, "0101"); break;
    case '6': snprintf(nibble, NIBBLE_STR_SIZE, "0110"); break;
    case '7': snprintf(nibble, NIBBLE_STR_SIZE, "0111"); break;
    case '8': snprintf(nibble, NIBBLE_STR_SIZE, "1000"); break;
    case '9': snprintf(nibble, NIBBLE_STR_SIZE, "1001"); break;
    case 'a':
    case 'A': snprintf(nibble, NIBBLE_STR_SIZE, "1010"); break;
    case 'b':
    case 'B': snprintf(nibble, NIBBLE_STR_SIZE, "1011"); break;
    case 'c':
    case 'C': snprintf(nibble, NIBBLE_STR_SIZE, "1100"); break;
    case 'd':
    case 'D': snprintf(nibble, NIBBLE_STR_SIZE, "1101"); break;
    case 'e':
    case 'E': snprintf(nibble, NIBBLE_STR_SIZE, "1110"); break;
    case 'f':
    case 'F': snprintf(nibble, NIBBLE_STR_SIZE, "1111"); break;
    default:  snprintf(nibble, NIBBLE_STR_SIZE, "err-"); break;
              break;
    }
}

void format3_char2nibble(char c, char *nibble)
{
    switch(c) {
    case '0': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 0 0 0"); break;
    case '1': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 0 0 1"); break;
    case '2': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 0 1 0"); break;
    case '3': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 0 1 1"); break;
    case '4': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 1 0 0"); break;
    case '5': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 1 0 1"); break;
    case '6': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 1 1 0"); break;
    case '7': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "0 1 1 1"); break;
    case '8': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 0 0 0"); break;
    case '9': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 0 0 1"); break;
    case 'a':
    case 'A': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 0 1 0"); break;
    case 'b':
    case 'B': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 0 1 1"); break;
    case 'c':
    case 'C': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 1 0 0"); break;
    case 'd':
    case 'D': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 1 0 1"); break;
    case 'e':
    case 'E': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 1 1 0"); break;
    case 'f':
    case 'F': snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "1 1 1 1"); break;
    default:  snprintf(nibble, FORMAT3_NIBBLE_STR_SIZE, "-error-"); break;
              break;
    }

}

void format1_line_type0(void)
{
    int i;
    int b = 0;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("   ");
        if(((i+1) % 8) == 0) {
            PRINT(" ");
        } else if(((i+1) % 2) == 0) {
            //PRINT("");
        } else {
            b++;
            PRINT("b%d",b);
        }
    }
    PRINT("(byte number)\n");
}



void format1_line_type1(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("---");
        if(((i+1) % 8) == 0) {
            PRINT("#");
        } else if(((i+1) % 2) == 0) {
            PRINT("`");
        } else {
            PRINT(".");
        }
    }
    PRINT("\n");
}

void format2_line_type1(char *hex_digits)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT(" %c   ", hex_digits[i]);
    }
    PRINT("(nibble value in hex)\n");
}

void format2_line_type2(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("----");
        if((i+1) == NUM_NIBBLE_IN_DW) {
        } else if(((i+1) % 8) == 0) {
            PRINT("#");
        } else if(((i+1) % 2) == 0) {
            PRINT("+");
        } else {
            PRINT("-");
        }
    }
    PRINT("\n");
}

void format2_line_type3(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("---- ");
    }
    PRINT("\n");
}

void format3_line_type1(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        if((i+1) == NUM_NIBBLE_IN_DW) {
            PRINT("|");
        } else if((i % 8) == 0) {
            PRINT("|                                                               ");
        }
    }
    PRINT("\n");
}

void format3_line_type2(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        if((i+1) == NUM_NIBBLE_IN_DW) {
            PRINT("|");
        } else if((i % 2) == 0) {
            PRINT("|               ");
        }
    }
    PRINT("\n");
}

void format3_line_type3(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("|       ");
        if((i+1) == NUM_NIBBLE_IN_DW) {
            PRINT("|");
        }
    }
    PRINT("\n");
}

void format3_line_type4(void)
{
    int i;
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("+-+-+-+-");
        if((i+1) == NUM_NIBBLE_IN_DW) {
            PRINT("+");
        }
    }
    PRINT("\n");
}

void printstringasbinary(char* hexstr)
{
    int i;
    char* s;
    char hex_digits[NUM_NIBBLE_IN_DW];
    char nibble[NUM_NIBBLE_IN_DW][NIBBLE_STR_SIZE];
    char format3_nibble[NUM_NIBBLE_IN_DW][FORMAT3_NIBBLE_STR_SIZE];

    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        hex_digits[i] = ' ';
    }
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        snprintf(nibble[i], NIBBLE_STR_SIZE, "0000");
    }
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        snprintf(format3_nibble[i], FORMAT3_NIBBLE_STR_SIZE, "0 0 0 0");
    }

    i = NUM_NIBBLE_IN_DW;
    s = hexstr + strlen(hexstr);

    while ((s != hexstr) && (i >= 0)) {
        s--;
        i--;
        hex_digits[i] = *s;
        char2nibble(*s, nibble[i]);
        format3_char2nibble(*s, format3_nibble[i]);
    }

    PRINT("\n\n\n");
    PRINT("________ Format 1 _______\n\n");
    format1_line_type0();
    format1_line_type1();
    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("%s",nibble[i]);
    }
    PRINT("\n\n\n");
    PRINT("________ Format 2 _______\n\n");
    format2_line_type1(hex_digits);
    format2_line_type2();

    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT("%s ",nibble[i]);
    }
    PRINT("(nibble value in binary)\n");
    format2_line_type3();

    PRINT("\n\n\n");
    PRINT("________ Format 3 _______\n\n");

    format3_line_type1();
    format3_line_type2();
    format3_line_type3();
    format3_line_type4();

    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        PRINT(" %s", format3_nibble[i]);
    }
    PRINT("\n");

    format3_line_type4();
    format3_line_type3();
    format3_line_type2();
    format3_line_type1();

}


#ifdef CGI
int main(void)
#else /* CGI */
main (int argc, char** argv)
#endif /* CGI */
{
    char *nh_hex_str = NULL;

#ifdef CGI
    PRINT("%s%c%c\n",
    "Content-Type:text/html;charset=iso-8859-1",13,10);

    PRINT("<TITLE>Decoded NH </TITLE>\n");
    //PRINT("<H3>Results</H3>\n");

    nh_hex_str = getenv("QUERY_STRING");
#else /* CGI */
    //PRINT("argc: %d argv[0]: %s argv[1]: %s\n", argc, argv[0], argv[1]);
    if(argc != 2) {
       PRINT("Please provide hex string\n");
       return;
    }

    nh_hex_str = argv[1];
#endif /* CGI */

    if (nh_hex_str == NULL) {
        PRINT("<P>Error! Error in passing data to script.\n");
        return 1;
    }

#ifdef CGI
    if (strlen(nh_hex_str) < 3) {
        PRINT("<P>Invalid dword hex string. Its too small!\n");
        return 0;
    }
    nh_hex_str +=2;
#endif /* CGI */
    PRINT("<P>DWORD (hex): %s\n", nh_hex_str); 

    if (strlen(nh_hex_str) > 18) {
        PRINT("<P>Invalid dword hex string. Its too big!\n");
        return 0;
    }

    if ((nh_hex_str[0] == '0') && (nh_hex_str[1] == 'x' || nh_hex_str[1] == 'X')) {
        nh_hex_str +=2;
    }

    PRINT_CGI("<pre>");
    PRINT("Binary: \n"); 
    printstringasbinary(nh_hex_str);
    PRINT_CGI("</pre>");

    return 0;
}

