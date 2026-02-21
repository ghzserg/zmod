<h1 align="centre">Zmod</h1>

Uma macro é um pequeno programa na linguagem Klipper/Gcode.

Ela pode ser chamada por:

- Do arquivo GCODE
- No console do Fluidd/Mainsail (pressione a letra inglesa `C` no fluidd)

!!! Nota
    *O valor entre colchetes é o valor padrão.

---

### CAMERA_ON

Use uma implementação alternativa da câmera

- WIDTH - largura da imagem (640)
- HEIGHT - altura da imagem (480)
- FPS - quadros por segundo (20)
- VIDEO - dispositivo de vídeo (video0)
- FS - 1 para ativar a limitação do tamanho do quadro para câmeras curvas, 0 para não ativar (0)
- STREAMER - qual streamer usar (auto, mjpg_streamer, ustreamer)
- FORMAT - formato de imagem para ustreamer: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG; padrão: MJPEG.

*Desative a câmera na tela da impressora e só então chame a macro.

Para ligar a câmera, use ```CAMERA_ON VIDEO=video0``` ou ```CAMERA_ON VIDEO=video3``` ou ```CAMERA_ON VIDEO=video99```.

<img width="734" height="221" alt="{D2A001DD-7C89-4AB9-9CB9-741B7007B0B4}" src="https://github.com/user-attachments/assets/e8ddbbd3-ebbf-4b4e-86cc-2a62365a4a88" />

Se a câmera não estiver funcionando, consulte os logs `mod_data/log/cam/`

Consumo de RAM na câmera padrão:

- 640x480 - 2,9 MiB
- 1280x720 - 7,8 MiB
- 1920x1080 - 18,1 MiB

*Muitas câmeras de Ali/Ozon/Wildberries sempre consomem 18 MiB.

- [O que é uma câmera alternativa?](/pt/FAQ/#what-is-an-alternative-camera)
- Instalei uma impressora e o ZMOD escondeu minha câmera! Eu a vi no Orca-FF e agora ela sumiu!](/pt/FAQ/#I-installed-a-printer-and-ZMOD-hid-my-camera-in-orca-ff-I-see-it-and-now-it's-gone).

`Camera Off Waiting...` - essa mensagem é exibida se o fluxo da câmera ainda não estiver disponível. A câmera inicia depois que o Klipper inicia - enquanto as informações sobre os parâmetros globais estão sendo exibidas

#### Configuração da câmera

**Parâmetros principais**

| Parâmetro | O que faz | Valor normal
|----------|------------|------------------|
| WIDTH | Largura da imagem | 640 |
| `HEIGHT` | altura da imagem | 480 |
| `FPS` | Quantos quadros por segundo | 20 |
| `VIDEO` | número da câmera | video0 |
| `FS` | Corrigir câmeras problemáticas (1 para sim, 0 para não) | 0 |
| `STREAMER` | Programa da câmera | auto |
| `FORMAT` | Formato da imagem (somente no ustreamer) | MJPEG | MJPEG | MJPEG

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

### CAMERA_OFF

Desativar a implementação da câmera alternativa

---

### CAMERA_RESTART

Reinicie a implementação da câmera alternativa

---

### REMOVE_ZMOD

Remover zMod.

- FULL: 0 - deixa a pasta `/opt/config/mod_data`, 1 - exclui a pasta `/opt/config/mod_data` (0)

Atenção! Desative todos os plug-ins e mude para o Klipper nativo.

A pasta `/opt/config/mod_data` contém as configurações `zmod`, `fluidd`, `moonraker` e `mainsail`.

Ela não é excluída por padrão, pois as pessoas costumam chamar a macro `REMOVE_ZMOD` por engano

---

### SKIP_ZMOD

Reinicialização no sistema original. Sem executar o zMod.

Os arquivos de configuração ZMOD, Moonraker e Fluidd são desativados.

Atenção! Desative você mesmo todos os plug-ins e mude para o Klipper nativo

Continua funcionando:

- Câmera alternativa
- SSH

---

### TAR_CONFIG

Salva os arquivos de configuração em um arquivo.

Faça o download do arquivo em "Configuration" -> "mod_data" -> config.tar.gz

---

### RESTORE_TAR_CONFIG

Restaura os arquivos de configuração do arquivo `config.tar.gz`.

Carregue o arquivo em 'Configuration' -> 'mod_data' -> `config.tar.gz`.

---

### ZFLASH

Permite que você atualize a partir de um pendrive USB pela rede.

Insira o pendrive USB na impressora e ligue-a.

Se estiver trabalhando no modo de tela não nativa, é importante que o pen drive seja inserido na impressora quando ela for ligada.

Essa macro procurará a versão mais recente disponível, fará o download para a unidade flash, verificará a soma MD5 do arquivo e a instalará após uma reinicialização.

---

### STOP_ZMOD

Descarregue o guppy, o moonraker e o fluidd/Mainsail da memória. O bot de telegrama também deixará de funcionar

Parâmetros:

- GUPPY (0 - não descarregar, 1 - descarregar)
- MOONRAKER (0 - não carregar, 1 - carregar)
- HTTP (0 - não carregar, 1 - carregar)

Exemplo:
```
STOP_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

Se essa linha for escrita no código inicial, o GUPPY será descarregado da memória após o início da impressão

---

### START_ZMOD

Ligue novamente o guppy, o moonraker e o fluidd/Mainsail após STOP_ZMOD.

Parâmetros:

- GUPPY (0 - não carregar, 1 - descarregar)
- MOONRAKER (0 - não carregar, 1 - descarregar)
- HTTP (0 - não carregar, 1 - descarregar)

Exemplo:
```
START_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

Se essa linha for incluída no código final, o GUPPY será iniciado após o término da impressão

---

### ZSSH_ON

Ativar o redirecionamento de SSH

- SSH_SERVER - IP do servidor SSH remoto
- SSH_PORT - porta do servidor SSH remoto
- SSH_USER - nome de usuário no servidor remoto
- VIDEO_PORT - porta no servidor remoto a ser usada para vídeo (8080)
- MOON_PORT - porta do servidor remoto a ser usada para moonraker (7125)
- REMOTE_RUN - comando a ser chamado no servidor remoto ("NONE") para reiniciar o bot de telegrama. Você pode usar o script [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh) (ele está na impressora na pasta `mod/telegram/`), escrevendo-o assim `./ff5m.sh bot1`, onde bot1 é o diretório onde o bot está instalado.
O script pode ser instalado da seguinte maneira (se você não instalou o bot com um único comando)
```
su - tbot # altere o usuário para o usuário sob o qual o serviço do bot é executado.
wget --cache=off -q -O ff5m.sh https://raw.githubusercontent.com/ghzserg/zmod_ff5m/refs/heads/main/telegram/ff5m.sh
chmod +x ff5m.sh
```

Exemplo de instalação, digite fluidd/mainsail no console:
```
ZSSH_ON SSH_SERVER=remote.server.ru SSH_PORT=22 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_RUN="./ff5m.sh bot1"
```

[Leia mais sobre o bot do Telegram](/pt/Telegram/)

O SSH é iniciado 3 minutos após o início do klipper.

Além disso, o SSH é reiniciado automaticamente (se estiver inativo) no início da impressão na macro START_PRINT.

---

### ZSSH_OFF

Desativar o cliente SSH

---

### ZSSH_RESTART

Reiniciar o cliente SSH

---

### ZSSH_RELOAD

Reinicie o cliente SSH se ele não estiver em execução.

Essa macro é chamada no início da impressão na macro START_PRINT.

---

### ZRESTORE

Restaura a impressão após uma falha de energia ou erro da impressora.

A recuperação de impressão estará ativa se a tela nativa estiver desativada, pois a tela nativa tem uma função integrada de recuperação de impressão.

Para que a função de recuperação funcione, **o nome do arquivo de impressão não deve começar com um número**.

---

### ZLINK

Conecte-se à nuvem [zmod.link](https://zmod.link/link/)

- A nuvem permite que você controle a impressora via Fluidd ou Mainsail de qualquer lugar.
- O consumo de memória da impressora aumenta em 1 MB.
- Os dados são transferidos para a nuvem a partir da impressora usando criptografia.
- O acesso à nuvem de qualquer lugar também usa criptografia.
- O usuário vê apenas suas impressoras e não pode se conectar a outras impressoras.
- O acesso às impressoras do usuário é protegido por um login e uma senha

Como obter o login e a senha:

1. Conecte-se ao bot [@zmod_help_bot](https://t.me/zmod_help_bot)
2. Digite o comando ```cloud``` - se você já tiver se registrado antes, ele informará seu nome de usuário
3. para registrar um usuário com o nome ```test```, digite: ```cloud register test```.
4. Para redefinir a senha, digite: ```cloud reset_password```.

Como se conectar à nuvem [zmod.link](https://zmod.link/link/):

1. Vá para [zmod.link](https://zmod.link/link//) e digite seu login e senha
   
   <img width="547" height="615" alt="{264D6782-600F-4700-B9D2-0582F7427FD2}" src="https://github.com/user-attachments/assets/d8d3f51e-4fc7-4e1e-8fa7-dfc07ddbeab2" />

2. Clique no botão "Add Printer" (Adicionar impressora)
   
   <img width="569" height="502" alt="image" src="https://github.com/user-attachments/assets/72346ee6-dde6-4736-80b1-2eb2927bf983" />

3. abra a impressora na guia vizinha e, no console da impressora, digite o comando ```ZLINK```
   
   <img width="1563" height="163" alt="{90DC4366-D258-4912-8028-22C589DF4E91}" src="https://github.com/user-attachments/assets/bee350ee-8d99-465c-9621-48788c6f7a9c" />

4. Copie a chave para a área de transferência - ela está destacada na captura de tela
5. Digite o nome da impressora e a chave que você copiou na etapa anterior
   
   Exemplo:

   - `testprinter`.
       - `ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAAIbmlzdHAyNTYAAABBBDxX5XzNDXg+sbTArdiOzFpMtHXzgAhfC2N2ogS4TUsQYV4AD6HfSFL3J4ISNZ2DgesZf35rfH1I/qI2ckQVGlE=`

   
   <img width="557" height="775" alt="{E4FC2206-84BC-4134-92C2-B4253D8F23E5}" src="https://github.com/user-attachments/assets/b6401b71-5827-480d-ba1c-b7114f87177b" />
   
   Clique no botão "Add Printer" (Adicionar impressora)

6. Copie o comando que o site lhe forneceu e cole-o no console da impressora
   
   <img width="558" height="652" alt="{CDC8146F-B9DF-44A1-9C0B-3E6828CD540E}" src="https://github.com/user-attachments/assets/ed92a80f-93cc-41b8-bde1-aa0b2b2c0ecc" />
   
   No exemplo ````zlink p=testprinter u=test m=10006 c=30006```.

   Clique em ````Eu já inseri a linha na impressora```
   
   A impressora poderá então se conectar à nuvem.
   
   Para desativar a conexão, digite ```ZLINK_OFF```.

7. Agora você pode se conectar ao Fluidd ou ao Mainsail pela Internet
   
   <img width="526" height="654" alt="{CA6FC599-6060-4E3B-B525-EBB76D8780A1}" src="https://github.com/user-attachments/assets/0208dbad-8627-4636-b971-cfe0c5d7f8bd" />
   
   Tudo o que você precisa fazer é selecionar o botão desejado.

PS: A câmera pode carregar mais tarde do que a interface, o que é normal

PPS: Se algo der errado, atualize a página com Ctrl + F5 e vá para [zmod.link](https://zmod.link/link/).

   <img width="540" height="449" alt="{30D01CA4-3E9E-40EC-BCD1-9A8597DCCFDE}" src="https://github.com/user-attachments/assets/0d48b9be-a9df-4bfd-a38a-6d883ab31e73" />

   <img width="500" height="393" alt="{D03D643F-907C-4A6D-A48E-D881AAC33268}" src="https://github.com/user-attachments/assets/69f9d8d5-67ca-476e-b362-e35abb1d4832" />
