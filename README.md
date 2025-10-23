# Red_Neuronal_XoR_Arduino
Funcionalidad. Implementa una red neuronal previamente entrenada para imitar el comportamiento de la compuerta lógica XOR en Arduino

Consideraciones
1. La función de activación utilizada es la sigmoidal logística
2. Las entradas del entrenamiento son bipolares, es decir, en lugar de 0 y 1 se emplearán -1 y 1
3. En la salida se aplica un valor de umbral para obtener resultados en 0 y 1.

Instruciones de uso
1. El programa debera ser cargado en tu programa Arduino, dependiendo de tu microcontrolador sera necesario una libreria distinta para la conexión del mismo.
2. El programa no utiliza librerias externas para el uso del sigmoide
3. Ya con el programa cargado debera de conectarse el microcontrolador a la tablilla de pruebas con la que observaras el problema.
4. El programa cuenta serial para observarlo en el monitor de Arduino por cualquier cosa. 
