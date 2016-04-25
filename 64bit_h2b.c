#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DEBUG

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
//

void char2bits(char c, int *nibble_bits)
{
    switch(c) {
    case '0': nibble_bits[0] = 0; nibble_bits[1] = 0; nibble_bits[2] = 0; nibble_bits[3] = 0; break;
    case '1': nibble_bits[0] = 0; nibble_bits[1] = 0; nibble_bits[2] = 0; nibble_bits[3] = 1; break;
    case '2': nibble_bits[0] = 0; nibble_bits[1] = 0; nibble_bits[2] = 1; nibble_bits[3] = 0; break;
    case '3': nibble_bits[0] = 0; nibble_bits[1] = 0; nibble_bits[2] = 1; nibble_bits[3] = 1; break;
    case '4': nibble_bits[0] = 0; nibble_bits[1] = 1; nibble_bits[2] = 0; nibble_bits[3] = 0; break;
    case '5': nibble_bits[0] = 0; nibble_bits[1] = 1; nibble_bits[2] = 0; nibble_bits[3] = 1; break;
    case '6': nibble_bits[0] = 0; nibble_bits[1] = 1; nibble_bits[2] = 1; nibble_bits[3] = 0; break;
    case '7': nibble_bits[0] = 0; nibble_bits[1] = 1; nibble_bits[2] = 1; nibble_bits[3] = 1; break;
    case '8': nibble_bits[0] = 1; nibble_bits[1] = 0; nibble_bits[2] = 0; nibble_bits[3] = 0; break;
    case '9': nibble_bits[0] = 1; nibble_bits[1] = 0; nibble_bits[2] = 0; nibble_bits[3] = 1; break;
    case 'a':
    case 'A': nibble_bits[0] = 1; nibble_bits[1] = 0; nibble_bits[2] = 1; nibble_bits[3] = 0; break;
    case 'b':
    case 'B': nibble_bits[0] = 1; nibble_bits[1] = 0; nibble_bits[2] = 1; nibble_bits[3] = 1; break;
    case 'c':
    case 'C': nibble_bits[0] = 1; nibble_bits[1] = 1; nibble_bits[2] = 0; nibble_bits[3] = 0; break;
    case 'd':
    case 'D': nibble_bits[0] = 1; nibble_bits[1] = 1; nibble_bits[2] = 0; nibble_bits[3] = 1; break;
    case 'e':
    case 'E': nibble_bits[0] = 1; nibble_bits[1] = 1; nibble_bits[2] = 1; nibble_bits[3] = 0; break;
    case 'f':
    case 'F': nibble_bits[0] = 1; nibble_bits[1] = 1; nibble_bits[2] = 1; nibble_bits[3] = 1; break;
    default: 
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

#define NUM_BITS_IN_DW 64

void print_string_as_binary(char* hexstr, int start_bit, int end_bit)
{
    int  b,i ;
    char* s;
    int  nibble_bits[4];
    int  hex_bits[NUM_BITS_IN_DW];
    char hex_digits[NUM_NIBBLE_IN_DW];

    for(i = 0; i < NUM_NIBBLE_IN_DW; i++) {
        hex_digits[i] = ' ';
    }

    b = NUM_BITS_IN_DW;
    i = NUM_NIBBLE_IN_DW;
    s = hexstr + strlen(hexstr);

    while ((s != hexstr) && (i >= 0)) {
        s--;
        i--;
        hex_digits[i] = *s;


        nibble_bits[0] = 0; 
        nibble_bits[1] = 0; 
        nibble_bits[2] = 0; 
        nibble_bits[3] = 0;
        char2bits(*s, nibble_bits);
        hex_bits[--b] = nibble_bits[3];
        hex_bits[--b] = nibble_bits[2];
        hex_bits[--b] = nibble_bits[1];
        hex_bits[--b] = nibble_bits[0];

    }

    PRINT("\n\n\n");

    /*
     * Format 1 
     */
    format1_line_type0();
    format1_line_type1();

    for (b = 0; b < NUM_BITS_IN_DW; b++)
    {
        if (b == start_bit) {
            PRINT("<mark><font color=\"red\">");
        }
        PRINT("%d", hex_bits[b]);
        if (b == end_bit) {
            PRINT("</font></mark>");
        }
    }

    PRINT("\n\n\n");
    /*
     * Format 2 
     */
    format2_line_type1(hex_digits);
    format2_line_type2();

    for (b = 0; b < NUM_BITS_IN_DW; b++)
    {
        if (b == start_bit) {
            PRINT("<mark><font color=\"red\">");
        }
        PRINT("%d", hex_bits[b]);
        if (b == end_bit) {
            PRINT("</font></mark>");
        }
        if (((b+1) % 4) == 0) {
            PRINT(" ");
        }
    }



    PRINT("(nibble value in binary)\n");
    format2_line_type3();

    PRINT("\n\n\n");

    /*
     * Format 3 
     */
    format3_line_type1();
    format3_line_type2();
    format3_line_type3();
    format3_line_type4();

    for (b = 0; b < NUM_BITS_IN_DW; b++)
    {
        if (b == start_bit) {
            PRINT(" <mark><font color=\"red\">%d", hex_bits[b]);
        } else {
            PRINT(" %d", hex_bits[b]);
        }

        if (b == end_bit) {
            PRINT("</font></mark>");
        }
    }


    PRINT("\n");

    format3_line_type4();
    format3_line_type3();
    format3_line_type2();
    format3_line_type1();

}


#ifdef CGI
int main(void)
#else /* !CGI */
main (int argc, char** argv)
#endif /* !CGI */
{
    int i;
    char *query_str = NULL;
    char *query_str_ptr = NULL;
#define HEX_64_BIT_STR_LEN    16
#define QUERY_STR_MAX_LEN     100
    char query_str_emended[QUERY_STR_MAX_LEN];

    char input_hex_str[QUERY_STR_MAX_LEN];
    char hex_str[20];
    char *nh_hex_str = NULL;
    long long int _64hex = 0;
    int start_bit = 0;
    int end_bit = 0;
    int num_vars;
    int input_hex_str_len;


#ifdef CGI
    PRINT("%s%c%c\n",
    "Content-Type:text/html;charset=iso-8859-1",13,10);

    PRINT("<TITLE>Decoded NH </TITLE>\n");

    query_str = getenv("QUERY_STRING");

    if(query_str == NULL) {
          PRINT("<P>Error! Error in passing query string (%p) to script.", query_str);
          return -1;
    }

#ifdef DEBUG
    PRINT("<P>query_str: %s\n", query_str);
#endif // DEBUG

    //hex_str=08d0957000020000&start_bit=0&end_bit=63
    //^^^^^^^^

    query_str += 8;

    if ((query_str[0] == '0') && (query_str[1] == 'x' || query_str[1] == 'X')) {
         query_str += 2;
    }


    i = 0;

    input_hex_str_len = 0;
    query_str_ptr = query_str;
    while(*query_str_ptr != '&') {
        input_hex_str_len++;
        query_str_ptr++;
        input_hex_str[i++] = *query_str_ptr;

    }
    input_hex_str[--i] = '\0';

#ifdef DEBUG
    PRINT("<P>input_hex_str_len: %d \n", input_hex_str_len);
#endif // DEBUG

    if (input_hex_str_len > HEX_64_BIT_STR_LEN) {
          PRINT("<P>Error! Input hex (0x%s) longer than 64 bit", input_hex_str);
          return -1;
    }
   
    if (input_hex_str[strspn(input_hex_str, "0123456789abcdefABCDEF")] != 0) {
        PRINT("<P>Error! Invalide input hex (0x%s)", input_hex_str);
        return -1;
    }
   
    /*
     * input_hex_str_len <= HEX_64_BIT_STR_LEN
     */

    query_str_emended[0] = '\0';

    for (i = 0; i < (16 - input_hex_str_len) ; i++) {
        strncat(query_str_emended, "0", (QUERY_STR_MAX_LEN - strlen(query_str_emended) - 1));
    }
    strncat(query_str_emended, query_str, (QUERY_STR_MAX_LEN - strlen(query_str_emended) -1)); 

    num_vars = sscanf(query_str_emended, "%16s&start_bit=%d&end_bit=%d", hex_str, &start_bit, &end_bit);

#ifdef DEBUG
    PRINT("<P>query_str_emended: %s hex_str:%s start_bit: %d end_bit: %d\n", 
            query_str_emended, hex_str, start_bit, end_bit); 
#endif // DEBUG

    if (num_vars != 3) {
          PRINT("<P>Error! 2Invalid query string (%s) to script.", query_str);
          return -1;
    }

    nh_hex_str = &hex_str[0];

    if((start_bit < 0) || (start_bit > 63)) {
        PRINT("<P>Error: Invalid start bit (%d)\n", start_bit);
        return -1;
    }

    if((end_bit < 0) || (end_bit > 63)) {
        PRINT("<P>Error: Invalid end bit (%d)\n", end_bit);
        return -1;
    }

    if(end_bit < start_bit) {
        PRINT("<P>Error: End bit (%d) smaller that start bit (%d)\n", end_bit, start_bit);
        return -1;
    }

    if (strlen(nh_hex_str) != HEX_64_BIT_STR_LEN) {
        PRINT("<P>Invalid 74 bit hex string (%s)\n", nh_hex_str);
        return -1;
    }

 
#else /* !CGI */
    //PRINT("argc: %d argv[0]: %s argv[1]: %s\n", argc, argv[0], argv[1]);
    if(argc != 2) {
       PRINT("Please provide hex string\n");
       return;
    }

    nh_hex_str = argv[1];
#endif /* !CGI */


    PRINT_CGI("<pre>");
    //PRINT("Binary: \n"); 
    print_string_as_binary(nh_hex_str, start_bit, end_bit);
    PRINT_CGI("</pre>");

    return 0;
}

