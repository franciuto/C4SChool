# Data location in the memory

| Memory Segment | Variables/Data                                                          | Sizes                                                                                                                                  |
| -------------- | ----------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| `.rodata`      | `MAX_INPUTS`, `*mask_descr`, `*s`                                       | 4 bytes, 39 bytes (string), 8 bytes (pointer)                                                                                          |
| `.data`        | `mask_descr`                                                            | 8 bytes (pointer)                                                                                                                      |
| `.bss`         | `last_result`                                                           | 4 bytes                                                                                                                                |
| `stack`        | `s`, `i`, `val`, `*inputs`, `results`, `count`, `buffer`, `n`, `masked` | 8 bytes (pointer), 4 bytes, 4 bytes, 32 bytes (array of 4 pointers), 16 bytes (array of 4 uints), 4 bytes, 256 bytes, 4 bytes, 4 bytes |
