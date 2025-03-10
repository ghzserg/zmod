### Версия 1.3.0
- Поддержка [GuppyScreen](https://github.com/ghzserg/zmod/wiki/Macros#display_off)
- Klipper 12, [в тестовом режиме](https://github.com/ghzserg/zmod/wiki/Macros#update_mcu) (по умолчанию отключен). В нем не работает: нагрев экструдера, температура экструдера, весы.
- Заменен SSH клиент и SSH сервер `dropbear` на актуальную версию.
- Заменен `mjpg_streamer` на версию с патчем Александра, снижает потребление памяти в 2-4 раза.
- Исправлено исключение объектов от Igor Polunovskiy (теперь учитываются поддержки).
- Построение графиков шейперов с учетом SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](https://github.com/ghzserg/zmod/wiki/Macros#fix_scv).
- [CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/Macros#check_system) - Добавлена проверка прав на файлы и каталоги, проверка ссылок и восстановление.
- Удален макрос SOFT_REMOVE.
- Обновлен Moonraker, Fluidd, Mainsail

### Версия 1.1.2
- Новый макрос [CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/Macros#check_system) - Проверить операционную систему принтера на предмет повреждений файлов.
- Новый макрос [NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Macros#nozzle_control) - Аварийное отключение принтера если зафиксирован отрыв детали или удар сопла о стол.
- Новый макрос [UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/Macros#update_mcu) - Обновить MCU в принтере.
- Новый глобальный флаг [NICE](https://github.com/ghzserg/zmod/wiki/Macros#nice) - Установить приоритет процесса Klipper, 1 - минимальный приоритет, 40 - максимальный (20).
- Новый глобальный флаг [FIX_E0011](https://github.com/ghzserg/zmod/wiki/Macros#fix_e0011) - Исправить ошибку E0011, а также `Communication timeout during homing`
- Очистка файловой системы принтера от удаленных файлов, ускоряет работу EMMC.
- Куча мелких фиксов
