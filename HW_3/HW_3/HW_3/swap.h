#ifndef __SWAP__
#define __SWAP__

// [swap]
// 두 변수의 값을 서로 변경해주는 함수
// @param (int *n1) -> 첫번쨰 정수
// @param (int *n2) -> 두번째 정수
void swap(int *n1, int *n2) {
    int tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

#endif
