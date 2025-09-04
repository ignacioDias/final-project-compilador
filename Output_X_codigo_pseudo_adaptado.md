# Conversión de Código a Assembly

## Input 1

**Código:**

```c
Program {
    void main() {
        int a;
        a = 3;
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ main
ASIGN a 3 a
RETURN      
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $32, %rsp 
	movl $3, -16(%rbp)
	addq $32, %rsp 
	popq    %rbp
	ret
```
    
## Input 2

**Código:**

```c
Program {
    int main() {
        int a;
        a = 3;
        if(false) then { //acá se rompe al poner una operación booleana
            return a;
        }
        return a;
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ main
ASIGN a 3 a
T_IFF false _ L1
RETURN     a
T_LABEL _ _ \81f\88X <-- ERROR, se genera mal
RETURN     a
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $32, %rsp 
	movl $3, -16(%rbp)
	movl $0, %eax
	cmpl $1, %eax
	jne L1
	movl -16(%rbp),  %eax
	addq $32, %rsp 
	popq    %rbp
	ret


\81f\88X: <--- Se buguea la etiqueta
	movl -16(%rbp),  %eax
	addq $32, %rsp 
	popq    %rbp
	ret
```
    
## Input 3

**Código:**

```c
Program {
    int main() {
        int a;
        a = 3;
        if(true) then {
            return a;
        } else {
            return a;
        }
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ main
ASIGN a 3 a
T_IFF true _ L1
RETURN     a
T_JUMP _ _ L2
T_LABEL _ _ x\AD>e
RETURN     a
T_LABEL _ _ L2
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $32, %rsp 
	movl $3, -16(%rbp)
	movl $1, %eax
	cmpl $1, %eax
	jne L1
	movl -16(%rbp),  %eax
	addq $32, %rsp 
	popq    %rbp
	ret
	jmp L2


x\AD>e: <--- se buguea de vuelta 
	movl -16(%rbp),  %eax
	addq $32, %rsp 
	popq    %rbp
	ret

L2: <-- etiqueta vacía
```
## Input 4

**Código:**

```c
Program {
    void main() {
        int a;
        a = 3;
        while(true) { //se buguean las condiciones, solo se pueden true/false, tampoco puedo hacer bool x = ...
            a = a + 1;
        }
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ main
ASIGN a 3 a
T_LABEL _ _ L1
T_WF true _ L2
PLUS a 1 +
ASIGN a + a
T_JUMP _ _ L1
T_LABEL _ _ L2
RETURN      
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $48, %rsp 
	movl $3, -16(%rbp)


L1: 
	movl $1, %eax
	cmpl $1, %eax
	jne L2
	movl -32(%rbp), %eax

	movl %eax, -16(%rbp)

	jmp L1


L2: 
	addq $48, %rsp 
	popq    %rbp
	ret
```
    
## Input 5

**Código:**

```c
Program {
    int suma(int a, int b) {
        return a + b;
    }
    void main() {
        int a;
        a = suma(3, 2);
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ suma
T_REQUIRED_PARAM     a
T_REQUIRED_PARAM     b
PLUS a b +
RETURN     +
END_FUN _ _ suma
T_FUNC _ _ main
LOAD_PARAM _ _ 3
LOAD_PARAM _ _ 2
T_CALL suma _ FUNCTION_CALL
ASIGN a FUNCTION_CALL a
RETURN      
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
suma:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $64, %rsp 
	movl %edi, -16(%rbp)
	movl %esi, -32(%rbp)
	movl -48(%rbp),  %eax
	addq $64, %rsp 
	popq    %rbp
	ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $48, %rsp 
	movl $3, %edi
	movl $2, %esi
	call suma
	movl %eax, -32(%rbp)
	movl -32(%rbp), %eax

	movl %eax, -16(%rbp)

	addq $48, %rsp 
	popq    %rbp
	ret
```

## Input 6

**Código:**

```c
Program {
    int prinInt(int a) extern;
    void main() {
        int a;
        a = 3;
        prinInt(a);
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ main
ASIGN a 3 a
LOAD_PARAM _ _ a
T_CALL prinInt _ FUNCTION_CALL
RETURN      
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $48, %rsp 
	movl $3, -16(%rbp)
	movl -16(%rbp), %eax
	movl %eax, %edi
	call prinInt
	movl %eax, -32(%rbp)
	addq $48, %rsp 
	popq    %rbp
	ret
```
    
## Input 7

**Código:**

```c
Program {
    void main() {
        int x; //No podemos hacer int x; x = ...; int a; a = ...; tampoco podemos hacer int x = ...; 
        int a;
        x = 2;
        a = x + 2;
    }
}
```

**Instrucciones intermedias:**

```text
T_FUNC _ _ main
ASIGN x 2 x
PLUS x 2 +
ASIGN a + a
RETURN      
END_FUN _ _ main
```

**Código en ensamblador:**

```asm
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
	subq $64, %rsp 
	movl $2, -16(%rbp)
	movl -48(%rbp), %eax

	movl %eax, -32(%rbp)

	addq $64, %rsp 
	popq    %rbp
	ret
```

