#include "foma.h"
#include <string>
#include <iostream>
using namespace std;

extern "C"{
extern void my_interfaceparse(char *my_string);
int promptmode = PROMPT_MAIN;
int apply_direction;
}
void compile(string str) {
    stack_init();
    g_defines = defined_networks_init();
    g_defines_f = defined_functions_init();
    my_interfaceparse(strdup(str.c_str()));
    if (find_defined(g_defines, "DateParser") != NULL) {
        puts("ok");
    }
    else {
        puts("error");
    }
}

int main() {
    string input = R""""(
define Number ["0"|1|2|3|4|5|6|7|8|9] ;
define Day [(1|2) Number | 3 "0" | 3 1];
define Year Number (Number) (Number) (Number); # Could use Number^<5

define WeekDay ["Monday"|"Tuesday"|"Wednesday"|"Thursday"|"Friday"|"Saturday"|"Sunday"];
define Month ["January"|"February"|"March"|"April"|"May"|"June"|"July"|"August"|"September"|"October"|"November"|"December"];
define RegDates [WeekDay | Month " " Day (", " Year)];

define DateParser [RegDates @-> "<DATE>" ... "</DATE>"];

regex DateParser;
)"""";
    compile(input);
}