## Recomendações
## Recomendações para melhorar a estabilidade da impressora

As recomendações se aplicam tanto ao firmware nativo quanto ao ZMOD.

---

### Habilitar a exclusão de modelos

Ativar a exclusão de modelos no Orca:

- `Process Profile` -> `Other` -> `Output G-cod` -> `Model Exclusion` para ativar a caixa de seleção
- `Process Profile` -> `Other` -> `Output G-cod` -> `Exclude models` para habilitar a caixa de seleção

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

---

### Instale o firmware nativo mais recente e a atualização do ZMOD

Somente a versão mais recente do mod é compatível.

O autor não tem os recursos para oferecer suporte a todas as versões, portanto, [instale o firmware nativo mais recente e a atualização do ZMOD](/en/Setup/).

### Substituir Spiral/Automatic Z-Hop.

A impressora não é compatível com ele.

No Orca. `Printer Profile` -> `Extruder 1` -> `Z-axis lift type`. Defina `Ordinary' ou `Tilt'.

---

### Desative o "Arc_move" (movimento de arco).

A impressora os suporta, mas eles reduzem a qualidade de impressão e, ocasionalmente, causam erros de impressão.

No Orca. `Process Profile` -> `Quality` -> `Precision` -> `"Arc_move approximation"` desmarque a caixa.

---

### Desative a câmera integrada na tela da impressora.

Ela consome mais memória e a qualidade da imagem é ruim.

Use uma câmera alternativa.

Na tela da impressora. `Configurações` -> `Aba da câmera` -> Desmarque `Câmera` e `Vídeo`.

Em seguida, execute a macro [CAMERA_ON](/pt/Zmod/#camera_on)

- [O que é uma câmera alternativa?](/pt/FAQ/#what-is-an-alternate-camera)
- Instalei uma impressora e o ZMOD escondeu minha câmera! Eu a vi no Orca-FF e agora ela sumiu!](/pt/FAQ/#I-installed-a-printer-and-ZMOD-hid-my-camera-in-orca-ff-I-see-it-and-now-it's-gone).

---

### Desativar nuvens chinesas.

### Erro no modo Lan

Desconecte as nuvens chinesas, pois elas são instáveis e caem periodicamente.
Quando a conexão é restaurada, elas obstruem a impressora com solicitações em atraso e causam erros.

Além disso, quando as nuvens chinesas estão em execução, a impressão a partir da tela nativa com remoção da área de trabalho e janelas de fechamento rápido não funciona.

Na tela da impressora.

`Configurações` -> `Aba WiFi` -> `Modo de rede` -> Habilite `Somente redes locais`.

A desativação das nuvens chinesas permite fechar rapidamente a janela "Ok" após a impressão, imprimindo com o mapa da tabela removido usando o algoritmo da tela nativa.

`Configurações` -> `Aba nuvem` -> Desativar `"FlashCloud"` e `"Polar3d"`.

Em vez disso, você pode usar:

- [zmod.link](/pt/Zmod/#zlink) - nuvem, para gerenciar impressoras via Fluidd/Mainsail.
- [Telegram bot](/pt/Macros/).

[Mais sobre nuvens chinesas](/pt/Global/#china_cloud).

---

### Habilite o controle [MD5].

Igor Polunovskiy

[CHECK_MD5](/pt/Sistema/#check_md5)

Recomenda-se usar o [parâmetro global FORCE_MD5](/pt/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`.

1. É necessário localizar e fazer download em seu computador de um arquivo para sua arquitetura e sistema operacional:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Não se esqueça de executar ```chmod +x zmod_preprocess-linux-amd64`''
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Intel. Não se esqueça de executar ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Silicon. Não se esqueça de executar ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Não se esqueça de executar ```chmod +x zmod-preprocess.py``` ```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Lembre-se de executar ```chmod +x zmod-preprocess.sh```.

2. No Orca, você precisa escrever. ```Process Profile``` -> ```Other``` -> ```Post Processing Scripts```.

Se houver espaços no caminho, você deve colocar o caminho completo entre aspas, mas é melhor não usar espaços nas pastas.

Aqui estão as variantes de adição:

- ````"C:C:\path_to_file\zmod_preprocess-windows-amd64.exe";````
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ````"/usr/bin/python3" "/home/user/zmod-preprocess.py";````
- ````"/home/user/zmod-preprocess.py";````
- ````"/home/user/zmod_preprocess-darwin-amd64";````
- ````"/home/user/zmod_preprocess-darwin-arm64";````
- ````"/home/user/zmod_preprocess-linux-amd64";````

<img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

[Leia mais](/pt/System/#check_md5)

*hamster

---

### Envie arquivos para impressão via "Octo/Klipper".

O protocolo nativo FF ocasionalmente envia arquivos quebrados e também não gera imagens e metadados para o bot do Telegram.

No Orca. Clique no ícone Wifi ao lado da impressora:

- Protocolo: `Octo/Klipper`.
- Nome do host: `IP_printer_name:7125`.
- Endereço URL do host: `IP_printer` ou `IP_printer:80`

Se o Mainsail for usado, especifique somente estes tamanhos de miniatura: ```140x110/PNG, 64x64/PNG```.

No Orca, ```Printer Profile``` -> ```General Information``` -> ```Advanced``` -> ```G-Code Thumbnails```.

Observe que a tela nativa deixará de exibir miniaturas.

---

### Ativar correção do erro E0017

[E0017](/pt/Global/#fix_e0017)

Já está ativado por padrão

---

### Ativar correção do erro E0011

Deve corrigir o `E0011` e o `Tempo limite de comunicação durante o homing`.

[E0011](/pt/Global/#fix_e0011)

---

### Verifique a exatidão dos arquivos do sistema operacional nativo

Devido à falta de desligamento correto da impressora no firmware, o sistema de arquivos pode estar corrompido.

O que eventualmente leva a uma série de bugs menores ou maiores.

A macro [CHECK_SYSTEM](/pt/System/#check_system) verifica a soma MD5 dos arquivos e indica quais foram corrompidos.

Ela também verifica se os links simbólicos estão corretos e os corrige automaticamente, se necessário.

---

### Habilite o controle de impacto do bocal na mesa.

O controle é desativado por padrão.

Ativado pela macro [NOZZLE_CONTROL](/pt/Global/#nozzle_control)

`NOZZLE_CONTROL WEIGHT=0`

O controle desligará o Klipper caso o bocal comece a arranhar a placa ou a peça saia da mesa.

É especialmente recomendável ativar o controle para aqueles que usam a pré-limpeza do bico.
