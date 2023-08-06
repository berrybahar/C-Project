.entry LENGTH
.entry loop1
.extern W
MAIN: mov @r3 ,LENGTH
loop1: jmp L1
prn -5
bne W
sub @r1, @r4
bne L3
L1: inc K
jmp W
END: stop
STR: .string "abcdef"
LENGTH: .data 6,-9,15
K: .data 22
.extern L3
