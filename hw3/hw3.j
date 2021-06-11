.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
ldc 0
istore 0
iload 0
ldc 0
istore 0
iload 0
ldc 10
isub
iload 0
ldc 1
iadd
istore 0
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\n"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 0
ldc 1
istore 0
while_loop0:
iload 0
ldc 0
isub
ifgt L_gtr0_1
L_gtr0_0:
iconst_0
goto exit_gtr0_cmp
L_gtr0_1:
iconst_1
exit_gtr0_cmp:
ifeq exit_while0
iload 0
ldc 1
isub
istore 0
ldc 3
newarray int
astore 1
aload 1
ldc 0
ldc 1
ldc 21
iadd
iastore
aload 1
ldc 1
aload 1
ldc 0
iaload
ldc 1
isub
iastore
aload 1
ldc 2
aload 1
ldc 1
iaload
ldc 3
idiv
iastore
aload 1
ldc 2
iaload
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\n"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 3
ldc 4
ldc 5
ldc 8
ineg
iadd
imul
isub
ldc 10
ldc 7
idiv
isub
ldc 4
ineg
ldc 3
irem
isub
ifgt L_gtr1_1
L_gtr1_0:
iconst_0
goto exit_gtr1_cmp
L_gtr1_1:
iconst_1
exit_gtr1_cmp:
iconst_1
iconst_1
ixor
iconst_0
iconst_1
ixor
iconst_1
ixor
iand
ior
ifeq FALSE_0
TRUE_0:
ldc "true"
goto exit_printbool0
FALSE_0:
ldc "false"
exit_printbool0:
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc "\n"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 3
newarray float
astore 2
aload 2
ldc 0
ldc 1.100000
ldc 2.100000
fadd
fastore
aload 2
ldc 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\n"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto while_loop0
exit_while0:
ldc 0
istore 3
iload 3
ldc 10
while_loop1:
iload 3
ldc 0
isub
ifgt L_gtr2_1
L_gtr2_0:
iconst_0
goto exit_gtr2_cmp
L_gtr2_1:
iconst_1
exit_gtr2_cmp:
ifeq exit_while1
iload 3
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\t"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 3
ldc 1
isub
istore 3
iload 3
ldc 0
isub
ldc 3.140000
fstore 4
fload 4
iload 3
iadd
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc 6.600000
fstore 5
ldc "If x == "
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
fload 5
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(F)V
ldc 1
istore 6
while_loop2:
iload 6
ldc 3
isub
ifeq exit_while2
ldc "\t"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 3
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "*"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 6
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "="
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 3
iload 6
imul
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\t"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 6
ldc 1
iadd
istore 6
goto while_loop2
exit_while2:
ldc "\n"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto while_loop1
exit_while1:
	return
.end method
