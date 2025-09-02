# 🖥️ Mini Compilador con Generador de Ensamblador

Este proyecto implementa un **mini compilador** que traduce un lenguaje fuente sencillo a **pseudo-ensamblador** y luego a **ensamblador x86-64**.
Incluye toda la cadena de compilación: **análisis léxico**, **análisis sintáctico**, **chequeos semánticos** (tablas de símbolos, verificación de tipos) y **generación de código en ensamblador**.

## 📚 Descripción General

El compilador está construido con **Lex** y **Yacc** para el análisis léxico y sintáctico, y utiliza módulos en C para:

* **Construcción del AST** (`tree.c`)
* **Gestión de la Tabla de Símbolos** (`symbols_table.c`)
* **Análisis Semántico y Manejo de Errores** (`errors_manager.c`)
* **Generación de Código de Tres Direcciones** (`pseudo_assembly.c`)
* **Generación de Código en Ensamblador** (`assembly_generator.c`)

El resultado final es un archivo `output.s` que contiene código ensamblador x86-64, listo para ensamblarse y enlazarse en un ejecutable.

---

## 🛠️ Instalación y Compilación

### Requisitos

* **Flex** y **Bison** (o Lex/Yacc equivalentes)
* **GCC** o Clang (para compilar el código en C)
* **Make** (opcional, si quieres automatizar la construcción con Makefile)

### Instrucciones de Compilación

```bash
#Ejecutar el script ya armado
sh script
```

---

## ▶️ Uso

Ejecuta el compilador pasando el archivo fuente como entrada:

```bash
./project entrada.txt
```

Esto generará:

* `output.s` → archivo con código ensamblador
* Salida en consola con posibles errores semánticos, tabla de símbolos y pseudo-ensamblador generado (modo de depuración)

Para ensamblar y ejecutar:

```bash
gcc output.s -o programa
./programa
```

---

## 📂 Estructura del Proyecto y Descripción de Archivos

| Archivo                   | Función                                                                                                                                                              |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **calc-lexico.l**         | Define los tokens y expresiones regulares para el análisis léxico (palabras clave, identificadores, números, operadores).                                            |
| **calc-sintaxis.y**       | Implementa las reglas gramaticales, construye el árbol de sintaxis abstracta (AST) e invoca las rutinas semánticas.                                                  |
| **tree.c**                | Define los nodos del AST y las rutinas de recorrido. Maneja la creación de scopes, asignación de offsets, chequeo de tipos y validación de `return`, `if` y `while`. |
| **symbols\_table.c**      | Implementa la tabla de símbolos jerárquica con soporte para scopes anidados. Incluye creación, búsqueda y registro de parámetros.                                    |
| **errors\_manager.c**     | Centraliza el manejo de errores semánticos: variables no declaradas, incompatibilidad de tipos, número incorrecto de argumentos en llamadas a función.               |
| **pseudo\_assembly.c**    | Genera código de tres direcciones (TAC), administra la lista de instrucciones, temporales y prepara el código para el generador de ensamblador.                      |
| **assembly\_generator.c** | Convierte el pseudo-ensamblador a instrucciones reales x86-64: prólogo/epílogo de funciones, operaciones aritméticas, saltos y definición de variables globales.     |
| **script**                | Script auxiliar para automatizar la compilación/ejecución (puedes documentar su uso en esta sección).                                                                |

## ✅ Características

* **Tabla de símbolos con scopes anidados**
* **Chequeo de tipos** para operaciones aritméticas, booleanas y condicionales
* **Validación de returns** en funciones (detecta faltantes o redundantes)
* **Verificación de llamadas a funciones** (cantidad y tipo de argumentos)
* **Generación de código de tres direcciones** con etiquetas y saltos
* **Generación de código ensamblador x86-64** listo para ensamblar y ejecutar