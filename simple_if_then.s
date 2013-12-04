.data
user_input: .word 0
readspace: .asciiz "read: "
writespace: .asciiz "write: "
space: .asciiz "\n"


###DECLARE VARIABLES##
output: .word 0 

###DECLARE VARIABLES##
input: .word 0 


###DECLARE VARIABLES##
greater: .word 0 

###DECLARE VARIABLES##
y: .word 0 

###DECLARE VARIABLES##
x: .word 0 

.text
.globl main
 main:


### ADDING AN ID TO THE STACK ####
lw	 $t0, x	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, x	 #load address of var into t0

### READ INPUT ###
li	$v0, 4	#print instruction
la	$a0, readspace	#put the message to be print
syscall	
li	$v0, 5	#accept input instruction
syscall	
sw	$v0, ($t0)	#add value to variable
li	$v0, 4	#print instruction
la	$a0, space	#put the message to be print
syscall	


### ADDING AN ID TO THE STACK ####
lw	 $t0, y	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, y	 #load address of var into t0

### READ INPUT ###
li	$v0, 4	#print instruction
la	$a0, readspace	#put the message to be print
syscall	
li	$v0, 5	#accept input instruction
syscall	
sw	$v0, ($t0)	#add value to variable
li	$v0, 4	#print instruction
la	$a0, space	#put the message to be print
syscall	


### ADDING AN ID TO THE STACK ####
lw	 $t0, x	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, x	 #load address of var into t0

### ADDING AN ID TO THE STACK ####
lw	 $t0, y	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, y	 #load address of var into t0

### PERFORMING RELOP ###
lw	$t2, ($sp)	#pop 1st! (relop)
addu	$sp, $sp, 4	#move the ptr (relop)
lw	$t1, ($sp)	#pop 2nd!
subu	$sp, $sp, 4	#move the stack ptr
BEQ	$t1,$t2, IF	#is it equal?
slt	$t0, $t2,$t1	#is it greater than?
BEQ 	$t0, 0,ELSE	#go to else if not equal
IF: li	$t0, 1	#t0 holds 1
j	RES	#jump to result!
ELSE: li	$t0, 0	#t0 holds 0
RES: sw	$t0, ($sp)	#push!
sw	$t0, ($sp)	#push!


### ADDING AN ID TO THE STACK ####
lw	 $t0, x	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, x	 #load address of var into t0

###POP THE STACK FOR ASSIGNOP###
lw	$t0, ($sp)	#pop 1st!
addu	$sp, $sp, 4	#move the ptr
sw	$t0, greater	#add value to variable


### ADDING AN ID TO THE STACK ####
lw	 $t0, y	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, y	 #load address of var into t0

###POP THE STACK FOR ASSIGNOP###
lw	$t0, ($sp)	#pop 1st!
addu	$sp, $sp, 4	#move the ptr
sw	$t0, greater	#add value to variable


### IF THEN ELSE ###
lw	$t0, ($sp)	#pop 1st! (relop)


### PRINT THE RESULT ###
li	$v0, 1	#print instruction
move	$a0, $t0	#put the value to be print
syscall	


### ADDING AN ID TO THE STACK ####
lw	 $t0, greater	 #store value from id into t0
subu	 $sp, $sp, 4	 #move the stack ptr
sw	 $t0, ($sp)	 #push!
la	$t0, greater	 #load