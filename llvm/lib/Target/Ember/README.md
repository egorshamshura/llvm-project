# Ember ISA specification
## Registers
In 32bit and 64bit modes there are 32 registers: R0-R31 (64bit) and RH0-RH31 (32bit)
## Instructions
| Instruction            | Description    | Operation                    | Opcode   | Modes |
| ---------------------- | -------------- | ---------------------------- | -------- | ----- |
| ADD  x1 x2 x3          | 3 regs         | x1 = x2 + x3                 | 00000001 |       |      
| ADDi x1 x2 imm3        | 2 regs, 1 imm  | x1 = x2 + imm3               | 00000010 |       |
| SUB  x1 x2 x3          | 3 regs         | x1 = x2 - x3                 | 00000011 |       |
| SUBi x1 x2 imm3        | 2 regs, 1 imm  | x1 = x2 - imm3               | 00000100 |       |
| MUL  x1 x2 x3          | 3 regs         | x1 = x2 * x3                 | 00000101 |       |
| DIV  x1 x2 x3          | 3 regs         | x1 = x2 / x3                 | 00000110 |       |
| REM  x1 x2 x3          | 3 regs         | x1 = x2 % x3                 | 00000111 |       |
| AND  x1 x2 x3          | 3 regs         | x1 = x2 & x3                 | 00001000 |       |
| ANDi x1 x2 imm3        | 2 regs, 1 imm  | x1 = x2 & imm3               | 00001001 |       |
| XOR  x1 x2 x3          | 3 regs         | x1 = x2 ^ x3                 | 00001010 |       |   
| EQi  x1 x2 x3          | 2 regs, 1 imm  | x1 = (x2 == imm3)            | 00001011 |       |
| INC_NEi x1 x2 imm3     | 2 regs, 1 imm  | x1 = (++x2 != imm3)          | 00001100 |       |
| PUT_PIXEL x1 x2 x3     | 3 regs         | simPutPixel(x1, x2, x3)      | 00001101 |       | 
| ALLOC x1 imm2          | 1 reg,  1 imm  | x1 = alloc(imm2)             | 00001110 |       | 
| WRITE16 x1 x2 x3       | 3 regs         | *(x1 + x2) = x3 in 16bit     | 00001111 |       | 
| WRITE16ii x1 imm2 imm3 | 1 reg,  2 imm  | *(x1 + imm2) = imm3 in 16bit | 00010000 | 64bit | 
| WRITE16ri x1 x2 imm3   | 2 regs, 1 imm  | *(x1 + x2) = imm3 in 16bit   | 00010001 |       |
| READ16 x1 x2 x3        | 3 regs         | x1 = *(x2 + x3) in 16bit     | 00010010 |       |  
| RAND16 x1              | 1 reg          | x1 = rand()     in 16bit     | 00010011 |       |
| WRITE32 x1 x2 x3       | 3 regs         | *(x1 + x2) = x3 in 32bit     | 00010100 |       | 
| WRITE32ii x1 imm2 imm3 | 1 reg,  2 imm  | *(x1 + imm2) = imm3 in 32bit | 00010101 |   -   | 
| WRITE32ri x1 x2 imm3   | 2 regs, 1 imm  | *(x1 + x2) = imm3 in 32bit   | 00010110 |       |
| READ32 x1 x2 x3        | 3 regs         | x1 = *(x2 + x3) in 32bit     | 00010111 |       |  
| RAND32 x1              | 1 reg          | x1 = rand()     in 32bit     | 00011000 |       |  
| DUMP x1                | 1 reg          | writes in console x1         | 00011001 |       | 
| FLUSH                  | 0 reg          | simFlush()                   | 00011010 |       | 
| BR_COND x1 label       | 1 reg, 1 label | if (x1) nextPC = label       | 00011011 |       | 
| EXIT                   | 0 reg          | returns void from func       | 00011100 |       | 
