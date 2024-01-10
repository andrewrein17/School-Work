/*
 * types.c
 *
 *  Created on: Jul 13, 2009
 *      Author: carr, wang
 */

#include <string.h>
#include <codegen/types.h>
#include <codegen/reg.h>
#include <util/symtab.h>
#include <codegen/symfields.h>

typedef struct array_type {
  int elementType;
  int dimensionSize;
  int numElements;
} Array_Type_Info;

int typeid = COMPOSITE_TYPE;
Array_Type_Info arrayTypeTable[NUM_ARRAY_TYPES];


/**
 * Return true if a type is an array, false otherwise.
 *
 * @param symtab a symbol table
 * @param typeIndex a symbol table index for a type
 * @return see above
 */
bool isArrayType(int typeIndex) {
  return (bool)(typeIndex >= COMPOSITE_TYPE);
}


int newArrayType(int numElements, int dimensionSize)
{
   int tid;

   tid = typeid++;
   arrayTypeTable[tid].numElements = numElements;
   arrayTypeTable[tid].dimensionSize = dimensionSize;
   return tid;
     
}  

void setArrayElementType(int typeId, int elementTypeId)
{
    arrayTypeTable[typeId].elementType = elementTypeId; 
}

int getArrayElementType(int typeId)
{
    return arrayTypeTable[typeId].elementType; 
}


int getTypeSize(int typeIndex)
{
  if (typeIndex == INTEGER_TYPE)
    return INTEGER_SIZE;
  else {// array type
    return arrayTypeTable[typeIndex].numElements * getTypeSize(arrayTypeTable[typeIndex].elementType);
  }
}

int get2ndDimensionSize(int typeIndex)
{
  return arrayTypeTable[typeIndex].dimensionSize;
}
