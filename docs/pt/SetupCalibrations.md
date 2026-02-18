### [Calibração](#calibrar-impressora-para-iniciantes)

### Calibração de impressora para iniciantes

Em geral, você não precisa calibrar nada, mas se quiser configurar melhor sua impressora, continue lendo:

Se você já passou pelas calibrações iniciais:
<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/c0c63cc4-c4b3-46d4-a3e7-6485d8bf26bb" />

Então você já fez isso:

- Um z-offset está configurado
- Há um mapa de tabela ```MESH_DATA``` (obtido a 60 graus) - não é possível excluí-lo se você usar a tela nativa, pois ele é carregado sempre que você imprime
- Há uma calibração do PID da extrusora a 240 graus

Mas essas configurações são bastante genéricas, não há muitas pessoas que imprimem a 240 graus de temperatura do bocal e 60 graus de temperatura da mesa.

---

### Configuração do PID da extrusora

**Por que isso é necessário?
Pense em uma extrusora como um forno. Se a temperatura nele estiver constantemente "pulando", o prato (sua peça) poderá não assar uniformemente. A calibração do PID "ensina" a impressora a manter a temperatura correta sem nenhum salto. Isso é fundamental para a qualidade da impressão.

**Um ponto importante antes de começar!
Calibre para as condições exatas em que você está imprimindo:

* Temperatura: A que você usa com mais frequência para o seu plástico (por exemplo, 210°C para PLA ou 255°C para PETG).
* Resfriamento:** O resfriador deve operar com a mesma capacidade da impressão normal.

**Como fazer a calibração?

- Use o comando especial (macro) [PID_TUNE_EXTRUDER](/en/Calibrations/#pid_tune_extruder)

- Você pode inseri-lo manualmente no console ou clicar no botão na interface, se a tiver:
    <img width="283" height="265" alt="image" src="https://github.com/user-attachments/assets/20b8a3c8-4726-44b0-b986-34881d95cb18" />

- O comando em si tem a seguinte aparência (este é um exemplo!):
    ```gcode
    PID_TUNE_EXTRUDER TEMPERATURE=255 COOLER=80
    ```
    **O que isso significa:**

    * * ```TEMPERATURE=255``` - a calibração é realizada para uma temperatura de 255°C. Defina a temperatura que você deseja.
        * ```COOLER=80``` - o cooler sopra a 80% da potência.

- **Quando terminar:**
    **A impressora salvará as novas configurações sozinha.
        * Certifique-se de reiniciar a impressora! Isso serve para atualizar os dados no sistema e evitar congelamentos.

---

### Configuração do PID da tabela

**Por que eu preciso disso?
A mesa da sua impressora, assim como a extrusora, precisa manter a temperatura com precisão. Se ela flutuar, poderá causar problemas de aderência da primeira camada ou até mesmo deformação (descascamento) da peça nas bordas. A calibração PID de sua mesa a ensinará a atingir a temperatura correta de forma rápida e consistente, sem superaquecimento.

Recomendação para AD5X

Abra o arquivo `printer.cfg` e defina a seção ```heater_bed``` como:
```
[heater_bed].
max_power: 0.6
```
Isso permitirá que a mesa aqueça mais rapidamente e o PID se ajustará corretamente.
Depois de alterar e salvar o parâmetro, você deve reiniciar a impressora.

Ou você pode ativar o plug-in de recomendações e ele corrigirá esse arquivo sozinho: ````ENABLE_PLUGIN NAME=recommend```.

**Um ponto importante antes de começar!**
A regra aqui é a mesma da extrusora: calibre para a temperatura que você planeja usar com mais frequência ao imprimir (por exemplo, 60 °C para PLA ou 110 °C para ABS).

**Como calibrar?

- Use a macro [PID_TUNE_BED](/pt/Calibrations/#pid_tune_bed)

- Ela também pode ser inserida no console ou chamada com um botão na interface (geralmente ao lado do botão para calibrar a extrusora):

    <img width="227" height="192" alt="image" src="https://github.com/user-attachments/assets/77dd8332-1912-41df-a94e-469ebfa2f895" />

- O comando para a tabela parece ainda mais simples:
    ```gcode
    PID_TUNE_BED TEMPERATURE=80
    ```
    **O que isso significa:**

    * ```TEMPERATURE=80``` - a calibração é realizada para uma temperatura de mesa de 80°C. Defina a temperatura desejada.

- Quando terminar:** ** **
    * As novas configurações serão salvas automaticamente.
        * Não se esqueça de reiniciar a impressora! Isso concluirá o processo de aplicação das novas configurações.

---

### Calibração dos parafusos da mesa (BED_LEVEL_SCREWS_TUNE)

**Por que fazer isso?
Sua mesa é mantida unida por vários parafusos. Se eles não forem parafusados da mesma forma, a mesa ficará desalinhada e a distância entre a mesa e o bocal ficará irregular. Isso faz com que o plástico grude muito e o bocal bata no modelo. Essa calibração ajuda a alinhar a mesa perfeitamente, ajustando os 4 parafusos que a mantêm no lugar.

**Como funciona?

1.  A impressora leva o bico para as posições acima de cada parafuso, um por vez.
2. mede a distância até a mesa e mostra na tela qual parafuso deve ser girado e em que direção.
3.  Você ajusta os parafusos seguindo os avisos.
4.  O processo é repetido até que a mesa esteja nivelada.

**Parâmetros de ajuste [BED_LEVEL_SCREWS_TUNE](/en/Calibrations/#bed_level_screws_tune):**

* `EXTRUDER_TEMP=130` - temperatura da extrusora. Necessário para que a expansão térmica do bocal não distorça as medições. Defina a temperatura na qual o plástico ainda não está saindo do bocal.
* `BED_TEMP=80` - Temperatura da mesa. A mesa também se expande quando aquecida, portanto, a calibração deve ser feita na temperatura em que você está imprimindo.

Antes da calibração, você deve limpar o bocal, caso contrário, as medições não serão corretas!

**Processo de calibração:**

- Digite um comando no console ou pressione o botão:

    <img width="344" height="310" alt="image" src="https://github.com/user-attachments/assets/6757eb4e-53b7-4b08-903f-75491b4daace" />

    ```gcode
    BED_LEVEL_SCREWS_TUNE EXTRUDER_TEMP=130 BED_TEMP=80
    ```

- **Importante:**
    * A impressora aquecerá a extrusora e a mesa até as temperaturas definidas.
        * Ela iniciará o procedimento e mostrará qual parafuso deve ser girado e o quanto deve ser girado (por exemplo, "clockwise" (sentido horário) para sentido horário, "counter-clockwise" (sentido anti-horário) para sentido anti-horário).

    <img width="621" height="394" alt="image" src="https://github.com/user-attachments/assets/f930f4ac-e907-4c83-bc1d-3d5a4e06fe3b" />

- Após a primeira passagem, a impressora aguardará que você faça o ajuste. Quando todos os parafusos estiverem apertados, **pressione o botão de repetição** para que a impressora verifique o resultado. Repita até que a leitura esteja perfeita.

- Finalizando o trabalho:**
    **Quando você terminar e sair do modo de calibração, a impressora **NÃO redefinirá** a temperatura automaticamente.
        * Ajuste automaticamente as temperaturas da extrusora e da mesa para zero por meio do menu de controle!
        * O mapa da mesa e o z-offset ficarão incorretos. Execute uma calibração de nível a partir da **tela nativa**.

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/2d17f77f-a98b-450d-a7e5-72a0a37e47de" />

---

### Criar um mapa de tabela preciso (AUTO_FULL_BED_LEVEL)

**Por que isso é necessário?
Mesmo uma mesa perfeitamente nivelada pode ter pequenas depressões ou saliências. Um mapa da mesa (ou "calibração de malha") é como um "mapa de altura" de sua mesa. A impressora se lembra dessas irregularidades e moverá levemente o eixo Z durante a impressão para que o bocal esteja sempre na distância perfeita da superfície. Isso garante que a primeira camada adira perfeitamente em toda a área da mesa.

**Por que esse comando?
As ferramentas embutidas Fluidd e Mainsail não são adequadas para nossas impressoras porque elas:

* Não sabem como trabalhar com o **sensor de toque** (que é responsável pela detecção precisa do toque).
* Elas não **limpam o bocal** antes de você começar, para remover qualquer gota de plástico que possa arruinar a precisão das medições.

Nossa macro [AUTO_FULL_BED_LEVEL](/pt/Calibrations/#auto_full_bed_level) leva esses dois recursos em consideração!

**Configurações importantes:**
O mapa precisa ser criado sob as mesmas condições em que você está imprimindo - uma mesa aquecida e uma extrusora quente, pois a temperatura faz com que o metal se expanda ligeiramente. Um mapa de mesa gravado a 60 graus é muito diferente de um mapa de mesa gravado a 110 graus.

* `EXTRUDER_TEMP=255` - temperatura da extrusora. O plástico no bocal deve ser derretido para que possa ser limpo antes da medição. Defina a temperatura que você deseja.
* `BED_TEMP=80` - Temperatura da mesa. Especifique a que está sendo usada para impressão. Defina a temperatura desejada.
* `PROFILE=auto` - nome do perfil sob o qual o cartão será salvo. É melhor nomeá-lo de acordo com a temperatura da tabela, por exemplo, `80`.

**Exemplo de comando:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=255 BED_TEMP=80 PROFILE=80
```

<img width="302" height="342" alt="image" src="https://github.com/user-attachments/assets/643b7bbc-992d-40cb-9404-1fed185ad0ea" />

Neste exemplo, criamos um mapa para imprimir em uma mesa de 80°C e o salvamos com o nome `80`.

#### Como posso usar o mapa salvo na impressão?

Para que a impressora carregue automaticamente o mapa correto no início de cada impressão, adicione as seguintes linhas ao **Start G-code* do seu OrcaSlicer:

```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=80
M190 S[bed_temperature_initial_layer_single] ; Aguarde o aquecimento da mesa
M104 S[nozzle_temperature_initial_layer] ; Definir a temperatura do bocal
```

**O que está acontecendo aqui:**

* [START_PRINT](/pt/Main/#start_print) é a macro básica de início de impressão
* A string `START_PRINT.... MESH=80` diz à impressora para `Iniciar a impressão e carregar um mapa de tabela chamado `80`."
* `[nozzle_temperature_initial_layer]` e `[bed_temperature_initial_layer_single]` são variáveis do fatiador que fornecerão automaticamente as temperaturas desejadas para a primeira camada.
* O principal é certificar-se de que o parâmetro `MESH=` aponte para o mesmo nome de perfil (em nosso exemplo é `80`) que você usou em `AUTO_FULL_BED_LEVEL`.

Melhor ainda, crie vários mapas para cada temperatura 60, 70, 80, 90, 100, 110 e escreva esse tipo de código inicial:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Aguarde o aquecimento da mesa
M104 S[nozzle_temperature_initial_layer] ; Definir a temperatura do bocal
```

Nesse caso, você terá o mapa da mesa carregado correspondente à temperatura da mesa.

> Observação:
> > Se não houver nenhum mapa de tabela salvo para o valor definido no fatiador (por exemplo, definir 77 graus), o algoritmo removerá o mapa de tabela e se oferecerá para salvá-lo no final da impressão com o nome 77.

**Ordem total das operações:**

1.  Crie um mapa de tabela com a macro `AUTO_FULL_BED_LEVEL` para sua temperatura de impressão.
2.  Adicione o comando `START_PRINT` ao código de início do fatiador com o parâmetro `MESH=...` apontando para o nome do seu perfil.
3 A impressora agora usará automaticamente o mapa de relevo correto sempre que você imprimir!

---

### Calibração de tabela adaptável (KAMP)

**Por que ele é necessário?
O [KAMP](/pt/Calibrations/#kamp) é um sistema inteligente que constrói um mapa das irregularidades da mesa não em toda a área, mas somente na área em que seus modelos estarão! Isso acelera muito a preparação da impressão, especialmente em impressoras grandes, ao mesmo tempo em que mantém todos os benefícios de um mapa preciso da mesa.

**Como funciona?

1.  Antes do início da impressão, o KAMP analisa a localização de todos os objetos na mesa.
2.  Em vez de criar uma grade completa, ele mede a altura da mesa somente na área desejada.
3. isso economiza tempo sem sacrificar a qualidade da impressão.
4.  O mapa fica mais denso e, portanto, mais preciso

**Um recurso importante do processo:**
Ao usar o KAMP (e também a calibração completa), a impressora age de forma inteligente para garantir a máxima precisão:

1.  O bico é **aquecido até a temperatura de impressão**.
2.  Há uma **limpeza do bico** do plástico que está vazando.
3.  O bico **resfria a 120°C**. Isso evita que o plástico derretido pingue do bocal limpo durante as medições, o que poderia distorcer os resultados.
4.  Há uma **descarga do cartão de mesa** com o bocal frio e limpo.
5.  Após a medição, o bico é **reaquecido até a temperatura de impressão** para iniciar a impressão.

#### Configuração do KAMP

**Quando usar o KAMP?
Na maioria dos casos, não é necessário criar um mapa de tabela antes de cada impressão. A exceção é se você estiver usando **placas intercambiáveis com espessuras diferentes** (por exemplo, folha PEI e vidro), pois elas podem ter alturas diferentes.

**1. Ativação da calibração adaptativa (KAMP)**

Ative essa opção para que a impressora use o KAMP sempre que possível [SAVE_ZMOD_DATA USE_KAMP=1](/pt/Global/#use_kamp).

```gcode
SAVE_ZMOD_DATA USE_KAMP=1
```

Personalizar o Orca:

- ```Process Profile``` -> ```Other``` -> ```Output G-cod``` -> ```Model Exclusion``` para ativar a caixa de seleção
- `Process Profile` -> `Other` -> `Output G-cod` -> `Exclude models` para ativar a caixa de seleção

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

**2. Ative a calibração antes de cada impressão**

Se você quiser que a impressora crie automaticamente um mapa de tabela antes de cada trabalho (por exemplo, ao trocar as chapas com frequência), ative essa função [SAVE_ZMOD_DATA PRINT_LEVELING=1](/pt/Global/#print_leveling).

```gcode
SAVE_ZMOD_DATA PRINT_LEVELING=1
```

O código inicial pode ser usado desta forma:
````gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Aguarde o aquecimento da mesa
M104 S[nozzle_temperature_initial_layer] ; Definir a temperatura do bocal
```

**Importante para trabalhar na tela nativa:** Para iniciar a remoção do mapa da tabela na tela nativa da impressora, é necessário acessar o menu da tela:
```Configurações``` → ```Ícone Wifi``` → ```Modo de rede``` → ative o controle deslizante ```Somente redes locais```.

**3. Limpeza inteligente antes da impressão**

Adicione essa configuração para que a impressora use a mesma área em que acabou de passar o cartão de mesa para limpar o bico. Isso economiza espaço e tempo [SAVE_ZMOD_DATA CLEAR=LINE_PURGE](/pt/Global/#clear).

```gcode
SAVE_ZMOD_DATA CLEAR=LINE_PURGE
```

#### Conclusão: como configurar o KAMP para uma impressão perfeita

Para ativar a criação inteligente de mapas de tabelas antes de cada impressão, execute o comando uma vez:

```gcode
SAVE_ZMOD_DATA USE_KAMP=1 PRINT_LEVELING=1 CLEAR=LINE_PURGE
```

Agora, antes de cada impressão, a impressora pegará o mapa da tabela antes de cada impressão, somente onde houver objetos a serem impressos

---

### Como o Z-Offset funciona em sua impressora

**O que é Z-Offset?
Simplificando, é a **distância exata entre a ponta do bico e a mesa** no momento em que a impressora pensa que eles estão "tocando" um ao outro. Um Z-Offset correto garante que a primeira camada de plástico grude perfeitamente na mesa - nem muito baixo (o bico tocará a mesa) nem muito alto (o plástico não grudará). [Leia mais](/pt/FAQ/#how-z-offset-works)

**Regra mais importante:**
Em nossa impressora, o **Z-Offset é relevante SOMENTE durante a impressão**. Os valores que você vê na tela ou na interface ANTES ou DEPOIS da impressão são apenas para referência e não refletem a imagem real.

**Segunda regra importante
**O deslocamento Z ao trabalhar com uma tela nativa e ao trabalhar no modo de tela não nativa não é o mesmo** e cada um tem sua própria vida e é configurado separadamente. Use ```LOAD_ZOFFSET_NATIVE``` para copiar o deslocamento Z da tela nativa para o modo de tela não nativa.

#### Ajuste do deslocamento Z da tela nativa da impressora

A tela nativa é a principal ferramenta para ajustar o deslocamento Z. Ela controla automaticamente o deslocamento e suas configurações são armazenadas de forma segura.

**Para que a impressora ajuste o Z-Offset automaticamente, é necessário executar o mapa da tabela na tela nativa.

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/7e5f1ba4-832e-493b-94be-14aadf67ad4e" />

**Como ajustar:**

1.  O ajuste é possível **somente durante a impressão**.
2.  Pressione o **quadrado inferior direito** na tela sensível ao toque.
    
    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/ae62aced-07af-489f-99b1-ce91cd55027d" />

3.  Em seguida, clique no ícone **lápis** para editar o valor do Z-Offset.
    
    <img width="800" height="474" alt="image" src="https://github.com/user-attachments/assets/7d185d47-6c60-4d57-8901-923971a9ee7f" />

4.  Faça alterações com base na qualidade da disposição da primeira camada.

**Importante saber:**

* Para a impressora AD5M, a tela nativa sempre adiciona um valor fixo de **0,025 mm** ao seu valor.
* Portanto, o Z-Offset que você vê na interface Fluidd ou Mainsail será sempre **0,025 mm MAIS** do que o valor definido na tela da impressora. Isso é normal!

#### Ajuste do Z-Offset via Fluidd / Mainsail / GuppyScreen ao trabalhar **em modo de tela não nativo**

**Como funciona:**

1.  Para que a impressora se lembre do Z-Offset da interface da Web e do GuppyScreen, a configuração especial [SAVE_ZMOD_DATA LOAD_ZOFFSET=1](/pt/Global/#load_zoffset) deve ser ativada uma vez:
    ```gcode
    SAVE_ZMOD_DATA LOAD_ZOFFSET=1
    ```
    *Esse comando informa ao sistema para "Carregar o Z-Offset a partir das configurações salvas, e não redefini-lo para zero".

2.  Quando essa opção estiver ativada, você poderá ajustar o Z-Offset diretamente durante a impressão no Fluidd/Mainsail ou por meio do painel de ajuste no GuppyScreen.

    <img width="418" height="73" alt="image" src="https://github.com/user-attachments/assets/96d644b3-9c52-44d1-9a7c-18ccbac61796" />

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/0f282f39-dec1-4488-9317-4e1395747277" />

3. se desejar transferir o deslocamento z da tela nativa para o modo de tela não nativa, chame a macro ```LOAD_ZOFFSET_NATIVE```, que lerá o valor do deslocamento z da tela nativa e o aplicará ao modo de tela não nativa.

**Principais benefícios

* Independentemente do método de ajuste (tela ou interface da Web), o valor do z-Offset é salvo automaticamente e aplicado automaticamente na próxima vez que você imprimir.
* Não são necessários comandos manuais.** Você NÃO precisa usar os comandos `Z_OFFSET_APPLY_PROBE` ou `Z_OFFSET_APPLY_ENDSTOP`. Todo o trabalho é realizado "sob o capô".

#### Sobre o Z-Offset em palavras simples:

* **Ajuste o Z-Offset somente durante a impressão da primeira camada.
* Ao trabalhar com a tela nativa, ajuste o Z-Offset na tela nativa.
* Ao trabalhar no modo de tela não nativa**, primeiro execute o comando ```SAVE_ZMOD_DATA LOAD_ZOFFSET=1```.
* O sistema salvará tudo sozinho. Você não precisa se preocupar com nada.

!!! perigo
    Você não pode usar `Z_OFFSET_APPLY_ENDSTOP` nessa impressora.
    
    E você não pode alterar ```[probe] z_offset: ``` em ```printer.cfg``` ou ```printer.base.cfg```.
    
    Porque a tela nativa e a macro ```START_PRINT``` carregam o offset no início da impressão.

---

### Calibração do modelador de entrada

**O que são shapers e por que eles são necessários?
Quando a impressora se move rapidamente, ela pode vibrar como uma máquina em alta velocidade. Essas vibrações são impressas em seu modelo como "ondulações" ou "fantasmas" nas paredes. Os shapers são algoritmos inteligentes que "preveem" e suprimem essas vibrações, permitindo que você imprima mais rapidamente sem perder a qualidade.

Sua impressora já configurou automaticamente os shapers quando você a calibrou pela primeira vez, e isso é suficiente para a maioria das tarefas. Mas, se quiser maximizar a qualidade ou entender como a impressora funciona, você pode consultar os gráficos e escolher as configurações manuais.

#### Importante: O parâmetro `FIX_SCV

**Qual é o problema?
Os cálculos de gráficos e shapers no Klipper usam o valor padrão de `square_corner_velocity = 5`. Mas, em nossa impressora, o valor desse parâmetro é especificado como `25`. Essa discrepância leva ao fato de que os valores calculados da aceleração máxima nos gráficos são superestimados várias vezes.

**O que fazer?

1.  **Corrija os cálculos:** Ative a correção para exibir os gráficos corretamente [SAVE_ZMOD_DATA FIX_SCV=1](/pt/Global/#fix_scv).
    ```gcode
    SALVAR_ZMOD_DATA FIX_SCV=1
    ```

2.  **Melhorar a qualidade de impressão (recomendado):** Adicione a seguinte linha ao arquivo ```mod_data/user.cfg```:
    ```ini
    [printer].
    square_corner_velocity: 9
    ```

    * O que isso faz? A impressora ficará um pouco mais lenta em cantos agudos. Isso aumentará um pouco o tempo de impressão, mas reduzirá significativamente as vibrações e melhorará a nitidez dos cantos.

Como alternativa, você pode manter a simplicidade. Digite ```ENABLE_PLUGIN name=recommend``` no console - esse comando ativará o plug-in de recomendação, que já tem ```FIX_SCV``` ativado e `square_corner_velocity: 9``` prescrito.

Não se esqueça de reiniciar a impressora!

#### Como usar a macro `ZSHAPER

[ZSHAPER](/pt/Calibrations/#zshaper) - essa macro faz com que a impressora vibre em diferentes frequências, mede a resposta e faz um gráfico para encontrar os parâmetros ideais do shaper para os eixos X e Y.

**Recurso para impressoras com pouca memória (AD5M, AD5MPro)
Para evitar sobrecarregar o sistema, **é necessário calibrar os eixos individualmente**.

* `ZSHAPER` - calibra ambos os eixos (X e Y).
* `ZSHAPER X=1 Y=0` - calibra apenas o eixo X (mais rápido e com menos carga).
* `ZSHAPER Y=1 X=0` - calibra somente o eixo Y.

**Exemplo de aplicação e saída:**

1.  Digite o comando para calibrar o eixo Y no console:
    ```gcode
    ZSHAPER Y=1 X=0
    ```

2.  Quando as medições forem concluídas, você obterá um relatório como este:
    ```
    // O shaper recomendado é zv @ 53,2 Hz
    // Frequência do shaper 'zv' ajustada = 53,2 Hz (vibrações = 0,9%, suavização ~= 0,074)
    // Para evitar muita suavização com 'zv', sugerimos max_accel <= 10200 mm/seg^2
    // Frequência ajustada do shaper 'mzv' = 54,2 Hz (vibrações = 0,0%, suavização ~= 0,080)
    // Para evitar muita suavização com 'mzv', sugerimos max_accel <= 8700 mm/seg^2
    ```

    * O sistema recomenda o shaper `zv` porque ele tem a suavização mais fraca (`smoothing`).
        * Mas o shaper `mzv` suprime completamente as vibrações (`0,0%`), embora exija um pouco menos de aceleração.

#### Como interpretar os resultados e tomar uma decisão

**Onde ver os gráficos?
Depois de executar o `ZSHAPER`, os gráficos e os arquivos CSV aparecerão na guia **"Configuration" -> mod_data** em sua interface da Web (Fluidd/Mainsail).

<img width="996" height="596" alt="image" src="https://github.com/user-attachments/assets/7e1dbdf8-5de5-4ce6-8f4a-2c37b320b8b3" />

**Instruções completas para leitura de gráficos:** [https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md](https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md)

**Opção 1: Aceitar a configuração automática**

Se estiver satisfeito com tudo, basta clicar no botão **`SAVE CONFIG & RESTART`** na interface da Web e a impressora registrará as configurações recomendadas por conta própria.

<img width="324" height="68" alt="image" src="https://github.com/user-attachments/assets/9c76d5f7-0021-4e03-b495-6736f49dc1c9" />

<img width="745" height="389" alt="image" src="https://github.com/user-attachments/assets/b5b55e95-52af-4ee0-b34e-5bc6077d8d10" />

**Opção 2: Ajuste manual**

No exemplo acima, achei o shaper `mzv` melhor, pois ele remove completamente as vibrações. Para usá-lo, é necessário adicionar manualmente as configurações ao arquivo `printer.cfg` (na seção `[input_shaper]`):

```ini
[input_shaper].
shaper_type_y = mzv ; Tipo de shaper selecionado para o eixo Y
shaper_freq_y = 54.2 ; Frequência ressonante para o eixo Y
```

**E não se esqueça da aceleração!
Como o shaper selecionado `mzv` permite usar uma aceleração não superior a 8700 mm/s², esse valor deve ser gravado no arquivo `mod_data/user.cfg`:

```ini
[printer].
max_accel: 8700 ; Aceleração máxima para os eixos X e Y
```

#### Algoritmo resumido de ações para calibração do shaper:

1.  Execute `SAVE_ZMOD_DATA FIX_SCV=1` para obter cálculos corretos.
2.  Adicione `square_corner_velocity: 9` ao `mod_data/user.cfg` para obter melhor qualidade.
3.  Execute a calibração do eixo desejado, por exemplo, `ZSHAPER Y=1`.
4. examine os gráficos e a saída do console.
5.  Pressione `SAVE CONFIG` ou escreva manualmente os valores `shaper_type` e `shaper_freq` desejados em `printer.cfg` e `max_accel` em `mod_data/user.cfg`.
6.  Reinicialize a impressora.
