[Contents]
Índice de Contenidos:

  DESCRIPCIÓNDESCRIPTION
  OPTIONSOPTIONS
  IntroducciónOverview
  Soporte de RatónMouse Support

  TeclasKeys
    Redefinición de teclasKeys_redefine
    Otras TeclasMiscellaneous Keys
    Paneles de DirectorioDirectory Panels
    Búsqueda rápidaQuick search
    Línea de Órdenes del SistemaShell Command Line
    Teclas Generales de MovimientoGeneral Movement Keys
    Teclas de la Línea de EntradaInput Line Keys

  Barra de MenúMenu Bar
    Menús Izquierdo y Derecho (Arriba y Abajo)Left and Right Menus
      Listado...Listing Format...
      Modo de Ordenación...Sort Order...
      Filtro...Filter...
      ReleerReread
    Menú de ArchivoFile Menu
      Cambiar de directorioQuick cd
    Menú de UtilidadesCommand Menu
      Árbol de DirectoriosDirectory Tree
      Buscar ArchivosFind File
      Búsquedas ExternasExternal panelize
      FavoritosHotlist
      Editar el Archivo de ExtensionesEdit Extension File
      Trabajos en Segundo PlanoBackground jobs
      Edición del Archivo de MenúEdit Menu File
    Menú de OpcionesOptions Menu
      ConfiguraciónConfiguration
      PresentaciónLayout
      PanelesPanel options
      ConfirmaciónConfirmation
      AspectoAppearance
      Juego de caracteresDisplay bits
      Aprender teclasLearn keys
      Sistema de Archivos Virtual (VFS)Virtual FS
      Guardar ConfiguraciónSave Setup

  Ejecutando Órdenes del Sistema OperativoExecuting operating system commands
    Comando cd InternoThe cd internal command
    Sustitución de MacroMacro Substitution
    Soporte de SubshellThe subshell support
  Cambiar PermisosChmod
  Cambiar DueñoChown
  Cambiar Dueño y PermisosAdvanced Chown
  Operaciones con ArchivosFile Operations
  Copiar/Renombrar con MáscaraMask Copy/Rename
  Seleccionar/Deseleccionar ArchivosSelect/Unselect Files
  Comparador de Archivos InternoDiff Viewer
  Visor de Archivos InternoInternal File Viewer
  Editor de Archivos InternoInternal File Editor
  TerminaciónCompletion
  Sistemas de Archivos Virtuales (VFS)Virtual File System
    Sistema de archivos Tar (tarfs)Tar File System
    Sistema de archivos FTPFTP File System
    Sistema de archivos a través de SHellFIle transfer over SHell filesystem
    Sistema de archivos SFTP (FTP sobre SSH)SFTP (SSH File Transfer Protocol) filesystem
    Sistema de archivos de RecuperaciónUndelete File System
    Sistema de archivos EXTerno (extfs)EXTernal File System
  ColoresColors
  SkinsSkins
    Descripción de secciones y parámetrosSkins sections
    Definiciones de pares de coloresSkins colors
    Trazado de líneasSkins lines
    CompatibilidadSkins oldcolors
  Resaltado de nombresFilenames Highlight
  Ajustes EspecialesSpecial Settings
  Parámetros para editor o visor externoParameters for external editor or viewer
  Ajustes del TerminalTerminal databases

  ARCHIVOS AUXILIARESFILES
  DISPONIBILIDADAVAILABILITY
  VÉASE TAMBIÉNSEE ALSO
  AUTORESAUTHORS
  ERRORESBUGS
  TRADUCCIÓNTRANSLATION
  Licencia GNULicencia GNU
  Licencia GNU (Español)Licencia GNU (Español)
  Cuadros de diálogoQueryBox
  Uso de la ayudaHow to use help
[DESCRIPTION]
DESCRIPCIÓN

"Midnight Commander" (Comandante de Medianoche) es un navegador de directorios/gestor de archivos para sistemas operativos tipo Unix.[OPTIONS]

OPCIONES


-a, --stickchars
        Deshabilita el uso de caracteres gráficos para el dibujo de líneas.

-b, --nocolor
        Fuerza el uso de la pantalla de Blanco y Negro.

-c, --color
        Fuerza el uso del modo color. Véase la sección ColoresColors para más información.

-C arg, --colors=arg
        Usado para especificar un juego de colores diferentes desde la línea de órdenes. El formato de arg está documentado en la sección ColoresColors.

--configure-options
        Muestra opciones de configuración compiladas.

-d, --nomouse
        Deshabilita el soporte de ratón.

-e [arch], --edit[=arch]
        Iniciar el editor interno. Si se indica un archivo, editarlo. Véase la página de manual de mcedit (1).

-f, --datadir
        Muestra las rutas de búsqueda compiladas para archivos de Midnight Commander.

-F, --datadir-info
        Muestra información más extensa sobre las rutas de búsqueda compiladas en Midnight Commander.

-g, --oldmouse
        Fuerza el uso de ratón en modo de seguimiento «normal». Se usa para terminales compatibles con xterm (tmux/screen).

-k, --resetsoft
        Restablece las softkeys a su valor por defecto según la base de datos de termcap/terminfo. Solo útil en terminales HP cuando las teclas de función no funcionan.

-K arch, --keymap=arch
        Carga desde un archivo la configuración de teclas para la línea de órdenes.

-l reg, --ftplog=reg
        Guarda el diálogo FTPfs con el servidor en el archivo.

--nokeymap
        No cargar asociaciones de teclas desde ningún archivo, utilizar las teclas nativas del sistema.

-P arch, --printwd=arch
        Al salir del programa, Midnight Commander registrará el último directorio de trabajo en el archivo indicado. Esta opción no debe ser usada directamente, sino desde un guión de shell adecuado, para dejar como directorio activo el directorio que estaba en uso dentro de Midnight Commander. Consúltese en los archivos /opt/lib/mc/mc.sh (usuarios de bash y zsh) y /opt/lib/mc/mc.csh (usuarios de tcsh) la manera de definir mc como un alias para el correspondiente guión de shell.

-s, --slow
        Activa el modo para terminales lentos. En este modo el programa no dibuja bordes con líneas de caracteres y desactiva el modo detallado. Si no se rellena la sección [Lines] el marco pseudo-gráfico estará formado por espacios; en caso contrario el marco se contruye con caracteres de texto según los parámetros siguientes:

lefttop esquina superior izquierda

righttop
        esquina superior derecha

centertop
        cruz superior central

centerbottom
        cruz inferior central

leftbottom
        esquina inferior izquierda

rightbottom
        esquina inferior derecha

leftmiddle
        cruz central izquierda

rightmiddle
        cruz central derecha

centermiddle
        cruz central

horiz   línea horizontal por defecto

vert    línea vertical por defecto

thinhoriz
        línea horizontal fina

thinvert
        línea vertical fina

-S arg, --skin=arg
        Permite elegir un «skin» o apariencia para mc. La configuración de las características de visualización (colores, líneas, etc.) se explica detalladamente en la sección SkinsSkins.

-t, --termcap
        Usado solo si el código fue compilado con S-Lang y terminfo: hace que Midnight Commander use el valor de la variable de entorno TERMCAP para obtener la información del terminal, en vez de la base de datos de terminales del sistema.

-u, --nosubshell
        Deshabilita el uso de shell concurrente (solo tiene sentido si este Midnight Commander fue construido con soporte de shell concurrente).

-U, --subshell
        Habilita el uso de shell concurrente (solo tiene sentido si este Midnight Commander fue construido con soporte de subshell opcional).

-v arch, --view=arch
        Iniciar el visor interno para ver el archivo indicado. Véase la página de manual de mcview (1).

-V, --version
        Muestra la versión del programa.

-x, --xterm
        Fuerza el modo xterm. Usado cuando se ejecuta en terminales con características de xterm (dos modos de pantalla, y pueden enviar secuencias de escape de ratón).

-X, --no-x11
        No utilizar X11 para obtener el estado de Mayús, Ctrl, Alt.

Si se especifican los dos directorios, el primer nombre se usará para el directorio a mostrar en el panel activo; el segundo nombre para el directorio a mostrar en el otro panel.

Si solo se especifica un directorio, el nombre se usará para el directorio a mostrar en el panel activo; el valor de «other_dir» de panels.ini será el nombre del directorio mostrado en el panel pasivo.

Si no se especifica ningún directorio, el directorio actual se mostrará en el panel activo; el valor de «other_dir» de panels.ini será el nombre del directorio mostrado en el panel pasivo.[Overview]
Introducción

La pantalla de Midnight Commander está divida en cuatro partes. La mayor parte de la pantalla está ocupada por los dos paneles de directorio. Por defecto, la segunda línea más inferior de la pantalla es la línea de órdenes del sistema, y la línea inferior muestra las etiquetas de las teclas de función. La línea superior es la barra de menúMenu Bar. La línea de la barra de menú podría no ser visible, pero aparece si pulsamos en la primea línea de la pantalla con el ratón o pulsamos la tecla F9.

Midnight Commander pone a la vista dos directorios al mismo tiempo. Uno de los paneles es el panel actual (hay una barra de selección en el panel actual). La mayoría de las operaciones tienen lugar en el panel actual. Algunas operaciones con archivos como Renombrar y Copiar utilizan por defecto el directorio del panel no seleccionado como destino, pero siempre solicitan una confirmación previa y podemos cambiarlo. Para más información, ver las secciones sobre los Paneles de DirectorioDirectory Panels, los Menús Izquierdo y DerechoLeft and Right Menus y el Menú de ArchivoFile Menu.

Podemos ejecutar comandos del sistema desde el Midnight Commander simplemente escribiéndolos. Todo lo que escribamos aparecerá en la línea de órdenes del sistema y cuando pulsemos Intro, Midnight Commander ejecutará estos comandos; ver las secciones Línea de Órdenes del SistemaShell Command Line y Teclas de la Línea de EntradaInput Line Keys para aprender más sobre la línea de órdenes.[Mouse Support]
Soporte de Ratón

Se puede utilizar Midnight Commander con un ratón o mouse. Se activa cuando estamos ejecutándolo en un entorno gráfico con un terminal tipo xterm(1) (funciona incluso si realizamos una conexión de telnet, ssh o rlogin a otra máquina desde el xterm) o si estamos ejecutándolo en una consola Linux y tenemos el servidor gpm cargado.

Cuando pulsamos el botón izquierdo del ratón sobre un archivo en los paneles de directorios, ese archivo es seleccionado; si lo hacemos con el botón derecho, el archivo es marcado (o desmarcado, dependiendo del estado previo).

Una doble pulsación sobre un archivo intentará ejecutar el comando si se trata de un programa ejecutable; y si la extensión del archivo tiene un programa asociado a esa extensiónEdit Extension File, se ejecuta el programa especificado.

Además, es posible ejecutar los comandos asignados a las teclas de función pulsando con el ratón sobre las etiquetas de la línea inferior de la pantalla.

El valor por defecto de auto repetición para los botones del ratón es 400 milisegundos. Este valor se puede modificar editando el archivo ~/.config/mc/iniSave Setup y cambiando el parámetro mouse_repeat_rate.

Si estamos ejecutando Midnight Commander con soporte para ratón, podemos recuperar el comportamiento habitual del ratón (cortar y pegar texto) manteniendo pulsada la tecla Mayúsculas.

[Keys]
Teclas

Algunos comandos en Midnight Commander implican el uso de las teclas Control (etiquetada habitualmente CTRL o CTL) y Meta (identificada como ALT o incluso Compose). En este manual usaremos las siguientes abreviaturas:

Ctrl-<car>
        significa mantener pulsada la tecla Control mientras se pulsa el carácter <car>. Así, Ctrl-f sería: manteniendo pulsada la tecla Control teclear f.

Alt-<car>
        significa mantener pulsada la tecla Alt o Meta mientras pulsamos el carácter <car>. Si no hay tecla Alt ni Meta, pulsar Esc, soltar, y entonces pulsar el carácter <car>.

Mayús-<car>
        significa mantener pulsada la tecla de Mayúsculas (o Shift) y teclear <car>.

Todas las líneas de entrada en Midnight Commander usan una aproximación a las asociaciones de teclas del editor GNU Emacs.

Se pueden redefinir las asociaciones de las teclas. El resto de los comportamientos de las teclas que se describen aquí hacen referencia al comportamiento original. Para más información, véase la sección sobre R "redefinición de teclas" .Keys_redefine

Hay bastantes secciones que hablan acerca de las teclas. Las siguientes son las más importantes.

La sección Menú de ArchivoFile Menu documenta los atajos de teclado para los comandos que aparecen en el Menú de Archivo. Esta sección incluye las teclas de función. La mayor parte de esos comandos realizan alguna acción, normalmente sobre el archivo seleccionado o sobre los archivos marcados.

La sección Paneles de DirectorioDirectory Panels documenta las teclas que seleccionan un archivo o marcan archivos como objetivo de una acción posterior (la acción normalmente es una del menú de archivo).

La sección Línea de Órdenes del SistemaShell Command Line lista las teclas que son usadas para introducir o editar líneas de comandos. La mayor parte de ellas copian nombres de archivos y demás desde los paneles de directorio a la línea de órdenes (para evitar un tecleado excesivo) o acceden al historial de la línea de órdenes.

Teclas de línea de EntradaInput Line Keys Son usadas para editar líneas de entrada. Esto implica la línea de órdenes y las líneas de entrada en las ventanas de preguntas.[Keys_redefine]
Redefinición de teclas

La función de ciertas teclas se puede alterar a partir de un mapa de teclado almacenado en un archivo externo. Inicialmente el programa asigna esas funciones según el mapa definido en el código fuente. Posteriormente se cargan siempre los archivos /opt/share/mc/mc.keymap y /opt/etc/mc/mc.keymap, reasignando en el orden marcado las definiciones anteriores. Se cargan después posibles mapas de teclado creados por el usuario atendiendo por orden de prioridad a:

        1) Opción de ejecución en línea de órdenes -K <mapa> o --keymap=<mapa>
        2) Variable de entorno MC_KEYMAP
        3) Parámetro keymap en la sección [Midnight-Commander] del archivo de configuración.
        4) Archivo ~/.config/mc/mc.keymap

La opción de línea de órdenes, la variable de entorno y el parámetro en el archivo de configuración pueden proporcionar la ruta absoluta al archivo de mapa de teclado (con o sin la extensión .keymap). En caso contrario se procede a realizar una búsqueda por directorios hasta encontrarlo en:

        1) ~/.config/mc
        2) /opt/etc/mc/
        3) /opt/share/mc/[Miscellaneous Keys]
Otras Teclas

Se incluyen aquí las teclas que no encajan en ninguna categoría concreta:

Intro. Si hay algún texto en la línea de órdenes (la de la parte inferior de los paneles), entonces ese comando es ejecutado. Si no hay texto en la línea de comandos entonces si la barra de selección está situada sobre un directorio Midnight Commander realiza un chdir(2) al directorio seleccionado y recarga la información en el panel; si la selección es un archivo ejecutable entonces es ejecutado. Por último, si la extensión del archivo seleccionado coincide con una de las extensiones en el archivo de extensionesEdit Extension File entonces se ejecuta la aplicación correspondiente.

Ctrl-l  redibuja toda la pantalla de Midnight Commander.

Ctrl-x c
        Cambiar permisosChmod de un archivo o un conjunto de archivos marcados.

Ctrl-x o
        Cambiar dueñoChown del archivo actual o de los archivos marcados.

Ctrl-x l
        crea enlaces.

Ctrl-x s
        crea enlaces simbólicos con rutas absolutas.

Ctrl-x v
        crea enlaces simbólicos con rutas relativas. Para más información sobre enlaces simbólicos véase la sección Menú de ArchivoFile Menu.

Ctrl-x Ctrl-s
        edita enlaces simbólicos.

Ctrl-x i
        cambia el panel opuesto al modo de información.

Ctrl-x q
        cambia el panel opuesto al modo de vista rápida.

Ctrl-x !
        ejecuta búsquedas externasExternal panelize.

Ctrl-x h
        añade el sitio actual a la lista de favoritosHotlist.

Alt-!   ejecuta una orden del sistema y muestra su salida en el visor de archivosInternal File Viewer.

Alt-?   buscar archivosFind File.

Alt-c   permite cambiar de directorioQuick cd.

Ctrl-o  en la consola de Linux o FreeBSD o bajo un xterm, se muestra la salida de la orden anterior. En la consola de Linux, Midnight Commander usa un programa externo (cons.saver) para controlar la copia y restauración de la pantalla.

Cuando se haya creado Midnight Commander con soporte de subshell incluido, podemos pulsar Ctrl-o en cualquier momento y volver a la pantalla principal; para volver a nuestra aplicación bastará con volver a pulsar Ctrl-o. Si tenemos una aplicación suspendida en esta situación, no podremos ejecutar otros programas desde Midnight Commander hasta que terminemos la aplicación suspendida.[Directory Panels]
Paneles de Directorio

Esta sección enumera las teclas que operan en los paneles de directorio. Si queremos saber cómo cambiar la apariencia de los paneles, deberemos echar un vistazo a la sección Menús Izquierdo y DerechoLeft and Right Menus.

Tab, Ctrl-i
        cambia el panel actual. El panel activo deja de serlo y el no activo pasa a ser el nuevo panel activo. La barra de selección se mueve del antiguo panel al nuevo, desaparece de aquel y aparece en este.

Insertar, Ctrl-t
        para marcar archivos (y/o directorios) como seleccionados podemos usar la tecla insertar (secuencia kich1 de terminfo). Para deseleccionar, basta repetir la operación sobre los archivos y/o directorios antes marcados.

Alt-e   permite mostrar nombres en el panel con otra codificación de caracteres. Los nombres se convierten a la codificación del sistema para mostrarlos. Para desactivar esta recodificación basta seleccionar la entrada (..) para el directorio superior. Para cancelar las conversiones en cualquier directorio seleccionar «Sin traducción» en el diálogo de selección de código.

Alt-g, Alt-r, Alt-j
        usadas para seleccionar el archivo superior en un panel, el archivo central y el inferior del panel, respectivamente.

Alt-t   rota el listado de pantalla actual para mostrar el siguiente modo de listado. Con esto es posible intercambiar rápidamente de un listado completo al regular o breve, así como al modo de listado definido por el usuario.

Ctrl-\ (control-Contrabarra)
        muestra la lista de sitios FavoritosHotlist y permite cambiar al directorio seleccionado.


        * N. del T.: En el teclado castellano, existe un pequeño inconveniente, dado que la contrabarra, no se consigue con una sola pulsación, por lo que este método no funciona directamente.

+ (más)
        usado para seleccionar (marcar) un grupo de archivos. Midnight Commander ofrecerá distintas opciones. Indicando Solo archivos los directorios no se seleccionan. Con los Caracteres Comodín habilitados, se pueden introducir expresiones regulares del tipo empleado en los patrones de nombres de la shell (poniendo * para cero o más caracteres y ? para uno o más caracteres). Si los Caracteres Comodín están deshabilitados, entonces la selección de archivos se realiza con expresiones regulares normales. Véase la página de manual de ed (1). Finalmente, si no se activa Distinguir May/min la selección se hará sin distinguir caracteres en mayúsculas o minúsculas.

- (menos) o \ (contrabarra)
        usaremos las teclas «-» o «\» para deseleccionar un grupo de archivos. Esta es la operación opuesta a la realizada por la tecla «+».


        * N. del T.: La tecla que realiza originalmente la función descrita es la «-» (menos) ya que es la utilizada en la aplicación originaria, Comandante Norton.

Arriba, Ctrl-p
        desplaza la barra de selección a la entrada anterior en el panel.

Abajo, Ctrl-n
        desplaza la barra de selección a la entrada siguiente en el panel.

Inicio, Alt-<
        desplaza la barra de selección a la primera entrada en el panel.

Fin, Alt->
        desplaza la barra de selección a la última entrada en el panel.

AvPág (Página adelante), Ctrl-v
        desplaza la barra de selección a la página siguiente.

RePág (Página atrás), Alt-v
        desplaza la barra de selección a la página anterior.

Alt-o   si el otro panel es un panel con lista de archivos y estamos situados en un directorio en el panel activo actual, entonces otro panel se posiciona dentro del directorio del panel activo (como la tecla de Emacs Ctrl-o) en otro caso el otro panel es posicionado el directorio padre del directorio seleccionado en el panel activo.

Alt-i   cambiar el directorio en el panel opuesto de manera que coincida con el panel actual. Si es necesario se cambiará también el panel opuesto a modo listado, pero si el panel actual no está en modo listado no se cambiará de modo el otro.

Ctrl-RePág, Ctrl-AvPág
        solamente bajo la consola Linux: realiza un chdir ".." o al directorio actualmente seleccionado respectivamente.

Alt-y   cambia al anterior directorio visitado, equivale a pulsar < con el ratón.

Alt-u   cambia al siguiente directorio visitado, equivale a pulsar > con el ratón.

Alt-Mayús-h, Alt-H
        muestra el historial de directorios visitados, equivale a pulsar la v con el ratón.[Quick search]
Búsqueda rápida

El modo de Búsqueda rápida permite localizar rápidamente nombres de archivos en los paneles de directorio. Pulsando Ctrl-s o Alt-s se inicia la búsqueda de un archivo en el panel activo.

Estando activada la búsqueda, las teclas pulsadas se van añadiendo a la cadena de texto en búsqueda y no a la línea de órdenes. Si la opción Mostrar Mini-estado está habilitada, la cadena a buscar se podrá ver en la línea de estado. Conforme tecleemos, dentro del panel activo la barra de selección se desplazará al siguiente archivo o directorio cuyo nombre coincida con las letras introducidas. Se pueden usar las teclas borrar o suprimir para corregir errores de escritura. Si pulsamos Ctrl-s de nuevo, se busca la siguiente coincidencia.

Si se inicia la búsqueda rápida pulsando dos veces Ctrl-s se recuperará el último patrón de búsqueda utilizado.

Aparte de los caracteres propios de los nombres se pueden utilizar también los caracteres comodín '*' y '?'.[Shell Command Line]
Línea de Órdenes del Sistema

Esta sección enumera las teclas útiles para evitar la excesiva escritura cuando se introducen órdenes del sistema.

Alt-Intro
        copia el nombre de archivo seleccionado a la línea de órdenes.

Ctrl-Intro
        igual que Alt-Intro. Puede no funcionar en ciertos sistemas o con algunos terminales.

Ctrl-Mayús-Intro
        copia la ruta completa del archivo actual en la línea de órdenes. Puede no funcionar en ciertos sistemas o con algunos terminales.

Alt-Tab realiza una terminación automáticaCompletion del nombre de archivo, comando, variable, nombre de usuario y host.

Ctrl-x t, Ctrl-x Ctrl-t
        copia los archivos marcados (o si no los hay, el archivo seleccionado) del panel activo (Ctrl-x t) o del otro panel (Ctrl-x Ctrl-t) a la línea de órdenes.

Ctrl-x p, Ctrl-x Ctrl-p
        la primera secuencia de teclas copia el nombre de la ruta de acceso actual a la línea de órdenes, y la segunda copia la ruta del otro panel a la línea de órdenes.

Ctrl-q  el comando cita (quote) puede ser utilizado para insertar caracteres que de otro modo serían interpretados por Midnight Commander (como el símbolo '+')

Alt-p, Alt-n
        usaremos esas teclas para navegar a través del histórico de comandos. Alt-p devuelve la última entrada, Alt-n devuelve la siguiente.

Alt-h   visualiza el historial para la línea de entrada actual.[General Movement Keys]
Teclas Generales de Movimiento

El visor de ayuda, el visor de archivo y el árbol de directorios usan un código de control de movimiento común. Por consiguiente, reconocen las mismas teclas. Además, cada uno reconoce algunas otras teclas propias.

Otras partes de Midnight Commander utilizan algunas de las mismas teclas de movimiento, por lo que esta sección podría ser aplicada a ellas también.

Arriba, Ctrl-p
        mueve una línea hacia arriba.

Abajo, Ctrl-n
        mueve una línea hacia abajo.

RePág (Página atrás), Alt-v
        mueve una página completa hacia atrás.

AvPág (Página adelante), Ctrl-v
        mueve una página hacia delante.

Inicio  mueve al principio.

Fin     mueve al final.

El visor de ayuda y el de archivo reconocen las siguientes teclas aparte de las mencionadas anteriormente:

b, Ctrl-b, Ctrl-h, Borrar, Suprimir
        mueve una página completa hacia atrás.

Barra espaciadora
        mueve una página hacia delante.

u, d    mueve la mitad de la página hacia atrás o adelante.

g, G    mueve al principio o al final.[Input Line Keys]
Teclas de la Línea de Entrada

Las líneas de entrada (usadas en la línea de órdenesShell Command Line y para los cuadros de diálogo en el programa) reconocen esas teclas:

Ctrl-a  coloca el cursor al comienzo de la línea.

Ctrl-e  coloca el cursor al final de la línea.

Ctrl-b, Izquierda
        desplaza el cursor una posición a la izquierda.

Ctrl-f, Derecha
        desplaza el cursor una posición a la derecha.

Alt-f   avanza una palabra.

Alt-b   retrocede una palabra.

Ctrl-h, Borrar
        borra el carácter anterior.

Ctrl-d, Suprimir
        elimina el carácter de la posición del cursor.

Ctrl-@  sitúa una marca para cortar.

Ctrl-w  copia el texto entre el cursor y la marca a la caché de eliminación y elimina el texto de la línea de entrada.

Alt-w   copia el texto entre el cursor y la marca a la caché de eliminación.

Ctrl-y  restaura el contenido de la caché de eliminación.

Ctrl-k  elimina el texto desde el cursor hasta el final de la línea.

Alt-p, Alt-n
        usaremos esas teclas para desplazarnos a través del historial de comandos. Alt-p nos lleva a la última entrada, Alt-n nos sitúa en la siguiente.

Ctrl-Alt-h, Alt-Borrar
        borra la palabra anterior.

Alt-Tab realiza una terminaciónCompletion del nombre de archivo, comando, variable, nombre de usuario o host.

[Menu Bar]
Barra de Menú

La barra de menú aparece cuando pulsamos F9 o pulsamos el botón del ratón sobre la primera fila de la pantalla. La barra de menú tiene cinco submenús: "Izquierdo", "Archivo", "Utilidades", "Opciones" y "Derecho".

Los Menús Izquierdo y DerechoLeft and Right Menus nos permiten modificar la apariencia de los paneles de directorio izquierdo y derecho.

El Menú de ArchivoFile Menu lista las acciones que podemos realizar sobre el archivo actualmente seleccionado o sobre los archivos marcados.

El Menú de UtilidadesCommand Menu lista las acciones más generales y que no guardan relación con la selección actual de archivos.[Left and Right Menus]
Menús Izquierdo y Derecho (Arriba y Abajo)

La presentación de los paneles de directorio puede ser cambiada desde los menús Izquierdo y Derecho (denominados Arriba y Abajo si hemos elegido la disposición horizontal de paneles en las opciones de presentaciónLayout).[Listing Format...]
Listado...

La vista en modo "Listado" se usa para mostrar la lista de archivos. Hay cuatro modos disponibles: Completo, Breve, Largo, y Definido por el usuario.

En modo completo se muestra el nombre del archivo, su tamaño y la fecha y hora de modificación.

En modo breve se muestran solo los nombres de archivo usando entre 1 y 9 columnas. Esto permite ver muchas más entradas que en los otros modos.

El modo largo es similar a la salida de la orden ls -l. Este modo requiere todo el ancho de la pantalla.

Si se elige el modo definido por el usuario, hay que especificar el formato de presentación. Un formato personalizado tiene que comenzar con la indicación de tamaño de panel, que puede ser "half" (medio) o "full" (completo) para tener respectivamente dos paneles de media pantalla o un único panel a pantalla completa. Tras el tamaño se puede colocar el número "2" para dividir el panel en dos columnas.

A continuación van los campos deseados con especificación opcional del tamaño. Los campos que se pueden emplear son:

name    nombre del archivo.

size    tamaño del archivo.

bsize   forma alternativa para size. Muestra el tamaño de los archivos y SUB-DIR o DIR-ANT para directorios.

type    carácter de tipo de archivo. Este carácter se asemeja a lo mostrado por la orden ls -F: * para archivos ejecutables, / para directorios, @ para enlaces, = para sockets, - para los dispositivos en modo carácter, + para dispositivos en modo bloque, | para tuberías, ~ para enlaces simbólicos a directorios y ! para enlaces rotos (enlaces que no apuntan a nada).

mark    un asterisco si el archivo está marcado, o un espacio si no lo está.

mtime   fecha y hora de la última modificación del contenido del archivo.

atime   fecha y hora del último acceso al archivo.

ctime   fecha y hora del último cambio del archivo.

perm    cadena representando los permisos del archivo.

mode    valor en octal representando los permisos del archivo.

nlink   número de enlaces al archivo.

ngid    Identificador de Grupo, GID (numérico).

nuid    Identificador de Usuario, UID (numérico).

owner   propietario del archivo.

group   grupo del archivo.

inode   número de inodo del archivo.

Además, podemos ajustar la apariencia del panel con:

space   un espacio.

|       añadir una línea vertical.

Para fijar el tamaño de un campo basta añadir : seguido por el número de caracteres que se desee. Si tras el número colocamos el símbolo + el tamaño indicado será el tamaño mínimo, y si hay espacio de sobra se extenderá más el campo.

Como ejemplo, el listado Completo corresponde al formato:

half type name | size | mtime

Y el listado Largo corresponde a:

full perm space nlink space owner space group space size space mtime space name

Este es un bonito formato de pantalla definido por el usuario:

half name | size:7 | type mode:3

Los paneles admiten además los siguientes modos:

"Información"
        La vista de información muestra detalles relativos al archivo seleccionado y, si es posible, sobre el sistema de archivos usado.

"Árbol"
        La vista en árbol es bastante parecida a la utilidad árbol de directoriosDirectory Tree. Para más información véase la sección correspondiente.

"Vista Rápida"
        En este modo, en el panel aparece un visorInternal File Viewer reducido que muestra el contenido del archivo seleccionado. Si se activa el panel (con el tabulador o con el ratón), se dispone de los funciones usuales del visor.[Sort Order...]
Modo de Ordenación...

Los ocho modos de ordenación son por nombre, por extensión, por hora de modificación, por hora de acceso, por la hora de modificación de la información del inodo, por tamaño, por inodo y desordenado. En el cuadro de diálogo del modo de ordenación podemos elegir el modo de ordenación así como especificar si deseamos que este se realice en orden inverso chequeando la casilla Invertir.

Por defecto, los directorios se colocan ordenados antes que los archivos. Esto se puede cambiar en Configuración dentro del Menú de OpcionesOptions Menu activando la opción Mezclar archivos y directorios.[Filter...]
Filtro...

La utilidad filtro nos permite seleccionar con un patrón (por ejemplo *.tar.gz) los archivos a listar. Indiferentes al patrón de filtro, siempre se muestran todos los directorios y enlaces a directorios.[Reread]
Releer

El comando releer recarga la lista de archivos en el directorio. Esto es útil si otros procesos han creado, borrado o modificado archivos. Si hemos panelizado los nombres de los archivos en un panel, esto recargará los contenidos del directorio y eliminará la información panelizada. Véase la sección Búsquedas externasExternal panelize para más información.[File Menu]
Menú de Archivo

Midnight Commander utiliza las teclas de función F1 - F10 como atajos de teclado para los comandos que aparecen en el menú de Archivo. Las secuencias de escape para las Fkeys son características de terminfo desde kf1 hasta kf10. En terminales sin soporte de teclas de función, podemos conseguir la misma funcionalidad pulsando la tecla Esc seguido de un número entre 1 y 9 ó 0 (correspondiendo a las teclas F1 a F9 y F10 respectivamente).

El menú de Archivo recoge las siguientes opciones (con los atajos de teclado entre paréntesis):

Ayuda (F1)

Invoca el visor hipertexto de ayuda interno. Dentro del visor de ayudaContents, podemos usar la tecla Tab para seleccionar el siguiente enlace y la tecla Intro para seguir ese enlace. Las teclas Espacio y Borrar son usadas para mover adelante y atrás en una página de ayuda. Pulsando F1 de nuevo para obtener la lista completa de teclas válidas.

Menú de Usuario (F2)

Invoca el Menú de usuarioEdit Menu File El menú de usuario otorga una manera fácil de tener usuarios con un menú y añadir asimismo características extra a Midnight Commander.

Ver (F3, Mayús-F3)

Visualiza el archivo seleccionado. Por defecto invoca el Visor de Archivos InternoInternal File Viewer pero si la opción "Usar visor interno" está desactivada, invoca un visor de archivos externo especificado por la variable de entorno VIEWER. Si VIEWER no está definida se aplica la variable PAGER y si esta tampoco, se invoca al comando «view». Con Mayús-F3, se abre directamente el visor interno, pero sin realizar ningún tipo de formateo o preprocesamiento del archivo.

Véanse los parámetros para el visor externoParameters for external editor or viewer para saber cómo proporcionar opciones adicionales en línea de órdenes para visores externos.

Ejecutar y Ver (Alt-!)

El comando con los argumentos indicados se ejecuta, y la salida se muestra usando el visor de archivos interno. Como argumento se ofrece, por defecto, el nombre seleccionado en el panel.

Editar (F4)

Invoca el editor vi, u otro especificado en la variable de entorno EDITOR, o el Editor de Archivos InternoInternal File Editor si la opción use_internal_edit está activada.

Véanse los parámetros para el editor externoParameters for external editor or viewer para saber cómo proporcionar opciones adicionales en línea de órdenes para ediotres externos.

Copiar (F5)

Sobreimpresiona una ventana de entrada con destino por defecto al directorio del panel no seleccionado y copia el archivo actualmente seleccionado (o los archivos marcados, si hay al menos uno marcado) al directorio especificado por el usuario en la ventana. Space for destination file may be preallocated relative to preallocate_space configure option. Durante este proceso, podemos pulsar Ctrl-c o Esc para anular la operación. Para más detalles sobre la máscara de origen (que será normalmente * o ^\(.*\)$ dependiendo de la selección de Uso de los patrones del shell) y los posibles comodines en destino véase Máscara copiar/renombrarMask Copy/Rename.

En algunos sistemas, es posible hacer la copia en segundo plano pulsando en el botón de segundo plano con el ratón (o pulsando Alt-b en el cuadro de diálogo). Los Trabajos en Segundo PlanoBackground jobs son utilizados para controlar los procesos en segundo plano.

Crear Enlace (Ctrl-x l)

Crea un enlace al archivo actual.

Crear Enlace Simbólico (Ctrl-x s)

Crea un enlace simbólico al archivo actual. Un enlace es como una copia del archivo, salvo que el original y el destino representan un único archivo físico, los mismos datos reales. En consecuencia, si editamos cualquiera de los archivos, los cambios que realicemos aparecerán en todos los archivos. Reciben también el nombre de alias o accesos directos.

Un enlace aparece como un archivo real. Después de crearlo, no hay modo de decir cuál es el original y cuál el enlace. Si borramos uno de ellos el otro aún seguirá intacto. Es muy difícil advertir que los archivos representan la misma imagen. Usaremos estos enlaces cuando no necesitemos saberlo.

Un enlace simbólico es, en cambio, solo una referencia al nombre del archivo original. Si se borra el archivo original, el enlace simbólico queda sin utilidad. Es bastante fácil advertir que los archivos representan la misma imagen. Midnight Commander muestra un símbolo "@" delante del nombre del archivo si es un enlace simbólico a alguna parte (excepto a un directorio, caso en que muestra una tilde (~)). El archivo original al cual apunta el enlace se muestra en la línea de estado si la opción Mostrar Mini-estado está habilitada. Usaremos enlaces simbólicos cuando queramos evitar la confusión que pueden causar los enlaces físicos.

Renombrar/Mover (F6)

Presenta un diálogo de entrada proponiendo como directorio de destino el directorio del panel no activo, y mueve allí, o bien los archivos marcados o en su defecto el archivo seleccionado. El usuario puede introducir en el diálogo un destino diferente. Durante el proceso, se puede pulsar Ctrl-c o Esc para abortar la operación. Para más detalles, véase más arriba la operación Copiar, dado que la mayoría de los aspectos son similares.

En algunos sistemas, es posible hacer la copia en segundo plano pulsando con el ratón en el susodicho botón de segundo plano (o pulsando Alt-o en el cuadro de diálogo). Con Procesos en 2º planoBackground jobs se puede controlar estas tareas.

Crear Directorio (F7)

Presenta un diálogo de entrada y crea el directorio especificado.

Borrar (F8)

Borra, o bien los archivos marcados o en su defecto el archivo seleccionado en el panel activo. Durante el proceso, se puede pulsar Ctrl-c o Esc para abortar la operación.

Cambiar Directorio (Alt-c) Usaremos el comando Cambiar de directorioQuick cd si tenemos llena la línea de órdenes y queremos hacer un cd a algún lugar.

Seleccionar Grupo (+)

Se utiliza para seleccionar (marcar) un grupo de archivos. Midnight Commander ofrecerá distintas opciones. Indicando Solo archivos los directorios no se seleccionan. Con los Caracteres Comodín habilitados, se pueden introducir expresiones regulares del tipo empleado en los patrones de nombres de la shell (poniendo * para cero o más caracteres y ? para uno o más caracteres). Si los Caracteres Comodín están deshabilitados, entonces la selección de archivos se realiza con expresiones regulares normales. Véase la página de manual de ed (1). Finalmente, si no se activa Distinguir May/min la selección se hará sin distinguir caracteres en mayúsculas o minúsculas.

De-seleccionar Grupo (\)

Utilizado para deseleccionar un grupo de archivos. Es la operación antagonista al comando Selecciona grupo.

Salir (F10, Mayús-F10)

Finaliza Midnight Commander. Mayús-F10 es usado cuando queremos salir y estamos utilizando la envoltura del shell. Mayús-F10 no nos llevará al último directorio visitado con Midnight Commander, en vez de eso nos llevará al directorio donde fue invocado Midnight Commander.[Quick cd]
Cambiar de directorio

Este comando es útil si tenemos completa la línea de órdenes y queremos hacer un cdThe cd internal command a algún lugar sin tener que cortar y pegar sobre la línea. Este comando sobreimpresiona una pequeña ventana, donde introducimos todo aquello que es válido como argumento del comando cd en la línea de órdenes y después pulsamos intro. Este comando caracteriza todas las cualidades incluidas en el comando cd internoThe cd internal command.[Command Menu]
Menú de Utilidades

Árbol de directoriosDirectory Tree muestra una figura con estructura de árbol con los directorios.

Buscar archivosFind File permite buscar un archivo específico. El comando "Intercambiar paneles" intercambia los contenidos de los dos paneles de directorios.

El comando "Activa/desactiva paneles" muestra la salida del último comando del shell. Esto funciona solo en xterm y en una consola Linux y FreeBSD.

El comando Compara directorios (Ctrl-x d) compara los paneles de directorio uno con el otro. Podemos usar el comando Copiar (F5) para hacer ambos paneles idénticos. Hay tres métodos de comparación. El método rápido compara solo el tamaño de archivo y la fecha. El método completo realiza una comparación completa octeto a octeto. El método completo no está disponible si la máquina no soporta la llamada de sistema mmap(2). El método de comparación de solo tamaño solo compara los tamaños de archivo y no chequea los contenidos o las fechas, solo chequea los tamaños de los archivos.

El comando Histórico de comandos muestra una lista de los comandos escritos. El comando seleccionado es copiado a la línea de órdenes. El histórico de comandos puede ser accedido también tecleando Alt-p ó Alt-n.

Favoritos (Ctrl-\)Hotlist permite acceder con facilidad a directorios y sitios utilizados con frecuencia.

Búsquedas ExternasExternal panelize nos permite ejecutar un programa externo, y llevar la salida de ese programa al panel actual.

Editar el archivo de extensionesEdit Extension File nos permite especificar los programas a ejecutar para intentar ejecutar, ver, editar y realizar un montón de cosas sobre archivos con ciertas extensiones (terminaciones de archivo). Por ejemplo, asociar la extensión de los archivos de audio de SUN (.au) con el programa reproductor adecuado. Editar archivo de menúEdit Menu File se puede utilizar para editar el menú de usuario (el que aparece al pulsar F2).[Directory Tree]
Árbol de Directorios

El comando Árbol de directorios muestra una figura con la estructura de los directorios. Podemos seleccionar un directorio de la figura y Midnight Commander cambiará a ese directorio.

Hay dos modos de invocar el árbol. El comando de árbol de directorios está disponible desde el menú Utilidades. El otro modo es seleccionar la vista en árbol desde el menú Izquierdo o Derecho.

Para evitar largos retardos Midnight Commander crea la figura de árbol escaneando solamente un pequeño subconjunto de todos los directorios. Si el directorio que queremos ver no está, nos moveremos hasta su directorio padre y pulsaremos Ctrl-r (o F2).

Podemos utilizar las siguientes teclas:

Teclas de Movimiento GeneralGeneral Movement Keys válidas.

Intro. En el árbol de directorios, sale del árbol de directorios y cambia al directorio en el panel actual. En la vista de árbol, cambia a este directorio en el otro panel y permanece en el modo de vista Árbol en el panel actual.

Ctrl-r, F2 (Releer). Relee este directorio. Usaremos este comando cuando el árbol de directorios esté anticuado: hay directorios perdidos o muestra algunos directorios que no existen ya.

F3 (Olvidar). Borra ese directorio de la figura del árbol. Usaremos esto para eliminar desorden de la figura. Si queremos que el directorio vuelva a la figura del árbol pulsaremos F2 en su directorio padre.

F4 (Estático/Dinámico, Dinam/Estát). Intercambia entre el modo de navegación dinámico (predefinido) y el modo estático.

En el modo de navegación estático podemos usar las teclas del cursor Arriba y Abajo para seleccionar un directorio. Todos los directorios conocidos serán mostrados.

En el modo de navegación dinámico podemos usar las teclas del cursor Arriba y Abajo para seleccionar el directorio hermano, la tecla Izquierda para situarnos en el directorio padre, y la tecla Derecha para situarnos en el directorio hijo. Solo los directorios padre, hijo y hermano son mostrados, el resto son dejados fuera. La figura de árbol cambia dinámicamente conforme nos desplazamos sobre ella.

F5 (Copiar). Copia el directorio.

F6 (Renombrar/Mover, RenMov). Mueve el directorio.

F7 (Mkdir). Crea un nuevo directorio por debajo del directorio actual. El directorio creado será así el hijo del directorio del cual depende jerárquicamente (Padre).

F8 (Eliminar). Elimina este directorio del sistema de archivos.

Ctrl-s, Alt-s. Busca el siguiente directorio coincidente con la cadena de búsqueda. Si no hay tal directorio esas teclas moverán una línea abajo.

Ctrl-h, Borrar. Borra el último carácter de la cadena de búsqueda.

Cualquier otro carácter. Añade el carácter a la cadena de búsqueda y se desplaza al siguiente directorio que comienza con esos caracteres. En la vista de árbol debemos primero activar el modo de búsqueda pulsando Ctrl-s. La cadena de búsqueda se muestra en la línea de estado.

Las siguientes acciones están disponibles solo en el árbol de directorios. No son funcionales en la vista de árbol.

F1 (Ayuda). Invoca el visor de ayuda y muestra esta sección.

Esc, F10. Sale del árbol de directorios. No cambia el directorio.

El ratón es soportado. Un doble click se comporta como pulsar Intro. Véase también la sección sobre soporte de ratónMouse Support.[Find File]
Buscar Archivos

La utilidad para Buscar Archivos primero pregunta por el directorio de inicio y el nombre de archivo a buscar. Pulsando el botón Árbol podemos seleccionar el directorio inicial en el Árbol de directoriosDirectory Tree.

El campo de contenidos puede aceptar expresiones regulares similares a egrep(1). En ese caso podremos proteger caracteres con significado especial para egrep anteponiendo «\», p.ej. si buscamos «strcmp (» tendremos que introducir «strcmp \(".

Con la opción «Palabras completas» se puede limitar la búsqueda a archivos donde la parte coincidente forme una palabra completa. Eso se corresponde con la función de la opción «-w» de grep.

Podemos iniciar la búsqueda pulsando el botón Aceptar. Durante el proceso de búsqueda podemos detenerla desde el botón Terminar.

Podemos navegar por la lista de archivos con las teclas del cursor Arriba y Abajo. El botón Chdir cambiará al directorio del archivo actualmente seleccionado. El botón "Otra vez" preguntará los parámetros para una nueva búsqueda. El botón Terminar finaliza la operación de búsqueda. El botón Panelizar colocará los archivos encontrados en el panel actual y así podremos realizar más operaciones con ellos (ver, copiar, mover, borrar y demás). Después de panelizar podemos pulsar Ctrl-r para regresar al listado normal de archivos.

Es posible tener una lista de directorios que el comando Buscar Archivo debería saltar durante la búsqueda (por ejemplo, podemos querer evitar búsquedas en un CDROM o en un directorio NFS que está montado a través de un enlace lento).

Los directorios a ser omitidos deberían ser enumerados en la variable ignore_dirs en la sección FindFile de nuestro archivo ~/.config/mc/ini.

Los componentes del directorio deberían ser separados por dos puntos, como en el ejemplo que sigue:

[FindFile]
ignore_dirs=/cdrom:/nfs/wuarchive:/afs

Debemos valorar la utilización de Búsquedas externasExternal panelize en ciertas situaciones. La utilidad Buscar archivos es solo para consultas simples, pero con Búsquedas externas se pueden hacer exploraciones tan complejas como queramos.[External panelize]
Búsquedas Externas

Búsquedas externas nos permite ejecutar un programa externo, y tomar la salida de ese programa como contenido del panel actual.

Por ejemplo, si queremos manipular en uno de los paneles todos los enlaces simbólicos del directorio actual, podemos usar búsquedas externas para ejecutar el siguiente comando:

find . -type l -print

Hasta la finalización del comando, el contenido del directorio del panel no será el listado de directorios del directorio actual, pero sí todos los archivos que son enlaces simbólicos.

Si queremos panelizar todos los archivos que hemos bajado de nuestro servidor ftp, podemos usar el comando awk para extraer el nombre del archivo de los archivos de registro (log) de la transferencia:

awk '$9 ~! /incoming/ { print $9 }' < /var/log/xferlog

Tal vez podríamos necesitar guardar los comandos utilizados frecuentemente bajo un nombre descriptivo, de manera que podamos llamarlos rápidamente. Haremos esto tecleando el comando en la línea de entrada y pulsando el botón "Añadir nuevo". Entonces introduciremos un nombre bajo el cual queremos que el comando sea guardado. La próxima vez, bastará elegir ese comando de la lista y no habrá que escribirlo de nuevo.[Hotlist]
Favoritos

Muestra una lista de sitios y directorios guardados y abre en el panel el lugar seleccionado. Desde el cuadro de diálogo podemos también crear y eliminar entradas. Para añadir se puede igualmente utilizar Añadir Actual (Ctrl-x h), que añade el directorio actual (no el seleccionado) a la lista de favoritos. Se pide al usuario una etiqueta para identificar la entrada.

Esto hace más rápido el posicionamiento en los directorios usados frecuentemente. Deberíamos considerar también el uso de la variable CDPATH tal y como se describe en comando cd internoThe cd internal command.[Edit Extension File]
Editar el Archivo de Extensiones

Abre el archivo ~/.config/mc/mc.ext.ini en nuestro editor. If this file does not exist and you are not root, it will be copied from /opt/etc/mc/mc.ext.ini. If you are root, you can choose the file to edit: user's ~/.config/mc/mc.ext.ini or system-wide /opt/etc/mc/mc.ext.ini. The format of this file is described in detail in it.[Background jobs]
Trabajos en Segundo Plano

Nos permite controlar el estado de cualquier proceso de Midnight Commander en segundo plano (solo las operaciones de copiar y mover archivos pueden realizarse en segundo plano). Podemos parar, reiniciar y eliminar procesos en segundo plano desde aquí.[Edit Menu File]
Edición del Archivo de Menú

El menú de usuario es un menú de acciones útiles que puede ser personalizado por el usuario. Cuando accedemos al menú de usuario se utiliza, si existe, el archivo .mc.menu del directorio actual, pero solo si es propiedad del usuario o del superusuario y no es modificable por todos. Si no se encuentra allí el archivo, se intenta de la misma manera con ~/.config/mc/menu, y si no, mc utiliza el menú por defecto para todo el sistema /opt/share/mc/mc.menu.

El formato del menú de archivo es muy simple. Todas las líneas, salvo las que empiezan con espacio o tabulación, son consideradas entradas para el menú (para posibilitar su uso como atajo de teclado, el primer carácter sí deberá ser una letra). Las líneas que comienzan con una tabulación o espacio son los comandos que serán ejecutados cuando la entrada es seleccionada.

Cuando se selecciona una opción todas las líneas de comandos de esa opción se copian en un archivo temporal en el directorio temporal (normalmente /usr/tmp), y se ejecuta ese archivo. Esto permite al usuario utilizar en los menús construcciones normales de la shell. También tiene lugar una sustitución simple de macros antes de ejecutar el código del menú. Para mayor información, ver Sustitución de macroMacro Substitution.

He aquí un ejemplo de archivo mc.menu:

A	Vuelca el contenido del archivo seleccionado
	od -c %f

B	Edita un informe de errores y lo envía al superusuario
	I=`mktemp ${MC_TMPDIR:-/tmp}/mail.XXXXXX` || exit 1
	vi $I
	mail -s "Error Midnight Commander" root < $I
	rm -f $I

M	Lee al correo
	emacs -f rmail

N	Lee las noticias de Usenet
	emacs -f gnus

H	Realiza una llamada al navegador hypertexto info
	info

J	Copia recursivamente el directorio actual al otro panel
	tar cf - . | (cd %D && tar xvpf -)

K	Realiza una versión del directorio actual
	echo -n "Nombre del archivo de distribución: "
	read tar
	ln -s %d `dirname %d`/$tar
	cd ..
	tar cvhf ${tar}.tar $tar

= f *.tar.gz | f *.tgz & t n
X       Extrae los contenidos de un archivo tar comprimido
	tar xzvf %f

Condiciones por Defecto

Cada entrada del menú puede ir precedida por una condición. La condición debe comenzar desde la primera columna con un carácter '='. Si la condición es verdadera, la entrada del menú será la entrada por defecto.

Sintaxis condicional: 	= <sub-cond>
  o:			= <sub-cond> | <sub-cond> ...
  o:			= <sub-cond> & <sub-cond> ...

Sub-condición es una de las siguientes:

  f <patrón>		¿el archivo actual encaja con el patrón?
  F <patrón>		¿otro archivo encaja con el patrón?
  d <patrón>		¿el directorio actual encaja con el patrón?
  D <patrón>		¿otro directorio encaja con el patrón?
  t <tipo>		¿archivo actual es de tipo <tipo>?
  T <tipo>		¿otro archivo es de tipo <tipo>?
  ! <sub-cond>		niega el resultado de la sub-condición

Patrón es un patrón normal del shell o una expresión regular, de acuerdo con la opción de patrones del shell. Podemos cambiar el valor global de la opción de los patrones del shell escribiendo "shell_patterns=x" en la primera línea del archivo de menú (donde "x" es 0 ó 1).

Tipo es uno o más de los siguientes caracteres:

  n	no directorio
  r	archivo regular
  d	directorio
  l	enlace
  c	dispositivo tipo carácter
  b	dispositivo tipo bloque
  f	tubería (fifo)
  s	socket
  x	ejecutable
  t	marcado (tagged)

Por ejemplo 'rlf' significa archivo regular, enlace o cola. El tipo 't' es un poco especial porque actúa sobre el panel en vez de sobre un archivo. La condición '=t t' es verdadera si existen archivos marcados en el panel actual y falsa si no los hay.

Si la condición comienza con '=?' en vez de '=' se mostrará un trazado de depuración mientras el valor de la condición es calculado.

Las condiciones son calculadas de izquierda a derecha. Esto significa que
	= f *.tar.gz | f *.tgz & t n
es calculado como
	( (f *.tar.gz) | (f *.tgz) ) & (t n)

He aquí un ejemplo de uso de condiciones:

= f *.tar.gz | f *.tgz & t n
L	Lista el contenido de un archivo tar comprimido
	gzip -cd %f | tar xvf -

Condiciones aditivas

Si la condición comienza con '+' (o '+?') en lugar de '=' (o '=?') es una condición aditiva. Si la condición es verdadera la entrada de menú será incluida en el menú. Sin embargo, si la condición es falsa, la entrada de menú no será incluida en el menú.

Podemos combinar condiciones por defecto y aditivas comenzando la condición con '+=' o '=+' (o '+=?' o '=+?' si queremos depurar). Si nosotros queremos condiciones diferentes, una para añadir y otra por defecto, una entrada de menú con dos líneas de condición, una comenzando con '+' y otra con '='.

Los comentarios empiezan con '#'. Las líneas adicionales de comentarios deben empezar con '#', espacio o tabulación.[Options Menu]
Menú de Opciones

Midnight Commander tiene opciones que pueden ser activadas o desactivadas a través de una serie de diálogos a los que se accede desde este menú. Una opción está activada cuando tiene delante un asterisco o una "x".

En ConfiguraciónConfiguration se pueden cambiar la mayoría de opciones de Midnight Commander.

En PresentaciónLayout está un grupo de opciones que determinan la apariencia de mc en la pantalla.

En PanelesPanel options se pueden configurar los paneles del gestor de archivos.

En ConfirmaciónConfirmation podemos especificar qué acciones requieren una confirmación del usuario antes de ser realizadas.

En AspectoAppearance podemos seleccionar un «skin» o apariencia para el programa.

En Juego de CaracteresDisplay bits podemos seleccionar qué caracteres es capaz de mostrar nuestro terminal.

En Aprender TeclasLearn keys podemos verificar teclas que no funcionan en algunos terminales y solucionarlo.

En Sistema de Archivos Virtual (VFS)Virtual FS podemos especificar algunas opciones relacionadas con el VFS (Sistema de Archivos Virtual).

Guardar ConfiguraciónSave Setup guarda los valores actuales de los menús Izquierdo, Derecho y Opciones. También se guardan algunos otros valores.[Configuration]
Configuración

Este diálogo presenta una serie de opciones divididas en tres grupos: «Operaciones con Archivos», «Tecla de Escape», «Pausa Después de Ejecutar» y «Otras Opciones».

Operaciones con Archivos

Operación Detallada. Controla la visualización de detalles durante las operaciones de Copiar, Mover y Borrar (i.e., muestra un cuadro de diálogo para cada operación). Si tenemos un terminal lento, podríamos querer desactivar la operación detallada. Se desactiva automáticamente si la velocidad de nuestro terminal es menor de 9600 bps.

Calcular Totales. Hace que Midnight Commander calcule el total de bytes y el número de archivos antes de iniciar operaciones de Copiar, Mover y Borrar. Esto proporciona una barra de progreso más precisa a costa de cierta velocidad. Esta opción no tiene efecto si la Operación Detallada no está seleccionada.

Barra de Progreso Clásica. Con esta opción la barra de progreso para las operaciones de Copiar, Mover o Borrar avanza de izquierda a derecha. Si se deshabilita, el sentido de crecimiento refleja el sentido de la copia: del panel izquierdo al derecho o viceversa. Por defecto, está activa.

Proponer Nombre Mkdir. Al pulsar F7 para crear un directorio nuevo, la línea de entrada del diálogo incorpora como sugerencia el nombre del archivo o directorio actual en el panbel activo. Está deshabilitado por defecto.

Reservar Espacio. Antes de comenzar una copia reserva espacio para el archivo destino completo. Por defecto está desactivado.

Tecla de Escape.

Midnight Commander utiliza la tecla ESC como prefijo para ciertas teclas. Por ello hay que pulsar ESC dos veces para abandonar los diálogos. Se puede configurar para que esto se pueda realizar con una única pulsación. Pulsación Única Por defecto, está deshabilitada. Permite que ESC actúe como prefijo durante un cierto tiempo (véase abajo la opción Tiempo) al cabo del cual se interpreta ESC para cancelar (ESC ESC).

Tiempo. Permite configurar el intervalo (en microsegundos) para una pulsación de ESC autónoma. Por defecto es de un segundo (1000000 microsegundos). Este intervalo también se puede fijar a través de la variable de entorno KEYBOARD_KEY_TIMEOUT_US (también en microsegundos) que tiene prioridad sobre el valor de esta opción Tiempo.

Pausa Después de Ejecutar.

Después de ejecutar comandos, Midnight Commander puede realizar una pausa, y darnos tiempo a examinar la salida del comando. Hay tres posibles valores para esta variable:

Nunca. Significa que no queremos ver la salida de nuestros comandos. Si estamos utilizando la consola Linux o FreeBSD o un xterm, podremos ver la salida del comando pulsando Ctrl-o.

SoloenTerminalesTontas. Obtendremos el mensaje de pausa solo en terminales que no sean capaces de mostrar la salida del último comando ejecutado (en realidad, cualquier terminal que no sea un xterm o una consola de Linux).

Siempre. El programa realizará siempre una pausa después de ejecutar comandos.

Otras Opciones

Usar Editor Interno. Emplear el editor de archivos interno. Si está desactivada, se editarán los archivos con el editor especificado por la variable de entorno EDITOR y si no se especifica ninguno, se usará vi. Véase la sección sobre el editor de archivos internoInternal File Editor.

Usar Visor Interno. Emplear el visor de archivos interno. Si la opción está desactivada, el paginador especificado en la variable de entorno PAGER será el utilizado. Si no se especifica ninguno, se usará el comando view. Véase la sección sobre el visor de archivos internoInternal File Viewer.

Pedir Nombre al Editar Nuevos. Si está activada, se pedirá al usuario el nombre de archivo antes de abrir un archivo nuevo en el editor.

Auto Menús. Si está activada, el menú de usuario aparece automáticamente al arrancar. Útil en menús construidos para personas sin conocimientos de Unix.

Menús Desplegables. Mostrar el contenido de los menús desplegables inmediatamente al presionar F9. Si está desactivada solo la barra de títulos de los menús está visible, y será necesario abrir cada menú con las flechas de movimiento o con las teclas de acceso rápido. Completar: Mostrar Todos. Por defecto, al completar nombres en situaciones de ambigüedad, Midnight Commander completa todo lo posible al pulsar Alt-Tab y produce un pitido; al intentarlo por segunda vez se muestra una lista con las posibilidades que han dado lugar a la ambigüedad. Con esta opción, la lista aparece directamente tras pulsar Alt-Tab por primera vez.

Patrones «shell». Por defecto, las funciones Selección, Deselección y Filtro emplean expresiones regulares al estilo del shell. Para realizar esto se realizan las siguientes conversiones: '*' se cambia por '.*' (cero o más caracteres); '?' por '.' (exactamente un carácter) y '.' por un punto literal. Si la opción está desactivada, entonces las expresiones regulares son las descritas en ed(1).

Completar: Mostrar Todos. Por defecto Midnight Commander presenta todas las posibilidades de terminaciónCompletion si la compleción es ambigua solo al pulsar Alt-Tab por segunda vez. La primera, solo completa todo lo posible y emite un pitido en caso de ambigüedad. Activando esta opción se muestran todas las posibilidades directamente con la primera pulsación de Alt-Tab.

Hélice de actividad. Mostrar un guión rotatorio en la esquina superior derecha a modo de indicador de progreso.

Cd Sigue los Enlaces. Esta opción, si está seleccionada, hace que Midnight Commander siga la secuencia de directorios lógica al cambiar el directorio actual, tanto en el panel como usando el comando cd. Este es el comportamiento por defecto de la shell bash. Sin esto, Midnight Commander sigue la estructura real de directorios, y cd .. nos trasladará al padre real del directorio actual aunque hayamos entrado en ese directorio a través de un enlace, y no al directorio donde se encontraba el enlace.

Precauciones de Borrado. Dificulta el borrado accidental de archivos. La opción por defecto en el diálogo de confirmación de borrado se cambia a "No". Por defecto, esta opción está desactivada.

Auto-Guarda Configuración. Si esta opción está activada, cuando salimos de Midnight Commander las opciones configurables de Midnight Commander se guardan en el archivo ~/.config/mc/ini.[Layout]
Presentación

La ventana de presentación nos da la posibilidad de cambiar la presentación general de la pantalla. Podemos configurar si son visibles la barra de menú, la línea de órdenes, la línea de sugerencias o la barra de teclas de Función. En la consola Linux o FreeBSD podemos especificar cuántas líneas se muestran en la ventana de salida.

El resto del área de pantalla se utiliza para los dos paneles de directorio. Podemos elegir si disponemos los paneles vertical u horizontalmente. La división puede ser simétrica o bien podemos indicar una división asimétrica.

Por defecto, todos los contenidos de los paneles se muestran en el mismo color, pero se puede indicar que permisos y tipos de archivos se resalten empleando coloresColors diferentes. Si se activa el resaltado de permisos, las partes de los campos de permisos del Modo de ListadoListing Format... aplicables al usuario actual de Midnight Commander serán resaltados usando el color indicado por medio de la palabra clave selected. Si se activa el resaltado de tipos de archivos, los nombres aparecerán coloreados según las reglas almacenadas en el archivo /opt/share/mc/filehighlight.ini. Para más información, véase la sección sobre Resaltado de nombresFilenames Highlight.

Si se está ejecutando en X Window dentro de un emulador de terminal, Midnight Commander toma control del titulo de la ventana mostrando allí el nombre del directorio actual. El título se actualiza cuando sea preciso. Podemos desactivar la opción de Titular las ventanas Xterm si el emulador de terminal empleado falla y no se muestran o actualizan correctamente estos textos.[Panel options]
Paneles

Opciones principales

Mostrar Mini-estado Si está activa se muestra en la parte inferior de cada panel una línea con información sobre el archivo seleccionado en cada momento. Por defecto, está activado.

Tamaños en unidades SI. Mostrar tamaños de archivos en bytes con prefijos según el SI, Sistema Internacional de Unidades, o sea, en base de 10. Por defecto, está desactivada: los tamaños se calculan con prefijos según el IEC, empleando base de 2. Véase al respecto ISO/IEC 80000-13.

Mezclar Archivos y Directorios. Cuando esta opción está habilitada, todos los archivos y directorios se muestran mezclados. Por defecto esta opción está desactivada: los directorios (y enlaces a directorios) aparecen al principio de la lista, y el resto de archivos a continuación.

Mostrar Archivos de Respaldo. Mostrar los archivos terminados en tilde '~'. Si se desactiva no se muestran (como la opción -B de ls de GNU). Por defecto, está activo.

Mostrar Archivos Ocultos. Mostrar los archivos que comiencen con un punto (como ls -a). Por defecto, está desactivado.

Recarga Rápida de Directorios. Hace que Midnight Commander emplee una pequeña trampa al determinar si los contenidos del directorio han cambiado. El truco consiste en recargar el directorio solo si el inodo del directorio ha cambiado. Las recargas se producen si se crean o borran archivos, pero si lo que cambia es solo el inodo de un archivo del directorio (cambios en el tamaño, permisos, propietario, etc.) la pantalla no se actualiza. En esos casos, si tenemos la opción activada, será preciso forzar la recarga de forma manual (con Ctrl-r). Por defecto, está desactivado.

Marcar y Avanzar. Hacer avanzar la barra de selección tras marcar un archivo (con la tecla insertar). Por defecto, está activo.

Invertir Solo Archivos. Permite invertir la selección solo sobre los archivos. Por defecto, está activo. Al invertir la selección se aplica solo a archivos, quedando los directorios como estaban. Si se desactiva, todos los elementos no seleccionados se seleccionan y viceversa, sean archivos o directorios.

Intercambio de Paneles Simple. Si los dos paneles contienen listados de directorios, el intercambio simple supone que ambos paneles intercambian sus posiciones: izquierda por derecha. Si se desactiva, que es el estado por defecto, los contenidos de los paneles se intercambian pero se mantienen las opciones de formato y orden de archivos.

Auto Guardar Configuración Por defecto está desactivado. Si se activa, la configuración de los paneles se guardará en ~/.config/mc/panels.ini al salir del programa.

Navegación

Navegación al Estilo Lynx. Cuando la selección es un directorio y la línea de órdenes está vacía permite cambiar a él con las flechas de movimiento. Esta opción está inactiva por defecto.

Avance de Página. Por defecto, cuando el cursor llega al final o al comienzo del panel este se desplaza el equivalente a media pantalla. Al desactivarlo el avance o retroceso se hace línea a línea.

Avance de Página con Ratón. Controla si el avance en los paneles con la rueda del ratón se hace por páginas o por líneas.

Resaltar

Permite que los permisos y tipos de archivos queden resaltados con coloresColors distintivos. Si se habilita el resaltado de permisos, los campos del listadoListing Format... perm y mode aplicables al usuario que ejecuta MC se mostrarán destacados en el color indicado con la clave selected. Si se habilita el resaltado de tipo de archivo, los nombres de archivo se mostrarán coloreados según las reglas contenidas en el archivo de configuración /opt/etc/mc/filehighlight.ini. Véase Resaltado de nombresFilenames Highlight.

Búsqueda rápida

Permite configurar si la Búsqueda rápidaQuick search distingue o no mayúsculas en los nombres: ignorar, distinguir o aplicar el mismo criterio elegido en el orden de los nombres en el panel.[Confirmation]
Confirmación

En este diálogo configuramos las opciones de confirmación de eliminación de archivos, sobreescritura, ejecución pulsando intro y salir del programa.[Appearance]
Aspecto

Aquí se puede elegir un «skin» o apariencia para usar.

Véase la sección sobre SkinsSkins para conocer los detalles de los archivos de definición de estos «skins».[Display bits]
Juego de caracteres

Esta opción permite configurar el conjunto de caracteres visibles en la pantalla. Este puede ser 7-bits si nuestro terminal/curses soporta solo siete bits de salida, alguna de las tablas del estándar ISO-8859 y diversas codificaciones comunes de PC con ocho bits por carácter, o UTF-8 para Unicode.

Para soportar teclados con caracteres locales debemos marcar la opción de Aceptar entrada de 8 bits.[Learn keys]
Aprender teclas

Este diálogo nos permite comprobar si nuestras teclas F1-F20, Inicio, Fin, etc. funcionan adecuadamente en nuestro terminal. A menudo fallan, dado que muchas bases de datos de terminales están mal.

Podemos movernos alrededor con la tecla Tab, con las teclas de movimiento de vi ('h' izquierda, 'j' abajo, 'k' arriba y 'l' derecha) y después de pulsar cualquier tecla del cursor (esto las marcará con OK), entonces podremos usar esa tecla también.

Para probarlas basta con pulsar cada una de ellas. Tan pronto como pulsamos una tecla y esta funciona adecuadamente, la marca «✓» debería aparecer junto al nombre de la susodicha tecla. Una vez que cada tecla queda marcada vuelve a funcionar con normalidad, p. ej. F1 la primera vez comprobará que F1 funciona perfectamente, pero a partir de ese momento mostrará la ayuda. Esto mismo es aplicable a las teclas del cursor. La tecla Tab debería funcionar siempre.

Si algunas teclas no funcionan adecuadamente, entonces no veremos el OK tras el nombre de la tecla después de haberla pulsado. Podemos entonces intentar solucionarlo. Haremos esto pulsando el botón de esa tecla (con el ratón o usando Tab e Intro). Entonces un mensaje rojo aparecerá y se nos pedirá que pulsemos la tecla en cuestión. Si deseamos abortar el proceso, bastará con pulsar Esc y esperar hasta que el mensaje desaparezca. Si no, pulsaremos la tecla que nos pide y esperaremos hasta que el diálogo desaparezca.

Cuando acabemos con todas las teclas, podríamos Guardar nuestras teclas en nuestro archivo ~/.config/mc/ini dentro de la sección [terminal:TERM] (donde TERM es el nombre de nuestro terminal actual) o descartarlas. Si todas nuestras teclas funcionan correctamente y no debemos corregir ninguna, entonces (lógico) no se grabará.[Virtual FS]
Sistema de Archivos Virtual (VFS)

Este diálogo permite ajustar opciones del Sistema de Archivos Virtual (VFS)Virtual File System.

Midnight Commander guarda en memoria o en disco información de algunos de los sistemas de archivos virtuales con el fin de acelerar el acceso a sus archivos. Ejemplo de esto son los listados descargados desde servidores FTP o los archivos temporales descomprimidos creados para acceder rápidamente a los contenidos de archivos tipo tar comprimidos.

Esas informaciones se conservan para permitirnos navegar, salir y volver a entrar rápidamente en los correspondientes sistemas de archivos virtuales. Al cabo de un cierto tiempo sin usarlos deben ser liberados y recuperar los recursos utilizados. Por defecto ese tiempo es de un minuto, pero se puede configurar por el usuario.

También podemos adelantar la liberación de los VFS desde el diálogo de control de Directorios virtuales (VFS).

El Sistema de Archivos FTP (FTPfs)FTP File System permite navegar por los directorios de servidores FTP remotos. Admite diversas opciones.

Contraseña de FTP anónimo es la contraseña a utilizar en conexiones en modo anónimo, esto es, empleando el nombre de usuario "anonymous". Algunos sitios exigen que esta sea una dirección de correo electrónico válida, pero tampoco es conveniente dar nuestra dirección real a desconocidos para protegernos de los envíos de correo masivo.

FTPfs conserva en caché los listados de los directorios consultados. La duración de la caché es el valor indicado tras Descartar el caché FTPfs. Un valor pequeño ralentiza el proceso porque cualquier pequeña operación iría siempre acompañada de una conexión con el servidor FTP.

Se puede configurar un sistema proxy para FTP, aunque los cortafuegos modernos son transparentes (al menos para FTP pasivo, ver más abajo) y está opción es generalmente innecesaria.

Si la opción Usar siempre proxy no está activa, aún se puede emplear el proxy en casos concretos. Véanse los ejemplos en la sección Sistema de Archivos FTP (FTPfs)FTP File System.

Si la opción Usar siempre proxy está puesta, el programa asume que cualquier nombre de máquina sin puntos es accesible directamente y también consulta el archivo /opt/etc/mc/mc.no_proxy en busca de nombres de máquinas locales (o dominios completos si el nombre empieza con un punto). En todos los demás casos se usará siempre el proxy de FTP indicado arriba.

Se puede usar el archivo ~/.netrc, que contiene información de usuarios y contraseñas para determinados servidores FTP. Para conocer el formato de los archivos .netrc véase la página de manual sobre netrc (5).

Usar FTP pasivo habilita el modo de tranferencia FTP pasivo (la conexión para transferencia de datos es iniciada por la máquina cliente, no por el servidor). Esta opción es la recomendada, y de hecho está activada por defecto. Si se desactiva, la conexión la inicia el servidor, y puede ser impedida por algún cortafuegos.

[Save Setup]
Guardar Configuración

Al arrancar Midnight Commander se carga la información de inicio del archivo ~/.config/mc/ini. Si este no existe, se cargará la información del archivo de configuración genérico del sistema, /opt/share/mc/mc.ini. Si el archivo de configuración genérico del sistema no existe, MC utiliza la configuración por defecto.

El comando Guardar Configuración crea el archivo ~/.config/mc/ini guardando la configuración actual de los menús Izquierdo, DerechoLeft and Right Menus y OpcionesOptions Menu.

Si se activa la opción Auto-guarda configuración, MC guardará siempre la configuración actual al salir.

Existen también configuraciones que no pueden ser cambiadas desde los menús. Para cambiarlas hay que editar manualmente el archivo de configuración. Para más información, véase la sección sobre Ajustes EspecialesSpecial Settings.

[Executing operating system commands]
Ejecutando Órdenes del Sistema Operativo

Podemos ejecutar comandos tecleando en la línea de órdenes de Midnight Commander, o seleccionando el programa que queremos ejecutar en alguno de los paneles y pulsando Intro.

Si pulsamos Intro sobre un archivo que no es ejecutable, Midnight Commander compara la extensión del archivo seleccionado con las extensiones recogidas en el Archivo de ExtensionesEdit Extension File. Si se produce una coincidencia se ejecutará el código asociado con esa extensión. Tendrá lugar una expansiónMacro Substitution muy simple antes de ejecutar el comando.[The cd internal command]
Comando cd Interno

El comando cd es interpretado directamente por Midnight Commander, en vez de pasarlo al interprete de comandos para su ejecución. Por ello puede que no todas las posibilidades de expansión y sustitución de macro que hace nuestro shell estén disponibles, pero sí algunas de ellas:

Sustitución de tilde. La tilde (~) será sustituida por nuestro directorio de inicio. Si añadimos un nombre de usuario tras la tilde, entonces será sustituido por el directorio de entrada al sistema del usuario especificado.

Por ejemplo, ~coco sería el directorio de un supuesto usuario denominado "coco", mientras que ~/coco es el directorio coco dentro de nuestro propio directorio de inicio.

Directorio anterior. Podemos volver al directorio donde estábamos anteriormente empleando el nombre de directorio especial '-' del siguiente modo: cd -

Directorios en CDPATH. Si el directorio especificado al comando cd no está en el directorio actual, entonces Midnight Commander utiliza el valor de la variable de entorno CDPATH para buscar el directorio en cualquiera de los directorios enumerados.

Por ejemplo, podríamos asignar a nuestra variable CDPATH el valor ~/src:/usr/src, lo que nos permitiría cambiar de directorio a cualquiera de los directorios dentro de ~/src y /usr/src, desde cualquier lugar del sistema de archivos, usando solo su nombre relativo (por ejemplo cd linux podría llevarnos a /usr/src/linux).[Macro Substitution]
Sustitución de Macro

Cuando se accede al menú de usuarioEdit Menu File, o se ejecuta un comando dependiente de extensiónEdit Extension File, o se ejecuta un comando desde la línea de entrada de comandos, se realiza una simple sustitución de macro.

Las macros son:

"%f"

        Archivo actual.

"%d"

        Nombre del directorio actual.

"%F"

        Archivo actual en el panel inactivo.

"%D"

        Directorio del panel inactivo.

"%t"

        Archivos actualmente marcados.

"%T"

        Archivos marcados en el panel inactivo.

"%u" y "%U"

        Similar a las macros %t y %T, salvo que los archivos quedan desmarcados. Solo se puede emplear esta macro una vez por cada entrada del archivo de menú o archivo de extensiones, puesto que para la siguiente vez no quedaría ningún archivo marcado.

"%s" y "%S"

        Archivos seleccionados: Los archivos marcados si los hay y si no el archivo actual.

"%cd"

        Esta es una macro especial usada para cambiar del directorio actual al directorio especificado frente a él. Esto se utiliza principalmente como interfaz con el Sistema de Archivos VirtualVirtual File System.

"%view"

        Esta macro es usada para invocar al visor interno. Puede ser utilizada en solitario, o bien con argumentos. Si pasamos algún argumento a esta macro, deberá ser entre paréntesis.

        Los argumentos son: ascii para forzar al visor a modo ascii; hex para forzar al visor a modo hexadecimal; nroff para indicar al visor que debe interpretar las secuencias de negrita y subrayado de nroff; unformated para indicar al visor que no interprete los comandos nroff referentes a texto resaltado o subrayado.

"%%"

        El carácter %

"%{cualquier texto}"

        Pregunta sobre la sustitución. Un cuadro de entrada es mostrado y el texto dentro de las llaves se usa como mensaje. La macro es sustituida por el texto tecleado por el usuario. El usuario puede pulsar Esc o F10 para cancelar. Esta macro no funciona aún sobre la línea de órdenes.[The subshell support]
Soporte de Subshell

El soporte del subshell es una opción de tiempo de compilación, que funciona con los shells: bash, tcsh y zsh.

Cuando el código del subshell es activado Midnight Commander engendrará una copia de nuestro shell (la definida en la variable SHELL y si no está definida, el que aparece en el archivo /etc/passwd) y lo ejecuta en un pseudoterminal, en lugar de invocar un nuevo shell cada vez que ejecutamos un comando, el comando será pasado al subshell como si lo hubiésemos escrito. Esto además permite cambiar las variables de entorno, usaremos las funciones del shell y los alias definidos que serán válidos hasta salir de Midnight Commander.

Si estamos usando bash podremos especificar comandos de arranque para el subshell en nuestro archivo ~/.local/share/mc/bashrc y mapas de teclado especiales en el archivo ~/.local/share/mc/inputrc. Los usuarios de tcsh podrán especificar los comandos de arranque en el archivo ~/.local/share/mc/tcshrc.

Cuando utilizamos el código del subshell, podemos suspender aplicaciones en cualquier momento con la secuencia Ctrl-o y volver a Midnight Commander, si interrumpimos una aplicación, no podremos ejecutar otros comandos externos hasta que quitemos la aplicación que hemos interrumpido.

Una característica extra añadida de uso del subshell es que el prompt mostrado por Midnight Commander es el mismo que estamos usando en nuestro shell.

La sección OPCIONES tiene más información sobre cómo controlar el código del subshell.[Chmod]
Cambiar Permisos

Cambiar Permisos se usa para cambiar los bits de permisos en un grupo de archivos y directorios. Puede ser invocado con la combinación de teclas Ctrl-x c.

La ventana de Cambiar Permisos tiene dos partes - Permisos y Archivo

En la sección Archivo se muestran el nombre del archivo o directorio y sus permisos en formato numérico octal, así como su propietario y grupo.

En la sección de Permisos hay un grupo de casillas de selección que corresponden a los posibles permisos del archivo. Conforme los cambiamos podemos ver cómo el valor octal va cambiando en la sección Archivo.

Para desplazarse entre las casillas y botones de la ventana podemos usar las teclas del cursor o la tecla de tabulación. Para marcar o desmarcar casillas y para pulsar los botones usaremos la barra espaciadora. Podemos usar los atajos de teclado (las letras destacadas) para accionar directamente los elementos.

Para aceptar y aplicar los permisos, usaremos la tecla Intro.

Si se trata de un grupo de archivos o directorios, podemos cambiar parte de los permisos marcándolos (las marcas son los asteriscos a la izquierda de las casillas) y pulsando el botón [* Poner] o [* Quitar] para indicar la acción deseada. Los permisos no marcados conservan, en este caso, los valores previos.

Podemos también fijar todos los permisos iguales en todos los archivos con el botón [Todos] o solo los permisos marcados con el botón [* Todos]. En estos casos las casillas indican el estado en que queda cada permiso, igual que para archivos individuales.

[Todos] actúa sobre todos los permisos de todos los archivos

[* Todos] actúa solo sobre los atributos marcados de los archivos

[* Poner] activa los permisos marcados en los archivos seleccionados

[* Quitar] desactiva los permisos marcados en los archivos seleccionados

[Aplicar] actúa sobre todos los permisos de cada archivo, uno a uno

[Cancelar] cancela Cambiar Permisos[Chown]
Cambiar Dueño

Cambiar Dueño permite cambiar el propietario y/o grupo de un archivo. La tecla rápida para este comando es Ctrl-x o.[Advanced Chown]
Cambiar Dueño y Permisos

Cambiar Dueño y Permisos combina Cambiar DueñoChown y Cambiar PermisosChmod en una única ventana. Se puede así cambiar los permisos, propietario y grupo del archivo de una sola vez.[File Operations]
Operaciones con Archivos

Cuando copiamos, movemos o borramos archivos, Midnight Commander muestra el diálogo de operaciones con archivos. En él aparecen los archivos que se estén procesando y hasta tres barras de progreso. La barra de archivo indica qué parte del archivo actual va siendo copiada, la barra de contador indica cuántos de los archivos marcados han sido completados y la barra de bytes nos dice qué parte del tamaño total de archivos marcados ha sido procesado hasta el momento. Si la operación detallada está desactivada no se muestran las barras de archivo y bytes.

En la parte inferior hay dos botones. Pulsando el botón Saltar se ignorará el resto del archivo actual. Pulsando el botón Abortar se detendrá la operación y se ignora el resto de archivos.

Hay otros tres diálogos que pueden aparecer durante operaciones de archivos.

El diálogo de error informa sobre una condición de error y tiene tres posibilidades. Normalmente seleccionaremos el botón Saltar para evitar el archivo o Abortar para detener la operación. También podemos seleccionar el botón Reintentar si hemos corregido el problema desde otro terminal.

El diálogo Reemplazar aparece cuando intentamos copiar o mover un archivo sobre otro ya existente. El mensaje muestra fechas y tamaños de ambos archivos. Pulsaremos el botón Sí para sobreescribir el archivo, el botón No para saltarlo, el botón Todos para sobreescribir todos los archivos, Ninguno para no sobreescribir en ningún caso y Actualizar para sobreescribir si el archivo origen es posterior al archivo objeto. Podemos abortar toda la operación pulsando el botón Abortar.

El diálogo de eliminación recursiva aparece cuando intentamos borrar un directorio no vacío. Pulsaremos Sí para borrar el directorio recursivamente, No para saltar el directorio, Todo para borrar recursivamente todos los directorios marcados no vacíos y Ninguno para saltarlos todos. Podemos abortar toda la operación pulsando el botón Abortar. Si seleccionamos el botón Sí o Todo se nos pedirá confirmación. Diremos "sí" solo si estamos realmente seguros de que queremos una eliminación recursiva.

Si hemos marcado archivos y realizamos una operación sobre ellos, solo los archivos sobre los que la operación fue exitosa son desmarcados. Los archivos saltados y aquellos en los que la operación falló permanecen marcados.[Mask Copy/Rename]
Copiar/Renombrar con Máscara

Las operaciones de copiar/mover permiten transformar los nombres de los archivos de manera sencilla. Para ello, hay que procurar una máscara correcta para el origen y normalmente en la terminación del destino algunos caracteres comodín. Todos los archivos que concuerden con la máscara origen son copiados/renombrados según la máscara destino. Si hay archivos marcados, solo aquellos que encajen con la máscara de origen serán renombrados.

Hay otras opción que podemos seleccionar:

Seguir Enlaces indica si los enlaces simbólicos o físicos en el directorio origen (y recursivamente en sus subdirectorios) producen nuevos enlaces en el directorio destino o si queremos copiar su contenido.

Copiar Recursivamente indica qué hacer si en el directorio destino existe ya un directorio con el mismo nombre que el archivo/directorio que está siendo copiado. La acción por defecto es copiar su contenido sobre ese directorio. Habilitando esto podemos copiar el directorio de origen dentro de ese directorio. Quizás un ejemplo pueda ayudar:

Queremos copiar el contenido de un directorio denominado coco a /blas donde ya existe un directorio /blas/coco. Por defecto, mc copiaría el contenido en /blas/coco, pero con esta opción se copiaría como /blas/coco/coco.

Preservar Atributos indica que se deben conservar los permisos originales de los archivos, marcas temporales y si somos superusuario también el propietario y grupo originales. Si esta opción no está activa se aplica el valor actual de umask.

"Usando Patrones Shell activado"

Usando Patrones Shell nos permite usar los caracteres comodín '*' y '?' en la máscara de origen. Funcionará igual que en la línea de órdenes. En la máscara destino, solo están permitidos los comodines '*' y '\<número>'. El primer '*' en la máscara destino corresponde al primer grupo del comodín en la máscara de origen, el segundo '*' al segundo grupo, etcétera. El comodín '\1' corresponde al primer grupo en la máscara de origen, el comodín '\2' al segundo y así sucesivamente hasta '\9'. El comodín '\0' es el nombre completo del archivo fuente.

Dos ejemplos:

Si la máscara de origen es "*.tar.gz", el destino es "/blas/*.tgz" y el archivo a copiar es "coco.tar.gz", la copia se hará como "coco.tgz" en "/blas".

Supongamos que queremos intercambiar el nombre y la extensión de modo que "archivo.c" se convierta en "c.archivo". La máscara origen será "*.*" y la de destino "\2.\1".

"Usando Patrones Shell desactivado"

Cuando la opción de Patrones Shell está desactivada MC no realiza una agrupación automática. Deberemos usar expresiones '\(...\)' en la máscara origen para especificar el significado de los comodines en la máscara destino. Esto es más flexible pero también necesita más escritura. Por lo demás, las máscaras destino son similares al caso de Patrones Shell activos.

Dos ejemplos:

Si la máscara de origen es "^\(.*\)\.tar\.gz$", el destino es "/blas/*.tgz" y el archivo a ser copiado es "coco.tar.gz", la copia será "/blas/coco.tgz".

Si queremos intercambiar el nombre y la extensión para que "archivo.c" sea "c.archivo", la máscara de origen puede ser "^\(.*\)\.\(.*\)$" y la de destino "\2.\1".

"Capitalización"

Podemos hacer cambios entre mayúsculas y minúsculas en los nombres de archivos. Si usamos '\u' o '\l' en la máscara destino, el siguiente carácter será convertido a mayúsculas o minúsculas respectivamente.

Si usamos '\U' o '\L' en la máscara destino, los siguientes caracteres serán convertidos a mayúsculas o minúsculas respectivamente hasta encontrar '\E' o un segundo '\U' o '\L' o el fin del nombre del archivo.

'\u' y '\l' tienen prioridad sobre '\U' y '\L'.

Por ejemplo, si la máscara fuente es '*' (con Patrones Shell activo) o '^\(.*\)$' (Patrones Shell desactivado) y la máscara destino es '\L\u*' los nombres de archivos serán convertidos para que tengan su inicial en mayúscula y el resto del nombre en minúsculas.

También podemos usar '\' como carácter de escape evitando la interpretación de todos estos caracteres especiales. Por ejemplo, '\\' es una contrabarra y '\*' es un asterisco.[Select/Unselect Files]
Seleccionar/Deseleccionar Archivos

El diálogo permite seleccionar o deseleccionar grupos de archivos y directorios. La línea de entradaInput Line Keys permite introducir una expresión regular para los nombres de los archivos a seleccionar/deseleccionar.

Indicando Solo archivos los directorios no se seleccionan. Con los Caracteres Comodín habilitados, se pueden introducir expresiones regulares del tipo empleado en los patrones de nombres de la shell (poniendo * para cero o más caracteres y ? para uno o más caracteres). Si los Caracteres Comodín están deshabilitados, entonces la selección de archivos se realiza con expresiones regulares normales. Véase la página de manual de ed (1). Finalmente, si no se activa Distinguir May/min la selección se hará sin distinguir caracteres en mayúsculas o minúsculas.[Diff Viewer]
Comparador de Archivos Interno

El comparador de archivos interno permite comparar dos archivos y editarlos en el sitio quedando la comparación actualizada sobre la marcha. Se puede navegar y ver copias de trabajos desde los sistemas de control de versiones populares (GIT, Subversion, etc).

El comparador ofrece los siguientes atajos de teclado:

F1      Invoca el visor de ayuda y muestra esta sección.

F2      Guarda los archivos modificados.

F4      Edita el archivo del panel izquierdo.

F14     Edita el archivo del panel derecho.

F5      Combina el fragmento actual. Solo se combina el fragmento actual.

F7      Comenzar una búsqueda.

F17     Repetir la búsqueda previa.

F10, Esc, q
        Salir del comparador.

Alt-s, s
        Mostrar/ocultar el estado de los fragmentos.

Alt-n, l
        Mostrar/ocultar números de línea.

f       Maximizar el panel izquierdo.

=       Igualar el ancho de los paneles.

>       Reducir el panel derecho.

<       Reducir el panel izquierdo.

c       Mostrar/ocultar «^M» para los saltos de línea con carácter de retorno (CR).

2, 3, 4, 8
        Fijar ancho de tabulaciones.

Ctrl-u  Intercambia el contenido de los paneles.

Ctrl-r  Actualizar la pantalla.

Ctrl-o  Alternar con la pantalla de órdenes del sistema.

Intro, Espacio, n
        Avanzar al siguiente fragmento diferente.

Backspace, p
        Retroceder al fragmento diferente anterior.

g       Saltar a la línea indicada.

Abajo   Avanzar una línea.

Ariba   Retroceder una línea.

AvPág (Página adelante)
        Avanza una página hacia abajo.

RePág (Página atrás)
        Retrocede una página hacia arriba.

Inicio, A1
        Va al comienzo de la línea.

Fin     Va al final de la línea.

Ctrl-Inicio
        Vuelve al comienzo del archivo.

Ctrl-Fin, C1
        Avanza hasta el final del archivo.[Internal File Viewer]
Visor de Archivos Interno

El visor de archivos interno ofrece dos modos de presentación: ASCII y hexadecimal. Para alternar entre ambos modos, se emplea la tecla F4.

El visor intenta usar el mejor método disponible en el sistema, según el tipo de archivo, para mostrar información. Los archivos comprimidos se descomprimen automáticamente si los programas correspondientes (GNU gzip ó bzip2) están instalados en el sistema. El propio visor es capaz de interpretar ciertas secuencias de caracteres que se emplean para activar los atributos de negrita y subrayado, mejorando la presentación de los archivos.

En modo hexadecimal, la función de búsqueda admite texto entre comillas o valores numéricos. El texto entrecomillado se busca tal cual (retirando las comillas) y cada número se corresponde a un byte. Unos y otros se pueden entremezclar como en:

"Cadena" -1 0xBB 012 "otro texto"

Nótese que 012 es un número octal y -1 se convierte en 0xFF.

Algunos detalles internos del visualizador: En sistemas con acceso a la llamada del sistema mmap(2), el programa mapea el archivo en vez de cargarlo; si el sistema no provee de la llamada al sistema mmap(2) o el archivo realiza una acción que necesita de un filtro, entonces el visor usará sus cachés de crecimiento, cargando solo las partes del archivo a las que actualmente estamos accediendo (esto incluye a los archivos comprimidos).

He aquí una lista de las acciones asociadas a cada tecla que Midnight Commander gestiona en el visor interno de archivos.

F1 Invoca el visor de ayuda de hipertexto interno.

F2 Cambia el modo de ajuste de líneas en pantalla.


        * N. del T.: Envuelta (Ajustada), se muestra toda la información de la línea en la pantalla, de modo que si esta ocupa más del ancho de la pantalla aparece como si fuese otra línea aparte o bien desenvuelta (desajustada), truncando el contenido de la línea que sobresale de la pantalla. Este contenido puede ser consultado utilizando las teclas del cursor.

F4 Cambia entre el modo hexadecimal y el Ascii.

F5 Ir a la línea. Nos pedirá el número de línea en el que deseamos posicionarnos y mostrará el archivo a partir de esa línea.

F6, /. Búsqueda de expresión regular desde la posición actual hacia adelante.

?, Búsqueda de expresión regular desde la posición actual hacia atrás.

F7 Búsqueda normal/ búsqueda en modo hexadecimal.

Ctrl-s. Comienza una búsqueda normal si no existe una expresión de búsqueda previa si no busca la próxima coincidencia.

Ctrl-r. Comienza una búsqueda hacia atrás si no había expresión de búsqueda anterior si no busca la próxima coincidencia.

n. Buscar la próxima coincidencia.

F8 Intercambia entre el modo crudo y procesado: esto mostrará el archivo como se encuentra en disco o si se ha especificado un filtro de visualización en el archivo mc.ext.ini, entonces la salida filtrada. El modo actual es siempre el contrario al mostrado en la etiqueta del botón, en tanto que el botón muestra el modo en el que entraremos con la pulsación de esa tecla.

F9 Alterna entre la visualización con y sin formato: en el modo con formato se interpretan algunas secuencias de caracteres para mostrar texto en negrita y subrayado con diferentes colores. Como en el caso anterior, la etiqueta del botón muestra el estado contrario al actual.

F10, Esc. Sale del visor interno.

AvPág, espacio, Ctrl-v. Avanza una página hacia abajo.

RePág, Alt-v, Ctrl-b, Borrar. Retrocede una página hacia arriba.

Cursor Abajo Desplaza el texto una línea hacia arriba, mostrando en la línea inferior de la pantalla una nueva línea que antes quedaba oculta.

Cursor Arriba Desplaza una línea hacia abajo.

Ctrl-l Redibuja el contenido de la pantalla.

! Engendra un nuevo shell en el directorio de trabajo actual.

"[n] m" Coloca la marca n.

"[n] r" Salta hasta la marca n.

Ctrl-f Salta al archivo siguiente.

Ctrl-b Ídem al archivo anterior.

Alt-r Intercambia entre los diferentes modos de regla: desactivado, arriba, abajo.

Es posible adiestrar al visor de archivos sobre cómo mostrar un archivo, mírese la sección Editar Archivo de ExtensionesEdit Extension File.[Internal File Editor]
Editor de Archivos Interno

El editor de archivos interno es un editor a pantalla completa de avanzadas prestaciones. Puede editar archivos de hasta 64 MB y también permite modificar archivos binarios. Se inicia pulsando F4 supuesto que la variable use_internal_edit esté presente en el archivo de inicialización.

Las características soportadas actualmente son: copia, desplazamiento, borrado, corte, y pegado de bloques; deshacer paso a paso; menús desplegables; inserción de archivos; definición de macros; buscar y reemplazar usando expresiones regulares); selección de texto con mayúsculas-cursor (si el terminal lo soporta); alternancia insertar-sobreescribir; plegado de líneas; sangrado automático; tamaño de tabulación configurable; realce de sintaxis para varios tipos de archivos; y la opción de pasar bloques de texto por filtros externos como indent o ispell.

El editor es muy fácil de usar y no requiere aprendizaje alguno. Para conocer las teclas asignadas a cada función, basta consultar los menús correspondientes. Además, las teclas de desplazamiento con la tecla de mayúsculas seleccionan texto. Se puede seleccionar con el ratón, aunque podemos recuperar su funcionamiento habitual en terminales (copiar y pegar) manteniendo pulsada la tecla mayúsculas. Ctrl-Ins copia al archivo mcedit.clip y Mayús-Ins pega desde mcedit.clip. Mayús-Supr corta y copia en mcedit.clip, y Ctrl-Supr elimina el texto resaltado. La tecla Intro produce un salto de línea con sangrado automático opcional.

Para definir una macro, pulsar Ctrl-r y entonces teclearemos las secuencias de teclas que deseamos sean ejecutadas. Pulsaremos Ctrl-r de nuevo al finalizar. Podemos asignar la macro a la tecla que queramos pulsando sobre ella. La macro será ejecutada cuando pulsemos Ctrl-a seguido de la tecla asignada. También será ejecutada si pulsamos Meta (Alt), Ctrl, o Escape y la tecla asignada, siempre y cuando la tecla no sea usada por ninguna otra función. Una vez definida, los comandos de macro irán al archivo ~/.local/share/mc/mcedit/mcedit.macros en nuestro directorio de inicio. Podemos eliminar una macro borrando la línea adecuada en este archivo.

F19 formateará el bloque seleccionado (sea texto, código C o C++ u otro). Esto está controlado por el archivo /opt/share/mc/edit.indent.rc que se copia la primera vez que se usa en ~/.local/share/mc/mcedit/edit.indent.rc en el directorio personal.

El editor también visualiza caracteres no estadounidenses (160+). Al editar archivos binarios, debemos configurar los bits de pantalla a 7 bits en el menú de opciones para mantener el espaciado saneado.[Completion]
Terminación

Permite a Midnight Commander escribir por nosotros.

Intenta completar el texto escrito antes de la posición actual. Midnight Commander intenta la terminación tratando el texto como si fuera una variable (si el texto comienza con $), nombre de usuario (si el texto empieza por ~), nombre de máquina (si el texto comienza con @) o un comando (si estamos en la línea de órdenes en una posición donde podríamos escribir un comando; las terminaciones posibles entonces incluyen las palabras reservadas del shell así como comandos internos del shell) en ese orden. Si nada de lo anterior es aplicable, se intenta la terminación con nombres de archivo.

La terminación de nombres de archivo, usuario y máquina funciona en todas las líneas de entrada; la terminación de comandos es específica de la línea de órdenes. Si la terminación es ambigua (hay varias posibilidades diferentes), Midnight Commander pita, y la acción siguiente depende de la opción Completar: Mostrar Todos en el diálogo de ConfiguraciónConfiguration. Si está activada, se despliega inmediatamente junto a la posición actual una lista con todas las posibilidades donde se puede seleccionar con las flechas de movimiento e Intro la entrada correcta. También podemos seguir escribiendo caracteres con lo que la línea se sigue completando tanto como sea posible y simultáneamente la primera entrada coincidente de la lista se va resaltando. Si volvemos a pulsar Alt-Tab, solo las coincidencias permanecen en la lista. Tan pronto como no haya ambigüedad, la lista desaparece; también podemos quitarla con las teclas de cancelación Esc, F10 y las teclas de movimiento a izquierda y derecha. Si Completar: Mostrar TodosConfiguration está desactivado, la lista aparece cuando pulsamos Alt-Tab por segunda vez; con la primera Midnight Commander solo emite un pitido.

Aplica escapes a los símbolos ?, * y & (como \?, \*, \& ) en los nombres de archivo para evitar su interpretación en expresiones regulares al realizar sustituciones en la línea de entrada.[Virtual File System]
Sistemas de Archivos Virtuales (VFS)

Midnight Commander dispone de una capa de código de acceso al sistema de archivos; esta capa se denomina Sistema de Archivos Virtual (VFS). El Sistema de Archivos Virtual permite a Midnight Commander manipular archivos no ubicados en el sistema de archivos Unix.

Midnight Commander incluye actualmente varios Sistemas de Archivos Virtuales: el sistema de archivos local, utilizado para acceder al sistema de archivos Unix habitual; tarfs para manipular archivos empaquetados con el comando tar y acaso comprimidos; undelfs para recuperar archivos borrados en sistemas de archivos de tipo ext2 (sistema de archivos habitual en Linux); ftpfs para manipular archivos en sistemas remotos a través de FTP; fish para manipular archivos a través de conexiones a shell como rsh o ssh.

Dependiendo de la forma en que fue compilado, puede disponer también de: sftpfs para manipular archivos en sistemas remotos a través de SFTP.

Se facilita también un sistema de archivos genérico extfs (EXternal virtual File System) para extender con facilidad las posibilidades de VFS empleando guiones y programas externos.

El código VFS interpretará todos los nombres de ruta usados y los dirigirá al sistema de archivos correcto. El formato usado para cada uno de los sistemas de archivos se describe más adelante en su propia sección.[Tar File System]
Sistema de archivos Tar (tarfs)

El sistema de archivos tar y los archivos tar comprimidos pueden consultarse usando el comando chdir. Para mostrar en el panel el contenido de un archivo tar, cambiamos de directorio empleando la siguiente sintaxis:

/archivo.tar/utar://[directorio-dentro-tar]

El archivo mc.ext.ini también ofrece un atajo para los archivos tar, esto quiere decir que normalmente basta con apuntar a un archivo tar y pulsar Intro para entrar en el archivo tar. Véase la sección Edición del Archivo de ExtensionesEdit Extension File para obtener más detalles sobre cómo hacer esto.

Ejemplos:

    mc-3.0.tar.gz/utar://mc-3.0/vfs
    /ftp/GCC/gcc-2.7.0.tar/utar://

En este último se indica la ruta completa hasta el archivo tar.[FTP File System]
Sistema de archivos FTP

FTPfs permite manipular archivos en máquinas remotas. Para utilizarlo se puede emplear la opción de menú Conexión por FTP o simplemente emplear la orden cd como cuando cambiamos habitualmente de directorio, pero indicando como ruta:

ftp://[!][usuario[:clave]@]maquina[:puerto][dir-remoto]

Los elementos usuario, puerto y directorio-remoto son opcionales. Si especificamos el elemento usuario, entonces Midnight Commander intentará conectarse con la máquina remota como ese usuario, y si no, establecerá una conexión en modo anónimo o con el nombre de usuario indicado en el archivo ~/.netrc. El elemento clave también es opcional, y si está presente, se emplea como contraseña de acceso. Esta forma de colocar la contraseña como parte del nombre del directorio virtual no es muy recomendable porque eventualmente puede aparecer en pantalla y guardarse en el histórico de directorios.

Si es necesario utilizar un proxy de FTP, se añade un símbolo de exclamación ! delante del nombre de la máquina.

Ejemplos:

    ftp://ftp.nuclecu.unam.mx/linux/local
    ftp://tsx-11.mit.edu/pub/linux/packages
    ftp://!detras.barrera.edu/pub
    ftp://guest@pcremoto.com:40/pub
    ftp://miguel:xxx@servidor/pub
    ftp://ftp.um.es/pub

La opciones de FTPfs se encuentran entre las opciones de configuración del Sistema de Archivos Virtual (VFS)Virtual FS.[FIle transfer over SHell filesystem]
Sistema de archivos a través de SHell

El FISH es un sistema de archivos por red que permite manipular archivos en una máquina remota como si estuvieran almacenados localmente. Para ello es preciso que el sistema remoto esté ejecutando el servidor FISH o permitir la conexión a una shell de tipo bash.

Para conectar con la máquina remota basta cambiar de directorio a un directorio virtual cuyo nombre sea de la forma:

sh://[usuario@]maquina[:opciones]/[directorio-remoto]

Los elementos usuario, opciones y directorio-remoto son opcionales. Si se especifica el elemento usuario Midnight Commander intentará entrar en la máquina remota como ese usuario, y si no usará nuestro nombre.

Como opciones se puede poner 'C' para usar compresión y 'r' para utilizar una conexión rsh en vez de ssh. Si se indica el directorio-remoto, se buscará este como primer directorio al conectar con la máquina remota.

Ejemplos:

    sh://solorsh.es:r/linux/local
    sh://pepe@quiero.comprension.edu:C/privado
    sh://pepe@sincomprimir.ssh.edu/privado
[SFTP (SSH File Transfer Protocol) filesystem]
Sistema de archivos SFTP (FTP sobre SSH)

El sistema de archivos SFTP es un sistema de archivos sobre red que permite manipular archivos en una máquina remota como si fueran locales.

Para conectar con la máquina remota basta cambiar de directorio a un directorio virtual cuyo nombre sea de la forma:

sftp://[usuario@]maquina:[puerto]/[directorio-remoto]

Los elementos usuario, puerto y directorio-remoto son opcionales. Si se especifica el elemento usuario Midnight Commander intentará acceder a la máquina remota como ese usuario, y si no usará nuestro nombre. El puerto indica el puerto utilizado por el servidor remoto, por defecto 22. El directorio-remoto será el directorio actual tras la conexión.

Ejemplos:

    sftp://solorsh.es/linux/local
    sftp://pepe:k1abe@quiero.comprension.edu/privado
    sftp://pepe@sincomprimir.ssh.edu/privado
    sftp://pepe@maquina.ssh.edu:2222/privado
[Undelete File System]
Sistema de archivos de Recuperación

En sistemas Linux, si el programa de configuración nos preguntó si queríamos usar las facilidades de recuperación de archivos de ext2fs, tendremos el sistema de archivos recuperables accesible. La recuperación de archivos borrados está disponible solo en los sistemas de archivos ext2. El sistema de archivos recuperable es solo un interface de la librería ext2fs con: restaurar todos los archivos borrados en un ext2fs y proporciona la extracción selectiva de archivos en una partición regular.

Para usar este sistema de archivos, tendremos que hacer un chdir a un nombre de archivo especial formado por el prefijo "/undel://" y el nombre de archivo donde se encuentra el sistema de archivos actual.

Por ejemplo, para recuperar archivos borrados en la segunda partición del primer disco scsi en Linux, usaríamos el siguiente nombre de ruta:

    undel://sda2

Esto le llevaría un tiempo a undelfs para cargar la información antes de empezar a navegar por los archivos allí contenidos.[EXTernal File System]
Sistema de archivos EXTerno (extfs)

extfs permite incorporar a GNU Midnight Commander numerosas utilidades y tipos de archivos de manera sencilla, simplemente escribiendo guiones (scripts).

Los sistemas de archivos Extfs son de dos tipos:

1. Sistemas de archivos autónomos, que no están asociados a ningún archivo existente. Representan algún tipo de información relacionada con el sistema en forma de árbol de directorios. Se accede a ellos ejecutando 'cd nombrefs://' donde nombrefs es el nombre corto que identifica el extfs (ver más adelante). Ejemplos de estos son audio (lista de pistas de sonido en el CD) o apt (lista de paquetes de tipo Debian en el sistema).

Por ejemplo, para listar las pistas de música del CD, escribir

  cd audio://

2. Sistemas de archivos en un archivo (como rpm, patchfs y más), que muestran los contenidos de un archivo en forma de árbol de directorios. Puede tratarse de archivos reales empaquetados o comprimidos en un archivo (urar, rpm) o archivos virtuales, como puede ser el caso de mensajes en un archivo de correo electrónico (mailfs) o partes de un archivo de modificaciones o parches (patchfs). Para acceder a ellos se añade 'nombrefs://' al nombre del archivo a abrir. Este archivo podría él mismo estar en otro sistema de archivos virtual.

Por ejemplo, para listar los contenidos de un archivo documentos.zip comprimido hay que escribir

  cd documentos.zip/uzip://

En muchos aspectos, se puede tratar un sistema de archivos externo como cualquier otro directorio. Podríamos añadirlo a la lista de favoritos o cambiar a él desde la historia de directorios. Una limitación importante es que, estando dentro de él, no se puede ejecutar órdenes del sistema, como por otra parte ocurre en cualquier sistema de archivos VFS no local.

Midnigth Commander incluye inicialmente guiones para algunos sistemas de archivos externos:

a       acceder a un disquete DOS/Windows 'A:' (cd a://).

apt     monitor del sistema de gestión de paquetes APT de Debian (cd apt://).

audio   acceso y audición de CDs (cd audio:// o cd dispositivo/audio://).

bpp     paquete de la distribución GNU/Linux Bad Penguin (cd archivo.bpp/bpp://).

deb     paquete de la distribución GNU/Linux Debian (cd archivo.deb/deb://).

dpkg    paquetes instalados en Debian GNU/Linux (cd deb://).

hp48    ver o copiar archivos a/desde una calculadora HP48 (cd hp48://).

lslR    navegación en listados lslR empleados en bastantes sitios FTP (cd filename/lslR://).

mailfs  soporte para archivos de correo electrónico tipo mbox (cd archivo_mbox/mailfs://).

patchfs manipulación de archivos de cambios/parches tipo diff (cd archivo/patchfs://).

rpm     paquete RPM (cd archivo/rpm://).

rpms    base de datos de paquetes RPM instalados (cd rpms://).

ulha, urar, uzip, uzoo, uar, uha
        herramientas de compresión (cd archivo/xxxx:// siendo xxxx uno de estos: ulha, urar, uzip, uzoo, uar, uha).

Se pueden asociar extensiones o tipos de archivo a un determinado sistema de archivos externo tal como se describe en la sección sobre cómo Editar el Archivo de ExtensionesEdit Extension File de Midnight Commander. He aquí, a modo de ejemplo, una entrada para paquetes Debian:

  regex/.deb$
          Open=%cd %p/deb://
[Colors]
Colores

Midnight Commander intentará determinar si nuestro terminal soporta el uso de color utilizando la base de datos de terminales y nuestro nombre de terminal. Algunas veces estará confundido, por lo que deberemos forzar el modo en color o deshabilitar el modo de color usando el argumento -c y -b respectivamente.

Si el programa está compilado con el gestor pantallas S-Lang en lugar de ncurses, también chequeará la variable COLORTERM, si existe, lo que tiene el mismo efecto que la opción -c.

Podemos especificar a los terminales que siempre fuercen el modo en color añadiendo la variable color_terminals a la sección Colors del archivo de inicialización. Esto evitará que Midnight Commander intente la detección de soporte de color. Ejemplo:

[Colors]
color_terminals=linux,xterm
color_terminals=nombre-terminal1,nombre-terminal2...

El programa puede compilarse con ncurses y S-Lang, ncurses no ofrece la posibilidad de forzar el modo en color: ncurses utiliza la información de la base de datos de terminales.

Midnight Commander ofrece una forma de cambiar los colores por defecto. Actualmente los colores se configuran a través de la variable de entorno MC_COLOR_TABLE o en la sección Colors del archivo de inicialización.

En la sección Colors, el mapa de colores por defecto se carga desde la variable base_color. Podemos especificar un mapa de colores alternativo para un terminal utilizando el nombre del terminal como clave en esta sección. Ejemplo:

[Colors]
base_color=
xterm=menu=magenta:marked=,magenta:markselect=,red

El formato de la definición de color es:

  <PalabraClave>=<ColorTexto>,<ColorFondo>:<PalabraClave>= ...

los colores son opcionales, y las palabras claves son: normal, selected, disabled, marked, markselect, errors, input, inputmark, inputunchanged, commandlinemark, reverse, gauge, header, inputhistory, commandhistory; los colores de la barra de botones: bbarhotkey, bbarbutton; los colores de la barra de estado: statusbar; los colores de menú: menunormal, menusel, menuhot, menuhotsel, menuinactive; los colores de los diálogos: dnormal, dfocus, dhotnormal, dhotfocus, dtitle; los colores de los diálogos de error: errdfocus, errdhotnormal, errdhotfocus, errdtitle; los colores de la ayuda: helpnormal, helpitalic, helpbold, helplink, helpslink, helptitle; los colores del visor: viewnormal, viewbold, viewunderline, viewselected; loc colores del editor: editnormal, editbold, editmarked, editwhitespace, editnonprintable, editlinestate; los colores de los menús desplegables: pmenunormal, pmenusel, pmenutitle.

header determina el color del encabezado de los paneles, la línea con los títulos de columna y el modo de ordenación.

input determina el color de las líneas de entrada de texto en los diálogos.

gauge (indicador) determina el color de la parte completada de la barra de progresión (gauge), que muestra qué porcentaje de archivos fueron copiados etc. de modo gráfico.

disabled detemina el color de los componentes inactivos.

Los cuadros de diálogo usan los siguientes colores: dnormal usado para el texto normal, dfocus usado para el componente actualmente seleccionado, dhotnormal usado para diferenciar el color de la tecla activa en los componentes normales, mientras que el color dhotfocus se utiliza para el color resaltado en el componente seleccionado.

Los menús utilizan el mismo esquema equivalente con los nombres menunormal, menusel, menuhot, menuhotsel and menuinactive en lugar de los anteriores.

La ayuda utiliza los siguientes colores: helpnormal texto normal, helpitalic utilizado para el texto enfatizado con letra itálica en la página del manual, helpbold usado para el texto enfatizado en negrita en la página del manual, helplink usado para los hiperenlaces no seleccionados y helpslink es utilizado para el hiperenlace seleccionado.

En los menús desplegables: pmenunormal se usa como color del fondo y de los elementos no seleccionados, menusel se usa para el elemento seleccionado, pmenutitle se usa para el titulo del menú.

Los colores posibles son: negro (black), gris (gray), rojo (red), rojo brillante (brightred), verde (green), verde claro (brightgreen), marrón (brown), amarillo (yellow), azul oscuro (blue), azul brillante (brightblue), rosa (magenta), rosa claro (brightmagenta), azul celeste (cyan), celeste claro (brightcyan), gris claro (lightgray) y blanco (white). Hay una palabra clave especial para obtener un fondo transparente. Se trata de 'default'. 'default' solo se puede utilizar como color de fondo. Otra palabra especial es 'base' que hace referencia a los colores generales. Cuando se puede disponer de 256 colores se pueden referir como color16 hasta color255. Ejemplo:

[Colors]
base_color=normal=white,default:marked=magenta,default
[Skins]
Skins

Con los «skins» (pieles, caretas) se puede cambiar la apariencia global de Midnight Commander. Para ello hay que proporcionar un archivo que contenga descripciones de colores y formas de trazar las líneas de borde de los paneles y diálogos. La redefinición de colores es completamente compatible con la configuración tradicional detallada en la sección sobre ColoresColors.

El archivo se busca, en orden, de varias maneras:

        1) La opción -S <skin> o --skin=<skin> al ejecutar mc.
        2) La variable de entorno MC_SKIN.
        3) El parámetro skin en la sección [Midnight-Commander] del archivo de configuración.
        4) El archivo /opt/etc/mc/skins/default.ini.
        5) El archivo /opt/share/mc/skins/default.ini.

En línea de órdenes, en la variable de entorno o el parámetro de la configuración pueden contener la ruta absoluta al archivo de skin con o sin su extensión .ini. De no indicar la ruta se realiza la búsqueda, en orden, en:

        1) ~/.local/share/mc/skins/.
        2) /opt/etc/mc/skins/.
        3) /opt/share/mc/skins/.

Para más información consultar:

        Descripción de secciones y parámetrosSkins sections
        Definiciones de pares de coloresSkins colors
        Trazado de líneasSkins lines
        CompatibilidadSkins oldcolors
[Skins sections]
Descripción de secciones y parámetros

La sección [skin] contiene metadatos del archivo. El parámetro description proporciona un pequeño texto descriptivo.

La sección [filehighlight] contiene descripciones de pares de colores para el resaltado de nombres de archivo. Los nombres de parámetros de esta sección tienen que coincidir con los nombres de sección del archivo filehighlight.ini. Para más información, véase la sección sobre Resaltado de nombresFilenames Highlight.

La sección [core] permite definir elementos que se utilizan en otras partes.

_default_
        Colores por defecto. Se utilizará en todas las secciones que no contengan definición de colores.

selected
        cursor.

marked  elementos seleccionados.

markselect
        cursor sobre elementos seleccionados.

gauge   color de la parte completada en las barras de progreso.

input   color de los recuadros de texto editable en los dialogos.

inputmark
        color de los textos editables en los dialogos.

inputunchanged
        color original de los textos editables antes de tocarlos.

commandlinemark
        color del texto seleccionado en la línea de órdenes.

reverse color inverso.

La sección [dialog] define elementos de las ventanas de diálogo salvo los diálogos de error.

_default_
        Colores por defecto para esta sección. Se utilizará [core]._default_ si no se especifica

dfocus  Color del elemento activo, con el foco.

dhotnormal
        Color de las teclas de acceso rápido.

dhotfocus
        Color de las teclas de acceso rápido del elemento activo.

La sección [error] define elementos de las ventanas de diálogo de error.

_default_
        Colores por defecto para esta sección. Se utilizará [core]._default_ si no se especifica.

errdhotnormal
        Color de las teclas de acceso rápido.

errdhotfocus
        Color de las teclas de acceso rápido del elemento activo.

La sección [menu] define elementos de menú. Esta sección afecta al menú general (activado con F9) y a los menús de usuario (activados con F2 en la pantalla general y con F11 en el editor).

_default_
        Colores por defecto para esta sección. Se utilizará [core]._default_ si no se especifica

entry   Color de las entradas de menú.

menuhot Color de las teclas de acceso rápido en menú.

menusel Color de la entrada de menú activa, con el foco.

menuhotsel
        Color de las teclas de acceso rápido en la entrada activa de menú.

menuinactive
        Color de menú inactiva.

La sección [help] define los elementos de la ventana de ayuda.

_default_
        Colores por defecto para esta sección. Se utilizará [core]._default_ si no se especifica.

helpitalic
        Par de color para elementos en cursiva.

helpbold
        Par de color para elementos resaltados.

helplink
        Color de los enlaces

helpslink
        Color del enlace activo, con el foco.

La sección [editor] define los colores de los elementos que se encuentran en el editor.

_default_
        Colores por defecto para esta sección. Se utilizará [core]._default_ si no se especifica.

editbold
        Par de color para elementos resaltados.

editmarked
        Color del texto seleccionado.

editwhitespace
        Color de las tabulaciones y espacios al final de línea resaltados.

editlinestate
        Color de la línea de estado.

La sección [viewer] define los colores de los elementos que se encuentran en el visor.

viewunderline
        Par de color para elementos subrayados.[Skins colors]
Definiciones de pares de colores

Cualquier parámetro del archivo de skin puede contener definiciones de pares de color.

Un par de colores está formado por el nombre de los dos colores separados por ';'. El primer color establece el color de frente y el segundo el color de fondo. Se puede omitir alguno de los dos colores, en cuyo caso se utilizará el color del par de color por defecto (par de color general o del par de color por defecto en la sección).

Ejemplo:
[core]
    # verde sobre negro
    _default_=green;black
    # verde (por defecto) sobre azul
    selected=;blue
    # amarillo sobre negro (por defecto)
    marked=yellow;

Los nombres de colores permitidos son los que aparecen en la sección ColoresColors.[Skins lines]
Trazado de líneas

Trazos de líneas de la sección [Lines] del archivo de skins. Por defecto se utilizan líneas sencillas, pero se pueden redefinir empleando cualquier símbolo utf-8 (por ejemplo, líneas dobles).

¡¡¡ATENCIÓN!!! Si se compila Midnight Commander empleando la biblioteca de pantalla ncurses, entonces el trazado de líneas está limitado. Es posible que solo se puedan utilizar líneas simples. Para consultas y comentarios contactar con los desarrolladores de ncurses.

Descripción de parámetros de la sección [Lines]:

lefttop esquina superior izquierda.

righttop
        esquina superior derecha.

centertop
        unión central en el borde superior.

centerbottom
        unión central en el borde inferior.

leftbottom
        esquina inferior izquierda.

rightbottom
        esquina inferior derecha.

leftmiddle
        unión central en el borde izquierdo.

rightmiddle
        unión central en el borde derecho.

centermiddle
        cruz central.

horiz   línea horizontal.

vert    línea vertical.

thinhoriz
        línea horizontal fina.

thinvert
        línea vertical fina.[Skins oldcolors]
Compatibilidad

Compatibilidad de la asignación de colores empleando archivos de skin con la configuración general de ColoresColors.

La compatibilidad es completa. En este caso la redefinición de colores tiene prioridad sobre las definiciones de skin y se completa con esta.[Filenames Highlight]
Resaltado de nombres

La sección [filehighlight] de un archivo de skin contiene como claves los nombres que identificarán cada grupo de resaltado y como valor el par de colores que le corresponda. El formato de estas parejas se explica en la sección SkinsSkins.

Las reglas de resaltado de nombres en el archivo se encuentran en /opt/share/mc/filehighlight.ini. Los nombres de sección en este archivo tienen que ser iguales a los nombres empleados en la sección [filehighlight] del archivo de skin en uso. PP. Los nombres de los parámetros en estos grupos podrán ser:

type    tipo de archivo. Si existe se ignoran otras opciones.

regexp  expresión regular. Si existe se ignora la opción 'extensions'.

extensions
        lista de extensiones de archivos. Separadas por punto y coma.

extensions_case
        hace la regla 'extensions' sensible o no a mayúsculas (true o false).

`type' puede tomar los valores:
- FILE (todos los archivos)
  - FILE_EXE
- DIR (todos los directorios)
  - LINK_DIR
- LINK (todos los enlaces excepto los rotos)
  - HARDLINK
  - SYMLINK
- STALE_LINK
- DEVICE (todos los archivos de dispositivo)
  - DEVICE_BLOCK
  - DEVICE_CHAR
- SPECIAL (todos los archivos especiales)
  - SPECIAL_SOCKET
  - SPECIAL_FIFO
  - SPECIAL_DOOR
[Special Settings]
Ajustes Especiales

La mayoría de las opciones de Midnight Commander pueden cambiarse desde los menús. Sin embargo, hay un pequeño número de ajustes para los que es necesario editar el archivo de configuración.

Estas variables se pueden cambiar en nuestro archivo ~/.config/mc/ini:

clear_before_exec
        Por defecto Midnight Commander limpia la pantalla antes de ejecutar un comando. Si preferimos ver la salida del comando en la parte inferior de la pantalla, editaremos nuestro archivo ~/mc.ini y cambiaremos el valor del campo clear_before_exec a 0.

confirm_view_dir
        Al pulsar F3 en un directorio, normalmente Midnight Commander entra en ese directorio. Si este valor está a 1, entonces el programa nos pedirá confirmación antes de cambiar el directorio si tenemos archivos marcados.

ftpfs_retry_seconds
        Este valor es el número de segundos que Midnight Commander esperará antes de intentar volver a conectar con un servidor de ftp que ha denegado el acceso. Si el valor es cero, el programa no reintentará el acceso.

max_dirt_limit
        Especifica cuántas actualizaciones de pantalla pueden saltarse al menos en el visor de archivos interno. Normalmente este valor no es significativo, porque el código automáticamente ajusta el número de actualizaciones a saltar de acuerdo al volumen de pulsaciones de teclas recibidas. Empero, en máquinas muy lentas o en terminales con autorepetición de teclado rápida, un valor grande puede hacer que la pantalla se actualice dando saltos.

        Parece ser que poniendo max_dirt_limit a 10 produce el mejor comportamiento, y este es el valor por defecto.

mouse_move_pages_viewer
        Controla cuándo el desplazamiento de pantalla realizado con el ratón se realiza por páginas o línea a línea en el visor de archivos interno.

only_leading_plus_minus
        Produce un tratamiento especial para '+', '-', '*' en la línea de órdenes (seleccionar, deseleccionar, selección inversa) solo si la línea de órdenes está vacía. No necesitamos entrecomillar estos caracteres en la línea de órdenes. Pero no podremos cambiar la selección cuando la línea de órdenes no esté vacía.

show_output_starts_shell
        Esta variable solo funciona si no se utiliza el soporte de subshell. Cuando utilizamos la combinación Ctrl-o para volver a la pantalla de usuario, si está activada, tendremos un nuevo shell. De otro modo, pulsando cualquier tecla nos devolverá a Midnight Commander.

timeformat_recent
        Cambiar el formato de fecha y hora empleado para fechas dentro de los seis últimos meses. Véanse las páginas de manual de strftime o date para la descripción del formato a emplear. Sin esta opción se emplea el formato por defecto.

timeformat_old
        Cambiar el formato de fecha y hora empleado para fechas más antiguas que seis meses. Véanse las páginas de manual de strftime o date para la descripción del formato a emplear. Sin esta opción se emplea el formato por defecto.

torben_fj_mode
        Si este modificador existe, entonces las teclas Inicio y Fin funcionarán de manera diferente en los paneles, en lugar de mover la selección al primer o último archivo en los paneles, actuarán como sigue:

        La tecla Inicio: Irá a la línea central del panel, si está bajo ella; sino va a la primera línea a menos que ya esté allí, en este caso irá al primer archivo del panel.

        La tecla Fin tiene un comportamiento similar: Irá a la línea central del panel, si está situada en la mitad superior del panel; si no irá a la línea inferior del panel a menos que ya estemos ahí, en cuyo caso moverá la selección al último nombre de archivo del panel.

use_file_to_guess_type
        Si esta variable está activada (por defecto lo está) se recurrirá al comando «file» para reconocer los tipos de archivo referidos en el archivo mc.ext.iniEdit Extension File.

xtree_mode
        Si esta variable está activada (por defecto no) cuando naveguemos por el sistema de archivos en un panel en árbol, se irá actualizando automáticamente el otro panel con los contenidos del directorio seleccionado en cada momento.

fish_directory_timeout
        Tiempo de vida por defecto de la caché de directorio. El valor por defecto de 900 segundos.

clipboard_store
        Ruta de acceso y opciones a una utilidad de portapapeles externa como 'xclip' para cargar texto de un archivo como selección en X Window. Por ejemplo:

clipboard_store=/usr/bin/xclip -i

clipboard_paste
        Ruta de acceso y opciones a una utilidad de portapapeles externa como 'xclip' para volcar la selección de X Window a la salida estándar. Por ejemplo:

clipboard_paste=/usr/bin/xclip -o

autodetect_codeset
        Esta opción permite emplear la orden 'enca' para autodetectar el juego de caracteres de los archivos de texto para el visor y el editor interno. La lista de valores posibles se puede obtener con `enca --list languages | cut -d : -f1'. Esta opción tiene que estar dentro de la sección [Misc].

For example:

autodetect_codeset=russian
[Parameters for external editor or viewer]
Parámetros para editor o visor externo

Midnight Commander permite especificar opciones para editores y visores externos. Midnight Commander busca la sección [External editor or viewer parameters] en el archivo de inicialización del sistema /opt/share/mc/mc.lib o en el del usuario ~/.config/mc/ini. El nombre de la opción debe coincidir con el nombre (ruta completa) del editor o visor externo. Su valor puede contener las siguientes variables:

%filename
        El nombre del archivo a editar/ver.

%lineno La línea de comienzo donde abrir el archivo.

Por ejemplo:

[External editor or viewer parameters]
    vi=%filename +%lineno
    joe=%filename +%lineno
    more=%filename +%lineno

La línea de comienzo solo se pasa al editor o visor externo cuando se llama desde la ventana de resultados de buscar archivoFind File.

Si el editor o visor externo se lanza mediante las teclas F3/F4, MC confía en que el programa (al menos «joe», pero puede que otros también) se comporte abriendo por defecto el archivo donde se abrió la última vez. MC no evita que el editor o visor externo pueda guardar y restaurar posiciones en los archivos abiertos.[Terminal databases]
Ajustes del Terminal

Midnight Commander permite hacer ajustes a la base de datos de terminales del sistema sin necesidad de privilegios de superusuario. El programa busca definiciones de teclas en el archivo de inicialización del sistema /opt/share/mc/mc.lib o en el del usuario ~/.config/mc/ini, en la sección "terminal:nuestro-terminal" y si no en "terminal:general". Cada línea comienza con el identificador de la tecla, seguido de un signo de igual y la definición de la tecla. Para representar el carácter de escape se utiliza \e y ^x para el carácter control-x.

Los identificadores de tecla son:

f0 a f20      teclas de función f0 a f20
bs            tecla de borrado
home          tecla de inicio
end           tecla de fin
up            tecla de cursor arriba
down          tecla de cursor abajo
left          tecla de cursor izquierda
right         tecla de cursor derecha
pgdn          tecla de avance de página
pgup          tecla de retroceso de página
insert        tecla de insertar
delete        tecla de suprimir
complete      tecla para completar

Ejemplo: para indicar que la secuencia Escape + [ + O + p corresponde a la tecla de insertar, hay que colocar en el archivo ~/.config/mc/ini:

insert=\e[Op

También se pueden usar secuencias avanzadas. Por ejemplo:
    ctrl-alt-right=\e[[1;6C
    ctrl-alt-left=\e[[1;6D

Esto significa que Ctrl + Alt + Izquierda envía la secuencia de escape \e[[1;6D y que entonces Midnight Commander debe interpretar "\e[[1;6D" como Ctrl-Alt-Izquierda.

El identificador complete representa la secuencia usada para invocar el mecanismo de completar nombres. Esto se hace habitualmente con Alt-Tab, pero podemos configurar otras teclas para esta función, especialmente en teclados que incorporan tantas teclas especiales (bonitas pero inútiles o infrautilizadas).

[FILES]
ARCHIVOS AUXILIARES

Los directorios indicados a continuación pueden variar de una instalación a otra. También se pueden modificar con la variable de entorno MC_DATADIR, que de estar definida se emplearía en vez de /opt/share/mc.

/opt/share/mc/help/mc.hlp

        Archivo de ayuda.

/opt/share/mc/mc.ext.ini

        Archivo de extensiones por defecto del sistema.

~/.config/mc/mc.ext.ini

        Archivo de usuario de extensiones y configuración de visor y editor. Si está presente prevalece sobre el contenido de los archivos del sistema.

/opt/share/mc/mc.ini

        Archivo de configuración del sistema para Midnight Commander, solo si el usuario no dispone de su propio ~/.config/mc/ini.

/opt/share/mc/mc.lib

        Opciones globales de Midnight Commander. Se aplican siempre a todos los usuarios, tengan ~/.config/mc/ini o no. Actualmente solo se emplea para los ajustes de terminalTerminal databases.

~/.config/mc/ini

        Configuración personal del usuario. Si este archivo está presente entonces se cargará la configuración desde aquí en lugar de desde el archivo de configuración del sistema.

/opt/share/mc/hints/mc.hint

        Este archivo contiene los mensajes cortos de ayuda mostrados por el programa.

/opt/share/mc/mc.menu

        Este archivo contiene el menú de aplicaciones por defecto para el sistema.

~/.config/mc/menu

        Menú de aplicaciones personal del usuario. Si está presente será utilizado en lugar del menú por defecto del sistema.

~/.cache/mc/Tree

        La lista de directorios para el árbol de directorios y la vista en árbol.

./.mc.menu

        Menú local definido por el usuario. Si este archivo está presente será usado en lugar del menú de aplicaciones personal o de sistema.

Para cambiar el directorio de incio de MC se puede utilizar la variable de entorno MC_PROFILE_ROOT. El valor de MC_PROFILE_ROOT tiene que ser una ruta absoluta. Si MC_PROFILE_ROOT no existe o está vacía se usa la variable HOME. Si HOME no existe o está vacía se recurre a la biblioteca GLib para obtener los directorios de MC.[AVAILABILITY]
DISPONIBILIDAD

La última versión de este programa se puede encontrar en http://ftp.midnight-commander.org/.[SEE ALSO]
VÉASE TAMBIÉN

mcedit(1), sh(1), bash(1), tcsh(1), zsh(1), ed(1), view(1), terminfo(1), gpm(1).

La página web de Midnight Commander está en:
	https://www.midnight-commander.org/

La presente documentación recoge información relativa a la versión 4.8 (mayo de 2015). Esta traducción no está completamente actualizada con la versión original en inglés. Para acceder a información sobre versiones recientes consultar la página de manual en inglés que contiene información más completa y actualizada. Para ver el susodicho manual original ejecutar en la línea de órdenes:
        LANG= LC_ALL= man mc
[AUTHORS]
AUTORES

Los autores y contribuciones se recogen en el archivo AUTHORS de la distribución.[BUGS]
ERRORES

Véase el archivo "TODO" en la distribución para saber qué falta por hacer.

Para informar de problemas con el programa, introducir una nueva incidencia en https://www.midnight-commander.org/.

Se debe proporcionar una descripción detallada del problema, la versión del programa (que se obtiene con 'mc -V') y el sistema operativo utilizados. Si el programa «revienta», sería también útil disponer del estado de la pila.[TRANSLATION]
TRADUCCIÓN

Francisco Gabriel Aroca, 1998. Reformateado y actualizado por David Martín, 2002-2015.

Midnight Commander traducido a castellano por David Martín.

[main]
 lqwqk     k           k     
 x x x .   x     .     x     
 x x x k lqu wqk k lqw tqk n 
 x x x x x x x x x x x x x x 
 v   v v mqv v v v mqu v v mj
     qqqqqqCommanderqj 

Esta es la pantalla principal de ayuda de GNU Midnight Commander.

Puede pulsar la tecla «Intro»How to use help para aprender a navegar por el sistema de ayuda, o acceder directamente a los contenidosContents.

GNU Midnight Commander es obra de sus autoresAUTHORS.

GNU Midnight Commander NO INCLUYE NINGÚN TIPO DE GARANTÍAWarranty. Es un producto de software libre, y su redistribución es bienvenida en los términos y condiciones establecidas por la Licencia Pública General de GNU (GPL)Licencia GNU, de la que existe una traducción no oficial al españolLicencia GNU (Español).

[Licencia GNU]

                    GNU GENERAL PUBLIC LICENSE
                      Version 3, 29 June 2007

Copyright © 2007 Free Software Foundation, Inc. <http://fsf.org/>

Everyone is permitted to copy and distribute verbatim copies  of this license document, but changing it is not allowed.

                            Preamble

The GNU General Public License is a free, copyleft license for software and other kinds of works.

The licenses for most software and other practical works are designed to take away your freedom to share and change the works.  By contrast, the GNU General Public License is intended to guarantee your freedom to share and change all versions of a program--to make sure it remains free software for all its users.  We, the Free Software Foundation, use the GNU General Public License for most of our software; it applies also to any other work released this way by its authors.  You can apply it to your programs, too.

When we speak of free software, we are referring to freedom, not price.  Our General Public Licenses are designed to make sure that you have the freedom to distribute copies of free software (and charge for them if you wish), that you receive source code or can get it if you want it, that you can change the software or use pieces of it in new free programs, and that you know you can do these things.

To protect your rights, we need to prevent others from denying you these rights or asking you to surrender the rights.  Therefore, you have certain responsibilities if you distribute copies of the software, or if you modify it: responsibilities to respect the freedom of others.

For example, if you distribute copies of such a program, whether gratis or for a fee, you must pass on to the recipients the same freedoms that you received.  You must make sure that they, too, receive or can get the source code.  And you must show them these terms so they know their rights.

Developers that use the GNU GPL protect your rights with two steps: (1) assert copyright on the software, and (2) offer you this License giving you legal permission to copy, distribute and/or modify it.

For the developers' and authors' protection, the GPL clearly explains that there is no warranty for this free software.  For both users' and authors' sake, the GPL requires that modified versions be marked as changed, so that their problems will not be attributed erroneously to authors of previous versions.

Some devices are designed to deny users access to install or run modified versions of the software inside them, although the manufacturer can do so.  This is fundamentally incompatible with the aim of protecting users' freedom to change the software.  The systematic pattern of such abuse occurs in the area of products for individuals to use, which is precisely where it is most unacceptable.  Therefore, we have designed this version of the GPL to prohibit the practice for those products.  If such problems arise substantially in other domains, we stand ready to extend this provision to those domains in future versions of the GPL, as needed to protect the freedom of users.

Finally, every program is threatened constantly by software patents. States should not allow patents to restrict development and use of software on general-purpose computers, but in those that do, we wish to avoid the special danger that patents applied to a free program could make it effectively proprietary.  To prevent this, the GPL assures that patents cannot be used to render the program non-free.

The precise terms and conditions for copying, distribution and modification follow.

                       TERMS AND CONDITIONS

0. Definitions.
---------------

“This License” refers to version 3 of the GNU General Public License.

“Copyright” also means copyright-like laws that apply to other kinds of works, such as semiconductor masks.

“The Program” refers to any copyrightable work licensed under this License.  Each licensee is addressed as “you”.  “Licensees” and “recipients” may be individuals or organizations.

To “modify” a work means to copy from or adapt all or part of the work in a fashion requiring copyright permission, other than the making of an exact copy.  The resulting work is called a “modified version” of the earlier work or a work “based on” the earlier work.

A “covered work” means either the unmodified Program or a work based on the Program.

To “propagate” a work means to do anything with it that, without permission, would make you directly or secondarily liable for infringement under applicable copyright law, except executing it on a computer or modifying a private copy.  Propagation includes copying, distribution (with or without modification), making available to the public, and in some countries other activities as well.

To “convey” a work means any kind of propagation that enables other parties to make or receive copies.  Mere interaction with a user through a computer network, with no transfer of a copy, is not conveying.

An interactive user interface displays “Appropriate Legal Notices” to the extent that it includes a convenient and prominently visible feature that (1) displays an appropriate copyright notice, and (2) tells the user that there is no warranty for the work (except to the extent that warranties are provided), that licensees may convey the work under this License, and how to view a copy of this License.  If the interface presents a list of user commands or options, such as a menu, a prominent item in the list meets this criterion.

1. Source Code.
---------------

The “source code” for a work means the preferred form of the work for making modifications to it.  “Object code” means any non-source form of a work.

A “Standard Interface” means an interface that either is an official standard defined by a recognized standards body, or, in the case of interfaces specified for a particular programming language, one that is widely used among developers working in that language.

The “System Libraries” of an executable work include anything, other than the work as a whole, that (a) is included in the normal form of packaging a Major Component, but which is not part of that Major Component, and (b) serves only to enable use of the work with that Major Component, or to implement a Standard Interface for which an implementation is available to the public in source code form.  A “Major Component”, in this context, means a major essential component (kernel, window system, and so on) of the specific operating system (if any) on which the executable work runs, or a compiler used to produce the work, or an object code interpreter used to run it.

The “Corresponding Source” for a work in object code form means all the source code needed to generate, install, and (for an executable work) run the object code and to modify the work, including scripts to control those activities.  However, it does not include the work's System Libraries, or general-purpose tools or generally available free programs which are used unmodified in performing those activities but which are not part of the work.  For example, Corresponding Source includes interface definition files associated with source files for the work, and the source code for shared libraries and dynamically linked subprograms that the work is specifically designed to require, such as by intimate data communication or control flow between those subprograms and other parts of the work.

The Corresponding Source need not include anything that users can regenerate automatically from other parts of the Corresponding Source.

The Corresponding Source for a work in source code form is that same work.

2. Basic Permissions.
---------------------

All rights granted under this License are granted for the term of copyright on the Program, and are irrevocable provided the stated conditions are met.  This License explicitly affirms your unlimited permission to run the unmodified Program.  The output from running a covered work is covered by this License only if the output, given its content, constitutes a covered work.  This License acknowledges your rights of fair use or other equivalent, as provided by copyright law.

You may make, run and propagate covered works that you do not convey, without conditions so long as your license otherwise remains in force.  You may convey covered works to others for the sole purpose of having them make modifications exclusively for you, or provide you with facilities for running those works, provided that you comply with the terms of this License in conveying all material for which you do not control copyright.  Those thus making or running the covered works for you must do so exclusively on your behalf, under your direction and control, on terms that prohibit them from making any copies of your copyrighted material outside their relationship with you.

Conveying under any other circumstances is permitted solely under the conditions stated below.  Sublicensing is not allowed; section 10 makes it unnecessary.

3. Protecting Users' Legal Rights From Anti-Circumvention Law.
--------------------------------------------------------------

No covered work shall be deemed part of an effective technological measure under any applicable law fulfilling obligations under article 11 of the WIPO copyright treaty adopted on 20 December 1996, or similar laws prohibiting or restricting circumvention of such measures.

When you convey a covered work, you waive any legal power to forbid circumvention of technological measures to the extent such circumvention is effected by exercising rights under this License with respect to the covered work, and you disclaim any intention to limit operation or modification of the work as a means of enforcing, against the work's users, your or third parties' legal rights to forbid circumvention of technological measures.

4. Conveying Verbatim Copies.
-----------------------------

You may convey verbatim copies of the Program's source code as you receive it, in any medium, provided that you conspicuously and appropriately publish on each copy an appropriate copyright notice; keep intact all notices stating that this License and any non-permissive terms added in accord with section 7 apply to the code; keep intact all notices of the absence of any warranty; and give all recipients a copy of this License along with the Program.

You may charge any price or no price for each copy that you convey, and you may offer support or warranty protection for a fee.

5. Conveying Modified Source Versions.
--------------------------------------

You may convey a work based on the Program, or the modifications to produce it from the Program, in the form of source code under the terms of section 4, provided that you also meet all of these conditions:

  a) The work must carry prominent notices stating that you modified it, and giving a relevant date.

  b) The work must carry prominent notices stating that it is released under this License and any conditions added under section 7.  This requirement modifies the requirement in section 4 to “keep intact all notices”.

  c) You must license the entire work, as a whole, under this License to anyone who comes into possession of a copy.  This License will therefore apply, along with any applicable section 7 additional terms, to the whole of the work, and all its parts, regardless of how they are packaged.  This License gives no permission to license the work in any other way, but it does not invalidate such permission if you have separately received it.

  d) If the work has interactive user interfaces, each must display Appropriate Legal Notices; however, if the Program has interactive interfaces that do not display Appropriate Legal Notices, your work need not make them do so.

A compilation of a covered work with other separate and independent works, which are not by their nature extensions of the covered work, and which are not combined with it such as to form a larger program, in or on a volume of a storage or distribution medium, is called an “aggregate” if the compilation and its resulting copyright are not used to limit the access or legal rights of the compilation's users beyond what the individual works permit.  Inclusion of a covered work in an aggregate does not cause this License to apply to the other parts of the aggregate.

6. Conveying Non-Source Forms.
------------------------------

You may convey a covered work in object code form under the terms of sections 4 and 5, provided that you also convey the machine-readable Corresponding Source under the terms of this License, in one of these ways:

  a) Convey the object code in, or embodied in, a physical product (including a physical distribution medium), accompanied by the Corresponding Source fixed on a durable physical medium customarily used for software interchange.

  b) Convey the object code in, or embodied in, a physical product (including a physical distribution medium), accompanied by a written offer, valid for at least three years and valid for as long as you offer spare parts or customer support for that product model, to give anyone who possesses the object code either (1) a copy of the Corresponding Source for all the software in the product that is covered by this License, on a durable physical medium customarily used for software interchange, for a price no more than your reasonable cost of physically performing this conveying of source, or (2) access to copy the Corresponding Source from a network server at no charge.

  c) Convey individual copies of the object code with a copy of the written offer to provide the Corresponding Source.  This alternative is allowed only occasionally and noncommercially, and only if you received the object code with such an offer, in accord with subsection 6b.

  d) Convey the object code by offering access from a designated place (gratis or for a charge), and offer equivalent access to the Corresponding Source in the same way through the same place at no further charge.  You need not require recipients to copy the Corresponding Source along with the object code.  If the place to copy the object code is a network server, the Corresponding Source may be on a different server (operated by you or a third party) that supports equivalent copying facilities, provided you maintain clear directions next to the object code saying where to find the Corresponding Source.  Regardless of what server hosts the Corresponding Source, you remain obligated to ensure that it is available for as long as needed to satisfy these requirements.

  e) Convey the object code using peer-to-peer transmission, provided you inform other peers where the object code and Corresponding Source of the work are being offered to the general public at no charge under subsection 6d.

A separable portion of the object code, whose source code is excluded from the Corresponding Source as a System Library, need not be included in conveying the object code work.

A “User Product” is either (1) a “consumer product”, which means any tangible personal property which is normally used for personal, family, or household purposes, or (2) anything designed or sold for incorporation into a dwelling.  In determining whether a product is a consumer product, doubtful cases shall be resolved in favor of coverage.  For a particular product received by a particular user, “normally used” refers to a typical or common use of that class of product, regardless of the status of the particular user or of the way in which the particular user actually uses, or expects or is expected to use, the product.  A product is a consumer product regardless of whether the product has substantial commercial, industrial or non-consumer uses, unless such uses represent the only significant mode of use of the product.

“Installation Information” for a User Product means any methods, procedures, authorization keys, or other information required to install and execute modified versions of a covered work in that User Product from a modified version of its Corresponding Source.  The information must suffice to ensure that the continued functioning of the modified object code is in no case prevented or interfered with solely because modification has been made.

If you convey an object code work under this section in, or with, or specifically for use in, a User Product, and the conveying occurs as part of a transaction in which the right of possession and use of the User Product is transferred to the recipient in perpetuity or for a fixed term (regardless of how the transaction is characterized), the Corresponding Source conveyed under this section must be accompanied by the Installation Information.  But this requirement does not apply if neither you nor any third party retains the ability to install modified object code on the User Product (for example, the work has been installed in ROM).

The requirement to provide Installation Information does not include a requirement to continue to provide support service, warranty, or updates for a work that has been modified or installed by the recipient, or for the User Product in which it has been modified or installed.  Access to a network may be denied when the modification itself materially and adversely affects the operation of the network or violates the rules and protocols for communication across the network.

Corresponding Source conveyed, and Installation Information provided, in accord with this section must be in a format that is publicly documented (and with an implementation available to the public in source code form), and must require no special password or key for unpacking, reading or copying.

7. Additional Terms.
--------------------

“Additional permissions” are terms that supplement the terms of this License by making exceptions from one or more of its conditions. Additional permissions that are applicable to the entire Program shall be treated as though they were included in this License, to the extent that they are valid under applicable law.  If additional permissions apply only to part of the Program, that part may be used separately under those permissions, but the entire Program remains governed by this License without regard to the additional permissions.

When you convey a copy of a covered work, you may at your option remove any additional permissions from that copy, or from any part of it.  (Additional permissions may be written to require their own removal in certain cases when you modify the work.)  You may place additional permissions on material, added by you to a covered work, for which you have or can give appropriate copyright permission.

Notwithstanding any other provision of this License, for material you add to a covered work, you may (if authorized by the copyright holders of that material) supplement the terms of this License with terms:

  a) Disclaiming warranty or limiting liability differently from the terms of sections 15 and 16 of this License; or

  b) Requiring preservation of specified reasonable legal notices or author attributions in that material or in the Appropriate Legal Notices displayed by works containing it; or

  c) Prohibiting misrepresentation of the origin of that material, or requiring that modified versions of such material be marked in reasonable ways as different from the original version; or

  d) Limiting the use for publicity purposes of names of licensors or authors of the material; or

  e) Declining to grant rights under trademark law for use of some trade names, trademarks, or service marks; or

  f) Requiring indemnification of licensors and authors of that material by anyone who conveys the material (or modified versions of it) with contractual assumptions of liability to the recipient, for any liability that these contractual assumptions directly impose on those licensors and authors.

All other non-permissive additional terms are considered “further restrictions” within the meaning of section 10.  If the Program as you received it, or any part of it, contains a notice stating that it is governed by this License along with a term that is a further restriction, you may remove that term.  If a license document contains a further restriction but permits relicensing or conveying under this License, you may add to a covered work material governed by the terms of that license document, provided that the further restriction does not survive such relicensing or conveying.

If you add terms to a covered work in accord with this section, you must place, in the relevant source files, a statement of the additional terms that apply to those files, or a notice indicating where to find the applicable terms.

Additional terms, permissive or non-permissive, may be stated in the form of a separately written license, or stated as exceptions; the above requirements apply either way.

8. Termination.
---------------

You may not propagate or modify a covered work except as expressly provided under this License.  Any attempt otherwise to propagate or modify it is void, and will automatically terminate your rights under this License (including any patent licenses granted under the third paragraph of section 11).

However, if you cease all violation of this License, then your license from a particular copyright holder is reinstated (a) provisionally, unless and until the copyright holder explicitly and finally terminates your license, and (b) permanently, if the copyright holder fails to notify you of the violation by some reasonable means prior to 60 days after the cessation.

Moreover, your license from a particular copyright holder is reinstated permanently if the copyright holder notifies you of the violation by some reasonable means, this is the first time you have received notice of violation of this License (for any work) from that copyright holder, and you cure the violation prior to 30 days after your receipt of the notice.

Termination of your rights under this section does not terminate the licenses of parties who have received copies or rights from you under this License.  If your rights have been terminated and not permanently reinstated, you do not qualify to receive new licenses for the same material under section 10.

9. Acceptance Not Required for Having Copies.
---------------------------------------------

You are not required to accept this License in order to receive or run a copy of the Program.  Ancillary propagation of a covered work occurring solely as a consequence of using peer-to-peer transmission to receive a copy likewise does not require acceptance.  However, nothing other than this License grants you permission to propagate or modify any covered work.  These actions infringe copyright if you do not accept this License.  Therefore, by modifying or propagating a covered work, you indicate your acceptance of this License to do so.

10. Automatic Licensing of Downstream Recipients.
-------------------------------------------------

Each time you convey a covered work, the recipient automatically receives a license from the original licensors, to run, modify and propagate that work, subject to this License.  You are not responsible for enforcing compliance by third parties with this License.

An “entity transaction” is a transaction transferring control of an organization, or substantially all assets of one, or subdividing an organization, or merging organizations.  If propagation of a covered work results from an entity transaction, each party to that transaction who receives a copy of the work also receives whatever licenses to the work the party's predecessor in interest had or could give under the previous paragraph, plus a right to possession of the Corresponding Source of the work from the predecessor in interest, if the predecessor has it or can get it with reasonable efforts.

You may not impose any further restrictions on the exercise of the rights granted or affirmed under this License.  For example, you may not impose a license fee, royalty, or other charge for exercise of rights granted under this License, and you may not initiate litigation (including a cross-claim or counterclaim in a lawsuit) alleging that any patent claim is infringed by making, using, selling, offering for sale, or importing the Program or any portion of it.

11. Patents.
------------

A “contributor” is a copyright holder who authorizes use under this License of the Program or a work on which the Program is based.  The work thus licensed is called the contributor's “contributor version”.

A contributor's “essential patent claims” are all patent claims owned or controlled by the contributor, whether already acquired or hereafter acquired, that would be infringed by some manner, permitted by this License, of making, using, or selling its contributor version, but do not include claims that would be infringed only as a consequence of further modification of the contributor version.  For purposes of this definition, “control” includes the right to grant patent sublicenses in a manner consistent with the requirements of this License.

Each contributor grants you a non-exclusive, worldwide, royalty-free patent license under the contributor's essential patent claims, to make, use, sell, offer for sale, import and otherwise run, modify and propagate the contents of its contributor version.

In the following three paragraphs, a “patent license” is any express agreement or commitment, however denominated, not to enforce a patent (such as an express permission to practice a patent or covenant not to sue for patent infringement).  To “grant” such a patent license to a party means to make such an agreement or commitment not to enforce a patent against the party.

If you convey a covered work, knowingly relying on a patent license, and the Corresponding Source of the work is not available for anyone to copy, free of charge and under the terms of this License, through a publicly available network server or other readily accessible means, then you must either (1) cause the Corresponding Source to be so available, or (2) arrange to deprive yourself of the benefit of the patent license for this particular work, or (3) arrange, in a manner consistent with the requirements of this License, to extend the patent license to downstream recipients.  “Knowingly relying” means you have actual knowledge that, but for the patent license, your conveying the covered work in a country, or your recipient's use of the covered work in a country, would infringe one or more identifiable patents in that country that you have reason to believe are valid.

If, pursuant to or in connection with a single transaction or arrangement, you convey, or propagate by procuring conveyance of, a covered work, and grant a patent license to some of the parties receiving the covered work authorizing them to use, propagate, modify or convey a specific copy of the covered work, then the patent license you grant is automatically extended to all recipients of the covered work and works based on it.

A patent license is “discriminatory” if it does not include within the scope of its coverage, prohibits the exercise of, or is conditioned on the non-exercise of one or more of the rights that are specifically granted under this License.  You may not convey a covered work if you are a party to an arrangement with a third party that is in the business of distributing software, under which you make payment to the third party based on the extent of your activity of conveying the work, and under which the third party grants, to any of the parties who would receive the covered work from you, a discriminatory patent license (a) in connection with copies of the covered work conveyed by you (or copies made from those copies), or (b) primarily for and in connection with specific products or compilations that contain the covered work, unless you entered into that arrangement, or that patent license was granted, prior to 28 March 2007.

Nothing in this License shall be construed as excluding or limiting any implied license or other defenses to infringement that may otherwise be available to you under applicable patent law.

12. No Surrender of Others' Freedom.
------------------------------------

If conditions are imposed on you (whether by court order, agreement or otherwise) that contradict the conditions of this License, they do not excuse you from the conditions of this License.  If you cannot convey a covered work so as to satisfy simultaneously your obligations under this License and any other pertinent obligations, then as a consequence you may not convey it at all.  For example, if you agree to terms that obligate you to collect a royalty for further conveying from those to whom you convey the Program, the only way you could satisfy both those terms and this License would be to refrain entirely from conveying the Program.

13. Use with the GNU Affero General Public License.
---------------------------------------------------

Notwithstanding any other provision of this License, you have permission to link or combine any covered work with a work licensed under version 3 of the GNU Affero General Public License into a single combined work, and to convey the resulting work.  The terms of this License will continue to apply to the part which is the covered work, but the special requirements of the GNU Affero General Public License, section 13, concerning interaction through a network will apply to the combination as such.

14. Revised Versions of this License.
-------------------------------------

The Free Software Foundation may publish revised and/or new versions of the GNU General Public License from time to time.  Such new versions will be similar in spirit to the present version, but may differ in detail to address new problems or concerns.

Each version is given a distinguishing version number.  If the Program specifies that a certain numbered version of the GNU General Public License “or any later version” applies to it, you have the option of following the terms and conditions either of that numbered version or of any later version published by the Free Software Foundation.  If the Program does not specify a version number of the GNU General Public License, you may choose any version ever published by the Free Software Foundation.

If the Program specifies that a proxy can decide which future versions of the GNU General Public License can be used, that proxy's public statement of acceptance of a version permanently authorizes you to choose that version for the Program.

Later license versions may give you additional or different permissions.  However, no additional obligations are imposed on any author or copyright holder as a result of your choosing to follow a later version.

[Warranty]
15. Disclaimer of Warranty.
---------------------------

THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

16. Limitation of Liability.
----------------------------

IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

17. Interpretation of Sections 15 and 16.
-----------------------------------------

If the disclaimer of warranty and limitation of liability provided above cannot be given local legal effect according to their terms, reviewing courts shall apply local law that most closely approximates an absolute waiver of all civil liability in connection with the Program, unless a warranty or assumption of liability accompanies a copy of the Program in return for a fee.

                     END OF TERMS AND CONDITIONS

            How to Apply These Terms to Your New Programs

If you develop a new program, and you want it to be of the greatest possible use to the public, the best way to achieve this is to make it free software which everyone can redistribute and change under these terms.

To do so, attach the following notices to the program.  It is safest to attach them to the start of each source file to most effectively state the exclusion of warranty; and each file should have at least the “copyright” line and a pointer to where the full notice is found.

  <one line to give the program's name and a brief idea of what it does.>
  Copyright (C) <year>  <name of author>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

Also add information on how to contact you by electronic and paper mail.

If the program does terminal interaction, make it output a short notice like this when it starts in an interactive mode:

  <program>  Copyright (C) <year>  <name of author>
  This program comes with ABSOLUTELY NO WARRANTY; for details type ‘show w’.
  This is free software, and you are welcome to redistribute it
  under certain conditions; type ‘show c’ for details.

The hypothetical commands ‘show w’ and ‘show c’ should show the appropriate parts of the General Public License.  Of course, your program's commands might be different; for a GUI interface, you would use an “about box”.

You should also get your employer (if you work as a programmer) or school, if any, to sign a “copyright disclaimer” for the program, if necessary. For more information on this, and how to apply and follow the GNU GPL, see <http://www.gnu.org/licenses/>.

The GNU General Public License does not permit incorporating your program into proprietary programs.  If your program is a subroutine library, you may consider it more useful to permit linking proprietary applications with the library.  If this is what you want to do, use the GNU Lesser General Public License instead of this License.  But first, please read <http://www.gnu.org/philosophy/why-not-lgpl.html>.

[Licencia GNU (Español)]

LICENCIA PÚBLICA GENERAL DE GNU (GPL)

Esta es la conocida como «GNU General Public License (GPL)», versión 3 (de junio de 2007), que cubre la mayor parte del software de la «Free Software Foundation», y muchos más programas.

---

IMPORTANT NOTICE:
This is an unofficial translation of the GNU General Public License into spanish. It was not published by the Free Software Foundation, and does not legally state the distribution terms for software that uses the GNU GPL —only the original English text of the GNU GPL does that. However, we hope that this translation will help spanish speakers understand the GNU GPL better.

NOTA IMPORTANTE:
Esta es una traducción no oficial de la Licencia Pública General GNU (GNU GPL) al español. No fue publicada por la Fundación para el Software Libre, y no establece legalmente los términos de distribución para software que utiliza la GNU GPL —sólamente el texto original en inglés de la GNU GPL hace eso. De todas formas, esperamos que esta traducción ayude a los hispanohablantes a comprender mejor la GNU GPL.

---

                  LICENCIA PÚBLICA GENERAL GNU
                 Versión 3, 29 de junio de 2007

Copyright © 2007 Free Software Foundation, Inc.
<http://fsf.org/>

Se permite la copia y distribución de copias literales de esta licencia, pero no está permitido modificarla.

                          Preámbulo

La Licencia Pública General GNU (GNU GPL) es una licencia libre, sin derechos para software y otro tipo de trabajos.

Las licencias para la mayoría del software y otros trabajos prácticos están destinadas a suprimir la libertad de compartir y modificar esos trabajos. Por el contrario, la Licencia Pública General GNU persigue garantizar su libertad para compartir y modificar todas las versiones de un programa--y asegurar que permanecerá como software libre para todos sus usuarios. Nosotros, La Fundación de Software Libre, usamos la Licencia Pública General GNU para la mayoría de nuestro software; y también se aplica a cualquier trabajo realizado de la misma forma por sus autores. Usted también puede aplicarla a sus programas.

Cuando hablamos de software libre, nos referimos a libertad, no a precio. Nuestras Licencias Públicas Generales están destinadas a garantizar la libertad de distribuir copias de software libre (y cobrar por ello si quiere), a recibir el código fuente o poder conseguirlo si así lo desea, a modificar el software o usar parte del mismo en nuevos programas libres, y a saber que puede hacer estas cosas.

Para proteger sus derechos, necesitamos evitar que otros le nieguen esos derechos o le pidan renunciar a ellos. Por lo tanto, usted tiene ciertas responsabilidades cuando distribuye copias del software, o si lo modifica: responsabilidades que persiguen respetar la libertad de otros.

Por ejemplo, si distribuye copias de tales programas, gratuitamente o no, debe transmitir a los destinatarios los mismos derechos que usted recibió. Debe asegurarse que ellos también reciban o puedan conseguir el código fuente. Y debe mostrarles estos términos y condiciones para que conozcan sus derechos.

Los desarrolladores que usen la GPL GNU protegen sus derechos de dos formas: (1) imponen derechos al software, y (2) le ofrecen esta Licencia para que legalmente lo copie, distribuya y/o modifique.

Para proteger a desarrolladores y autores, la GPL expone claramente que no existe garantía alguna para este software libre. Para beneficio de ambos, usuarios y autores, la GPL establece que las versiones modificadas deberán estar identificadas como tales, para que cualquier problema no sea atribuido por error a los autores de versiones anteriores.

Algunos dispositivos están diseñados para negar al usuario la instalación o la ejecución de versiones modificadas del software que usan internamente, aunque el fabricante sí pueda hacerlo. Esto es completamente incompatible con el objetivo de proteger la libertad de los usuarios para modificar el software. Este tipo de abuso sistemático ocurre con productos de uso personal, que es precisamente donde es menos aceptable. Por tanto, hemos diseñado esta versión de la GPL para prohibir estas prácticas en esos productos. Si apareciesen problemas similares en otros ámbitos, estaremos preparados para extender estas prestaciones a las próximas versiones de la GPL, tanto como sea necesario para proteger la libertad de los usuarios.

Por último, todo programa está constantemente amenazado por las patentes de software. Los estados no deberían permitir que las patentes restrinjan el desarrollo y el uso de software en ordenadores de uso general; pero en aquellos que lo hagan, esperamos evitar el especial peligro que suponen las patentes, que aplicadas a un programa libre puedan hacerlo propietario en la práctica. Para prevenir eso, la GPL establece que las patentes no pueden usarse para convertir un programa en no-libre.

A continuación se exponen los términos y condiciones para la copia, distribución y modificación.

                     TÉRMINOS Y CONDICIONES

0. Definiciones.
----------------

En adelante «Esta Licencia» se refiere a la versión 3 de la Licencia Pública General GNU.

«Copyright» también significa «leyes similares al copyright» que son aplicables a otro tipo de trabajos, tales como las máscaras de semiconductores.

«El Programa» se refiere a cualquier trabajo con copyright al que se haya aplicado esta Licencia. Cada beneficiario es asimilable a «usted». «Beneficiarios» y «destinatarios» pueden ser personas físicas u organizaciones.

«Modificar» un trabajo significa copiar o adaptar todo o parte de un trabajo, exceptuando la copia exacta, de manera que se requiera permiso de copyright. El trabajo resultante se denomina «versión modificada» de un trabajo anterior o trabajo «basado en» el trabajo anterior.

Un «trabajo amparado» puede ser tanto el Programa no modificado como un trabajo basado en el Programa.

«Difundir» un trabajo significa hacer cualquier cosa con él, sin permiso, que le haga directa o indirectamente responsable de infringir leyes cubiertas por copyright, excepto la ejecución en un ordenador o la modificación de una copia privada. La difusión incluye la copia, distribución (con o sin modificaciones), distribución pública, y en algunos países también otras actividades.

«Distribuir» un trabajo implica cualquier tipo de difusión que permite a la otra parte hacer o recibir copias. La mera interacción con un usuario mediante una red de ordenadores, sin transferir copia alguna, no se considera «distribución».

Una interfaz de usuario interactiva muestra «Avisos Legales Apropiados» siempre y cuando incluya características visuales apropiadas y destacadas que (1) muestren un aviso de copyright apropiado, y (2) indiquen al usuario que no existe garantía alguna para el trabajo (exceptuando las garantías que se hayan podido establecer), que los beneficiarios deben distribuir el trabajo según se establece en la presente Licencia, y cómo se puede ver una copia de esta Licencia. Si la interfaz muestra una lista de opciones o comandos, tales como menús, un elemento destacado en dicha lista cumple estos criterios.

1. Código Fuente.
-----------------

El «código fuente» de un trabajo es el formato preferido para realizar modificaciones sobre él. «Código objeto» se refiere a cualquier formato del trabajo que no sea código fuente.

Una «Interfaz Estándar» se refiere a una interfaz que sea o bien un estándar oficial definido por una institución de estándares reconocida, o bien, en el caso de interfaces específicos para una determinado lenguaje de programación, una cuyo uso esté generalizada entre los desarrolladores que trabajan con ese lenguaje.

Las «Bibliotecas de Sistema» de un trabajo ejecutable incluyen a cualquier elemento, que no sea el trabajo completo, que (a) esté incluida/o de la misma forma que un componente principal, pero que no forme parte de ese componente principal, y (b) sólo sirva para habilitar la utilización del trabajo a través de ese componente principal, o para implementar un Interfaz Estándar para el cual está disponible una implementación pública en código fuente. Un «Componente Principal», en este contexto, se refiere a un componente principal y esencial (núcleo, sistema de ventanas y similares) del sistema operativo particular (en su caso) sobre el cual funcione el ejecutable, o un compilador utilizado para generar el trabajo, o un intérprete del código objeto utilizado para ejecutarlo.

La «Fuente Correspondiente» de un trabajo en código objeto se refiere a todo código fuente necesario para generar, instalar, y (en el caso de trabajos ejecutables) ejecutar el código objeto y modificar el trabajo, incluyendo guiones que controlen esas actividades. Sin embargo, no se incluyen las Bibliotecas de Sistema del trabajo, o herramientas de propósito general o programas gratuitos habitualmente disponibles y usados sin ninguna modificación para realizar estas actividades pero que no forman parte del trabajo. Por ejemplo, la Fuente Correspondiente incluye los archivos de definición de interfaz asociados con archivos fuente del trabajo, y el código fuente de las bibliotecas compartidas o subprogramas enlazados dinámicamente que el programa requiere por diseño, como la comunicación de datos intrínseca o el control de flujo entre esos subprogramas y otras partes del trabajo.

La Fuente Correspondiente no incluye necesariamente aquello que los usuarios pueden regenerar automáticamente a partir de otras partes de la Fuente Correspondiente.

La Fuente Correspondiente de un trabajo en código fuente es ese mismo trabajo.

2. Permisos Básicos.
--------------------

Todos los derechos garantizados por esta Licencia se otorgan como copyright del Programa, y se proporcionan de manera irrevocable siempre y cuando se cumplan las condiciones establecidas. Esta Licencia afirma explícitamente su permiso ilimitado para ejecutar el Programa sin modificaciones. El resultado de la ejecución de un programa amparado está cubierto por esta Licencia sólo en el caso de que la salida, por su contenido, constituya un trabajo amparado. Esta Licencia reconoce sus derechos de uso razonable u otro equivalente, tal y como determina la ley de copyright.

Usted podrá realizar, ejecutar y difundir trabajos amparados que no distribuya, sin condición alguna, siempre y cuando no tenga otra licencia más restrictiva. Podrá distribuir trabajos amparados a terceros con el mero objetivo de que ellos hagan modificaciones exclusivamente para usted, o para que le proporcionen ayuda para ejecutar esos trabajos, siempre que cumpla los términos de esta Licencia distribuyendo todo el material de cuyo copyright no posee el control. Aquellos que realicen o ejecuten los trabajos amparados para usted deben hacerlo exclusivamente en su nombre, bajo su dirección y control, con términos que les prohíban realizar copias de su material con copyright al margen de la relación con usted.

La distribución bajo otras circunstancias se permite únicamente bajo las condiciones establecidas más abajo. No está permitido sublicenciar; la claúsula 10 lo hace innecesario.

3. Protección de Derechos Legales de los Usuarios frente a Leyes Anti-Burla.
----------------------------------------------------------------------------

Ningún trabajo amparado debe considerarse parte de una medida tecnológica efectiva, a tenor de lo establecido en cualquier ley aplicable que cumpla las obligaciones expresas en el artículo 11 del tratado de copyright WIPO adoptado el 20 de diciembre de 1996, o leyes similares que prohíben o restringen la burla de tales medidas.

Cuando distribuya un trabajo amparado, renuncia a cualquier poder legal para prohibir la burla de medidas tecnológicas mientras tales burlas se realicen en ejercicio de derechos amparados por esta Licencia respecto al trabajo amparado; además, usted negará cualquier intención de limitar el uso o modificación del trabajo con el objetivo de imponer, al trabajo de los usuarios, sus derechos legales o de terceros para prohibir la burla de medidas tecnológicas.

4. Distribución de copias literales.
------------------------------------

Usted podrá distribuir copias literales del código fuente del Programa tal y como lo ha recibido , por cualquier medio, siempre que publique de forma clara y llamativa en cada copia el correspondiente aviso de copyright ; mantenga intactos todos los avisos que establezcan que esta Licencia y cualquier término no-permisivo añadido y acorde con la cláusula 7 son aplicables al código; mantenga intactos todos los avisos de ausencia de garantía; y proporcione a todos los destinatarios una copia de esta Licencia junto con el Programa.

Usted podrá cobrar cualquier importe o no cobrar nada por cada copia que distribuya, y podrá ofrecer soporte o protección de garantía mediante un pago.

5. Distribución de Versiones Modificadas de Código.
---------------------------------------------------

Usted podrá distribuir un trabajo basado en el Programa, o las modificaciones que lo producen a partir del Programa, como código fuente en virtud de los términos establecidos en la cláusula 4, siempre que cumpla todas las condiciones siguientes:

  a) El trabajo debe incluir avisos destacados indicando que usted lo ha modificado y dando una fecha pertinente.

  b) El trabajo debe incluir avisos destacados indicando que está realizado a tenor de lo dispuesto en la presente Licencia y en cualquier otra condición añadida en virtud de la cláusula 7. Este requisito modifica el requisito de «mantener intactos todos los avisos» expuesto en la claúsula 4.

  c) En virtud del presente documento, usted deberá aplicar la licencia al trabajo completo, como un todo, a cualquier persona que esté en posesión de una copia. Por lo tanto, esta Licencia se aplicará junto con cualquier otra condición adicional aplicable de la cláusula 7, al conjunto completo del trabajo y todas y cada una de sus partes, independientemente de como sean agrupadas o empaquetadas. Esta Licencia no permite ser aplicada al trabajo de ninguna otra forma, pero no se anula dicho permiso si usted lo ha recibido por separado.

  d) Si el trabajo tiene interfaces de usuario interactivos, cada uno debe mostrar Avisos Legales Apropiados; sin embargo, si el Programa tiene interfaces interactivos que no muestran Avisos Legales Apropiados, su trabajo no tiene porqué modificarlos para que lo hagan.

Un conjunto o recopilación formado por un trabajo amparado y otros trabajos distintos e independientes, que por su naturaleza no sean ampliaciones del trabajo amparado, que no se combinen con él de alguna forma para dar lugar a un programa mayor, y que estén ubicados en un medio de distribución o almacenamiento, se denomina «paquete» si la recopilación y su copyright al completo no son usados para limitar el acceso o los derechos legales de los usuarios de la recopilación, más allá de lo que permita el trabajo individual. La inclusión de un trabajo amparado en un paquete no hace aplicable esta Licencia al resto de elementos del paquete.

6. Distribución de código No-fuente.
------------------------------------

Usted podrá distribuir el código objeto de un trabajo amparado en virtud de los términos de las cláusulas 4 y 5, siempre que también distribuya las Fuentes Correspondientes en código máquina, de acuerdo con los términos establecidos en esta Licencia, de alguna de las siguientes maneras:

  a) Distribuir el código objeto en, o embebido en, un producto físico (incluyendo medios de distribución físicos), acompañado de las Fuentes Correspondientes en un medio físico duradero y que sea utilizado habitualmente para el intercambio de software.

  b) Distribuir el código objeto en, o embebido en, un producto físico (incluyendo medios de distribución físicos), acompañado de una oferta por escrito, válida al menos durante tres años y válida durante el tiempo en el que usted ofrezca recambios o soporte para ese modelo de producto, con el fin de ofrecer al poseedor del código objeto (1) una copia de las Fuentes Correspondientes a todo el software del producto que esté cubierto por esta Licencia, en un medio físico duradero habitual para el intercambio de software, a un precio no mayor que su coste razonable por distribuir físicamente las fuentes, o (2) acceso para copiar las fuentes correspondientes desde un servidor de red sin coste alguno.

  c) Distribuir copias individuales del código objeto junto con una copia de la oferta por escrito para/con el fin de proporcionar las Fuentes Correspondientes. Esta alternativa sólo está permitida ocasionalmente, pero no de forma comercial, y solamente si usted recibió el código objeto junto con una oferta parecida, de acuerdo con la subcláusula 6b.

  d) Distribuir el código objeto ofreciendo acceso desde un lugar determinado (gratuitamente o mediante pago), y ofrecer acceso equivalente a las Fuentes Correspondientes de la misma forma y en el mismo lugar sin cargo añadido. No es necesario exigir a los destinatarios que copien las Fuentes Correspondientes junto con el código objeto. Si el lugar para copiar el código objeto es un servidor de red, las Fuentes Correspondientes pueden estar en un servidor diferente (gestionado por usted o terceros) que ofrezca facilidades de copia equivalentes, siempre que mantenga instrucciones claras junto al código objeto especificando dónde encontrar las Fuentes Correspondientes. Independientemente de qué servidores alberguen las Fuentes Correspondientes, usted seguirá obligado a asegurar que estarán disponibles durante el tiempo necesario para cumplir estos requisitos.

  e) Distribuir el código mediante transferencias entre usuarios, siempre que informe a otros usuarios dónde se ofrecen el código objeto y las Fuentes Correspondientes de forma pública sin cargo alguno, tal y como se establece en la subcláusula 6d.

Una parte separable del código objeto, cuyo código fuente esté excluido de las Fuentes Correspondientes como Biblioteca de Sistema, no necesita ser incluida en la distribución del código objeto del trabajo.

Un «Producto de Usuario» es tanto (1) un «producto de consumo», que se refiere a cualquier propiedad personal tangible habitualmente utilizada para fines personales, familiares o domésticos, o (2) cualquier cosa diseñada o vendida para ser incorporada como extensión/expansión para otro producto. Para determinar si un producto es un producto de consumo, los casos dudosos se resolverán favoreciendo el amparo. En el caso de un producto concreto recibido por un usuario particular, «de uso habitual» se refiere al uso típico o corriente de ese tipo de producto, independientemente de la situación del usuario particular o de la forma en que el usuario concreto utilice, o pretenda o se espere que pretenda utilizar, el producto. Un producto es un producto de consumo independientemente de si el producto tiene usos sustancialmente comerciales, industriales o distintos del consumo, a menos que tales usos representen la única forma posible de utilizar el producto.

Las «Instrucciones de Instalación» para un Producto de Usuario se refieren a cualquier método, procedimiento, clave de autorización, u otro tipo de información necesaria para instalar y ejecutar una versión modificada de un trabajo amparado en ese Producto de Usuario a partir de una versión modificada de las Fuentes Correspondientes. Las instrucciones deben ser suficientes para asegurar el funcionamiento continuo del código objeto modificado sin ningún tipo de condicionamiento o intromisión por el simple hecho de haber sido modificado.

Si, bajo las premisas de esta cláusula, usted distribuye el código objeto de un trabajo en, o con un Producto de Usuario o específicamente para ser usado en el mismo, y la distribución forma parte de una transacción donde los derechos de posesión y uso del Producto de Usuario se transfieren al destinatario a perpetuidad o durante un plazo fijo de tiempo (independientemente de las características de la transacción), las Fuentes Correspondientes distribuidas bajo estos supuestos deben acompañarse de las Instrucciones de Instalación. Sin embargo, estos requerimientos no se aplican si ni usted ni terceros tienen posibilidad de instalar el código objeto modificado en el Producto de Usuario (por ejemplo, el trabajo ha sido instalado en memoria de sólo lectura, ROM):

El requerimiento de proporcionar Información de Instalación no incluye el hecho de continuar proporcionando servicio de soporte, garantía, o actualizaciones para un trabajo que haya sido modificado o instalado por el destinatario, o para el Producto de Usuario en el que se haya modificado o instalado. El acceso a la red puede ser denegado cuando la propia modificación afecte materialmente y de forma adversa a la operación de la red o viole las reglas y protocolos de comunicación en la red.

Las Fuentes Correspondientes distribuidas, y las Instrucciones de Instalación proporcionadas de acuerdo con esta cláusula, deben figurar en un formato documentado públicamente (y con una implementación disponible para el público en código fuente), y no deben necesitar claves de acceso especiales para la descompresión, lectura o copia.

7. Condiciones adicionales.
---------------------------

Los «Permisos Adicionales» son condicionantes que amplían los términos de esta Licencia permitiendo excepciones a una o más de sus condiciones. Los Permisos Adicionales que son aplicables al Programa completo deberán ser tratados como si estuviesen incluidos en esta Licencia, hasta los límites de validez impuestos por las leyes aplicables. Si los permisos adicionales se aplicasen sólo a una parte del Programa, esa parte podría ser usada de forma independiente en virtud de dichos permisos, pero el Programa completo seguiría estando afectado por esta Licencia con independencia de los permisos adicionales.

Cuando distribuya una copia de un trabajo amparado, usted podrá opcionalmente eliminar cualquier permiso adicional de esa copia, o de alguna parte del mismo. (Los permisos adicionales pueden haber establecido que sea requerida su eliminación en ciertos supuestos si usted modifica el trabajo.) Usted puede establecer permisos adicionales en material añadido por usted a un trabajo amparado, sobre el cual tiene o podrá aportar sus permisos de copyright correspondientes.

Sin contravenir cualquier otra estipulación en esta Licencia, usted podrá, para el material que añada a un trabajo amparado, (si está autorizado por los poseedores de copyright de ese material) añadir condiciones a esta Licencia con los siguientes términos:

  a) Ausencia de garantía o limitación de responsabilidad diferente de los términos establecidos en las cláusulas 15 y 16 de esta Licencia; u

  b) Obligación de mantener determinados avisos legales razonables o atribuciones de autoría en el material o en los Avisos Legales Correspondientes mostrados por los trabajos que lo contengan; o

  c) Prohibir la tergiversación del origen del material, o solicitar que las diferencias respecto a la versión original sean señaladas de forma apropiada en las versiones modificadas del material; o

  d) Limitar la utilización de los nombres de los autores o beneficiarios del material con fines divulgativos; o

  e) Negarse a ofrecer derechos afectados por leyes de registro para el uso de marcas empresariales, registradas o de servicio; o

  f) Exigir indemnización a los autores y poseedores de la licencia de ese material, por parte de cualquier persona que distribuya el material (o versiones modificadas del mismo), estableciendo obligaciones contractuales de responsabilidad sobre el destinatario, para cualquier responsabilidad que estas obligaciones contractuales impongan directamente sobre los autores y poseedores de licencia.

Cualesquiera otras condiciones adicionales no-permisivas son consideradas «otras restricciones» en el contexto de la cláusula 10. Si el Programa, tal cual lo recibió, o cualquier parte del mismo, contiene un aviso indicando que está amparado por esta Licencia junto a una cláusula de restricción posterior específica, usted podrá suprimir esa cláusula. Si un documento de licencia contiene una restricción de este tipo pero permite modificar la licencia o la distribución en virtud de la presente Licencia, usted podrá añadirla al material de un trabajo amparado por los términos de ese documento de licencia, siempre que dicha restricción no se mantenga tras la modificación de la licencia o la distribución.

Si añade condiciones para un trabajo amparado, a tenor de lo establecido en la presente cláusula, usted deberá ubicar, en los archivos fuente involucrados, una declaración de los términos adicionales aplicables a esos archivos, o un aviso indicando dónde localizar los términos aplicables.

Las condiciones adicionales, permisivas o no, deben aparecer por escrito como licencias separadas, o figurar como excepciones; de todas formas, los requisitos anteriores siempre son aplicables.

8. Cancelación.
---------------

Usted no podrá distribuir o modificar un trabajo amparado salvo de la forma en la que se ha previsto expresamente en esta Licencia. Cualquier intento diferente de distribución o modificación será considerado nulo, y automáticamente cancelará sus derechos respecto a esta Licencia (incluyendo cualquier patente conseguida según el párrafo tercero de la cláusula 11).

Sin embargo, si deja de violar esta Licencia, entonces su licencia desde el poseedor del copyright correspondiente será restituida (a) provisionalmente, a menos que y hasta que el poseedor del copyright dé por terminada explícita y permanentemente su licencia, y (b) permanentemente, si el poseedor del copyright no le ha notificado por algún cauce de la violación no después de los 60 días posteriores al cese.

Además, su licencia desde el poseedor del copyright correspondiente será restituida permanentemente si el poseedor del copyright le notifica de la violación por algún cauce, es la primera vez que recibe la notificación de violación de esta Licencia (para cualquier trabajo) de ese poseedor de copyright, y usted subsana la violación antes de 30 días desde la recepción del aviso.

La cancelación de sus derechos según esta cláusula no da por canceladas las licencias de terceros que hayan recibido copias o derechos a través de usted con esta Licencia. Si sus derechos han finalizado y no han sido restituidos de forma permanente, usted no está capacitado para recibir nuevas licencias para el mismo material en virtud de la cláusula 10.

9. Aceptación no obligatoria por tenencia de copias.
----------------------------------------------------

No está obligado a aceptar esta Licencia por recibir o ejecutar una copia del Programa. La distribución de un trabajo amparado surgida simplemente como consecuencia de la transmisión entre usuarios para obtener una copia tampoco requiere aceptación. Sin embargo, únicamente esta Licencia le otorga permiso para distribuir o modificar cualquier trabajo amparado. Estas acciones infringen el copyright si usted no acepta las los términos y condiciones de esta Licencia. Por lo tanto, al modificar o distribuir un trabajo amparado, usted indica que acepta la Licencia.

10. Herencia automática de licencia para destinatarios.
-------------------------------------------------------

Cada vez que distribuya un trabajo amparado, el destinatario recibirá automáticamente una licencia desde los poseedores originales, para ejecutar, modificar y distribuir ese trabajo, al amparo de los términos de esta Licencia. Usted no será responsable de asegurar el cumplimiento por terceros de esta Licencia.

Una «transacción de entidad» es una transacción que transfiere el control de una organización, o todos los bienes sustanciales de una, o subdivide una organización, o fusiona organizaciones. Si la distribución de un trabajo amparado surge de una transacción de entidad, cada parte involucrada en esa transacción que reciba una copia del trabajo, también recibe todas y cada una de las licencias existentes del trabajo que la parte interesada tuviese o pudiese ofrecer según el párrafo anterior, además del derecho a tomar posesión de las Fuentes Correspondientes del trabajo a través de la parte interesada, si está en poder de dicha parte o se puede conseguir con un esfuerzo razonable.

Usted no podrá imponer restricciones posteriores en el ejercicio de los derechos otorgados o concedidos en virtud de la presente Licencia. Por ejemplo, usted no puede imponer a la licencia pagos, derechos u otros cargos por el ejercicio de los derechos otorgados según esta Licencia; además no podrá iniciar litigios (incluyendo demandas o contrademandas en pleitos) alegando que se infringen patentes por cambiar, usar, vender, ofrecer en venta o importar el Programa, o cualquier parte del mismo.

11. Patentes.
-------------

Un «colaborador» es un poseedor de copyright que autoriza el uso del Programa o un trabajo en el que se base el Programa bajo los términos y condiciones establecidos en la presente Licencia. El trabajo con esta licencia se denomina «versión en colaboración» con el colaborador.

Todas las reivindicaciones de patentes en posesión o controladas por el colaborador se denominan «demandas de patente original», ya sean existentes o adquiridas con posterioridad, que hayan sido infringidas de alguna forma permitida por esta Licencia, al hacer, usar o vender la versión en colaboración, pero sin incluir demandas que sólo sean infracciones como consecuencia de modificaciones posteriores de la versión en colaboración. Para aclarar esta definición, «control» incluye el derecho de conceder sublicencias de patente de forma que no contravenga los requisitos establecidos en la presente Licencia.

Cada colaborador le concede a usted una licencia de la patente no-exclusiva, global y libre de derechos bajo las reivindicaciones de patente de origen del colaborador, para el uso, modificación, venta, ofertas de venta, importación y otras formas de ejecución, modificación y redistribución del contenido de la versión en colaboración.

En los siguientes tres párrafos, una «licencia de patente» se refiere a cualquier acuerdo o compromiso expreso y manifiesto, cualquiera que sea su denominación, que no imponga una patente (como puede ser el permiso expreso para ejecutar una patente o acuerdos para no imponer demandas por infracción de patente). «Conceder» estas licencias de patente a un tercero significa llegar a tal tipo de acuerdo o compromiso que no imponga una patente al tercero.

Si usted distribuye un trabajo amparado, conociendo que está afectado por una licencia de patente, y no están disponibles de forma pública para su copia las Fuentes Correspondientes, sin cargo alguno y bajo los términos de esta Licencia, ya sea a través de un servidor de red público o mediante cualquier otro medio, entonces usted deberá o bien (1) permitir que sean públicas las Fuentes Correspondientes, o (2) tratar de eliminar los beneficios de la licencia de patente para este trabajo en particular, o (3) tratar de extender, de una forma que no contravenga los requisitos de esta Licencia, la licencia de patente a terceros. «Conocer que está afectado» significa que usted tiene conocimiento real de que, para la licencia de patente, la distribución del trabajo amparado en un determinado país, o el uso del trabajo amparado por sus destinatarios en un determinado país, infringiría una o más patentes existentes en ese país que usted considera aplicables por algún motivo.

Si, de conformidad con alguna transacción o acuerdo(o en un proceso relacionado con ellos), usted distribuye o distribuye con fines de distribución , un trabajo amparado, concediendo una licencia de patente para algún tercero que reciba el trabajo amparado, y autorizándole a usar, distribuir, modificar o distribuir una copia específica del trabajo amparado, entonces la licencia de patente que usted otorgue se extiende automáticamente a todos los receptores del trabajo amparado y cualquier trabajo basado en el mismo.

Una licencia de patente es «discriminatoria» si no incluye dentro de su ámbito de cobertura, prohíbe el ejercicio, o está condicionada a no ejercitar uno o más de los derechos que están específicamente otorgados por esta Licencia. Usted no debe distribuir un trabajo amparado si está implicado en un acuerdo con terceros que estén relacionados con el negocio de la distribución de software, en el que usted haga pagos relacionados con su actividad de distribución del trabajo, y donde se otorgue, a cualquier receptor del trabajo amparado, una licencia de patente discriminatoria (a) en relación con las copias del trabajo amparado distribuido por usted (o copias hechas a partir de éstas), o (b) directa o indirectamente relacionadas con productos específicos o paquetes que contengan el trabajo amparado, a menos que usted forme parte del acuerdo, o que esa licencia de patente fuese otorgada antes del 28 de marzo de 2007.

Ninguna disposición de esta Licencia se considerará como excluyente o limitante de la aplicación de cualquier otra licencia o defensas legales contra la violación de las leyes de propiedad intelectual a que pudiera tener derecho bajo la ley de propiedad intelectual vigente.

12. No condicionamiento de la libertad de terceros.
---------------------------------------------------

Si a usted le son impuestas condiciones que contravienen las estipuladas en la presente Licencia (ya sea por orden judicial, acuerdo u otros), no quedará eximido de cumplir las condiciones de esta Licencia. Si usted no puede distribuir un trabajo amparado cumpliendo simultáneamente sus obligaciones con esta Licencia y con cualquier otra pertinente, entonces no podrá distribuirlo de ninguna forma. Por ejemplo, si usted se compromete con términos que le obligan a obtener derechos por la distribución a terceros, la única forma de satisfacer ambos condicionantes y esta Licencia es abstenerse completamente de distribuir el Programa.

13. Uso conjunto con la Licencia Pública General Affero GNU.
------------------------------------------------------------

Sin contravenir las disposiciones de la presente Licencia, usted tendrá permiso para enlazar o combinar cualquier trabajo amparado con otro trabajo amparado por la versión 3 de la Licencia Pública General Affero GNU y formar un solo trabajo combinado, y distribuir el trabajo resultante. Los términos de esta Licencia seguirán siendo aplicables a la parte formada por el trabajo amparado, pero los condicionantes especiales de la Licencia Pública General Affero GNU, en su cláusula 13, relativos a la interacción mediante redes, serán aplicables a la combinación de ambas partes.

14. Versiones Revisadas de esta Licencia.
-----------------------------------------

La Fundación para el Software Libre podrá publicar revisiones y/o nuevas versiones de la Licencia Pública General GNU de vez en cuando. Esas versiones serán similares en espíritu a la versión actual, pero podrán diferir en algunos detalles para afrontar nuevos problemas o situaciones.

A cada versión se le da un número distintivo. Si el Programa especifica que le es aplicable cierto número de versión de la Licencia Pública General o «cualquier versión posterior», usted tendrá la posibilidad de adoptar los términos y condiciones de la versión indicada o de cualquier otra versión posterior publicada por la Fundación para el Software Libre. Si el Programa no especifica un número de versión de la Licencia Pública General, usted podrá elegir cualquier versión que haya sido publicada por la Fundación para el Software Libre.

Si el Programa especifica que un apoderado/representante puede decidir qué versiones de la Licencia Pública General pueden aplicarse en el futuro, la declaración pública de aceptación que el apoderado/representante haga de una versión le autoriza a usted con carácter permanente a elegir esa versión para el Programa.

Versiones posteriores de la licencia podrán otorgarle permisos adicionales o diferentes. Sin embargo, no podrán imponerse obligaciones adicionales a cualquier autor o poseedor de copyright como consecuencia de que usted adopte una versión posterior.

15. Ausencia de Garantía.
-------------------------

EL PROGRAMA NO TIENE GARANTÍA ALGUNA, HASTA LOS LÍMITES PERMITIDOS POR LAS LEYES APLICABLES. SALVO CUANDO SE ESTABLEZCA LO CONTRARIO POR ESCRITO, EL POSEEDOR DEL COPYRIGHT Y/O TERCEROS PROPORCIONARÁN EL PROGRAMA «TAL CUAL» SIN GARANTÍA DE NINGÚN TIPO, YA SEA EXPLÍCITA O IMPLÍCITA, INCLUYENDO, PERO SIN LIMITARSE A, LAS GARANTÍAS IMPLÍCITAS MERCANTILES Y DE APTITUD PARA UN PROPÓSITO DETERMINADO. USTED ASUMIRÁ CUALQUIER RIESGO RELATIVO A LA CALIDAD Y RENDIMIENTO DEL PROGRAMA. SI EL PROGRAMA FUESE DEFECTUOSO, USTED ASUMIRÁ CUALQUIER COSTE DE SERVICIO, REPARACIÓN O CORRECCIÓN.

16. Limitación de Responsabilidad.
----------------------------------

EN NINGÚN CASO, SALVO REQUERIMIENTO POR LEYES APLICABLES O MEDIANTE ACUERDO POR ESCRITO, PODRÁ UN POSEEDOR DE COPYRIGHT, O UN TERCERO QUE MODIFIQUE O DISTRIBUYA EL PROGRAMA SEGÚN LO INDICADO ANTERIORMENTE, HACERLE A USTED RESPONSABLE DE DAÑO ALGUNO, INCLUYENDO CUALQUIER DAÑO GENERAL, ESPECIAL, OCASIONAL O DERIVADO QUE SURJA DEL USO O LA INCAPACIDAD DE USO DEL PROGRAMA (INCLUYENDO PERO SIN LIMITARSE A LA PÉRDIDA DE DATOS O LA PRESENTACIÓN NO PRECISA DE LOS MISMOS O A PÉRDIDAS SUFRIDAS POR USTED O TERCEROS O AL FALLO DEL PROGRAMA AL INTERACTUAR CON OTROS PROGRAMAS), INCLUSO EN EL CASO DE QUE EL POSEEDOR O UN TERCERO HAYA SIDO ADVERTIDO DE LA POSIBILIDAD DE TALES DAÑOS.

17. Interpretación de las cláusulas 15 y 16.
--------------------------------------------

Si la ausencia de garantía y la limitación de responsabilidad descrita anteriormente no tuviesen efecto legal a nivel local en todos sus términos, los juzgados aplicarán las leyes locales que más se aproximen a la exención de responsabilidad civil en lo relativo al Programa, a menos que la copia del Programa esté acompañada mediante pago de una garantía o compromiso de responsabilidad.

                     FIN DE TÉRMINOS Y CONDICIONES


         Cómo aplicar estas condiciones a sus nuevos programas

Si usted desarrolla un nuevo programa, y quiere darle al público el mayor uso posible del mismo, la mejor forma de conseguirlo es hacerlo software libre para que cualquiera pueda redistribuirlo y modificarlo bajo estas condiciones.

Para ello, adjunte los siguientes avisos al programa. Es más seguro adjuntarlos al inicio de cada archivo fuente para hacer más explícita la ausencia de garantía; y cada archivo debería tener al menos la línea de «copyright» y un enlace a la versión completa del aviso.

  <una línea con el nombre del programa y una breve idea de su objetivo.>
  Copyright (C) <año>  <nombre del autor>

  Este programa es software libre: usted puede redistribuirlo y/o modificarlo
  bajo los términos de la Licencia Pública General GNU publicada
  por la Fundación para el Software Libre, ya sea la versión 3
  de la Licencia, o (a su elección) cualquier versión posterior.

  Este programa se distribuye con la esperanza de que sea útil, pero
  SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita
  MERCANTIL o de APTITUD PARA UN PROPÓSITO DETERMINADO.
  Consulte los detalles de la Licencia Pública General GNU para obtener
  una información más detallada.

  Debería haber recibido una copia de la Licencia Pública General GNU
  junto a este programa.
  En caso contrario, consulte <http://www.gnu.org/licenses/>.

Incluya además información de cómo contactar con usted por correo electrónico y ordinario.

Si el programa es interactivo, haga que muestre un breve aviso como el siguiente cuando se inicie en modo interactivo:

  <programa>  Copyright (C) <año>  <nombre del autor>
  Este programa se ofrece SIN GARANTÍA ALGUNA;
  escriba ‘show w’ para consultar los detalles.
  Es software libre, y usted puede redistribuirlo bajo ciertas condiciones;
  escriba ‘show c’ para más información.

Los hipotéticos comandos ‘show w’ y ‘show c’ deberían mostrar las partes correspondientes de la Licencia Pública General. Por supuesto, los comandos en su programa podrían ser diferentes; en un interfaz gráfico de usuario, podría usar un mensaje del tipo «Acerca de».

También debería conseguir que su empresa (si trabaja como programador) o escuela, en su caso, firme una «renuncia de copyright» sobre el programa, si fuese necesario. Para más información a este respecto, y saber cómo aplicar y cumplir la licencia GNU GPL, consulte <http://www.gnu.org/licenses/>.

La Licencia Pública General GNU no permite incorporar sus programas como parte de programas propietarios. Si su programa es una subrutina en una biblioteca, resultaría mucho más útil habilitar el enlace de aplicaciones propietarias a la biblioteca. Si es esto lo que quiere hacer, utilice la Licencia Pública General Reducida GNU en vez de esta Licencia. Pero por favor, consulte primero <http://www.gnu.org/philosophy/why-not-lgpl.html>.

[QueryBox]
Cuadros de diálogo

En los cuadros de diálogo puede desplazarse con el teclado usando las flechas o las teclas de las letras resaltadas.

También se pueden pulsar los botones con el ratón.

[How to use help]
Uso de la ayuda

Se pueden utilizar las flechas o el ratón para navegar por el sistema de ayuda.

La flecha de abajo cambia al siguiente elemento o baja. La tecla de arriba vuelve al elemento anterior o sube. La tecla derecha sigue el enlace activo. La tecla izquierda vuelve a la última página visitada.

Si el terminal no es compatible con las flechas de cursor se puede avanzar con la barra espaciadora y retroceder con la tecla b (back). El tabulador activa el elemento siguiente y con INTRO se puede entrar al enlace correspondiente. La tecla l (last) permite volver a la última página.

ESC pulsada dos veces permite salir de la ayuda.

El botón izquierdo del ratón avanza o sigue enlaces y el botón derecho retrocede o vuelve a la última página.

La función de todas las teclas en la ayuda:

Las teclas de desplazamiento genéricasGeneral Movement Keys son válidas.

tabulador       Avanzar al elemento posterior.
Alt-tabulador   Retroceder al elemento anterior.
abajo           Avanzar elemento o bajar una línea.
arriba          Retroceder elemento o subir una línea.
derecha, INTRO  Seguir enlace.
izquierda, l    Volver a la última página visitada.
F1              Mostrar la ayuda del sistema de ayuda.
n               Pasar a la página siguiente.
p               Pasar a la página anterior.
c               Pasar a la página de contenidos.
F10, ESC        Salir de la ayuda.

Local variables:
fill-column: 58
end:
