#include <stdio.h>
char s[]="#include <stdio.h>\nchar s[]=\"%s\";\nint main(){printf(s,s);return 0;}";
int main(){printf(s,s);return 0;}