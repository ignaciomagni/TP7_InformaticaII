# Interfaz Gráfica en Processing

Este directorio contiene el script de Processing encargado de renderizar la interfaz gráfica de usuario (GUI).

## Características de la Interfaz
- **Visualización:** Muestra de forma gráfica los estados de las entradas digitales (`E1`, `E2`) provenientes de Arduino.
- **Interactividad por Mouse:** Permite hacer clic directamente sobre los indicadores circulares de las salidas (`L1`, `L2`) para alternar su estado de manera remota.
- **Sincronización Bidireccional:** Actualiza el entorno visual instantáneamente tanto si se manipulan los componentes físicos como si se opera desde la pantalla.

## Instrucciones para Replicarlo y Hacerlo Funcionar
1. Asegúrate de tener instalada la librería **Serial** en Processing (*Sketch > Import Library > Serial*).
2. Conecta tu placa Arduino a la PC mediante el puerto USB.
3. Cierra cualquier otro software que esté utilizando el puerto serial (como el Monitor Serie del IDE de Arduino).
4. Ejecuta el código. El programa listará por consola los puertos disponibles y se conectará automáticamente al índice configurado (por defecto `Serial.list()[0]`). Si tu Arduino está en otro puerto, asegúrate de cambiar el índice numérico en el código principal (`.pde`).
