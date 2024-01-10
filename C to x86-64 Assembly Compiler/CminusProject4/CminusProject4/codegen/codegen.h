#include <util/symtab_stack.h>
#ifndef CODEGEN_H_
#define CODEGEN_H_

EXTERN(void, emitProcedurePrologue, (DList instList, char* name)); 
EXTERN(void, emitDataPrologue, (DList dataList));
EXTERN(void, emitInstructions,(DList list));
EXTERN(void, emitExit, (DList instList));
EXTERN(void, emitAssignment, (DList instList, int lhsRegIndex, int rhsRegIndex));
EXTERN(void, emitReadVariable, (DList instList, DList dataList, char *formatStr, SymTable symtab, int addrIndex));
EXTERN(void, emitWriteExpression, (DList instList, DList dataList, char *formatStr, SymTable symtab, int regIndex));
EXTERN(void, emitWriteString,(DList instList,  DList dataList, SymTable symtab, char *str));

EXTERN(int, emitOrExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitAndExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitNotExpression, (DList instList, int operand));
EXTERN(int, emitEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitNotEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitLessEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitLessThanExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitGreaterEqualExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitGreaterThanExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitAddExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitSubtractExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitMultiplyExpression, (DList instList, int leftOperand, int rightOperand));
EXTERN(int, emitDivideExpression, (DList instList, int leftOperand, int rightOperand));

EXTERN(int, emitIfTest, (DList instList, SymTable symtab, int regIndex));
EXTERN(void, emitEndBranchTarget, (DList instList, SymTable symtab, int endLabelIndex));
EXTERN(int, emitThenBranch, (DList instList, SymTable symtab, int elseLabelIndex));
EXTERN(int, emitWhileLoopLandingPad, (DList instList,SymTable symtab));
EXTERN(int, emitWhileLoopTest, (DList instList, SymTable symtab, int regIndex));
EXTERN(void, emitWhileLoopBackBranch,(DList instList, SymTable symtab, int beginLabelIndex, int endLabelIndex));

EXTERN(int, emitComputeVariableAddress,(DList instList,  SymTable symtab, int varIndex));
EXTERN(int, emitComputeArrayAddress, (DList instList, SymTable symtab, int varIndex, int subIndex));
EXTERN(int, emitCompute2DArrayAddress, (DList instList, SymTable varSymtab, int varIndex, int subIndex1, int subIndex2));

EXTERN(int, emitLoadVariable,(DList instList, int varIndex));
EXTERN(int, emitLoadIntegerConstant,(DList instList, char* intConst));

EXTERN(int, emitFuncCall,(DList instList, char* str, SymtabStack stack));

EXTERN(void, addIdToSymtab, (SymTable symtab, char* id));
EXTERN(void, addArrayIdToSymtab, (SymTable symtab, char* id, int dim1, int dim2));
#endif /*CODEGEN_H_*/

