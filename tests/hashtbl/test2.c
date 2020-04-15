#define OCAML_STACK_WOSIZE              2048
#define OCAML_STATIC_HEAP_WOSIZE          70
#define OCAML_DYNAMIC_HEAP_WOSIZE        186
#define OCAML_FLASH_HEAP_WOSIZE          144
#define OCAML_STACK_INITIAL_WOSIZE         2
#define OCAML_RAM_GLOBDATA_NUMBER          0
#define OCAML_FLASH_GLOBDATA_NUMBER        5
#define OCAML_BYTECODE_BSIZE             178
#define OCAML_PRIMITIVE_NUMBER             5
#define OCAML_VIRTUAL_ARCH                64
#define OCAML_STARTING_OOID                2
#define OCAML_NO_FLASH_HEAP                0
#define OCAML_NO_FLASH_GLOBALS             0

#define OCAML_GC_MARK_AND_COMPACT

#include </usr/local/include/omicrob/vm/values.h>

#define OCAML_ACC0                        0
#define OCAML_ACC1                        1
#define OCAML_PUSH                        2
#define OCAML_PUSHACC1                    3
#define OCAML_PUSHACC2                    4
#define OCAML_PUSHACC3                    5
#define OCAML_PUSHACC4                    6
#define OCAML_PUSHACC6                    7
#define OCAML_PUSHACC                     8
#define OCAML_POP                         9
#define OCAML_APPLY1                     10
#define OCAML_APPLY2                     11
#define OCAML_APPTERM2                   12
#define OCAML_RETURN                     13
#define OCAML_RESTART                    14
#define OCAML_GRAB                       15
#define OCAML_PUSHOFFSETCLOSURE0         16
#define OCAML_GETFLASHGLOBAL_1B          17
#define OCAML_PUSHGETFLASHGLOBAL_1B      18
#define OCAML_GETFIELD0                  19
#define OCAML_GETFIELD1                  20
#define OCAML_GETFIELD2                  21
#define OCAML_VECTLENGTH                 22
#define OCAML_BRANCH_2B                  23
#define OCAML_BRANCHIF_1B                24
#define OCAML_BRANCHIFNOT_1B             25
#define OCAML_RAISE                      26
#define OCAML_C_CALL1                    27
#define OCAML_C_CALL2                    28
#define OCAML_C_CALL4                    29
#define OCAML_PUSHCONSTINT_1B            30
#define OCAML_ANDINT                     31
#define OCAML_OFFSETINT_1B               32
#define OCAML_STOP                       33

value ocaml_stack[OCAML_STACK_WOSIZE];
value ocaml_ram_heap[OCAML_STATIC_HEAP_WOSIZE + OCAML_DYNAMIC_HEAP_WOSIZE];
value ocaml_ram_global_data[OCAML_RAM_GLOBDATA_NUMBER];

PROGMEM value const ocaml_flash_heap[OCAML_FLASH_HEAP_WOSIZE] = {
  /*   0 */  Make_header(0, 0, Color_white),
  /*   1 */  Make_header(2, Object_tag, Color_white),
  /*   2 */  Val_flash_block(&ocaml_flash_heap[5]),
  /*   3 */  Val_int(-1),
  /*   4 */  Make_header(2, String_tag, Color_white),
  /*   5 */  Make_string_data('O', 'u', 't', '_', 'o', 'f', '_', 'm'),
  /*   6 */  Make_string_data('e', 'm', 'o', 'r', 'y', '\0', '\0', '\2'),
  /*   7 */  Make_header(2, Object_tag, Color_white),
  /*   8 */  Val_flash_block(&ocaml_flash_heap[11]),
  /*   9 */  Val_int(-3),
  /*  10 */  Make_header(1, String_tag, Color_white),
  /*  11 */  Make_string_data('F', 'a', 'i', 'l', 'u', 'r', 'e', '\0'),
  /*  12 */  Make_header(2, Object_tag, Color_white),
  /*  13 */  Val_flash_block(&ocaml_flash_heap[16]),
  /*  14 */  Val_int(-4),
  /*  15 */  Make_header(3, String_tag, Color_white),
  /*  16 */  Make_string_data('I', 'n', 'v', 'a', 'l', 'i', 'd', '_'),
  /*  17 */  Make_string_data('a', 'r', 'g', 'u', 'm', 'e', 'n', 't'),
  /*  18 */  Make_string_data('\0', '\0', '\0', '\0', '\0', '\0', '\0', '\7'),
  /*  19 */  Make_header(2, Object_tag, Color_white),
  /*  20 */  Val_flash_block(&ocaml_flash_heap[23]),
  /*  21 */  Val_int(-6),
  /*  22 */  Make_header(3, String_tag, Color_white),
  /*  23 */  Make_string_data('D', 'i', 'v', 'i', 's', 'i', 'o', 'n'),
  /*  24 */  Make_string_data('_', 'b', 'y', '_', 'z', 'e', 'r', 'o'),
  /*  25 */  Make_string_data('\0', '\0', '\0', '\0', '\0', '\0', '\0', '\7'),
  /*  26 */  Make_header(2, Object_tag, Color_white),
  /*  27 */  Val_flash_block(&ocaml_flash_heap[30]),
  /*  28 */  Val_int(-9),
  /*  29 */  Make_header(2, String_tag, Color_white),
  /*  30 */  Make_string_data('S', 't', 'a', 'c', 'k', '_', 'o', 'v'),
  /*  31 */  Make_string_data('e', 'r', 'f', 'l', 'o', 'w', '\0', '\1'),
  /*  32 */  Make_header(1, Closure_tag, Color_white),
  /*  33 */  Val_codeptr(4),
  /*  34 */  Make_header(1, Closure_tag, Color_white),
  /*  35 */  Val_codeptr(154),
  /*  36 */  Make_header(2, 0, Color_white),
  /*  37 */  Val_flash_block(&ocaml_flash_heap[40]),
  /*  38 */  Val_flash_block(&ocaml_flash_heap[45]),
  /*  39 */  Make_header(2, 0, Color_white),
  /*  40 */  Val_flash_block(&ocaml_flash_heap[43]),
  /*  41 */  Val_int(1),
  /*  42 */  Make_header(1, String_tag, Color_white),
  /*  43 */  Make_string_data('u', 'n', '\0', '\0', '\0', '\0', '\0', '\5'),
  /*  44 */  Make_header(2, 0, Color_white),
  /*  45 */  Val_flash_block(&ocaml_flash_heap[48]),
  /*  46 */  Val_flash_block(&ocaml_flash_heap[53]),
  /*  47 */  Make_header(2, 0, Color_white),
  /*  48 */  Val_flash_block(&ocaml_flash_heap[51]),
  /*  49 */  Val_int(2),
  /*  50 */  Make_header(1, String_tag, Color_white),
  /*  51 */  Make_string_data('d', 'e', 'u', 'x', '\0', '\0', '\0', '\3'),
  /*  52 */  Make_header(2, 0, Color_white),
  /*  53 */  Val_flash_block(&ocaml_flash_heap[56]),
  /*  54 */  Val_flash_block(&ocaml_flash_heap[61]),
  /*  55 */  Make_header(2, 0, Color_white),
  /*  56 */  Val_flash_block(&ocaml_flash_heap[59]),
  /*  57 */  Val_int(3),
  /*  58 */  Make_header(1, String_tag, Color_white),
  /*  59 */  Make_string_data('t', 'r', 'o', 'i', 's', '\0', '\0', '\2'),
  /*  60 */  Make_header(2, 0, Color_white),
  /*  61 */  Val_flash_block(&ocaml_flash_heap[64]),
  /*  62 */  Val_flash_block(&ocaml_flash_heap[69]),
  /*  63 */  Make_header(2, 0, Color_white),
  /*  64 */  Val_flash_block(&ocaml_flash_heap[67]),
  /*  65 */  Val_int(4),
  /*  66 */  Make_header(1, String_tag, Color_white),
  /*  67 */  Make_string_data('q', 'u', 'a', 't', 'r', 'e', '\0', '\1'),
  /*  68 */  Make_header(2, 0, Color_white),
  /*  69 */  Val_flash_block(&ocaml_flash_heap[72]),
  /*  70 */  Val_flash_block(&ocaml_flash_heap[77]),
  /*  71 */  Make_header(2, 0, Color_white),
  /*  72 */  Val_flash_block(&ocaml_flash_heap[75]),
  /*  73 */  Val_int(5),
  /*  74 */  Make_header(1, String_tag, Color_white),
  /*  75 */  Make_string_data('c', 'i', 'n', 'q', '\0', '\0', '\0', '\3'),
  /*  76 */  Make_header(2, 0, Color_white),
  /*  77 */  Val_flash_block(&ocaml_flash_heap[80]),
  /*  78 */  Val_flash_block(&ocaml_flash_heap[85]),
  /*  79 */  Make_header(2, 0, Color_white),
  /*  80 */  Val_flash_block(&ocaml_flash_heap[83]),
  /*  81 */  Val_int(6),
  /*  82 */  Make_header(1, String_tag, Color_white),
  /*  83 */  Make_string_data('s', 'i', 'x', '\0', '\0', '\0', '\0', '\4'),
  /*  84 */  Make_header(2, 0, Color_white),
  /*  85 */  Val_flash_block(&ocaml_flash_heap[88]),
  /*  86 */  Val_flash_block(&ocaml_flash_heap[93]),
  /*  87 */  Make_header(2, 0, Color_white),
  /*  88 */  Val_flash_block(&ocaml_flash_heap[91]),
  /*  89 */  Val_int(7),
  /*  90 */  Make_header(1, String_tag, Color_white),
  /*  91 */  Make_string_data('s', 'e', 'p', 't', '\0', '\0', '\0', '\3'),
  /*  92 */  Make_header(2, 0, Color_white),
  /*  93 */  Val_flash_block(&ocaml_flash_heap[96]),
  /*  94 */  Val_flash_block(&ocaml_flash_heap[101]),
  /*  95 */  Make_header(2, 0, Color_white),
  /*  96 */  Val_flash_block(&ocaml_flash_heap[99]),
  /*  97 */  Val_int(8),
  /*  98 */  Make_header(1, String_tag, Color_white),
  /*  99 */  Make_string_data('h', 'u', 'i', 't', '\0', '\0', '\0', '\3'),
  /* 100 */  Make_header(2, 0, Color_white),
  /* 101 */  Val_flash_block(&ocaml_flash_heap[104]),
  /* 102 */  Val_flash_block(&ocaml_flash_heap[109]),
  /* 103 */  Make_header(2, 0, Color_white),
  /* 104 */  Val_flash_block(&ocaml_flash_heap[107]),
  /* 105 */  Val_int(9),
  /* 106 */  Make_header(1, String_tag, Color_white),
  /* 107 */  Make_string_data('n', 'e', 'u', 'f', '\0', '\0', '\0', '\3'),
  /* 108 */  Make_header(2, 0, Color_white),
  /* 109 */  Val_flash_block(&ocaml_flash_heap[112]),
  /* 110 */  Val_flash_block(&ocaml_flash_heap[117]),
  /* 111 */  Make_header(2, 0, Color_white),
  /* 112 */  Val_flash_block(&ocaml_flash_heap[115]),
  /* 113 */  Val_int(10),
  /* 114 */  Make_header(1, String_tag, Color_white),
  /* 115 */  Make_string_data('d', 'i', 'x', '\0', '\0', '\0', '\0', '\4'),
  /* 116 */  Make_header(2, 0, Color_white),
  /* 117 */  Val_flash_block(&ocaml_flash_heap[120]),
  /* 118 */  Val_flash_block(&ocaml_flash_heap[125]),
  /* 119 */  Make_header(2, 0, Color_white),
  /* 120 */  Val_flash_block(&ocaml_flash_heap[123]),
  /* 121 */  Val_int(11),
  /* 122 */  Make_header(1, String_tag, Color_white),
  /* 123 */  Make_string_data('o', 'n', 'z', 'e', '\0', '\0', '\0', '\3'),
  /* 124 */  Make_header(2, 0, Color_white),
  /* 125 */  Val_flash_block(&ocaml_flash_heap[128]),
  /* 126 */  Val_unit,
  /* 127 */  Make_header(2, 0, Color_white),
  /* 128 */  Val_flash_block(&ocaml_flash_heap[131]),
  /* 129 */  Val_int(12),
  /* 130 */  Make_header(1, String_tag, Color_white),
  /* 131 */  Make_string_data('d', 'o', 'u', 'z', 'e', '\0', '\0', '\2'),
  /* 132 */  Make_header(2, Object_tag, Color_white),
  /* 133 */  Val_flash_block(&ocaml_flash_heap[136]),
  /* 134 */  Val_int(-7),
  /* 135 */  Make_header(2, String_tag, Color_white),
  /* 136 */  Make_string_data('N', 'o', 't', '_', 'f', 'o', 'u', 'n'),
  /* 137 */  Make_string_data('d', '\0', '\0', '\0', '\0', '\0', '\0', '\6'),
  /* 138 */  Make_header(1, Closure_tag, Color_white),
  /* 139 */  Val_codeptr(135),
  /* 140 */  Make_header(1, Closure_tag, Color_white),
  /* 141 */  Val_codeptr(22),
  /* 142 */  Make_header(1, Closure_tag, Color_white),
  /* 143 */  Val_codeptr(51)
};

PROGMEM value const ocaml_initial_static_heap[OCAML_STATIC_HEAP_WOSIZE] = {
  /*  0 */  Make_header(4, 0, Color_white),
  /*  1 */  Val_int(12),
  /*  2 */  Val_static_block(&ocaml_ram_heap[6]),
  /*  3 */  Val_unit,
  /*  4 */  Val_int(16),
  /*  5 */  Make_header(16, 0, Color_white),
  /*  6 */  Val_unit,
  /*  7 */  Val_unit,
  /*  8 */  Val_static_block(&ocaml_ram_heap[23]),
  /*  9 */  Val_static_block(&ocaml_ram_heap[27]),
  /* 10 */  Val_unit,
  /* 11 */  Val_static_block(&ocaml_ram_heap[31]),
  /* 12 */  Val_unit,
  /* 13 */  Val_static_block(&ocaml_ram_heap[35]),
  /* 14 */  Val_static_block(&ocaml_ram_heap[47]),
  /* 15 */  Val_static_block(&ocaml_ram_heap[63]),
  /* 16 */  Val_unit,
  /* 17 */  Val_unit,
  /* 18 */  Val_static_block(&ocaml_ram_heap[67]),
  /* 19 */  Val_unit,
  /* 20 */  Val_unit,
  /* 21 */  Val_unit,
  /* 22 */  Make_header(3, 0, Color_white),
  /* 23 */  Val_flash_block(&ocaml_flash_heap[107]),
  /* 24 */  Val_int(9),
  /* 25 */  Val_unit,
  /* 26 */  Make_header(3, 0, Color_white),
  /* 27 */  Val_flash_block(&ocaml_flash_heap[123]),
  /* 28 */  Val_int(11),
  /* 29 */  Val_unit,
  /* 30 */  Make_header(3, 0, Color_white),
  /* 31 */  Val_flash_block(&ocaml_flash_heap[67]),
  /* 32 */  Val_int(4),
  /* 33 */  Val_unit,
  /* 34 */  Make_header(3, 0, Color_white),
  /* 35 */  Val_flash_block(&ocaml_flash_heap[91]),
  /* 36 */  Val_int(7),
  /* 37 */  Val_static_block(&ocaml_ram_heap[39]),
  /* 38 */  Make_header(3, 0, Color_white),
  /* 39 */  Val_flash_block(&ocaml_flash_heap[83]),
  /* 40 */  Val_int(6),
  /* 41 */  Val_static_block(&ocaml_ram_heap[43]),
  /* 42 */  Make_header(3, 0, Color_white),
  /* 43 */  Val_flash_block(&ocaml_flash_heap[75]),
  /* 44 */  Val_int(5),
  /* 45 */  Val_unit,
  /* 46 */  Make_header(3, 0, Color_white),
  /* 47 */  Val_flash_block(&ocaml_flash_heap[131]),
  /* 48 */  Val_int(12),
  /* 49 */  Val_static_block(&ocaml_ram_heap[51]),
  /* 50 */  Make_header(3, 0, Color_white),
  /* 51 */  Val_flash_block(&ocaml_flash_heap[115]),
  /* 52 */  Val_int(10),
  /* 53 */  Val_static_block(&ocaml_ram_heap[55]),
  /* 54 */  Make_header(3, 0, Color_white),
  /* 55 */  Val_flash_block(&ocaml_flash_heap[59]),
  /* 56 */  Val_int(3),
  /* 57 */  Val_static_block(&ocaml_ram_heap[59]),
  /* 58 */  Make_header(3, 0, Color_white),
  /* 59 */  Val_flash_block(&ocaml_flash_heap[51]),
  /* 60 */  Val_int(2),
  /* 61 */  Val_unit,
  /* 62 */  Make_header(3, 0, Color_white),
  /* 63 */  Val_flash_block(&ocaml_flash_heap[43]),
  /* 64 */  Val_int(1),
  /* 65 */  Val_unit,
  /* 66 */  Make_header(3, 0, Color_white),
  /* 67 */  Val_flash_block(&ocaml_flash_heap[99]),
  /* 68 */  Val_int(8),
  /* 69 */  Val_unit
};

PROGMEM value const ocaml_initial_stack[OCAML_STACK_INITIAL_WOSIZE] = {
  /* 0 */  Val_flash_block(&ocaml_flash_heap[35]),
  /* 1 */  Val_flash_block(&ocaml_flash_heap[37])
};

PROGMEM value const ocaml_flash_global_data[OCAML_FLASH_GLOBDATA_NUMBER] = {
  /* 0 */  Val_flash_block(&ocaml_flash_heap[133]),
  /* 1 */  Val_flash_block(&ocaml_flash_heap[139]),
  /* 2 */  Val_flash_block(&ocaml_flash_heap[141]),
  /* 3 */  Val_static_block(&ocaml_ram_heap[1]),
  /* 4 */  Val_flash_block(&ocaml_flash_heap[143])
};

value acc = Val_flash_block(&ocaml_flash_heap[33]);
value env = Val_unit;

#define OCAML_Out_of_memory        Val_flash_block(&ocaml_flash_heap[2])
#define OCAML_Failure              Val_flash_block(&ocaml_flash_heap[8])
#define OCAML_Invalid_argument     Val_flash_block(&ocaml_flash_heap[13])
#define OCAML_Division_by_zero     Val_flash_block(&ocaml_flash_heap[20])
#define OCAML_Stack_overflow       Val_flash_block(&ocaml_flash_heap[27])

#define OCAML_atom0                Val_flash_block(&ocaml_flash_heap[1])

PROGMEM opcode_t const ocaml_bytecode[OCAML_BYTECODE_BSIZE] = {
  /*   0 */  OCAML_BRANCH_2B, 0, 174,
  /*   3 */  OCAML_RESTART,
  /*   4 */  OCAML_GRAB, 1,
  /*   6 */  OCAML_ACC1,
  /*   7 */  OCAML_BRANCHIFNOT_1B, 12,
  /*   9 */  OCAML_ACC1,
  /*  10 */  OCAML_GETFIELD0,
  /*  11 */  OCAML_PUSHACC1,
  /*  12 */  OCAML_APPLY1,
  /*  13 */  OCAML_ACC1,
  /*  14 */  OCAML_GETFIELD1,
  /*  15 */  OCAML_PUSHACC1,
  /*  16 */  OCAML_PUSHOFFSETCLOSURE0,
  /*  17 */  OCAML_APPTERM2, 4,
  /*  19 */  OCAML_RETURN, 2,
  /*  21 */  OCAML_RESTART,
  /*  22 */  OCAML_GRAB, 1,
  /*  24 */  OCAML_ACC1,
  /*  25 */  OCAML_BRANCHIFNOT_1B, 22,
  /*  27 */  OCAML_ACC1,
  /*  28 */  OCAML_GETFIELD0,
  /*  29 */  OCAML_PUSHACC2,
  /*  30 */  OCAML_GETFIELD1,
  /*  31 */  OCAML_PUSHACC3,
  /*  32 */  OCAML_GETFIELD2,
  /*  33 */  OCAML_PUSHACC2,
  /*  34 */  OCAML_PUSHACC4,
  /*  35 */  OCAML_C_CALL2, 0,
  /*  37 */  OCAML_BRANCHIF_1B, 5,
  /*  39 */  OCAML_ACC1,
  /*  40 */  OCAML_RETURN, 5,
  /*  42 */  OCAML_ACC0,
  /*  43 */  OCAML_PUSHACC4,
  /*  44 */  OCAML_PUSHOFFSETCLOSURE0,
  /*  45 */  OCAML_APPTERM2, 7,
  /*  47 */  OCAML_GETFLASHGLOBAL_1B, 0,
  /*  49 */  OCAML_RAISE,
  /*  50 */  OCAML_RESTART,
  /*  51 */  OCAML_GRAB, 1,
  /*  53 */  OCAML_ACC1,
  /*  54 */  OCAML_PUSHACC1,
  /*  55 */  OCAML_PUSHGETFLASHGLOBAL_1B, 1,
  /*  57 */  OCAML_APPLY2,
  /*  58 */  OCAML_PUSHACC1,
  /*  59 */  OCAML_GETFIELD1,
  /*  60 */  OCAML_C_CALL2, 1,
  /*  62 */  OCAML_PUSH,
  /*  63 */  OCAML_BRANCHIFNOT_1B, 68,
  /*  65 */  OCAML_ACC0,
  /*  66 */  OCAML_GETFIELD0,
  /*  67 */  OCAML_PUSHACC1,
  /*  68 */  OCAML_GETFIELD1,
  /*  69 */  OCAML_PUSHACC2,
  /*  70 */  OCAML_GETFIELD2,
  /*  71 */  OCAML_PUSHACC2,
  /*  72 */  OCAML_PUSHACC6,
  /*  73 */  OCAML_C_CALL2, 0,
  /*  75 */  OCAML_BRANCHIF_1B, 5,
  /*  77 */  OCAML_ACC1,
  /*  78 */  OCAML_RETURN, 6,
  /*  80 */  OCAML_ACC0,
  /*  81 */  OCAML_BRANCHIFNOT_1B, 47,
  /*  83 */  OCAML_ACC0,
  /*  84 */  OCAML_GETFIELD0,
  /*  85 */  OCAML_PUSHACC1,
  /*  86 */  OCAML_GETFIELD1,
  /*  87 */  OCAML_PUSHACC2,
  /*  88 */  OCAML_GETFIELD2,
  /*  89 */  OCAML_PUSHACC2,
  /*  90 */  OCAML_PUSHACC, 9,
  /*  92 */  OCAML_C_CALL2, 0,
  /*  94 */  OCAML_BRANCHIF_1B, 5,
  /*  96 */  OCAML_ACC1,
  /*  97 */  OCAML_RETURN, 9,
  /*  99 */  OCAML_ACC0,
  /* 100 */  OCAML_BRANCHIFNOT_1B, 25,
  /* 102 */  OCAML_ACC0,
  /* 103 */  OCAML_GETFIELD0,
  /* 104 */  OCAML_PUSHACC1,
  /* 105 */  OCAML_GETFIELD1,
  /* 106 */  OCAML_PUSHACC2,
  /* 107 */  OCAML_GETFIELD2,
  /* 108 */  OCAML_PUSHACC2,
  /* 109 */  OCAML_PUSHACC, 12,
  /* 111 */  OCAML_C_CALL2, 0,
  /* 113 */  OCAML_BRANCHIF_1B, 5,
  /* 115 */  OCAML_ACC1,
  /* 116 */  OCAML_RETURN, 12,
  /* 118 */  OCAML_ACC0,
  /* 119 */  OCAML_PUSHACC, 12,
  /* 121 */  OCAML_PUSHGETFLASHGLOBAL_1B, 2,
  /* 123 */  OCAML_APPTERM2, 14,
  /* 125 */  OCAML_GETFLASHGLOBAL_1B, 0,
  /* 127 */  OCAML_RAISE,
  /* 128 */  OCAML_GETFLASHGLOBAL_1B, 0,
  /* 130 */  OCAML_RAISE,
  /* 131 */  OCAML_GETFLASHGLOBAL_1B, 0,
  /* 133 */  OCAML_RAISE,
  /* 134 */  OCAML_RESTART,
  /* 135 */  OCAML_GRAB, 1,
  /* 137 */  OCAML_ACC0,
  /* 138 */  OCAML_GETFIELD1,
  /* 139 */  OCAML_VECTLENGTH,
  /* 140 */  OCAML_OFFSETINT_1B, (opcode_t) -1,
  /* 142 */  OCAML_PUSHACC2,
  /* 143 */  OCAML_PUSHACC2,
  /* 144 */  OCAML_GETFIELD2,
  /* 145 */  OCAML_PUSHCONSTINT_1B, 100,
  /* 147 */  OCAML_PUSHCONSTINT_1B, 10,
  /* 149 */  OCAML_C_CALL4, 2,
  /* 151 */  OCAML_ANDINT,
  /* 152 */  OCAML_RETURN, 2,
  /* 154 */  OCAML_ACC0,
  /* 155 */  OCAML_GETFIELD1,
  /* 156 */  OCAML_PUSHACC1,
  /* 157 */  OCAML_GETFIELD0,
  /* 158 */  OCAML_PUSH,
  /* 159 */  OCAML_C_CALL1, 3,
  /* 161 */  OCAML_ACC1,
  /* 162 */  OCAML_C_CALL1, 4,
  /* 164 */  OCAML_ACC0,
  /* 165 */  OCAML_PUSHGETFLASHGLOBAL_1B, 3,
  /* 167 */  OCAML_PUSHGETFLASHGLOBAL_1B, 4,
  /* 169 */  OCAML_APPLY2,
  /* 170 */  OCAML_C_CALL1, 4,
  /* 172 */  OCAML_RETURN, 3,
  /* 174 */  OCAML_APPLY2,
  /* 175 */  OCAML_POP, 1,
  /* 177 */  OCAML_STOP
};

#include </usr/local/include/omicrob/vm/runtime.c>

PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER] = {
  /*  0 */  (void *) &caml_compare,
  /*  1 */  (void *) &caml_array_get_addr,
  /*  2 */  (void *) &caml_hash,
  /*  3 */  (void *) &caml_debug_trace,
  /*  4 */  (void *) &caml_debug_tracei,
};
