insmod keyboard_gpio_add.ko
cd /sys/module/keyboard_gpio_add/parameters/ 
echo alloc=16 > keyboard
echo gpio="PB11" key_code=0x164 tag="KEY_POWER2" active_level=0 wakeup=  > keyboard
echo register > keyboard
