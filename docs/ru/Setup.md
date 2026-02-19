### [Установка](#установка-мода)

## Возврат принтера к заводским установкам (необходимо для установки мода)

0. [Удалить KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/blob/master/docs/UNINSTALL.md), если он был установлен
1. Сбросить принтер до настроек по умолчанию
2. Отформатировать USB Flash в FAT/FAT16/FAT32
3. Поместить файл из [Native firmware](/ru/Native_FW/) в корневую папку USB Flash

    - [Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz) для FF5m 
    - [Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz) для FF5m**Pro** версии 
    - [AD5X-1.1.7-1.1.0-3.0.6-20250912.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.7-1.1.0-3.0.6-20250912-Factory.tgz.gz) для AD5X

4. Выключить принтер
5. Вставить флешку в принтер
6. Включить принтер
7. Дождаться установки родной прошивки
8. Настроить WiFi или Lan *новый бобер*
9. Провести первоначальные калибровки
10. Получить последние обновления для принтера или установить прошивку 1.1.7 для AD5X, или 3.2.3 для [AD5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.3-2.2.3-20251016-Factory.tgz)/[AD5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.3-2.2.3-20251017-Factory.tgz) если вы не хотите чтобы принтер [измерял стол перед каждой печатью](https://wiki.zmod.link/ru/FAQ/#перед-каждой-печатью-измеряет-стол-по-центру)

---

## Установка мода

[Video](https://www.youtube.com/watch?v=2sfb2OtY7wM)

1. **[Вернуть принтер к заводским настройкам](/ru/Setup/#возврат-принтера-к-заводским-установкам-необходимо-для-установки-мода)** [Внимание AD5X](/ru/Setup/#внимание-ad5x)
2. Отформатировать USB Flash в FAT/FAT16/FAT32
3. Поместить [файл](https://github.com/ghzserg/zmod/releases/) в корневую папку USB Flash.

    - для FF5M: Adventurer5M-**zmod**-\*.tgz
       - для FF5MPro: Adventurer5MPro-**zmod**-\*.tgz
       - для [AD5X](/ru/AD5X/): AD5X-**zmod**-\*.tgz

4. Выключить принтер
5. Вставить флешку в принтер
6. Включить принтер
7. Дождаться установки мода

   <img width="800" height="480" alt="install" src="https://github.com/user-attachments/assets/9d6b9ad7-e9ec-4bc2-bd8f-54c945b5add5" />
   
   <img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/19d66329-72f9-4e92-aba6-35b7820ce9a0" />
   
   На AD5X установка может занимать до 40 минут

8. Вытащить флешку
9. Выключить принтер
10. Включить принтер
11. **Открыть в браузере ip принтера**
    <img width="800" height="480" alt="main" src="https://github.com/user-attachments/assets/a0466fa8-03e8-458d-8cc5-c1efb8f565ac" />
    <img width="800" height="480" alt="ip" src="https://github.com/user-attachments/assets/1d7dd5fa-86f4-4b1a-bd42-364619b20229" />
    
    Если веб интерфейс не открывается, значит родная прошивка деактивировала мод. Чтобы его включить нужно записать на USB флэш файл [AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-ENABLE-zmod.tgz) и [активировать мод](/ru/R//#ad5x-enable-zmodtgz).
     
12. Переведите мод на ваш язык.
    
    <img width="564" height="583" alt="{8E14F84D-E8D1-4129-B192-AA335243A3D9}" src="https://github.com/user-attachments/assets/e6dd3f8a-3cc3-4a05-b5fb-ad8ba372ede6" />
    
    Или в консоли наберите ```LANG LANG=ru```
    
    <img width="881" height="502" alt="image" src="https://github.com/user-attachments/assets/cf3f797d-80e0-4864-85b4-cd28886590f4" />

13. Настройте мод
    
    <img width="558" height="219" alt="{B34D2AF2-F2A6-433D-B9F8-86A83389D5A7}" src="https://github.com/user-attachments/assets/a79ec692-a284-4cb8-a0ad-3be10f33d813" />
    
    Тут отображаются параметры, которые используются при старте, окончании печтати и глобальные праметры. Рекомендуется просто прочитать настройки, но не менять их. Значение каждой настройки можно [посмотреть тут](/ru/Global/)

    <img width="561" height="443" alt="{623507C1-D3AB-4FEF-9A92-E949A85DCB49}" src="https://github.com/user-attachments/assets/3a8028bf-b078-4edc-827b-07e9d49c52f9" />

    Нужно дойти до последнгего экрана и нажать `Ok` или `Reboot`. Если этого не сделать, то это окно будет появляться при каждой загрузке

    <img width="564" height="228" alt="{BCEBDCCC-0703-46F3-8B7B-3BC58E78F27A}" src="https://github.com/user-attachments/assets/72d386a4-18ba-40a9-8f85-a6109a4e4c57" />

    Если хотите  снова увидеть это окно - то наберите к консоли `GLOBAL`

14. Перейдите в `Настройки` -> `Обновления ПО` 
15. Нажмите `Проверить обновления`, подождите пока обновления проверятся
16. Нажать **Обновление** и обновить все компоненты.
    <img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

    Если показывает много ошибок, то это нормально. Плагины не входят в состав прошивки и скачиваются отдельно. Нужно нажать `Проверить обновления`.
    И по одному восстановить и обновить все модули. Принтер при этом будет перезагружаться.
    
    <img width="671" height="844" alt="image" src="https://github.com/user-attachments/assets/d6fe3ad0-64be-4c07-8f5e-53647a6bd6ee" />

17. Активируйте [плагин с рекомендациями](https://github.com/ghzserg/recommend/blob/main/Readme_ru.md)
    
    <img width="560" height="224" alt="{E27E192D-3FC2-49AC-BEAF-F7B574FFEF45}" src="https://github.com/user-attachments/assets/dade8a2e-fc67-4df5-aad4-85cc5cd81d66" />

    Или введите в консоли ```ENABLE_PLUGIN name=recommend```

    <img width="864" height="87" alt="image" src="https://github.com/user-attachments/assets/ca96c67f-cc58-4655-8fdf-9554d1a489a3" />

18. [Настройте  Orca](/ru/Recomendations/#отправляйте-файлы-на--печать-через-octoklipper)  
    Весь стартовый код нужно заменить на этот:

    ```
    START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
    M190 S[bed_temperature_initial_layer_single]
    M104 S[nozzle_temperature_initial_layer]
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    ```START_PRINT EXTRUDER_TEMP= BED_TEMP=``` **должно писаться в одну строку**

    Конечный код на этот:

    ```END_PRINT```

    <img width="612" height="443" alt="image" src="https://github.com/user-attachments/assets/0dfd8840-c183-4d33-92aa-46f882b8c32c" />

    Код перед сменой слоя на этот:

    ```SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}```

    <img width="449" height="153" alt="image" src="https://github.com/user-attachments/assets/705fb49e-2c6b-451b-9b99-9d8d1f0e80f8" />

    Необходимо переключиться на протокол "Octo/Klipper":

      - Протокол: `Octo/Klipper`
          - Имя хоста: `IP_принтера:7125`
          - Url-адрес хоста: `IP_принтера` или `IP_принтера:80`

    <img width="673" height="467" alt="image" src="https://github.com/user-attachments/assets/70d5da64-0604-44e5-9102-887b758b5cf0" />
    <img width="473" height="395" alt="image" src="https://github.com/user-attachments/assets/ca4c5330-dc88-4372-a3c8-51527ae76146" />

19. [Включите контроль MD5](/ru/Recomendations/#включите-контроль-md5)

    <img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

20. [Прочитайте рекомендации](/ru/Recomendations/)
21. [Прочитайте FAQ](/ru/FAQ/)

### Внимание AD5X

[@Khamai](https://t.me/Khamai)

После установки Native Firmware, возможна некорректная парковка печатающей головы к приемнику филамента (недожим шторки приемника, выдавливание филамента на стол и т.п.).

[Через инженерное меню на родной прошивке](/ru/AD5X/#настройка-корзины-на-родной-прошивке-ad5x)

Если вы столкнулись с данной ситуацией, необходимо откалибровать парковку по следующему алгоритму:

1. Скачать архив [Set.XY.Offset.zip](https://github.com/ghzserg/FF/releases/download/R/Set.XY.Offset.zip) и распаковать его в корень флешки
2. Вставить флешку в выключенный принтер и включить его.
3. На экране принтера появится интерфейс для калибровки. Необходимо нажать Reset.
4. Стрелками управления припарковать печатающую голову к приемнику таким образом, чтобы печатающая голова достаточно прижимала рычажок шторки, сопло было за подвижной шторкой, а сама шторка была заподлицо с передней поверхностью приемника.
5. Зафиксировать результат калибровки кнопкой Set.
6. Вынуть флешку и перезагрузить принтер.

---

## Обновление мода

Если мод пишет `Обновите ZMOD с флешки`, то нужно обновить zMod с флешки, даже если вы его недавно обновляли.

**При обновлении с флешки все данные сохраняются.**

**Проще всего обновить мод через флешку макросом [ZFLASH](/ru/Zmod/#zflash)**

В этом случае, вам нужно вставить флешку в принтер, перезагрузить принтер и вызвать макрос `ZFLASH`.

- Макрос посмотрит последнюю актуальную версию
- Скачает последний релиз для вашей модели принтера
- Проверит контрольные суммы
- Перезагрузит принтер
- Новая версия установится автоматически после перезагрузки (флешку вытаскивать нет необходимости, ее можно оставить в принтере для следующих обновлений)
- Далее переходите во Fluidd/Mainsail на вкладку `Настройки` -> `Обновление ПО`. Нажмите `Проверить обновления` и установите последние обновления `ZMOD`

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

Если показывает много ошибок, то это нормально.

Так как плагины не входят в состав прошивки и скачиваются отдельно.

Нужно нажать `Проверить обновления`. И по одному восстановить и обновить модули. Принтер при этом будет перезагружаться.

<img width="671" height="223" alt="image" src="https://github.com/user-attachments/assets/5744dc8e-ba58-4359-b78a-652be846ca07" />

Посмотреть текущую версию операционной системы мода можно на вкладке "Система" -> "Дистрибутив"

Текущая версия zMod (вкладка "Настройки" -> "Обновление" -> "ffm5/zmod"), **должна совпадать** первыми двумя цифрами с версией со вкладки система.

<u>Если не совпадает, то мод **будет работать некорректно**, в этом случае не надо жаловаться на ZMOD</u>

Обновление через флешку:

1. Отформатировать USB Flash в FAT/FAT16/FAT32
2. Поместить [файл](https://github.com/ghzserg/zmod/releases/) в корневую папку USB Flash.

    - для FF5M: Adventurer5M-**zmod**-\*.tgz
       - для FF5MPro: Adventurer5MPro-**zmod**-\*.tgz
       - для [AD5X](/ru/AD5X/): AD5X-**zmod**-\*.tgz

3. Выключить принтер
4. Вставить флешку в принтер
5. Включить принтер
6. Дождаться перезагрузки принтера (вытаскивать флешку не надо)
7. Дождаться установки мода
8. Когда принтер напишет что установка прошла
9. Вытащить флешку
10. Выключить принтер
11. Включить принтер
12. Переходите во Fluidd/Mainsail на вкладку `Настройки` -> `Обновление ПО`. Нажмите `Проверить обновления` и установите последние обновления `ZMOD`

---

## Помочь разработке

[СБП, Банковская карта, T-pay](https://pay.cloudtips.ru/p/3cbf9e9f)

<img width="262" height="262" alt="qrCode" src="https://github.com/user-attachments/assets/e7c1ebf3-3a54-4b46-b071-06656ac06ae1" />

BTC `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`

---

## Удаление - временное отключение мода

- [SKIP_ZMOD](/ru/Zmod/#skip_zmod) - макрос перезагрузки без запуска moonraker и fluidd
- [REMOVE_ZMOD](/ru/Zmod/#remove_zmod) - макрос удаления мода

Рекомендуется **удалять мод через макрос `REMOVE_ZMOD`**, удаление через флешку использовать, только если нет возможности запустить макрос.

Внимание!

- Если у вас используется Klipper 13, то надо выполнить ```UPDATE_MCU```. Это позволит избежать ситуации, когда MCU и Klipper разных версий.
- Если у вас включены плагины, то сначала нужно их отключить ```DISABLE_PLUGIN name=g28_tenz```

Полностью удалить мод ```REMOVE_ZMOD FULL=1```

Удаление мода  через флешку:

- Отформатируйте флешку в FAT/FAT16/FAT32
- Поместите файл [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/rem_zmod/flashforge_init.sh) на эту флешку
- Выключите принтер
- Вставьте флешку в принтер
- Включите принтер
- Принтер 3 раза перезагрузится
- Извлеките флешку и пользуйтесь стоковой прошивкой

---

## Как обновлять сток?

1. Отключиьте все активные плагины кроме recommend, timelamse, notify (```DISABLE_PLUGIN name=имя_плагина```)
2. Если у вас используется **Klipper 13**, то перед обновлением родной прошивки надо выполнить ```UPDATE_MCU```. Это позволит избежать ситуации, когда MCU и Klipper разных версий.
3. Включите китайские облака, если хотите обновиться с родного экрана ```SAVE_ZMOD_DATA CHINA_CLOUD=1```

Если родной экран не находит обновления:

- Ваш серийный номер еще не попал под раздачу обновлений
- [Установите обновление родной прошивки с флешки](/ru/Native_FW/)

**Для [AD5X](/ru/AD5X/) требуется [активация zMod](/ru/Native_FW/) через `AD5X-ENABLE-zmod.tgz` с флешки, после обновления стока**.

---

## Восстановление загрузки

Авторы инструкции: [@darksimpson](https://t.me/darksimpson), [Александр](https://github.com/DrA1ex), [@Ikaros413](https://t.me/Ikaros413), [@SoloMen88](https://t.me/SoloMen88)

Для тех у кого принтер при включении повисает на заставке и не доступен по ЛАН кабелю.

![resized-image](https://github.com/user-attachments/assets/f63b16e6-2425-41c8-a166-226fb041f5ad)

![](../images/ff.jpg)

Попробуйте восстановить прошивку, через установку полной прошивки:

- [FF5M](/ru/Native_FW/#установка-полной-прошивки-на-ff5m)
- [AD5X](/ru/Native_FW/#установка-полной-прошивки-на-ad5x)

Алгоритм восстановления:

1. **Обесточить принтер**
2. Подготовить преобразователь UART/USB (Нужен на 3.3V, или с джампером 5V/3.3V)

![](../images/ch340.jpg)

**ВНИМАНИЕ!** конвертор должен быть на 3.3 ВОЛЬТА, подадите 5 вольт и процессор сгорит! 

3. Открыть заднюю стенку FlashForge
4. Подключиться к выводу UART на плате (подключаем RX, TX, GND, **3.3V не подключать**)

![](../images/connect.jpg)

ОБЯЗАТЕЛЬНО, ПЕРЕКИДЫВАЕМ ДЖАМПЕР (если у вас есть) С 5V на 3.3V  Если подадите на 5V, то попадете на замену материнской платы.
Как должно выглядеть подключение в конечном итоге:

- RX/TX подключаются крест накрест RX-TX TX-RX
- GND преобразователя к GND на плате
- 3.3V никуда не подключается

![](../images/connect_photo.jpg)

5. В системе должен появиться новый СОМ-порт.

![](../images/port.jpg)

6. Запускаем программу [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html), там вписываем ваш СОМ-порт(в примере  выше COM6), скорость `115200`, тип подключения - `Serial`.

7. Подаем штатное питание на принтер.

8. В терминале нужно дождаться строки:
```
Hit any key to stop autoboot
```
затем  быстро нажать `Enter`.

9. После этого вы окажетесь в `U-Boot`. Из него самого можно многое сделать (пишите `help`)

Но нам достаточно переопределить стартовую команду для ядра линукса, чтобы получить шелл.

Пишем в U-boot через терминал:

```
setenv init /bin/sh
boot
```

10. Если все сделали правильно, то получите `sh` после загрузки ядра Linux.

11. Файловая система смонтирована в режиме только для чтения, так что нужно будет её перемонтировать:

```
mount -t proc proc /proc
mount -o remount,rw /
```

12. Исправляем то что сломалось, например `rm -f /etc/init.d/S01bad_script`, или `rm -f /opt/config/mod/.shell/S98camera`, если у вас не проходит запуск из-за камеры.

13. Нужно сохранить изменения: ```sync```

14. И перезагрузиться: ```reboot```

