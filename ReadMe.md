# LibASM

## Notes

rsp --> adress of the top of the stack
[addr] --> ptr, not value
push reg --> push reg value on the top of the stack
pop reg --> pop value out of the stack in reg
mov reg, [rsp] --> copy top value of the stack in reg

var db byte,byte,"ascii string",byte

Registers sizes :
(last bits)
- 64bits --> rax
- 32bits --> eax
- 16bits --> ax
- 8bits --> al

Syscall --> call function from kernel (OS)
Syscall ID: rax
Arg1: rdi
Arg2: rsi
Arg3: rdx
Arg4: r10
Arg5: r8
Arg6: r9

Syscall IDs examples:
0 --> read
1 --> write
2 --> open
3 --> close

## Resources
- https://www.youtube.com/playlist?list=PLetF-YjXm-sCH6FrTz4AQhfH6INDQvQSn
- https://cs.lmu.edu/~ray/notes/nasmtutorial/
