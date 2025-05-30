# Memory Layout Analysis

## Variables by Memory Section

### .data/.rodata Section (Initialized Static Data)
| Variable | Address | Type |
|----------|---------|------|
| MAX_INPUTS | 0x402008 | const int * |
| mask_descr | 0x404068 | const char ** |
| last_result | 0x4040ac | unsigned int * |

### Stack Section
| Variable | Address | Type |
|----------|---------|------|
| count | 0x7fffffffdd70 | int * |
| n | 0x7fffffffdd78 | unsigned int * |
| masked | 0x7fffffffdd7c | unsigned int * |
| resuts | 0x7fffffffdd80 | unsigned int (*)[4] |
| inputs | 0x7fffffffdd90 | char *(*)[4] |
| buffer | 0x7fffffffddb0 | char (*)[256] |

### Memory Regions
| Region | Start Address | End Address | Size |
|--------|--------------|-------------|------|
| Heap | 0x405000 | 0x426000 | 0x21000 (135 KB) |
| Stack | 0x7ffffffde000 | 0x7ffffffff000 | 0x21000 (135 KB) |

## Visual Memory Layout
```
High Addresses
+----------------------+ 0x7ffffffff000
|                      |
|        Stack         |
|                      |
+----------------------+ 0x7ffffffde000
           ...
Low Addresses
+----------------------+ 0x426000
|                      |
|         Heap         |
|                      |
+----------------------+ 0x405000
           ...
+----------------------+ 0x4040ac
| last_result          |
+----------------------+
           ...
+----------------------+ 0x404068
| mask_descr           |
+----------------------+
           ...
+----------------------+ 0x402008
| MAX_INPUTS           |
+----------------------+
```
