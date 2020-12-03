#ifndef __SWAP__
#define __SWAP__

#include <stdlib.h>

// [swap]
// 두 변수의 값을 서로 변경해주는 함수
// @param (char *str) -> 첫번쨰 문자열
// @param (char *str) -> 두번째 문자열
void swap(char *str1, char *str2) {
    char* tmp;
    tmp = (char *)malloc(sizeof(char)*100);
    tmp = str1;
    str1 = str2;
    str2 = tmp;
}

#endif
