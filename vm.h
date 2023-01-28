//
// Created by lc on 2022/12/7.
//

#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "table.h"
#include "object.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
    // the function being called
    ObjClosure* closure;

    uint8_t* ip;
    // first slot of this function call in vm.stack
    Value* slots;
} CallFrame;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;


typedef struct {

    CallFrame frames[FRAMES_MAX];
    int frameCount;

    Value stack[STACK_MAX];
    Value* stackTop;
    //global variables
    Table globals;
    //hash table
    Table strings;
    //keep track of all objects for freeing them
    Obj* objects;
    //init method name, "init"
    ObjString* initString;

    // list of all open upvalues that point to variables still on the stack
    ObjUpvalue* openUpvalues;
    //GC, tracing worklist
    int grayCount;
    int grayCapacity;
    Obj** grayStack;
    //for adjusting GC parameters
    size_t bytesAllocated;
    size_t nextGC;
} VM;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif
