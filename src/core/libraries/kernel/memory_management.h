// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/bit_field.h"
#include "common/types.h"

constexpr u64 SCE_KERNEL_MAIN_DMEM_SIZE = 5376_MB; // ~ 6GB

namespace Libraries::Kernel {

enum MemoryTypes : u32 {
    SCE_KERNEL_WB_ONION = 0,  // write - back mode (Onion bus)
    SCE_KERNEL_WC_GARLIC = 3, // write - combining mode (Garlic bus)
    SCE_KERNEL_WB_GARLIC = 10 // write - back mode (Garlic bus)
};

enum MemoryFlags : u32 {
    SCE_KERNEL_MAP_FIXED = 0x0010, // Fixed
    SCE_KERNEL_MAP_NO_OVERWRITE = 0x0080,
    SCE_KERNEL_MAP_NO_COALESCE = 0x400000
};

enum MemoryProtection : u32 {
    SCE_KERNEL_PROT_CPU_READ = 0x01,  // Permit reads from the CPU
    SCE_KERNEL_PROT_CPU_RW = 0x02,    // Permit reads/writes from the CPU
    SCE_KERNEL_PROT_CPU_WRITE = 0x02, // Permit reads/writes from the CPU (same)
    SCE_KERNEL_PROT_GPU_READ = 0x10,  // Permit reads from the GPU
    SCE_KERNEL_PROT_GPU_WRITE = 0x20, // Permit writes from the GPU
    SCE_KERNEL_PROT_GPU_RW = 0x30     // Permit reads/writes from the GPU
};

struct OrbisQueryInfo {
    uintptr_t start;
    uintptr_t end;
    int memoryType;
};

struct OrbisVirtualQueryInfo {
    uintptr_t start;
    uintptr_t end;
    size_t offset;
    s32 protection;
    s32 memory_type;
    union {
        BitField<0, 1, u32> is_flexible;
        BitField<1, 1, u32> is_direct;
        BitField<2, 1, u32> is_stack;
        BitField<3, 1, u32> is_pooled;
        BitField<4, 1, u32> is_commited;
    };
    std::array<char, 32> name;
};

u64 PS4_SYSV_ABI sceKernelGetDirectMemorySize();
s32 PS4_SYSV_ABI sceKernelCheckedReleaseDirectMemory(u64 start, size_t len);
int PS4_SYSV_ABI sceKernelAllocateDirectMemory(s64 searchStart, s64 searchEnd, u64 len,
                                               u64 alignment, int memoryType, s64* physAddrOut);
s32 PS4_SYSV_ABI sceKernelAllocateMainDirectMemory(size_t len, size_t alignment, int memoryType,
                                                   s64* physAddrOut);
int PS4_SYSV_ABI sceKernelMapDirectMemory(void** addr, u64 len, int prot, int flags,
                                          s64 directMemoryStart, u64 alignment);
s32 PS4_SYSV_ABI sceKernelMapNamedFlexibleMemory(void** addrInOut, std::size_t len, int prot,
                                                 int flags, const char* name);
s32 PS4_SYSV_ABI sceKernelMapFlexibleMemory(void** addr_in_out, std::size_t len, int prot,
                                            int flags);
int PS4_SYSV_ABI sceKernelQueryMemoryProtection(void* addr, void** start, void** end, u32* prot);

int PS4_SYSV_ABI sceKernelDirectMemoryQuery(u64 offset, int flags, OrbisQueryInfo* query_info,
                                            size_t infoSize);

s32 PS4_SYSV_ABI sceKernelVirtualQuery(const void *addr, int flags, OrbisVirtualQueryInfo *info, size_t infoSize);

void PS4_SYSV_ABI _sceKernelRtldSetApplicationHeapAPI(void* func);

} // namespace Libraries::Kernel
