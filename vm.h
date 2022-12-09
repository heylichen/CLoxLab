//
// Created by lc on 2022/12/7.
//

#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#define STACK_MAX 256

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;


typedef struct {
    Chunk* chunk;
    //instruction pointer
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
} VM;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
