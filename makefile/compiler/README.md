컴파일러의 단계 

```
//STEP 1. 전처리 단계 [*.c -> *.i]
gcc -E main.c -o main.i
gcc -E func.c -o func.o


//STEP 2. 컴파일 단계 [*.c -> (*.i) -> *.s]
gss -S main.c func.c

//STEP 3. 어셈블 단계 [*.c -> (*.i) -> (*.s) -> *.o ]
gcc -c main.c func.c

//STEP4. 링크 단계 [*.c -> (*.i) -> (*.s) -> (*.o) -> executable ]
gcc -o main main.c func.c

```
