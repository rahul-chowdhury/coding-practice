#include <stdio.h>
char *program = "#include <stdio.h>%cchar *program = %c%s%c;%cint main()%c{%cprintf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);%c    return 0;%c}%c";
//what is this line doing, what is the use of %c and %s and what properties of %c and %s are being used here?
int main()
{
        printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10, 10);
        //what is this print function doing, and how?
        return 0;
}
