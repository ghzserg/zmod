<h1 align="center">Telegram Bot</h1>

| Функция / Возможность | [Плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md) | [Moonraker Telegram Bot](/ru/Telegram/) |
| :--- | :---: | :---: |
| **Требует внешний сервер** | – | + |
| **Удалённое управление принтером** | – (можно через [zmod.link](https://zmod.link/link/)) | + |
| **Создание таймлапса** | – (можно через [timelapse](https://github.com/ghzserg/timelapse/blob/main/Readme_ru.md)) | + |
| **Информация о событиях печати** (старт, пауза, отмена, окончание) | + | + |
| **Информация от датчика филамента** | + | + |
| **Информация о прогрессе печати в процентах** | + | + |
| **Работа с несколькими принтерами через одного бота** | + | – |
| **Информировиние через другие сервисы** | + | - |
| **Splooman** | - | + |

---

Если вам достаточно только уведомлений в Telegram - то [используйте плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

## Telegram Bot

### Описание

Если вам достаточно только уведомлений в Telegram - то [используйте плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Суть:
У нас очень медленное  железо и очень мало памяти. Поэтому на железе запускать moonraker-telegram-bot нет смысла. 
Но мы его можем запустить на внешнем сервере.
Для этого нужен любой  сервер (реальный/виртуальный), до которого сможет достучаться принтер по SSH.

Новая версия автоматом создает SSH ключи (они используются для авторизации без паролей).

Ключи лежат тут:

- `‎/mod_data/ssh.pub.txt` - это открытый ключ. Текст из него необходимо поместить на сервере в файл `~/.ssh/authorized_keys`
- `‎/mod_data/ssh.key` - закрытый ключ. Используется принтером для подключения к серверу.

Сами ключи вам по сути не нужны.
Вам достаточно вызвать макрос [ZSSH_ON](/ru/Zmod/#zssh_on) передав следующие параметры:

- SSH_SERVER - ip или имя вашего сервера
- SSH_PORT - порт ssh на сервере - обычно 22
- SSH_USER - имя  пользователя на ssh сервере
- VIDEO_PORT - порт который будет использоваться на сервере для приема видеоданных с камеры (8080)
- MOON_PORT - порт который будет использоваться на сервере для приема данных от moonraker (7125).
- REMOTE_RUN - команда, которую нужно вызывать на удаленном сервере

Запуск ssh съедает около 300 килобайт памяти.

**Если принтер и сервер находятся в одной сети, то использовать SSH не обязательно. Читайте файл конфигурации [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf)** [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
Файл конфигурации можно скачать с принтера `mod/telegram/`.

---

### Регистрация бота

Как зарегистрировать свой бот

1. Идете к [@BotFather](https://t.me/BotFather)
2. `/newbot`
3. Вводите любое имя, которое  вам нравится
4. Вводите имя бота  ff5msuper_bot - обязательно _bot  в конце. 
5. Получаете  длинный ID - его нужно будет прописать в настройках бота в параметр bot_token

---

### Развертывание сервера

#### Установка телеграмм бота одной командой на Debian

Если вам достаточно только уведомлений в Telegram - то [используйте плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Установка телеграмм бота [одной командой](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.sh) на Debian:

Выполнять под пользователем `root`
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Если у вас нет wget
```
apt update && apt install wget -y
```

Этот скрипт:

1. Установит docker
2. Скачает [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) и [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf). [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Создаст пользователя tbot
4. Напишет инструкцию по регистрации телеграмм бота и запросит `bot_token`
5. Напишет инструкцию по получению `chat_id` и запросит `chat_id`
6. Установит [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh)

Добавить ssh ключ нужно будет самостоятельно

---

#### Установка телеграмм бота по шагам

Если вам достаточно только уведомлений в Telegram - то [используйте плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Берете файл [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) из `mod/telegram/` c принтера.

Устанавливаете docker, далее инструкция для Debian
```
apt update 
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

Создаете  каталог для бота.
```
mkdir bot1
cd bot1
```

Помещаете  туда  [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Создаете подкаталоги
```
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

В каталог config помещаете [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) из [mod/telegram/](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) и правите его под себя.

[Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Больше информации о настройке бота можно почитать [тут](https://github.com/nlef/moonraker-telegram-bot/wiki)

Из каталога bot1 запускаете
```
docker-compose up -d
```

Добавляете пользователя и даем ему право самому запускать docker-compose
```
useradd tbot
usermod -a -G docker tbot
```

---

#### Добавление ssh ключей

1. Заходим под пользователем `tbot`
   ```bash
   su - tbot
   ```

2. Прописываем ssh ключи:
   ```bash
   mkdir  .ssh
   cat >.ssh/authorized_keys
   ```

   Вводите открытый ключ из файла `mod_data/ssh.pub.txt`. Потом  `Ctrl + d` 

---

#### Запуск ZSSH на принтере
После этого запускаете на принтере [ZSSH_ON](/ru/Zmod/#zssh_on) c необходимыми параметрами.

После  каждой перезагрузки ssh, будет запускаться автоматически через 3 минуты.

#### TimeZone

Отредактируйте файл [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Укажите  вашу временную зону. В примере файла указана ```TZ=Asia/Yekaterinburg```

```docker-compose down && docker-compose up -d``` или ```docker compose down && docker compose up -d```

#### Spoolman

Отредактируйте файл [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Добавьте:
```
  spoolman:
    image: ghcr.io/donkie/spoolman:latest
    restart: unless-stopped
    volumes:
      - ./spoolman:/home/app/.local/share/spoolman
    ports:
      - "7912:8000"
    environment:
      - TZ=Asia/Yekaterinburg

```

Откройте порт в фаерволе если он у вас используется
```iptables -I INPUT -p tcp --dport 7912 -j ACCEPT```

Создайте папку `spoolman`
```
mkdir spoolman
chmod 777 spoolman
```

Перезапустите docker:
```docker-compose down && docker-compose up -d``` или ```docker compose down && docker compose up -d```

На принтере пропишите в `mod_data/user.moonraker.conf`

`external_IP` - внешний ИП сервера на котором стоит docker

У принтера ДОЛЖЕН быть доступ к этому IP

```
[spoolman]
server: http://external_IP:7912
sync_rate: 5
```

---

#### Установка и настройка для armbian (от noyhay)

Если вам достаточно только уведомлений в Telegram - то [используйте плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Скачиваем Debian Minimal/IOT images with Armbian с сайта [https://www.armbian.com/download/](https://www.armbian.com/download/)

Устанавливаем Armbian на sdcard с помощью balenaEtcher с сайта [https://etcher.balena.io/](https://etcher.balena.io/)

Запускаем систему, создаем пароль root и нового пользователя

В дальнейшем все делаем под пользователем root
```
su - root
```

Настраиваем wi-fi, если не настроили после создания нового пользователя
```
sudo armbian-config
```

Обновляем систему
```
sudo apt update && sudo apt upgrade -y
```

Устанавливаем apparmor модуль безопасности ядра Linux
```
sudo apt install -y apparmor apparmor-utils
```

Устанавливаем бот telegram
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Добавление ssh ключей:
Заходим из под пользователя root в пользователя tbot
```
su - tbot
```

Прописываем ssh ключи:
```
mkdir -p .ssh
cat >.ssh/authorized_keys
```
Вводите открытый ключ из файла в системе корневой системе mod_data/ssh.pub.txt. Потом CTRL+D

Перезагружаем систему
```sudo reboot```

---

#### Установка бота телеграмм через helm в kubernetes (от aldiserg)

Если вам достаточно только уведомлений в Telegram - то [используйте плагин Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Скачиваем helm и устанавливаем на компьютер [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Клонируем репозиторий с helm чартом
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```
Изменяем:

1. persistence.enabled меняем на false если не планируется долговременно хранить таймлапсы

2. persistence.volumes...storageClass если будем использовать внешний сторадж для таймлапсов

2. configMapAsFile.data.telegram.conf - основной наш конфиг, тут нужно поменять поля:
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [camera]
   host: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Как получить bot_token и chat_id смотри [тут](/ru/Telegram/#регистрация-бота)

Установка:

Команды должны выполняться из директории в которой находится чарт
```
helm upgrade --install zmod_ff5m_tg_bot ./ -n default -f values.yaml
```
---

#### Решение проблемы с подключением принтера к серверу через SSH

После переустановки ОС на сервере меняются **SSH host-ключи**, и принтер отказывается подключаться с ошибкой:
```
ssh-ed25519 host key mismatch ...
```

##### Решение

###### 1. Очистка сохранённых ключей на принтере

Подключитесь к принтеру по SSH:

``` bash
ssh root@<IP_принтера> -p 22
```

Пароль по умолчанию:
```
    root
```

Далее выполните команды:

``` bash
cd ~/.ssh
rm -f know*
```

Это удалит старые сохранённые host-ключи сервера.

------------------------------------------------------------------------

###### 2. Пересоздание пары SSH-ключей на принтере (при необходимости)

Если требуется сгенерировать новую пару ключей, нужно удалить старые файлы:

``` bash
cd ~/mod_data
rm -f ssh.pub.txt ssh.key
```

После перезапуска сервис автоматически создаст новые ключи.

Публичный ключ (`ssh.pub.txt`) нужно будет снова добавить на сервер в файл:
```
    ~/.ssh/authorized_keys
```
для пользователя, через которого работает подключение (например, `tbot`).

------------------------------------------------------------------------

###### 3. Проверка подключения

После очистки ключей на принтере и обновления `authorized_keys` на
сервере --- запустите ZSSH макрос на принтере.
Теперь соединение должно устанавливаться без ошибок.
