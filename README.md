# MUB Digital Music Player
Es el primer proyecto del ramo de Estructuras de Datos, el cual consiste en diseñar e implementar un sistema que simule el
funcionamiento de un reproductor de música, permitiendo generar, almacenar, ordenar y buscar información de canciones. 
Nuestro mejora planteada es implementar la reproducción de música. 

## Integrantes
**Ingeniería Civil en Computación e Informática** 
- [Nicolas Balic](mailto:nbalic@umagallanes.cl)
- [Tomas Minte](mailto:tminte@umagallanes.cl) 
- [Daniel Uribe](mailto:daniurib@umagallanes.cl) 

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
