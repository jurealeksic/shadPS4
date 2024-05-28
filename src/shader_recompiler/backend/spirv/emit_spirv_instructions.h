// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <sirit/sirit.h>
#include "common/types.h"

namespace Shader::IR {
enum class Attribute : u64;
enum class ScalarReg : u32;
class Inst;
class Value;
} // namespace Shader::IR

namespace Shader::Backend::SPIRV {

using Sirit::Id;

class EmitContext;

// Microinstruction emitters
Id EmitPhi(EmitContext& ctx, IR::Inst* inst);
void EmitVoid(EmitContext& ctx);
Id EmitIdentity(EmitContext& ctx, const IR::Value& value);
Id EmitConditionRef(EmitContext& ctx, const IR::Value& value);
void EmitReference(EmitContext&);
void EmitPhiMove(EmitContext&);
void EmitJoin(EmitContext& ctx);
void EmitBarrier(EmitContext& ctx);
void EmitWorkgroupMemoryBarrier(EmitContext& ctx);
void EmitDeviceMemoryBarrier(EmitContext& ctx);
void EmitGetScc(EmitContext& ctx);
void EmitGetExec(EmitContext& ctx);
void EmitGetVcc(EmitContext& ctx);
void EmitGetVccLo(EmitContext& ctx);
void EmitSetScc(EmitContext& ctx);
void EmitSetExec(EmitContext& ctx);
void EmitSetVcc(EmitContext& ctx);
void EmitSetVccLo(EmitContext& ctx);
void EmitPrologue(EmitContext& ctx);
void EmitEpilogue(EmitContext& ctx);
void EmitDiscard(EmitContext& ctx);
Id EmitGetUserData(EmitContext& ctx, IR::ScalarReg reg);
void EmitGetScalarRegister(EmitContext& ctx);
void EmitSetScalarRegister(EmitContext& ctx);
void EmitGetVectorRegister(EmitContext& ctx);
void EmitSetVectorRegister(EmitContext& ctx);
void EmitSetGotoVariable(EmitContext& ctx);
void EmitGetGotoVariable(EmitContext& ctx);
void EmitSetScc(EmitContext& ctx);
Id EmitReadConst(EmitContext& ctx);
Id EmitReadConstBuffer(EmitContext& ctx, u32 handle, Id index);
Id EmitReadConstBufferU32(EmitContext& ctx, u32 handle, Id index);
Id EmitLoadBufferF32(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address);
Id EmitLoadBufferF32x2(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address);
Id EmitLoadBufferF32x3(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address);
Id EmitLoadBufferF32x4(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address);
Id EmitLoadBufferU32(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address);
void EmitStoreBufferF32(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address, Id value);
void EmitStoreBufferF32x2(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address, Id value);
void EmitStoreBufferF32x3(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address, Id value);
void EmitStoreBufferF32x4(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address, Id value);
void EmitStoreBufferU32(EmitContext& ctx, IR::Inst* inst, u32 handle, Id address, Id value);
Id EmitGetAttribute(EmitContext& ctx, IR::Attribute attr, u32 comp);
Id EmitGetAttributeU32(EmitContext& ctx, IR::Attribute attr, u32 comp);
void EmitSetAttribute(EmitContext& ctx, IR::Attribute attr, Id value, u32 comp);
void EmitSetFragColor(EmitContext& ctx, u32 index, u32 component, Id value);
void EmitSetSampleMask(EmitContext& ctx, Id value);
void EmitSetFragDepth(EmitContext& ctx, Id value);
Id EmitWorkgroupId(EmitContext& ctx);
Id EmitLocalInvocationId(EmitContext& ctx);
Id EmitInvocationId(EmitContext& ctx);
Id EmitInvocationInfo(EmitContext& ctx);
Id EmitSampleId(EmitContext& ctx);
Id EmitUndefU1(EmitContext& ctx);
Id EmitUndefU8(EmitContext& ctx);
Id EmitUndefU16(EmitContext& ctx);
Id EmitUndefU32(EmitContext& ctx);
Id EmitUndefU64(EmitContext& ctx);
Id EmitReadSharedU8(EmitContext& ctx, Id offset);
Id EmitReadSharedS8(EmitContext& ctx, Id offset);
Id EmitReadSharedU16(EmitContext& ctx, Id offset);
Id EmitReadSharedS16(EmitContext& ctx, Id offset);
Id EmitReadSharedU32(EmitContext& ctx, Id offset);
Id EmitReadSharedU64(EmitContext& ctx, Id offset);
void EmitWriteSharedU8(EmitContext& ctx, Id offset, Id value);
void EmitWriteSharedU16(EmitContext& ctx, Id offset, Id value);
void EmitWriteSharedU32(EmitContext& ctx, Id offset, Id value);
void EmitWriteSharedU64(EmitContext& ctx, Id offset, Id value);
void EmitWriteSharedU128(EmitContext& ctx, Id offset, Id value);
Id EmitCompositeConstructU32x2(EmitContext& ctx, Id e1, Id e2);
Id EmitCompositeConstructU32x3(EmitContext& ctx, Id e1, Id e2, Id e3);
Id EmitCompositeConstructU32x4(EmitContext& ctx, Id e1, Id e2, Id e3, Id e4);
Id EmitCompositeExtractU32x2(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeExtractU32x3(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeExtractU32x4(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeInsertU32x2(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertU32x3(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertU32x4(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeConstructF16x2(EmitContext& ctx, Id e1, Id e2);
Id EmitCompositeConstructF16x3(EmitContext& ctx, Id e1, Id e2, Id e3);
Id EmitCompositeConstructF16x4(EmitContext& ctx, Id e1, Id e2, Id e3, Id e4);
Id EmitCompositeExtractF16x2(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeExtractF16x3(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeExtractF16x4(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeInsertF16x2(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertF16x3(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertF16x4(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeConstructF32x2(EmitContext& ctx, Id e1, Id e2);
Id EmitCompositeConstructF32x3(EmitContext& ctx, Id e1, Id e2, Id e3);
Id EmitCompositeConstructF32x4(EmitContext& ctx, Id e1, Id e2, Id e3, Id e4);
Id EmitCompositeExtractF32x2(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeExtractF32x3(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeExtractF32x4(EmitContext& ctx, Id composite, u32 index);
Id EmitCompositeInsertF32x2(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertF32x3(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertF32x4(EmitContext& ctx, Id composite, Id object, u32 index);
void EmitCompositeConstructF64x2(EmitContext& ctx);
void EmitCompositeConstructF64x3(EmitContext& ctx);
void EmitCompositeConstructF64x4(EmitContext& ctx);
void EmitCompositeExtractF64x2(EmitContext& ctx);
void EmitCompositeExtractF64x3(EmitContext& ctx);
void EmitCompositeExtractF64x4(EmitContext& ctx);
Id EmitCompositeInsertF64x2(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertF64x3(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitCompositeInsertF64x4(EmitContext& ctx, Id composite, Id object, u32 index);
Id EmitSelectU1(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectU8(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectU16(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectU32(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectU64(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectF16(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectF32(EmitContext& ctx, Id cond, Id true_value, Id false_value);
Id EmitSelectF64(EmitContext& ctx, Id cond, Id true_value, Id false_value);
void EmitBitCastU16F16(EmitContext& ctx);
Id EmitBitCastU32F32(EmitContext& ctx, Id value);
void EmitBitCastU64F64(EmitContext& ctx);
void EmitBitCastF16U16(EmitContext&);
Id EmitBitCastF32U32(EmitContext& ctx, Id value);
void EmitBitCastF64U64(EmitContext& ctx);
Id EmitPackUint2x32(EmitContext& ctx, Id value);
Id EmitUnpackUint2x32(EmitContext& ctx, Id value);
Id EmitPackFloat2x16(EmitContext& ctx, Id value);
Id EmitUnpackFloat2x16(EmitContext& ctx, Id value);
Id EmitPackHalf2x16(EmitContext& ctx, Id value);
Id EmitUnpackHalf2x16(EmitContext& ctx, Id value);
Id EmitFPAbs16(EmitContext& ctx, Id value);
Id EmitFPAbs32(EmitContext& ctx, Id value);
Id EmitFPAbs64(EmitContext& ctx, Id value);
Id EmitFPAdd16(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPAdd32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPAdd64(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPSub32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPFma16(EmitContext& ctx, IR::Inst* inst, Id a, Id b, Id c);
Id EmitFPFma32(EmitContext& ctx, IR::Inst* inst, Id a, Id b, Id c);
Id EmitFPFma64(EmitContext& ctx, IR::Inst* inst, Id a, Id b, Id c);
Id EmitFPMax32(EmitContext& ctx, Id a, Id b);
Id EmitFPMax64(EmitContext& ctx, Id a, Id b);
Id EmitFPMin32(EmitContext& ctx, Id a, Id b);
Id EmitFPMin64(EmitContext& ctx, Id a, Id b);
Id EmitFPMul16(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPMul32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPMul64(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitFPNeg16(EmitContext& ctx, Id value);
Id EmitFPNeg32(EmitContext& ctx, Id value);
Id EmitFPNeg64(EmitContext& ctx, Id value);
Id EmitFPSin(EmitContext& ctx, Id value);
Id EmitFPCos(EmitContext& ctx, Id value);
Id EmitFPExp2(EmitContext& ctx, Id value);
Id EmitFPLog2(EmitContext& ctx, Id value);
Id EmitFPRecip32(EmitContext& ctx, Id value);
Id EmitFPRecip64(EmitContext& ctx, Id value);
Id EmitFPRecipSqrt32(EmitContext& ctx, Id value);
Id EmitFPRecipSqrt64(EmitContext& ctx, Id value);
Id EmitFPSqrt(EmitContext& ctx, Id value);
Id EmitFPSaturate16(EmitContext& ctx, Id value);
Id EmitFPSaturate32(EmitContext& ctx, Id value);
Id EmitFPSaturate64(EmitContext& ctx, Id value);
Id EmitFPClamp16(EmitContext& ctx, Id value, Id min_value, Id max_value);
Id EmitFPClamp32(EmitContext& ctx, Id value, Id min_value, Id max_value);
Id EmitFPClamp64(EmitContext& ctx, Id value, Id min_value, Id max_value);
Id EmitFPRoundEven16(EmitContext& ctx, Id value);
Id EmitFPRoundEven32(EmitContext& ctx, Id value);
Id EmitFPRoundEven64(EmitContext& ctx, Id value);
Id EmitFPFloor16(EmitContext& ctx, Id value);
Id EmitFPFloor32(EmitContext& ctx, Id value);
Id EmitFPFloor64(EmitContext& ctx, Id value);
Id EmitFPCeil16(EmitContext& ctx, Id value);
Id EmitFPCeil32(EmitContext& ctx, Id value);
Id EmitFPCeil64(EmitContext& ctx, Id value);
Id EmitFPTrunc16(EmitContext& ctx, Id value);
Id EmitFPTrunc32(EmitContext& ctx, Id value);
Id EmitFPTrunc64(EmitContext& ctx, Id value);
Id EmitFPFract(EmitContext& ctx, Id value);
Id EmitFPOrdEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdNotEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdNotEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdNotEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordNotEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordNotEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordNotEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdLessThan16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdLessThan32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdLessThan64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordLessThan16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordLessThan32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordLessThan64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdGreaterThan16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdGreaterThan32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdGreaterThan64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordGreaterThan16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordGreaterThan32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordGreaterThan64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdLessThanEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdLessThanEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdLessThanEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordLessThanEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordLessThanEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordLessThanEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdGreaterThanEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdGreaterThanEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPOrdGreaterThanEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordGreaterThanEqual16(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordGreaterThanEqual32(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPUnordGreaterThanEqual64(EmitContext& ctx, Id lhs, Id rhs);
Id EmitFPIsNan16(EmitContext& ctx, Id value);
Id EmitFPIsNan32(EmitContext& ctx, Id value);
Id EmitFPIsNan64(EmitContext& ctx, Id value);
Id EmitIAdd32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitIAdd64(EmitContext& ctx, Id a, Id b);
Id EmitISub32(EmitContext& ctx, Id a, Id b);
Id EmitISub64(EmitContext& ctx, Id a, Id b);
Id EmitIMul32(EmitContext& ctx, Id a, Id b);
Id EmitSDiv32(EmitContext& ctx, Id a, Id b);
Id EmitUDiv32(EmitContext& ctx, Id a, Id b);
Id EmitINeg32(EmitContext& ctx, Id value);
Id EmitINeg64(EmitContext& ctx, Id value);
Id EmitIAbs32(EmitContext& ctx, Id value);
Id EmitShiftLeftLogical32(EmitContext& ctx, Id base, Id shift);
Id EmitShiftLeftLogical64(EmitContext& ctx, Id base, Id shift);
Id EmitShiftRightLogical32(EmitContext& ctx, Id base, Id shift);
Id EmitShiftRightLogical64(EmitContext& ctx, Id base, Id shift);
Id EmitShiftRightArithmetic32(EmitContext& ctx, Id base, Id shift);
Id EmitShiftRightArithmetic64(EmitContext& ctx, Id base, Id shift);
Id EmitBitwiseAnd32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitBitwiseOr32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitBitwiseXor32(EmitContext& ctx, IR::Inst* inst, Id a, Id b);
Id EmitBitFieldInsert(EmitContext& ctx, Id base, Id insert, Id offset, Id count);
Id EmitBitFieldSExtract(EmitContext& ctx, IR::Inst* inst, Id base, Id offset, Id count);
Id EmitBitFieldUExtract(EmitContext& ctx, IR::Inst* inst, Id base, Id offset, Id count);
Id EmitBitReverse32(EmitContext& ctx, Id value);
Id EmitBitCount32(EmitContext& ctx, Id value);
Id EmitBitwiseNot32(EmitContext& ctx, Id value);
Id EmitFindSMsb32(EmitContext& ctx, Id value);
Id EmitFindUMsb32(EmitContext& ctx, Id value);
Id EmitSMin32(EmitContext& ctx, Id a, Id b);
Id EmitUMin32(EmitContext& ctx, Id a, Id b);
Id EmitSMax32(EmitContext& ctx, Id a, Id b);
Id EmitUMax32(EmitContext& ctx, Id a, Id b);
Id EmitSClamp32(EmitContext& ctx, IR::Inst* inst, Id value, Id min, Id max);
Id EmitUClamp32(EmitContext& ctx, IR::Inst* inst, Id value, Id min, Id max);
Id EmitSLessThan(EmitContext& ctx, Id lhs, Id rhs);
Id EmitULessThan(EmitContext& ctx, Id lhs, Id rhs);
Id EmitIEqual(EmitContext& ctx, Id lhs, Id rhs);
Id EmitSLessThanEqual(EmitContext& ctx, Id lhs, Id rhs);
Id EmitULessThanEqual(EmitContext& ctx, Id lhs, Id rhs);
Id EmitSGreaterThan(EmitContext& ctx, Id lhs, Id rhs);
Id EmitUGreaterThan(EmitContext& ctx, Id lhs, Id rhs);
Id EmitINotEqual(EmitContext& ctx, Id lhs, Id rhs);
Id EmitSGreaterThanEqual(EmitContext& ctx, Id lhs, Id rhs);
Id EmitUGreaterThanEqual(EmitContext& ctx, Id lhs, Id rhs);
Id EmitLogicalOr(EmitContext& ctx, Id a, Id b);
Id EmitLogicalAnd(EmitContext& ctx, Id a, Id b);
Id EmitLogicalXor(EmitContext& ctx, Id a, Id b);
Id EmitLogicalNot(EmitContext& ctx, Id value);
Id EmitConvertS16F16(EmitContext& ctx, Id value);
Id EmitConvertS16F32(EmitContext& ctx, Id value);
Id EmitConvertS16F64(EmitContext& ctx, Id value);
Id EmitConvertS32F16(EmitContext& ctx, Id value);
Id EmitConvertS32F32(EmitContext& ctx, Id value);
Id EmitConvertS32F64(EmitContext& ctx, Id value);
Id EmitConvertS64F16(EmitContext& ctx, Id value);
Id EmitConvertS64F32(EmitContext& ctx, Id value);
Id EmitConvertS64F64(EmitContext& ctx, Id value);
Id EmitConvertU16F16(EmitContext& ctx, Id value);
Id EmitConvertU16F32(EmitContext& ctx, Id value);
Id EmitConvertU16F64(EmitContext& ctx, Id value);
Id EmitConvertU32F16(EmitContext& ctx, Id value);
Id EmitConvertU32F32(EmitContext& ctx, Id value);
Id EmitConvertU32F64(EmitContext& ctx, Id value);
Id EmitConvertU64F16(EmitContext& ctx, Id value);
Id EmitConvertU64F32(EmitContext& ctx, Id value);
Id EmitConvertU64F64(EmitContext& ctx, Id value);
Id EmitConvertU64U32(EmitContext& ctx, Id value);
Id EmitConvertU32U64(EmitContext& ctx, Id value);
Id EmitConvertF16F32(EmitContext& ctx, Id value);
Id EmitConvertF32F16(EmitContext& ctx, Id value);
Id EmitConvertF32F64(EmitContext& ctx, Id value);
Id EmitConvertF64F32(EmitContext& ctx, Id value);
Id EmitConvertF16S8(EmitContext& ctx, Id value);
Id EmitConvertF16S16(EmitContext& ctx, Id value);
Id EmitConvertF16S32(EmitContext& ctx, Id value);
Id EmitConvertF16S64(EmitContext& ctx, Id value);
Id EmitConvertF16U8(EmitContext& ctx, Id value);
Id EmitConvertF16U16(EmitContext& ctx, Id value);
Id EmitConvertF16U32(EmitContext& ctx, Id value);
Id EmitConvertF16U64(EmitContext& ctx, Id value);
Id EmitConvertF32S8(EmitContext& ctx, Id value);
Id EmitConvertF32S16(EmitContext& ctx, Id value);
Id EmitConvertF32S32(EmitContext& ctx, Id value);
Id EmitConvertF32S64(EmitContext& ctx, Id value);
Id EmitConvertF32U8(EmitContext& ctx, Id value);
Id EmitConvertF32U16(EmitContext& ctx, Id value);
Id EmitConvertF32U32(EmitContext& ctx, Id value);
Id EmitConvertF32U64(EmitContext& ctx, Id value);
Id EmitConvertF64S8(EmitContext& ctx, Id value);
Id EmitConvertF64S16(EmitContext& ctx, Id value);
Id EmitConvertF64S32(EmitContext& ctx, Id value);
Id EmitConvertF64S64(EmitContext& ctx, Id value);
Id EmitConvertF64U8(EmitContext& ctx, Id value);
Id EmitConvertF64U16(EmitContext& ctx, Id value);
Id EmitConvertF64U32(EmitContext& ctx, Id value);
Id EmitConvertF64U64(EmitContext& ctx, Id value);

Id EmitImageSampleImplicitLod(EmitContext& ctx, IR::Inst* inst, u32 handle, Id coords, Id bias_lc,
                              Id offset);
Id EmitImageSampleExplicitLod(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords,
                              Id lod, const IR::Value& offset);
Id EmitImageSampleDrefImplicitLod(EmitContext& ctx, IR::Inst* inst, const IR::Value& index,
                                  Id coords, Id dref, Id bias_lc, const IR::Value& offset);
Id EmitImageSampleDrefExplicitLod(EmitContext& ctx, IR::Inst* inst, const IR::Value& index,
                                  Id coords, Id dref, Id lod, const IR::Value& offset);
Id EmitImageGather(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords,
                   const IR::Value& offset, const IR::Value& offset2);
Id EmitImageGatherDref(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords,
                       const IR::Value& offset, const IR::Value& offset2, Id dref);
Id EmitImageFetch(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords, Id offset,
                  Id lod, Id ms);
Id EmitImageQueryDimensions(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id lod,
                            const IR::Value& skip_mips);
Id EmitImageQueryLod(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords);
Id EmitImageGradient(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords,
                     Id derivatives, const IR::Value& offset, Id lod_clamp);
Id EmitImageRead(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords);
void EmitImageWrite(EmitContext& ctx, IR::Inst* inst, const IR::Value& index, Id coords, Id color);

} // namespace Shader::Backend::SPIRV
