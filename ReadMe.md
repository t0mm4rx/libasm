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
Return value: eax

Syscall IDs examples:
0 --> read
1 --> write
2 --> open
3 --> close

Flags --> single bit register
CF, PF, ZF, SF... 8 flags --> one 'flags' register 

RIP register --> contains the next instruction adress, auto increments after each instruction

CMP compares multiple variables, stores the result in flags

jmp <label> --> set RIP to the adress of given label
je --> jumps if equals
jne --> jumps if not equals
jg --> jumps if greater than
jge --> jumps if greater and equals to
jl --> jumps if smaller than
jle --> jumps if smaller or equels to
jz --> jumps if equals 0

Exemple of conditional jump :
cmp rax,23
je doThis

subroutine --> function
\_start:
	call \_function

\_function:
	mov rax,23
	ret

ret = return, goes back to the call adress

## Debug

lldb <binary file>

run --> run the program
register read --> print all registers
kill --> kill current thread
memory read -c<bytes> <memory> --> read <bytes> bytes from address <memory>

## Resources
- https://www.youtube.com/playlist?list=PLetF-YjXm-sCH6FrTz4AQhfH6INDQvQSn
- https://cs.lmu.edu/~ray/notes/nasmtutorial/
