<h1 align="centre">Filamento</h1>

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada por:

- Do arquivo GCODE
- No console do Fluidd/Mainsail (pressione a letra inglesa `C` no fluidd)

!!! Nota
    *O valor entre colchetes é o valor padrão.

---

### COLDPULL

Coldpool (limpeza do bocal) sem violência.
Implementação [deste algoritmo](https://t.me/FF_5M_5M_Pro/2836/447172)

- Escolha com o que limpar (PETG, ABS, NEYLON).
- Siga as instruções no console do FLUIDD.
- Puxe o resíduo para fora do bocal

---

### M600

Pausa e substituição do filamento

---

### COR

*Somente AD5X

Controla o tipo de plástico, a cor do plástico, o carregamento e o descarregamento de filamentos de carretéis coloridos.

Só funciona quando operado no modo de tela nativa

---

### SET_PAUSE_NEXT_LAYER

Definir macro de pausa/chamada na próxima camada

- ENABLE - 0 - desliga, 1 - liga (1)
- MACRO - macro a ser chamada (`PAUSE`)

---

### SET_PAUSE_AT_LAYER

Ativar/desativar a pausa em um número de camada específico

- ENABLE - 0 - desligado, 1 - ligado (1)
- MACRO - macro a ser chamada (`PAUSE`)
- LAYER - número da camada (0)

---
!!! aviso
    Para que essas funções funcionem, você precisa adicionar ao código inicial:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    No código de alteração de camada, adicione:
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
    ```

