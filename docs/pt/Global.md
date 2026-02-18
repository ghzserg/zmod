<h1 align="centre">Parâmetro global</h1>

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada por:

- Do arquivo GCODE
- No console do Fluidd/Mainsail (pressione a letra inglesa `C` no fluidd)

!!! Nota
    *O valor entre colchetes é o valor padrão.

---

### LANG

Define o idioma a ser usado pelo zMod.

- LANG - idioma, en - inglês, ru - russo, de - alemão, fr - francês, it - italiano, es - espanhol, zh - chinês, ja - japonês, ko - coreano, pt - português, cs - tcheco, tr - turco

Exemplo:
```
LANG LANG=pt
```

---

### SET_TIMEZONE

Alterar o fuso horário

- ZONE - fuso horário (Ásia/Yekaterinburg)

---

### CONTROLE_DE_BICOS

Controle da quebra da peça ou do impacto do bico na mesa.

Desligamento de emergência da impressora se for detectado excesso de peso.

WEIGHT - peso em gramas (1500)

A configuração é mantida mesmo após uma reinicialização.

Defina `NOZZLE_CONTROL WEIGHT=0` para desativar essa função.

*Antes da primeira chamada de macro, o controle é desativado.

Ao trabalhar com a tela nativa, a chamada da macro reinicia a impressora.

Ao operar no modo de tela não nativa, ela reinicia o Klipper à medida que são feitas alterações nos arquivos de configuração.

Tudo funciona no modo automático, mas as seguintes macros também estão disponíveis e podem ser usadas no Gcode:

- `ZCONTROL_ON` - ativa o controle
- `ZCONTROL_OFF` - desativar o controle
- `ZCONTROL_STATUS` - descobre o status da função
- `ZCONTROL_PAUSE` - chama a pausa ao acionar (a pausa será executada somente depois que a fila de comandos for liberada, não nas primeiras camadas).
- `ZCONTROL_ABORT` - interrompe o Klipper quando ele é acionado.
- `ZCONTROL_AUTO` - interrompe o Klipper (se a altura z < `ZCONTROL_Z`), ou chama PAUSE se z >= `ZCONTROL_Z`.
- `ZCONTROL_Z Z=10` - define a altura por Z.
- `SAVE_ZMOD_DATA ZCONTROL_Z=10` - salva a altura por Z. Se você não quiser ativar a pausa, defina ```SAVE_ZMOD_DATA ZCONTROL_Z=230``` ```

Se quiser ativar o controle do bocal nas primeiras camadas, adicione ```ZCONTROL_PAUSE``` por meio do fatiador na camada em que deseja usar a pausa em vez da operação de interrupção.

---

### GET_ZMOD_DATA

Obtém os valores dos parâmetros/flags globais do ZMOD.
Depois que a macro for executada, o console exibirá os dados que foram salvos anteriormente e aplicados no momento atual

`Fluidd` -> `Macros` -> `Main` -> `ZMOD PARAMETERS`.

---

### GLOBAL

Controle simplificado dos parâmetros globais. Somente os parâmetros que podem ser alterados ao pressionar o botão estão disponíveis. Os parâmetros que exigem um número, nome de arquivo etc. não são controlados por essa macro.

Recomenda-se reiniciar a impressora após alterar os parâmetros

---

### SALVAR_ZMOD_DATA

Salva os parâmetros/flags globais do ZMOD, aplicados a cada impressão.

Essa macro não precisa ser adicionada ao código inicial, final ou ao arquivo gcode. A macro é chamada no console do fluidd/mainsail. Depois que a impressora é desligada, os parâmetros são armazenados na memória da impressora no arquivo `mod_data/variables.cfg` (**não edite o arquivo manualmente, pois você bagunçará o clipper ou o mod**) e não será necessário inseri-los todas as vezes.

**Para editar o parâmetro necessário, vá para `Fluidd` -> `Macros` -> `System` -> `SAVE ZMOD PARAMETERS`**, selecione o parâmetro que deseja alterar, preencha-o e pressione `SEND`. Veja o que será exibido no console do fluidd.

Segunda opção. Escreva no console do Fluidd o comando desejado, por exemplo: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

[Exibir parâmetros salvos](/pt/Global/#get_zmod_data)

---

#### Parâmetros do menu de seleção de cores de impressão ###

**Todas as opções do menu de seleção de cores se aplicam somente ao AD5X.

##### ALLOWED_TOOL_COUNT

O número de ferramentas exibidas no menu de seleção de cores. Isso se refere aos comandos T0, T1, etc. no arquivo gcode, e não às bobinas físicas no IFS.

Se o zMod escanear com êxito o arquivo em busca de instrumentos em uso, esse valor será substituído e somente os instrumentos usados no arquivo serão mostrados.

Essa configuração não poderá ser usada se a tela nativa estiver ativada.

[Consulte a configuração de pré-processamento](https://wiki.zmod.link/pt/Recomendations/#enable-md5-checksum-control)

Exemplo: `SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=4`.

##### SCAN_FILE_COLORS

Permite a varredura de arquivos gcode para determinar os comandos de troca de ferramenta usados (T0, T1 etc.) e as cores e os materiais atribuídos a eles no fatiador: 0 (desativado), 1 (ativado), 2 (desativa a varredura completa, mas procura dados preparados pelo script do fatiador).

[Consulte a configuração de pré-processamento](https://wiki.zmod.link/pt/Recomendations/#enable-md5-checksum-control)

Exemplo: `SAVE_ZMOD_DATA SCAN_FILE_COLORS=0`.

##### COLOUR_MENU_1_BASED

Determina quais rótulos serão exibidos no menu de seleção de cores: começando com 0 (T0, T1, etc.) ou começando com 1 (Cor 1, Cor 2, etc.). Isso altera apenas os nomes dos botões e é puramente por conveniência: 0 (de zero), 1 (de um).

Exemplo: `SAVE_ZMOD_DATA COLOUR_MENU_1_BASED=1`.

##### AUTO_ASSIGN_COLORS

Determina se você tentará mapear automaticamente os comandos de troca de ferramenta (T0, T1, etc.) para o filamento físico carregado no IFS quando iniciar a impressão. Se você não tiver ativado o modo silencioso, o menu de seleção de cores ainda será exibido; essa configuração afeta apenas a seleção padrão: 0 (desligado), 1 (ligado).

Essa configuração também se aplica a trabalhos executados no modo silencioso. Você pode configurá-la para que a impressão seja interrompida quando ocorrerem determinados erros de atribuição automática: 2 (interromper se algum material não corresponder, mas permitir incompatibilidade de cores), 30 (interromper para quaisquer problemas).

Para definir valores personalizados para as condições de erro no modo silencioso, some os valores a seguir para obter a configuração desejada:

* 2 (Pelo menos um material não corresponde; por exemplo, o arquivo gcode especifica ABS e você só tem PLA carregado; ou os dados do material não puderam ser carregados)
* 4 (Pelo menos uma cor não corresponde, geralmente porque os arquivos de digitalização estão desativados ou falharam)
* 8 (Pelo menos uma cor não corresponde bem)
* 16 (A mesma bobina física foi atribuída a mais de um índice de ferramenta no arquivo)

[Consulte a configuração de pré-processamento](https://wiki.zmod.link/pt/Recomendations/#enable-md5-checksum-control)

Exemplo: `SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=0`.

### Parâmetros do início da impressão, construção do mapa da tabela [START_PRINT]:

##### MIDI_START

Reproduzir MIDI no início da impressão (""), 0 para desligar

Exemplo: `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`.

---

##### PRECLEAR

Usar a pré-limpeza do bocal em CLEAR_NOZZLE 0-não, 1-sim (0)

Exemplo: `SAVE_ZMOD_DATA PRECLEAR=0`.

---

##### PRINT_LEVELING

A cada impressão, crie um mapa de tabela (usando a tela nativa, se a tela estiver ativada) 0-não, 1-sim (0). *Para remover o mapa da área de trabalho da tela nativa, vá para "Settings" (Configurações) -> "WiFi Icon" (Ícone WiFi) -> "Network Mode" (Modo de rede) -> **ative o controle deslizante** "Local Networks Only "* por meio do menu da tela da impressora.

Exemplo: `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

---

##### USE_KAMP

Onde é possível usar o mapa de tabela adaptável (KAMP) em vez do mapa de tabela completo 0-no, 1-yes (0).

Também é recomendável colocar `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, o que permitirá usar o espaço de limpeza onde o mapa da tabela é removido.

*Permite usar o KAMP ao nivelar a partir da tela nativa pela rede.

Exemplo: `SAVE_ZMOD_DATA USE_KAMP=1`.

---

##### MESH_TEST

Teste o mapa da tabela antes da impressão:

- 0 - nenhum
- 1 - teste SEM seleção automática de Z-Offset (por padrão)
- 2 - teste SEM a definição automática do deslocamento Z, em caso de incompatibilidade do mapa, inicie o KAMP
- 3 - teste com seleção AUTO Z-Offset, com limpeza do bico
- 4 - teste com a SELEÇÃO AUTOMÁTICA do Z-Offset, com limpeza do bocal, em caso de incompatibilidade do mapa, inicie o KAMP

**Seleção automática de Z-Offset**

Algoritmo para calibração automática do deslocamento do eixo Z (Z-Offset):

1.  **Dados de origem:** A memória da impressora armazena o mapa da tabela (normalmente 25 pontos) do último procedimento de alinhamento.
2.  **Preparação

    * Bocal aquecido até a temperatura operacional, limpo contra a mesa e resfriado a 151°C.

3.  **Selecione o ponto de medição:**

    * É usado o ponto **central** do mapa.

4.  **Medição e comparação:**

    * Uma nova medição de sonda (PROBE) é feita no ponto selecionado.
        * O valor obtido é comparado com o valor armazenado no mapa da tabela.

5.  **Ajuste do deslocamento:**

    * Se a diferença for **menor que 0,3 mm**, a diferença será adicionada ao valor atual do deslocamento Z.
        * Se a diferença for **maior ou igual a 0,3 mm**, o sistema considerará o mapa salvo irrelevante e, com as configurações ativadas, iniciará automaticamente o procedimento de realinhamento da tabela (KAMP).

**No Auto Z-Offset**

Algoritmo para verificar o mapa da mesa:

1.  **Medição:** Uma medição de sonda padrão (PROBE) é feita no ponto atual.
2.  **Validação:** O valor Z resultante é verificado em relação ao mapa carregado.
3.  **Critério:** O valor deve estar entre (mínimo do mapa - 0,21 mm) e (máximo do mapa + 0,21 mm).
4.  **Resultado:**

    * Sucesso: O mapa é considerado correto e a impressão continua.
        * Falha:** Um aviso é exibido e a impressão é interrompida ou, se as configurações estiverem ativadas, inicia automaticamente o procedimento de realinhamento da mesa (KAMP)

**Notas:**

* A verificação é uma estimativa aproximada. Ela se destina a detectar erros críticos, como quando um mapa feito para vidro grosso é carregado para uma folha PEI e vice-versa.
* Não confie nessa verificação como uma defesa absoluta.
* Ao usar a limpeza inteligente (KAMP), a espera de calor fica perto da área de limpeza, não no canto da mesa.

Exemplo: `SAVE_ZMOD_DATA MESH_TEST=0`.

---

##### FORCE_MD5

Igor Polunovskiy

Verifica a soma MD5 do arquivo e exclui o arquivo em caso de erro. 0 - não verificar, 1 - verificar (1)

1. Você precisa selecionar e fazer download para o seu computador de um arquivo para a sua arquitetura e sistema operacional:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Não se esqueça de executar ```chmod +x zmod_preprocess-linux-amd64`''
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Intel. Não se esqueça de executar ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Silicon. Não se esqueça de executar ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Não se esqueça de executar ```chmod +x zmod-preprocess.py``` ```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Lembre-se de executar ```chmod +x zmod-preprocess.sh```.

2. No Orca, você precisa escrever. ```Process Profile``` -> ```Other``` -> ```Post Processing Scripts```.

Aqui estão as opções a serem adicionadas:

- ```"C:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ````"/usr/bin/python3" "/home/user/zmod-preprocess.py";````
- ````"/home/user/zmod-preprocess.py";````
- ````"/home/user/zmod_preprocess-darwin-amd64";````
- ````"/home/user/zmod_preprocess-darwin-arm64";````
- ````"/home/user/zmod_preprocess-linux-amd64";````

Exemplo: `SAVE_ZMOD_DATA FORCE_MD5=1`.

---

##### DISABLE_SKEW

1 - desativa a correção SKEW, 0 - carrega o perfil `skew_profile` (a macro `SKEW_PROFILE LOAD=skew_profile` será chamada) (1)

[Leia mais](https://www.klipper3d.org/Skew_Correction.html)

Exemplo: `SAVE_ZMOD_DATA DISABLE_SKEW=1`.

---

##### LOAD_ZOFFSET

Carrega o deslocamento Z dos parâmetros globais salvos anteriormente por meio de SET_GCODE_OFFSET. 1 - sim, 0 - não (1)

[Como funciona o deslocamento Z](/pt/FAQ/#how-z-offset-works)

Exemplo: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`.

---

##### DISABLE_PRIMING

Desativar a limpeza do bico apertando 0-no, 1-yes (0)

Exemplo: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`.

---

##### CLEAR

Selecione o algoritmo de limpeza da extrusão do bico (LINE_PURGE)

- _CLEAR1 - como no Orca
- _CLEAR2 - do grupo FF
- _CLEAR3 - da variante 2 do grupo FF
- _CLEAR4 - código de limpeza Schrader da direita de cima para baixo
- _CLEAR_TRAP - se houver uma escova do lado direito de cima para baixo
- LINE_PURGE - limpeza do KAMP

Se você usar `KAMP`, a limpeza será forçada a ser definida como `LINE_PURGE` (em vez de _CLEAR1, _CLEAR2, _CLEAR3, _CLEAR4).

Se você usar `LINE_PURGE` mas não tiver ativado o particionamento de objetos no Orca, então `_CLEAR2` será aplicado

Você pode adicionar sua macro de limpeza a 'mod_data/user.cfg' e nomeá-la com este parâmetro
*behemoth

Exemplo: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`.

*5M/5MPro: isso não substitui o clean(CLEAR_NOZZLE) nativo, em que o bico entra no meio da mesa pela parte superior e raspa o plástico contra a mesa. Trata-se da limpeza do bocal imediatamente antes da impressão.

---

### Opções de fim de impressão e cancelamento [END_PRINT]:

##### MIDI_END

Reproduzir MIDI no final da impressão (""), 0 para desativar

Exemplo: `SAVE_ZMOD_DATA MIDI_END=Pain-Shut-your-mouth.mid`.

---

##### CLOSE_DIALOGS

Fecha automaticamente as caixas de diálogo quando a impressão é concluída e cancelada 0-não, 1-sim lentamente, 2-sim rapidamente

*Para fechar as caixas de diálogo rapidamente, vá para "Settings" (Configurações) -> "WiFi Icon" (Ícone WiFi) -> "Network Mode" (Modo de rede) -> **ative o controle deslizante** "Local Network Only "* (0) no menu da tela da impressora.

Exemplo: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

---

##### STOP_MOTOR

Desliga automaticamente os motores após a impressão/cancelamento após 25 segundos 0-não, 1-sim (1)

Exemplo: `SAVE_ZMOD_DATA STOP_MOTOR=1`.

---

##### AUTO_REBOOT

Reinicializa automaticamente a impressora quando a impressão é concluída (0):

- 0 - sem reinicialização
- 1 - reinicialização da impressora por meio do comando `REBOOT
- 2 - no modo sem tela nativa - reinicialização do firmware via `FIRMWARE_RESTART`, com tela - reinicialização da impressora via comando `REBOOT`.

Exemplo: `SAVE_ZMOD_DATA AUTO_REBOOT=0`.

---

### Parâmetros do sistema:

##### MOTION_SENSOR

Use em vez do sensor de filamento, [sensor de movimento de filamento](https://aliexpress.ru/item/1005007480443587.html) (0)

- 0 - não
- 1 - sim

Ao usar o sensor de movimento do filamento, desative-o na tela nativa; caso contrário, a impressão será interrompida.

Se o sensor de filamento for usado no modo de tela não nativa, a seguinte frase será exibida quando ele for acionado: "Out of filament. Haverá uma pausa em 30 segundos"

Exemplo: `SAVE_ZMOD_DATA MOTION_SENSOR=1`.

---

##### SILENT

Somente AD5X.

Não mostra a janela de seleção de cores quando a impressão é iniciada

- 0 - mostrar a janela (padrão)
- 1 - não mostrar a janela, usar as cores definidas anteriormente
- 2 - não mostrar a janela, não usar o IFS

Exemplo: `SAVE_ZMOD_DATA SILENT=0`

---

##### AUTOINSERT

Somente AD5X.

Carrega a barra automaticamente

- 0 - não carregar a barra automaticamente
- 1 - carregar a barra automaticamente (padrão)

Exemplo: `SAVE_ZMOD_DATA AUTOINSERT=0`

---

##### ALWAYS_FULL_COLOR_CHANGE

Somente AD5X

Determina se o processo de mudança de cor deve ser ignorado se as cores anterior e posterior forem atribuídas à mesma bobina física.

- 0 - pular o processo
- 1 - não pular o processo

Exemplo: `SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0`

---

##### USE_TRASH_ON_PRINT

Somente AD5X

Somente quando estiver operando em modo de tela não nativa

Use a redefinição do compartimento ao alterar a cor durante a impressão

- 0 - não usar
- 1 - usar (padrão)

Exemplo: `SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`

---

##### REMOVE_FILAMENT

Somente AD5X.

Somente quando estiver operando em modo de tela não nativa

Remova a barra após a conclusão da impressão

- 0 - não ejetar (padrão)
- 1 - ejetar

Exemplo: `SAVE_ZMOD_DATA REMOVE_FILAMENT=1`

---

##### FIX_SCV

Correção de SCV incorreto ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) ao renderizar gráficos de aceleração e calcular shapers.
 shapers.

- 0 deixa o parâmetro como no estoque 5
- 1 usa `square_corner_velocity` de `mod_data/user.cfg` ou `printer.base.cfg`

Exemplo: `SAVE_ZMOD_DATA FIX_SCV=1`.

Em nossa impressora, `square_corner_velocity: 25`, e os cálculos do gráfico de aceleração e do shaper são feitos para `SCV = 5`.

Em geral, isso afeta apenas as acelerações de saída e os níveis de suavização calculados.
Os valores `shaper_type_x`, `shaper_freq_x`, `shaper_type_y` e `shaper_freq_y` não são alterados.

Por outro lado, se o cálculo estiver correto, as acelerações calculadas caem em um fator de cerca de 2.

Portanto, a recomendação é escrever em `mod_data/user.cfg`:
```
[printer]
square_corner_velocity: 9
```

Isso reduzirá a velocidade nos cantos e, em geral, melhorará a qualidade da impressão, ao custo de uma pequena redução na velocidade

---

##### WIFI

Em alguns firmwares, ocasionalmente o Wi-Fi não é iniciado.

Para corrigir isso. Você precisa se conectar à rede Wi-Fi por meio da tela nativa.

Chame `SAVE_ZMOD_DATA WIFI=1`.

Desativar o Wi-Fi na tela nativa

- 0 usar WiFi na tela nativa
- 1 usar WiFi via zMod

---

##### FIX_E0011

As causas do erro E0011 são globais (temporizador muito próximo):

- O host não respondeu no tempo alocado (0,025 s)
- A MCU não respondeu dentro do tempo alocado (0,025 s)

Causas particulares:

- A placa-mãe ou a placa eletrônica da MCU das Nações foi suspensa. `Perdeu a comunicação com a MCU 'mcu'`. Solução: Reinicialize. Substitua a placa principal (`mcu`) ou a placa da extrusora ('eboard').
- O processador host está sobrecarregado (cálculo/plotagem do shaper)
- O EMMC está sobrecarregado (trabalho com git, backups, carregamento de arquivos grandes durante a impressão, etc.)
- Falta de RAM. Solução: soldar novamente o processador e aumentar o tamanho da memória para 256 megabytes
- Cabo quebrado para a extrusora. Solução: substituir/corrigir o cabo
- O conector do cabo não está fazendo contato com a placa do cabeçote da extrusora. Solução: substitua a placa da extrusora
- Download de dados do SWAP (o SWAP está no EMMC, que funciona a 10 MB/s, a quantidade de dados no SWAP é de até 25 megabytes quando os shapers são construídos). Solução: desative o SWAP se você tiver 256 MB de RAM `SAVE_ZMOD_DATA USE_SWAP=0`.
- Falha no firmware da MCU. Solução: reinicie a MCU [via reset](/en/Setup/#return-printer-to-factory-settings-needed-for-mod installation). Atualizar novamente a MCU a partir do mod [UPDATE_MCU](/pt/System/#update_mcu)

Corrigir o erro E0011 e o `Communication timeout during homing`; a alteração do parâmetro fará com que a impressora seja reinicializada. 0-não, 1-sim (0)

- 0 deixa o parâmetro como estoque 0,025
- 1 define o parâmetro para 0,1

Exemplo: `SAVE_ZMOD_DATA FIX_E0011=1`.

O erro também pode ocorrer:

- Grande quantidade de exclusões de modelos: Solução `Process Profile` -> `Other` -> `Output G-cod` -> `Model Exclusion` desativa a marcação.
- Se você tiver desativado a troca no FF5M/FF5MPro.
  
  Execute a macro `MEM` e veja se há uma troca e qual é o tamanho dela.
  
  Ative o SWAP se ele estiver desativado ```SAVE_ZMOD_DATA USE_SWAP=1```.

- Se estiver no FF5M/FF5MPro, faça um teste completo. Ou seja, calibração do PID, remoção do mapa da tabela e remoção do shaper ao mesmo tempo.
  
  É melhor fazer todas as calibrações [seguindo estas instruções](/pt/SetupCalibrations/#calibrate-printer-for-beginners)

O erro "Communication timeout during homing" pode ocorrer devido à alta latência de comunicação entre o computador host e os microcontroladores. Normalmente, o tempo de deslocamento deve ser consistentemente menor que 10 ms. Um atraso alto, mesmo por períodos curtos, pode causar mau funcionamento durante a configuração.

O `TRSYNC_TIMEOUT` é um parâmetro do Klipper cujo padrão é 0,025 segundos. Ele permite que você compense os atrasos na operação do sistema.

O arquivo `/opt/klipper/klippy/mcu.py` tem `TRSYNC_TIMEOUT = 0,025` no arquivo de estoque; o patch altera o valor para `TRSYNC_TIMEOUT = 0,1`.

Como corrigir isso no arquivo de estoque:

- Formate o USB para FAT32
- Salve o arquivo `flashforge_init.sh` no flash usb:
    - [Para corrigir o parâmetro do Adventurer5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
      - [Para restaurar o parâmetro de estoque do Adventurer5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-off.tgz)
      - [Para corrigir o Adventurer5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)
      - [Para restaurar o parâmetro de estoque do Adventurer5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-off.tgz)

- Desligue a impressora
- Insira o flash usb na impressora
- Ligue a impressora
- A impressora emitirá um bipe alto.
- Aguarde até que ela seja reinicializada
- Remova o flash USB
- Imprima o arquivo problemático novamente e o erro E0011 não deverá mais incomodá-lo.

Como corrigi-lo manualmente no estoque:

- Instale o [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Vá para [winscp](https://winscp.net/eng/download.php) via ssh e edite o arquivo `/opt/klipper/klippy/mcu.py`.
- Localize a linha `TRSYNC_TIMEOUT = 0.025` no arquivo.
- Substitua-a por `TRSYNC_TIMEOUT = 0.1`.
- Salve o arquivo na impressora
- Reinicie a impressora

---

##### FIX_E0017

Corrige o erro E0017; se você alterar o parâmetro, a impressora será reinicializada. 0-não, 1-sim (1)

No arquivo `/opt/klipper/klippy/toolhead.py` na pilha o parâmetro `LOOKAHEAD_FLUSH_TIME = 0.5`, no clipper original `LOOKAHEAD_FLUSH_TIME = 0.250`, nosso milagre funciona bem com `LOOKAHEAD_FLUSH_TIME = 0.150`.

- 0 define o parâmetro como estoque
- 1 define o parâmetro como 0,150

Exemplo: `SAVE_ZMOD_DATA FIX_E0017=1`.

Como corrigir no estoque:

- Formate o USB para FAT32
- Salve no arquivo flash USB:
    - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0017-4.tgz) para o FlashForge 5M
      - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0017-4.tgz) para o FlashForge 5M Pro

- Desligue a impressora
- Insira o flash USB na impressora
- Ligue a impressora
- A impressora emitirá um bipe alto.
- Aguarde até que ela seja reinicializada
- Remova o flash USB
- Imprima o arquivo problemático novamente e o erro E0017 não deverá mais incomodá-lo.

Como corrigi-lo manualmente no estoque:

- Instale [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Faça login via [winscp](https://winscp.net/eng/download.php) no ssh e edite o arquivo `/opt/klipper/klippy/toolhead.py`.
- Localize a linha `LOOKAHEAD_FLUSH_TIME = 0.5` no arquivo.
- Substitua-a por `LOOKAHEAD_FLUSH_TIME = 0,150`.
- Salve o arquivo na impressora
- Reinicie a impressora

---

##### LED

Brilho do LED quando ligado (50)

Exemplo: `SAVE_ZMOD_DATA LED=50`

---

##### MIDI_ON

Reproduzir MIDI quando ligado (""), 0 para desligar

Exemplo: `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`.

---

##### NEW_SAVE_CONFIG

Use o SAVE_CONFIG alternativo (chama o `SAVE_CONFIG` sem suspender a tela nativa) [NEW_SAVE_CONFIG](/pt/Main/#new_save_config) ao calibrar o PID 0-não, 1-sim (0)

Exemplo: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`.

---

##### USE_SWAP

Usar SWAP (1)

- 0 - não *Apenas para processador resoldered com 256 MB de memória*
- 1 - sim, em EMMC
- 2 - sim, se possível em USB FLASH

Exemplo: `SAVE_ZMOD_DATA USE_SWAP=1`.

---

##### CHINA_CLOUD

Habilitar nuvens chinesas 0 - não, 1 - sim (1)

Exemplo: `SAVE_ZMOD_DATA CHINA_CLOUD=0`.

[Desativar nuvens chinesas](/pt/Recomendations/#disable-china-clouds)

Mesmo que você tenha desligado tudo na tela. A impressora ainda tenta enviar fotos e telemetria de vídeo para servidores chineses.

A configuração desse parâmetro como 0 desativa parcialmente esses recursos úteis para o fabricante.

**Se as nuvens chinesas estiverem desativadas, a impressora não procurará atualizações de firmware nativas.

Em vez disso, você pode usar:

- [zmod.link](/pt/Zmod/#zlink) - nuvem, para gerenciar impressoras via Fluidd/Mainsail.
- [Telegram bot](/pt/Macros/).

Se quiser atualizar o firmware nativo, você precisará ativar as nuvens chinesas, `SAVE_ZMOD_DATA CHINA_CLOUD=1`, reiniciar e atualizar o firmware nativo.

Para **desativar** as nuvens chinesas no firmware nativo:

- Formate a unidade flash para FAT32
- Coloque o arquivo [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) nessa unidade flash
- Desligue a impressora
- Insira a unidade USB na impressora
- Ligue a impressora
- A impressora será reinicializada uma vez
- Remova a unidade flash e use o firmware padrão.

Para **ativar** as nuvens chinesas no firmware nativo:

- Formate a unidade flash para FAT32
- Coloque o arquivo [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) na unidade flash.
- Desligue a impressora
- Insira a unidade USB na impressora
- Ligue a impressora
- A impressora será reinicializada uma vez
- Remova a unidade flash e use o firmware padrão.

---

##### NICE

Defina a prioridade do processo Klipper, 1 é a prioridade mínima, 40 é a máxima (20).

Exemplo: `SAVE_ZMOD_DATA NICE=20`.

Quanto maior a prioridade do Klipper, mais recursos ele terá, mas o Moonraker e a câmera travarão com mais frequência.

Para aqueles que conhecem o Linux:
```
NICE=20
grep -q "^nice = " /opt/config/mod_data/variables.cfg && NICE=$(grep "^nice = " /opt/config/mod_data/variables.cfg | cut -d "=" -f2| awk '{print $1}')
NICE=$((20-$NICE))
[ $NICE -ge 20 ] && NICE=19
[ $NICE -lt -20 ] && NICE=-20.
renice $NICE $(ps |grep klippy.py| grep -v grep| awk '{print $1}')
```

---

##### DISPLAY_OFF_TIMEOUT

Define o tempo, em segundos, em que a tela nativa é desligada ao operar no modo de tela não nativa. (180)

Observe que a tela nativa deve ter tempo para configurar o WiFi; o tempo mínimo é de 5 segundos.

Exemplo: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`.

---

##### PRO_POWEROFF_TIMEOUT

Define o tempo, em minutos, após o qual o FF5m Pro será desligado. (0)

Exemplo: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`.

---

##### SAVE_MOONRAKER

- 0 - Carrega os locais dos botões de macro do ZMOD (padrão)
- 1 - Permite salvar localmente as alterações dos botões de macro no Fluidd/Moonraker.

Ao salvar macros localmente, as novas macros serão colocadas em uma seção separada.

Exemplo: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`.

---

##### SAVE_FILAMENT_SENSORS

- 0 - Não salva o estado dos sensores de filamento após a reinicialização, eles sempre estarão ativados (padrão)
- 1 - Salvar o estado dos sensores após a reinicialização. Se você desativar um sensor, ele também será desativado após a reinicialização.

Exemplo: `SAVE_ZMOD_DATA SAVE_FILAMENT_SENSORS=1`.
