### AD5X

1. [Recursos importantes](#1-important-features-ad5x)
2. [Como preparar um arquivo no Orca](#2-comopreparar-um-arquivo-no-orca-ad5x)
3. [Menu de seleção de cores (`COLOR`)](#3-how-to-use the-colour-selection-menu-macros-color-ad5x)
4. [Menu de impressão (`PRINT`)](#4-print-menu-macro-print-ad5x)
    - [Parâmetros globais do AD5X](#parâmetros-globais-ad5x)
5. [Como especificar manualmente o spool](#5-how-to-manually-indicate-to-the-printer-which-coil-is-now-filled-ad5x)
6. [Setting the amount of waste at filament change](#6-how-to-set-the-amount-of-waste-at-filament-change-ad5x)

    - 🔧 [Basic Settings](#most-important-settings-what-to-change-most-often-ad5x)
       - ⚙️ [Configurações avançadas](#settings-for-advanced-don't-change-if-you're-não-certo-do-resultado-ad5x)

7. [Add your filament types](#7-add-your-filament-types-ad5x)
8. [Add your colours](#8-add-your-colours-ad5x)
9. [Fixar o estacionamento no cesto e cortar o filamento](#9-fix-working-with-basket-and-knife-to-cut-filament-ad5x)

    - [Por meio do menu de engenharia no firmware nativo](#customize-the-basket-on-native-firmware-ad5x)
       - [Via Flash no firmware nativo](/pt/Setup/#attention-ad5x)

10. [Comandos IFS](#10-ifs-commands)
11. [Restaurar firmware do IFS](#11-restore-firmware-ifs)

[Plugins](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_ru.md):

- [bambufy](https://github.com/function3d/bambufy) - Compatível com o Bambu Studio, melhora o controle da torre de alimentação, fornece uma estimativa precisa do tempo e do consumo de material, reduz o desperdício, oferece suporte ao Mainsail,
troca rápida de cores e recursos avançados de impressão.

- [nopoop](https://github.com/ghzserg/nopoop) - Maximiza a redução de resíduos da ninjamida
- lessWaste](https://github.com/Hrybmo/lessWaste/) - Uma bifurcação do bambufy

---

## **1. Recursos importantes do AD5X**

Diferenças em relação ao AD5M:

* Não há `Entware`.
* Em vez da macro `CLOSE_DILALOGS` (fechamento lento), **sempre use** `FAST_CLOSE_DILAOGS` (fechamento rápido).
* A macro `NEW_SAVE_CONFIG` **não funciona**.
* Para ligar a câmera, é necessário usar ```CAMERA_ON VIDEO=video3``` ou ```CAMERA_ON VIDEO=video0``` ou ```CAMERA_ON VIDEO=video99```.
* O Klipper pode falhar. Solução: `Process Profile` -> `Other` -> `Output G-cod` -> `Model Exclusion` desative o tique.

---

## **2. Como preparar um arquivo no Orca AD5X**

[Enviar arquivos para impressão via "Octo/Klipper"](/pt/Recomendations/#send-files-to-print-octoklipper).

**Você precisa remover as bobinas não utilizadas da lista no Orca.

**Exemplo
Há 4 bobinas na impressora (#1, #2, #3, #4). Somente as cores das bobinas nº 1 e nº 3 são necessárias para a impressão.

* No arquivo, elas serão chamadas de **T0** (primeira cor) e **T1** (segunda cor).
* No menu, você precisará selecionar para **T0** -> carretel nº 1 e para **T1** -> carretel nº 3.

---

## **3. Como usar o menu de seleção de cores (macro `COLOR`) AD5X**

<img width="874" height="286" alt="image" src="https://github.com/user-attachments/assets/c0538a17-88a9-4aee-a65c-cff4cc1773d0" />

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/b6eb3ddd-ad7d-4cc2-b1b5-9f1aef918b29" />

<img width="563" height="550" alt="image" src="https://github.com/user-attachments/assets/cc0c951f-48c1-469d-8940-90832ad1d3f5" />

<img width="800" height="480" alt="color" src="https://github.com/user-attachments/assets/4145baef-a695-49e6-a914-c12dd3f6b8a4" />

* `Extruder: 1 (PETG/Orange)` - Isso significa que a impressora está agora preenchida com plástico PETG laranja do carretel número 1.
* `IFS: True` - O sistema de alimentação automática de filamento está funcionando.

**Agora selecione o carretel com o qual deseja trabalhar (por exemplo, carretel 2):**

<img width="568" height="455" alt="image" src="https://github.com/user-attachments/assets/f7ea3ed0-28a5-48d5-99db-eade0a199e99" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/c42cbefa-a29c-4df0-a62a-d99842c13961" />

Há quatro ações que você pode realizar:

1.  **Alterar a cor** da bobina.
2.  **Alterar o tipo** de plástico (por exemplo, de PLA para PETG).
3.  **Coloque** esse filamento na impressora.
4.  **Descarregue** o filamento da impressora.

**Como mudar a cor:**

1.  Pressione "Change Colour" (Alterar cor).
2.  **Selecione uma cor na lista.** Dessa forma, a impressora e a tela nativa o entenderão melhor.
<img width="561" height="823" alt="image" src="https://github.com/user-attachments/assets/8dbff228-dfc0-4705-92f9-d94df80b7a4e" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/f51f91a2-4131-4ba3-a8a0-3b9519f61f6d" />

3.  Depois de selecionada, volte e a cor da bobina na lista **deve mudar**.
<img width="556" height="545" alt="image" src="https://github.com/user-attachments/assets/f32a9239-44c6-449d-bbf7-5f453f149ef7" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/4fa7bb58-ee03-4613-ba06-a5af9b2ddfa6" />

**Se a cor não mudar:** feche a janela com uma cruz e execute a macro `COLOR` novamente. Às vezes, a tela não é atualizada a tempo.

**Como alterar o tipo:**

1.  Clique em "Change Type" (Alterar tipo).
2.  **Selecione um tipo na lista.

<img width="562" height="710" alt="image" src="https://github.com/user-attachments/assets/baf7b807-c4f5-4ab4-8bfd-2fc43bb448cd" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/2d7b4f12-a8f1-4c99-a555-7c422bd5ffe4" />

**Se o tipo não mudar:** feche a janela com uma cruz e execute a macro `COLOR` novamente. Às vezes, a tela não é atualizada a tempo.

**Dica:** Se você especificar a **mesma cor e o mesmo tipo** para vários carretéis, a impressora passará automaticamente para o próximo carretel quando o primeiro acabar. Isso é chamado de **"modo de carretel infinito "**.

---

## **4. Menu de impressão (macro `PRINT`) AD5X**

Essa janela se abre **auto** quando você começa a imprimir.
<img width="567" height="564" alt="image" src="https://github.com/user-attachments/assets/a046c089-22d3-474e-89b6-89815412d068" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/f1ad0f49-e2bd-43c8-9301-7c58b9c05c22" />

**Como entender o que isso diz:**

* "Cube.gcode" é o nome do arquivo que está sendo impresso.
* `T0` é a primeira cor do arquivo. Ela é impressa com o filamento da **bobina nº 4** (PLA laranja).
* `T1` é a segunda cor. É impressa com o filamento da **bobina nº 3** (PLA preto).
* A `T2` é a terceira cor, impressa com o filamento da **bobina #2** (PLA verde).
* `T3` é a quarta cor, também impressa a partir da **bobina #2** (PLA verde).

**Se você precisar trocar a bobina de cor durante a impressão:**

**Basta **pressionar o T** desejado (por exemplo, T1) e selecionar outro carretel na lista.
<img width="553" height="550" alt="image" src="https://github.com/user-attachments/assets/4d831fdb-6ff5-4a0d-ac9e-10154d1c7956" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/a87d6115-87e4-4cb1-af3e-b194edefb42b" />

### Parâmetros globais do AD5X

Use o parâmetro global [SILENT](/en/Global/#silent) para evitar que a janela de seleção de cores seja exibida quando a impressão for iniciada.

- 0 - mostrar a janela (padrão)
- 1 - não mostra a janela, usa as cores definidas anteriormente
- 2 - não mostrar a janela, não usar cores IFS

```gcode
SAVE_ZMOD_DATA SILENT=1
```

Use o parâmetro global [AUTOINSERT](/pt/Global/#autoinsert) para desativar a função de inserção automática da haste na extrusora

```gcode
SAVE_ZMOD_DATA AUTOINSERT=0
```

Para desativar o descarte de filamentos na lixeira durante a impressão, use o parâmetro [USE_TRASH_ON_PRINT](/pt/Global/#use_trash_on_print).

- 0 - Não ocorrerá purga no descarte. O cabeçote de impressão ainda se deslocará até a rampa de descarte durante as trocas de cor na primeira camada para reduzir falhas (blobs). Se isso estiver acontecendo em todas as camadas, verifique seu gcode de início e de troca de camada!
- 1 - A purga ocorrerá na rampa de descarte durante as trocas de cor. Duas purgas com comprimento igual a `filament_drop_length` no arquivo filament.json (mais `filament_drop_length_add` se os materiais forem diferentes) ocorrerão em cada troca de cor.
- 2 - Após inserir a nova cor, o cabeçote de impressão se deslocará até a rampa de descarte e, a partir daí, devolverá o controle ao fatiador. Isso só deve ser usado em conjunto com um perfil de fatiador projetado para este modo.

```gcode
SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0
```

Para remover o filamento quando a impressão estiver concluída, use o parâmetro [REMOVE_FILAMENT](/pt/Global/#remove_filament).

```gcode
SAVE_ZMOD_DATA REMOVE_FILAMENT=1
```

Para ajustar o número de ferramentas exibidas na janela de seleção de cores (se as informações não puderem ser obtidas pela varredura do arquivo), use o parâmetro [ALLOWED_TOOL_COUNT](/Global/#allowed_tool_count).

[Consulte configuração de pré-processamento](https://wiki.zmod.link/pt/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=16
```

Para permitir a varredura de arquivos gcode para obter informações sobre ferramentas, cores e materiais, use o parâmetro [SCAN_FILE_COLORS](/Global/#scan_file_colors). Você também pode definir o valor como 2 para verificar apenas os dados preparados pelo script do fatiador, sem verificar os arquivos inteiros.

[Consulte configuração de pré-processamento](https://wiki.zmod.link/pt/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

Para ativar o mapeamento automático de cores do arquivo gcode para as bobinas físicas, use o parâmetro [AUTO_ASSIGN_COLORS](/Global/#auto_assign_colors). A digitalização de arquivos deve estar ativada para que esse recurso funcione. O uso de um valor de 30 interromperá a impressão no modo silencioso se houver algum problema com a atribuição automática.

Você pode configurar seus próprios valores para interromper a impressão no modo silencioso somando os números a seguir:

* 2 (Pelo menos um material não corresponde; por exemplo, o arquivo gcode especifica ABS e você só tem PLA carregado; ou os dados do material não puderam ser carregados)
* 4 (Pelo menos uma cor não corresponde, geralmente porque os arquivos de digitalização estão desativados ou falharam)
* 8 (Pelo menos uma cor não corresponde bem)
* 16 (A mesma bobina física foi atribuída a mais de um índice de ferramenta no arquivo)

[Consulte a configuração de pré-processamento](https://wiki.zmod.link/pt/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

Se o comando de alteração de cor descobrir que a nova cor corresponde a uma cor já carregada, o processo de alteração geralmente é ignorado por ser inútil. Se, por algum motivo, você quiser que o processo de alteração de cor seja sempre executado por completo, use o parâmetro [ALWAYS_FULL_COLOR_CHANGE](/Global/#always_full_color_change).

```gcode
SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0
```

## Como informar manualmente à impressora qual spool está atualmente preenchido com AD5X**

Às vezes, você mesmo alterou o spool e a impressora não percebe isso e mostra as informações antigas.

Há um comando especial para corrigir isso.

**Basta digitar esta frase no console:**

```
SET_EXTRUDER_SLOT SLOT=1
```

**O que isso significa:**

* O `SET_EXTRUDER_SLOT` é um comando que diz: "Impressora, memorize o carretel!".
* `SLOT=1` é o número do carretel que você acabou de reabastecer. **O número pode ser alterado!

**Exemplos

* Se você tiver enchido o filamento do carretel número 3, digite: `SET_EXTRUDER_SLOT SLOT=3`.
* Se for do carretel número 2, digite: `SET_EXTRUDER_SLOT SLOT=2`.

Após esse comando, a impressora saberá qual spool está sendo executado no momento e não misturará as cores.

## **6. Como definir a quantidade de resíduos ao trocar o filamento AD5X**

Essas configurações são necessárias para desperdiçar menos plástico ao trocar os carretéis. Para alterá-las, você deve primeiro **desabilitar a tela nativa da impressora** usando a macro `DISPLAY_OFF`.

No modo sem tela, os sensores estão disponíveis e ativados:

- `Head Switch Sensor` - presença de filamento na extrusora
- `Ifs Motion Sensor` - movimento do filamento no IFS

**Como encontrar essas configurações:**

1.  Clique na guia **"Configuration "** (Configuração).
2.  Localize e abra a pasta **`mod_data`**.
3.  Nessa pasta, localize e abra o arquivo **`filament.json`**.

![Onde encontrar o arquivo](https://github.com/user-attachments/assets/109b0f0a-c87d-4f5c-9333-ebfbb8065b87)

Nesse arquivo, há uma lista de números para cada tipo de plástico (PLA, ABS, PETG, etc.). Veja a seguir o que eles significam:

---

#### **Configurações mais importantes (o que deve ser alterado com mais frequência) AD5X:**

Para que essas configurações funcionem, é necessário **desativar a tela nativa da impressora** usando a macro `DISPLAY_OFF`.

1.  ** `temp`** - A temperatura à qual o bocal de troca de filamento se aquece. **O valor padrão depende do tipo de material.
2.  ** `filament_drop_length` - A temperatura à qual o bocal é aquecido para a troca de filamentos.

    * **Simples:** Quantos milímetros de plástico a impressora espremerá na lixeira para **limpar o bocal** da cor antiga. Isso se aplica ao carregar cores fora da impressão ou antes de uma impressão, ou ao trocar de cor com USE_TRASH_ON_PRINT definido como 1.
    * **Dica:** Se as cores forem misturadas quando você trocar os carretéis, aumente esse número. Se você quiser menos desperdício, diminua-o.

3.  **`filament_drop_length_add`** (Reinicialização opcional)

    * Simplificando: quanto plástico a mais a impressora jogará na lixeira se você mudar não apenas a cor, mas o **tipo de material** (por exemplo, de PLA para PETG). Isso se aplica ao carregar cores fora da impressão ou antes de uma impressão, ou ao trocar de cor com USE_TRASH_ON_PRINT definido como 1.
    * Por que é necessário: Materiais diferentes não se misturam bem, portanto, você precisa limpar melhor o bocal.

4.  **`nozzle_cleaning_length`** - O comprimento (em mm) que o filamento é puxado para fora da extrusora ao limpar o bocal quando o carretel não está mais em uso. **Padrão: 60 mm.**

5.  **`filament_unload_into_tube`** — Quanto filamento descarregar do módulo 4 em 1 quando o extrusor não estiver mais em uso. **Padrão: 70 mm.**

    *   Se você tiver um módulo 4 em 1 de nova versão, aumente `filament_unload_into_tube` ou, em último caso, aumente `nozzle_cleaning_length`

---

##### **Configurações avançadas (não altere a menos que tenha certeza do resultado) AD5X:**

Para que essas configurações funcionem, é necessário **desativar a tela nativa da impressora** usando a macro `DISPLAY_OFF`.

* **`filament_tube_length`** - O comprimento total do tubo de Teflon do módulo IFS até a extrusora. Útil para tubos não padronizados. **Padrão: 1000 mm.
* **`filament_unload_before_cutting`** - Quantos milímetros levantar o filamento **antes** de cortá-lo. **Padrão: 0 mm. **Padrão: 0 mm.
* ** `filament_unload_after_cutting`** - Quantos milímetros levantar o filamento **após** o corte, antes de começar a passar para a cesta. **Padrão: 5 mm.
* **`filament_unload_after_drop`** - Retrai (puxa) o filamento de volta para cima depois de deixá-lo cair no cesto antes da impressão. Necessário para evitar o gotejamento do bico. **Padrão: 3 mm.
* **`filament_extruder_speed`** — Velocidade (em mm/min) na qual o filamento é carregado no extrusor. **Padrão: 300 mm/min (5 mm/s).**
* **`filament_ifs_speed`** — Velocidade (em mm/min) na qual o módulo IFS opera. **Padrão: 12000 mm/min (20 mm/s).**
* **`filament_fan_speed`** - A velocidade do ventilador (0 a 255) ao despejar no cesto. Ele sopra ao redor do bocal para resfriar o fluxo inferior. **Padrão: 102.
* **`filament_autoinsert_empty_length`** - Quantos milímetros de filamento são puxados durante a inserção automática se a extrusora estiver vazia. **```Padrão: 600 mm.```**
* **`filament_autoinsert_full_length`** - Quantos milímetros de filamento são puxados durante o preenchimento automático se já houver outro filamento na extrusora. **Padrão: 550 mm.**
* ** `filament_autoinsert_ret_length`** - Quantos milímetros de filamento são retraídos se o sensor na extrusora for acionado (somente quando a extrusora estiver vazia). **Padrão: 90 mm.**
* ** `filament_autoinsert_speed`** - A velocidade (em mm/m) na qual o filamento é alimentado automaticamente na extrusora. ** **Padrão: 1200 mm/m (20 mm/s).**

**Alterar as configurações na seção avançada pode resultar em operação incorreta da impressora, atolamentos de filamentos ou falhas. Altere-as somente se você entender completamente o que cada parâmetro é responsável e quais podem ser as consequências.

**Conclusão principal:** Se você quiser menos desperdício, comece reduzindo os números **`filament_drop_length`** e **`filament_drop_length_add`** do seu plástico. Não se esqueça de salvar o arquivo após as alterações!

---

#### **Purga controlada pelo fatiador (Slicer-controlled purge)**

É possível fazer com que o fatiador controle a purga, utilizando outras configurações de USE_TRASH_ON_PRINT em vez do valor padrão (1).

##### Modo Nopoop (`SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`)

Neste modo, nenhuma purga é realizada pela impressora durante as trocas de cor. A impressora cortará o filamento, retornará à torre de limpeza (prime tower) para descarregar e carregar o filamento e, em seguida, continuará imediatamente a partir dali.

Na primeira camada, a impressora irá para o duto de descarte ao trocar o filamento, mas retornará à torre de limpeza logo em seguida sem produzir nenhum resíduo (poop).

Para purgar adequadamente o filamento antigo neste modo, a abordagem recomendada é ativar "Purgar na torre de limpeza" (Purge into prime tower) nas configurações do OrcaSlicer. Isso é encontrado nas configurações da impressora, na aba "Multimaterial". Você pode então usar a configuração "Flush Volumes" para ajustar as quantidades de purga. Se desejar adicionar uma quantidade fixa aos volumes de descarga calculados automaticamente, poderá fazê-lo configurando o "Volume do Bico" (Nozzle Volume) na aba Geral das configurações da impressora.

É normal que sua torre de limpeza seja consideravelmente maior do que o normal ao usar esta opção, especialmente ao trabalhar com alturas de camada finas.

Além disso, você pode usar opções como "Purgar no preenchimento" (Purge to infill), "Purgar neste objeto" (Purge to this object), etc., ao usar este modo, para reduzir a quantidade de resíduos purgados na torre de limpeza.

Esta opção é suportada apenas no OrcaSlicer; ela não pode ser usada com o Bambu Studio devido à falta da função "Purgar na torre de limpeza".

##### Modo Poop Controlado pelo Fatiador (`SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=2`)

Neste modo, nenhuma purga é realizada pela impressora por conta própria durante as trocas de cor. A impressora cortará o filamento, irá para o duto de descarte e devolverá o controle ao fatiador.

Este modo requer suporte adequado do perfil da impressora no fatiador; em particular, é necessário um gcode de troca de filamento que gerencie o descarte (pooping) e o retorno à torre de limpeza posterior. NÃO use este modo com nenhum arquivo gcode que não tenha sido fatiado especificamente para ele.

Ao usar o OrcaSlicer, opções como "Purgar no preenchimento" não podem ser usadas neste modo. Este é um bug no OrcaSlicer e não pode ser corrigido pelo zMod. Elas funcionam corretamente ao usar o Bambu Studio.

##### Perfis de impressora

Perfis de impressora configurados para purga controlada pelo fatiador estão disponíveis para [OrcaSlicer](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/orcaslicer) e [Bambu Studio](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/bambustudio). Estes perfis são próximos aos perfis padrão da AD5X, exceto por:
- Todo o gcode personalizado do zMod adicionado, incluindo o gcode de troca de filamento apropriado para USE_TRASH_ON_PRINT=2
- "Purgar na torre de limpeza" ativado (apenas OrcaSlicer)
- Define automaticamente a configuração correta de USE_TRASH_ON_PRINT no início da impressão
- Tipo de Z-Hop definido como Normal
- Volume do bico definido como 144
- Tempo de descarregamento do filamento definido como 66s para estimativas mais precisas (com base nas configurações padrão do filament.json)
- Tempo de inicialização da ventoinha definido como 1.5s e kickstart como 0.5s (apenas OrcaSlicer)

Ao usar o OrcaSlicer, você pode alternar entre os dois modos alterando a configuração "Purgar na torre de limpeza". Quando ativado, o modo nopoop será usado. Quando desativado, o modo poop será usado. O perfil definirá automaticamente o valor correto de USE_TRASH_ON_PRINT para você no início de uma impressão.

Ao usar o Bambu Studio, apenas o modo poop é suportado.

**Se você realizar uma impressão a partir destes perfis no Modo Poop Controlado pelo Fatiador, certifique-se de alterar sua configuração USE_TRASH_ON_PRINT de volta para 0 ou 1 antes de imprimir qualquer gcode multicolorido que não tenha sido fatiado com estes perfis.**

## **7. Adicione seus tipos de filamentos AD5X**

Para que essas configurações funcionem, é necessário **desabilitar a tela nativa da impressora** usando a macro `DISPLAY_OFF`.

Para adicionar um novo tipo de filamento ```mod_data/user.cfg``` adicione:
```
[zmod_ifs].
filament_NEWTYPE: 300
```
Em que NEWTYPE é substituído pelo tipo de filamento que você deseja (por exemplo, HIPS) e o número é o ponto de fusão desse filamento.

```IFS_PRINT_DEFAULTS``` - exibirá os tipos de filamentos disponíveis e suas temperaturas de fusão

---

## **8. Adicione suas cores AD5X**

Para que essas configurações funcionem, você deve **desabilitar a tela nativa da impressora** usando a macro `DISPLAY_OFF`.

Para adicionar ou renomear uma cor, abra ```mod_data/colors/ru.cfg``` (use seu idioma em vez de ru):

```e adicione uma nova cor ou renomeie uma cor existente.

Para exibir o nome de uma cor, o nome da cor deve começar com um sublinhado ```_```.

Exemplo:
```
{
  "ffffff": "branco",
  "fffff1": "_transparente",
  "fef043": "amarelo brilhante",
  "dcf478": "light green" (verde claro),
  "0acc38": { "green" (verde),
  "067749": "verde escuro",
  "0c6283": "verde-azulado",
  "0de2a0": "turquesa",
  "75d9f3": "azul",
  "45a8f9": "azul",
  "2750e0": "azul escuro",
  "46328e": "purple" (roxo),
  "a03cf7": "roxo brilhante",
  "f330f9": "magenta",
  "d4b0dc": "lilás",
  "f95d73": "pink" (rosa),
  "f72224": "red" (vermelho),
  "7c4b00": "marrom",
  "f98d33": "laranja",
  "fdebd5": "beige" (bege),
  "d3c4a3": "marrom claro",
  "af7836": "terracotta",
  "898989": "grey" (cinza),
  "bcbcbc": "light grey" (cinza claro),
  "161616": "black" (preto)
}
```

A inscrição ```_transparent``` será exibida nos botões

---

## 9. Corrige a operação com a cesta e o cortador de filamentos AD5X

[Manual de Instruções Alternativo](/pt/Setup/#attention-ad5x)

As coordenadas da cesta e da faca podem ser diferentes para impressoras AD5X diferentes. Às vezes, a diferença pode ser de até 4 mm.

Por esse motivo:

- O filamento pode não entrar na cesta;
- A faca não corta o filamento;
- A cabeça da impressora pode bater na parede.

Para corrigir isso, você precisa:

1. atualizar o zMod.
2. abrir o arquivo `/rw/Adventurer5M.json`.
3. encontrar linhas como
```json
{
	"CutXOffset" : 0.5,
	"CutYOffset" : -0.20000001788139343,
	"xOffset" : 0.0,
	"yOffset" : -0.20000001788139343,
	"zOffset" : 0,0,
	"zProbeOffset" : 0,004999995231628418
},
```
<img width="504" height="241" alt="image" src="https://github.com/user-attachments/assets/8647b1fe-594c-4bb3-91ee-560cfe4a58fd" />

Substitua **apenas** esses valores:
```json
"CutXOffset": 0,0,
"CutYOffset": 0,0,
"yOffset": 0,0,
```

4. Digite o comando: `UPDATE_FF_OFFSET` (isso atualizará as configurações).
5. Em seguida, digite: `_GOTO_TRASH` (isso fará com que a impressora volte para a lixeira).

---

### Configurando a lixeira do AD5X

[Instruções alternativas](/pt/Setup/#attention-ad5x)

1. Digite o comando `_GOTO_TRASH` - o cabeçote da impressora será direcionado para a lixeira.
2. Se o compartimento não fechar, mova cuidadosamente o cabeçote até que o compartimento feche. Você deve usar o GCODE: ```G1 Y230.2```.
3. Veja qual é a coordenada **Y** que você tem agora.
4. subtraia 229 desse número. O resultado será seu `yOffset`.

Exemplos:

- Se Y = 230,2, então `yOffset = 230,2 - 229 = 1,2`.
- Se Y = 228,4, então `yOffset = 228,4 - 229 = -0,6`.
- Fórmula: `yOffset = Y - 229`.

Escreva esse número no arquivo `/rw/Adventurer5M.json`. A cesta está configurada.

5. Digite o comando: `UPDATE_FF_OFFSET` (isso atualizará as configurações).
6. Em seguida, digite: `_GOTO_TRASH` (isso fará com que a impressora volte para a lixeira).

---

### Configurando a faca AD5X

[Versão alternativa das instruções](/pt/Setup/#attention-ad5x)

1. Digite o comando `_CUT_PRUTOK` - o cabeçote irá para a faca.
2. Use a tela para mover o cabeçote até que a faca seja acionada. Você precisa usar o GCODE: ```G1 Y-7.7``` ```G1 X-1.7```.
3. Veja quais são suas coordenadas X e Y.
4. Para **Y**:

    - Subtraia de **7,5** sua coordenada Y, módulo de sua coordenada Y.
       - Exemplo: se Y = -7,7, então `CutYOffset = 7,5 - 7,7 = -0,2`.
       - Exemplo: se Y = -5,9, então `CutYOffset = 7,5 - 5,9 = 1,6`.
       - Fórmula: `CutYOffset = 7,5 + Y`.

5. Para **X**:

    - Subtraia sua coordenada X do módulo de sua coordenada X de **2,5**.
       - Exemplo: se X = -1,7, então `CutXOffset = 2,5 - 1,7 = 0,8`.
       - Exemplo: se X = -2,8, então `CutXOffset = 2,5 - 2,8 = -0,3`.
       - Fórmula: `CutXOffset = 2,5 + X`.

Escreva esses números no arquivo `/rw/Adventurer5M.json`. A faca está configurada.

6. Digite o comando: `UPDATE_FF_OFFSET` (isso atualizará as configurações).
7. Em seguida, digite: `_GOTO_TRASH` (isso fará com que a impressora volte para a lixeira).

Reinicialize a impressora e pronto.

---

## Configuração da cesta no firmware nativo do AD5X

1. Vá para a guia "i" e pressione o botão `Status`.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/08a99d33-c970-4e86-933d-0064b447f5b7" />

2. Vá para a guia 6
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0eb4b8f-552b-4e58-86d7-2b47b8b0035c" />

3. Pressione `Move the extruder to waste tray position` e mantenha pressionado por 20 segundos
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/81213d65-bf06-4d33-8e4a-eb3aae2782d7" />

4- Ajuste a posição do cabeçote na bandeja de resíduos de modo que ela se feche. Use as setas de controle para estacionar o cabeçote de impressão contra o receptor, de modo que o cabeçote tenha pressão suficiente sobre a alavanca do obturador, o bico fique atrás do obturador móvel e o próprio obturador fique nivelado com a parte frontal do receptor.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/7b506200-0d61-4b88-aaf8-40475e3ad463" />
   
   Pressione o botão `Set`.

5. Pressione `Move the extruder to cutter stiker position` e mantenha pressionado por 20 segundos
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/e61c61c0-f1a1-4535-b9ef-37baa4ab1d8c" />

4- Ajuste a faca. Pressione `CutX` - a faca deve cortar o filamento sem se deslocar ou bater.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0c1939e-dada-48cb-8789-df43999bf99b" />
   
   Pressione o botão `Set`.

---

## **10. Comandos IFS**

Para que essas configurações funcionem, é necessário **desabilitar a tela nativa da impressora** usando a macro `DISPLAY_OFF`.

- IFS_F10 - Inserir barra
- IFS_F11 - Remover barra
- IFS_F13 - Status do IFS
- `IFS_F15` - Reiniciar driver
- `F18` - Apertar o filamento em qualquer lugar
- F23 - Marcar a barra como inserida
- F24 - Fixação do filamento
- F39 - Aperto do filamento
- F112` - Parar a alimentação do filamento
- `PURGE_PRUTOK_IFS` - Limpar a haste do IFS para a extrusora
- `REMOVE_PRUTOK_IFS` - Remove barra por número de barra
- `INSERT_PRUTOK_IFS` - Insere barra no IFS pelo número da barra
- `SET_CURRENT_PRUTOK` - Especifica para o klipper qual barra está ativa no momento
- `ANALOG_PRUTOK` - Carrega uma barra semelhante
- `IFS_MOTION` - Verifica se o filamento parou ou ficou sem filamento

Parâmetros do módulo IFS:

- debug - depurar (True, *False*)
- silk_count - a partir de qual tentativa de leitura a barra está no IFS (*1*)
- stall_count - em qual tentativa de leitura a barra parou (*1*)
- retry_count - quantas vezes repetir o comando em caso de erro (*3*)
- filament_NEWFILEMENT - adiciona um novo tipo de parâmetro de filamento - temperatura de substituição desse tipo de plástico.

Definido por meio de `mod_data/user.cfg`:
```
[zmod_ifs].
debug: True
silk_count: 1
stall_count: 1
filament_NEWTYPE: 300
```

## **11. Restaurar o firmware do IFS**

Para reconstruir o firmware do IFS, você precisa de um programador **ARM J-LINK V9**.

<img width="800" height="800" alt="image" src="https://github.com/user-attachments/assets/ae91768b-00d8-4e36-a62d-3056a7e117bf" />

<img width="960" height="479" alt="image" src="https://github.com/user-attachments/assets/f623fa41-4bc3-40a4-a434-5d8ad717792b" />

Soldagem dos fios na placa iFS

<img width="579" height="774" alt="image" src="https://github.com/user-attachments/assets/cb2b2f72-9eba-4831-8cea-072813b6e0e3" />

Conexão:

- CLK a SWCK
- DIO a SWIO
- VCC a 3,3
- GND a GND

<img width="346" height="390" src="https://github.com/user-attachments/assets/19438d58-9879-48e5-8acc-bfb21ce4549c" />

- Dispositivo de destino - `Nations N32G455RE`.
- Interface de destino: `SWD`
- Velocidade: `4000`
- Marque a primeira caixa.
- Desmarque a segunda caixa

1. Conectar
2. Selecione [arquivo flash](/en/Native_FW/#5x-ifs). **Não se esqueça de descompactá-lo**.
3. pressione **F7** e aguarde o dispositivo piscar

## IFS: erro do sensor: erro de comunicação serial: falha na leitura: o dispositivo informa que está pronto para ler, mas não retornou dados (dispositivo desconectado ou acesso múltiplo na porta?).

Esse erro ocorre quando a tela nativa e o mod acessam o IFS ao mesmo tempo.

É melhor reduzir o tempo de vida da tela nativa para 10 segundos: ```SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=10```.
