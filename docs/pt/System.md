<h1 align="centre">Sistema</h1>

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada por:

- Do arquivo GCODE
- No console do Fluidd/Mainsail (pressione a letra inglesa `C` no fluidd)

!!! Nota
    *O valor entre colchetes é o valor padrão.

---

### DISPLAY_ON

Ligue a tela padrão e reinicie a impressora.

---

#### DISPLAY_OFF

- GUPPY: 0 - não ativar o GuppyScreen, 1 - ativar o GuppyScreen (1)

Desativa a tela padrão. Economiza 13 megabytes (20 megabytes em versões mais antigas do firmware nativo).

O GuppyScreen é uma implementação de tela alternativa:

- Oferece suporte a todos os recursos da tela nativa, exceto as configurações de WiFi
- Usa 9 MB de RAM, em comparação com 23 MB na tela nativa
- Não trava quando o clipper é reinicializado
- Recomendado para uso em vez da tela nativa.
- Melhor recuperação de impressão interrompida
- Criado a partir do [fork](https://github.com/ghzserg/guppyscreen_ff5m), que é baseado no [repositório original](https://github.com/ballaswag/guppyscreen) e em outro [fork](https://github.com/consp/guppyscreen/tree/flashforge_ad5m).

**Não desative a tela a menos que entenda claramente como funcionam o mapa da tabela, o z-offset e as macros START_PRINT e END_PRINT**

**Não há necessidade de incluir essa macro no código g.
Após a reinicialização, a tela funcionará por mais 3 minutos, mas isso não afeta o z-offset, pois não imprime através dele.

Para alterar o tempo de ativação da tela alternativa [use parâmetros globais](/pt/Global/#display_off_timeout)

Defina START_PRINT. Defina o z-offset desejado por meio dele ou de parâmetros globais.

[Leia esta nota](/pt/FAQ/#qual é a diferença entre trabalhar com uma tela e sem uma tela nativa)

---

### MEM

Exibir o consumo de memória

---

### TEST_EMMC

Grava SIZE MB no EMMC e grava a velocidade de leitura e gravação.

Emite a porcentagem de desgaste do EMMC

- SIZE - quantos megabytes serão gravados (100)
- SYNC - 1 - operação em modo síncrono. SIZE megabytes de dados serão gravados e lidos e a velocidade será emitida, 0 - modo assíncrono, SIZE megabytes de dados serão gravados em segundo plano - serve como carga em segundo plano para o cartão de memória EMMC. (1)
- FLASH - gravação: 0 - para EMMC, 1 - para USB FLASH, 2 - para RAM (0)
- RANDOM - usa números aleatórios para gravação. 1 - sim, 0 - não (0)

No estoque:
Baixe o arquivo [zfs.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/.shell/zfs.sh)
```
chmod +x zfs.sh
./zfs.sh 400 1
```

---

### CLEAR_EMMC

Limpa o EMMC.

- LOG - limpa os arquivos de registro, 1 - sim, 0 - não (1)
- ANY - limpa tudo (gcode, imagens, fotos, vídeos), exceto os arquivos de registro, 1 - sim, 0 - não (0).

---

### DATE_GET

Exibir a hora atual

---

### DATE_SET

Defina a data e a hora no formato 2024.01.01.01-00:00:00:00:00

- DT - data 2024.01.01.01-00:00:00:00:00

---

### WEB

Alterar a interface da Web fluidd/mainsail

Depois de executar a macro:

- Você precisa pressionar `Ctrl + F5` ou `Ctrl + Shift + R` ou `Option + Command + E`.
- Se tiver um problema no Orca, pressione `Ctrl + F5` ou `Ctrl + Shift + R` ou `Option + Command + E`.

Se estiver usando o Mainsail, especifique apenas estes tamanhos de miniatura: ```140x110/PNG, 64x64/PNG```.

No Orca, ```Printer Profile``` -> ```General Information``` -> ```Advanced``` -> ```G-Code Thumbnails```.

Observe que a tela nativa deixará de exibir miniaturas.

Atenção: O autor usa o Fluidd, o Mainsail é testado apenas por usuários. Se você tiver problemas com o Mainsail, crie um [ticket](/pt/Help/)

---

### SET_TIMEZONE

Alterar o fuso horário

- ZONE - fuso horário (Ásia/Yekaterinburg)

---

### CHECK_MD5

Igor Polunovskiy

É recomendável usar o [parâmetro global FORCE_MD5](/pt/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`.

Verifique a soma MD5.

- DELETE - excluir arquivo quebrado (sim)

1. É necessário selecionar e fazer o download em seu computador de um arquivo para sua arquitetura e sistema operacional:

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

Os arquivos de origem podem ser encontrados aqui: [https://github.com/ghzserg/zmod_preprocess](https://github.com/ghzserg/zmod_preprocess)

```
Interrompe a impressão em caso de incompatibilidade de checksum com possível exclusão do arquivo defeituoso.

O autor não se responsabiliza por quaisquer erros ou problemas ou pelos resultados obtidos com o uso dessas informações.

A soma de verificação é gravada no início do arquivo de código G. Se o arquivo não contiver uma soma de verificação, a macro não verificará o arquivo e ele será imediatamente enviado para impressão.
O resultado da verificação é impresso no console.

=========================================
1. Em uma máquina Windows em que o fatiador esteja instalado.
  a) Faça o download de https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe
  b) Adicione o script do ponto 1.a. ao fatiador,
     substituindo "disk:\patch\to\file\" pelo caminho para o script:
    - Para o OrcaSlicer
      "Process"->"Other"->"Postprocessing scripts".
    - Para o SuperSlicer e o PrusaSlicer
      "Print Settings"->"Output Options"->"Post-Processing Scripts" (Configurações de impressão"->"Opções de saída"->"Scripts de pós-processamento").
    disco:\patch\to\file\zmod_preprocess-windows-amd64.exe;
  c) Adicione uma macro ao fatiador
    - para o OrcaSlicer.
      "Printer Profile" (Perfil da impressora) -> "Printer G-code" (Código G da impressora) -> "Printer Start G-code" (Código G de início da impressora).
    - Para o SuperSlicer e o PrusaSlicer
      "Printer Settings"->"Custom G-code"->"Start G-code" (Configurações da impressora"->"Código G personalizado"->"Iniciar código G").
    * Sem excluir o arquivo:
      CHECK_MD5
    * Com a exclusão do arquivo:
      CHECK_MD5 DELETE=true
  d) Se a macro START_PRINT for usada, não será necessário adicionar CHECK_MD5 ao código inicial. Por padrão, a verificação é feita automaticamente.
```

---

### UPDATE_MCU

Atualiza a MCU na impressora.

Altera o firmware da MCU da versão nativa do Klipper (11 para FF5M/FF5MPRO, 12 para AD5X) para Klipper 13 e vice-versa

Klipper 13 (desativado por padrão).

Parâmetro FORCE:

- 11 - carregar firmware do Klipper 11 - FF5M
- 12 - carregar firmware do Klipper 12 - AD5X
- 13 - carregar firmware do Klipper 13

Altera o firmware para o firmware oposto sem parâmetros.

Exemplo: `UPDATE_MCU FORCE=13` força o carregamento do firmware do Klipper 13

Se você não entender como [restaurar as configurações e o firmware da MCU](/pt/Native_FW/#installing-full-firmware-on-ad5x), não o execute.

Se algo der errado, volte apenas para [factory](/pt/Native_FW/).

---

### RESET_PASSWD

Redefinir a senha do usuário root para root

---

### CHECK_SYSTEM

Verifique se há arquivos corrompidos no sistema operacional da impressora.

- RESTORE: 0 - não repara arquivos corrompidos, 1 - repara arquivos corrompidos (0)

Verificações:

- Arquivos (md5, permissões)
- Catálogos (permissões)
- Links simbólicos (exatidão da especificação)

Links simbólicos, direitos a diretórios e arquivos são restaurados automaticamente.

O tempo de verificação é de cerca de 10 minutos.

Se forem encontrados erros, vá para [link](https://github.com/ghzserg/zmod/tree/main/stock), onde você poderá fazer o download de uma cópia não danificada do arquivo.

---

### TELA

Obtenha uma captura de tela da tela da impressora

A captura de tela será salva em ```mod_data/screen.jpg```.
