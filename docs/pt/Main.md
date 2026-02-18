<h1 align="centre">Principal</h1>

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada por:

- Do arquivo GCODE
- No console do Fluidd/Mainsail (pressione a letra inglesa `C` no fluidd)

!!! Nota
    *O valor entre colchetes é o valor padrão.

---

### START_PRINT

Substituindo o código g inicial nativo (se usado com uma tela, adicione M140 ou M190 Table_temperature e M109 ou M104 Extruder_temperature).

- EXTRUDER_TEMP - temperatura da extrusora (245)
- BED_TEMP - temperatura da mesa (80)
- MESH - nome do cartão da tabela a ser carregado; se não for especificado, nada será carregado; se não existir, será criado ("").
- FORCE_LEVELING - força a criação de um mapa de tabela (False)
- SKIP_LEVELING - não cria um mapa de tabela sob nenhuma condição. Mais forte do que FORCE_KAMP e FORCE_LEVELING (False)
- FORCE_KAMP - Inicia a criação de um mapa de tabela adaptável (False) *Recomenda-se colocar também `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, o que permitirá que você use o espaço de limpeza onde o mapa de tabela é removido.
- Z_OFFSET - Define o deslocamento Z (0,0)
- INTERNAL - Para a versão PRO, ao trabalhar em modo de tela não nativa, 1 - ativa a recirculação interna (0)
- EXTERNAL - Para a versão PRO no modo de tela não nativa, 1 - ativa a recirculação externa (0).

*Qualquer chamada à calibração FORCE_KAMP ou FORCE_LEVELING causa [CLEAR_NOZZLE](/pt/Main/#CLEAR_NOZZLE)*

*Durante a inicialização de START_PRINT, [ZSSH_RELOAD](/pt/Zmod/#zssh_reload) é chamado, o que restaura a conexão SSH, se necessário.

Exemplo para o Orca com tela nativa. Remova o código de inicialização e coloque o que está abaixo.
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```
Exemplo para o Orca em modo de tela não nativa
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Para que as camadas no Fluidd sejam contadas corretamente, escreva no código inicial:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

E no código de alteração de camada, adicione:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Quais são as opções para remover um cartão de mesa?](/pt/FAQ/#what-are-the-options-for-removing-a-table-card)

# porcupine #

#### Esses não são parâmetros START_PRINT, são sinalizadores/parâmetros globais que são definidos por meio de [SAVE_ZMOD_DATA](/pt/Global/#start_print):

- [PRECLEAR](/pt/Global/#preclear) - usar preclear de bocal em [CLEAR_NOZZLE](/pt/Main/#CLEAR_NOZZLE) 0-no, 1-yes (0).
- [CLEAR](/pt/Global/#clear) - Selecione o algoritmo de limpeza do bocal (LINE_PURGE)
- [PRINT_LEVELING](/pt/Global/#print_leveling) - Criar mapa de tabela em cada impressão 0-não, 1-sim (0).
- [USE_KAMP](/pt/Global/#use_kamp) - Onde é possível usar o mapa de tabela adaptável (KAMP) em vez do mapa de tabela completo 0-não, 1-sim (0)
- DISABLE_PRIMING](/pt/Global/#disable_priming) - Desativa a limpeza do bocal por extrusão 0-não, 1-sim (0)
- [FORCE_MD5](/pt/Global/#force_md5) - se 1 (o padrão é 1) - verifica a soma MD5 do arquivo, se houver erro - exclui o arquivo.
    1. Você precisa selecionar e fazer o download para o seu computador de um arquivo para a sua arquitetura e sistema operacional:

    - [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
    - [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Não se esqueça de executar ```chmod +x zmod_preprocess-linux-amd64`''
    - [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Intel. Não se esqueça de executar ```chmod +x zmod_preprocess-darwin-arm64```
    - [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Silicon. Não se esqueça de executar ```chmod +x zmod_preprocess-darwin-amd64```
    - [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Não se esqueça de executar ```chmod +x zmod-preprocess.py```
    - [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Lembre-se de executar ```chmod +x zmod-preprocess.sh```.

    2. No Orca, você precisa escrever. ```Process Profile``` -> ```Other``` -> ```Post Processing Scripts```.

    Aqui estão as opções a serem adicionadas:

    - ```"C:\path_to_file\zmod_preprocess-windows-amd64.exe";```
    - ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
    - ````"/usr/bin/python3" "/home/user/zmod-preprocess.py";````
    - ```"/home/user/zmod-preprocess.py";````
    - ````"/home/user/zmod_preprocess-darwin-amd64";````
    - ````"/home/user/zmod_preprocess-darwin-arm64";````
    - ````"/home/user/zmod_preprocess-linux-amd64";````

- [DISABLE_SKEW](/pt/Global/#disable_skew) - 1 - desativa a correção SKEW, 0 - carrega o perfil `skew_profile` (a macro `SKEW_PROFILE LOAD=skew_profile` será chamada) (1)
- AUTO_REBOOT - reinicializa automaticamente a impressora após o término da impressão 0-no, 1-yes, 2-FIRMWARE_RESTART (somente no modo sem tela nativa, com tela REBOOT) (0).
- CLOSE_DIALOGS - Fecha automaticamente as caixas de diálogo quando a impressão é concluída e cancelada 0-não, 1-sim lentamente, 2-sim rapidamente *Para fechar rapidamente as caixas de diálogo, é necessário acessar "Settings" (Configurações) -> "WiFi icon" (Ícone WiFi) -> "Network mode" (Modo de rede) -> **ativar o controle deslizante** "Local networks only "* (0).
- STOP_MOTOR - Desliga automaticamente os motores após a impressão/cancelamento depois de 25 segundos 0-não, 1-sim (1).
- MIDI_START - Reproduzir MIDI quando a impressão começar ("")
- MIDI_END - Toca MIDI quando a impressão é concluída ("")

#### Algoritmo de retirada de cartão:

- Se MESH não estiver vazio, o cartão com o nome escrito no parâmetro MESH será carregado
- Se SKIP_LEVELING = True - o cartão da mesa não será removido em nenhuma condição
- Caso contrário,
- Se FORCE_CAMP = True, então KAMP será removido.
- Caso contrário
- Se o mapa da tabela não estiver carregado (o cabeçalho nativo sempre carrega o mapa MESH_DATA) ou se FORCE_LEVELING = True, a construção do mapa da tabela será iniciada.
- A construção do mapa da tabela é iniciada, mas não é salva.

---

### END_PRINT

Substituindo o código g final nativo

#### Esses não são parâmetros END_PRINT, são sinalizadores/parâmetros globais que são definidos por meio de [SAVE_ZMOD_DATA](/pt/Global/#end_print).

- AUTO_REBOOT - reinicialização automática da impressora após o fim da impressão 0-não, 1-sim, 2-FIRMWARE_RESTART (somente no modo sem tela nativa, com tela REBOOT) (0).
- CLOSE_DIALOGS - Fecha automaticamente as caixas de diálogo quando a impressão é concluída e cancelada 0-não, 1-sim lentamente, 2-sim rapidamente *Para fechar rapidamente as caixas de diálogo, é necessário ir para "Settings" (Configurações) -> "WiFi icon" (Ícone WiFi) -> "Network mode" (Modo de rede) -> **ativar o controle deslizante** "Local networks only "* (0).
- STOP_MOTOR - Desliga automaticamente os motores após a impressão/cancelamento depois de 25 segundos 0-não, 1-sim (1)
- MIDI_END - Reproduzir MIDI quando a impressão estiver concluída ("")

---

### _USER_START_PRINT

Macro do usuário para adicionar suas próprias ações no início da impressão.

Essa macro é chamada automaticamente no final da macro `START_PRINT`. Usada para estender o processo padrão de inicialização da impressão com comandos personalizados.

**Onde usar

- Adicionar seus próprios comandos de aquecimento ou calibração
- Fazer configurações adicionais antes de iniciar a impressão
- Ativar/desativar dispositivos (ventilador, sensores, etc.)
- Adicionar limpeza personalizada do bocal ou outras operações preparatórias

**Exemplo de substituição em `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_START_PRINT].
gcode:
    # Habilite o ventilador opcional
    SET_PIN PIN=my_fan VALUE=1
    # Algum comando seu
    G4 P1000 ; pausa de 1 segundo
    # Alguma outra ação
```

**Nota:** Por padrão, a macro está vazia e pode ser substituída pelo usuário para atender às suas necessidades.

---

### _USER_END_PRINT

Macro do usuário para adicionar suas próprias ações no final da impressão.

Essa macro é chamada automaticamente no final da macro `END_PRINT`. Usada para estender o processo padrão de fim de impressão com comandos personalizados.

**Onde usar

- Executar ações adicionais no final da impressão
- Desligar dispositivos adicionais
- Salvar estatísticas ou registros
- Executar limpeza ou manutenção personalizada da impressora

**Exemplo de substituição em `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_END_PRINT].
gcode:
    # Desligue o ventilador opcional
    SET_PIN PIN=my_fan VALUE=0
    # Enviar notificação
    M118 Impressão concluída!
    # Ou qualquer outro comando
```

**Nota:** Por padrão, a macro está vazia e pode ser substituída pelo usuário para atender às suas necessidades.

---

### CANCELAR

Cancelar impressão

---

### CLEAR_NOZZLE

Limpando o bocal na mesa como no firmware nativo

- EXTRUDER_TEMP - temperatura da extrusora (230)
- BED_TEMP - temperatura da mesa (80)

*PRECLEAR - usar a pré-limpeza do bocal em CLEAR_NOZZLE 0-não, 1-sim (0).
Esse não é um parâmetro do CLEAR_NOZZLE, é um sinalizador global que é definido por meio de `SAVE_ZMOD_DATA PRECLEAR=1`. Leia mais [aqui](/pt/Global/#preclear)*

*O refinamento da macro `CLEAR_NOZZLE` em `mod_data/user.cfg` não alterará a limpeza nativa do bocal na tabela quando chamada diretamente da tela nativa, porque a tela nativa funciona bem sem o zMod e, portanto, não usa macros zMod*.

---

### LED_ON

Liga a luz de fundo

---

### LED_OFF

Desligar a luz de fundo

---

### LED

Ative a luz de fundo em alguns por cento

- S - porcentagem (50)

---

### PAUSA

Pausa na impressão

---

### RESUME

Retomar a impressão após uma pausa

---

### PLAY_MIDI

Reproduzir arquivo MIDI

- FILE - nome do arquivo (For_Elise.mid) os arquivos são armazenados em mod_data/midi/

---

### REBOOT

Reiniciar a impressora

---

### CLOSE_DIALOGS

Faz com que as caixas de diálogo sejam fechadas lentamente na tela nativa. Usado para fechar a janela quando a impressão é concluída ou quando a impressão é cancelada.

Pode fazer com que a impressora trave.

Implementação: @darksimpson.

Também controlado pelo [parâmetro global CLOSE_DIALOGS](/pt/Global/#close_dialogs)

---

### FAST_CLOSE_DIALOGS

Faz com que as caixas de diálogo sejam fechadas rapidamente na tela nativa. Usado para fechar uma janela quando a impressão é concluída ou quando a impressão é cancelada.

É executado mais rapidamente e não faz com que a impressora trave.

*Para fechar as caixas de diálogo rapidamente, vá para `Configurações` -> `Icone WiFi` -> `Modo de rede` -> **Ajuste o controle deslizante** `Somente redes locais` por meio do menu da tela da impressora.

Também controlado pelo [parâmetro global CLOSE_DIALOGS](/pt/Global/#close_dialogs)

Implementação: @darksimpson.

---

### NEW_SAVE_CONFIG

Chama `SAVE_CONFIG` a partir da tela nativa. Pode ser usado para reiniciar o clipper sem suspender a tela nativa.

Implementação: @darksimpson.

Funciona por cerca de um minuto.

Às vezes, pode fazer com que a tela nativa não funcione corretamente

---

### SHUTDOWN

Desligar a impressora
