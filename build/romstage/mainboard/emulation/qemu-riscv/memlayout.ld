OUTPUT_ARCH(riscv)
PHDRS
{
 to_load PT_LOAD;
}
ENTRY(stage_entry)
SECTIONS
{
 _ = ASSERT(. <= 0x80000000, "sram overlaps the previous region!"); . = 0x80000000; _sram = .;
 _ = ASSERT(. <= 0x80000000, "bootblock overlaps the previous region!"); . = 0x80000000; _bootblock = .; _ = ASSERT(. == ALIGN(1), "bootblock must be aligned to 1!"); _ = ASSERT(. <= 0x80000000 + 64K, "ebootblock overlaps the previous region!"); . = 0x80000000 + 64K; _ebootblock = .;
 _ = ASSERT(. <= (0x80000000 + 0x00400000), "esram overlaps the previous region!"); . = (0x80000000 + 0x00400000); _esram = .;
 _ = ASSERT(. <= (0x80000000 + 0x00400000), "dram overlaps the previous region!"); . = (0x80000000 + 0x00400000); _dram = .;
 _ = ASSERT(. <= (0x80000000 + 0x00400000), "romstage overlaps the previous region!"); . = (0x80000000 + 0x00400000); _romstage = .; _eromstage = _romstage + 128K; _ = ASSERT(_eprogram - _program <= 128K, "Romstage exceeded its allotted size! (128K)"); INCLUDE "romstage/lib/program.ld"
 _ = ASSERT(. <= (0x80000000 + 0x00400000) + 128K, "preram_cbmem_console overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 128K; _preram_cbmem_console = .; _ = ASSERT(. == ALIGN(4), "preram_cbmem_console must be aligned to 4!"); _ = ASSERT(. <= (0x80000000 + 0x00400000) + 128K + 8K, "epreram_cbmem_console overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 128K + 8K; _epreram_cbmem_console = .;
 _ = ASSERT(. <= (0x80000000 + 0x00400000) + 136K, "fmap_cache overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 136K; _fmap_cache = .; _ = ASSERT(. == ALIGN(4), "fmap_cache must be aligned to 4!"); _ = ASSERT(. <= (0x80000000 + 0x00400000) + 136K + 2K, "efmap_cache overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 136K + 2K; _efmap_cache = .; _ = ASSERT(2K >= 0xe0, "FMAP does not fit in FMAP_CACHE! (2K < 0xe0)");
 _ = ASSERT(. <= (0x80000000 + 0x00400000) + 200K, "ramstage overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 200K; _ramstage = .; _ = ASSERT(. == ALIGN(1), "ramstage must be aligned to 1!"); _ = ASSERT(. <= (0x80000000 + 0x00400000) + 200K + 16M, "eramstage overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 200K + 16M; _eramstage = .;
 _ = ASSERT(. <= (0x80000000 + 0x00400000) + 200K + 16M, "stack overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 200K + 16M; _stack = .; _ = ASSERT(. == ALIGN(4096), "stack must be aligned to 4096!"); _ = ASSERT(. <= (0x80000000 + 0x00400000) + 200K + 16M + 4K, "estack overlaps the previous region!"); . = (0x80000000 + 0x00400000) + 200K + 16M + 4K; _estack = .;
}
