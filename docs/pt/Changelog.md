# Registro de mudanças

- Histórico da versão](#histórico-da-versão)
    - [Versão 1.6.6](#versão-166)
      - [Versão 1.6.5](#versão-165)
      - [Versão 1.6.4](#versão-164)
      - [Versão 1.6.3](#versão-163)
      - [Versão 1.6.2](#versão-162)
      - [Versão 1.6.1](#versão-161)
      - [Versão 1.6.0](#versão-160)
      - [Versão 1.5.4](#versão-154)
      - [Versão 1.5.3](#versão-153)
      - [Versão 1.5.2](#versão-152)
      - [Versão 1.5.1](#versão-151)
      - [Versão 1.5.0](#versão-150)
      - [Versão 1.4.3](#versão-143)
      - [Versão 1.4.2](#versão-142)
      - [Versão 1.4.1](#versão-141)
      - [Versão 1.4.0](#versão-140)
      - [Versão 1.3.1](#versão-131)
      - [Versão 1.3.0](#versão-130)
      - [Versão 1.1.2](#versão-112)
      - [Versão 1.1.1](#versão-111)
      - [Versão 1.1.0](#versão-110)
      - [Versão 1.0.5](#versão-105)
      - [Versão 1.0.4](#versão-104)
      - [Versão 1.0.0](#versão-100)
      - [Versão 0.2.4](#versão-024)
      - [Versão 0.2.3](#versão-023)
      - [Versão 0.2.2](#versão-022)
      - [Versão 0.2.1.1](#versão-0211)
      - [Versão 0.2.1](#versão-021)
      - [Versão 0.2.0](#versão-020)
      - [Versão 0.1.8](#versão-018)
      - [Versão 0.1.7](#versão-017)
      - [Versão 0.1.6](#versão-016)
      - [Versão 0.1.5](#versão-015)
      - [Versão 0.1.4](#versão-014)
      - [Versão 0.1.3](#versão-013)
      - [Versão 0.1.1](#versão-011)
      - [Versão 0.0.9-fix](#versão-009-fix)
      - [Versão 0.0.9](#versão-009)

## Histórico de versões

### Versão 1.6.6
27.01.2026

* Atualização do Fluidd/Mainsail/Klipper
* As atualizações do Klipper, Fluidd, Mainsail e Moonraker não dependem de atualizações de mods.

### Versão 1.6.5
14.01.2026

* Fluidd/Mainsail/Klipper atualizados
* Configurações adicionais da câmera estão disponíveis
* Auto Z-Offset

### Versão 1.6.4
11.12.2025

* Melhoria na facilidade de configuração e uso
* Atualização do Fluidd/Mainsail/Klipper
* Plugin de notificação
* Removido o crackle do IFS

### Versão 1.6.3
25.11.2025 - Ano do mod

* [zmod.link](https://zmod.link/link/) [ZLINK](/pt/Zmod/#zlink) - conexão remota com a impressora via nuvem
* Macro [SCREEN](/pt/System/#screen) - obtém uma captura de tela da tela da impressora
* Macro [LOAD_ZOFFSET_NATIVE](/Calibrations/#load_zoffset_native) - transfere as configurações de z-offset da tela nativa para o modo sem tela
* [AD5X](/pt/AD5X/): Adicionado o parâmetro global [REMOVE_FILAMENT](/pt/Global/#remove_filament) - remove o filamento após a impressão
* Adicionado o plug-in [Recommended settings plugin](https://github.com/ghzserg/recommend)
* Adicionado o idioma tcheco
* Adicionado controle de versão da MCU para o Klipper 13
* [AD5X](/pt/AD5X/): Adicionado botão de nivelamento
* [AD5X](/pt/AD5X/): Correções para o Klipper 13
* [AD5X](/pt/AD5X/): Correção para limpeza do bocal
* [AD5X](/pt/AD5X/): Remoção da trituração IFS
* ```CAMERA_ON VIDEO=video99``` - teste todas as câmeras disponíveis
* Verificação de atualizações após o término da impressão
* Ao remover a tabela via Fluidd/Mainsail, os tensils são redefinidos. Mas cabe ao usuário limpar o bico e aquecer a mesa antes.
* Correção do PURGE_LINE, não imprime em suportes
* Corrigida a colisão de bordas ao reimprimir
* Correção das escalas quando elas mostram várias toneladas
* Correção da desativação do chamber_fan após a conclusão da impressão
* Corrigida a exibição do tempo restante nos guppies para o idioma não russo

### Versão 1.6.2
27.10.2025

* [Plugin Support](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_ru.md)
* [Plugin g28_tenz](https://github.com/ghzserg/g28_tenz) - Estacionamento do eixo Z por células de carga
* Plugin bambufy](https://github.com/function3d/bambufy) - Compatível com o Bambu Studio e o Orca Slicer, melhora o controle da torre de alimentação, fornece estimativa precisa do tempo e do consumo de material, reduz o desperdício, oferece suporte à mudança rápida de cores e a recursos avançados de impressão. De @function3d.
* [Plugin nopoop](https://github.com/ghzserg/nopoop) - Maximize a redução de desperdício de @ninjamida
* Fluidd: Suporte a cores
* Mainsail: Suporte a cores De @function3d, problema de erro 404 corrigido após a atualização da página
* Guppy: Suporte a cores. Integração HA corrigida.
* Adicionada a conexão automática de pen drives ao trabalhar com o Guppy
* Adicionada a ativação de [WiFi](/pt/Global/#wifi) diretamente sem usar a tela nativa
* [AD5X](/pt/AD5X/): Resolvido o problema de corte de cesta e filamento em revisões mais recentes
* [AD5X](/pt/AD5X/): Suporte a cores para recuperação de impressão
* [AD5X](/pt/AD5X/): Capacidade de criar [seus próprios tipos e cores de filamentos](/pt/AD5X/#7-add-your-own-filament-types) ao trabalhar sem uma tela nativa
* Klipper e Monnraker atualizados
* Adicionado suporte para ens160.py de @minicx
* Adicionado o idioma português
* Correções de bugs
* Compatibilidade aprimorada com as versões mais recentes do firmware nativo

### Versão 1.6.1
06.09.2025

- [AD5X](/pt/AD5X/) - Suporte para o Klipper 13. [UPDATE_MCU](/pt/System/#update_mcu)
- [AD5X](/pt/AD5X/) - Sensor de temperatura do cabeçote
- [AD5X](/pt/AD5X/) - Funciona sem tela nativa. O IFS funciona totalmente com a configuração do valor de redefinição
- Pequenas correções

### Versão 1.6.0
14.08.2025

- AD5M - Suporte para o Klipper 13. [UPDATE_MCU](/pt/Sistema/#update_mcu)
- AD5M - Sensor de temperatura no cabeçote
- Pequenas correções

Agradecemos a [@darksimpson](https://github.com/darksimpson) pelo suporte à MCU.

Para suporte a tens, obrigado a [@minicx](https://github.com/loss-and-quick/)

### Versão 1.5.4
28.06.2025

- AD5X - o som funciona
- AD5X - células de carga e controle de impacto do bico na mesa funcionam
- AD5X - o bot de telegrama funciona
- AD5X - trabalhos com sensor de filamento
- AD5X - configuração do PID da mesa do prinetron funciona
- AD5X - restaurada a limpeza do bocal ao remover o cartão da mesa
- AD5X - o mod testado funciona no firmware 1.0.9, 1.1.0, 1.1.1
- AD5X - criado [unidade flash instalando a tela versão 1.0.7 e todos os outros módulos versão 1.1.1](/en/Native_FW/)
- AD5X - criado [pen drive de reinicialização da impressora](/pt/Native_FW/)
- AD5X - criado [stick de ativação do mod, após a atualização do firmware nativo](/pt/Native_FW/)

### Versão 1.5.3
03.06.2025

* Corrigido o bug do Klipper [#119](https://github.com/ghzserg/zmod/issues/119) que tornava necessário usar [this](/pt/Recomendations/#don't-use-Russian-names-in-object-names)
* O controle do bocal agora também está ativado ao imprimir a partir da tela de uma só vez.
* Pequenas correções cosméticas

### Versão 1.5.2
15.05.2025

* Estrutura da documentação atualizada graças a @TMTYD
* Nova macro RESTORE_TAR_CONFIG
* Correção da tela do Guppy
* Correções de bugs do **AD5X** HOME
* Atualização do Moonraker
* Mudança na aceleração do estacionamento
* Nuvens chinesas ativadas por padrão

### Versão 1.5.1
23.04.2025

- AD5X**: suporte ao firmware AD5X-1.0.8-1.0.5-20250418
- **AD5X**: correção do _LINE_PURGE
- **AD5X**: suporte para atualização do MCU IFS
- **AD5X**: correção de MESH_TEST
- **AD5X**: correção do _SMART_PARK
- **AD5X**: correção do driver_fan
- **AD5X**: corrige _HOME
- Correções cosméticas CHECK_MD5
- Retornar chamber_fan para o Moonraker
- Correção da exclusão de objetos
- Corrigir guppyscreen para diferentes idiomas

### Versão 1.5.0
17.04.2025
Suporte para idiomas de interface:

- ZMOD - inglês, alemão, francês, italiano, espanhol, chinês, japonês, japonês, coreano
- GuppyScreen - inglês, alemão, francês, italiano, espanhol

### Versão 1.4.3
23.03.2025

- Configuração automática da câmera da Web
- Quando a interface WEB é alterada, a seguinte mensagem é exibida
- 5X. Corrigido o erro de fechamento rápido de diálogos
- 5X. Correção do estacionamento
- Corrigido o problema de desligamento da tela em novas revisões da impressora

### Versão 1.4.2
19.03.2025

- Funcionalidade aprimorada do [controle de impacto do bico](/pt/Global/#nozzle_control), agora é possível [usar pausa](/pt/Global/#nozzle_control) em vez de desligar. Tarefa [#23](https://github.com/ghzserg/zmod/issues/23)
- Aprimorada a função de verificação do sistema.
- Alterado o esquema de cores do Fluidd
- Adicionado o parâmetro global [SAVE_MOONRAKER](/pt/Macros/#save_moonraker) - permite usar o local dos botões de macro personalizados.
- O GuppyScreen funciona no AD5X
- No AD5X, a nova macro [COLOR](/pt/Filament/#color) controla o tipo de plástico, a cor do plástico, o carregamento e o descarregamento do filamento de carretéis coloridos.
- Alterado o algoritmo de teste da tabela antes da impressão, introduzido o novo parâmetro global [MESH_TEST](/pt/Macros/#mesh_test)
- Corrigido o bug [#13](https://github.com/ghzserg/zmod/issues/13) (Impressão no ar após o KAMP)
- Corrigido o bug [#14](https://github.com/ghzserg/zmod/issues/14) (Restaurar a impressão na tela nativa)
- Corrigido o bug [#31](https://github.com/ghzserg/zmod/issues/27) (Congela na GuppyScreen)
- Corrigido o bug [#25](https://github.com/ghzserg/zmod/issues/25) (AD5X. A calibração da mesa não está funcionando corretamente)
- Corrigido o bug [#26](https://github.com/ghzserg/zmod/issues/26) (AD5X. Sem espectrograma de cinturão)
- Corrigido o bug [#27](https://github.com/ghzserg/zmod/issues/27) (AD5X. Erro no instalador)

### Versão 1.4.1
09.03.2025

- A soma MD5 dos arquivos descompactados é verificada durante a instalação do zMod. A impressora corrompe periodicamente os arquivos ao copiar arquivos de uma unidade flash para o sistema de arquivos.
- A macro CHECK_SYSTEM introduziu a autoverificação do sistema
- O botão de desligamento funciona na versão Pro
- Possibilidade de instalar câmeras não MJPEG
- Suporte alfa para FF5X:
  Recursos conhecidos:

  - Sem Entware, portanto NEW_SAVE_CONFIG e CLOSE_DIALOGS não funcionam
      - Não reproduz música
      - Não há calibração de tabela de PID, pois não há PID lá
      - Especifique VIDEO3 ao ativar a câmera
      - Não há células de carga e, consequentemente, não há proteção da tabela e redefinição das células de carga.
      - Não há sensor de movimento do filamento disponível na máquina de corte

### Versão 1.4.0
04.03.2025

- Moonraker, Fluidd e Python atualizados
- [Restaurar a impressão na perda de energia](/pt/Zmod/#zrestore)
- Construir espectrograma do cinto](/pt/Macros/#belts_shaper_calibration)
- Verificação da placa carregada, verifica se o mapa da tabela é aproximadamente igual à placa carregada no momento
- Trabalho implementado com o [sensor de movimento do filamento](/pt/Macros/#motion_sensor)
- GuppyScreen: exclusão de objeto, saída de erro, reversão de firmware, calibração de PID, redefinição de peso, trabalho com FF5M Pro
- Executar macro na [próxima camada](/pt/Macros/#set_pause_next_layer) ou [em uma camada específica](/pt/Macros/#set_pause_at_layer)
- Registro de todas as mensagens de tela nativa para o Klipper e respostas a essas mensagens
- Alteração do algoritmo de remoção do shaper, os gráficos do shaper são plotados com o SCV levado em consideração
- Macro MUTE - mudo antes da reinicialização
- Novo parâmetro - [native screen off timeout](/pt/System/#display_off_timeout)
- Novo arquivo `mod_data/power_off.sh` - permite escrever código a ser executado quando a impressora é desligada
- Ativação do estacionamento inteligente ao usar o KAMP
- Correção de erros de remoção de mod, desativação de mod e remoção completa de mod
- Correção da pré-limpeza
- Corrigido o controle do bocal que atingia a mesa. Só funciona durante a impressão.
- Correção do movimento da cabeça da impressora com botões no Fluid/GuppyScreen
- Correção da pausa no modo de tela não nativa
- Correção da operação KAMP

### Versão 1.3.1

- Melhorias no GuppyScreen: COLDPULL, controle PID, retrações de firmware, calibração do shaper, calibração da esteira, correções cosméticas
- O controle do bocal funciona agora somente durante a impressão
- BELTS_SHAPER_CALIBRATION
- Melhoria da operação sem tela nativa
- Melhoria no trabalho de fechamento lento de janelas e NEW_SAVE_CONFIG

### Versão 1.3.0
08.02.2025

- Suporte a [GuppyScreen](/pt/System/#display_off)
- Klipper 12, [em modo de teste](/pt/Macros/#update_mcu) (desativado por padrão). Não funciona nele: aquecimento da extrusora, temperatura da extrusora, escalas.
- Substituímos o cliente SSH `dropbear` e o servidor SSH pela versão atual.
- Substituído o `mjpg_streamer` pela versão com o patch Alexander, reduzindo o consumo de memória em 2 a 4 vezes.
- Corrigida a exclusão de objetos de Igor Polunovskiy (agora o suporte é levado em consideração).
- Plotagem do shaper levando em conta o SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](/pt/Global/#fix_scv).
- CHECK_SYSTEM](/pt/System/#check_system) - Adicionada a verificação de permissões de arquivos e diretórios, verificação de links e recuperação.
- Removida a macro SOFT_REMOVE.
- Atualizados Moonraker, Fluidd, Mainsail

### Versão 1.1.2
03.02.2025

- Nova macro [CHECK_SYSTEM](/pt/System/#check_system) - Verifica se há arquivos corrompidos no sistema operacional da impressora.
- Nova macro [NOZZLE_CONTROL](/pt/Global/#nozzle_control) - Desligamento de emergência da impressora se for detectada a quebra de uma peça ou se o bico atingir a mesa.
- Nova macro [UPDATE_MCU](/pt/Macros/#update_mcu) - Atualiza a MCU na impressora.
- Novo sinalizador global [NICE](/pt/Macros/#nice) - Define a prioridade do processo Klipper, 1 é a prioridade mínima, 40 é a máxima (20).
- Novo sinalizador global [FIX_E0011](/pt/System/#fix_e0011) - Corrige o erro E0011, bem como o `Tempo limite de comunicação durante o homing`.
- Limpa o sistema de arquivos da impressora de arquivos excluídos, acelera o EMMC.
- Várias pequenas correções

### Versão 1.1.1
24.01.2025

- Corrigido o problema com a ordem se a chamada de retorno estiver bloqueada no manipulador de botões [#6440](https://github.com/Klipper3d/klipper/pull/6440) encontrado [Alexander K](https://github.com/drA1ex) - agora [LOAD_CELL_TARE](/pt/Macros/#load_cell_tare) funciona como deveria.
- Removidos os parâmetros globais: `ALTER_CELL_TARE`, `IGNORE_CELL_TARE`, `CELL_WEIGHT`.
- Aumento do tempo limite do zsend. São exibidas mensagens adicionais.
- O G28 agora estaciona primeiro Z, depois X e Y
- Nova macro [CAMERA_RESTART](/pt/Macros/#camera_restart) - Reinicia a implementação da câmera alternativa
- Código corrigido para cancelamento de impressão sem tela nativa
- Implementação de EXCLUDE_OBJECT_DEFINE por Igor Polunovskiy
- Em caso de impressão repetida, os motores não são desligados e a impressora não é reiniciada, mesmo que isso esteja especificado nos parâmetros globais
- Na macro [TEST_EMMC](/pt/Macros/#test_emmc), o desgaste do cartão EMMC é exibido
- Correção da desativação das nuvens chinesas

### Versão 1.1.0
15.01.2025

- Moonraker atualizado
- Velocidade de carregamento do moonraker bem aumentada
- Ocultação de `level_h1`, `level_h2`, `level_h3`, `power_off`, `clear_power_off`, `level_clear`, `check_level_pin_alt`.
- A implementação de Igor Polunovskiy é usada para redefinir as células de carga no modo de tela não nativo
- Redefinição das células de carga, agora somente na mesa aquecida
- Novo parâmetro global [ALTER_CELL_TARE](/pt/Macros/#alter_cell_tare). Permite contornar o erro [load cell reset error](/pt/FAQ/#alter_cell_tare error).
- O novo parâmetro global [CELL_WEIGHT](/pt/Macros/#cell_weight) especifica em que peso as células de carga não devem ser calibradas
- Novo parâmetro global [CHINA_CLOUD](/pt/Global/#china_cloud) - permite desativar as nuvens chinesas.
- Atualização da configuração da impressora reescrita
- Na versão Pro, os ventiladores do soprador agora funcionam corretamente. Os ângulos padrão são 165/105
- A velocidade do resfriador agora é definida durante a calibração da extrusora
- A hora e o fuso horário no moonraker agora correspondem ao horário do klipper
- A guia `Informações do sistema` exibe a versão nativa do firmware.
- Redução da capacidade de falar do mod

### Versão 1.0.5
13.01.2025

- Adicionado parâmetro à macro [AUTO_REBOOT](/pt/Macros/#auto_reboot) que permite reiniciar o firmware.
- G28 em macros é chamado somente se necessário
- Alteramos quase completamente o algoritmo MD5. Agora, a verificação do MD5 funciona em qualquer lugar e não exige o aquecimento da mesa ou da extrusora.
- A macro aprimorada [MEM](/pt/Macros/#mem) agora exibe a memória do Moonraker, do Klipper, do Shield e como o SWAP é usado
- O processo do klipper tem uma prioridade mais alta do que os outros processos
- O parâmetro global [PRINT_LEVELING](/pt/Global/#zshaper) agora também funciona em telas não nativas
- A macro [BED_LEVEL_SCREWS_TUNE](/pt/Calibrations/#bed_level_screws_tune) agora usa a temperatura corretamente.
- A macro [TEST_EMMC](/pt/Macros/#test_emmc) pode testar EMMC, USB Flash e RAM.
- A troca agora pode ser (mas não precisa ser) colocada no USB Flash
- Macro [CLEAR_EMMC](/pt/System/#clear_emmc) - limpeza de registros e/ou GCODEs
- Solução de problemas [E0017](/pt/System/#fix_e0017)

### Versão 1.0.4
05.01.2025

- Suporte [rollback do firmware](/pt/FAQ/#what-is-rollback-firmware)
- Correção [E0017](/pt/Sistema/#fix_e0017)
- Liga automaticamente o sopro do driver quando os motores são ligados. Resolve o problema de remoção de shapers sem sopro de estoque.
- Nova macro [TEST_EMMC](/pt/Macros/#test_emmc) - Grava o tamanho do MB no EMMC e grava a velocidade de leitura e gravação.
- Nova macro [CLEAR_EMMC](/pt/System/#clear_emmc) - Limpa a EMMC.
- Reinício automático do bot quando executado por SSH](/pt/Macros/#zssh_on)
- [Auto-clean](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) - vídeos com mais de 10 dias no bot.
- Definir [fuso horário desejado](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) no bot
- Alternar automaticamente de KAMP [LINE_PURGE](/pt/Global/#clear) para _CLEAR2 se nenhum objeto for encontrado
- Correção da operação [SKIP_ZMOD](/pt/Macros/#skip_zmod)
- A atualização do fluidd/mainsail agora não requer reinicialização
- A alteração de fluidd para mainsail agora não requer reinicialização
- O Zmod reporta arquivos se forem usados arcos neles
- Correção do script `addMD5.sh
- Correção do controle de resfriamento do driver para versão de tela não nativa
- Carregamento do mapa de mesa `auto` para versão de tela não nativa na inicialização da impressora

### Versão 1.0.0
23.12.2024

- Novo sistema de atualização e instalação, agora quase todas as atualizações podem ser recebidas pela rede
- Novo parâmetro de macro [CAMERA_ON](/pt/Zmod/#camera_on), VIDEO - dispositivo de vídeo (video0)

### Versão 0.2.4
21.12.2024

- O ZMOD grava automaticamente se deseja atualizar a partir do pen drive - agora na cor vermelha
- Se a remoção nativa do mapa da tabela da tela for usada (PRINT_LEVELING=1), os parâmetros FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH em START_PRINT serão ignorados
- Pausa, mesmo ao imprimir a partir da tela no canto direito
- O parâmetro PRRECLEAR agora também funciona ao imprimir com a construção do mapa a partir da tela
- Alterado o algoritmo de instalação, agora, após a instalação bem-sucedida, não é necessário remover o pendrive USB - a impressora se reinicializará e excluirá o arquivo de instalação.

### Versão 0.2.3
19.12.2024

- O ZMOD grava automaticamente se for necessário atualizar a partir de um pendrive USB.
- Macro [M600](/pt/Macros/#m600) aprimorada - substitui o filamento com uma pausa durante a impressão.
- Controle MD5 aprimorado - agora exibe mensagem se o MD5 não for encontrado

### Versão 0.2.2
17.12.2024

- Nova macro [FAST_CLOSE_DIALOGS](/pt/Macros/#fast_close_dialogs) - Faz com que as caixas de diálogo sejam fechadas rapidamente na tela nativa. Usado para fechar uma janela quando a impressão é concluída ou quando a impressão é cancelada. *Para que as caixas de diálogo de fechamento rápido funcionem, vá para a guia Configurações -> Ícone WiFi -> Modo de rede -> ative o controle deslizante "Somente redes locais": @darksimpson
- Nova macro [LEVELING_PRINT_FILE](/pt/Macros/#leveling_print_file) - Imprime um arquivo com plotagem de mapa de tabela a partir da tela nativa. *Para LEVELING_PRINT_FILE, é necessário ir para a guia "Settings" (Configurações) -> "WiFi icon" (Ícone WiFi) -> "Network mode" (Modo de rede) -> ative o controle deslizante "Local networks only" (Somente redes locais) por meio do menu da tela da impressora.
- Nova macro [COLDPULL](/pt/Filamento/#coldpull) Coldpull (limpeza do bico) sem violência. Implementação de [this algorithm](https://t.me/FF_5M_5M_Pro/2836/447172)
- Novos parâmetros [SAVE_ZMOD_DATA](/pt/Global/#save_zmod_data):
    - [PRINT_LEVELING](/pt/Global/#save_zmod_data) - construir mapa de mesa com tela nativa significa 0-não, 1-sim (0) em cada impressão. *Para remover o mapa da área de trabalho da tela nativa, vá para a guia "Configurações" -> "Ícone WiFi" -> "Modo de rede" -> ative o controle deslizante "Somente redes locais" por meio do menu da tela da impressora.
      - [USE_KAMP](/pt/Global/#save_zmod_data) - onde é possível usar o mapa adaptável da área de trabalho (KAMP) em vez do mapa completo da área de trabalho 0-não, 1-sim (0). *Permite usar o KAMP ao obter um mapa de tabela pela rede a partir da tela nativa.
      - CLOSE_DIALOGS](/pt/Global/#save_zmod_data) - fecha automaticamente as caixas de diálogo quando terminadas e quando a impressão é cancelada 0-não, 1-sim lento, 2-sim rápido. *Para que o fechamento rápido das caixas de diálogo funcione, vá para a guia "Settings" (Configurações) -> "WiFi icon" (Ícone WiFi) -> "Network mode" (Modo de rede) -> ative o controle deslizante "Local networks only" (Apenas redes locais)* (0) por meio do menu da tela da impressora.
      - [USE_SWAP](/pt/Global/#save_zmod_data) - Usar SWAP 0-não, 1-sim (1). *Se você tiver um processador sem solda, o SWAP é obrigatório.

#### Versão 0.2.1.1
10.12.2024

- Algoritmo assíncrono de reprodução de arquivos MIDI
- Correção da instalação
- Correção do SHUTDOWN do menu principal
- Novo script [addMD5.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.4/addMD5.sh) - controle md5 para macOS/Linux - obrigado Alexander
- Novo parâmetro [STOP_MOTOR](/pt/Global/#save_zmod_data) - desliga automaticamente os motores após a impressão/cancelamento depois de 25 segundos.
- Novo parâmetro [AUTO_REBOOT](/pt/Global/#save_zmod_data) - reinicia automaticamente a impressora 1,5 minutos após a impressão.
- Novo parâmetro [PRECLEAR](/pt/Global/#save_zmod_data) - usa a pré-limpeza do bocal em START_PRINT
- Nova música: BattleCity, IndianaJones, WeWillRockYou de [@drmax_gc](https://t.me/drmax_gc)

### Versão 0.2.1
10.12.2024

- Obtenção de um gráfico do shaper diretamente da impressora. Macro [ZSHAPER](/pt/Calibrations/#zshaper)
- Correção de bug ao trabalhar sem tela nativa

### Versão 0.2.0
09.12.2024

- Atualização do fluidd/mainsauil
- Adicionar mc, opkg, gdb
- Reinicialização via menu superior do fluidd
- Correções de erros
- Grande reformulação da macro [START_PRINT](/pt/Main/#start_print)
- Macro [NEW_SAVE_CONFIG](/pt/Macros/#new_save_config) - salvar alterações/recarregar o clipper sem congelamento de tela nativo. Implementação de @darksimpson
- Macro [CLOSE_DIALOGS](/pt/Macros/#close_dialogs) - fecha janelas quando a impressão é concluída e quando a impressão é cancelada. Implementação por @darksimpson
- Macro [STOP_ZMOD](/pt/Macros/#stop_zmod) - desativa o moonraker
- Macro [START_ZMOD](/pt/Macros/#start_zmod) - ativa o moonraker
- Macro [SAVE_ZMOD_DATA](/pt/Global/#save_zmod_data) - salva os parâmetros do ZMOD.
    - CLOSE_DIALOGS - fecha automaticamente as caixas de diálogo quando a impressão é concluída e cancelada 0-não, 1-sim (0)
        - NEW_SAVE_CONFIG - usar NEW_SAVE_CONFIG alternativo ao calibrar o PID 0-não, 1-sim (0)
        - LED - brilho do LED quando ligado (50)
        - MIDI_ON - reproduzir MIDI quando ligado ("")
        - MIDI_START - Reproduzir MIDI no início da impressão ("")
        - MIDI_END - Reproduzir MIDI no final da impressão ("")

### Versão 0.1.8
04.12.2024

- Suporte à conexão do bot do Telegram
- Macro [ZSSH_ON](/pt/Macros/#zssh_on) - ZSSH_ON SSH_SERVER SSH_PORT SSH_USER VIDEO_PORT MOON_PORT
- Macro [ZSSH_OFF](/pt/Macros/#zssh_off) - desliga o cliente SSH
- Macro [ZSSH_RESTART](/pt/Macros/#zssh_restart) - reinicia o cliente SSH

#### Versão 0.1.7
03.12.2024

- Várias correções de macro
- Macro [STOP_ZMOD](/pt/Macros/#stop_zmod) - desativa temporariamente o fluidd/mainstaill e o moonraker

### Versão 0.1.6
02.12.2024

- Corrigida a localização dos registros
- Correção da macro [LOAD_CELL_TARE](/pt/Macros/#load_cell_tare)
- Correção da macro de calibração do PID da extrusora e da mesa
- Macro [CLEAR_NOZZLE](/pt/Macros/#CLEAR_NOZZLE) - limpeza do bocal como no firmware nativo
- Macros [KAMP](/pt/Calibrations/#kamp) extruder_temp=[nozzle_temperature_initial_layer] bed_temp=[bed_temperature_initial_layer_single]. Mapa de tabela adaptável com limpeza de bico.
- [AUTO_FULL_BED_LEVEL](/pt/Calibrations/#auto_full_bed_level) - macro completamente reescrita

### Versão 0.1.5
30.11.2024

- Adicionada a vela principal. Comutação via macro WEB
- Macro STOP - desliga os motores, escrita no gcod final.
- Macro [ZSHAPER](/pt/Calibrations/#zshaper) - calibra shapers e carrega arquivos csv para /mod_data na configuração. Análise adicional via (https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)
- Macro [LOAD_CELL_TARE](/pt/Macros/#load_cell_tare) - redefine as células de carga
- Calibração de mesa corrigida. Agora é possível definir a temperatura da mesa e da extrusora para calibração. Padrão 120/80
- Foi corrigido o desligamento da tela no modo de tela não nativa. Ela será desligada após 4 minutos.

### Versão 0.1.4
29.11.2024

- Adicionado controle de câmera do mod. Permite a memória t. E trabalhar com a câmera com a tela desligada. Também é possível alterar a resolução da câmera. (A implementação é imitada de Pavel Mironov)
- Corrigido o bug do instalador que, na última versão, podia excluir [heater_bed] dos arquivos de configuração
- Imagens alteradas durante a instalação. Implementado [@drmax_gc](https://t.me/drmax_gc)
- As macros foram categorizadas e traduzidas para o russo
- Macro [DATE_GET](/pt/Macros/#date_get) - ver a hora atual
- Macro [DATE_SET](/pt/Macros/#date_set) - define a hora atual
- Macro [CAMERA_ON](/pt/Zmod/#camera_on) - Usar implementação de câmera alternativa
- Macro [CAMERA_OFF](/pt/Macros/#camera_off) - Desativa a implementação da câmera alternativa

### Versão 0.1.3
28.11.2024

- Adicionada a reprodução de MIDI. Os arquivos são armazenados em mod_data/midi - acesso pela guia de configuração. Agradecimentos a [@drmax_gc](https://t.me/drmax_gc)
- Macros [PLAY_MIDI](/pt/Macros/#play_midi). Reproduz a melodia PLAY_MIDI FILE=Pain-Shut-your-mouth.mid
- Macro [SOFT_REMOVE](/pt/Macros/#soft_remove). Remove apenas o zMod, deixa áudio, md5, root
- Após a atualização, as configurações do moonraker são preservadas
- As configurações do usuário para o klipper são movidas para mod_data/user.cfg.
- As configurações do usuário para o moonraker são movidas para mod_data/user.moonraker.conf
- Quando a tela é desligada, ele mostra o texto que diz que a tela está desligada. Obrigado @drmax_gc
- Corrigido o erro de calibração da cama via macro. A cama agora está aquecendo.
- Corrigido o erro de calibração da cama por meio de macro. A cama agora está aquecendo.

### Versão 0.1.1
27.11.2024

- Suporta a execução com a tela nativa desativada. Isso economiza 20 megabytes de RAM. Para ativar esse modo, você precisa chamar a macro DISPLAY_OFF. O clipper será reinicializado e usará arquivos de configuração alternativos. Recomenda-se remover o mapa da tabela e salvar no perfil padrão. Após a reinicialização, a tela ficará indisponível após 5 minutos e o mapa da tabela do perfil padrão será carregado.
- Macros [MEM](/pt/Macros/#mem) - mostra a quantidade de memória usada e por qual aplicativo.
- Macro [DISPLAY_ON](/pt/System/#display_on) - retorna a tela ao modo padrão, a impressora será reinicializada
- Macros [LED](/pt/Macros/#led) - acenderá a luz de fundo em 50%
- Macro [LED_ON](/pt/Macros/#led_on) - ligará a luz de fundo em 100%.
- Macro [LED_OFF](/pt/Macros/#led_off) - desliga a luz de fundo

### Versão 0.0.9-fix
25.11.2025

- Corrigido o erro de instalação.

### Versão 0.0.9
25.11.2025

- Implementação de pausa durante a impressão, tratada por meio da tela nativa
- Implementada a recuperação da pausa, tratada por meio da tela nativa
- Cancelamento de impressão implementado, tratado por meio da tela nativa
- [REBOOT](/pt/Macros/#reboot) - macro reinicia a impressora
- SHUTDOWN](/pt/Macros/#shutdown) - macro para desligar a impressora
- SKIP_ZMOD](/pt/Macros/#skip_zmod) - macro para reiniciar sem iniciar o moonraker e o fluidd
- [REMOVE_ZMOD](/pt/Macros/#remove_zmod) - macro para remover mods
- Corrigido o bug: "Após uma pausa devido à ativação do sensor de movimento do filamento, ele restaura a impressão, mas imprime no ar cerca de 3 centímetros acima do local onde deveria estar".
