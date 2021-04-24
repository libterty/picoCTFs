# Easy-as-GDB

## Category

- Reverse-Engineering

## Pre steps

- Load Soure file
- [Ghidra](https://ghidra-sre.org/)

## Solution

- Check the decompiled output using `Ghidra`, find the entry function first

### Main Function

```c
int main(undefined1 param_1)

{
  char *userInput;
  size_t encodedLen;
  int isFlag;

  userInput = (char *)calloc(0x200,1);
  printf("input the flag: ");
  fgets(userInput,0x200,stdin);
  encodedLen = strnlen(&ourEncodedFlag,0x200);
  userInput = encodedFlag(userInput,encodedLen);
  someAssignStrategy((int)userInput,encodedLen,1);
  isFlag = checkFlag(userInput,encodedLen);
  if (isFlag == 1) {
    puts("Correct!");
  }
  else {
    puts("Incorrect.");
  }
  return 0;
}
```

### someAssignStrategy Function

```c
void someAssignStrategy(int userInput,uint encodedLen,int index)

{
  uint local_c;
  int local_8;

  if (index < 1) {
    local_8 = encodedLen - 1;
    while (0 < local_8) {
      FUN_00010751(userInput,encodedLen,local_8);
      local_8 = local_8 + -1;
    }
  }
  else {
    local_c = 1;
    while (local_c < encodedLen) {
      FUN_00010751(userInput,encodedLen,local_c);
      local_c = local_c + 1;
    }
  }
  return;
}
```

### checkFlag Function

```c
undefined4 checkFlag(char *userInput,uint encodedLen)

{
  char *__dest;
  char *__dest_00;
  uint i;

  __dest = (char *)calloc(encodedLen + 1,1);
  strncpy(__dest,userInput,encodedLen);
  someAssignStrategy((int)__dest,encodedLen,-1);
  __dest_00 = (char *)calloc(encodedLen + 1,1);
  strncpy(__dest_00,&ourEncodedFlag,encodedLen);
  someAssignStrategy((int)__dest_00,encodedLen,-1);
  puts("checking solution...");
  i = 0;
  while( true ) {
    if (encodedLen <= i) {
      return 1;
    }
    if (__dest[i] != __dest_00[i]) break;
    i = i + 1;
  }
  return 0xffffffff;
}
```

### Our Flag Information

```assembly
                             ourEncodedFlag                                  XREF[4]:     checkFlag:00010931(*),
                                                                                          checkFlag:00010937(*),
                                                                                          main:00010a19(*),
                                                                                          main:00010a1f(*)
        00012008 7a              ??         7Ah    z
        00012009 2e              ??         2Eh    .
        0001200a 6e              ??         6Eh    n
        0001200b 68              ??         68h    h
        0001200c 1d              ??         1Dh
        0001200d 65              ??         65h    e
        0001200e 16              ??         16h
        0001200f 7c              ??         7Ch    |
        00012010 6d              ??         6Dh    m
        00012011 43              ??         43h    C
        00012012 6f              ??         6Fh    o
        00012013 36              ??         36h    6
        00012014 32              ??         32h    2
        00012015 62              ??         62h    b
        00012016 12              ??         12h
        00012017 16              ??         16h
        00012018 43              ??         43h    C
        00012019 34              ??         34h    4
        0001201a 40              ??         40h    @
        0001201b 3e              ??         3Eh    >
        0001201c 58              ??         58h    X
        0001201d 01              ??         01h
        0001201e 58              ??         58h    X
        0001201f 3f              ??         3Fh    ?
        00012020 62              ??         62h    b
        00012021 3f              ??         3Fh    ?
        00012022 53              ??         53h    S
        00012023 30              ??         30h    0
        00012024 6e              ??         6Eh    n
        00012025 17              ??         17h

```

- In order to pass flag comparison compares with character we input, we need to pass the following condition

```c
  while( true ) {
    if (encodedLen <= i) {
      return 1;
    }
    if (__dest[i] != __dest_00[i]) break;
    i = i + 1;
  }
  return 0xffffffff;
```

- The following function in assembly

```assembly
                             LAB_00010978                                    XREF[1]:     000109a5(j)  
        00010978 8b 55 f0        MOV        EDX,dword ptr [EBP + -0x10]
        0001097b 8b 45 ec        MOV        EAX,dword ptr [EBP + -0x14]
        0001097e 01 d0           ADD        EAX,EDX
        00010980 0f b6 10        MOVZX      EDX,byte ptr [EAX]
        00010983 8b 4d f4        MOV        ECX,dword ptr [EBP + -0xc]
        00010986 8b 45 ec        MOV        EAX,dword ptr [EBP + -0x14]
        00010989 01 c8           ADD        EAX,ECX
        0001098b 0f b6 00        MOVZX      EAX,byte ptr [EAX]
        0001098e 38 c2           CMP        DL,AL
        00010990 74 09           JZ         LAB_0001099b
        00010992 c7 45 e8        MOV        dword ptr [EBP + -0x18],0xffffffff
                 ff ff ff ff

```