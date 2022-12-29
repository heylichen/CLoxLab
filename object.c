//
// Created by lc on 2022-12-29.
//
#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "object.h"
#include "value.h"
#include "vm.h"

/**
 * allocate specific Obj struct on heap, assign objType
 */
#define ALLOCATE_OBJ(type, objectType) \
    (type*)allocateObject(sizeof(type), objectType)

/**
 * allocate specific Obj struct on heap, assign objType
 */
static Obj* allocateObject(size_t size, ObjType type) {
    Obj* object = (Obj*)reallocate(NULL, 0, size);
    object->type = type;

    //add to vm.objects linked list when creating object
    object->next = vm.objects;
    vm.objects = object;

    return object;
}

/**
 * allocate ObjString on heap, point to the char array passed in.
 * @param chars
 * @param length
 * @return
 */
static ObjString* allocateString(char* chars, int length) {
    ObjString* string = ALLOCATE_OBJ(ObjString, OBJ_STRING);
    string->length = length;
    string->chars = chars;
    return string;
}

/**
 * copy char array on heap, allocate a new ObjString point to
 * the copied char array.
 * @param chars
 * @param length
 * @return
 */
ObjString* copyString(const char* chars, int length) {
    char* heapChars = ALLOCATE(char, length + 1);
    memcpy(heapChars, chars, length);
    heapChars[length] = '\0';
    return allocateString(heapChars, length);
}

void printObject(Value value) {
    switch (OBJ_TYPE(value)) {
        case OBJ_STRING:
            printf("%s", AS_CSTRING(value));
            break;
    }
}

ObjString* takeString(char* chars, int length) {
    return allocateString(chars, length);
}