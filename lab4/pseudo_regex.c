#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool match(char* pattern, char* sequence){
    if(strlen(pattern)==0 && strlen(sequence) == 0)
        return true;
        
    if(strlen(pattern)==0)
        return false;

    if(strlen(sequence) == 0){
        if(pattern[0] == '*')
            return match(pattern + 1, sequence);
        return false;
    }

    // sequence i pattern są niepuste
    if(pattern[0] == '*')
        return match(pattern + 1, sequence + 1) || 
               match(pattern, sequence + 1);

    if(pattern[0] == sequence[0] || pattern[0] == '?')
        return match(pattern + 1, sequence + 1);

    return false;
}

void tests(){
    assert(match("", ""));
    assert(!match("", "a"));
    assert(!match("a", ""));
    assert(match("a", "a"));
    assert(!match("a", "b"));
    assert(match("ab", "ab"));
    assert(!match("ab", "aa"));
    assert(!match("amla", "aml"));
    assert(match("halo%^&", "halo%^&"));
    assert(match("123", "123"));
    assert(match("?", "a"));
    assert(match("??", "ab"));
    assert(match("a?a", "ala"));
    assert(!match("a?b", "ama"));
    assert(match("*", ""));
    assert(match("*", "aa"));
    assert(match("*", "ala ma kota"));
    assert(match("al*", "ala ma kota"));
    assert(match("*ota", "ala ma kota"));
    assert(!match("*a", "k"));
    assert(match("a*b*a", "abababababababababababa"));
    assert(!match("a*b*a","ababababababababababab"));
}

int main(){
    tests();
    printf("Testy zakończone pomyślnie\nPodaj swoje zapytanie\n");
    while(true){
        const int buf_len = 1000;
        char pattern[buf_len];
        char sequence[buf_len];
        
        printf("Wzorzec: ");
        fgets(pattern, buf_len, stdin);
        printf("Ciąg: ");
        fgets(sequence, buf_len, stdin);

        if(match(pattern, sequence))
            printf("Zgodny\n");
        else
            printf("Nie zgodny\n");
    }    
}
