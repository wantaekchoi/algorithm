int isOdd(int x) {
    return (x&1);
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// winner become ceil(n/2)
int updateNumber(int n) {
    return ((n&1) == 1) ? ((n+1)>>1) : (n>>1);
}

int isMatch(int a, int b) {
    return (isOdd(a) && ((a+1) == b));
}

int updateRound(int n) {
    return n>>1;
}

int solution(int n, int a, int b) {
    int currentRound = 1;

    if (n==2) {
        return 1;
    }

    if (a > b) {
        swap(&a, &b);
    }

    while (!isMatch(a, b)) {
        a = updateNumber(a);
        b = updateNumber(b);
        n >>= 1;
        currentRound++;
    }

    return currentRound;
}