<h1 align="centre">Botão de telegrama</h1>

| Função / Recurso | [Plug-in de notificação](https://github.com/ghzserg/notify/blob/main/Readme_ru.md) | [Moonraker Telegram Bot](/pt/Telegram/) | [Moonraker Telegram Bot](/pt/Telegram/) |
| :--- | :---: | :---: |
| **Requer servidor externo** | - | + | |
| **Controle remoto da impressora** | - (pode ser feito via [zmod.link](https://zmod.link/link/)) | + | | |
Criar lapso de tempo** | - (pode ser feito via [timelapse](https://github.com/ghzserg/timelapse/blob/main/Readme_ru.md) | + | | |
| **Imprimir informações do evento** (início, pausa, cancelamento, fim) | + | + | | | | + |
| **Informações do sensor de filamento** | + | + | + | | | |
**Imprimir informações de progresso em porcentagem** | + | + | | + | | | |
Trabalho com várias impressoras por meio de um bot** | + | | | - | | | |
| **Informar através de outros serviços** | + | | - | | | |
| **Splooman** | | - | + | |

---

Se você precisar apenas de notificações do Telegram, [use o plug-in Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md).

## Bot do Telegram

### Descrição

Se apenas as notificações do Telegram forem suficientes para você, então [use o plugin Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

A essência:
Temos um ferro muito lento e pouca memória. Portanto, não faz sentido executar o moonraker-telegram-bot no hardware.
Mas podemos executá-lo em um servidor externo.
Para isso, precisamos de qualquer servidor (real/virtual) que possa ser acessado pela impressora via SSH.

A nova versão cria automaticamente chaves SSH (elas são usadas para autorização sem senhas).

As chaves podem ser encontradas aqui:

- `/mod_data/ssh.pub.txt` - essa é uma chave pública. O texto dela deve ser colocado no servidor no arquivo `~/.ssh/authorised_keys`
- `/mod_data/ssh.key` é a chave privada. Ela é usada pela impressora para se conectar ao servidor.

Na verdade, você não precisa das chaves em si.
Você só precisa chamar a macro [ZSSH_ON](/pt/Zmod/#zssh_on) passando os seguintes parâmetros:

- SSH_SERVER - ip ou nome do seu servidor
- SSH_PORT - porta ssh no servidor - geralmente 22
- SSH_USER - nome de usuário no servidor ssh
- VIDEO_PORT - porta que será usada no servidor para receber dados de vídeo da câmera (8080)
- MOON_PORT - porta que será usada no servidor para receber dados do moonraker (7125).
- REMOTE_RUN - comando a ser chamado no servidor remoto

A execução do ssh consome cerca de 300 kilobytes de memória.

**Se a impressora e o servidor estiverem na mesma rede, não será necessário usar o SSH. Leia o arquivo de configuração [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf)** [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config).
O arquivo de configuração pode ser baixado da impressora `mod/telegram/`.

---

### Registre o bot

Como registrar seu bot

1. vá para [@BotFather](https://t.me/BotFather).
2. `/newbot`.
3. Digite o nome que desejar
4. Digite o nome do bot ff5msuper_bot - não se esqueça de colocar _bot no final.
5. Obtenha um ID longo - ele precisará ser escrito nas configurações do bot no parâmetro bot_token

---

### Implementação do servidor

#### Instale o bot do Telegram com um único comando no Debian

Se você só precisa de notificações do Telegram, então [use o plugin Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md).

Instale o bot do Telegram [com um comando](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.sh) no Debian:

Execute com o usuário `root
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Se você não tiver o wget
```
apt update && apt install wget -y
```

Este script:

1. Instalar o docker
2. Faça o download de [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) e [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf). [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Crie o usuário tbot
4. Escreverá instruções para registrar o bot do telegram e solicitar o `bot_token`.
5. Escreverá instruções para obter o `chat_id` e solicitará o `chat_id`.
6. Instalará o [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh)

Você precisará adicionar a chave ssh por conta própria

---

#### Instalação do bot do Telegram por etapas

Se você só precisa de notificações no Telegram - então [use o plugin Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Pegue o arquivo [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) de `mod/telegram/` c printer.

Instale o docker e siga as instruções para o Debian
```
apt update
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

Crie um diretório para o bot.
```
mkdir bot1
cd bot1
```

Coloque [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) lá.

Crie subdiretórios
```
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

Coloque o [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) de [mod/telegram/](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) no diretório config e modifique-o de acordo com suas necessidades.

[Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Você pode ler mais informações sobre a configuração do bot [aqui](https://github.com/nlef/moonraker-telegram-bot/wiki)

No diretório bot1, execute
```
docker-compose up -d
```

Adicione um usuário e dê a ele o direito de executar o docker-compose por conta própria.
```
useradd tbot
usermod -a -G docker tbot
```

---

#### Adicionando chaves ssh

1. Faça login como usuário `tbot`.
   ```bash
   su - tbot
   ```

2. Escreva as chaves ssh:
   ```bash
   mkdir .ssh
   cat >.ssh/authorised_keys
   ```

   Digite a chave pública do arquivo ```mod_data/ssh.pub.txt```. Em seguida, ```Ctrl + d```

---

#### Execute o ZSSH na impressora
Em seguida, execute [ZSSH_ON](/pt/Zmod/#zssh_on) na impressora com os parâmetros necessários.

Depois de cada reinicialização, o ssh será iniciado automaticamente após 3 minutos.

#### TimeZone

Edite o arquivo [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Especifique seu fuso horário. O arquivo de exemplo especifica ```TZ=Asia/Yekaterinburg```.

``` ```docker-compose down && docker-compose up -d```` ou ````docker compose down && docker compose up -d````

#### Spoolman

Edite o arquivo [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Adicione:
```
  spoolman:
    imagem: ghcr.io/donkie/spoolman:latest
    restart: unless-stopped
    volumes:
      - ./spoolman:/home/app/.local/share/spoolman
    portas:
      - "7912:8000"
    ambiente:
      - TZ=Asia/Yekaterinburg

```

Abra a porta em seu firewall, se estiver usando-o.
````iptables -I INPUT -p tcp --dport 7912 -j ACCEPT```

Crie uma pasta `spoolman`.
```
mkdir spoolman
chmod 777 spoolman
```

Reinicie o docker:
``````docker-compose down && docker-compose up -d```` ou ````docker compose down && docker compose up -d````

Na impressora, escreva em ```mod_data/user.moonraker.conf```

`external_IP` - o IP externo do servidor no qual o docker está sendo executado

A impressora DEVE ter acesso a esse IP

```
[spoolman]
servidor: http://external_IP:7912
sync_rate: 5
```

---

#### Instalação e configuração para armbian (por noyhay)

Se apenas as notificações do Telegram forem suficientes para você, então [use o plugin Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Faça o download das imagens do Debian Minimal/IOT com o Armbian em [https://www.armbian.com/download/](https://www.armbian.com/download/)

Instale o Armbian no sdcard usando o balenaEtcher em [https://etcher.balena.io/](https://etcher.balena.io/).

Inicie o sistema, crie uma senha de root e um novo usuário

De agora em diante, faremos tudo com o usuário root
```
su - root
```

Configure o wi-fi, caso não o tenha configurado após criar um novo usuário
```
sudo armbian-config
```

Atualizar o sistema
```
sudo apt update && sudo apt upgrade -y
```

Instalar o módulo de segurança do kernel do Linux apparmor
```
sudo apt install -y apparmor apparmor-utils
```

Instalar o bot do telegrama
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Adicionar chaves ssh:
Fazer login do usuário root para o usuário tbot
```
su - tbot
```

Gravar chaves ssh:
```
mkdir -p .ssh
cat >.ssh/authorised_keys
```
Digite a chave pública do arquivo na raiz do sistema mod_data/ssh.pub.txt. Em seguida, pressione CTRL+D

Reinicialize o sistema
``````sudo reboot```

---

#### Instalação do bot do telegrama via helm no kubernetes (de aldiserg)

Se apenas as notificações do Telegram forem suficientes para você, então [use o plugin Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Faça o download do helm e instale-o em seu computador [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Clone o repositório com o gráfico do helm
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```
Modificar:

1. persistence.enabled altere para false se você não planeja armazenar timelapses por um longo período

2. persistence.volumes...storageClass se for usar um armazenamento externo para timelapses

2. configMapAsFile.data.telegram.conf - nossa configuração principal, aqui precisamos alterar os campos:
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [câmera]
   host: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Como obter bot_token e chat_id, veja [aqui](/pt/Telegram/#register-bot)

Instalação:

Os comandos devem ser executados no diretório em que o gráfico está localizado
```
helm upgrade --install zmod_ff5m_tg_bot ./ -n default -f values.yaml
```
---

#### Solução de um problema ao conectar a impressora ao servidor via SSH

Após reinstalar o sistema operacional no servidor, as **chaves de host SSH** são alteradas e a impressora se recusa a se conectar com um erro:
```
ssh-ed25519 host key mismatch ...
```

##### Solução

###### 1. Limpar as chaves salvas na impressora

Conecte-se à impressora via SSH:

``` bash
ssh root@<<IP_printer> -p 22
```

Senha padrão:
```
    root
```

Em seguida, execute os comandos:

``` bash
cd ~/.ssh
rm -f know
```

Isso removerá as antigas chaves de host salvas do servidor.

------------------------------------------------------------------------

###### 2. Crie novamente o par de chaves SSH na impressora (se necessário)

Se quiser gerar um novo par de chaves, você deverá excluir os arquivos antigos:

``` bash
cd ~/mod_data
rm -f ssh.pub.txt ssh.key
```

Após a reinicialização, o serviço criará automaticamente novas chaves.

A chave pública (`ssh.pub.txt`) precisará ser adicionada novamente ao servidor em um arquivo:
```
    ~/.ssh/authorised_keys
```
para o usuário por meio do qual a conexão funciona (por exemplo, `tbot`).

------------------------------------------------------------------------

###### 3. Verificação da conexão

Depois de limpar as chaves na impressora e atualizar as `authorised_keys` no servidor
servidor --- execute a macro ZSSH na impressora.
A conexão deverá ser estabelecida sem erros.
