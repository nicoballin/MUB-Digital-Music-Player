# MUB Digital Music Player
Es el primer proyecto del ramo de Estructuras de Datos, el cual consiste en diseñar e implementar un sistema que simule el
funcionamiento de un reproductor de música, permitiendo generar, almacenar, ordenar y buscar información de canciones. 
Nuestro mejora planteada es implementar la reproducción de música. 

## Integrantes
**Ingeniería Civil en Computación e Informática** 
- [Nicolas Balic](mailto:nbalic@umagallanes.cl)
- [Tomas Minte](mailto:tminte@umagallanes.cl) 
- [Daniel Uribe](mailto:daniurib@umagallanes.cl) 

## Informacion
## Cómo compilar y ejecutar
 
Siempre desde la **carpeta raíz del proyecto** (donde está el `Makefile`):
 
```bash
make          # compila y deja el ejecutable en build/mub.out
make run      # ejecuta el reproductor
make clean    # borra obj/ y build/ (Borra el catálogo)
```
 
> ⚠️ El programa busca los archivos con rutas relativas (`build/catalogo.csv`), por lo que **debe ejecutarse desde la raíz del proyecto**. Si lo corres desde otra carpeta no encontrará el catálogo.
 
## ⚠️ Cosas a tener en consideración
 
### 1. La terminal debe soportar 256 colores y UTF-8
 
La interfaz usa colores de la paleta de 256 tonos (`\033[38;5;...m`) y símbolos Unicode (`◆ ━ ✦ ➤ ✔`). En una terminal sin soporte se verán secuencias raras como `←[38;5;213m` o cuadritos `?` en vez de los marcos.
 
Cómo comprobarlo:
 
```bash
echo $TERM      # debería decir algo como xterm-256color
locale          # debería mostrar UTF-8 (ej: es_CL.UTF-8 o en_US.UTF-8)
```
 
Si no está en UTF-8 o en 256 colores:
 
```bash
export TERM=xterm-256color
export LANG=en_US.UTF-8
```
 
| Terminal | ¿Funciona? |
|---|---|
| Terminal de Linux (GNOME Terminal, Konsole, Kitty, Alacritty…) | ✅ |
| Terminal de VS Code | ✅ |
| Windows Terminal + WSL | ✅ |
| macOS Terminal / iTerm2 | ✅ |
| `cmd.exe` clásico o PowerShell antiguo | ❌ (colores y símbolos rotos) |
 
Además, en el código **no se usa la letra ñ** (se reemplaza por `nh`, por ejemplo `Anho`) para evitar problemas de codificación.
 
### 2. El catálogo CSV se genera una sola vez
 
La primera vez que ejecutas el programa **no existe catálogo**, así que te pide cuántas canciones generar (entre 1 y 5000) y las guarda en `data/catalogo.csv` (mezcladas con Fisher-Yates).
 
Desde la segunda ejecución **ya no se genera uno nuevo, se carga el existente**. Los archivos son dos:
 
| Archivo | Cuándo se crea |
|---|---|
| `data/catalogo.csv` | Al generar el catálogo por primera vez (catálogo base original) |
| `data/catalogo_actualizado.csv` | Al salir (opción `0`) o al exportar (opción `7`). Guarda el orden actual y las reproducciones acumuladas |
 
Al iniciar:
 
- Si existen **ambos**, el programa te pregunta cuál cargar (1 = base, 2 = actualizado).
- Si existe **solo uno**, lo carga directamente.
- Si no existe ninguno, genera uno nuevo.
- Si el archivo está vacío o dañado, te ofrece generar uno nuevo desde cero (o salir sin tocar nada).


## Buenas Practicas
### Convención de nombres
- **Funciones:** PascalCase_Con_Guion_Bajo(ej. Crear_Canciones)
- **Variables:** snake_case (ej. int cantidad_de_canciones).
- **Constantes y #defines:** MAYUSCULAS (ej. #define RUNNNING).

### Otros
- **Memoria:** Todo malloc tiene su free correspondiente antes de salir del programa.
- **Documentacion:** Cada función lleva comentario de su propósito, parámetros, valor de retorno.
- **Documentacion:** No se utilizan ñ (se reemplaza por nh) en ninguna parte del codgio pra evitar errores en compiladores.
- **Organizacion:** src/ para implementación, inc/ para headers, build//obj/ ignorados por git.
- **Organizacion:** Un archivo .c/.h por módulo funcional
