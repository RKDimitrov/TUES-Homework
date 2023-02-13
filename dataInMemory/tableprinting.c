#include <stdio.h>
#include <limits.h>

#define TABLEROW(NAME,FORMAT,MAXSIGNED, MINSIGNED, TYPEUNSIGNED, MAXUNSIGNED) printf("%-15s%-15s%-15d%-15d%-15s%-15d\n", NAME,FORMAT,MAXSIGNED, MINSIGNED, TYPEUNSIGNED, MAXUNSIGNED); 

int main(){
    printf("%-15s%-15s%-15s%-15s%-15s%-15s\n\n", "Name", "Format", "Maxsigned", "Minsigned", "FormatUnsigned", "Maxunsigned");
    TABLEROW("char", "%s", CHAR_MAX, CHAR_MIN, "%uc", UCHAR_MAX);
    TABLEROW("int", "%d", INT_MAX, INT_MIN, "%u", UINT_MAX);
    TABLEROW("short", "%sd", SHRT_MAX, SHRT_MIN, "%su", USHRT_MAX);
    TABLEROW("long", "%ld", LONG_MAX, LONG_MIN, "%lu", ULONG_MAX);
    TABLEROW("long long", "%lld", LLONG_MAX, LLONG_MIN, "%llu", ULLONG_MAX);
}