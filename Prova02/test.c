#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

#define var(x) &(x)
#define val(x) (*(x))

int str_len (char *s2){
    char *sa = s2;
    while (*sa != '\0')
    {
        sa++;
    }
    return (sa - s2);
}

char * str_cat (char *s1, char *s2){
    char *sa = s1;
    char *sb = s2;
    char *sc = sa;
    while (*sa != '\0') sa++;
    while (*sb != '\0') {*sa = *sb; sa++; sb++;}
    *sa = '\0';
    return ( sc );
}

//incompleto
char * str_dup (char *s2){
    char *sa = malloc(80);
    char *sb = s2;
    char *sc = sa;
    while (*sb != '\0') {*sa = *sb; sa = sa + 1; sb = sb + 1;}
    *sa = '\0';
    return ( sa-str_len(s2) );
}

int str_cmp ( char *s1, char *s2){
    char *sa = s1;
    char *sb = s2;
    while (*sa == *sb && *sa != '\0' && *sb != '\0')
    {
        sa++;
        sb++;
    }
    return(*sa - *sb);
}

int main (void) {
    int *x = malloc(4); // malloc (1 * sizeof (int));
    int *y = malloc(20); // malloc (1 * sizeof (int));
    char *s = malloc(80);
    char *s0 = NULL;

//  for (val(x) = 0; val(x) < 5; val(x)++)
//  {
//      printf("%d ", val(x));
//  }
    for ( val(x) = 0; val(x) < 5; val(x)++){
//      val(y+val(x)) = val(x);
//      val(y+k) = k;
        y[val(x)] = val(x);
    }
    for ( val(x) = 0; val(x) < 5; val(x)++){
//      printf("%d ", val(y+val(x)));
//      printf("%d ", val(y+k))
        printf ("%d", y[val(x)]);
    }

    free(x);
    free(y);

    printf("\n");
    scanf("%s", s);
/*     printf("%s\n", s);
    for (k = 0; k < str_len(s); k++)
    {
        printf("\n%c", s[k]);
    } */
/*     k=0;
    while (s[k] != '\0')
    {
        printf ("\n%c", s[k]);
    } */

//  k=0;
    s0 = s;
    while (val(s) != '\0')
    {
        printf ("\n%c", val(s));
        s++;
    }
    printf("\n");
    printf("str_len=%d\n", (s-s0));
    
    s0 = str_dup("123");
    printf("\nstr_len(%s)=%d\n", s0, str_len(s0));
    printf("\n[%s]+[%s] = [%s]\n", s, s0, str_cat(s, s0));


    printf("\n[%s]==[%s] = [%s]\n", s, s0, str_cmp(s, s0));
    printf("\n[%s]==[%s] = [%s]\n", s, s0, str_cmp(s0, s));
    s0 = str_dup(s);
    printf("\n[%s]==[%s] = [%s]\n", s, s0, str_cmp(s, s0));


    printf("\n");
    return 0;
}