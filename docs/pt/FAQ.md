## FAQ
## Perguntas frequentes

> Instalei um mod.
>
> Você não quer entender nada - imprima como você fez.
>
> Você não precisa ajustar ou alterar nada.
>
> Se você decidir que está pronto para seguir em frente, siga em frente lendo a documentação.

### Como o ZMOD difere do KlipperMod/firmware nativo

   A diferença entre o KlipperMod e o ZMOD:

  - O KlipperMod usa o Klipper puro com um mínimo de alterações específicas do flashforge 5m(pro)
      - O ZMOD usa o Klipper padrão do firmware nativo, bem como o Klipper 13.
      - O KlipperMod usa o KlipperScreen como uma tela para a impressora.
      - O ZMOD usa a tela nativa ou o GuppyScreen em vez do KlipperScreen
      - O KlipperMod usa o moonraker-timelapse
      - O ZMOD usa o moonraker-telegram-bot em um host EXTERNO que suporta timelapse ou [TimeLapse plugin](https://github.com/ghzserg/timelapse/).

Filosofia diferente.

* O KlipperMod é essencialmente uma implementação de firmware alternativa.
* ZMOD é uma interferência mínima com o firmware nativo. Todas as funções do firmware nativo são preservadas.

É por isso que não haverá G17, G18, G19 no ZMOD - embora isso seja fácil. Não haverá atualizações para o clipper nativo, nem renomeação ou alteração de macros padrão, configurações, nomes de pinos, etc.

O ZMOD NÃO é baseado no KlipperMod e NÃO é uma evolução dele. Dito isso, o ZMOD usa algumas macros e scripts do KlipperMod, e também usa desenvolvimentos do KlipperMod. Mas você não deve esperar do ZMOD um comportamento semelhante ao do KlipperMod.

**O ZMOD é binário incompatível com o KlipperMod.

#### O que está no KlipperMod e o que não está no ZMOD:

- [KlipperScreen](https://klipperscreen.readthedocs.io/en/latest/) - tela para impressora. No ZMOD, em vez de KlipperScreen, é uma tela nativa ou GuppyScreen
- [Moonraker-timelapse](https://github.com/mainsail-crew/moonraker-timelapse) - o ZMOD usa o bot do Telegram ou [TimeLapse plugin](https://github.com/ghzserg/timelapse/).
- Configuração de rede via iwd/wpa_supplicant (no caso de guppyscreen) - na configuração de rede do zMod via tela nativa, a inicialização da rede também é possível no modo de tela não nativa

#### O que está no ZMOD e o que não está no KlipperMod:

- Suporte [AD5X](/pt/AD5X/)
- Suporte para [os seguintes idiomas](/pt/Global/#lang): inglês, alemão, francês, italiano, espanhol, chinês, japonês, coreano.
- Operação de tela nativa
- [Restauração de impressão por falha de energia](/pt/Zmod/#zrestore)
- [Remoção de shaper com geração de gráfico](/pt/Calibrations/#zshaper) levando em conta [SCV](/pt/Global/#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
- [Verificar e restaurar arquivos/direitos/ligações simbólicas do sistema de arquivos nativo](/pt/System/#check_system)
- Atualização automática do `Fluidd`/`Mainsail`/`Moonraker` e do ZMOD pela rede
- [Entware](/pt/FAQ/#-zmod-entware-entware--how-to-use-it)
- Bug corrigido [E0017](/pt/Sistema/#fix_e0017)
- Além disso, o GuppyScreen suporta: calibração de PID, controle de flap, reversão de firmware, limpeza de bocal, redefinição de célula de carga, ajuste de parafuso, ColdPull, mapa de tabela finalizado
- Operação fixa dos ventiladores do soprador do driver. Eles são ligados automaticamente quando os motores estão funcionando. No firmware nativo - somente durante a impressão.
- Remoção do mapa da tabela adaptável [KAMP](/pt/Calibrations/#kamp)
- Calibração do PID do [extrusor](/pt/Calibrations/#pid_tune_extruder) e da [mesa](/pt/Calibrations/#pid_tune_bed), inclusive via GuppyScreen.
- Implementação do [COLDPULL/coldpull](/pt/Filament/#coldpull) (limpeza do bocal) sem violência. Realização de [este algoritmo](https://t.me/FF_5M_5M_Pro/2836/447172)

---

#### O que está no ZMOD e o que não está no firmware nativo:

- Suporte a Moonraker/Fluidd/Mainsail
- Suporte ao bot do Telegram
- Suporte ao Klipper 13
- Todos os recursos listados em comparação com o KlipperMod.
- O firmware nativo envia muitos dados para servidores chineses (https://github.com/FlashForge/Orca-Flashforge/issues/26), o que pode ser evitado com o uso do zmod com o GuppyScreen.

---

## Armazenamento de configurações

Acesso à pasta **mod_data** por meio da interface da Web do fluidd.

`Configuration` -> `Configuration files` -> `mod_data`.

- As configurações personalizadas do klipper devem ser inseridas no arquivo `mod_data/user.cfg`; as configurações gravadas nesse arquivo podem substituir/adicionar as configurações dos arquivos `printer_base.cfg` e zMod.
- As configurações personalizadas do moonraker devem ser inseridas no arquivo `mod_data/user.moonraker.conf`
- As músicas personalizadas são armazenadas em `mod_data/midi/`
- As configurações globais do mod são armazenadas por meio da macro [SAVE_ZMOD_DATA](/pt/Global/#save_zmod_data) *nyuhler*
- O código a ser executado quando a impressora é desligada é armazenado aqui `mod_data/power_off.sh`.
- O código a ser executado quando a impressora é ligada é armazenado aqui `mod_data/power_on.sh`.

**Não modifique os arquivos zmod e plugin**, pois isso interromperá o sistema de atualização.

Qualquer função pode ser substituída em `mod_data/user.cfg` ou `printer.cfg`

---

## Recursos conhecidos:

- Se a impressora executar qualquer ação `M109` (aquecimento da extrusora), `M190` (aquecimento da mesa), calibração do PID - basicamente qualquer ação que faça o gcod pausar, a tela nativa congelará
- Se o klipper for reiniciado (depois de salvar o mapa da tabela, PID, Shapers, etc.), a tela nativa congela (use a reinicialização via [NEW_SAVE_CONFIG](/pt/Main/#new_save_config).
- Depois de cancelar a impressão, a tela nativa precisa clicar em Ok (use a macro [CLOSE_DIALOGS](/pt/Main/#close_dialogs) ou [FAST_CLOSE_DIALOGS](https://github.com/ghzserg
/zmod/wiki/Main_en/Main_en#fast_close_dialogs))

- A tela nativa sempre carrega o perfil `DEFAULT_MESH` quando a impressão é carregada e sempre exclui o perfil `Default` quando a impressão é concluída

---

## Recursos da versão sem tela nativa

- É necessário remover todo o código de início e escrever [START_PRINT](/pt/Main/#start_print) e, no final, [END_PRINT](/pt/Main/#end_print)
- A câmera não funciona, é necessário iniciar a câmera alternativa por meio da macro [CAMERA_ON](/pt/Zmod/#camera_on).
- Se necessário, é preciso escrever manualmente o parâmetro `Z_OFFSET` na macro [START_PRINT](/pt/Main/#start_print) ou usar o parâmetro global [LOAD_ZOFFSET](/pt/Global/#load_zoffset) que carrega o Z-offset dos parâmetros globais salvos anteriormente via SET_GCODE_OFFSET. *crot.
- Se quiser transferir o z-offset da tela nativa para o modo de tela não nativa, chame a macro ```LOAD_ZOFFSET_NATIVE```, que lerá o valor do z-offset da tela nativa e o aplicará ao modo de tela não nativa.
- A impressora carrega automaticamente o mapa de mesa `auto` quando a impressora é ligada
- O envio por meio do protocolo FlashForge não funciona, pois é controlado pela tela.
  Você precisa mudar para o protocolo Octo/Klipper:

  - Protocolo: `Octo/Klipper`.
      - Nome do host: `IP_printer_name:7125`.
      - Endereço URL do host: `IP_printer` ou `IP_printer:80`

---

### Qual é a diferença entre trabalhar com e sem a tela nativa?

A impressora pode ser operada em dois modos:

- Com tela nativa - nesse caso, quase toda a lógica é controlada pela tela nativa e muitas coisas não podem ser alteradas.
- Sem tela nativa - nesse caso, todos os recursos são controlados pelo zMod.
Isso não significa que você precise desativar a tela por hardware ou alterá-la para outra.
No modo de tela não nativa, você pode usar a tela alternativa do software GuppyScreen ou desligar a tela completamente e ela será desligada.

**Não desative a tela a menos que entenda claramente como funcionam o mapa da tabela, o z-offset e as macros START_PRINT e END_PRINT**

Nossa impressora tem 128 megabytes de memória, metade é consumida pelo sistema e 13 megabytes (20 em versões mais antigas do firmware nativo) são consumidos pelo controle de tela nativo.

Se [desativar a tela nativa](/pt/System/#display_off), economizaremos memória.

Mas, nesse caso, as ferramentas de impressão integradas começam a funcionar de forma diferente (iniciar a impressão, pausar, restaurar, cancelar, encerrar a impressão, enviar arquivos para impressão, restaurar após falha de energia).

É por isso que é necessário alterar o código G inicial e final. *foi.

Além disso, ao operar no modo de tela não nativa, a impressora não define o deslocamento Z registrado na tela, e ele deve ser passado como parâmetro para [START_PRINT](/pt/Main/#start_print) ou por meio de parâmetros globais. [Leia mais](/pt/FAQ/#how-z-offset-works)

Leia [recursos da versão de tela não nativa](#features-of-the-native-screen version).

E mude para o protocolo Octo/Klipper

---

### Estou usando a opção de tela. Envio um arquivo para impressão e a tela mostra uma temperatura de 0 0 0 e nenhuma impressão.

Adicione 2 linhas ao código inicial, bem no começo do código
```
M190 S[bed_temperature_initial_layer_single]
M104 S[camada_inicial_de_temperatura_do_bocal]
```

Sem essas linhas, a tela da impressora não sabe a que temperatura aquecer o bico e a mesa.
*```

---

#### Depois de instalar o ZMOD, minha tela está inoperante e não responde às teclas digitadas.

- Instale a atualização mais recente do firmware nativo e do ZMOD](/pt/Recomendations/#install-last-update-native-firmware-and-zmod)
- Leia [recursos operacionais](#conhecer-recursos)
- Você pode ter desligado a tela. Ligue-a com a macro [DISPLAY_ON](/pt/System/#display_on)

---

#### Você precisa alterar alguma coisa no código inicial?

Se estiver trabalhando com a tela nativa, não é necessário alterar nada.

Ao trabalhar no modo de tela não nativa/Guppy (e isso também é recomendado ao trabalhar com uma tela), substitua todo o código inicial:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

````START_PRINT EXTRUDER_TEMP= BED_TEMP=`````` deve ser escrito em uma linha

E o código final está em:
```
END_PRINT
```

Para que as camadas no Fluidd sejam contadas corretamente, escreva o código antes de alterar a camada:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

Se quiser ativar a calibração automática sempre que imprimir, digite Fluidd/Mainsail 1 vez no console
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```
No menu da tela da impressora, vá para `Settings` -> `Wifi icon` -> `Network mode` -> ative o controle deslizante `Local networks only`.

Leia a documentação de [START_PRINT](/pt/Main/#start_print) e [SAVE_ZMOD_DATA](/pt/Global/#save_zmod_data), isso permitirá que você utilize os recursos avançados e úteis do ZMOD

Se você quiser usar a reversão do firmware, leia [documentation](/pt/FAQ/#what-is-rollback-from-firmware) e adicione
```Perfil da barra``` -> ```Avançado``` -> ```Iniciar barra de código G```.
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

*raccoon

---

### Como funciona o Z-Offset

Leia o artigo "[Como o Z-Offset funciona em nossa impressora](/pt/SetupCalibrations/#how-z-offset-works-on-your-printer)".

O mod não interfere no z-offset de forma alguma ao trabalhar com a tela.

O deslocamento ao trabalhar com a tela nativa e ao trabalhar no modo de tela não nativa não é o mesmo e cada um tem sua própria vida e é configurado separadamente.

Use ```LOAD_ZOFFSET_NATIVE``` para copiar o z-offset da tela nativa para o modo de tela não nativa.

O z-offset salvo na tela é usado.

O deslocamento Z do Fluidd/Mainsail/GuppyScreen afeta **apenas até a reinicialização** e não deve ser alterado sem que se saiba para onde o bocal está se movendo.

Qualquer chamada para `SET_GCODE_OFFSET` (que é chamada automaticamente ao alterar o deslocamento Z do Fluid/Mainsail/GuppyScreen) salva o deslocamento Z atual nos parâmetros globais do mod. Mas esse valor salvo só será usado se o parâmetro global [LOAD_ZOFFSET](/pt/Global/#load_zoffset) for especificado (o que é desativado por padrão, para ativar `SAVE_ZMOD_DATA LOAD_ZOFFSET=1`), a tela nativa não for usada e a macro [START_PRINT](/pt/Main/#start_print) for usada.

Você também pode usar os parâmetros [START_PRINT](/pt/Main/#start_print) para definir o deslocamento Z

- Z_OFFSET - Define o deslocamento Z (0,0)

#### Quais são as opções para remover o mapa da tabela?

Se quiser ativar a calibração automática sempre que imprimir, digite fluidd/mainsail 1 vez no console:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```

A tela nativa usa mapas (sempre, não é fixo, mesmo que não seja necessário):

- ```MESH_DATA``` - padrão
- `DEFAULT` - se a opção `leveling` (criação do mapa da tabela antes da impressão) estiver marcada e, após a impressão, o mapa `DEFAULT` sempre for excluído.

Ao trabalhar em modo de tela não nativo, o mapa é usado:

- `auto` - ele é carregado automaticamente quando a impressora é ligada.

Se você quiser usar um cartão diferente ao imprimir (por exemplo, `moya_karta_na_80_gradusov`), então:

- Desative a calibração automática nos parâmetros globais

  ````SAVE_ZMOD_DATA PRINT_LEVELING=0````

- Capture o mapa da tabela antecipadamente por meio da macro [AUTO_FULL_BED_LEVEL](/pt/FAQ/#chores-macros-and-buttons-in-fluidd).
 
  ````AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=230 BED_TEMP=80 PROFILE=moya_karta_na_80_gradusov```''

Escolha uma das duas opções:

- Especificar o nome do mapa da tabela no parâmetro `MESH` para a macro [START_PRINT](/pt/Main/#start_print).
 
  ``` ```START_PRINT MESH=moya_karta_na_80_gradusov```''

- ou carregue o mapa da tabela em qualquer local conveniente (por exemplo, no perfil da barra) usando o comando
 
  ```BED_MESH_PROFILE LOAD=moya_karta_na_80_gradusov```

  Certifique-se de usar o mesmo cartão no perfil da barra e no `START_PRINT`, ou desative a limpeza de bicos no `START_PRINT` executando-o por meio do perfil da barra.

---

#### Por meio de parâmetros globais

Recomendo o uso de parâmetros globais, que são configurados uma vez e usados sempre que você imprime. Não há necessidade de alterar o código G inicial e final nesse caso.

Parâmetro `PRINT_LEVELING`:

- Remove o mapa da tabela toda vez que você imprime
- Se estiver trabalhando com a tela, o mapa da tabela será retirado da tela nativa, como seria se você tivesse selecionado um arquivo da tela e clicado na caixa de seleção `LEVELING`. Se o parâmetro for 1 `SAVE_ZMOD_DATA PRINT_LEVELING=1`, quando você enviar arquivos por meio do Orca/Fluidd/Mainsail, a impressora presumirá que você selecionou o arquivo a ser impresso na tela nativa e marcou `Alignment`. Toda vez que você imprimir nesse caso, o mapa da tabela será capturado.
- Se estiver trabalhando no modo de tela não nativa e usar a macro [START_PRINT](/pt/Main/#start_print) no código G inicial, o mapa da tabela também será apagado toda vez que você imprimir

  Para ativar esse recurso, você precisa configurar uma vez a macro [SAVE_ZMOD_DATA](/pt/Global/#save_zmod_data), o parâmetro [PRINT_LEVELING](/pt/Global/#zshaper)

  ```SAVE_ZMOD_DATA PRINT_LEVELING=1``` *(deve ser inserido no console do Fluidd/Mainsail)*. Nesse caso, o mapa será removido a cada impressão.

  *Para remover o mapa da área de trabalho da tela nativa, vá para ```Configurações``` -> ```Ícone Wifi``` -> `Modo de rede``` -> ative o controle deslizante ```Somente redes locais``` no menu da tela da impressora.

  *Se essa opção estiver ativa, todos os parâmetros do START_PRINT relacionados à criação/utilização de um mapa de mesa serão ignorados (FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH).

Parâmetro `USE_KAMP`:

- A remoção adaptativa do mapa da mesa (KAMP) pode ser ativada, então nem toda a mesa será removida, mas apenas as partes com modelos imprimíveis.
  **Automatic table map skimming will not be triggered!**. Esse parâmetro indica que, se o skimming do mapa da tabela for acionado, o KAMP será executado em seu lugar.

  Para ativar esse recurso, você precisa configurar a macro [SAVE_ZMOD_DATA](/pt/Global/#save_zmod_data) uma vez, parâmetro [USE_KAMP](/pt/Global/#zshaper)

  ```SAVE_ZMOD_DATA USE_KAMP=1``` *(deve ser inserido no console do Fluidd/Mainsail)*. Nesse caso, o mapa de tabela adaptável será usado sempre que possível, inclusive ao capturar o mapa de tabela com a tela nativa pela rede.

---

#### Por meio da alteração do código de início e da macro START_PRINT

Se você não quiser usar os parâmetros globais *(SAVE_ZMOD_DATA PRINT_LEVELING=0)*, os seguintes parâmetros da macro [START_PRINT](/pt/Main/#start_print), que é gravada no código G inicial, estarão disponíveis.

- FORCE_LEVELING - força a criação de um mapa de tabela, True - criar, False - não criar (False)
- FORCE_KAMP - iniciar a construção do mapa de tabela adaptável, True - sim, False - não (False).
- SKIP_LEVELING - não cria o mapa da tabela em nenhuma condição. Mais forte do que FORCE_KAMP e FORCE_LEVELING (False)
- MESH - nome do mapa de tabela a ser carregado; se não for especificado, nada será carregado; se não existir, será criado ("").

Exemplos:

Remoção de um mapa de tabela completo:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_LEVELING=True
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Remoção do mapa da tabela adaptativa
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_KAMP=True
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Algoritmo para remover o mapa da tabela na macro [START_PRINT](/pt/Main/#start_print):

1. Se MESH não estiver vazio, o mapa será carregado com o nome escrito no parâmetro MESH
2. Se SKIP_LEVELING = True - o mapa da tabela não será removido sob nenhuma condição
3. Caso contrário, se `FORCE_CAMP=True` for definido, o KAMP será removido.
4. Caso contrário, se o mapa da tabela não estiver carregado (o head nativo sempre carrega o mapa `MESH_DATA`) ou se `FORCE_LEVELING=True`, a construção do mapa da tabela é iniciada, mas não é salva

---

#### Por meio de macros e botões no Fluidd

Se você não quiser usar a macro `START_PRINT` e os parâmetros globais, as seguintes macros estão disponíveis:

- [AUTO_FULL_BED_LEVEL](/pt/Calibrations/#auto_full_bed_level) - remoção da carda da mesa com limpeza do bocal em uma determinada temperatura da mesa e da extrusora. *Desativa o aquecimento após a remoção da placa.

   A mesma macro pode ser chamada com o botão Fluidd/Mainsail, chamada `TABLE CALIBRATION`. Depois de remover o cartão da mesa em uma determinada temperatura, você pode pressionar o botão `Save Parameters` e o cartão da mesa será salvo no arquivo `printer.cfg`.

   Ele também pode ser escrito no código G inicial:
   ```
   AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
   M190 S[bed_temperature_initial_layer_single]
   M104 S[nozzle_temperature_initial_layer]
   ```

- KAMP](/pt/Calibrations/#kamp) - Calibração de mesa adaptável com limpeza de bocal
  ```` KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]````

- BED_MESH_CALIBRATE - remoção do mapa da tabela pela macro padrão do klipper. **Não é recomendável usar**, pois a limpeza do bocal não é realizada e, portanto, os resultados serão incorretos. **Mapa de tabela adaptativo do Orca, não recomendado de forma alguma**, porque ele não randomiza a remoção de pontos, o que significa que, ao imprimir modelos idênticos, o bico fará medições nos mesmos pontos todas as vezes, o que levará ao aparecimento de microfuros e, consequentemente, a um mapa de tabela incorreto.

---

#### Usando comandos padrão do KLIPPER

Para trabalhar com o MESH, existem macros Klipper padrão:

- [BED_MESH_CALIBRATE](https://www.klipper3d.org/G-Codes.html#bed_mesh_calibrate) - remove o mapa da tabela
- [BED_MESH_OUTPUT](https://www.klipper3d.org/G-Codes.html#bed_mesh_output) - mapa da tabela de saída
- [BED_MESH_PROFILE](https://www.klipper3d.org/G-Codes.html#bed_mesh_profile) - carregar, excluir, salvar o mapa da tabela

Se você carregar um mapa por meio de comandos KLIPPER no perfil da barra, certifique-se de usar o mesmo mapa em `START_PRINT` e no perfil da barra, ou desative a limpeza de bicos em START_PRINT e execute-a separadamente por meio do perfil da barra.

É altamente recomendável que você leia as opções de limpeza de bicos:

- [CLEAR_NOZZLE](/pt/Global/#clear_nozzle) - Limpeza do bico como no firmware nativo
- Parâmetro [PRECLEAR](/pt/Global/#preclear) - Limpeza adicional do bocal quando o cartão da mesa é removido.
- Parâmetro [CLEAR](/pt/Global/#clear) - quatro algoritmos (você pode adicionar o seu próprio) de limpeza de bocal por linha antes da impressão.

---

#### Por que os nomes dos animais aparecem periodicamente na documentação?

Ninguém gosta/não quer ler a documentação, embora 90% das questões sejam resolvidas e descritas nela.

Aqueles que não a leem também gostam de dizer que leram tudo.

É por isso que espalhei os nomes dos animais *opossum* no texto e os perguntarei quando fizerem outra pergunta da documentação. Se você não conseguiu nomear o animal que estava oculto no texto para sua pergunta, então você não leu a documentação.

Se você foi direcionado para cá. Leia a documentação e diga o nome do animal que está escrito em sua pergunta e, com certeza, você receberá ajuda:

- [Perguntas frequentes](/en/FAQ/)
- Dicas para melhorar a estabilidade da impressora](/en/Recomendations/)
- [Install/Upgrade/Uninstall Mod](/pt/Setup/)
- Lista de macros](/pt/Macros/)
- Configurações de armazenamento](#storage-settings)
- Recursos conhecidos](#recursosconhecidos)

---

### Quero excluir o ZMOD - tenho que recalibrar tudo?

Não - todas as configurações são mantidas

### O que é uma câmera alternativa?
 
A câmera nativa, que é ativada na tela, tem várias desvantagens.

- Alto consumo de RAM
- Qualidade de imagem ruim
- Apenas uma conexão com a câmera. Depois de abri-la no Ork, você não a verá mais no navegador
- Quedas periódicas de imagem

Câmera alternativa, permite alterar a resolução, os fps, permite várias conexões, não comprime a imagem, é fácil de reiniciar e personalizar [macro](/pt/Zmod/#camera_on). *zayats*

- Desative a câmera nativa na tela da impressora.
- Chame a macro [CAMERA_ON](/pt/Zmod/#camera_on)

Leia: [Instalei uma impressora e o ZMOD escondeu a minha câmera!](#I-installed-a-printer-and-zmod-hid-my-camera-in-orca-ff-I-see-it-and-now-it's-gone).

#### Configuração da câmera

**Configurações principais

| Parâmetro | O que faz | Valor normal
|----------|------------|------------------|
| WIDTH | Largura da imagem | 640 |
| Altura da imagem | 480 |
| `FPS` | Quantos quadros por segundo | 20 |
| `VIDEO` | número da câmera | video0 |
| `FS` | Corrigir câmeras problemáticas (1 para sim, 0 para não) | 0 |
| `STREAMER` | Programa da câmera | auto |
| `FORMAT` | Formato da imagem (somente ustreamer) | MJPEG | MJPEG | MJPEG

**O que é um streamer?

Um streamer é um programa que obtém uma imagem de uma câmera e a exibe em um navegador.

**Há duas opções disponíveis:**

- **mjpg_streamer** - programa simples, funciona somente com câmeras MJPG.
- **ustreamer** - mais avançado, mas requer mais memória, suporta diferentes câmeras.

O parâmetro `STREAMER=auto` selecionará o streamer apropriado.

**Formatos de imagem (somente para o ustreamer)

Você pode selecionar: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

O MJPEG é usado por padrão.

**Exemplos de comandos**

Inicialização simples da câmera video0 via mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Execução da câmera video0 via ustreamer com configurações:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Onde ver a imagem?

Abra em um navegador: `http://ip_адрес_принтера:8080`.

Lá você pode alterar o brilho, o contraste e outras configurações.

**Se houver problemas**

Não consegue ver a câmera?
Execute:
```
CAMERA_ON VIDEO=video99
```
O programa mostrará uma lista de câmeras disponíveis.

Os **Logs (registros de erros)** estão localizados na pasta: `log/cam/`.

---

### Instalei uma impressora e o ZMOD escondeu minha câmera! Eu podia vê-la no Orca-FF, mas agora ela sumiu!
 
Na interface da Web (fluidd), vá para `Settings` -> `Video Cameras`.

Já haverá uma câmera de vídeo lá, `Sample_Settings_Camera`. Vá até ela e veja as configurações.

**Crie uma nova câmera** com configurações semelhantes às da câmera "Example_Settings_Camera":

- Tipo de fluxo: `MJPEG stream`.
- URL do fluxo: `http://your_IP:8080/?action=stream`
- URL do instantâneo: `http://your_IP:8080/?action=snapshot`
- your_IP - substitua pelo endereço IP da impressora.

Em versões anteriores a `1.4.3`, você também pode especificar:

- Tipo de fluxo: `Fluxo MJPEG`.
- URL do fluxo: `/webcam/?action=stream`.
- URL do instantâneo: `/webcam/?action=snapshot`.

Se quiser ajustar a resolução, os fps, usar a câmera do bot do Telegram, reduzir o consumo de RAM, permitir conexões paralelas, será necessário usar [alternative camera](/pt/Zmod/#camera_on). *Câmera

No roteador, coloque um *endereço IP estático para a impressora*, caso contrário, ele mudará e a câmera falhará.

---

### Tenho 2 câmeras / como desativar/reverter a câmera

Se você não tiver uma câmera ou se as configurações automáticas da câmera não forem adequadas para você, será necessário abrir o arquivo `mod_data/user.moonraker.conf` por meio do Fluidd/Mainsail

E escrever em:

Para desativar a câmera:
```
[webcam video]
enabled: false
```

Para girar a câmera:
```
[webcam video]
rotação: 90
```

---

### Instalei a versão mais recente e o desenvolvedor diz que preciso fazer a atualização.

- Certifique-se de que você instalou a versão mais recente a partir da unidade flash
- Acesse a interface da Web. `Configurações` -> `Atualizações de software` -> Clique em `Verificar atualizações`.
- Atualize todos os componentes do *treeflyer*.
- Reinicialize a impressora

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

---

### Não é possível atualizar a MCU

Após a reinicialização, aparece um erro
```
!! Não é possível atualizar a configuração da MCU 'eboard' porque ela está desligada
```

Reiniciar o modo de operação anormal da impressora.

É por isso que você é solicitado a desligar e ligar novamente a impressora ao instalar o firmware nativo.

Ao reiniciar, a energia não é removida da MCU, o que significa que o programa gravado na MCU continua a ser executado. Esse programa tenta entrar em contato com o clipper, que não está disponível durante a reinicialização, e faz com que a MCU congele ou desligue.

Nesse caso, você deve escolher uma opção:

- Chamar `FIRMWARE_RESTART` e, nesse caso, a tela nativa ficará suspensa.
- Desligue a impressora e ligue-a

A diferença entre `REBOOT` e `FIRMWARE_RESTART` é que o `REBOOT` reinicia o Linux e, com ele, o Klipper na placa-mãe, enquanto o `FIRMWARE_RESTART` reinicia parcialmente o Klipper e reinicia completamente a MCU

---

### O que é MACROS? Como executá-lo, fazer download e usá-lo.

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada:

- De um arquivo GCODE
- No console do Fluidd/Mainstaill
*Ouriço

[Lista de macros](/pt/Macros/)

---

### Vou até a impressora via Orca/navegador e vejo Welcome to Moonraker

Então, quais portas o ZMOD usa:

- `7125` - é onde está o Moonraker.
- 8080 - é onde está a câmera.
- `80` - é onde o Fluidd/Mainsail funciona.

Para acessar a impressora, basta digitar o IP da impressora, **sem especificar o número da porta**. *rabbit

[Como configurar no Orca](/pt/Recomendations/#send-files-to-print-octoklipper)

#### Troquei a interface da Web e agora nada funciona.

Se você trocou a interface com a macro [WEB](/pt/System/#web) *whoosh*

A primeira coisa a fazer é pressionar `Ctrl + F5` ou `Ctrl + Shift + R` ou `Option + Command + E`.

Se tiver um problema no Orca, você precisa pressionar `Ctrl + F5` ou `Ctrl + Shift + R` ou `Option + Command + E` *fox*

Se estiver usando um navegador diferente, será necessário limpar o cache e os cookies e acessar o endereço IP da impressora sem caracteres adicionais na barra de endereços.

http://ИП_ПРИНТЕРА/.

Se isso não ajudar, use outro navegador: Firefox, Chrome, Yandex, Opera, etc.

---

### O ZMOD inclui o Entware - como usá-lo?

**AVISO! Não há Entware** no [AD5X](/pt/AD5X/)

Você precisa usar o SSH na impressora (`root`:`root` porta `22`)

Execute o comando
`
export PATH="$PATH:/opt/bin/:/opt/sbin/"
`

Em seguida, você pode executar o `mc` ou o `opkg`

- Atualizar o banco de dados de pacotes: `opkg update`
- Instalar um pacote: `opkg install mc`

Catálogos que são criados e usados pelo entware:

- /opt/bin
- /opt/etc
- /opt/home
- /opt/lib
- /opt/libexec
- /opt/root
- /opt/sbin
- /opt/share
- /opt/tmp
- /opt/usr
- /opt/var

---

### O que é reversão do firmware?

No ZMOD, em Fluidd/Mainsail, há controles deslizantes para controlar a velocidade e a quantidade de reversão do firmware.

Eles não afetam a impressão se o arquivo de código g for cortado sem usar os parâmetros de reversão do firmware.

A reversão do firmware permite que você altere o valor de reversão durante a impressão sem precisar recortar o arquivo inteiro.

Em vez de comandos de reversão complicados como `G1 E-.5 F2100`, o comando curto `G10` agora é usado para retração e, em vez de `G1 E.5 F2100`, `G11` é usado para retração reversa.

Para usar a reversão do firmware, no Orca.

`Printer Settings` -> `General Information` -> `Advanced` -> `Firmware rollback`, marque a caixa de seleção

Se você quiser alterar as configurações de reversão padrão no firmware:

Via Fluidd. `Configuration` -> `mod_data` -> `user.cfg`
```
[firmware_retraction].
retract_length: 0.9
retract_speed: 35
unretract_extra_length: 0
unretract_speed: 35
```

O `SET_RETRACTION` é normalmente definido como parte da configuração do fatiador para cada filamento, pois filamentos diferentes exigem configurações de parâmetros diferentes:
SET_RETRACTION [RETRACT_LENGTH=<mm>] [RETRACT_SPEED=<mm/s>] [UNRETRACT_EXTRA_LENGTH=<mm>] [UNRETRACT_SPEED=<mm/s>]: Define os parâmetros usados para retrações.

- RETRACT_LENGTH é o comprimento da rosca para retrações e retrações.
- RETRACT_SPEED - velocidade de retração.
- UNRETRACT_SPEED - a velocidade de retração é controlada por UNRETRACT_SPEED e não é particularmente crítica, embora muitas vezes seja menor do que RETRACT_SPEED.
- UNRETRACT_EXTRA_LENGTH - em alguns casos, é útil adicionar uma pequena quantidade de comprimento extra ao puxar para trás.

Exemplo de configuração de RETRACTION no Orca:

`Bar Profile` -> `Parameter Override` -> `RETRACT` -> `Length`.

`Bar profile` -> `Additional` -> `Start G-code of the bar`
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

```GET_RETRACTION```: consulta os parâmetros atuais usados na reversão e os exibe no terminal.

Variante de substituição de retração de [@minicx](https://github.com/loss-and-quick/)
```
SET_RETRACTION RETRACT_LENGTH={if not is_nil(filament_retraction_length[current_extruder])}[filament_retraction_length[current_extruder]]{else}[retraction_length]{endif} RETRACT_SPEED={if not is_nil(filament_retraction_speed[current_extruder])}[filament_retraction_speed[current_extruder]]{else}[retraction_speed]{endif}
```

---

### AD5X

[AD5X](/pt/AD5X/)

---

### Ajuda

### Como entrar em contato com o suporte ao desenvolvedor

[Instruções movidas](/pt/Help/)

---

### Como alterar o logotipo de inicialização

O logotipo está na pasta ```mod_data/logo```.

Requisitos do logotipo:

- Tamanho 800x480 profundidade de cor 24 bits
- AD5M: formato BMP. Nome do arquivo: ```bootlogo.bmp```.
- AD5X: Formato JPG. Nome do arquivo: ```logo.jpeg```.

Carregue seu logotipo na pasta ```mod_data/logo```.

Reinicie a impressora duas vezes.

Quando você excluir o mod, o logotipo nativo será restaurado. Se isso não tiver acontecido no AD5M:

- Você precisará instalar o mod
- Faça upload do arquivo [boot.bmp](https://github.com/ghzserg/FF/releases/download/R/boot.bmp) para a pasta `mod_data/logo`.
- Reiniciar a impressora

---

### Não há disparo na sonda após o movimento completo

O erro ocorre principalmente se a elevação do eixo z durante a sondagem for insuficiente.

Ele pode ser corrigido programaticamente da seguinte forma:

Digite em ```mod_data/user.cfg```.
```
[bed_mesh]
horizontal_move_z: 5
```

Hardware - todos os parafusos devem estar ajustados e a mesa não deve ter desalinhamento.

---

### Valor do peso

WeightValue é o valor nas células de carga em gramas. Ele é exibido em graus porque é implementado por meio da interface do sensor de temperatura. Portanto, Fluidd e Mainsail exibem graus.

Por que você precisa desse sensor?

- Ele pode ser usado para medir o zoffset por meio do plug-in [g28_tenz](https://github.com/ghzserg/g28_tenz).
- Você pode interromper a impressão se o bocal atingir uma peça ou se uma peça for arrancada. [NOZZLE_CONTROL](/pt/Global/#nozzle_control)
- Sem redefini-la, a medição do mapa da tabela não estará correta

---

### Erro de protocolo da MCU

Aqui estão alguns erros que dependem da MCU:

- Erro de protocolo da MCU
- Sensor de temperatura desconhecido flashforge_loadcell
- Comando necessário da MCU
- flashforge_loadcell: O comando MCU necessário "flashforge_loadcell_h1" não está disponível

A essência de todos esses erros é que a versão do Klipper não corresponde à versão da MCU.

Você pode visualizar a versão da MCU na guia `System`.

<img width="700" height="396" alt="{9CCFD772-CCDB-42ED-B952-DA15231DCF68}" src="https://github.com/user-attachments/assets/80e6a573-b372-4620-a7bc-7cbf020bc874" />

<img width="438" height="277" alt="{52EC8847-ACAB-461D-A9FA-633CDAF180CC}" src="https://github.com/user-attachments/assets/9bba3ff2-9a0e-4aa6-8327-f93fd1b46c3a" />

Por exemplo, você tem o Klipper 13 em execução e está usando a MCU do Klipper 11 ou 12.

Ou vice-versa. Você está executando um Klipper nativo, mas carregou o MCU para o Klipper 13.

Se a versão do seu MCU começar com ```?-20230317_182329-ubuntu20-virtual-machine``` - isso significa que você carregou o MCU para o Klipper 12 (AD5X) ou Klipper 11 (Ad5M/Ad5mPro).

Portanto, você precisa do zMod para carregar o Klipper nativo.

- Vá para ```mod_data/variables.cfg``` e exclua a linha ```klipper13 = 1```.
- Salve o arquivo
- Desligue a impressora e ligue-a (não reinicie!).

<img width="422" height="570" alt="image" src="https://github.com/user-attachments/assets/6a96aa9d-7d07-4bf7-8039-042d28f4a87f" />

Se esse não for o caso e o Klipper estiver em execução, execute ```UPDATE_MCU FORCE=13``` - esse comando instalará a versão atual da MCU

Se nada ajudar e o **Klipper não funcionar**:

- Mude para o Klipper nativo conforme descrito acima.
- [Install native Factory firmware](/pt/Native_FW/#how-to-install-native-firmware), que instalará a MCU nativa.

---

#### O filamento acabou ou parou

Para o AD5M, você precisa calibrar as etapas do sensor por seleção. Escreva em `mod_data/user.cfg`.

Aumente esse número. Algumas pessoas estão satisfeitas com o padrão `8`, e alguns sensores funcionam corretamente apenas com `17`.
```
[filament_motion_sensor e0_sensor].
detection_length: 8
```

O filamento (IFS) parou.

No AD5X, é necessário calibrar as etapas do sensor IFS por seleção. Escreva em `mod_data/user.cfg`.

Aumente esse número. Algumas pessoas estão satisfeitas com o padrão `10`, e alguns IFS funcionam corretamente apenas com `17`.
```
[zmod_ifs_motion_sensor ifs_motion_sensor].
detection_length: 8
```

A interrupção do filamento no IFS também pode estar relacionada:

- Há uma haste 1 na extrusora e uma haste 2 está sendo puxada para fora. Use [SET_EXTRUDER_SLOT](/pt/AD5X/#5-how-to-manually-indicate-to-the-printer-which-coil-is-now-filled-ad5x).
- A extrusora tem uma haste inserida nela, mas já tem a haste antiga
- Os módulos 4 em 1 e os tubos para eles têm comprimentos diferentes, portanto, você precisa ajustar o parâmetro ```filament_unload_into_tube``` em ```mod_data/filament.json``` definindo-o como 70 ou mais. [Leia mais](/pt/AD5X/#most-important-settings-what-to-change-more-often-ad5x)

Além disso, o problema pode ser causado por uma incapacidade de desbloquear a barra no canal IFS.

Os motivos são puramente mecânicos:

- entrada de aparas de plástico no eixo de fixação
- deslizamento da mola da alavanca do canal.

É necessário remover os cavacos, desmontar e reinstalar as peças.

Em seguida, teste a impressão e o bloqueio/desbloqueio da barra por meio de [comandos IFS](/pt/AD5X/#10-ifs-commands).

---

### Mede a tabela centralizada antes de cada trabalho de impressão

Antes de imprimir, a impressora:

- aquece a mesa e o bico.
- limpa o bico.
- resfria o bico
- ** mede o centro da mesa** (Iniciando a sonda Z manual. Use o TESTZ para ajustar a posição)
- aquece o bico
- inicia a impressão

Esse é um recurso do **firmware nativo** a partir da versão do **firmware nativo**:

- 1.1.8 AD5X
- 3.2.4 AD5M/AD5MPro

Solução:

- Reverter o firmware nativo](/pt/Native_FW/) para a versão **1.1.7.7** para o AD5X, **3.2.3.3** para o FF5M/FF5MPro
- Desativar a tela nativa](/pt/System/#display_off)

---

### E0120

Esse é um erro do Klipper.

Na maioria das vezes, ele é corrigido pelas seguintes ações simples:

- Desligar a alimentação da impressora
- Aguardar 10 segundos
- Ligar a impressora

Para ver exatamente qual é o erro:

- abra o Fluidd/Mainsail
- vá para o console e leia o texto do erro
- abra o bot do Telegram [@zmod_help_bot](http://t.me/zmod_help_bot) e digite o texto do erro ou encontre você mesmo a descrição na documentação.

Se não conseguir corrigi-lo, [você precisa criar um tíquete](/pt/Help/).

[Configurações nativas](https://github.com/ghzserg/zmod/tree/main/Native_firmware/config/)

