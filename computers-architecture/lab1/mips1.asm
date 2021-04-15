.data
Y: .word 3 2 1 9 3 2 1 9
X: .word 3 2 1 9 8 0 0 4 -4 0 7 8 6 5 11 2
str0: .asciiz "\n{"
str1: .asciiz ","
str2: .asciiz "}" 
s: .word 16
x1: .word 3
x2: .word 14

.text
la $t0, X   #endereço 0x00400000
lw $t8, x1
lw $t9, x2
sll $t1, $t8, 2
sll $t2, $t9, 2
add $t1, $t0, $t1
add $t2, $t0, $t2
lw $t3, 0($t1)
lw $t4, 0($t2)
sw $t3, 0($t2)
sw $t4, 0($t1) 
la $t0, X
lw $t1, s
add $t3, $zero, $zero
addi $v0, $zero, 4
la $a0, str0
syscall
L3: j L1
j L3

L1:	beq $t1, $t3, L2 
	lw $t4, 0($t0) 
	addi $v0, $zero, 1
	add $a0, $zero, $t4
	syscall
	addi $v0, $zero, 4 
	la $a0, str1
	syscall
	addi $t0, $t0, 4
	addi $t3, $t3, 1
	j L1
L2:	addi $v0, $zero, 4
	la $a0, str2
	syscall