# Ember ISA specification
## Registers
In 32bit and 64bit modes there are 32 registers: R0-R31 (64bit) and RH0-RH31 (32bit)
## Instructions
| Instruction            | Description    | Operation                    | Opcode | Modes |
| ---------------------- | -------------- | ---------------------------- | ------ | ----- |
| ADD  x1 x2 x3          | 3 regs         | x1 = x2 + x3                 | 000001 |       |      
| ADDi x1 x2 imm3        | 2 regs, 1 imm  | x1 = x2 + imm3               | 000010 |       |
| SUB  x1 x2 x3          | 3 regs         | x1 = x2 - x3                 | 000011 |       |
| SUBi x1 x2 imm3        | 2 regs, 1 imm  | x1 = x2 - imm3               | 000100 |       |
| MUL  x1 x2 x3          | 3 regs         | x1 = x2 * x3                 | 000101 |       |
| DIV  x1 x2 x3          | 3 regs         | x1 = x2 / x3                 | 000110 |       |
| REM  x1 x2 x3          | 3 regs         | x1 = x2 % x3                 | 000111 |       |
| AND  x1 x2 x3          | 3 regs         | x1 = x2 & x3                 | 001000 |       |
| ANDi x1 x2 imm3        | 2 regs, 1 imm  | x1 = x2 & imm3               | 001001 |       |
| XOR  x1 x2 x3          | 3 regs         | x1 = x2 ^ x3                 | 001010 |       |   
| EQi  x1 x2 x3          | 2 regs, 1 imm  | x1 = (x2 == imm3)            | 001011 |       |
| INC_NEi x1 x2 imm3     | 2 regs, 1 imm  | x1 = (++x2 != imm3)          | 001100 |       |
| PUT_PIXEL x1 x2 x3     | 3 regs         | simPutPixel(x1, x2, x3)      | 001101 |       | 
| ALLOC x1 imm2          | 1 reg,  1 imm  | x1 = alloc(imm2)             | 001110 |       | 
| WRITE16 x1 x2 x3       | 3 regs         | *(x1 + x2) = x3 in 16bit     | 001111 |       | 
| WRITE16ii x1 imm2 imm3 | 1 reg,  2 imm  | *(x1 + imm2) = imm3 in 16bit | 010000 | 64bit | 
| WRITE16ri x1 x2 imm3   | 2 regs, 1 imm  | *(x1 + x2) = imm3 in 16bit   | 010001 |       |
| READ16 x1 x2 x3        | 3 regs         | x1 = *(x2 + x3) in 16bit     | 010010 |       |  
| RAND16 x1              | 1 reg          | x1 = rand()     in 16bit     | 010011 |       |
| WRITE32 x1 x2 x3       | 3 regs         | *(x1 + x2) = x3 in 32bit     | 010100 |       | 
| WRITE32ii x1 imm2 imm3 | 1 reg,  2 imm  | *(x1 + imm2) = imm3 in 32bit | 010101 |   -   | 
| WRITE32ri x1 x2 imm3   | 2 regs, 1 imm  | *(x1 + x2) = imm3 in 32bit   | 010110 |       |
| READ32 x1 x2 x3        | 3 regs         | x1 = *(x2 + x3) in 32bit     | 010111 |       |  
| RAND32 x1              | 1 reg          | x1 = rand()     in 32bit     | 011000 |       |  
| DUMP x1                | 1 reg          | writes in console x1         | 011001 |       | 
| FLUSH                  | 0 reg          | simFlush()                   | 011010 |       | 
| BR_COND x1 label       | 1 reg, 1 label | if (x1) nextPC = label       | 011011 |       | 
| EXIT                   | 0 reg          | returns void from func       | 011100 |       | 
