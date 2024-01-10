/*
 * types.h
 *
 *  Created on: Jul 13, 2009
 *  Modified on: Feb 13, 2021
 *      Author: carr, wang
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <util/general.h>
#include <util/symtab.h>
#include <codegen/symfields.h>

#define INTEGER_SIZE 4	/**< The number of bytes for an integer */

#define INTEGER_TYPE 0 /**< an integer */
#define COMPOSITE_TYPE 1 /**< starting type id of composite type*/

#define NUM_ARRAY_TYPES 100

EXTERN(bool, isArrayType, (int typeIndex));
EXTERN(int, newArrayType, (int numElements, int dimensionSize));
EXTERN(void, setArrayElementType, (int typeId, int elementTypeId));
EXTERN(int, getArrayElementType, (int typeId));
EXTERN(int, getTypeSize, (int typeIndex));
EXTERN(int, get2ndDimensionSize, (int typeIndex));
#endif /* TYPES_H_ */
