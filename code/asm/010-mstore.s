	.file	"010-mstore.c"
	.text
.Ltext0:
	.globl	multstore
	.type	multstore, @function
multstore:
.LVL0:
.LFB0:
	.file 1 "010-mstore.c"
	.loc 1 4 44 view -0
	.cfi_startproc
	.loc 1 4 44 is_stmt 0 view .LVU1
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdx, %rbx
	.loc 1 5 5 is_stmt 1 view .LVU2
	.loc 1 5 14 is_stmt 0 view .LVU3
	call	mult2
.LVL1:
	.loc 1 6 5 is_stmt 1 view .LVU4
	.loc 1 6 11 is_stmt 0 view .LVU5
	movq	%rax, (%rbx)
	.loc 1 7 1 view .LVU6
	popq	%rbx
	.cfi_def_cfa_offset 8
.LVL2:
	.loc 1 7 1 view .LVU7
	ret
	.cfi_endproc
.LFE0:
	.size	multstore, .-multstore
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xc8
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF1
	.byte	0xc
	.long	.LASF2
	.long	.LASF3
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF4
	.byte	0x1
	.byte	0x4
	.byte	0x6
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0xb2
	.uleb128 0x3
	.string	"x"
	.byte	0x1
	.byte	0x4
	.byte	0x15
	.long	0xb2
	.long	.LLST0
	.long	.LVUS0
	.uleb128 0x3
	.string	"y"
	.byte	0x1
	.byte	0x4
	.byte	0x1d
	.long	0xb2
	.long	.LLST1
	.long	.LVUS1
	.uleb128 0x4
	.long	.LASF0
	.byte	0x1
	.byte	0x4
	.byte	0x26
	.long	0xb9
	.long	.LLST2
	.long	.LVUS2
	.uleb128 0x5
	.string	"t"
	.byte	0x1
	.byte	0x5
	.byte	0xa
	.long	0xb2
	.long	.LLST3
	.long	.LVUS3
	.uleb128 0x6
	.quad	.LVL1
	.long	0xbf
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x7
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.byte	0x5
	.long	.LASF5
	.uleb128 0x9
	.byte	0x8
	.long	0xb2
	.uleb128 0xa
	.long	.LASF6
	.long	.LASF6
	.byte	0x1
	.byte	0x2
	.byte	0x6
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LVUS0:
	.uleb128 0
	.uleb128 .LVU4
	.uleb128 .LVU4
	.uleb128 0
.LLST0:
	.quad	.LVL0-.Ltext0
	.quad	.LVL1-1-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL1-1-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS1:
	.uleb128 0
	.uleb128 .LVU4
	.uleb128 .LVU4
	.uleb128 0
.LLST1:
	.quad	.LVL0-.Ltext0
	.quad	.LVL1-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL1-1-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS2:
	.uleb128 0
	.uleb128 .LVU4
	.uleb128 .LVU4
	.uleb128 .LVU7
	.uleb128 .LVU7
	.uleb128 0
.LLST2:
	.quad	.LVL0-.Ltext0
	.quad	.LVL1-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL1-1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL2-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS3:
	.uleb128 .LVU4
	.uleb128 0
.LLST3:
	.quad	.LVL1-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF6:
	.string	"mult2"
.LASF2:
	.string	"010-mstore.c"
.LASF1:
	.string	"GNU C17 8.5.0 20210514 (Red Hat 8.5.0-4) -mtune=generic -march=x86-64 -g -Og"
.LASF0:
	.string	"dest"
.LASF3:
	.string	"/CSAPP/code/asm"
.LASF5:
	.string	"long int"
.LASF4:
	.string	"multstore"
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-4)"
	.section	.note.GNU-stack,"",@progbits
