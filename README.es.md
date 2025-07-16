<div>
    <p align="left">
        <a href="README.md">English<a> · <b>Español</b>
    </p>
</div>

# cub3d  
Mi primer RayCaster con MLX42

##### Resumen

Este proyecto está inspirado en el mundialmente famoso juego Wolfenstein 3D, considerado el primer FPS jamás creado. Te permitirá explorar el ray-casting. Tu objetivo será crear una vista dinámica dentro de un laberinto, donde tendrás que encontrar el camino.  

---

## Instrucciones

| **Nombre del programa** | **cub3d** |
|-------------------------|-----------|
| **Archivos a entregar** | Todos tus archivos |
| **Makefile** | all, clean, fclean, re, bonus |
| **Argumentos** | un mapa en formato *.cub |
| **Funciones externas** | - open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday <br> - Todas las funciones de la biblioteca matemática (-lm man man 3 math) <br> - Todas las funciones de la biblioteca MLX42 |
| **Libft autorizada** | Sí |
| **Descripción** | Debes crear una representación gráfica 3D “realista” del interior de un laberinto desde una perspectiva en primera persona. <br>Debes crear esta representación utilizando los principios de ray-casting mencionados anteriormente. |

---

Las restricciones son las siguientes:

- Debes usar la MLX42. Ya sea la versión que está disponible en el sistema operativo o desde sus fuentes. Si eliges trabajar con las fuentes, deberás aplicar las mismas reglas para tu libft que las escritas anteriormente en la parte de Instrucciones Comunes.

- La gestión de tu ventana debe ser fluida: cambiar a otra ventana, minimizar, etc.

- Mostrar diferentes texturas de pared (la elección es tuya) que varíen dependiendo de qué lado de la pared esté enfrentando (Norte, Sur, Este, Oeste).

- Tu programa debe poder establecer colores diferentes para el piso y el techo.

- El programa muestra la imagen en una ventana y respeta las siguientes reglas:

    - Las teclas de flecha izquierda y derecha del teclado deben permitir mirar a la izquierda y a la derecha dentro del laberinto.

    - Las teclas W, A, S y D deben permitir mover el punto de vista a través del laberinto.

    - Presionar ESC debe cerrar la ventana y salir del programa de manera limpia.

    - Hacer clic en la cruz roja del marco de la ventana debe cerrar la ventana y salir del programa de manera limpia.

    - Se recomienda encarecidamente el uso de imágenes de la biblioteca MLX42.

- Tu programa debe aceptar como primer argumento un archivo de descripción de escena con la extensión .cub.

    - El mapa debe estar compuesto únicamente por 6 caracteres posibles: 0 para espacio vacío, 1 para pared, y N, S, E o W para la posición inicial del jugador y su orientación.

    Este es un ejemplo de mapa válido:
        ```
        111111
        100101
        101001
        1100N1
        111111
        ```

    - El mapa debe estar cerrado/rodeado por paredes; si no lo está, el programa debe devolver un error.

    - Excepto el contenido del mapa, cada tipo de elemento puede estar separado por una o más líneas en blanco.

    - Excepto el contenido del mapa, que siempre debe estar al final, cada tipo de elemento puede aparecer en cualquier orden dentro del archivo.

    - Excepto el mapa, cada tipo de información puede estar separada por uno o más espacios.

    - El mapa debe ser interpretado tal como aparece en el archivo. Los espacios son una parte válida del mapa y debes gestionarlos adecuadamente. Debes poder interpretar cualquier tipo de mapa, siempre que respete las reglas del mapa.

    - Excepto el mapa, cada elemento debe comenzar con su identificador de tipo (compuesto por uno o dos caracteres), seguido de su información específica en un orden estricto.

        - Textura del Norte:  
            `NO ./ruta_a_la_textura_norte`  
            - identificador: NO  
            - ruta a la textura norte

        - Textura del Sur:  
            `SO ./ruta_a_la_textura_sur`  
            - identificador: SO  
            - ruta a la textura sur

        - Textura del Oeste:  
            `WE ./ruta_a_la_textura_oeste`  
            - identificador: WE  
            - ruta a la textura oeste

        - Textura del Este:  
            `EA ./ruta_a_la_textura_este`  
            - identificador: EA  
            - ruta a la textura este

        - Color del piso:  
            `F 220,100,0`  
            - identificador: F  
            - Colores RGB deben estar en el rango [0,255]: 0. 255, 255

        - Color del techo:  
            `C 225,30,0`  
            - identificador: C  
            - Colores RGB deben estar en el rango [0,255]: 0. 255, 255

    - Ejemplo de la parte obligatoria con una escena .cub minimalista:

        ```
        NO ./ruta_a_la_textura_norte
        SO ./ruta_a_la_textura_sur
        WE ./ruta_a_la_textura_oeste
        EA ./ruta_a_la_textura_este

        F 220,100,0
        C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
        111111111011000001110000000000001
        100000000011000001110111111111111
        11110111111111011100000010001
        11110111111111011101010010001
        11000000110101011100000010001
        10000000000000001100000010001
        10000000000000001101010010001
        11000001110101011111011110N0111
        11110111 1110101 101111010001
        11111111 1111111 111111111111
        ```

    - Si se encuentra cualquier tipo de mala configuración en el archivo, el programa debe cerrarse correctamente y devolver "Error\n" seguido de un mensaje de error explícito de tu elección.
